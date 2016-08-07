/**
  * \file PnlFmncNavAdmin.cpp
  * job handler for job PnlFmncNavAdmin (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncNavAdmin.h"

// IP blksInclude --- BEGIN
#include "PnlFmncNavAdmin_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncNavAdmin_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncNavAdmin
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncNavAdmin::PnlFmncNavAdmin(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCNAVADMIN, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstAdr.tag = "FeedFLstAdr";
	feedFLstFil.tag = "FeedFLstFil";
	feedFLstOrg.tag = "FeedFLstOrg";
	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";

// IP constructor.cust1 --- INSERT

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshUsg(dbsfmnc, moditems);
	refreshUsr(dbsfmnc, moditems);
	refreshOrg(dbsfmnc, moditems);
	refreshPrs(dbsfmnc, moditems);
	refreshAdr(dbsfmnc, moditems);
	refreshFil(dbsfmnc, moditems);
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCUSG, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCUSR, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCORG, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCPRS, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCADR, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecFmncVCard::CRDFMNCFIL, xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), Clstn::VecVJactype::LOCK);
};

PnlFmncNavAdmin::~PnlFmncNavAdmin() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncNavAdmin::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstAdr, &feedFLstFil, &feedFLstOrg, &feedFLstPrs, &feedFLstUsg, &feedFLstUsr, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncNavAdmin::refreshLstUsg(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsgAvail = evalLstUsgAvail(dbsfmnc);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavAdmin::refreshUsg(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsg = 0;

	// feedFLstUsg
	feedFLstUsg.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCUSG, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstUsg.appendRefTitles(rec->ref, StubFmnc::getStubUsgStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsg(dbsfmnc, moditems);
};

void PnlFmncNavAdmin::refreshLstUsr(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsrAvail = evalLstUsrAvail(dbsfmnc);
	statshr.ButUsrViewActive = evalButUsrViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavAdmin::refreshUsr(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsr = 0;

	// feedFLstUsr
	feedFLstUsr.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCUSR, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstUsr.appendRefTitles(rec->ref, StubFmnc::getStubUsrStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsr(dbsfmnc, moditems);
};

void PnlFmncNavAdmin::refreshLstOrg(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstOrgAvail = evalLstOrgAvail(dbsfmnc);
	statshr.ButOrgViewActive = evalButOrgViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavAdmin::refreshOrg(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstOrg = 0;

	// feedFLstOrg
	feedFLstOrg.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCORG, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstOrg.appendRefTitles(rec->ref, StubFmnc::getStubOrgStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTORG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstOrg(dbsfmnc, moditems);
};

void PnlFmncNavAdmin::refreshLstPrs(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrsAvail = evalLstPrsAvail(dbsfmnc);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavAdmin::refreshPrs(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrs = 0;

	// feedFLstPrs
	feedFLstPrs.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCPRS, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPrs.appendRefTitles(rec->ref, StubFmnc::getStubPrsStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrs(dbsfmnc, moditems);
};

void PnlFmncNavAdmin::refreshLstAdr(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstAdrAvail = evalLstAdrAvail(dbsfmnc);
	statshr.ButAdrViewActive = evalButAdrViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavAdmin::refreshAdr(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstAdr = 0;

	// feedFLstAdr
	feedFLstAdr.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCADR, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstAdr.appendRefTitles(rec->ref, StubFmnc::getStubAdrStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTADR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstAdr(dbsfmnc, moditems);
};

void PnlFmncNavAdmin::refreshLstFil(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFilAvail = evalLstFilAvail(dbsfmnc);
	statshr.ButFilViewActive = evalButFilViewActive(dbsfmnc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlFmncNavAdmin::refreshFil(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListFmncHistRMUserUniversal rst;
	FmncHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFil = 0;

	// feedFLstFil
	feedFLstFil.clear();

	dbsfmnc->tblfmnchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecFmncVPreset::PREFMNCOWN, jref), VecFmncVCard::CRDFMNCFIL, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstFil.appendRefTitles(rec->ref, StubFmnc::getStubFilStd(dbsfmnc, rec->unvUref, ixFmncVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFIL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFil(dbsfmnc, moditems);
};

void PnlFmncNavAdmin::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
// IP refresh --- INSERT
};

void PnlFmncNavAdmin::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsfmnc, moditems);

	refreshLstUsg(dbsfmnc, moditems);
	refreshLstUsr(dbsfmnc, moditems);
	refreshLstOrg(dbsfmnc, moditems);
	refreshLstPrs(dbsfmnc, moditems);
	refreshLstAdr(dbsfmnc, moditems);
	refreshLstFil(dbsfmnc, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
// IP updatePreset --- END
};

void PnlFmncNavAdmin::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVADMINDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCNAVADMINDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGNEWCRDCLICK) {
					handleDpchAppDoButUsgNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRVIEWCLICK) {
					handleDpchAppDoButUsrViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRNEWCRDCLICK) {
					handleDpchAppDoButUsrNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTORGVIEWCLICK) {
					handleDpchAppDoButOrgViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTORGNEWCRDCLICK) {
					handleDpchAppDoButOrgNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSNEWCRDCLICK) {
					handleDpchAppDoButPrsNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTADRVIEWCLICK) {
					handleDpchAppDoButAdrViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTADRNEWCRDCLICK) {
					handleDpchAppDoButAdrNewcrdClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILNEWCRDCLICK) {
					handleDpchAppDoButFilNewcrdClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncNavAdmin::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncNavAdmin::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTUSG)) {
		contiac.numFLstUsg = _contiac->numFLstUsg;
		refreshLstUsg(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUSR)) {
		contiac.numFLstUsr = _contiac->numFLstUsr;
		refreshLstUsr(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTORG)) {
		contiac.numFLstOrg = _contiac->numFLstOrg;
		refreshLstOrg(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRS)) {
		contiac.numFLstPrs = _contiac->numFLstPrs;
		refreshLstPrs(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTADR)) {
		contiac.numFLstAdr = _contiac->numFLstAdr;
		refreshLstAdr(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFIL)) {
		contiac.numFLstFil = _contiac->numFLstFil;
		refreshLstFil(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncNavAdmin::handleDpchAppDoButUsgViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsgAvail && statshr.ButUsgViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstUsg.getRefByNum(contiac.numFLstUsg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncUsg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncUsg");
	};
};

void PnlFmncNavAdmin::handleDpchAppDoButUsgNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncUsg");
};

void PnlFmncNavAdmin::handleDpchAppDoButUsrViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsrAvail && statshr.ButUsrViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstUsr.getRefByNum(contiac.numFLstUsr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncUsr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncUsr");
	};
};

void PnlFmncNavAdmin::handleDpchAppDoButUsrNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncUsr");
};

void PnlFmncNavAdmin::handleDpchAppDoButOrgViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstOrgAvail && statshr.ButOrgViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstOrg.getRefByNum(contiac.numFLstOrg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncOrg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncOrg");
	};
};

void PnlFmncNavAdmin::handleDpchAppDoButOrgNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncOrg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncOrg");
};

void PnlFmncNavAdmin::handleDpchAppDoButPrsViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrsAvail && statshr.ButPrsViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstPrs.getRefByNum(contiac.numFLstPrs), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncPrs", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncPrs");
	};
};

void PnlFmncNavAdmin::handleDpchAppDoButPrsNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncPrs");
};

void PnlFmncNavAdmin::handleDpchAppDoButAdrViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstAdrAvail && statshr.ButAdrViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstAdr.getRefByNum(contiac.numFLstAdr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncAdr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncAdr");
	};
};

void PnlFmncNavAdmin::handleDpchAppDoButAdrNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncAdr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncAdr");
};

void PnlFmncNavAdmin::handleDpchAppDoButFilViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	FmncHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFilAvail && statshr.ButFilViewActive) {
		if (dbsfmnc->tblfmnchistrmuseruniversal->loadRecByRef(feedFLstFil.getRefByNum(contiac.numFLstFil), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, husrRunv->ixFmncVPreset, husrRunv->preUref, "CrdFmncFil", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
		else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncFil");
	};
};

void PnlFmncNavAdmin::handleDpchAppDoButFilNewcrdClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncFil");
};

void PnlFmncNavAdmin::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallFmncHusrRunvMod_crdUsrEq(dbsfmnc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlFmncNavAdmin::handleCallFmncHusrRunvMod_crdUsrEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecFmncVCard::CRDFMNCUSG) {
		refreshUsg(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCUSR) {
		refreshUsr(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCORG) {
		refreshOrg(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCPRS) {
		refreshPrs(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCADR) {
		refreshAdr(dbsfmnc, moditems);
	} else if (ixInv == VecFmncVCard::CRDFMNCFIL) {
		refreshFil(dbsfmnc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


