/**
  * \file CrdFmncPco.cpp
  * job handler for job CrdFmncPco (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "CrdFmncPco.h"

// IP blksInclude --- BEGIN
#include "CrdFmncPco_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class CrdFmncPco
 ******************************************************************************/

CrdFmncPco::CrdFmncPco(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
			, const ubigint ref
		) : JobFmnc(xchg, VecFmncVJob::CRDFMNCPCO, jrefSup, ixFmncVLocale) {

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

// IP constructor.cust1 --- INSERT

	// initialize according to ref
	changeRef(dbsfmnc, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnlrec = new PnlFmncPcoRec(xchg, dbsfmnc, jref, ixFmncVLocale);
	pnlheadbar = new PnlFmncPcoHeadbar(xchg, dbsfmnc, jref, ixFmncVLocale);
	pnllist = new PnlFmncPcoList(xchg, dbsfmnc, jref, ixFmncVLocale);

// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	changeStage(dbsfmnc, VecVSge::IDLE);

	xchg->addClstn(VecFmncVCall::CALLFMNCDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

CrdFmncPco::~CrdFmncPco() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* CrdFmncPco::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdFmncPco::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdFmncPco/" + VecFmncVLocale::getSref(ixFmncVLocale);
	continf.MtxCrdPco = StubFmnc::getStubPcoStd(dbsfmnc, xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPCO, jref), ixFmncVLocale, Stub::VecVNonetype::FULL);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void CrdFmncPco::changeRef(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixFmncVAccess;
	xchg->triggerIxRefToIxCall(dbsfmnc, VecFmncVCall::CALLFMNCACCESS, jref, VecFmncVMaintable::TBLFMNCMPURCHORDER, ref, ixFmncVAccess);

	if (ixFmncVAccess != VecFmncVAccess::NONE) {
		xchg->addIxPreset(VecFmncVPreset::PREFMNCIXACC, jref, ixFmncVAccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsfmnc, VecFmncVCall::CALLFMNCLOG, jref, VecFmncVPreset::VOID, 0, "CrdFmncPco", ref);
		xchg->addRefPreset(VecFmncVPreset::PREFMNCREFPCO, jref, ref);

		refresh(dbsfmnc, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));

		if (pnllist) pnllist->updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFPCO, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFPCO, jrefTrig, notif);
	};
};

void CrdFmncPco::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- INSERT
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void CrdFmncPco::changeStage(
			DbsFmnc* dbsfmnc
			, uint _ixVSge
			, DpchEngFmnc** dpcheng
		) {
// IP dpchchangeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsfmnc); break;
			case VecVSge::ALRFMNCABT: leaveSgeAlrfmncabt(dbsfmnc); break;
			case VecVSge::CLOSE: leaveSgeClose(dbsfmnc); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh1 --- BEGIN
		if (!muteRefresh) refreshWithDpchEng(dbsfmnc, dpcheng);
// IP changeStage.refresh1 --- END

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsfmnc); break;
			case VecVSge::ALRFMNCABT: _ixVSge = enterSgeAlrfmncabt(dbsfmnc); break;
			case VecVSge::CLOSE: _ixVSge = enterSgeClose(dbsfmnc); break;
		};

// IP changeStage.refresh2 --- INSERT
	};
};
// IP changeStage --- END

uint CrdFmncPco::enterSgeIdle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdFmncPco::leaveSgeIdle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeIdle --- INSERT
};

uint CrdFmncPco::enterSgeAlrfmncabt(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::ALRFMNCABT;
	nextIxVSge = VecVSge::IDLE;
// IP enterSgeAlrfmncabt --- BEGIN
	xchg->submitDpch(AlrFmnc::prepareAlrAbt(jref, ixFmncVLocale, feedFMcbAlert));
// IP enterSgeAlrfmncabt --- END
	return retval;
};

void CrdFmncPco::leaveSgeAlrfmncabt(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeAlrfmncabt --- INSERT
};

uint CrdFmncPco::enterSgeClose(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDCLOSE, jref, VecFmncVCard::CRDFMNCPCO);
	return retval;
};

void CrdFmncPco::leaveSgeClose(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeClose --- INSERT
};

string CrdFmncPco::getSquawk(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
// IP getSquawk --- END
	return retval;
};

void CrdFmncPco::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCODO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsfmnc, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCALERT) {
			handleDpchAppFmncAlert(dbsfmnc, (DpchAppFmncAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdFmncPco::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdFmncPco::handleDpchAppDoClose(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngFmncConfirm(true, jref, "");
	changeStage(dbsfmnc, VecVSge::CLOSE);
};

void CrdFmncPco::handleDpchAppDoMitAppAbtClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsfmnc, VecVSge::ALRFMNCABT, dpcheng);
// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdFmncPco::handleDpchAppFmncAlert(
			DbsFmnc* dbsfmnc
			, DpchAppFmncAlert* dpchappfmncalert
			, DpchEngFmnc** dpcheng
		) {
	if (ixVSge == VecVSge::ALRFMNCABT) {
		changeStage(dbsfmnc, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngFmncConfirm(true, jref, "");
};

void CrdFmncPco::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCDLGCLOSE) {
		call->abort = handleCallFmncDlgClose(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSTATCHG) {
		call->abort = handleCallFmncStatChg(dbsfmnc, call->jref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCREFPRESET) {
		call->abort = handleCallFmncRefPreSet(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool CrdFmncPco::handleCallFmncDlgClose(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;
// IP handleCallFmncDlgClose --- INSERT
	return retval;
};

bool CrdFmncPco::handleCallFmncStatChg(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixFmncVExpstate == VecFmncVExpstate::REGD) && (pnlrec->statshr.ixFmncVExpstate == VecFmncVExpstate::REGD)) pnllist->minimize(dbsfmnc, true);
	return retval;
};

bool CrdFmncPco::handleCallFmncRefPreSet(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecFmncVPreset::PREFMNCREFPCO) {
		changeRef(dbsfmnc, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsfmnc, true);
	};

	return retval;
};


