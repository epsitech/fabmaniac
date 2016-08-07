/**
  * \file PnlFmncFusDetail.cpp
  * job handler for job PnlFmncFusDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncFusDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncFusDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncFusDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncFusDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncFusDetail::PnlFmncFusDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCFUSDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
	VecFmncVMFabuserState::fillFeed(ixFmncVLocale, feedFPupSte);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFFUS, jref);
};

PnlFmncFusDetail::~PnlFmncFusDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncFusDetail::getNewDpchEng(
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

void PnlFmncFusDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMFabuserState fusJstes;
	FmncJMFabuserState* fusJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmfabuserstate->loadRstByFus(recFus.ref, false, fusJstes);

	for (unsigned int i=0;i<fusJstes.nodes.size();i++) {
		fusJste = fusJstes.nodes[i];

		s = "";
		if (fusJste->x1Startd != 0) {
			s = Ftm::date(fusJste->x1Startd) + " -";
			if ((i+2) < fusJstes.nodes.size()) if (fusJstes.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(fusJstes.nodes[i+1]->x1Startd);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(fusJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecFusJste(dbsfmnc, moditems);

};

void PnlFmncFusDetail::refreshRecFus(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMFabuser* _recFus = NULL;

	if (dbsfmnc->tblfmncmfabuser->loadRecByRef(recFus.ref, &_recFus)) {
		recFus = *_recFus;
		delete _recFus;
	} else recFus = FmncMFabuser();

	dirty = false;

	recFusJste.ref = recFus.refJState;
	xchg->removeClstns(VecFmncVCall::CALLFMNCFUSJSTEMOD_FUSEQ, jref);
	if (recFus.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCFUSJSTEMOD_FUSEQ, jref, Clstn::VecVJobmask::ALL, 0, recFus.ref, Clstn::VecVJactype::LOCK);

	continf.TxtPrs = StubFmnc::getStubPrsStd(dbsfmnc, recFus.refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSrf = recFus.sref;
	continf.TxtFab = StubFmnc::getStubFabStd(dbsfmnc, recFus.refFmncMFab, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtFpj = StubFmnc::getStubFusStd(dbsfmnc, recFus.refFmncMFabproject, ixFmncVLocale, Stub::VecVNonetype::FULL);

	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbsfmnc);
	statshr.ButFabViewAvail = evalButFabViewAvail(dbsfmnc);
	statshr.ButFpjViewAvail = evalButFpjViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);

};

void PnlFmncFusDetail::refreshRecFusJste(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncJMFabuserState* _recFusJste = NULL;

	if (dbsfmnc->tblfmncjmfabuserstate->loadRecByRef(recFusJste.ref, &_recFusJste)) {
		recFusJste = *_recFusJste;
		delete _recFusJste;
	} else recFusJste = FmncJMFabuserState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recFusJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recFusJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncFusDetail::refresh(
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

void PnlFmncFusDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFFUS) {
		recFus.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFFUS, jref);
		refreshRecFus(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncFusDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCFUSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFABVIEWCLICK) {
					handleDpchAppDoButFabViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFPJVIEWCLICK) {
					handleDpchAppDoButFpjViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncFusDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncFusDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSTE})) {
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recFusJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecFusJste(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncFusDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncFusDetail::handleDpchAppDoButPrsViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButPrsViewClick --- INSERT
};

void PnlFmncFusDetail::handleDpchAppDoButFabViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButFabViewClick --- INSERT
};

void PnlFmncFusDetail::handleDpchAppDoButFpjViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButFpjViewClick --- INSERT
};

void PnlFmncFusDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncFusDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCFUSUPD_REFEQ) {
		call->abort = handleCallFmncFusUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFUSJSTEMOD_FUSEQ) {
		call->abort = handleCallFmncFusJsteMod_fusEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncFusDetail::handleCallFmncFusUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncFusUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncFusDetail::handleCallFmncFusJsteMod_fusEq(
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


