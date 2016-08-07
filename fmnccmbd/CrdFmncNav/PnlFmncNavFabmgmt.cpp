/**
  * \file PnlFmncNavFabmgmt.cpp
  * job handler for job PnlFmncNavFabmgmt (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncNavFabmgmt.h"

// IP blksInclude --- BEGIN
#include "PnlFmncNavFabmgmt_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncNavFabmgmt_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncNavFabmgmt
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncNavFabmgmt::PnlFmncNavFabmgmt(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCNAVFABMGMT, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstBil.tag = "FeedFLstBil";
	feedFLstFab.tag = "FeedFLstFab";
	feedFLstFpj.tag = "FeedFLstFpj";
	feedFLstFus.tag = "FeedFLstFus";
	feedFLstTol.tag = "FeedFLstTol";
	feedFLstTty.tag = "FeedFLstTty";

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshFab(dbsfmnc, moditems);
	refreshFus(dbsfmnc, moditems);
	refreshTty(dbsfmnc, moditems);
	refreshTol(dbsfmnc, moditems);
	refreshFpj(dbsfmnc, moditems);
	refreshBil(dbsfmnc, moditems);
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCFAB, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCFUS, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCTTY, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCTOL, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCFPJ, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCBIL, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
};

PnlFmncNavFabmgmt::~PnlFmncNavFabmgmt() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncNavFabmgmt::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstBil, &feedFLstFab, &feedFLstFpj, &feedFLstFus, &feedFLstTol, &feedFLstTty, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncNavFabmgmt::refreshLstFab(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFabAvail = evalLstFabAvail(dbsfmnc);
	statshr.ButFabViewActive = evalButFabViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavFabmgmt::refreshFab(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFab = 0;

	// feedFLstFab
	feedFLstFab.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCFAB, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstFab.appendRefTitles(rec->ref, StubFmnc::getStubFabStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFAB);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFab(dbsfmnc, moditems);
};

void PnlFmncNavFabmgmt::refreshLstFus(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFusAvail = evalLstFusAvail(dbsfmnc);
	statshr.ButFusViewActive = evalButFusViewActive(dbsfmnc);
	statshr.ButFusNewcrdActive = evalButFusNewcrdActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavFabmgmt::refreshFus(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFus = 0;

	// feedFLstFus
	feedFLstFus.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCFUS, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstFus.appendRefTitles(rec->ref, StubFmnc::getStubFusStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFUS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFus(dbsfmnc, moditems);
};

void PnlFmncNavFabmgmt::refreshLstTty(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstTtyAvail = evalLstTtyAvail(dbsfmnc);
	statshr.ButTtyViewActive = evalButTtyViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavFabmgmt::refreshTty(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstTty = 0;

	// feedFLstTty
	feedFLstTty.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCTTY, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstTty.appendRefTitles(rec->ref, StubFmnc::getStubTtyStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTTTY);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstTty(dbsfmnc, moditems);
};

void PnlFmncNavFabmgmt::refreshLstTol(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstTolAvail = evalLstTolAvail(dbsfmnc);
	statshr.ButTolViewActive = evalButTolViewActive(dbsfmnc);
	statshr.ButTolNewcrdActive = evalButTolNewcrdActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavFabmgmt::refreshTol(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstTol = 0;

	// feedFLstTol
	feedFLstTol.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCTOL, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstTol.appendRefTitles(rec->ref, StubFmnc::getStubTolStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTTOL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstTol(dbsfmnc, moditems);
};

void PnlFmncNavFabmgmt::refreshLstFpj(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFpjAvail = evalLstFpjAvail(dbsfmnc);
	statshr.ButFpjViewActive = evalButFpjViewActive(dbsfmnc);
	statshr.ButFpjNewcrdActive = evalButFpjNewcrdActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavFabmgmt::refreshFpj(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFpj = 0;

	// feedFLstFpj
	feedFLstFpj.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCFPJ, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstFpj.appendRefTitles(rec->ref, StubFmnc::getStubFpjStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFPJ);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFpj(dbsfmnc, moditems);
};

void PnlFmncNavFabmgmt::refreshLstBil(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstBilAvail = evalLstBilAvail(dbsfmnc);
	statshr.ButBilViewActive = evalButBilViewActive(dbsfmnc);
	statshr.ButBilNewcrdActive = evalButBilNewcrdActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavFabmgmt::refreshBil(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstBil = 0;

	// feedFLstBil
	feedFLstBil.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCBIL, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstBil.appendRefTitles(rec->ref, StubFmnc::getStubBilStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTBIL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstBil(dbsfmnc, moditems);
};

void PnlFmncNavFabmgmt::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlFmncNavFabmgmt::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsfmnc, moditems);

	refreshLstFab(dbsfmnc, moditems);
	refreshLstFus(dbsfmnc, moditems);
	refreshLstTty(dbsfmnc, moditems);
	refreshLstTol(dbsfmnc, moditems);
	refreshLstFpj(dbsfmnc, moditems);
	refreshLstBil(dbsfmnc, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlFmncNavFabmgmt::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVFABMGMTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVFABMGMTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTFABVIEWCLICK) {
					handleDpchAppDoButFabViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFABNEWCRDCLICK) {
					handleDpchAppDoButFabNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFUSVIEWCLICK) {
					handleDpchAppDoButFusViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFUSNEWCRDCLICK) {
					handleDpchAppDoButFusNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTTYVIEWCLICK) {
					handleDpchAppDoButTtyViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTTYNEWCRDCLICK) {
					handleDpchAppDoButTtyNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTOLVIEWCLICK) {
					handleDpchAppDoButTolViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTOLNEWCRDCLICK) {
					handleDpchAppDoButTolNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFPJVIEWCLICK) {
					handleDpchAppDoButFpjViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFPJNEWCRDCLICK) {
					handleDpchAppDoButFpjNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBILVIEWCLICK) {
					handleDpchAppDoButBilViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBILNEWCRDCLICK) {
					handleDpchAppDoButBilNewcrdClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncNavFabmgmt::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncNavFabmgmt::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	ubigint ref;

	if (has(diffitems, ContIac::NUMFLSTFAB)) {
		contiac.numFLstFab = _contiac->numFLstFab;
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadUnuByRef(feedFLstFab.getRefByNum(contiac.numFLstFab), ref)) xchg->triggerIxRefCall(dbsfmnc, VecFmncVCall::CALLFMNCREFPRESET, jref, VecFmncVPreset::PREFMNCREFFAB, ref);
		refreshLstFab(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFUS)) {
		contiac.numFLstFus = _contiac->numFLstFus;
		refreshLstFus(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTTTY)) {
		contiac.numFLstTty = _contiac->numFLstTty;
		refreshLstTty(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTTOL)) {
		contiac.numFLstTol = _contiac->numFLstTol;
		refreshLstTol(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFPJ)) {
		contiac.numFLstFpj = _contiac->numFLstFpj;
		refreshLstFpj(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTBIL)) {
		contiac.numFLstBil = _contiac->numFLstBil;
		refreshLstBil(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncNavFabmgmt::handleDpchAppDoButFabViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFabAvail && statshr.ButFabViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstFab.getRefByNum(contiac.numFLstFab), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncFab", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncFab");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButFabNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncFab", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncFab");
};

void PnlFmncNavFabmgmt::handleDpchAppDoButFusViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFusAvail && statshr.ButFusViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstFus.getRefByNum(contiac.numFLstFus), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncFus", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncFus");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButFusNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButFusNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncFus", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncFus");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButTtyViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstTtyAvail && statshr.ButTtyViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstTty.getRefByNum(contiac.numFLstTty), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncTty", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncTty");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButTtyNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncTty", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncTty");
};

void PnlFmncNavFabmgmt::handleDpchAppDoButTolViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstTolAvail && statshr.ButTolViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstTol.getRefByNum(contiac.numFLstTol), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncTol", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncTol");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButTolNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButTolNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncTol", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncTol");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButFpjViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFpjAvail && statshr.ButFpjViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstFpj.getRefByNum(contiac.numFLstFpj), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncFpj", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncFpj");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButFpjNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButFpjNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncFpj", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncFpj");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButBilViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstBilAvail && statshr.ButBilViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstBil.getRefByNum(contiac.numFLstBil), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncBil", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncBil");
	};
};

void PnlFmncNavFabmgmt::handleDpchAppDoButBilNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButBilNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncBil", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncBil");
	};
};

void PnlFmncNavFabmgmt::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallFmncHusrRunvMod_crdUsrEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlFmncNavFabmgmt::handleCallFmncHusrRunvMod_crdUsrEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecFmncVCard::CRDFMNCFAB) {
		refreshFab(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCFUS) {
		refreshFus(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCTTY) {
		refreshTty(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCTOL) {
		refreshTol(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCFPJ) {
		refreshFpj(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCBIL) {
		refreshBil(dbsfmnc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


