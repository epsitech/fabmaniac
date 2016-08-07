/**
  * \file PnlFmncSkiDetail.cpp
  * job handler for job PnlFmncSkiDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncSkiDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncSkiDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncSkiDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncSkiDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncSkiDetail::PnlFmncSkiDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCSKIDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupLcn.tag = "FeedFPupLcn";
	dbsfmnc->fillFeedFromKlst(VecFmncVKeylist::KLSTFMNCKSTOCKLCN, ixFmncVLocale, feedFPupLcn);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVKeylist::KLSTFMNCKSTOCKLCN, Clstn::VecVJactype::LOCK);

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFSKI, jref);
};

PnlFmncSkiDetail::~PnlFmncSkiDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncSkiDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &feedFPupLcn, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncSkiDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMStockitemQuantity skiJqtys;
	FmncJMStockitemQuantity* skiJqty = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmstockitemquantity->loadRstBySki(recSki.ref, false, skiJqtys);

	for (unsigned int i=0;i<skiJqtys.nodes.size();i++) {
		skiJqty = skiJqtys.nodes[i];

		s = "";
		if (skiJqty->x1Startd != 0) {
			s = Ftm::date(skiJqty->x1Startd) + " -";
			if ((i+2) < skiJqtys.nodes.size()) if (skiJqtys.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(skiJqtys.nodes[i+1]->x1Startd);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(skiJqty->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecSkiJqty(dbsfmnc, moditems);

};

void PnlFmncSkiDetail::refreshPupLcn(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupLcn = 0;

	for (unsigned int i=0;i<feedFPupLcn.size();i++) {
		if (feedFPupLcn.getSrefByNum(i+1) == contiac.TxfLcn) {
			contiac.numFPupLcn = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfLcnValid = (contiac.numFPupLcn != 0);
	statshr.ButLcnEditAvail = evalButLcnEditAvail(dbsfmnc);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncSkiDetail::refreshTxfLcn(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfLcn = feedFPupLcn.getSrefByNum(contiac.numFPupLcn);

	// statshr
	statshr.TxfLcnValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncSkiDetail::refreshLcn(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	// feedFPupLcn
	dbsfmnc->fillFeedFromKlst(VecFmncVKeylist::KLSTFMNCKSTOCKLCN, ixFmncVLocale, feedFPupLcn);

	insert(moditems, DpchEngData::FEEDFPUPLCN);

	refreshPupLcn(dbsfmnc, moditems);
};

void PnlFmncSkiDetail::refreshRecSki(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMStockitem* _recSki = NULL;

	if (dbsfmnc->tblfmncmstockitem->loadRecByRef(recSki.ref, &_recSki)) {
		recSki = *_recSki;
		delete _recSki;
	} else recSki = FmncMStockitem();

	dirty = false;

	recSkiJqty.ref = recSki.refJQuantity;
	xchg->removeClstns(VecFmncVCall::CALLFMNCSKIJQTYMOD_SKIEQ, jref);
	if (recSki.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCSKIJQTYMOD_SKIEQ, jref, Clstn::VecVJobmask::ALL, 0, recSki.ref, Clstn::VecVJactype::LOCK);

	continf.TxtOrg = StubFmnc::getStubOrgStd(dbsfmnc, recSki.refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtArt = StubFmnc::getStubArtStd(dbsfmnc, recSki.refFmncMArticle, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfLcn = recSki.osrefFmncKStocklcn;
	contiac.TxfExd = Ftm::date(recSki.Expdate);
	contiac.TxfCmt = recSki.Comment;

	statshr.ButOrgViewAvail = evalButOrgViewAvail(dbsfmnc);
	statshr.ButArtViewAvail = evalButArtViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);
	refreshPupLcn(dbsfmnc, moditems);

};

void PnlFmncSkiDetail::refreshRecSkiJqty(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncJMStockitemQuantity* _recSkiJqty = NULL;

	if (dbsfmnc->tblfmncjmstockitemquantity->loadRecByRef(recSkiJqty.ref, &_recSkiJqty)) {
		recSkiJqty = *_recSkiJqty;
		delete _recSkiJqty;
	} else recSkiJqty = FmncJMStockitemQuantity();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recSkiJqty.ref);
	continf.TxtQty = recSkiJqty.Quantity;

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncSkiDetail::refresh(
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

void PnlFmncSkiDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSKI) {
		recSki.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSKI, jref);
		refreshRecSki(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncSkiDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSKIDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSKIDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTORGVIEWCLICK) {
					handleDpchAppDoButOrgViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTARTVIEWCLICK) {
					handleDpchAppDoButArtViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLCNEDITCLICK) {
					handleDpchAppDoButLcnEditClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncSkiDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncSkiDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFEXD, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFEXD)) contiac.TxfExd = _contiac->TxfExd;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recSkiJqty.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecSkiJqty(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::TXFLCN)) {
		contiac.TxfLcn = _contiac->TxfLcn;
		refreshPupLcn(dbsfmnc, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPLCN)) {
		contiac.numFPupLcn = _contiac->numFPupLcn;
		refreshTxfLcn(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncSkiDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncSkiDetail::handleDpchAppDoButOrgViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButOrgViewClick --- INSERT
};

void PnlFmncSkiDetail::handleDpchAppDoButArtViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButArtViewClick --- INSERT
};

void PnlFmncSkiDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncSkiDetail::handleDpchAppDoButLcnEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButLcnEditClick --- INSERT
};

void PnlFmncSkiDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSKIUPD_REFEQ) {
		call->abort = handleCallFmncSkiUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallFmncKlsAkeyMod_klsMtbUrfEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSKIJQTYMOD_SKIEQ) {
		call->abort = handleCallFmncSkiJqtyMod_skiEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncSkiDetail::handleCallFmncSkiUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncSkiUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncSkiDetail::handleCallFmncKlsAkeyMod_klsMtbUrfEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval = false;
// IP handleCallFmncKlsAkeyMod_klsMtbUrfEq --- INSERT
	return retval;
};

bool PnlFmncSkiDetail::handleCallFmncSkiJqtyMod_skiEq(
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


