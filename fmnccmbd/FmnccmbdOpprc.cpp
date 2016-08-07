/**
  * \file FmnccmbdOpprc.cpp
  * operation processor for Fmnc combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "Fmnccmbd.h"

#include "FmnccmbdOpprc.h"

/******************************************************************************
 namespace FmnccmbdOpprc
 ******************************************************************************/

void* FmnccmbdOpprc::run(
			void* arg
		) {
	XchgFmnccmbd* xchg = (XchgFmnccmbd*) arg;

	// open database connection
	DbsFmnc dbsfmnc;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsfmnc.init(xchg->stgfmncdatabase.ixDbsVDbstype, "", xchg->stgfmncdatabase.dbsname, xchg->stgfmncdatabase.ip
						, xchg->stgfmncdatabase.port, xchg->stgfmncdatabase.username, xchg->stgfmncdatabase.password);
			break;
		} catch (DbsException e) {
			contry--;
			if (contry == 0) throw;
		};
	};

	DpchInvFmnc* inv = NULL;
	ReqFmnc* req = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// main loop: wait for operation invocations
	while (true) {
		// an inv is already here
		inv = xchg->pullFirstInv();

		while (inv == NULL) {
			// no req is here ; wait for it
			Mutex::lock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "FmnccmbdOpprc", "run");
			Cond::wait(&(xchg->cOpprcs), &(xchg->mcOpprcs), "xchg->cOpprcs", "FmnccmbdOpprc", "run");

			inv = xchg->pullFirstInv();

			Mutex::unlock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "FmnccmbdOpprc", "run");
		};

		// re-signal condition to avoid using broadcast
		Cond::signal(&(xchg->cOpprcs), "xchg->cOpprcs", "FmnccmbdOpprc", "run");

		// prepare request
		req = new ReqFmnc(ReqFmnc::VecVBasetype::RET);

		req->jref = inv->jref;
		req->dpchinv = inv;

		// perform op

		if (req->dpchret) {
			req->dpchret->oref = req->dpchinv->oref;
			req->dpchret->jref = req->dpchinv->jref;

			xchg->addReq(req);

		} else {
			delete req;
		};
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void FmnccmbdOpprc::cleanup(
			void* arg
		) {
	XchgFmnccmbd* xchg = (XchgFmnccmbd*) arg;

	Mutex::unlock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "FmnccmbdOpprc", "cleanup");
};


