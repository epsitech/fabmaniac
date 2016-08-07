/**
  * \file PnlFmncFilRec.cpp
  * job handler for job PnlFmncFilRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncFilRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncFilRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncFilRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncFilRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncFilRec::PnlFmncFilRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCFILREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlmnsample = NULL;
	pnlmnstep = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecFmncVCall::CALLFMNCFIL_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFFIL, jref);
};

PnlFmncFilRec::~PnlFmncFilRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncFilRec::getNewDpchEng(
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

void PnlFmncFilRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubFilStd(dbsfmnc, recFil.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recFil.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlmnsample) {delete pnlmnsample; pnlmnsample = NULL;};
		if (pnlmnstep) {delete pnlmnstep; pnlmnstep = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncFilDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnsample) pnlmnsample = new PnlFmncFilMNSample(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnstep) pnlmnstep = new PnlFmncFilMNStep(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefMNSample = ((pnlmnsample) ? pnlmnsample->jref : 0);
	statshr.jrefMNStep = ((pnlmnstep) ? pnlmnstep->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncFilRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFIL) {
		FmncMFile* _recFil = NULL;

		recFil.ref = 0;

		if (dbsfmnc->tblfmncmfile->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFIL, jref), &_recFil)) {
			recFil = *_recFil;

			delete _recFil;
		};

		if (recFil.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnsample) pnlmnsample->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnstep) pnlmnstep->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncFilRec::minimize(
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

void PnlFmncFilRec::regularize(
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

void PnlFmncFilRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFILRECDO) {
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

void PnlFmncFilRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncFilRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncFilRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncFilRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCFIL_CLUEQ) {
		call->abort = handleCallFmncFil_cluEq(dbsfmnc, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFILUPD_REFEQ) {
		call->abort = handleCallFmncFilUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncFilRec::handleCallFmncFil_cluEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
// IP handleCallFmncFil_cluEq --- BEGIN
		if (recFil.ref != 0) boolvalRet = (recFil.refFmncCFile == refInv);
// IP handleCallFmncFil_cluEq --- END
	return retval;
};

bool PnlFmncFilRec::handleCallFmncFilUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncFilUpd_refEq --- INSERT
	return retval;
};


