/**
  * \file PnlFmncPrsDetail.cpp
  * job handler for job PnlFmncPrsDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncPrsDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncPrsDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncPrsDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncPrsDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncPrsDetail::PnlFmncPrsDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCPRSDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstDrv.tag = "FeedFLstDrv";
	VecFmncWMPersonDerivate::fillFeed(ixFmncVLocale, feedFLstDrv);
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSex.tag = "FeedFPupSex";
	VecFmncVMPersonSex::fillFeed(ixFmncVLocale, feedFPupSex);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFPRS, jref);
};

PnlFmncPrsDetail::~PnlFmncPrsDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncPrsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDrv, &feedFPupJ, &feedFPupSex, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncPrsDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMPersonLastname prsJlnms;
	FmncJMPersonLastname* prsJlnm = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmpersonlastname->loadRstByPrs(recPrs.ref, false, prsJlnms);

	for (unsigned int i=0;i<prsJlnms.nodes.size();i++) {
		prsJlnm = prsJlnms.nodes[i];

		s = "";
		if (prsJlnm->x1Startd != 0) {
			s = Ftm::date(prsJlnm->x1Startd) + " -";
			if ((i+2) < prsJlnms.nodes.size()) if (prsJlnms.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(prsJlnms.nodes[i+1]->x1Startd);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(prsJlnm->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecPrsJlnm(dbsfmnc, moditems);

};

void PnlFmncPrsDetail::refreshTxtDrv(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i=0;i<contiac.numsFLstDrv.size();i++) ix |= feedFLstDrv.getIxByNum(contiac.numsFLstDrv[i]);
	continf.TxtDrv = VecFmncWMPersonDerivate::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlFmncPrsDetail::refreshRecPrs(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	FmncMPerson* _recPrs = NULL;

	if (dbsfmnc->tblfmncmperson->loadRecByRef(recPrs.ref, &_recPrs)) {
		recPrs = *_recPrs;
		delete _recPrs;
	} else recPrs = FmncMPerson();

	dirty = false;

	recPrsJlnm.ref = recPrs.refJLastname;
	xchg->removeClstns(VecFmncVCall::CALLFMNCPRSJLNMMOD_PRSEQ, jref);
	if (recPrs.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCPRSJLNMMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, recPrs.ref, Clstn::VecVJactype::LOCK);

	contiac.TxfTit = recPrs.Title;
	contiac.TxfFnm = recPrs.Firstname;
	contiac.numsFLstDrv.clear();
	VecFmncWMPersonDerivate::getIcs(recPrs.ixWDerivate, ics);
	for (auto it=ics.begin();it!=ics.end();it++) contiac.numsFLstDrv.push_back(feedFLstDrv.getNumByIx(*it));
	continf.TxtOrg = StubFmnc::getStubOrgStd(dbsfmnc, recPrs.refFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtAdr = StubFmnc::getStubAdrStd(dbsfmnc, recPrs.refFmncMAddress, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupSex = feedFPupSex.getNumByIx(recPrs.ixVSex);
	contiac.TxfTel = recPrs.Tel;
	contiac.TxfEml = recPrs.Eml;
	contiac.TxfSal = recPrs.Salutation;

	statshr.ButOrgViewAvail = evalButOrgViewAvail(dbsfmnc);
	statshr.ButAdrViewAvail = evalButAdrViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);
	refreshTxtDrv(dbsfmnc, moditems);

};

void PnlFmncPrsDetail::refreshRecPrsJlnm(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	FmncJMPersonLastname* _recPrsJlnm = NULL;

	if (dbsfmnc->tblfmncjmpersonlastname->loadRecByRef(recPrsJlnm.ref, &_recPrsJlnm)) {
		recPrsJlnm = *_recPrsJlnm;
		delete _recPrsJlnm;
	} else recPrsJlnm = FmncJMPersonLastname();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recPrsJlnm.ref);
	continf.TxtLnm = recPrsJlnm.Lastname;

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncPrsDetail::refresh(
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

void PnlFmncPrsDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFPRS) {
		recPrs.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPRS, jref);
		refreshRecPrs(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncPrsDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPRSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTORGVIEWCLICK) {
					handleDpchAppDoButOrgViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTADRVIEWCLICK) {
					handleDpchAppDoButAdrViewClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncPrsDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncPrsDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFFNM, ContIac::NUMFPUPSEX, ContIac::TXFTEL, ContIac::TXFEML, ContIac::TXFSAL})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::NUMFPUPSEX)) contiac.numFPupSex = _contiac->numFPupSex;
		if (has(diffitems, ContIac::TXFTEL)) contiac.TxfTel = _contiac->TxfTel;
		if (has(diffitems, ContIac::TXFEML)) contiac.TxfEml = _contiac->TxfEml;
		if (has(diffitems, ContIac::TXFSAL)) contiac.TxfSal = _contiac->TxfSal;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recPrsJlnm.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecPrsJlnm(dbsfmnc, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTDRV)) {
		contiac.numsFLstDrv = _contiac->numsFLstDrv;
		refreshTxtDrv(dbsfmnc, moditems);
		refresh(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncPrsDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncPrsDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncPrsDetail::handleDpchAppDoButOrgViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButOrgViewClick --- INSERT
};

void PnlFmncPrsDetail::handleDpchAppDoButAdrViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButAdrViewClick --- INSERT
};

void PnlFmncPrsDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCPRSUPD_REFEQ) {
		call->abort = handleCallFmncPrsUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPRSJLNMMOD_PRSEQ) {
		call->abort = handleCallFmncPrsJlnmMod_prsEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncPrsDetail::handleCallFmncPrsUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncPrsUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncPrsDetail::handleCallFmncPrsJlnmMod_prsEq(
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


