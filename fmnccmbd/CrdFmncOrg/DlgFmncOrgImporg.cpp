/**
  * \file DlgFmncOrgImporg.cpp
  * job handler for job DlgFmncOrgImporg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifdef FMNCCMBD
	#include <Fmnccmbd.h>
#else
	#include <Fmncd.h>
#endif

#include "DlgFmncOrgImporg.h"

// IP blksInclude --- BEGIN
#include "DlgFmncOrgImporg_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "DlgFmncOrgImporg_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class DlgFmncOrgImporg
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
DlgFmncOrgImporg::DlgFmncOrgImporg(
			XchgFmnc* xchg
			, DbsFmnc* dbsfmnc
			, const ubigint jrefSup
			, const uint ixFmncVLocale
		) : JobFmnc(xchg, VecFmncVJob::DLGFMNCORGIMPORG, jrefSup, ixFmncVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixFmncVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	iex = new IexFmncOrg(xchg, dbsfmnc, jref, ixFmncVLocale);

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsfmnc, moditems);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

DlgFmncOrgImporg::~DlgFmncOrgImporg() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngFmnc* DlgFmncOrgImporg::getNewDpchEng(
			set<uint> items
		) {
	DpchEngFmnc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngFmncConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &feedFDse, &feedFSge, &statshr, &statshrifi, &statshrimp, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgFmncOrgImporg::refreshIfi(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShrIfi oldStatshrifi(statshrifi);

// IP refreshIfi --- BEGIN
	// statshrifi
	statshrifi.UldActive = evalIfiUldActive(dbsfmnc);

// IP refreshIfi --- END
	if (statshrifi.diff(&oldStatshrifi).size() != 0) insert(moditems, DpchEngData::STATSHRIFI);
};

void DlgFmncOrgImporg::refreshImp(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	ContInfImp oldContinfimp(continfimp);
	StatShrImp oldStatshrimp(statshrimp);

// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbsfmnc);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbsfmnc);
	statshrimp.ButStoActive = evalImpButStoActive(dbsfmnc);

// IP refreshImp --- REND
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
};

void DlgFmncOrgImporg::refreshLfi(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);

// IP refreshLfi --- BEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbsfmnc);

// IP refreshLfi --- END
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgFmncOrgImporg::refresh(
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

	refreshIfi(dbsfmnc, moditems);
	refreshImp(dbsfmnc, moditems);
	refreshLfi(dbsfmnc, moditems);
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void DlgFmncOrgImporg::changeStage(
			DbsFmnc* dbsfmnc
			, uint _ixVSge
			, DpchEngFmnc** dpcheng
		) {
// IP dpchchangeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsfmnc); break;
			case VecVSge::PRSIDLE: leaveSgePrsidle(dbsfmnc); break;
			case VecVSge::PARSE: leaveSgeParse(dbsfmnc); break;
			case VecVSge::ALRFMNCPER: leaveSgeAlrfmncper(dbsfmnc); break;
			case VecVSge::PRSDONE: leaveSgePrsdone(dbsfmnc); break;
			case VecVSge::IMPIDLE: leaveSgeImpidle(dbsfmnc); break;
			case VecVSge::IMPORT: leaveSgeImport(dbsfmnc); break;
			case VecVSge::DONE: leaveSgeDone(dbsfmnc); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh1 --- BEGIN
		if (!muteRefresh) refreshWithDpchEng(dbsfmnc, dpcheng);
// IP changeStage.refresh1 --- END

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsfmnc); break;
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbsfmnc); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbsfmnc); break;
			case VecVSge::ALRFMNCPER: _ixVSge = enterSgeAlrfmncper(dbsfmnc); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbsfmnc); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbsfmnc); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbsfmnc); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsfmnc); break;
		};

// IP changeStage.refresh2 --- INSERT
	};
};
// IP changeStage --- END

uint DlgFmncOrgImporg::enterSgeIdle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgFmncOrgImporg::leaveSgeIdle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeIdle --- INSERT
};

uint DlgFmncOrgImporg::enterSgePrsidle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSge = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgePrsidle --- INSERT
	return retval;
};

void DlgFmncOrgImporg::leaveSgePrsidle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgePrsidle --- INSERT
};

uint DlgFmncOrgImporg::enterSgeParse(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::PARSE;
	nextIxVSge = retval;
// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	char* buf;
	string s;

	bool ifitxt;
	bool ifixml;

	bool success;

	iex->reset();

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("- ") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	success = false;

	if (ifitxt) success = iex->readTxtFile(infilename);
	else if (ifixml) success = iex->readXMLFile(infilename);

	if (success) {
		retval = VecVSge::PRSDONE;
	} else {
		if (reqCmd) {
			cout << "\tparse error at line " << iex->lineno << endl;
			retval = VecVSge::IDLE;
		} else {
			retval = VecVSge::ALRFMNCPER;
		};
	};
// IP enterSgeParse --- IEND
	return retval;
};

void DlgFmncOrgImporg::leaveSgeParse(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeParse --- INSERT
};

uint DlgFmncOrgImporg::enterSgeAlrfmncper(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::ALRFMNCPER;
	nextIxVSge = VecVSge::IDLE;
// IP enterSgeAlrfmncper --- RBEGIN
	xchg->submitDpch(AlrFmnc::prepareAlrPer(jref, ixFmncVLocale, to_string(iex->lineno), feedFMcbAlert));
// IP enterSgeAlrfmncper --- REND
	return retval;
};

void DlgFmncOrgImporg::leaveSgeAlrfmncper(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeAlrfmncper --- INSERT
};

uint DlgFmncOrgImporg::enterSgePrsdone(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::PRSDONE;
	nextIxVSge = retval;
// IP enterSgePrsdone --- INSERT
	return retval;
};

void DlgFmncOrgImporg::leaveSgePrsdone(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgePrsdone --- INSERT
};

uint DlgFmncOrgImporg::enterSgeImpidle(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSge = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgeImpidle --- INSERT
	return retval;
};

void DlgFmncOrgImporg::leaveSgeImpidle(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeImpidle --- INSERT
};

uint DlgFmncOrgImporg::enterSgeImport(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::IMPORT;
	nextIxVSge = VecVSge::DONE;

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeImport --- IBEGIN
	iex->import(dbsfmnc);
// IP enterSgeImport --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgFmncOrgImporg::leaveSgeImport(
			DbsFmnc* dbsfmnc
		) {
	invalidateWakeups();
// IP leaveSgeImport --- INSERT
};

uint DlgFmncOrgImporg::enterSgeDone(
			DbsFmnc* dbsfmnc
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- INSERT
	return retval;
};

void DlgFmncOrgImporg::leaveSgeDone(
			DbsFmnc* dbsfmnc
		) {
// IP leaveSgeDone --- INSERT
};

string DlgFmncOrgImporg::getSquawk(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRFMNCPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) ) {
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing organizational structure";
			else if (ixVSge == VecVSge::ALRFMNCPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "organizational structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing organizational structure (" + to_string(iex->impcnt) + " records added)";
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing organizational structure";
			else if (ixVSge == VecVSge::ALRFMNCPER) retval = "Fehler beim Einlesen";
			else if (ixVSge == VecVSge::PRSDONE) retval = "organizational structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing organizational structure (" + to_string(iex->impcnt) + " records added)";
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing organizational structure";
			else if (ixVSge == VecVSge::ALRFMNCPER) retval = "\\u00e9chec de lecture";
			else if (ixVSge == VecVSge::PRSDONE) retval = "organizational structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing organizational structure (" + to_string(iex->impcnt) + " records added)";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
// IP getSquawk --- REND
	return retval;
};

void DlgFmncOrgImporg::handleRequest(
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

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGIMPORGDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsfmnc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPDLGFMNCORGIMPORGDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsfmnc, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbsfmnc, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbsfmnc, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixFmncVDpch == VecFmncVDpch::DPCHAPPFMNCALERT) {
			handleDpchAppFmncAlert(dbsfmnc, (DpchAppFmncAlert*) (req->dpchapp), &(req->dpcheng));

		};
// IP handleRequest.upload --- BEGIN

	} else if (req->ixVBasetype == ReqFmnc::VecVBasetype::UPLOAD) {
		handleUpload(dbsfmnc, req->filename);
// IP handleRequest.upload --- END
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

void DlgFmncOrgImporg::handleDpchAppFmncInit(
			DbsFmnc* dbsfmnc
			, DpchAppFmncInit* dpchappfmncinit
			, DpchEngFmnc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgFmncOrgImporg::handleDpchAppDataContiac(
			DbsFmnc* dbsfmnc
			, ContIac* _contiac
			, DpchEngFmnc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::IFI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbsfmnc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgFmncOrgImporg::handleDpchAppDoButDneClick(
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

void DlgFmncOrgImporg::handleDpchAppDoImpButRunClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		if (ixVSge == VecVSge::PRSDONE) {
			changeStage(dbsfmnc, VecVSge::IMPIDLE, dpcheng);
		};
	};
// IP handleDpchAppDoImpButRunClick --- END
};

void DlgFmncOrgImporg::handleDpchAppDoImpButStoClick(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgFmncOrgImporg::handleDpchAppFmncAlert(
			DbsFmnc* dbsfmnc
			, DpchAppFmncAlert* dpchappfmncalert
			, DpchEngFmnc** dpcheng
		) {
// IP handleDpchAppFmncAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRFMNCPER) {
		changeStage(dbsfmnc, nextIxVSge);
	};
// IP handleDpchAppFmncAlert --- IEND
};

void DlgFmncOrgImporg::handleUpload(
			DbsFmnc* dbsfmnc
			, const string& filename
		) {
// IP handleUpload --- BEGIN
	if (ixVSge == VecVSge::IDLE) {
// IP handleUpload.prsidle --- IBEGIN
		infilename = filename;
// IP handleUpload.prsidle --- IEND
		changeStage(dbsfmnc, VecVSge::PRSIDLE);
	};
// IP handleUpload --- END
};

string DlgFmncOrgImporg::handleDownload(
			DbsFmnc* dbsfmnc
		) {
	string retval;
// IP handleDownload --- INSERT
	return retval;
};

void DlgFmncOrgImporg::handleTimer(
			DbsFmnc* dbsfmnc
			, const string& sref
		) {
	if (ixVSge == VecVSge::PRSIDLE) {
		changeStage(dbsfmnc, nextIxVSge);
	} else if (ixVSge == VecVSge::IMPIDLE) {
		changeStage(dbsfmnc, nextIxVSge);
	} else if ((ixVSge == VecVSge::IMPORT) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.import.mon --- IBEGIN
		set<uint> moditems;
		refresh(dbsfmnc, moditems);
		xchg->submitDpch(getNewDpchEng(moditems));
// IP handleTimer.import.mon --- IEND
	};
};


