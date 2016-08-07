/**
  * \file DlgFmncSmpNew.cpp
  * job handler for job DlgFmncSmpNew (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "DlgFmncSmpNew.h"

// IP blksInclude --- BEGIN
#include "DlgFmncSmpNew_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "DlgFmncSmpNew_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class DlgFmncSmpNew
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
DlgFmncSmpNew::DlgFmncSmpNew(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::DLGFMNCSMPNEW, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFDetPupArt.tag = "FeedFDetPupArt";
	feedFDetPupSup.tag = "FeedFDetPupSup";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

// IP constructor.cust1 --- INSERT

	valid = false;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

DlgFmncSmpNew::~DlgFmncSmpNew() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* DlgFmncSmpNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFDetPupArt, &feedFDetPupSup, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgFmncSmpNew::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac

	// statshr
	statshr.ButCncActive = evalButCncActive(dbsfmnc);
	statshr.ButCreActive = evalButCreActive(dbsfmnc);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void DlgFmncSmpNew::changeStage(
			DbsFmnc* dbsfmnc
			, uint _ixVSge
			, DpchEngFmnc** dpcheng
		) {
// IP dpchchangeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsfmnc); break;
			case VecVSge::CREATE: leaveSgeCreate(dbsfmnc); break;
			case VecVSge::DONE: leaveSgeDone(dbsfmnc); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh1 --- BEGIN
		if (!muteRefresh) refreshWithDpchEng(dbsfmnc, dpcheng);
// IP changeStage.refresh1 --- END

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsfmnc); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbsfmnc); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsfmnc); break;
		};

// IP changeStage.refresh2 --- INSERT
	};
};
// IP changeStage --- END

uint DlgFmncSmpNew::enterSgeIdle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgFmncSmpNew::leaveSgeIdle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeIdle --- INSERT
};

uint DlgFmncSmpNew::enterSgeCreate(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::CREATE;
	nextIxVSge = VecVSge::DONE;
// IP enterSgeCreate --- INSERT
	retval = nextIxVSge;
	return retval;
};

void DlgFmncSmpNew::leaveSgeCreate(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeCreate --- INSERT
};

uint DlgFmncSmpNew::enterSgeDone(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- INSERT
	return retval;
};

void DlgFmncSmpNew::leaveSgeDone(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeDone --- INSERT
};

string DlgFmncSmpNew::getSquawk(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
// IP getSquawk --- END
	return retval;
};

void DlgFmncSmpNew::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCSMPNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCSMPNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void DlgFmncSmpNew::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgFmncSmpNew::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
// IP handleDpchAppDataContiac --- INSERT
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgFmncSmpNew::handleDpchAppDoButCncClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButCncClick --- IBEGIN
	if (statshr.ButCncActive) {
		*dpcheng = new DpchEngFmncConfirm(true, jref, "");
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCDLGCLOSE, jref);
	};
// IP handleDpchAppDoButCncClick --- IEND
};

void DlgFmncSmpNew::handleDpchAppDoButCreClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbsfmnc, VecVSge::CREATE);
		};

		if (ixVSge == VecVSge::DONE) {
			if (!*dpcheng) *dpcheng = new DpchEngFmncConfirm(true, jref, "");
			xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCDLGCLOSE, jref);
		};
	};
// IP handleDpchAppDoButCreClick --- REND
};


