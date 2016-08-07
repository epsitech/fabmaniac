/**
  * \file PnlFmncOrgRec.cpp
  * job handler for job PnlFmncOrgRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncOrgRec.h"

// IP blksInclude --- BEGIN
#include "PnlFmncOrgRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncOrgRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncOrgRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncOrgRec::PnlFmncOrgRec(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCORGREC, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnldetail = NULL;
	pnlkstocklcn = NULL;
	pnladetail = NULL;
	pnlbio1nfabproject = NULL;
	pnlmnf1ntool = NULL;
	pnl1narticle = NULL;
	pnlpco1npurchorder = NULL;
	pnlspl1npurchorder = NULL;
	pnl1nstockitem = NULL;
	pnlsup1norg = NULL;
	pnlhk1naddress = NULL;
	pnlmnperson = NULL;
	pnlsvcmntool = NULL;
	pnlmnarticle = NULL;

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFORG, jref);
};

PnlFmncOrgRec::~PnlFmncOrgRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncOrgRec::getNewDpchEng(
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

void PnlFmncOrgRec::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubFmnc::getStubOrgStd(dbsfmnc, recOrg.ref, ixFmncVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recOrg.ref == 0) statshr.ixFmncVExpstate = VecFmncVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsfmnc);

	if (statshr.ixFmncVExpstate == VecFmncVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlkstocklcn) {delete pnlkstocklcn; pnlkstocklcn = NULL;};
		if (pnladetail) {delete pnladetail; pnladetail = NULL;};
		if (pnlbio1nfabproject) {delete pnlbio1nfabproject; pnlbio1nfabproject = NULL;};
		if (pnlmnf1ntool) {delete pnlmnf1ntool; pnlmnf1ntool = NULL;};
		if (pnl1narticle) {delete pnl1narticle; pnl1narticle = NULL;};
		if (pnlpco1npurchorder) {delete pnlpco1npurchorder; pnlpco1npurchorder = NULL;};
		if (pnlspl1npurchorder) {delete pnlspl1npurchorder; pnlspl1npurchorder = NULL;};
		if (pnl1nstockitem) {delete pnl1nstockitem; pnl1nstockitem = NULL;};
		if (pnlsup1norg) {delete pnlsup1norg; pnlsup1norg = NULL;};
		if (pnlhk1naddress) {delete pnlhk1naddress; pnlhk1naddress = NULL;};
		if (pnlmnperson) {delete pnlmnperson; pnlmnperson = NULL;};
		if (pnlsvcmntool) {delete pnlsvcmntool; pnlsvcmntool = NULL;};
		if (pnlmnarticle) {delete pnlmnarticle; pnlmnarticle = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlFmncOrgDetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlkstocklcn) pnlkstocklcn = new PnlFmncOrgKStocklcn(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnladetail) pnladetail = new PnlFmncOrgADetail(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlbio1nfabproject) pnlbio1nfabproject = new PnlFmncOrgBio1NFabproject(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnf1ntool) pnlmnf1ntool = new PnlFmncOrgMnf1NTool(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnl1narticle) pnl1narticle = new PnlFmncOrg1NArticle(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlpco1npurchorder) pnlpco1npurchorder = new PnlFmncOrgPco1NPurchorder(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlspl1npurchorder) pnlspl1npurchorder = new PnlFmncOrgSpl1NPurchorder(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnl1nstockitem) pnl1nstockitem = new PnlFmncOrg1NStockitem(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlsup1norg) pnlsup1norg = new PnlFmncOrgSup1NOrg(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlhk1naddress) pnlhk1naddress = new PnlFmncOrgHk1NAddress(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnperson) pnlmnperson = new PnlFmncOrgMNPerson(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlsvcmntool) pnlsvcmntool = new PnlFmncOrgSvcMNTool(xchg, dbsfmnc, jref, ixFmncVLocale);
		if (!pnlmnarticle) pnlmnarticle = new PnlFmncOrgMNArticle(xchg, dbsfmnc, jref, ixFmncVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKStocklcn = ((pnlkstocklcn) ? pnlkstocklcn->jref : 0);
	statshr.jrefADetail = ((pnladetail) ? pnladetail->jref : 0);
	statshr.jrefBio1NFabproject = ((pnlbio1nfabproject) ? pnlbio1nfabproject->jref : 0);
	statshr.jrefMnf1NTool = ((pnlmnf1ntool) ? pnlmnf1ntool->jref : 0);
	statshr.jref1NArticle = ((pnl1narticle) ? pnl1narticle->jref : 0);
	statshr.jrefPco1NPurchorder = ((pnlpco1npurchorder) ? pnlpco1npurchorder->jref : 0);
	statshr.jrefSpl1NPurchorder = ((pnlspl1npurchorder) ? pnlspl1npurchorder->jref : 0);
	statshr.jref1NStockitem = ((pnl1nstockitem) ? pnl1nstockitem->jref : 0);
	statshr.jrefSup1NOrg = ((pnlsup1norg) ? pnlsup1norg->jref : 0);
	statshr.jrefHk1NAddress = ((pnlhk1naddress) ? pnlhk1naddress->jref : 0);
	statshr.jrefMNPerson = ((pnlmnperson) ? pnlmnperson->jref : 0);
	statshr.jrefSvcMNTool = ((pnlsvcmntool) ? pnlsvcmntool->jref : 0);
	statshr.jrefMNArticle = ((pnlmnarticle) ? pnlmnarticle->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncOrgRec::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFORG) {
		FmncMOrg* _recOrg = NULL;

		recOrg.ref = 0;

		if (dbsfmnc->tblfmncmorg->loadRecByRef(xchg->getRefPreset(VecFmncVPreset::PREFMNCREFORG, jref), &_recOrg)) {
			recOrg = *_recOrg;

			delete _recOrg;
		};

		if (recOrg.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlkstocklcn) pnlkstocklcn->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnladetail) pnladetail->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlbio1nfabproject) pnlbio1nfabproject->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnf1ntool) pnlmnf1ntool->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnl1narticle) pnl1narticle->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlpco1npurchorder) pnlpco1npurchorder->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlspl1npurchorder) pnlspl1npurchorder->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnl1nstockitem) pnl1nstockitem->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlsup1norg) pnlsup1norg->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlhk1naddress) pnlhk1naddress->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnperson) pnlmnperson->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlsvcmntool) pnlsvcmntool->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
			if (pnlmnarticle) pnlmnarticle->updatePreset(dbsfmnc, ixFmncVPreset, jrefTrig, notif);
		};

		refresh(dbsfmnc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncOrgRec::minimize(
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

void PnlFmncOrgRec::regularize(
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

void PnlFmncOrgRec::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGRECDO) {
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

void PnlFmncOrgRec::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncOrgRec::handleDpchAppDoButMinimizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	minimize(dbsfmnc, true, dpcheng);
};

void PnlFmncOrgRec::handleDpchAppDoButRegularizeClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	regularize(dbsfmnc, true, dpcheng);
};

void PnlFmncOrgRec::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCORGUPD_REFEQ) {
		call->abort = handleCallFmncOrgUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncOrgRec::handleCallFmncOrgUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncOrgUpd_refEq --- INSERT
	return retval;
};


