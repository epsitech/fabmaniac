/**
  * \file PnlFmncUsrDetail.cpp
  * job handler for job PnlFmncUsrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncUsrDetail.h"

// IP blksInclude --- BEGIN
#include "PnlFmncUsrDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncUsrDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncUsrDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncUsrDetail::PnlFmncUsrDetail(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCUSRDETAIL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupLcl.tag = "FeedFPupLcl";
	VecFmncVLocale::fillFeed(ixFmncVLocale, feedFPupLcl);
	feedFPupSte.tag = "FeedFPupSte";
	VecFmncVMUserState::fillFeed(ixFmncVLocale, feedFPupSte);
	feedFPupUlv.tag = "FeedFPupUlv";
	VecFmncVUserlevel::fillFeed(ixFmncVLocale, feedFPupUlv);

// IP constructor.cust1 --- INSERT

	dirty = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsfmnc, VecFmncVPreset::PREFMNCREFUSR, jref);
};

PnlFmncUsrDetail::~PnlFmncUsrDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncUsrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &feedFPupLcl, &feedFPupSte, &feedFPupUlv, &statshr, items);
	};

	return dpcheng;
};

void PnlFmncUsrDetail::refreshJ(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ListFmncJMUserState usrJstes;
	FmncJMUserState* usrJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsfmnc->tblfmncjmuserstate->loadRstByUsr(recUsr.ref, false, usrJstes);

	for (unsigned int i=0;i<usrJstes.nodes.size();i++) {
		usrJste = usrJstes.nodes[i];

		s = "";
		if (usrJste->x1Startd != 0) {
			s = Ftm::date(usrJste->x1Startd) + " -";
			if ((i+2) < usrJstes.nodes.size()) if (usrJstes.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(usrJstes.nodes[i+1]->x1Startd);
		} else s = "(" + VecFmncVTag::getTitle(VecFmncVTag::ALWAYS, ixFmncVLocale) + ")";
		feedFPupJ.appendRefTitles(usrJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecUsrJste(dbsfmnc, moditems);

};

void PnlFmncUsrDetail::refreshRecUsr(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncMUser* _recUsr = NULL;

	if (dbsfmnc->tblfmncmuser->loadRecByRef(recUsr.ref, &_recUsr)) {
		recUsr = *_recUsr;
		delete _recUsr;
	} else recUsr = FmncMUser();

	dirty = false;

	recUsrJste.ref = recUsr.refJState;
	xchg->removeClstns(VecFmncVCall::CALLFMNCUSRJSTEMOD_USREQ, jref);
	if (recUsr.ref != 0) xchg->addRefClstn(VecFmncVCall::CALLFMNCUSRJSTEMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, recUsr.ref, Clstn::VecVJactype::LOCK);

	continf.TxtPrs = StubFmnc::getStubPrsStd(dbsfmnc, recUsr.refFmncMPerson, ixFmncVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSrf = recUsr.sref;
	continf.TxtUsg = StubFmnc::getStubUsgStd(dbsfmnc, recUsr.refFmncMUsergroup, ixFmncVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupLcl = feedFPupLcl.getNumByIx(recUsr.ixFmncVLocale);
	contiac.numFPupUlv = feedFPupUlv.getNumByIx(recUsr.ixFmncVUserlevel);
	contiac.TxfPwd = recUsr.Password;

	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbsfmnc);
	statshr.ButUsgViewAvail = evalButUsgViewAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsfmnc, moditems);

};

void PnlFmncUsrDetail::refreshRecUsrJste(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	FmncJMUserState* _recUsrJste = NULL;

	if (dbsfmnc->tblfmncjmuserstate->loadRecByRef(recUsrJste.ref, &_recUsrJste)) {
		recUsrJste = *_recUsrJste;
		delete _recUsrJste;
	} else recUsrJste = FmncJMUserState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recUsrJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recUsrJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsfmnc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlFmncUsrDetail::refresh(
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

void PnlFmncUsrDetail::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFUSR) {
		recUsr.ref = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFUSR, jref);
		refreshRecUsr(dbsfmnc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlFmncUsrDetail::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCUSRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncUsrDetail::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncUsrDetail::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSTE, ContIac::NUMFPUPLCL, ContIac::NUMFPUPULV, ContIac::TXFPWD})) {
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::NUMFPUPLCL)) contiac.numFPupLcl = _contiac->numFPupLcl;
		if (has(diffitems, ContIac::NUMFPUPULV)) contiac.numFPupUlv = _contiac->numFPupUlv;
		if (has(diffitems, ContIac::TXFPWD)) contiac.TxfPwd = _contiac->TxfPwd;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recUsrJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecUsrJste(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncUsrDetail::handleDpchAppDoButSaveClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlFmncUsrDetail::handleDpchAppDoButPrsViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButPrsViewClick --- INSERT
};

void PnlFmncUsrDetail::handleDpchAppDoButUsgViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButUsgViewClick --- INSERT
};

void PnlFmncUsrDetail::handleDpchAppDoButJEditClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlFmncUsrDetail::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCUSRUPD_REFEQ) {
		call->abort = handleCallFmncUsrUpd_refEq(dbsfmnc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCUSRJSTEMOD_USREQ) {
		call->abort = handleCallFmncUsrJsteMod_usrEq(dbsfmnc, call->jref, call->argInv.ref);
	};
};

bool PnlFmncUsrDetail::handleCallFmncUsrUpd_refEq(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallFmncUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlFmncUsrDetail::handleCallFmncUsrJsteMod_usrEq(
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


