/**
  * \file PnlFmncArtDetail.cpp
  * job handler for job PnlFmncArtDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncArtDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncArtDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncArtDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncArtDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncArtDetail::PnlFmncArtDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCARTDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupTyp.tag = "FeedFPupTyp";
	dbsfmnc->fillFeedFromKlst(VecFmncVKeylist::KLSTFMNCKMARTICLETYPE, ixFmncVLocale, feedFPupTyp);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVKeylist::KLSTFMNCKMARTICLETYPE, Clstn::VecVJactype::LOCK);

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFART, jref);
};

PnlFmncArtDetail::~PnlFmncArtDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncArtDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncArtDetail::refreshPupTyp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupTyp = 0;

	for (unsigned int i=0;i<feedFPupTyp.size();i++) {
		if (feedFPupTyp.getSrefByNum(i+1) == contiac.TxfTyp) {
			contiac.numFPupTyp = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfTypValid = (contiac.numFPupTyp != 0);
	statshr.ButTypEditAvail = evalButTypEditAvail(dbsfmnc);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncArtDetail::refreshTxfTyp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfTyp = feedFPupTyp.getSrefByNum(contiac.numFPupTyp);

	// statshr
	statshr.TxfTypValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncArtDetail::refreshTyp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	// feedFPupTyp
	dbsfmnc->fillFeedFromKlst(VecFmncVKeylist::KLSTFMNCKMARTICLETYPE, ixFmncVLocale, feedFPupTyp);

	insert(moditems, DpchEngData::FEEDFPUPTYP);

	refreshPupTyp(dbsfmnc, moditems);
};

void PnlFmncArtDetail::refreshRecArt(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMArticle* _recArt = NULL;

	if (dbsfmnc->tblfmncmarticle->loadRecByRef(recArt.ref, &_recArt)) {
		recArt = *_recArt;
		delete _recArt;
	} else recArt = FmncMArticle();

	dirty = false;

	continf.TxtSrf = recArt.sref;
	contiac.TxfTit = recArt.Title;
	continf.TxtOrg = StubFmnc::getStubOrgStd(dbsfmnc, recArt.refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTol = StubFmnc::getStubTolStd(dbsfmnc, recArt.refFmncMTool, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfTyp = recArt.srefKType;
	contiac.TxfCmt = recArt.Comment;

	statshr.ButOrgViewAvail = evalButOrgViewAvail(dbsfmnc);
	statshr.ButTolViewAvail = evalButTolViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupTyp(dbsfmnc, moditems);

};

void PnlFmncArtDetail::refresh(
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

void PnlFmncArtDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFART) {
		recArt.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFART, jref);
		refreshRecArt(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncArtDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCARTDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTORGVIEWCLICK) {
					handleDpchAppDoButOrgViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTOLVIEWCLICK) {
					handleDpchAppDoButTolViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTYPEDITCLICK) {
					handleDpchAppDoButTypEditClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncArtDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncArtDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFTYP)) {
		contiac.TxfTyp = _contiac->TxfTyp;
		refreshPupTyp(dbsfmnc, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPTYP)) {
		contiac.numFPupTyp = _contiac->numFPupTyp;
		refreshTxfTyp(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncArtDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncArtDetail::handleDpchAppDoButOrgViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButOrgViewClick --- INSERT
};

void PnlFmncArtDetail::handleDpchAppDoButTolViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButTolViewClick --- INSERT
};

void PnlFmncArtDetail::handleDpchAppDoButTypEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButTypEditClick --- INSERT
};

void PnlFmncArtDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCARTUPD_REFEQ) {
		call->abort = handleCallFmncArtUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallFmncKlsAkeyMod_klsEq(dbsfmnc, call->jref, call->argInv.ix);
	};
};

bool PnlFmncArtDetail::handleCallFmncArtUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncArtUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncArtDetail::handleCallFmncKlsAkeyMod_klsEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecFmncVKeylist::KLSTFMNCKMARTICLETYPE) {
		refreshTyp(dbsfmnc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


