/**
  * \file PnlFmncOrgDetail.cpp
  * job handler for job PnlFmncOrgDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncOrgDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncOrgDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncOrgDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncOrgDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncOrgDetail::PnlFmncOrgDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCORGDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstDrv.tag = "FeedFLstDrv";
	VecFmncWMOrgDerivate::fillFeed(ixFmncVLocale, feedFLstDrv);
	feedFPupJ.tag = "FeedFPupJ";

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFORG, jref);
};

PnlFmncOrgDetail::~PnlFmncOrgDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncOrgDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDrv, &feedFPupJ, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncOrgDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMOrgTitle orgJtits;
	FmncJMOrgTitle* orgJtit = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmorgtitle->loadRstByOrg(recOrg.ref, false, orgJtits);

	for (unsigned int i=0;i<orgJtits.nodes.size();i++) {
		orgJtit = orgJtits.nodes[i];

		s = "";
		if (orgJtit->x1Startd != 0) {
			s = Ftm::date(orgJtit->x1Startd) + " -";
			if ((i+2) < orgJtits.nodes.size()) if (orgJtits.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(orgJtits.nodes[i+1]->x1Startd);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(orgJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecOrgJtit(dbsfmnc, moditems);

};

void PnlFmncOrgDetail::refreshTxtDrv(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i=0;i<contiac.numsFLstDrv.size();i++) ix |= feedFLstDrv.getIxByNum(contiac.numsFLstDrv[i]);
	continf.TxtDrv = VecFmncWMOrgDerivate::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlFmncOrgDetail::refreshRecOrg(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	FmncMOrg* _recOrg = NULL;

	if (dbsfmnc->tblfmncmorg->loadRecByRef(recOrg.ref, &_recOrg)) {
		recOrg = *_recOrg;
		delete _recOrg;
	} else recOrg = FmncMOrg();

	dirty = false;

	recOrgJtit.ref = recOrg.refJTitle;
	xchg->removeClstns(VecFmncVCall::CALLFMNCORGJTITMOD_ORGEQ, jref);
	if (recOrg.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCORGJTITMOD_ORGEQ, jref, Clstn::VecVJobmask::ALL, 0, recOrg.ref, Clstn::VecVJactype::LOCK);

	continf.TxtSrf = recOrg.sref;
	contiac.numsFLstDrv.clear();
	VecFmncWMOrgDerivate::getIcs(recOrg.ixWDerivate, ics);
	for (auto it=ics.begin();it!=ics.end();it++) contiac.numsFLstDrv.push_back(feedFLstDrv.getNumByIx(*it));
	continf.TxtAdr = StubFmnc::getStubAdrStd(dbsfmnc, recOrg.refFmncMAddress, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSup = StubFmnc::getStubOrgStd(dbsfmnc, recOrg.supRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfTel = recOrg.Tel;
	contiac.TxfEml = recOrg.Eml;

	statshr.ButAdrViewAvail = evalButAdrViewAvail(dbsfmnc);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);
	refreshTxtDrv(dbsfmnc, moditems);

};

void PnlFmncOrgDetail::refreshRecOrgJtit(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	FmncJMOrgTitle* _recOrgJtit = NULL;

	if (dbsfmnc->tblfmncjmorgtitle->loadRecByRef(recOrgJtit.ref, &_recOrgJtit)) {
		recOrgJtit = *_recOrgJtit;
		delete _recOrgJtit;
	} else recOrgJtit = FmncJMOrgTitle();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recOrgJtit.ref);
	continf.TxtTit = recOrgJtit.Title;

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncOrgDetail::refresh(
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

void PnlFmncOrgDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFORG) {
		recOrg.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFORG, jref);
		refreshRecOrg(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncOrgDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTADRVIEWCLICK) {
					handleDpchAppDoButAdrViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncOrgDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncOrgDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTEL, ContIac::TXFEML})) {
		if (has(diffitems, ContIac::TXFTEL)) contiac.TxfTel = _contiac->TxfTel;
		if (has(diffitems, ContIac::TXFEML)) contiac.TxfEml = _contiac->TxfEml;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recOrgJtit.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecOrgJtit(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTDRV)) {
		contiac.numsFLstDrv = _contiac->numsFLstDrv;
		refreshTxtDrv(dbsfmnc, moditems);
		refresh(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncOrgDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncOrgDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncOrgDetail::handleDpchAppDoButAdrViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButAdrViewClick --- INSERT
};

void PnlFmncOrgDetail::handleDpchAppDoButSupViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSupViewClick --- INSERT
};

void PnlFmncOrgDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCORGUPD_REFEQ) {
		call->abort = handleCallFmncOrgUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCORGJTITMOD_ORGEQ) {
		call->abort = handleCallFmncOrgJtitMod_orgEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncOrgDetail::handleCallFmncOrgUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncOrgUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncOrgDetail::handleCallFmncOrgJtitMod_orgEq(
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


