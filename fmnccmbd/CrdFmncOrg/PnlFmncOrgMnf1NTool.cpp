/**
  * \file PnlFmncOrgMnf1NTool.cpp
  * job handler for job PnlFmncOrgMnf1NTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "PnlFmncOrgMnf1NTool.h"

// IP blksInclude --- BEGIN
#include "PnlFmncOrgMnf1NTool_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlFmncOrgMnf1NTool_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlFmncOrgMnf1NTool
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlFmncOrgMnf1NTool::PnlFmncOrgMnf1NTool(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::PNLFMNCORGMNF1NTOOL, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecFmncVQrystate::MNR, "ong", VecFmncVQrystate::getTitle(VecFmncVQrystate::MNR, ixFmncVLocale));
	feedFCsiQst.appendIxSrefTitles(VecFmncVQrystate::OOD, "red", VecFmncVQrystate::getTitle(VecFmncVQrystate::OOD, ixFmncVLocale));
	feedFCsiQst.appendIxSrefTitles(VecFmncVQrystate::SLM, "yel", VecFmncVQrystate::getTitle(VecFmncVQrystate::SLM, ixFmncVLocale));
	feedFCsiQst.appendIxSrefTitles(VecFmncVQrystate::UTD, "grn", VecFmncVQrystate::getTitle(VecFmncVQrystate::UTD, ixFmncVLocale));

	qry = NULL;

// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref, 0);

	qry = new QryFmncOrgMnf1NTool(xchg, dbsfmnc, jref, ixFmncVLocale);

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsfmnc, moditems);

	xchg->addClstn(VecFmncVCall::CALLFMNCSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

};

PnlFmncOrgMnf1NTool::~PnlFmncOrgMnf1NTool() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* PnlFmncOrgMnf1NTool::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlFmncOrgMnf1NTool::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixFmncVQrystate);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlFmncOrgMnf1NTool::updatePreset(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixFmncVPreset == VecFmncVPreset::PREFMNCREFORG) {
		xchg->addRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref, 0);

		qry->stgiac.jnumFirstload = 1;

		qry->refresh(dbsfmnc);
		refresh(dbsfmnc, moditems);

		if (notif) {
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			xchg->submitDpch(getNewDpchEng(moditems));
		};
	};
// IP updatePreset --- END
};

void PnlFmncOrgMnf1NTool::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGMNF1NTOOLDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsfmnc, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsfmnc, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCORGMNF1NTOOLDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlFmncOrgMnf1NTool::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlFmncOrgMnf1NTool::handleDpchAppDataStgiac(
			DbsFmnc* dbsfmnc
			, StgIac* _stgiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiac->diff(&stgiac);
// IP handleDpchAppDataStgiac --- INSERT
	insert(moditems, DpchEngData::STGIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncOrgMnf1NTool::handleDpchAppDataStgiacqry(
			DbsFmnc* dbsfmnc
			, QryFmncOrgMnf1NTool::StgIac* _stgiacqry
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	ubigint refSelNew = 0;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryFmncOrgMnf1NTool::StgIac::JNUM)) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryFmncOrgMnf1NTool::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->refresh(dbsfmnc);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryFmncOrgMnf1NTool::StgIac::JNUM)) {
			if (refSelNew == 0) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

			xchg->addRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref, refSelNew);
			qry->refreshJnum();
		};

		refresh(dbsfmnc, moditems);
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncOrgMnf1NTool::handleDpchAppDoButViewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint refSel;

	ubigint jrefNew = 0;

	refSel = xchg->getRefPreset(VecFmncVPreset::PREFMNCREFSEL, jref);
	if (refSel != 0)  xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncTol", refSel, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncTol");
};

void PnlFmncOrgMnf1NTool::handleDpchAppDoButNewClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsfmnc, VecFmncVCall::CALLFMNCCRDOPEN, jref, 0, 0, "CrdFmncTol", -1, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngFmncConfirm(false, 0, "");
	else *dpcheng = new DpchEngFmncConfirm(true, jrefNew, "CrdFmncTol");
};

void PnlFmncOrgMnf1NTool::handleDpchAppDoButDeleteClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlFmncOrgMnf1NTool::handleDpchAppDoButRefreshClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->refresh(dbsfmnc, false);
	refresh(dbsfmnc, moditems);

	muteRefresh = false;

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlFmncOrgMnf1NTool::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	if (call->ixVCall == VecFmncVCall::CALLFMNCSTATCHG) {
		call->abort = handleCallFmncStatChg(dbsfmnc, call->jref);
	};
};

bool PnlFmncOrgMnf1NTool::handleCallFmncStatChg(
			DbsFmnc* dbsfmnc
			, const ubigint jrefTrig
		) {
	bool retval = false;
// IP handleCallFmncStatChg --- BEGIN

	set<uint> moditems;

	if (jrefTrig == qry->jref) {
		if (!muteRefresh) {
			refresh(dbsfmnc, moditems);
			if (qry->ixFmncVQrystate == VecFmncVQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
		};
	};

// IP handleCallFmncStatChg --- END
	return retval;
};


