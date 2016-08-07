/**
  * \file PnlFmncNavSupply.cpp
  * job handler for job PnlFmncNavSupply (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncNavSupply.h"

// IP blksInclude --- BEGIN
#include "PnlFmncNavSupply_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncNavSupply_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncNavSupply
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncNavSupply::PnlFmncNavSupply(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCNAVSUPPLY, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstArt.tag = "FeedFLstArt";
	feedFLstPco.tag = "FeedFLstPco";
	feedFLstSki.tag = "FeedFLstSki";

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshArt(dbsfmnc, moditems);
	refreshSki(dbsfmnc, moditems);
	refreshPco(dbsfmnc, moditems);
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCART, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCSKI, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCPCO, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
};

PnlFmncNavSupply::~PnlFmncNavSupply() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncNavSupply::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstArt, &feedFLstPco, &feedFLstSki, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncNavSupply::refreshLstArt(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstArtAvail = evalLstArtAvail(dbsfmnc);
	statshr.ButArtViewActive = evalButArtViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavSupply::refreshArt(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstArt = 0;

	// feedFLstArt
	feedFLstArt.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCART, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstArt.appendRefTitles(rec->ref, StubFmnc::getStubArtStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTART);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstArt(dbsfmnc, moditems);
};

void PnlFmncNavSupply::refreshLstSki(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSkiAvail = evalLstSkiAvail(dbsfmnc);
	statshr.ButSkiViewActive = evalButSkiViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavSupply::refreshSki(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSki = 0;

	// feedFLstSki
	feedFLstSki.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCSKI, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstSki.appendRefTitles(rec->ref, StubFmnc::getStubSkiStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSKI);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSki(dbsfmnc, moditems);
};

void PnlFmncNavSupply::refreshLstPco(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPcoAvail = evalLstPcoAvail(dbsfmnc);
	statshr.ButPcoViewActive = evalButPcoViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavSupply::refreshPco(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPco = 0;

	// feedFLstPco
	feedFLstPco.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCPCO, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPco.appendRefTitles(rec->ref, StubFmnc::getStubPcoStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPCO);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPco(dbsfmnc, moditems);
};

void PnlFmncNavSupply::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlFmncNavSupply::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsfmnc, moditems);

	refreshLstArt(dbsfmnc, moditems);
	refreshLstSki(dbsfmnc, moditems);
	refreshLstPco(dbsfmnc, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlFmncNavSupply::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVSUPPLYDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVSUPPLYDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTARTVIEWCLICK) {
					handleDpchAppDoButArtViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTARTNEWCRDCLICK) {
					handleDpchAppDoButArtNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSKIVIEWCLICK) {
					handleDpchAppDoButSkiViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSKINEWCRDCLICK) {
					handleDpchAppDoButSkiNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPCOVIEWCLICK) {
					handleDpchAppDoButPcoViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPCONEWCRDCLICK) {
					handleDpchAppDoButPcoNewcrdClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncNavSupply::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncNavSupply::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTART)) {
		contiac.numFLstArt = _contiac->numFLstArt;
		refreshLstArt(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSKI)) {
		contiac.numFLstSki = _contiac->numFLstSki;
		refreshLstSki(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPCO)) {
		contiac.numFLstPco = _contiac->numFLstPco;
		refreshLstPco(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncNavSupply::handleDpchAppDoButArtViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstArtAvail && statshr.ButArtViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstArt.getRefByNum(contiac.numFLstArt), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncArt", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncArt");
	};
};

void PnlFmncNavSupply::handleDpchAppDoButArtNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncArt", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncArt");
};

void PnlFmncNavSupply::handleDpchAppDoButSkiViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSkiAvail && statshr.ButSkiViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstSki.getRefByNum(contiac.numFLstSki), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncSki", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncSki");
	};
};

void PnlFmncNavSupply::handleDpchAppDoButSkiNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncSki", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncSki");
};

void PnlFmncNavSupply::handleDpchAppDoButPcoViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPcoAvail && statshr.ButPcoViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstPco.getRefByNum(contiac.numFLstPco), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncPco", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncPco");
	};
};

void PnlFmncNavSupply::handleDpchAppDoButPcoNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncPco", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncPco");
};

void PnlFmncNavSupply::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallFmncHusrRunvMod_crdUsrEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlFmncNavSupply::handleCallFmncHusrRunvMod_crdUsrEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecFmncVCard::CRDFMNCART) {
		refreshArt(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCSKI) {
		refreshSki(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCPCO) {
		refreshPco(dbsfmnc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


