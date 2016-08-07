/**
  * \file PnlFmncPrsRec.cpp
  * job handler for job PnlFmncPrsRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncPrsRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncPrsRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncPrsRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncPrsRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncPrsRec::PnlFmncPrsRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCPRSREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnladetail = NULL;
	pnlhk1naddress = NULL;
	pnlmnrun = NULL;
	pnlmnorg = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFPRS, jref);
};

PnlFmncPrsRec::~PnlFmncPrsRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncPrsRec::getNewDpchEng(
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

void PnlFmncPrsRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubPrsStd(dbsfmnc, recPrs.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recPrs.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnladetail) {delete pnladetail; pnladetail = NULL;};
		if (pnlhk1naddress) {delete pnlhk1naddress; pnlhk1naddress = NULL;};
		if (pnlmnrun) {delete pnlmnrun; pnlmnrun = NULL;};
		if (pnlmnorg) {delete pnlmnorg; pnlmnorg = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncPrsDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnladetail) pnladetail = new PnlFmncPrsADetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlhk1naddress) pnlhk1naddress = new PnlFmncPrsHk1NAddress(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnrun) pnlmnrun = new PnlFmncPrsMNRun(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnorg) pnlmnorg = new PnlFmncPrsMNOrg(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefADetail = ((pnladetail) ? pnladetail->jref : 0);
	statshr.jrefHk1NAddress = ((pnlhk1naddress) ? pnlhk1naddress->jref : 0);
	statshr.jrefMNRun = ((pnlmnrun) ? pnlmnrun->jref : 0);
	statshr.jrefMNOrg = ((pnlmnorg) ? pnlmnorg->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncPrsRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFPRS) {
		FmncMPerson* _recPrs = NULL;

		recPrs.ref = 0;

		if (dbsfmnc->tblfmncmperson->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPRS, jref), &_recPrs)) {
			recPrs = *_recPrs;

			delete _recPrs;
		};

		if (recPrs.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnladetail) pnladetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlhk1naddress) pnlhk1naddress->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnrun) pnlmnrun->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnorg) pnlmnorg->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncPrsRec::minimize(
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

void PnlFmncPrsRec::regularize(
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

void PnlFmncPrsRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSRECDO) {
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

void PnlFmncPrsRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncPrsRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncPrsRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncPrsRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCPRSUPD_REFEQ) {
		call->abort = handleCallFmncPrsUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncPrsRec::handleCallFmncPrsUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncPrsUpd_refEq --- INSERT
	return retval;
};


