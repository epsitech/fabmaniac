/**
  * \file PnlFmncAdrDetail.cpp
  * job handler for job PnlFmncAdrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncAdrDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncAdrDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncAdrDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncAdrDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncAdrDetail::PnlFmncAdrDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCADRDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupAty.tag = "FeedFPupAty";
	dbsfmnc->fillFeedFromKlst(VecFmncVKeylist::KLSTKMADDRESSADRTYPE, ixFmncVLocale, feedFPupAty);
	feedFPupCry.tag = "FeedFPupCry";
	dbsfmnc->fillFeedFromKlst(VecFmncVKeylist::KLSTFMNCKMADDRESSCOUNTRY, ixFmncVLocale, feedFPupCry);
	feedFPupHkt.tag = "FeedFPupHkt";
	VecFmncVMAddressHkTbl::fillFeed(ixFmncVLocale, feedFPupHkt);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVKeylist::KLSTKMADDRESSADRTYPE, Clstn::VecVJactype::LOCK);
	xchg->addIxClstn(VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVKeylist::KLSTFMNCKMADDRESSCOUNTRY, Clstn::VecVJactype::LOCK);

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFADR, jref);
};

PnlFmncAdrDetail::~PnlFmncAdrDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncAdrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupAty, &feedFPupCry, &feedFPupHkt, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncAdrDetail::refreshPupAty(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupAty = 0;

	for (unsigned int i=0;i<feedFPupAty.size();i++) {
		if (feedFPupAty.getSrefByNum(i+1) == contiac.TxfAty) {
			contiac.numFPupAty = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfAtyValid = (contiac.numFPupAty != 0);
	statshr.ButAtyEditAvail = evalButAtyEditAvail(dbsfmnc);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncAdrDetail::refreshTxfAty(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfAty = feedFPupAty.getSrefByNum(contiac.numFPupAty);

	// statshr
	statshr.TxfAtyValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncAdrDetail::refreshAty(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	// feedFPupAty
	dbsfmnc->fillFeedFromKlst(VecFmncVKeylist::KLSTKMADDRESSADRTYPE, ixFmncVLocale, feedFPupAty);

	insert(moditems, DpchEngData::FEEDFPUPATY);

	refreshPupAty(dbsfmnc, moditems);
};

void PnlFmncAdrDetail::refreshPupCry(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupCry = 0;

	for (unsigned int i=0;i<feedFPupCry.size();i++) {
		if (feedFPupCry.getSrefByNum(i+1) == contiac.TxfCry) {
			contiac.numFPupCry = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfCryValid = (contiac.numFPupCry != 0);
	statshr.ButCryEditAvail = evalButCryEditAvail(dbsfmnc);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncAdrDetail::refreshTxfCry(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfCry = feedFPupCry.getSrefByNum(contiac.numFPupCry);

	// statshr
	statshr.TxfCryValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncAdrDetail::refreshCry(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	// feedFPupCry
	dbsfmnc->fillFeedFromKlst(VecFmncVKeylist::KLSTFMNCKMADDRESSCOUNTRY, ixFmncVLocale, feedFPupCry);

	insert(moditems, DpchEngData::FEEDFPUPCRY);

	refreshPupCry(dbsfmnc, moditems);
};

void PnlFmncAdrDetail::refreshRecAdr(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMAddress* _recAdr = NULL;

	if (dbsfmnc->tblfmncmaddress->loadRecByRef(recAdr.ref, &_recAdr)) {
		recAdr = *_recAdr;
		delete _recAdr;
	} else recAdr = FmncMAddress();

	dirty = false;

	contiac.TxfAd1 = recAdr.Address1;
	contiac.TxfCty = recAdr.City;
	contiac.TxfSta = Ftm::date(recAdr.x1Startd);
	contiac.numFPupHkt = feedFPupHkt.getNumByIx(recAdr.hkIxVTbl);
	contiac.TxfAty = recAdr.srefKAdrtype;
	contiac.TxfAd2 = recAdr.Address2;
	contiac.TxfZip = recAdr.Zipcode;
	contiac.TxfSte = recAdr.State;
	contiac.TxfCry = recAdr.srefKCountry;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupAty(dbsfmnc, moditems);
	refreshPupCry(dbsfmnc, moditems);

};

void PnlFmncAdrDetail::refresh(
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

void PnlFmncAdrDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFADR) {
		recAdr.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFADR, jref);
		refreshRecAdr(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncAdrDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCADRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCADRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHKUVIEWCLICK) {
					handleDpchAppDoButHkuViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTATYEDITCLICK) {
					handleDpchAppDoButAtyEditClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRYEDITCLICK) {
					handleDpchAppDoButCryEditClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncAdrDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncAdrDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFAD1, ContIac::TXFCTY, ContIac::TXFSTA, ContIac::TXFAD2, ContIac::TXFZIP, ContIac::TXFSTE})) {
		if (has(diffitems, ContIac::TXFAD1)) contiac.TxfAd1 = _contiac->TxfAd1;
		if (has(diffitems, ContIac::TXFCTY)) contiac.TxfCty = _contiac->TxfCty;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFAD2)) contiac.TxfAd2 = _contiac->TxfAd2;
		if (has(diffitems, ContIac::TXFZIP)) contiac.TxfZip = _contiac->TxfZip;
		if (has(diffitems, ContIac::TXFSTE)) contiac.TxfSte = _contiac->TxfSte;
	};

	if (has(diffitems, ContIac::TXFATY)) {
		contiac.TxfAty = _contiac->TxfAty;
		refreshPupAty(dbsfmnc, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPATY)) {
		contiac.numFPupAty = _contiac->numFPupAty;
		refreshTxfAty(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::TXFCRY)) {
		contiac.TxfCry = _contiac->TxfCry;
		refreshPupCry(dbsfmnc, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPCRY)) {
		contiac.numFPupCry = _contiac->numFPupCry;
		refreshTxfCry(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncAdrDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncAdrDetail::handleDpchAppDoButHkuViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButHkuViewClick --- INSERT
};

void PnlFmncAdrDetail::handleDpchAppDoButAtyEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButAtyEditClick --- INSERT
};

void PnlFmncAdrDetail::handleDpchAppDoButCryEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButCryEditClick --- INSERT
};

void PnlFmncAdrDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCADRUPD_REFEQ) {
		call->abort = handleCallFmncAdrUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallFmncKlsAkeyMod_klsEq(dbsfmnc, call->jref, call->argInv.ix);
	};
};

bool PnlFmncAdrDetail::handleCallFmncAdrUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncAdrUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncAdrDetail::handleCallFmncKlsAkeyMod_klsEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecFmncVKeylist::KLSTKMADDRESSADRTYPE) {
		refreshAty(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVKeylist::KLSTFMNCKMADDRESSCOUNTRY) {
		refreshCry(dbsfmnc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


