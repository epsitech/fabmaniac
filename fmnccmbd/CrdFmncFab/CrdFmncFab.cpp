/**
  * \file CrdFmncFab.cpp
  * job handler for job CrdFmncFab (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "CrdFmncFab.h"

// IP blksInclude --- BEGIN
#include "CrdFmncFab_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "CrdFmncFab_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class CrdFmncFab
 ******************************************************************************/

CrdFmncFab::CrdFmncFab(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
			, const ubigint ref
		) : JobFmnc(xchg, VecFmncVJob::CRDFMNCFAB, jrefSup, ixFmncVLocale) {

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgexpfab = NULL;
	dlgimpfab = NULL;
	dlgnew = NULL;
	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

// IP constructor.cust1 --- INSERT

	// initialize according to ref
	changeRef(dbsfmnc, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnlrec = new PnlFmncFabRec(xchg, dbsfmnc, jref, ixFmncVLocale);
	pnlheadbar = new PnlFmncFabHeadbar(xchg, dbsfmnc, jref, ixFmncVLocale);
	pnllist = new PnlFmncFabList(xchg, dbsfmnc, jref, ixFmncVLocale);

// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	if ((ref+1) == 0) {
		dlgnew = new DlgFmncFabNew(xchg, dbsfmnc, jref, ixFmncVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbsfmnc, VecVSge::IDLE);

	xchg->addClstn(VecFmncVCall::CALLFMNCDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecFmncVCall::CALLFMNCREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

CrdFmncFab::~CrdFmncFab() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* CrdFmncFab::getNewDpchEng(
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

void CrdFmncFab::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdFmncFab/" + VecFmncVLocale::getSref(ixFmncVLocale);
	continf.MtxCrdFab = StubFmnc::getStubFabStd(dbsfmnc, xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref), ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbsfmnc);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbsfmnc);
	statshr.MitCrdImfAvail = evalMitCrdImfAvail(dbsfmnc);
	statshr.MitCrdExfActive = evalMitCrdExfActive(dbsfmnc);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void CrdFmncFab::changeRef(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixFmncVAccess;
	xchg->triggerIxRefToIxCall(dbsfmnc, VecFmncVCall::CALLFMNCACCESS, jref, VecFmncVMaintable::TBLFMNCMFAB, ref, ixFmncVAccess);

	if (ixFmncVAccess != VecFmncVAccess::NONE) {
		xchg->addIxPreset(VecFmncVPreset::PREFMNCIXACC, jref, ixFmncVAccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsfmnc, VecFmncVCall::CALLFMNCLOG, jref, VecFmncVPreset::VOID, 0, "CrdFmncFab", ref);
		xchg->addRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref, ref);

		refresh(dbsfmnc, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));

		if (pnllist) pnllist->updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFFAB, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFFAB, jrefTrig, notif);
	};
};

void CrdFmncFab::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- INSERT
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void CrdFmncFab::changeStage(
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

uint CrdFmncFab::enterSgeIdle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdFmncFab::leaveSgeIdle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeIdle --- INSERT
};

uint CrdFmncFab::enterSgeAlrfmncabt(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::ALRFMNCABT;
	nextIxVSge = VecVSge::IDLE;
// IP enterSgeAlrfmncabt --- BEGIN
	xchg->submitDpch(AlrFmnc::prepareAlrAbt(jref, ixFmncVLocale, feedFMcbAlert));
// IP enterSgeAlrfmncabt --- END
	return retval;
};

void CrdFmncFab::leaveSgeAlrfmncabt(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeAlrfmncabt --- INSERT
};

uint CrdFmncFab::enterSgeClose(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::CLOSE;
	nextIxVSge = retval;
	xchg->triggerIxCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDCLOSE, jref, VecFmncVCard::CRDFMNCFAB);
	return retval;
};

void CrdFmncFab::leaveSgeClose(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeClose --- INSERT
};

string CrdFmncFab::getSquawk(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
// IP getSquawk --- END
	return retval;
};

void CrdFmncFab::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIMFCLICK) {
					handleDpchAppDoMitCrdImfClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDEXFCLICK) {
					handleDpchAppDoMitCrdExfClick(dbsfmnc, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCALERT) {
			handleDpchAppFmncAlert(dbsfmnc, (DpchAppFmncAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdFmncFab::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdFmncFab::handleDpchAppDoClose(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngFmncConfirm(true, jref, "");
	changeStage(dbsfmnc, VecVSge::CLOSE);
};

void CrdFmncFab::handleDpchAppDoMitAppAbtClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsfmnc, VecVSge::ALRFMNCABT, dpcheng);
// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdFmncFab::handleDpchAppDoMitCrdNewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgFmncFabNew(xchg, dbsfmnc, jref, ixFmncVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdFmncFab::handleDpchAppDoMitCrdImfClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	if (!dlgimpfab) {
		dlgimpfab = new DlgFmncFabImpfab(xchg, dbsfmnc, jref, ixFmncVLocale);
		statshr.jrefDlgimpfab = dlgimpfab->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdFmncFab::handleDpchAppDoMitCrdExfClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	if (!dlgexpfab) {
		dlgexpfab = new DlgFmncFabExpfab(xchg, dbsfmnc, jref, ixFmncVLocale);
		statshr.jrefDlgexpfab = dlgexpfab->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdFmncFab::handleDpchAppFmncAlert(
			DbsFmnc* dbsfmnc
			, DpchAppFmncAlert* dpchappfmncalert
			, DpchEngFmnc** dpcheng
		) {
	if (ixVSge == VecVSge::ALRFMNCABT) {
		changeStage(dbsfmnc, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngFmncConfirm(true, jref, "");
};

void CrdFmncFab::handleCall(
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

bool CrdFmncFab::handleCallFmncDlgClose(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgexpfab) {
		delete dlgexpfab;
		dlgexpfab = NULL;
		statshr.jrefDlgexpfab = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgimpfab) {
		delete dlgimpfab;
		dlgimpfab = NULL;
		statshr.jrefDlgimpfab = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

bool CrdFmncFab::handleCallFmncStatChg(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixFmncVExpstate == VecFmncVExpstate::REGD) && (pnlrec->statshr.ixFmncVExpstate == VecFmncVExpstate::REGD)) pnllist->minimize(dbsfmnc, true);
	return retval;
};

bool CrdFmncFab::handleCallFmncRefPreSet(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecFmncVPreset::PREFMNCREFFAB) {
		changeRef(dbsfmnc, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsfmnc, true);
		else if ((jrefTrig == statshr.jrefDlgnew) && (refInv != 0)) {
			pnllist->qry->refresh(dbsfmnc, true);
			pnllist->minimize(dbsfmnc, true);
			pnlrec->regularize(dbsfmnc, true);
		};
	};

	return retval;
};


