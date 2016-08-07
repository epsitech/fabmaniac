/**
  * \file PnlFmncSmpRec.cpp
  * job handler for job PnlFmncSmpRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncSmpRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncSmpRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncSmpRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncSmpRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncSmpRec::PnlFmncSmpRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCSMPREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlapar = NULL;
	pnlsup1nsample = NULL;
	pnlref1nfile = NULL;
	pnlmnstep = NULL;
	pnlmnfile = NULL;
	pnlmnrun = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFSMP, jref);
};

PnlFmncSmpRec::~PnlFmncSmpRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncSmpRec::getNewDpchEng(
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

void PnlFmncSmpRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubSmpStd(dbsfmnc, recSmp.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recSmp.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlsup1nsample) {delete pnlsup1nsample; pnlsup1nsample = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
		if (pnlmnstep) {delete pnlmnstep; pnlmnstep = NULL;};
		if (pnlmnfile) {delete pnlmnfile; pnlmnfile = NULL;};
		if (pnlmnrun) {delete pnlmnrun; pnlmnrun = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncSmpDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlapar) pnlapar = new PnlFmncSmpAPar(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlsup1nsample) pnlsup1nsample = new PnlFmncSmpSup1NSample(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlFmncSmpRef1NFile(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnstep) pnlmnstep = new PnlFmncSmpMNStep(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnfile) pnlmnfile = new PnlFmncSmpMNFile(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnrun) pnlmnrun = new PnlFmncSmpMNRun(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefSup1NSample = ((pnlsup1nsample) ? pnlsup1nsample->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);
	statshr.jrefMNStep = ((pnlmnstep) ? pnlmnstep->jref : 0);
	statshr.jrefMNFile = ((pnlmnfile) ? pnlmnfile->jref : 0);
	statshr.jrefMNRun = ((pnlmnrun) ? pnlmnrun->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncSmpRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSMP) {
		FmncMSample* _recSmp = NULL;

		recSmp.ref = 0;

		if (dbsfmnc->tblfmncmsample->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSMP, jref), &_recSmp)) {
			recSmp = *_recSmp;

			delete _recSmp;
		};

		if (recSmp.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlsup1nsample) pnlsup1nsample->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnstep) pnlmnstep->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnfile) pnlmnfile->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnrun) pnlmnrun->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncSmpRec::minimize(
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

void PnlFmncSmpRec::regularize(
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

void PnlFmncSmpRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPRECDO) {
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

void PnlFmncSmpRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncSmpRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncSmpRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncSmpRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSMPUPD_REFEQ) {
		call->abort = handleCallFmncSmpUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncSmpRec::handleCallFmncSmpUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncSmpUpd_refEq --- INSERT
	return retval;
};


