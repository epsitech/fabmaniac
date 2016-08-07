/**
  * \file PnlFmncBilDetail.cpp
  * job handler for job PnlFmncBilDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncBilDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncBilDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncBilDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncBilDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncBilDetail::PnlFmncBilDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCBILDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
	VecFmncVMBillState::fillFeed(ixFmncVLocale, feedFPupSte);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFBIL, jref);
};

PnlFmncBilDetail::~PnlFmncBilDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncBilDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &feedFPupSte, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncBilDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMBillState bilJstes;
	FmncJMBillState* bilJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmbillstate->loadRstByBil(recBil.ref, false, bilJstes);

	for (unsigned int i=0;i<bilJstes.nodes.size();i++) {
		bilJste = bilJstes.nodes[i];

		s = "";
		if (bilJste->x1Startd != 0) {
			s = Ftm::date(bilJste->x1Startd) + " -";
			if ((i+2) < bilJstes.nodes.size()) if (bilJstes.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(bilJstes.nodes[i+1]->x1Startd);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(bilJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecBilJste(dbsfmnc, moditems);

};

void PnlFmncBilDetail::refreshRecBil(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMBill* _recBil = NULL;

	if (dbsfmnc->tblfmncmbill->loadRecByRef(recBil.ref, &_recBil)) {
		recBil = *_recBil;
		delete _recBil;
	} else recBil = FmncMBill();

	dirty = false;

	recBilJste.ref = recBil.refJState;
	xchg->removeClstns(VecFmncVCall::CALLFMNCBILJSTEMOD_BILEQ, jref);
	if (recBil.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCBILJSTEMOD_BILEQ, jref, Clstn::VecVJobmask::ALL, 0, recBil.ref, Clstn::VecVJactype::LOCK);

	continf.TxtSrf = recBil.sref;
	contiac.TxfDat = Ftm::date(recBil.Date);
	continf.TxtPrj = StubFmnc::getStubFpjStd(dbsfmnc, recBil.refFmncMFabproject, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtFil = StubFmnc::getStubFilStd(dbsfmnc, recBil.refFmncMFile, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfPra = Ftm::date(recBil.Prdstart);
	contiac.TxfPro = Ftm::date(recBil.Prdstop);
	contiac.TxfAmt = to_string(recBil.Amount);
	contiac.TxfCmt = recBil.Comment;

	statshr.ButPrjViewAvail = evalButPrjViewAvail(dbsfmnc);
	statshr.ButFilViewAvail = evalButFilViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);

};

void PnlFmncBilDetail::refreshRecBilJste(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncJMBillState* _recBilJste = NULL;

	if (dbsfmnc->tblfmncjmbillstate->loadRecByRef(recBilJste.ref, &_recBilJste)) {
		recBilJste = *_recBilJste;
		delete _recBilJste;
	} else recBilJste = FmncJMBillState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recBilJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recBilJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncBilDetail::refresh(
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

void PnlFmncBilDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFBIL) {
		recBil.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFBIL, jref);
		refreshRecBil(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncBilDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCBILDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJVIEWCLICK) {
					handleDpchAppDoButPrjViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncBilDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncBilDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFDAT, ContIac::NUMFPUPSTE, ContIac::TXFPRA, ContIac::TXFPRO, ContIac::TXFAMT, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFDAT)) contiac.TxfDat = _contiac->TxfDat;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::TXFPRA)) contiac.TxfPra = _contiac->TxfPra;
		if (has(diffitems, ContIac::TXFPRO)) contiac.TxfPro = _contiac->TxfPro;
		if (has(diffitems, ContIac::TXFAMT)) contiac.TxfAmt = _contiac->TxfAmt;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recBilJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecBilJste(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncBilDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncBilDetail::handleDpchAppDoButPrjViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButPrjViewClick --- INSERT
};

void PnlFmncBilDetail::handleDpchAppDoButFilViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButFilViewClick --- INSERT
};

void PnlFmncBilDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncBilDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCBILUPD_REFEQ) {
		call->abort = handleCallFmncBilUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCBILJSTEMOD_BILEQ) {
		call->abort = handleCallFmncBilJsteMod_bilEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncBilDetail::handleCallFmncBilUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncBilUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncBilDetail::handleCallFmncBilJsteMod_bilEq(
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


