/**
  * \file PnlFmncStpHeadbar.cpp
  * job handler for job PnlFmncStpHeadbar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncStpHeadbar.h"

// IP blksInclude --- BEGIN
#include "PnlFmncStpHeadbar_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class PnlFmncStpHeadbar
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncStpHeadbar::PnlFmncStpHeadbar(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCSTPHEADBAR, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

};

PnlFmncStpHeadbar::~PnlFmncStpHeadbar() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncStpHeadbar::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, items);
	};

	return dpcheng;
};

void PnlFmncStpHeadbar::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
};

void PnlFmncStpHeadbar::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
	if (req->ixVBasetype == ReqFmnc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCINIT) {
			handleDpchAppFmncInit(dbsfmnc, (DpchAppFmncInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void PnlFmncStpHeadbar::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};


