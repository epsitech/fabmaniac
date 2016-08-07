/**
  * \file PnlFmncFusRec.cpp
  * job handler for job PnlFmncFusRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncFusRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncFusRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncFusRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncFusRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncFusRec::PnlFmncFusRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCFUSREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlmntool = NULL;
	pnlmnfabproject = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFFUS, jref);
};

PnlFmncFusRec::~PnlFmncFusRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncFusRec::getNewDpchEng(
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

void PnlFmncFusRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubFusStd(dbsfmnc, recFus.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recFus.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlmntool) {delete pnlmntool; pnlmntool = NULL;};
		if (pnlmnfabproject) {delete pnlmnfabproject; pnlmnfabproject = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncFusDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmntool) pnlmntool = new PnlFmncFusMNTool(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnfabproject) pnlmnfabproject = new PnlFmncFusMNFabproject(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefMNTool = ((pnlmntool) ? pnlmntool->jref : 0);
	statshr.jrefMNFabproject = ((pnlmnfabproject) ? pnlmnfabproject->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncFusRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFUS) {
		FmncMFabuser* _recFus = NULL;

		recFus.ref = 0;

		if (dbsfmnc->tblfmncmfabuser->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFUS, jref), &_recFus)) {
			recFus = *_recFus;

			delete _recFus;
		};

		if (recFus.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmntool) pnlmntool->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnfabproject) pnlmnfabproject->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncFusRec::minimize(
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

void PnlFmncFusRec::regularize(
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

void PnlFmncFusRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSRECDO) {
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

void PnlFmncFusRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncFusRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncFusRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncFusRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCFUSUPD_REFEQ) {
		call->abort = handleCallFmncFusUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncFusRec::handleCallFmncFusUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncFusUpd_refEq --- INSERT
	return retval;
};


