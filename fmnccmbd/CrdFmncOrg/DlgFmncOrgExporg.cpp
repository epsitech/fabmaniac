/**
  * \file DlgFmncOrgExporg.cpp
  * job handler for job DlgFmncOrgExporg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "DlgFmncOrgExporg.h"

// IP blksInclude --- BEGIN
#include "DlgFmncOrgExporg_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "DlgFmncOrgExporg_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class DlgFmncOrgExporg
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
DlgFmncOrgExporg::DlgFmncOrgExporg(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::DLGFMNCORGEXPORG, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixFmncVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::PRP;

	iex = new IexFmncOrg(xchg, dbsfmnc, jref, ixFmncVLocale);

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

DlgFmncOrgExporg::~DlgFmncOrgExporg() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* DlgFmncOrgExporg::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfprp, &feedFDse, &feedFSge, &statshr, &statshrfia, &statshrprp, items);
	};

	return dpcheng;
};

void DlgFmncOrgExporg::refreshPrp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInfPrp oldContinfprp(continfprp);
	StatShrPrp oldStatshrprp(statshrprp);

// IP refreshPrp --- BEGIN
	// continfprp

	// statshrprp
	statshrprp.ButRunActive = evalPrpButRunActive(dbsfmnc);
	statshrprp.ButStoActive = evalPrpButStoActive(dbsfmnc);

// IP refreshPrp --- END
	if (continfprp.diff(&oldContinfprp).size() != 0) insert(moditems, DpchEngData::CONTINFPRP);
	if (statshrprp.diff(&oldStatshrprp).size() != 0) insert(moditems, DpchEngData::STATSHRPRP);
};

void DlgFmncOrgExporg::refreshFia(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShrFia oldStatshrfia(statshrfia);

// IP refreshFia --- BEGIN
	// statshrfia
	statshrfia.DldActive = evalFiaDldActive(dbsfmnc);

// IP refreshFia --- END
	if (statshrfia.diff(&oldStatshrfia).size() != 0) insert(moditems, DpchEngData::STATSHRFIA);
};

void DlgFmncOrgExporg::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbsfmnc);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPrp(dbsfmnc, moditems);
	refreshFia(dbsfmnc, moditems);
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void DlgFmncOrgExporg::changeStage(
			DbsFmnc* dbsfmnc
			, uint _ixVSge
			, DpchEngFmnc** dpcheng
		) {
// IP dpchchangeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsfmnc); break;
			case VecVSge::COLIDLE: leaveSgeColidle(dbsfmnc); break;
			case VecVSge::COLLECT: leaveSgeCollect(dbsfmnc); break;
			case VecVSge::EXPORT: leaveSgeExport(dbsfmnc); break;
			case VecVSge::PACK: leaveSgePack(dbsfmnc); break;
			case VecVSge::DONE: leaveSgeDone(dbsfmnc); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh1 --- BEGIN
		if (!muteRefresh) refreshWithDpchEng(dbsfmnc, dpcheng);
// IP changeStage.refresh1 --- END

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsfmnc); break;
			case VecVSge::COLIDLE: _ixVSge = enterSgeColidle(dbsfmnc); break;
			case VecVSge::COLLECT: _ixVSge = enterSgeCollect(dbsfmnc); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbsfmnc); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbsfmnc); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsfmnc); break;
		};

// IP changeStage.refresh2 --- INSERT
	};
};
// IP changeStage --- END

uint DlgFmncOrgExporg::enterSgeIdle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgFmncOrgExporg::leaveSgeIdle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeIdle --- INSERT
};

uint DlgFmncOrgExporg::enterSgeColidle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::COLIDLE;
	nextIxVSge = VecVSge::COLLECT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgeColidle --- INSERT
	return retval;
};

void DlgFmncOrgExporg::leaveSgeColidle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeColidle --- INSERT
};

uint DlgFmncOrgExporg::enterSgeCollect(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::COLLECT;
	nextIxVSge = VecVSge::EXPORT;
// IP enterSgeCollect --- INSERT
	retval = nextIxVSge;
	return retval;
};

void DlgFmncOrgExporg::leaveSgeCollect(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeCollect --- INSERT
};

uint DlgFmncOrgExporg::enterSgeExport(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::EXPORT;
	nextIxVSge = VecVSge::PACK;
// IP enterSgeExport --- INSERT
	retval = nextIxVSge;
	return retval;
};

void DlgFmncOrgExporg::leaveSgeExport(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeExport --- INSERT
};

uint DlgFmncOrgExporg::enterSgePack(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::PACK;
	nextIxVSge = VecVSge::DONE;
// IP enterSgePack --- INSERT
	retval = nextIxVSge;
	return retval;
};

void DlgFmncOrgExporg::leaveSgePack(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgePack --- INSERT
};

uint DlgFmncOrgExporg::enterSgeDone(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- INSERT
	return retval;
};

void DlgFmncOrgExporg::leaveSgeDone(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeDone --- INSERT
};

string DlgFmncOrgExporg::getSquawk(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::EXPORT) || (ixVSge == VecVSge::PACK) ) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			if (ixVSge == VecVSge::COLLECT) retval = "collecting organizational structure";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting organizational structure";
			else if (ixVSge == VecVSge::PACK) retval = "packing organizational structure";
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			if (ixVSge == VecVSge::COLLECT) retval = "collecting organizational structure";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting organizational structure";
			else if (ixVSge == VecVSge::PACK) retval = "packing organizational structure";
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			if (ixVSge == VecVSge::COLLECT) retval = "collecting organizational structure";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting organizational structure";
			else if (ixVSge == VecVSge::PACK) retval = "packing organizational structure";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
// IP getSquawk --- END
	return retval;
};

void DlgFmncOrgExporg::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGEXPORGDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGEXPORGDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsfmnc, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoPrp != 0) {
				if (dpchappdo->ixVDoPrp == VecVDoPrp::BUTRUNCLICK) {
					handleDpchAppDoPrpButRunClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDoPrp == VecVDoPrp::BUTSTOCLICK) {
					handleDpchAppDoPrpButStoClick(dbsfmnc, &(req->dpcheng));
				};

			};

		};
// IP handleRequest.download --- BEGIN

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbsfmnc);
// IP handleRequest.download --- END
// IP handleRequest.timer --- BEGIN

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::TIMER) {
		handleTimer(dbsfmnc, req->sref);
// IP handleRequest.timer --- END
	};
};

void DlgFmncOrgExporg::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgFmncOrgExporg::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::PRP) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgFmncOrgExporg::handleDpchAppDoButDneClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngFmncConfirm(true, jref, "");
		xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCDLGCLOSE, jref);
	};
// IP handleDpchAppDoButDneClick --- IEND
};

void DlgFmncOrgExporg::handleDpchAppDoPrpButRunClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoPrpButRunClick --- BEGIN
	if (statshrprp.ButRunActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbsfmnc, VecVSge::COLIDLE, dpcheng);
		};
	};
// IP handleDpchAppDoPrpButRunClick --- END
};

void DlgFmncOrgExporg::handleDpchAppDoPrpButStoClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoPrpButStoClick --- INSERT
};

string DlgFmncOrgExporg::handleDownload(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP handleDownload --- INSERT
	return retval;
};

void DlgFmncOrgExporg::handleTimer(
			DbsFmnc* dbsfmnc
			, const string& sref
		) {
	if (ixVSge == VecVSge::COLIDLE) {
		changeStage(dbsfmnc, nextIxVSge);
	};
};


