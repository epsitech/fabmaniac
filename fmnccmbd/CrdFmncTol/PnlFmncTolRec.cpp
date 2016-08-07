/**
  * \file PnlFmncTolRec.cpp
  * job handler for job PnlFmncTolRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncTolRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncTolRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncTolRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncTolRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncTolRec::PnlFmncTolRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCTOLREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlksteppar = NULL;
	pnlktoolchar = NULL;
	pnlaavl = NULL;
	pnlachar = NULL;
	pnlares = NULL;
	pnlautil = NULL;
	pnl1narticle = NULL;
	pnlrlv1nstep = NULL;
	pnlref1nfile = NULL;
	pnlmntooltype = NULL;
	pnlmnfabuser = NULL;
	pnlsvcmnorg = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFTOL, jref);
};

PnlFmncTolRec::~PnlFmncTolRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncTolRec::getNewDpchEng(
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

void PnlFmncTolRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubTolStd(dbsfmnc, recTol.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recTol.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlksteppar) {delete pnlksteppar; pnlksteppar = NULL;};
		if (pnlktoolchar) {delete pnlktoolchar; pnlktoolchar = NULL;};
		if (pnlaavl) {delete pnlaavl; pnlaavl = NULL;};
		if (pnlachar) {delete pnlachar; pnlachar = NULL;};
		if (pnlares) {delete pnlares; pnlares = NULL;};
		if (pnlautil) {delete pnlautil; pnlautil = NULL;};
		if (pnl1narticle) {delete pnl1narticle; pnl1narticle = NULL;};
		if (pnlrlv1nstep) {delete pnlrlv1nstep; pnlrlv1nstep = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
		if (pnlmntooltype) {delete pnlmntooltype; pnlmntooltype = NULL;};
		if (pnlmnfabuser) {delete pnlmnfabuser; pnlmnfabuser = NULL;};
		if (pnlsvcmnorg) {delete pnlsvcmnorg; pnlsvcmnorg = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncTolDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlksteppar) pnlksteppar = new PnlFmncTolKSteppar(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlktoolchar) pnlktoolchar = new PnlFmncTolKToolchar(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlaavl) pnlaavl = new PnlFmncTolAAvl(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlachar) pnlachar = new PnlFmncTolAChar(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlares) pnlares = new PnlFmncTolARes(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlautil) pnlautil = new PnlFmncTolAUtil(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnl1narticle) pnl1narticle = new PnlFmncTol1NArticle(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlrlv1nstep) pnlrlv1nstep = new PnlFmncTolRlv1NStep(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlFmncTolRef1NFile(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmntooltype) pnlmntooltype = new PnlFmncTolMNTooltype(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnfabuser) pnlmnfabuser = new PnlFmncTolMNFabuser(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlsvcmnorg) pnlsvcmnorg = new PnlFmncTolSvcMNOrg(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKSteppar = ((pnlksteppar) ? pnlksteppar->jref : 0);
	statshr.jrefKToolchar = ((pnlktoolchar) ? pnlktoolchar->jref : 0);
	statshr.jrefAAvl = ((pnlaavl) ? pnlaavl->jref : 0);
	statshr.jrefAChar = ((pnlachar) ? pnlachar->jref : 0);
	statshr.jrefARes = ((pnlares) ? pnlares->jref : 0);
	statshr.jrefAUtil = ((pnlautil) ? pnlautil->jref : 0);
	statshr.jref1NArticle = ((pnl1narticle) ? pnl1narticle->jref : 0);
	statshr.jrefRlv1NStep = ((pnlrlv1nstep) ? pnlrlv1nstep->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);
	statshr.jrefMNTooltype = ((pnlmntooltype) ? pnlmntooltype->jref : 0);
	statshr.jrefMNFabuser = ((pnlmnfabuser) ? pnlmnfabuser->jref : 0);
	statshr.jrefSvcMNOrg = ((pnlsvcmnorg) ? pnlsvcmnorg->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncTolRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFTOL) {
		FmncMTool* _recTol = NULL;

		recTol.ref = 0;

		if (dbsfmnc->tblfmncmtool->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTOL, jref), &_recTol)) {
			recTol = *_recTol;

			delete _recTol;
		};

		if (recTol.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlksteppar) pnlksteppar->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlktoolchar) pnlktoolchar->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlaavl) pnlaavl->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlachar) pnlachar->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlares) pnlares->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlautil) pnlautil->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnl1narticle) pnl1narticle->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlrlv1nstep) pnlrlv1nstep->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmntooltype) pnlmntooltype->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnfabuser) pnlmnfabuser->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlsvcmnorg) pnlsvcmnorg->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncTolRec::minimize(
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

void PnlFmncTolRec::regularize(
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

void PnlFmncTolRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLRECDO) {
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

void PnlFmncTolRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncTolRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncTolRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncTolRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCTOLUPD_REFEQ) {
		call->abort = handleCallFmncTolUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncTolRec::handleCallFmncTolUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncTolUpd_refEq --- INSERT
	return retval;
};


