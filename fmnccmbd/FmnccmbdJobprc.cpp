/**
  * \file FmnccmbdJobprc.cpp
  * job processor for Fmnc combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "Fmnccmbd.h"

#include "FmnccmbdJobprc.h"

/******************************************************************************
 namespace FmnccmbdJobprc
 ******************************************************************************/

void* FmnccmbdJobprc::run(
			void* arg
		) {
	XchgFmnccmbd* xchg = (XchgFmnccmbd*) arg;

	JobFmnc* job = NULL;

	ubigint eref;

	// open database connection
	DbsFmnc dbsfmnc;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsfmnc.init(xchg->stgfmncdatabase.ixDbsVDbstype, "", xchg->stgfmncdatabase.dbsname, xchg->stgfmncdatabase.ip,
						xchg->stgfmncdatabase.port, xchg->stgfmncdatabase.username, xchg->stgfmncdatabase.password);
			break;
		} catch (DbsException e) {
			contry--;
			if (contry == 0) throw;
		};
	};

	ReqFmnc* req = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// main loop: wait for requests
	while (true) {
		// req is already here
		req = xchg->pullFirstReq();

		while (req == NULL) {
			// no req here ; wait for it
			Mutex::lock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "FmnccmbdJobprc", "run");
			Cond::wait(&(xchg->cJobprcs), &(xchg->mcJobprcs), "xchg->cJobprcs", "FmnccmbdJobprc", "run");

			req = xchg->pullFirstReq();

			Mutex::unlock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "FmnccmbdJobprc", "run");
		};

		// re-signal condition to avoid using broadcast
		Cond::signal(&(xchg->cJobprcs), "xchg->cJobprcs", "FmnccmbdJobprc", "run");

		// --- handle request
		if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
			xchg->mon.eventHandleReqCmd(req->jref, req->cmd);

			// pass on to job
			accessJob(xchg, &dbsfmnc, req);

		} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
			if (req->dpchapp) {
				//cout << "FmnccmbdJobprc::run() REGULAR request: '" << VecFmncVDpch::getSref(req->dpchapp->ixFmncVDpch) << "'" << endl;
				eref = xchg->mon.eventHandleReqRegular(req->jref, VecFmncVDpch::getSref(req->dpchapp->ixFmncVDpch), req->dpchapp->getSrefsMask(), "");

				// pass on to job
				accessJob(xchg, &dbsfmnc, req);
			};

			if (!req->dpcheng) req->dpcheng = new DpchEngFmncAck(req->jref);
			xchg->mon.eventReplyReqRegular(eref, req->jref, VecFmncVDpch::getSref(req->dpcheng->ixFmncVDpch), req->dpcheng->getSrefsMask(), "");

		} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::UPLOAD) {
			//cout << "FmnccmbdJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;
			xchg->mon.eventHandleReqUpload(req->jref, req->filename);

			// pass on to job
			accessJob(xchg, &dbsfmnc, req);

			// usually the job leaves req unchanged

		} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::DOWNLOAD) {
			eref = xchg->mon.eventHandleReqDownload(req->jref);

			// pass on to job
			accessJob(xchg, &dbsfmnc, req);

			xchg->mon.eventReplyReqDownload(eref, req->jref, req->filename);

		} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::RET) {
			if (req->dpchret) {
				//cout << "FmnccmbdJobprc::run() RET request: '" << VecFmncVDpch::getSref(req->dpchret->ixFmncVDpch) << "'" << endl;

				job = xchg->getJobByJref(req->jref);
				if (job) job->removeOp(req->dpchret->oref);

				xchg->mon.eventHandleReqRet(req->jref, VecFmncVDpch::getSref(req->dpchret->ixFmncVDpch), "", req->dpchret->oref);

				accessJob(xchg, &dbsfmnc, req);
			};

		} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::TIMER) {
			// pass on to job
			job = xchg->getJobByJref(req->jref);

			if (job) if (req->wref >= job->wrefMin) {
				xchg->mon.eventHandleReqTimer(req->jref, req->sref);
				accessJob(xchg, &dbsfmnc, req);
			};

		} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::EXTCALL) {
			xchg->triggerCall(&dbsfmnc, req->call);
		};

		if ((req->ixVBasetype == ReqFmnc::VecVBasetype::RET) || (req->ixVBasetype == ReqFmnc::VecVBasetype::TIMER) || (req->ixVBasetype == ReqFmnc::VecVBasetype::EXTCALL)) {
			// ret, timer and extcall requests can be deleted here
			delete req;

		} else {
			// all other requests are being waited for for further processing
			if (!(req->retain)) req->setStateReply();
		};
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void FmnccmbdJobprc::cleanup(
			void* arg
		) {
	XchgFmnccmbd* xchg = (XchgFmnccmbd*) arg;

	Mutex::unlock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "FmnccmbdJobprc", "cleanup");
};

void FmnccmbdJobprc::accessJob(
			XchgFmnccmbd* xchg
			, DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	JobFmnc* job = NULL;
	
	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("FmnccmbdJobprc", "accessJob");

		req->ixFmncVLocale = job->ixFmncVLocale;
		job->handleRequest(dbsfmnc, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("FmnccmbdJobprc", "accessJob");
	};
};


