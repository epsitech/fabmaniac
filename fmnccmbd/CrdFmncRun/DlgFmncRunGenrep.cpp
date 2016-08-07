/**
  * \file DlgFmncRunGenrep.cpp
  * job handler for job DlgFmncRunGenrep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "DlgFmncRunGenrep.h"

// IP blksInclude --- BEGIN
#include "DlgFmncRunGenrep_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "DlgFmncRunGenrep_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class DlgFmncRunGenrep
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
DlgFmncRunGenrep::DlgFmncRunGenrep(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::DLGFMNCRUNGENREP, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixFmncVLocale, feedFDse);
	feedFOptLstSpa.tag = "FeedFOptLstSpa";
	feedFOptRbuFab.tag = "FeedFOptRbuFab";
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::OFF, ixFmncVLocale, feedFOptRbuFab);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TXT, ixFmncVLocale, feedFOptRbuFab);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TBL, ixFmncVLocale, feedFOptRbuFab);
	feedFOptRbuFil.tag = "FeedFOptRbuFil";
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::OFF, ixFmncVLocale, feedFOptRbuFil);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TXT, ixFmncVLocale, feedFOptRbuFil);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TBL, ixFmncVLocale, feedFOptRbuFil);
	feedFOptRbuHis.tag = "FeedFOptRbuHis";
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::OFF, ixFmncVLocale, feedFOptRbuHis);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TXT, ixFmncVLocale, feedFOptRbuHis);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TBL, ixFmncVLocale, feedFOptRbuHis);
	feedFOptRbuPrs.tag = "FeedFOptRbuPrs";
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::OFF, ixFmncVLocale, feedFOptRbuPrs);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TXT, ixFmncVLocale, feedFOptRbuPrs);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TBL, ixFmncVLocale, feedFOptRbuPrs);
	feedFOptRbuSmp.tag = "FeedFOptRbuSmp";
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::OFF, ixFmncVLocale, feedFOptRbuSmp);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TXT, ixFmncVLocale, feedFOptRbuSmp);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TBL, ixFmncVLocale, feedFOptRbuSmp);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);
	feedFStoLstImf.tag = "FeedFStoLstImf";
	feedFStoLstPar.tag = "FeedFStoLstPar";
	feedFStoRbuCpa.tag = "FeedFStoRbuCpa";
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TXT, ixFmncVLocale, feedFStoRbuCpa);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TBL, ixFmncVLocale, feedFStoRbuCpa);
	feedFStoRbuFil.tag = "FeedFStoRbuFil";
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TXT, ixFmncVLocale, feedFStoRbuFil);
	VecFmncVRepdisp::appendToFeed(VecFmncVRepdisp::TBL, ixFmncVLocale, feedFStoRbuFil);
	feedFStoRbuFsp.tag = "FeedFStoRbuFsp";
	VecFmncVRepfsp::fillFeed(ixFmncVLocale, feedFStoRbuFsp);
	feedFStoRbuSsp.tag = "FeedFStoRbuSsp";
	VecFmncVRepssp::fillFeed(ixFmncVLocale, feedFStoRbuSsp);

// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::OPT;

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

DlgFmncRunGenrep::~DlgFmncRunGenrep() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* DlgFmncRunGenrep::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacopt, &contiacsto, &continf, &continfgen, &feedFDse, &feedFOptLstSpa, &feedFOptRbuFab, &feedFOptRbuFil, &feedFOptRbuHis, &feedFOptRbuPrs, &feedFOptRbuSmp, &feedFSge, &feedFStoLstImf, &feedFStoLstPar, &feedFStoRbuCpa, &feedFStoRbuFil, &feedFStoRbuFsp, &feedFStoRbuSsp, &statshr, &statshrgen, items);
	};

	return dpcheng;
};

void DlgFmncRunGenrep::refreshOpt(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIacOpt oldContiacopt(contiacopt);

// IP refreshOpt --- BEGIN
	// contiacopt

// IP refreshOpt --- END
	if (contiacopt.diff(&oldContiacopt).size() != 0) insert(moditems, DpchEngData::CONTIACOPT);
};

void DlgFmncRunGenrep::refreshSto(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContIacSto oldContiacsto(contiacsto);

// IP refreshSto --- BEGIN
	// contiacsto

// IP refreshSto --- END
	if (contiacsto.diff(&oldContiacsto).size() != 0) insert(moditems, DpchEngData::CONTIACSTO);
};

void DlgFmncRunGenrep::refreshGen(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInfGen oldContinfgen(continfgen);
	StatShrGen oldStatshrgen(statshrgen);

// IP refreshGen --- BEGIN
	// continfgen

	// statshrgen
	statshrgen.ButRunActive = evalGenButRunActive(dbsfmnc);
	statshrgen.ButStoActive = evalGenButStoActive(dbsfmnc);

// IP refreshGen --- END
	if (continfgen.diff(&oldContinfgen).size() != 0) insert(moditems, DpchEngData::CONTINFGEN);
	if (statshrgen.diff(&oldStatshrgen).size() != 0) insert(moditems, DpchEngData::STATSHRGEN);
};

void DlgFmncRunGenrep::refreshFia(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {

// IP refreshFia --- BEGIN
// IP refreshFia --- END
};

void DlgFmncRunGenrep::refresh(
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

	refreshOpt(dbsfmnc, moditems);
	refreshSto(dbsfmnc, moditems);
	refreshGen(dbsfmnc, moditems);
	refreshFia(dbsfmnc, moditems);
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void DlgFmncRunGenrep::changeStage(
			DbsFmnc* dbsfmnc
			, uint _ixVSge
			, DpchEngFmnc** dpcheng
		) {
// IP dpchchangeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsfmnc); break;
			case VecVSge::PRPIDLE: leaveSgePrpidle(dbsfmnc); break;
			case VecVSge::PREPARE: leaveSgePrepare(dbsfmnc); break;
			case VecVSge::TYPESET: leaveSgeTypeset(dbsfmnc); break;
			case VecVSge::PACK: leaveSgePack(dbsfmnc); break;
			case VecVSge::DONE: leaveSgeDone(dbsfmnc); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh1 --- BEGIN
		if (!muteRefresh) refreshWithDpchEng(dbsfmnc, dpcheng);
// IP changeStage.refresh1 --- END

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsfmnc); break;
			case VecVSge::PRPIDLE: _ixVSge = enterSgePrpidle(dbsfmnc); break;
			case VecVSge::PREPARE: _ixVSge = enterSgePrepare(dbsfmnc); break;
			case VecVSge::TYPESET: _ixVSge = enterSgeTypeset(dbsfmnc); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbsfmnc); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsfmnc); break;
		};

// IP changeStage.refresh2 --- INSERT
	};
};
// IP changeStage --- END

uint DlgFmncRunGenrep::enterSgeIdle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgFmncRunGenrep::leaveSgeIdle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeIdle --- INSERT
};

uint DlgFmncRunGenrep::enterSgePrpidle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::PRPIDLE;
	nextIxVSge = VecVSge::PREPARE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgePrpidle --- INSERT
	return retval;
};

void DlgFmncRunGenrep::leaveSgePrpidle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgePrpidle --- INSERT
};

uint DlgFmncRunGenrep::enterSgePrepare(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::PREPARE;
	nextIxVSge = VecVSge::TYPESET;
// IP enterSgePrepare --- INSERT
	retval = nextIxVSge;
	return retval;
};

void DlgFmncRunGenrep::leaveSgePrepare(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgePrepare --- INSERT
};

uint DlgFmncRunGenrep::enterSgeTypeset(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::TYPESET;
	nextIxVSge = VecVSge::PACK;
// IP enterSgeTypeset --- INSERT
	retval = nextIxVSge;
	return retval;
};

void DlgFmncRunGenrep::leaveSgeTypeset(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeTypeset --- INSERT
};

uint DlgFmncRunGenrep::enterSgePack(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::PACK;
	nextIxVSge = VecVSge::DONE;
// IP enterSgePack --- INSERT
	retval = nextIxVSge;
	return retval;
};

void DlgFmncRunGenrep::leaveSgePack(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgePack --- INSERT
};

uint DlgFmncRunGenrep::enterSgeDone(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- INSERT
	return retval;
};

void DlgFmncRunGenrep::leaveSgeDone(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeDone --- INSERT
};

string DlgFmncRunGenrep::getSquawk(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::PREPARE) || (ixVSge == VecVSge::TYPESET) || (ixVSge == VecVSge::PACK) ) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			if (ixVSge == VecVSge::PREPARE) retval = "preparing report sources";
			else if (ixVSge == VecVSge::TYPESET) retval = "typesetting report";
			else if (ixVSge == VecVSge::PACK) retval = "packing report files";
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			if (ixVSge == VecVSge::PREPARE) retval = "preparing report sources";
			else if (ixVSge == VecVSge::TYPESET) retval = "typesetting report";
			else if (ixVSge == VecVSge::PACK) retval = "packing report files";
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			if (ixVSge == VecVSge::PREPARE) retval = "preparing report sources";
			else if (ixVSge == VecVSge::TYPESET) retval = "typesetting report";
			else if (ixVSge == VecVSge::PACK) retval = "packing report files";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
// IP getSquawk --- END
	return retval;
};

void DlgFmncRunGenrep::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCRUNGENREPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACOPT)) {
				handleDpchAppDataContiacopt(dbsfmnc, &(dpchappdata->contiacopt), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACSTO)) {
				handleDpchAppDataContiacsto(dbsfmnc, &(dpchappdata->contiacsto), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCRUNGENREPDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsfmnc, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoGen != 0) {
				if (dpchappdo->ixVDoGen == VecVDoGen::BUTRUNCLICK) {
					handleDpchAppDoGenButRunClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDoGen == VecVDoGen::BUTSTOCLICK) {
					handleDpchAppDoGenButStoClick(dbsfmnc, &(req->dpcheng));
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

void DlgFmncRunGenrep::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgFmncRunGenrep::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::OPT) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgFmncRunGenrep::handleDpchAppDataContiacopt(
			DbsFmnc* dbsfmnc
			, ContIacOpt* _contiacopt
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacopt->diff(&contiacopt);
// IP handleDpchAppDataContiacopt --- INSERT
	insert(moditems, DpchEngData::CONTIACOPT);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgFmncRunGenrep::handleDpchAppDataContiacsto(
			DbsFmnc* dbsfmnc
			, ContIacSto* _contiacsto
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacsto->diff(&contiacsto);
// IP handleDpchAppDataContiacsto --- INSERT
	insert(moditems, DpchEngData::CONTIACSTO);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgFmncRunGenrep::handleDpchAppDoButDneClick(
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

void DlgFmncRunGenrep::handleDpchAppDoGenButRunClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoGenButRunClick --- BEGIN
	if (statshrgen.ButRunActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbsfmnc, VecVSge::PRPIDLE, dpcheng);
		};
	};
// IP handleDpchAppDoGenButRunClick --- END
};

void DlgFmncRunGenrep::handleDpchAppDoGenButStoClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoGenButStoClick --- INSERT
};

string DlgFmncRunGenrep::handleDownload(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP handleDownload --- INSERT
	return retval;
};

void DlgFmncRunGenrep::handleTimer(
			DbsFmnc* dbsfmnc
			, const string& sref
		) {
	if (ixVSge == VecVSge::PRPIDLE) {
		changeStage(dbsfmnc, nextIxVSge);
	};
};


