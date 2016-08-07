/**
  * \file PnlFmncTolDetail.cpp
  * job handler for job PnlFmncTolDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncTolDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncTolDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncTolDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncTolDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncTolDetail::PnlFmncTolDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCTOLDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFTOL, jref);
};

PnlFmncTolDetail::~PnlFmncTolDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncTolDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncTolDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMToolUnitprice tolJuprs;
	FmncJMToolUnitprice* tolJupr = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmtoolunitprice->loadRstByTol(recTol.ref, false, tolJuprs);

	for (unsigned int i=0;i<tolJuprs.nodes.size();i++) {
		tolJupr = tolJuprs.nodes[i];

		s = "";
		if (tolJupr->x1Startd != 0) {
			s = Ftm::date(tolJupr->x1Startd) + " -";
			if ((i+2) < tolJuprs.nodes.size()) if (tolJuprs.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(tolJuprs.nodes[i+1]->x1Startd);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(tolJupr->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecTolJupr(dbsfmnc, moditems);

};

void PnlFmncTolDetail::refreshRecTol(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMTool* _recTol = NULL;

	if (dbsfmnc->tblfmncmtool->loadRecByRef(recTol.ref, &_recTol)) {
		recTol = *_recTol;
		delete _recTol;
	} else recTol = FmncMTool();

	dirty = false;

	recTolJupr.ref = recTol.refJUnitprice;
	xchg->removeClstns(VecFmncVCall::CALLFMNCTOLJUPRMOD_TOLEQ, jref);
	if (recTol.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCTOLJUPRMOD_TOLEQ, jref, Clstn::VecVJobmask::ALL, 0, recTol.ref, Clstn::VecVJactype::LOCK);

	contiac.TxfTit = recTol.Title;
	continf.TxtFab = StubFmnc::getStubFabStd(dbsfmnc, recTol.fabRefFmncMFab, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtMnf = StubFmnc::getStubOrgStd(dbsfmnc, recTol.mnfRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfTrn = recTol.Training;
	contiac.TxfCmt = recTol.Comment;

	statshr.ButFabViewAvail = evalButFabViewAvail(dbsfmnc);
	statshr.ButMnfViewAvail = evalButMnfViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);

};

void PnlFmncTolDetail::refreshRecTolJupr(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncJMToolUnitprice* _recTolJupr = NULL;

	if (dbsfmnc->tblfmncjmtoolunitprice->loadRecByRef(recTolJupr.ref, &_recTolJupr)) {
		recTolJupr = *_recTolJupr;
		delete _recTolJupr;
	} else recTolJupr = FmncJMToolUnitprice();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recTolJupr.ref);
	continf.TxtUpr = to_string(recTolJupr.Unitprice);

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncTolDetail::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbsfmnc);
	statshr.ButSaveActive = evalButSaveActive(dbsfmnc);
// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncTolDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFTOL) {
		recTol.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFTOL, jref);
		refreshRecTol(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncTolDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCTOLDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFABVIEWCLICK) {
					handleDpchAppDoButFabViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMNFVIEWCLICK) {
					handleDpchAppDoButMnfViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncTolDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncTolDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFTRN, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFTRN)) contiac.TxfTrn = _contiac->TxfTrn;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recTolJupr.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecTolJupr(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncTolDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncTolDetail::handleDpchAppDoButFabViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButFabViewClick --- INSERT
};

void PnlFmncTolDetail::handleDpchAppDoButMnfViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButMnfViewClick --- INSERT
};

void PnlFmncTolDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncTolDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCTOLUPD_REFEQ) {
		call->abort = handleCallFmncTolUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLJUPRMOD_TOLEQ) {
		call->abort = handleCallFmncTolJuprMod_tolEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncTolDetail::handleCallFmncTolUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncTolUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncTolDetail::handleCallFmncTolJuprMod_tolEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbsfmnc, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


