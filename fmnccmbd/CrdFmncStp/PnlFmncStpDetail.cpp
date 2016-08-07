/**
  * \file PnlFmncStpDetail.cpp
  * job handler for job PnlFmncStpDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncStpDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncStpDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncStpDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncStpDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncStpDetail::PnlFmncStpDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCSTPDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFLstFcf.tag = "FeedFLstFcf";
	VecFmncWMStepFilecfg::fillFeed(ixFmncVLocale, feedFLstFcf);
	feedFPupRlt.tag = "FeedFPupRlt";
	VecFmncVMStepRlvTbl::fillFeed(ixFmncVLocale, feedFPupRlt);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFSTP, jref);
};

PnlFmncStpDetail::~PnlFmncStpDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncStpDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstFcf, &feedFPupRlt, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncStpDetail::refreshTxtFcf(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i=0;i<contiac.numsFLstFcf.size();i++) ix |= feedFLstFcf.getIxByNum(contiac.numsFLstFcf[i]);
	continf.TxtFcf = VecFmncWMStepFilecfg::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlFmncStpDetail::refreshRecSte(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	FmncMStep* _recSte = NULL;

	if (dbsfmnc->tblfmncmstep->loadRecByRef(recSte.ref, &_recSte)) {
		recSte = *_recSte;
		delete _recSte;
	} else recSte = FmncMStep();

	dirty = false;

	contiac.TxfTit = recSte.Title;
	continf.TxtAct = StubFmnc::getStubActStd(dbsfmnc, recSte.refFmncMActivity, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupRlt = feedFPupRlt.getNumByIx(recSte.rlvIxVTbl);
	continf.TxtStp = StubFmnc::getStubSteStd(dbsfmnc, recSte.tplRefFmncMStep, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.numsFLstFcf.clear();
	VecFmncWMStepFilecfg::getIcs(recSte.ixWFilecfg, ics);
	for (auto it=ics.begin();it!=ics.end();it++) contiac.numsFLstFcf.push_back(feedFLstFcf.getNumByIx(*it));
	contiac.TxfSta = Ftm::stamp(recSte.start);
	continf.TxtPrs = StubFmnc::getStubPrsStd(dbsfmnc, recSte.refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::FULL);

	statshr.ButActViewAvail = evalButActViewAvail(dbsfmnc);
	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtFcf(dbsfmnc, moditems);

};

void PnlFmncStpDetail::refresh(
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

void PnlFmncStpDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFSTP) {
		recSte.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSTP, jref);
		refreshRecSte(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncStpDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCSTPDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTACTVIEWCLICK) {
					handleDpchAppDoButActViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRLUVIEWCLICK) {
					handleDpchAppDoButRluViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncStpDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncStpDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFSTA})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
	};

	if (has(diffitems, ContIac::NUMSFLSTFCF)) {
		contiac.numsFLstFcf = _contiac->numsFLstFcf;
		refreshTxtFcf(dbsfmnc, moditems);
		refresh(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncStpDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncStpDetail::handleDpchAppDoButActViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButActViewClick --- INSERT
};

void PnlFmncStpDetail::handleDpchAppDoButRluViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButRluViewClick --- INSERT
};

void PnlFmncStpDetail::handleDpchAppDoButPrsViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButPrsViewClick --- INSERT
};

void PnlFmncStpDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTEUPD_REFEQ) {
		call->abort = handleCallFmncSteUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncStpDetail::handleCallFmncSteUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncSteUpd_refEq --- INSERT
	return retval;
};


