/**
  * \file PnlFmncSmpDetail.cpp
  * job handler for job PnlFmncSmpDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncSmpDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncSmpDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncSmpDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncSmpDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncSmpDetail::PnlFmncSmpDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCSMPDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
	VecFmncVMSampleState::fillFeed(ixFmncVLocale, feedFPupSte);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFSMP, jref);
};

PnlFmncSmpDetail::~PnlFmncSmpDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncSmpDetail::getNewDpchEng(
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

void PnlFmncSmpDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMSampleState smpJstes;
	FmncJMSampleState* smpJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmsamplestate->loadRstBySmp(recSmp.ref, false, smpJstes);

	for (unsigned int i=0;i<smpJstes.nodes.size();i++) {
		smpJste = smpJstes.nodes[i];

		s = "";
		if (smpJste->x1Start != 0) {
			s = Ftm::stamp(smpJste->x1Start) + " -";
			if ((i+2) < smpJstes.nodes.size()) if (smpJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::stamp(smpJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(smpJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecSmpJste(dbsfmnc, moditems);

};

void PnlFmncSmpDetail::refreshRecSmp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMSample* _recSmp = NULL;

	if (dbsfmnc->tblfmncmsample->loadRecByRef(recSmp.ref, &_recSmp)) {
		recSmp = *_recSmp;
		delete _recSmp;
	} else recSmp = FmncMSample();

	dirty = false;

	recSmpJste.ref = recSmp.refJState;
	xchg->removeClstns(VecFmncVCall::CALLFMNCSMPJSTEMOD_SMPEQ, jref);
	if (recSmp.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCSMPJSTEMOD_SMPEQ, jref, Clstn::VecVJobmask::ALL, 0, recSmp.ref, Clstn::VecVJactype::LOCK);

	continf.TxtSrf = recSmp.sref;
	continf.TxtSup = StubFmnc::getStubSmpStd(dbsfmnc, recSmp.supRefFmncMSample, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtArt = StubFmnc::getStubArtStd(dbsfmnc, recSmp.refFmncMArticle, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfMat = recSmp.Material;
	contiac.TxfCmt = recSmp.Comment;

	statshr.ButSupViewAvail = evalButSupViewAvail(dbsfmnc);
	statshr.ButArtViewAvail = evalButArtViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);

};

void PnlFmncSmpDetail::refreshRecSmpJste(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncJMSampleState* _recSmpJste = NULL;

	if (dbsfmnc->tblfmncjmsamplestate->loadRecByRef(recSmpJste.ref, &_recSmpJste)) {
		recSmpJste = *_recSmpJste;
		delete _recSmpJste;
	} else recSmpJste = FmncJMSampleState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recSmpJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recSmpJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncSmpDetail::refresh(
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

void PnlFmncSmpDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSMP) {
		recSmp.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSMP, jref);
		refreshRecSmp(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncSmpDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSMPDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTARTVIEWCLICK) {
					handleDpchAppDoButArtViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncSmpDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncSmpDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFMAT, ContIac::NUMFPUPSTE, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFMAT)) contiac.TxfMat = _contiac->TxfMat;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recSmpJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecSmpJste(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncSmpDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncSmpDetail::handleDpchAppDoButSupViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSupViewClick --- INSERT
};

void PnlFmncSmpDetail::handleDpchAppDoButArtViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButArtViewClick --- INSERT
};

void PnlFmncSmpDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncSmpDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSMPUPD_REFEQ) {
		call->abort = handleCallFmncSmpUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSMPJSTEMOD_SMPEQ) {
		call->abort = handleCallFmncSmpJsteMod_smpEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncSmpDetail::handleCallFmncSmpUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncSmpUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncSmpDetail::handleCallFmncSmpJsteMod_smpEq(
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


