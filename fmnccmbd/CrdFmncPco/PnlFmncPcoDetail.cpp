/**
  * \file PnlFmncPcoDetail.cpp
  * job handler for job PnlFmncPcoDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncPcoDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncPcoDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncPcoDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncPcoDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncPcoDetail::PnlFmncPcoDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCPCODETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
	VecFmncVMPurchorderState::fillFeed(ixFmncVLocale, feedFPupSte);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFPCO, jref);
};

PnlFmncPcoDetail::~PnlFmncPcoDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncPcoDetail::getNewDpchEng(
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

void PnlFmncPcoDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMPurchorderState pcoJstes;
	FmncJMPurchorderState* pcoJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmpurchorderstate->loadRstByPco(recPco.ref, false, pcoJstes);

	for (unsigned int i=0;i<pcoJstes.nodes.size();i++) {
		pcoJste = pcoJstes.nodes[i];

		s = "";
		if (pcoJste->x1Start != 0) {
			s = Ftm::stamp(pcoJste->x1Start) + " -";
			if ((i+2) < pcoJstes.nodes.size()) if (pcoJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::stamp(pcoJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(pcoJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecPcoJste(dbsfmnc, moditems);

};

void PnlFmncPcoDetail::refreshRecPco(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMPurchorder* _recPco = NULL;

	if (dbsfmnc->tblfmncmpurchorder->loadRecByRef(recPco.ref, &_recPco)) {
		recPco = *_recPco;
		delete _recPco;
	} else recPco = FmncMPurchorder();

	dirty = false;

	recPcoJste.ref = recPco.refJState;
	xchg->removeClstns(VecFmncVCall::CALLFMNCPCOJSTEMOD_PCOEQ, jref);
	if (recPco.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCPCOJSTEMOD_PCOEQ, jref, Clstn::VecVJobmask::ALL, 0, recPco.ref, Clstn::VecVJactype::LOCK);

	continf.TxtSrf = recPco.sref;
	contiac.TxfDat = Ftm::date(recPco.Date);
	continf.TxtPco = StubFmnc::getStubOrgStd(dbsfmnc, recPco.pcoRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSpl = StubFmnc::getStubOrgStd(dbsfmnc, recPco.splRefFmncMOrg, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtFil = StubFmnc::getStubFilStd(dbsfmnc, recPco.refFmncMFile, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfAmt = to_string(recPco.Amount);
	continf.TxtPcp = StubFmnc::getStubPrsStd(dbsfmnc, recPco.pcpRefFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recPco.Comment;

	statshr.ButPcoViewAvail = evalButPcoViewAvail(dbsfmnc);
	statshr.ButSplViewAvail = evalButSplViewAvail(dbsfmnc);
	statshr.ButFilViewAvail = evalButFilViewAvail(dbsfmnc);
	statshr.ButPcpViewAvail = evalButPcpViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);

};

void PnlFmncPcoDetail::refreshRecPcoJste(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncJMPurchorderState* _recPcoJste = NULL;

	if (dbsfmnc->tblfmncjmpurchorderstate->loadRecByRef(recPcoJste.ref, &_recPcoJste)) {
		recPcoJste = *_recPcoJste;
		delete _recPcoJste;
	} else recPcoJste = FmncJMPurchorderState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recPcoJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recPcoJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncPcoDetail::refresh(
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

void PnlFmncPcoDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFPCO) {
		recPco.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFPCO, jref);
		refreshRecPco(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncPcoDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCODETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCPCODETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPCOVIEWCLICK) {
					handleDpchAppDoButPcoViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSPLVIEWCLICK) {
					handleDpchAppDoButSplViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPCPVIEWCLICK) {
					handleDpchAppDoButPcpViewClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncPcoDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncPcoDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFDAT, ContIac::NUMFPUPSTE, ContIac::TXFAMT, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFDAT)) contiac.TxfDat = _contiac->TxfDat;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::TXFAMT)) contiac.TxfAmt = _contiac->TxfAmt;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recPcoJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecPcoJste(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncPcoDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncPcoDetail::handleDpchAppDoButPcoViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButPcoViewClick --- INSERT
};

void PnlFmncPcoDetail::handleDpchAppDoButSplViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSplViewClick --- INSERT
};

void PnlFmncPcoDetail::handleDpchAppDoButFilViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButFilViewClick --- INSERT
};

void PnlFmncPcoDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncPcoDetail::handleDpchAppDoButPcpViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButPcpViewClick --- INSERT
};

void PnlFmncPcoDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCPCOUPD_REFEQ) {
		call->abort = handleCallFmncPcoUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPCOJSTEMOD_PCOEQ) {
		call->abort = handleCallFmncPcoJsteMod_pcoEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncPcoDetail::handleCallFmncPcoUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncPcoUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncPcoDetail::handleCallFmncPcoJsteMod_pcoEq(
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


