/**
  * \file PnlFmncRunRec.cpp
  * job handler for job PnlFmncRunRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncRunRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncRunRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncRunRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncRunRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncRunRec::PnlFmncRunRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCRUNREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlrun1nactivity = NULL;
	pnlref1nfile = NULL;
	pnlmnsample = NULL;
	pnlmnperson = NULL;
	pnlmnfab = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFRUN, jref);
};

PnlFmncRunRec::~PnlFmncRunRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncRunRec::getNewDpchEng(
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

void PnlFmncRunRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubRunStd(dbsfmnc, recRun.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recRun.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlrun1nactivity) {delete pnlrun1nactivity; pnlrun1nactivity = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
		if (pnlmnsample) {delete pnlmnsample; pnlmnsample = NULL;};
		if (pnlmnperson) {delete pnlmnperson; pnlmnperson = NULL;};
		if (pnlmnfab) {delete pnlmnfab; pnlmnfab = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncRunDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlrun1nactivity) pnlrun1nactivity = new PnlFmncRunRun1NActivity(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlFmncRunRef1NFile(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnsample) pnlmnsample = new PnlFmncRunMNSample(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnperson) pnlmnperson = new PnlFmncRunMNPerson(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnfab) pnlmnfab = new PnlFmncRunMNFab(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefRun1NActivity = ((pnlrun1nactivity) ? pnlrun1nactivity->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);
	statshr.jrefMNSample = ((pnlmnsample) ? pnlmnsample->jref : 0);
	statshr.jrefMNPerson = ((pnlmnperson) ? pnlmnperson->jref : 0);
	statshr.jrefMNFab = ((pnlmnfab) ? pnlmnfab->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncRunRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFRUN) {
		FmncMRun* _recRun = NULL;

		recRun.ref = 0;

		if (dbsfmnc->tblfmncmrun->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFRUN, jref), &_recRun)) {
			recRun = *_recRun;

			delete _recRun;
		};

		if (recRun.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlrun1nactivity) pnlrun1nactivity->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnsample) pnlmnsample->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnperson) pnlmnperson->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnfab) pnlmnfab->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncRunRec::minimize(
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

void PnlFmncRunRec::regularize(
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

void PnlFmncRunRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCRUNRECDO) {
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

void PnlFmncRunRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncRunRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncRunRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncRunRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCRUNUPD_REFEQ) {
		call->abort = handleCallFmncRunUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncRunRec::handleCallFmncRunUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncRunUpd_refEq --- INSERT
	return retval;
};


