/**
  * \file PnlFmncFabRec.cpp
  * job handler for job PnlFmncFabRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncFabRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncFabRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncFabRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncFabRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncFabRec::PnlFmncFabRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCFABREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnl1nfabproject = NULL;
	pnl1nfabuser = NULL;
	pnlfab1ntool = NULL;
	pnlmnrun = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFFAB, jref);
};

PnlFmncFabRec::~PnlFmncFabRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncFabRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncFabRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubFabStd(dbsfmnc, recFab.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recFab.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nfabproject) {delete pnl1nfabproject; pnl1nfabproject = NULL;};
		if (pnl1nfabuser) {delete pnl1nfabuser; pnl1nfabuser = NULL;};
		if (pnlfab1ntool) {delete pnlfab1ntool; pnlfab1ntool = NULL;};
		if (pnlmnrun) {delete pnlmnrun; pnlmnrun = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncFabDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnl1nfabproject) pnl1nfabproject = new PnlFmncFab1NFabproject(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnl1nfabuser) pnl1nfabuser = new PnlFmncFab1NFabuser(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlfab1ntool) pnlfab1ntool = new PnlFmncFabFab1NTool(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnrun) pnlmnrun = new PnlFmncFabMNRun(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NFabproject = ((pnl1nfabproject) ? pnl1nfabproject->jref : 0);
	statshr.jref1NFabuser = ((pnl1nfabuser) ? pnl1nfabuser->jref : 0);
	statshr.jrefFab1NTool = ((pnlfab1ntool) ? pnlfab1ntool->jref : 0);
	statshr.jrefMNRun = ((pnlmnrun) ? pnlmnrun->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncFabRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFAB) {
		FmncMFab* _recFab = NULL;

		recFab.ref = 0;

		if (dbsfmnc->tblfmncmfab->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFAB, jref), &_recFab)) {
			recFab = *_recFab;

			delete _recFab;
		};

		if (recFab.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnl1nfabproject) pnl1nfabproject->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnl1nfabuser) pnl1nfabuser->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlfab1ntool) pnlfab1ntool->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnrun) pnlmnrun->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncFabRec::minimize(
			DbsFmnc* dbsfmnc
			, const bool notif
			, DpchEngFmnc** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixFmncVExpstate != VecFmncVExpstate::MIND) {
		statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsfmnc, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlFmncFabRec::regularize(
			DbsFmnc* dbsfmnc
			, const bool notif
			, DpchEngFmnc** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixFmncVExpstate != VecFmncVExpstate::REGD) {
		statshr.ixFmncVExpstate = VecFmncVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsfmnc, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlFmncFabRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFABRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncFabRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncFabRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncFabRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncFabRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCFABUPD_REFEQ) {
		call->abort = handleCallFmncFabUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncFabRec::handleCallFmncFabUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncFabUpd_refEq --- INSERT
	return retval;
};


