/**
  * \file PnlFmncNavLabbook.cpp
  * job handler for job PnlFmncNavLabbook (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncNavLabbook.h"

// IP blksInclude --- BEGIN
#include "PnlFmncNavLabbook_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncNavLabbook_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncNavLabbook
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncNavLabbook::PnlFmncNavLabbook(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCNAVLABBOOK, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstAct.tag = "FeedFLstAct";
	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstRun.tag = "FeedFLstRun";
	feedFLstSep.tag = "FeedFLstSep";
	feedFLstSmp.tag = "FeedFLstSmp";
	feedFLstStp.tag = "FeedFLstStp";

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshStp(dbsfmnc, moditems);
	refreshPrj(dbsfmnc, moditems);
	refreshRun(dbsfmnc, moditems);
	refreshAct(dbsfmnc, moditems);
	refreshSep(dbsfmnc, moditems);
	refreshSmp(dbsfmnc, moditems);
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCSTP, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCPRJ, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCRUN, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCACT, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCSEP, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCSMP, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
};

PnlFmncNavLabbook::~PnlFmncNavLabbook() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncNavLabbook::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstAct, &feedFLstPrj, &feedFLstRun, &feedFLstSep, &feedFLstSmp, &feedFLstStp, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncNavLabbook::refreshLstStp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstStpAvail = evalLstStpAvail(dbsfmnc);
	statshr.ButStpViewActive = evalButStpViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavLabbook::refreshStp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstStp = 0;

	// feedFLstStp
	feedFLstStp.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCSTP, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstStp.appendRefTitles(rec->ref, StubFmnc::getStubSteStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSTP);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstStp(dbsfmnc, moditems);
};

void PnlFmncNavLabbook::refreshLstPrj(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrjAvail = evalLstPrjAvail(dbsfmnc);
	statshr.ButPrjViewActive = evalButPrjViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavLabbook::refreshPrj(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrj = 0;

	// feedFLstPrj
	feedFLstPrj.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCPRJ, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPrj.appendRefTitles(rec->ref, StubFmnc::getStubPrjStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRJ);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrj(dbsfmnc, moditems);
};

void PnlFmncNavLabbook::refreshLstRun(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRunAvail = evalLstRunAvail(dbsfmnc);
	statshr.ButRunViewActive = evalButRunViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavLabbook::refreshRun(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstRun = 0;

	// feedFLstRun
	feedFLstRun.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCRUN, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstRun.appendRefTitles(rec->ref, StubFmnc::getStubRunStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTRUN);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstRun(dbsfmnc, moditems);
};

void PnlFmncNavLabbook::refreshLstAct(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstActAvail = evalLstActAvail(dbsfmnc);
	statshr.ButActViewActive = evalButActViewActive(dbsfmnc);
	statshr.ButActNewcrdActive = evalButActNewcrdActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavLabbook::refreshAct(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstAct = 0;

	// feedFLstAct
	feedFLstAct.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCACT, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstAct.appendRefTitles(rec->ref, StubFmnc::getStubActStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTACT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstAct(dbsfmnc, moditems);
};

void PnlFmncNavLabbook::refreshLstSep(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSepAvail = evalLstSepAvail(dbsfmnc);
	statshr.ButSepViewActive = evalButSepViewActive(dbsfmnc);
	statshr.ButSepNewcrdActive = evalButSepNewcrdActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavLabbook::refreshSep(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSep = 0;

	// feedFLstSep
	feedFLstSep.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCSEP, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstSep.appendRefTitles(rec->ref, StubFmnc::getStubSepStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSEP);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSep(dbsfmnc, moditems);
};

void PnlFmncNavLabbook::refreshLstSmp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSmpAvail = evalLstSmpAvail(dbsfmnc);
	statshr.ButSmpViewActive = evalButSmpViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavLabbook::refreshSmp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSmp = 0;

	// feedFLstSmp
	feedFLstSmp.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCSMP, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstSmp.appendRefTitles(rec->ref, StubFmnc::getStubSmpStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSMP);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSmp(dbsfmnc, moditems);
};

void PnlFmncNavLabbook::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlFmncNavLabbook::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsfmnc, moditems);

	refreshLstStp(dbsfmnc, moditems);
	refreshLstPrj(dbsfmnc, moditems);
	refreshLstRun(dbsfmnc, moditems);
	refreshLstAct(dbsfmnc, moditems);
	refreshLstSep(dbsfmnc, moditems);
	refreshLstSmp(dbsfmnc, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlFmncNavLabbook::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVLABBOOKDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVLABBOOKDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSTPVIEWCLICK) {
					handleDpchAppDoButStpViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTPNEWCRDCLICK) {
					handleDpchAppDoButStpNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJVIEWCLICK) {
					handleDpchAppDoButPrjViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJNEWCRDCLICK) {
					handleDpchAppDoButPrjNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRUNVIEWCLICK) {
					handleDpchAppDoButRunViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRUNNEWCRDCLICK) {
					handleDpchAppDoButRunNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTACTVIEWCLICK) {
					handleDpchAppDoButActViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTACTNEWCRDCLICK) {
					handleDpchAppDoButActNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSEPVIEWCLICK) {
					handleDpchAppDoButSepViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSEPNEWCRDCLICK) {
					handleDpchAppDoButSepNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSMPVIEWCLICK) {
					handleDpchAppDoButSmpViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSMPNEWCRDCLICK) {
					handleDpchAppDoButSmpNewcrdClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncNavLabbook::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncNavLabbook::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	ubigint ref;

	if (has(diffitems, ContIac::NUMFLSTSTP)) {
		contiac.numFLstStp = _contiac->numFLstStp;
		refreshLstStp(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRJ)) {
		contiac.numFLstPrj = _contiac->numFLstPrj;
		refreshLstPrj(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTRUN)) {
		contiac.numFLstRun = _contiac->numFLstRun;
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadUnuByRef(feedFLstRun.getRefByNum(contiac.numFLstRun), ref)) xchg->triggerIxRefCall(dbsfmnc, VecFmncVCall::CALLFMNCREFPRESET, jref, VecFmncVPreset::PREFMNCREFRUN, ref);
		refreshLstRun(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTACT)) {
		contiac.numFLstAct = _contiac->numFLstAct;
		refreshLstAct(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSEP)) {
		contiac.numFLstSep = _contiac->numFLstSep;
		refreshLstSep(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSMP)) {
		contiac.numFLstSmp = _contiac->numFLstSmp;
		refreshLstSmp(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncNavLabbook::handleDpchAppDoButStpViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstStpAvail && statshr.ButStpViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstStp.getRefByNum(contiac.numFLstStp), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncStp", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncStp");
	};
};

void PnlFmncNavLabbook::handleDpchAppDoButStpNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncStp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncStp");
};

void PnlFmncNavLabbook::handleDpchAppDoButPrjViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrjAvail && statshr.ButPrjViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstPrj.getRefByNum(contiac.numFLstPrj), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncPrj", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncPrj");
	};
};

void PnlFmncNavLabbook::handleDpchAppDoButPrjNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncPrj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncPrj");
};

void PnlFmncNavLabbook::handleDpchAppDoButRunViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstRunAvail && statshr.ButRunViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstRun.getRefByNum(contiac.numFLstRun), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncRun", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncRun");
	};
};

void PnlFmncNavLabbook::handleDpchAppDoButRunNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncRun", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncRun");
};

void PnlFmncNavLabbook::handleDpchAppDoButActViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstActAvail && statshr.ButActViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstAct.getRefByNum(contiac.numFLstAct), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncAct", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncAct");
	};
};

void PnlFmncNavLabbook::handleDpchAppDoButActNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButActNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncAct", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncAct");
	};
};

void PnlFmncNavLabbook::handleDpchAppDoButSepViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSepAvail && statshr.ButSepViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstSep.getRefByNum(contiac.numFLstSep), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncSep", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncSep");
	};
};

void PnlFmncNavLabbook::handleDpchAppDoButSepNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButSepNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncSep", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncSep");
	};
};

void PnlFmncNavLabbook::handleDpchAppDoButSmpViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSmpAvail && statshr.ButSmpViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstSmp.getRefByNum(contiac.numFLstSmp), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncSmp", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncSmp");
	};
};

void PnlFmncNavLabbook::handleDpchAppDoButSmpNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncSmp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncSmp");
};

void PnlFmncNavLabbook::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallFmncHusrRunvMod_crdUsrEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlFmncNavLabbook::handleCallFmncHusrRunvMod_crdUsrEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecFmncVCard::CRDFMNCSTP) {
		refreshStp(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCPRJ) {
		refreshPrj(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCRUN) {
		refreshRun(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCACT) {
		refreshAct(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCSEP) {
		refreshSep(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCSMP) {
		refreshSmp(dbsfmnc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


