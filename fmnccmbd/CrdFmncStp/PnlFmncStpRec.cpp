/**
  * \file PnlFmncStpRec.cpp
  * job handler for job PnlFmncStpRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncStpRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncStpRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncStpRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncStpRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncStpRec::PnlFmncStpRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCSTPREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlksteppar = NULL;
	pnlapar = NULL;
	pnlref1nfile = NULL;
	pnltpl1nstep = NULL;
	pnlmnfile = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFSTP, jref);
};

PnlFmncStpRec::~PnlFmncStpRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncStpRec::getNewDpchEng(
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

void PnlFmncStpRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubSteStd(dbsfmnc, recSte.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recSte.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlksteppar) {delete pnlksteppar; pnlksteppar = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
		if (pnltpl1nstep) {delete pnltpl1nstep; pnltpl1nstep = NULL;};
		if (pnlmnfile) {delete pnlmnfile; pnlmnfile = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncStpDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlksteppar) pnlksteppar = new PnlFmncStpKSteppar(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlapar) pnlapar = new PnlFmncStpAPar(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlFmncStpRef1NFile(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnltpl1nstep) pnltpl1nstep = new PnlFmncStpTpl1NStep(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnfile) pnlmnfile = new PnlFmncStpMNFile(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKSteppar = ((pnlksteppar) ? pnlksteppar->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);
	statshr.jrefTpl1NStep = ((pnltpl1nstep) ? pnltpl1nstep->jref : 0);
	statshr.jrefMNFile = ((pnlmnfile) ? pnlmnfile->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncStpRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSTP) {
		FmncMStep* _recSte = NULL;

		recSte.ref = 0;

		if (dbsfmnc->tblfmncmstep->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSTP, jref), &_recSte)) {
			recSte = *_recSte;

			delete _recSte;
		};

		if (recSte.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlksteppar) pnlksteppar->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnltpl1nstep) pnltpl1nstep->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnfile) pnlmnfile->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncStpRec::minimize(
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

void PnlFmncStpRec::regularize(
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

void PnlFmncStpRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPRECDO) {
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

void PnlFmncStpRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncStpRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncStpRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncStpRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTEUPD_REFEQ) {
		call->abort = handleCallFmncSteUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncStpRec::handleCallFmncSteUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncSteUpd_refEq --- INSERT
	return retval;
};


