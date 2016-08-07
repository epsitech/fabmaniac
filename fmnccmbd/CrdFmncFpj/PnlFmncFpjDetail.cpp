/**
  * \file PnlFmncFpjDetail.cpp
  * job handler for job PnlFmncFpjDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncFpjDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncFpjDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncFpjDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncFpjDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncFpjDetail::PnlFmncFpjDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCFPJDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
	VecFmncVMFabprojectState::fillFeed(ixFmncVLocale, feedFPupSte);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFFPJ, jref);
};

PnlFmncFpjDetail::~PnlFmncFpjDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncFpjDetail::getNewDpchEng(
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

void PnlFmncFpjDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMFabprojectState fpjJstes;
	FmncJMFabprojectState* fpjJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmfabprojectstate->loadRstByFpj(recFpj.ref, false, fpjJstes);

	for (unsigned int i=0;i<fpjJstes.nodes.size();i++) {
		fpjJste = fpjJstes.nodes[i];

		s = "";
		if (fpjJste->x1Startd != 0) {
			s = Ftm::date(fpjJste->x1Startd) + " -";
			if ((i+2) < fpjJstes.nodes.size()) if (fpjJstes.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(fpjJstes.nodes[i+1]->x1Startd);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(fpjJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecFpjJste(dbsfmnc, moditems);

};

void PnlFmncFpjDetail::refreshRecFpj(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMFabproject* _recFpj = NULL;

	if (dbsfmnc->tblfmncmfabproject->loadRecByRef(recFpj.ref, &_recFpj)) {
		recFpj = *_recFpj;
		delete _recFpj;
	} else recFpj = FmncMFabproject();

	dirty = false;

	recFpjJste.ref = recFpj.refJState;
	xchg->removeClstns(VecFmncVCall::CALLFMNCFPJJSTEMOD_FPJEQ, jref);
	if (recFpj.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCFPJJSTEMOD_FPJEQ, jref, Clstn::VecVJobmask::ALL, 0, recFpj.ref, Clstn::VecVJactype::LOCK);

	continf.TxtSrf = recFpj.sref;
	contiac.TxfTit = recFpj.Title;
	continf.TxtFab = StubFmnc::getStubFabStd(dbsfmnc, recFpj.refFmncMFab, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtBio = StubFmnc::getStubOrgStd(dbsfmnc, recFpj.bioRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtBip = StubFmnc::getStubPrsStd(dbsfmnc, recFpj.bipRefFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recFpj.Comment;

	statshr.ButFabViewAvail = evalButFabViewAvail(dbsfmnc);
	statshr.ButBioViewAvail = evalButBioViewAvail(dbsfmnc);
	statshr.ButBipViewAvail = evalButBipViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);

};

void PnlFmncFpjDetail::refreshRecFpjJste(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncJMFabprojectState* _recFpjJste = NULL;

	if (dbsfmnc->tblfmncjmfabprojectstate->loadRecByRef(recFpjJste.ref, &_recFpjJste)) {
		recFpjJste = *_recFpjJste;
		delete _recFpjJste;
	} else recFpjJste = FmncJMFabprojectState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recFpjJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recFpjJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncFpjDetail::refresh(
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

void PnlFmncFpjDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFPJ) {
		recFpj.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFPJ, jref);
		refreshRecFpj(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncFpjDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFPJDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFABVIEWCLICK) {
					handleDpchAppDoButFabViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBIOVIEWCLICK) {
					handleDpchAppDoButBioViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBIPVIEWCLICK) {
					handleDpchAppDoButBipViewClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncFpjDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncFpjDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::NUMFPUPSTE, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recFpjJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecFpjJste(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncFpjDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncFpjDetail::handleDpchAppDoButFabViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButFabViewClick --- INSERT
};

void PnlFmncFpjDetail::handleDpchAppDoButBioViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButBioViewClick --- INSERT
};

void PnlFmncFpjDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncFpjDetail::handleDpchAppDoButBipViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButBipViewClick --- INSERT
};

void PnlFmncFpjDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCFPJUPD_REFEQ) {
		call->abort = handleCallFmncFpjUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFPJJSTEMOD_FPJEQ) {
		call->abort = handleCallFmncFpjJsteMod_fpjEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncFpjDetail::handleCallFmncFpjUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncFpjUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncFpjDetail::handleCallFmncFpjJsteMod_fpjEq(
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


