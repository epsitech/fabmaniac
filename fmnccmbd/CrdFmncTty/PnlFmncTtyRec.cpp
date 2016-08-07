/**
  * \file PnlFmncTtyRec.cpp
  * job handler for job PnlFmncTtyRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncTtyRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncTtyRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncTtyRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncTtyRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncTtyRec::PnlFmncTtyRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCTTYREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlksteppar = NULL;
	pnlktoolchar = NULL;
	pnlsup1ntooltype = NULL;
	pnlrlv1nstep = NULL;
	pnlmntool = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFTTY, jref);
};

PnlFmncTtyRec::~PnlFmncTtyRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncTtyRec::getNewDpchEng(
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

void PnlFmncTtyRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubTtyStd(dbsfmnc, recTty.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recTty.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlksteppar) {delete pnlksteppar; pnlksteppar = NULL;};
		if (pnlktoolchar) {delete pnlktoolchar; pnlktoolchar = NULL;};
		if (pnlsup1ntooltype) {delete pnlsup1ntooltype; pnlsup1ntooltype = NULL;};
		if (pnlrlv1nstep) {delete pnlrlv1nstep; pnlrlv1nstep = NULL;};
		if (pnlmntool) {delete pnlmntool; pnlmntool = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncTtyDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlksteppar) pnlksteppar = new PnlFmncTtyKSteppar(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlktoolchar) pnlktoolchar = new PnlFmncTtyKToolchar(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlsup1ntooltype) pnlsup1ntooltype = new PnlFmncTtySup1NTooltype(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlrlv1nstep) pnlrlv1nstep = new PnlFmncTtyRlv1NStep(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmntool) pnlmntool = new PnlFmncTtyMNTool(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKSteppar = ((pnlksteppar) ? pnlksteppar->jref : 0);
	statshr.jrefKToolchar = ((pnlktoolchar) ? pnlktoolchar->jref : 0);
	statshr.jrefSup1NTooltype = ((pnlsup1ntooltype) ? pnlsup1ntooltype->jref : 0);
	statshr.jrefRlv1NStep = ((pnlrlv1nstep) ? pnlrlv1nstep->jref : 0);
	statshr.jrefMNTool = ((pnlmntool) ? pnlmntool->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncTtyRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFTTY) {
		FmncMTooltype* _recTty = NULL;

		recTty.ref = 0;

		if (dbsfmnc->tblfmncmtooltype->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTTY, jref), &_recTty)) {
			recTty = *_recTty;

			delete _recTty;
		};

		if (recTty.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlksteppar) pnlksteppar->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlktoolchar) pnlktoolchar->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlsup1ntooltype) pnlsup1ntooltype->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlrlv1nstep) pnlrlv1nstep->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmntool) pnlmntool->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncTtyRec::minimize(
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

void PnlFmncTtyRec::regularize(
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

void PnlFmncTtyRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTTYRECDO) {
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

void PnlFmncTtyRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncTtyRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncTtyRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncTtyRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCTTYUPD_REFEQ) {
		call->abort = handleCallFmncTtyUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncTtyRec::handleCallFmncTtyUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncTtyUpd_refEq --- INSERT
	return retval;
};


