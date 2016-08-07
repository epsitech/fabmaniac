/**
  * \file CrdFmncNav.cpp
  * API code for job CrdFmncNav (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "CrdFmncNav.h"

/******************************************************************************
 class CrdFmncNav::VecVDo
 ******************************************************************************/

uint CrdFmncNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("close") == 0) return CLOSE;
	else if (s.compare("mitappabtclick") == 0) return MITAPPABTCLICK;
	else if (s.compare("mitsestrmclick") == 0) return MITSESTRMCLICK;
	else if (s.compare("mitcrdusgclick") == 0) return MITCRDUSGCLICK;
	else if (s.compare("mitcrdusrclick") == 0) return MITCRDUSRCLICK;
	else if (s.compare("mitcrdorgclick") == 0) return MITCRDORGCLICK;
	else if (s.compare("mitcrdprsclick") == 0) return MITCRDPRSCLICK;
	else if (s.compare("mitcrdadrclick") == 0) return MITCRDADRCLICK;
	else if (s.compare("mitcrdfilclick") == 0) return MITCRDFILCLICK;
	else if (s.compare("mitcrdstpclick") == 0) return MITCRDSTPCLICK;
	else if (s.compare("mitcrdprjclick") == 0) return MITCRDPRJCLICK;
	else if (s.compare("mitcrdrunclick") == 0) return MITCRDRUNCLICK;
	else if (s.compare("mitcrdactclick") == 0) return MITCRDACTCLICK;
	else if (s.compare("mitcrdsepclick") == 0) return MITCRDSEPCLICK;
	else if (s.compare("mitcrdsmpclick") == 0) return MITCRDSMPCLICK;
	else if (s.compare("mitcrdfabclick") == 0) return MITCRDFABCLICK;
	else if (s.compare("mitcrdfusclick") == 0) return MITCRDFUSCLICK;
	else if (s.compare("mitcrdttyclick") == 0) return MITCRDTTYCLICK;
	else if (s.compare("mitcrdtolclick") == 0) return MITCRDTOLCLICK;
	else if (s.compare("mitcrdfpjclick") == 0) return MITCRDFPJCLICK;
	else if (s.compare("mitcrdbilclick") == 0) return MITCRDBILCLICK;
	else if (s.compare("mitcrdartclick") == 0) return MITCRDARTCLICK;
	else if (s.compare("mitcrdskiclick") == 0) return MITCRDSKICLICK;
	else if (s.compare("mitcrdpcoclick") == 0) return MITCRDPCOCLICK;
	else if (s.compare("mitapploiclick") == 0) return MITAPPLOICLICK;

	return(0);
};

string CrdFmncNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	else if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	else if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	else if (ix == MITCRDORGCLICK) return("MitCrdOrgClick");
	else if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	else if (ix == MITCRDADRCLICK) return("MitCrdAdrClick");
	else if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	else if (ix == MITCRDSTPCLICK) return("MitCrdStpClick");
	else if (ix == MITCRDPRJCLICK) return("MitCrdPrjClick");
	else if (ix == MITCRDRUNCLICK) return("MitCrdRunClick");
	else if (ix == MITCRDACTCLICK) return("MitCrdActClick");
	else if (ix == MITCRDSEPCLICK) return("MitCrdSepClick");
	else if (ix == MITCRDSMPCLICK) return("MitCrdSmpClick");
	else if (ix == MITCRDFABCLICK) return("MitCrdFabClick");
	else if (ix == MITCRDFUSCLICK) return("MitCrdFusClick");
	else if (ix == MITCRDTTYCLICK) return("MitCrdTtyClick");
	else if (ix == MITCRDTOLCLICK) return("MitCrdTolClick");
	else if (ix == MITCRDFPJCLICK) return("MitCrdFpjClick");
	else if (ix == MITCRDBILCLICK) return("MitCrdBilClick");
	else if (ix == MITCRDARTCLICK) return("MitCrdArtClick");
	else if (ix == MITCRDSKICLICK) return("MitCrdSkiClick");
	else if (ix == MITCRDPCOCLICK) return("MitCrdPcoClick");
	else if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdFmncNav::VecVSge
 ******************************************************************************/

uint CrdFmncNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("alrfmncabt") == 0) return ALRFMNCABT;
	else if (s.compare("close") == 0) return CLOSE;

	return(0);
};

string CrdFmncNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRFMNCABT) return("alrfmncabt");
	else if (ix == CLOSE) return("close");

	return("");
};

/******************************************************************************
 class CrdFmncNav::ContInf
 ******************************************************************************/

CrdFmncNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxSesSes1 = MtxSesSes1;
	this->MtxSesSes2 = MtxSesSes2;
	this->MtxSesSes3 = MtxSesSes3;

	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

bool CrdFmncNav::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncNav";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", MtxSesSes1)) add(MTXSESSES1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", MtxSesSes2)) add(MTXSESSES2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", MtxSesSes3)) add(MTXSESSES3);
	};

	return basefound;
};

set<uint> CrdFmncNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp.compare(comp->MrlAppHlp) == 0) insert(items, MRLAPPHLP);
	if (MtxSesSes1.compare(comp->MtxSesSes1) == 0) insert(items, MTXSESSES1);
	if (MtxSesSes2.compare(comp->MtxSesSes2) == 0) insert(items, MTXSESSES2);
	if (MtxSesSes3.compare(comp->MtxSesSes3) == 0) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdFmncNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdFmncNav::StatApp
 ******************************************************************************/

CrdFmncNav::StatApp::StatApp(
			const uint ixFmncVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneLabbook
			, const bool initdoneFabmgmt
			, const bool initdoneSupply
		) : Block() {
	this->ixFmncVReqitmode = ixFmncVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdonePre = initdonePre;
	this->initdoneAdmin = initdoneAdmin;
	this->initdoneLabbook = initdoneLabbook;
	this->initdoneFabmgmt = initdoneFabmgmt;
	this->initdoneSupply = initdoneSupply;

	mask = {IXFMNCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONELABBOOK, INITDONEFABMGMT, INITDONESUPPLY};
};

bool CrdFmncNav::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVReqitmode", srefIxFmncVReqitmode)) {
			ixFmncVReqitmode = VecFmncVReqitmode::getIx(srefIxFmncVReqitmode);
			add(IXFMNCVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAdmin", initdoneAdmin)) add(INITDONEADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneLabbook", initdoneLabbook)) add(INITDONELABBOOK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFabmgmt", initdoneFabmgmt)) add(INITDONEFABMGMT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSupply", initdoneSupply)) add(INITDONESUPPLY);
	};

	return basefound;
};

set<uint> CrdFmncNav::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVReqitmode == comp->ixFmncVReqitmode) insert(items, IXFMNCVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneAdmin == comp->initdoneAdmin) insert(items, INITDONEADMIN);
	if (initdoneLabbook == comp->initdoneLabbook) insert(items, INITDONELABBOOK);
	if (initdoneFabmgmt == comp->initdoneFabmgmt) insert(items, INITDONEFABMGMT);
	if (initdoneSupply == comp->initdoneSupply) insert(items, INITDONESUPPLY);

	return(items);
};

set<uint> CrdFmncNav::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONELABBOOK, INITDONEFABMGMT, INITDONESUPPLY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdFmncNav::StatShr
 ******************************************************************************/

CrdFmncNav::StatShr::StatShr(
			const string& scrJrefDlgloaini
			, const string& scrJrefHeadbar
			, const string& scrJrefPre
			, const bool pnlpreAvail
			, const string& scrJrefAdmin
			, const bool pnladminAvail
			, const string& scrJrefLabbook
			, const bool pnllabbookAvail
			, const string& scrJrefFabmgmt
			, const bool pnlfabmgmtAvail
			, const string& scrJrefSupply
			, const bool pnlsupplyAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdOrgAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdAdrAvail
			, const bool MitCrdFilAvail
			, const bool MspCrd2Avail
			, const bool MitCrdStpAvail
			, const bool MitCrdPrjAvail
			, const bool MitCrdRunAvail
			, const bool MitCrdActAvail
			, const bool MitCrdActActive
			, const bool MitCrdSepAvail
			, const bool MitCrdSepActive
			, const bool MitCrdSmpAvail
			, const bool MspCrd3Avail
			, const bool MitCrdFabAvail
			, const bool MitCrdFusAvail
			, const bool MitCrdFusActive
			, const bool MitCrdTtyAvail
			, const bool MitCrdTolAvail
			, const bool MitCrdTolActive
			, const bool MitCrdFpjAvail
			, const bool MitCrdFpjActive
			, const bool MitCrdBilAvail
			, const bool MitCrdBilActive
			, const bool MspCrd4Avail
			, const bool MitCrdArtAvail
			, const bool MitCrdSkiAvail
			, const bool MitCrdPcoAvail
			, const bool MspApp2Avail
			, const bool MitAppLoiAvail
		) : Block() {
	this->scrJrefDlgloaini = scrJrefDlgloaini;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefPre = scrJrefPre;
	this->pnlpreAvail = pnlpreAvail;
	this->scrJrefAdmin = scrJrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->scrJrefLabbook = scrJrefLabbook;
	this->pnllabbookAvail = pnllabbookAvail;
	this->scrJrefFabmgmt = scrJrefFabmgmt;
	this->pnlfabmgmtAvail = pnlfabmgmtAvail;
	this->scrJrefSupply = scrJrefSupply;
	this->pnlsupplyAvail = pnlsupplyAvail;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUsgAvail = MitCrdUsgAvail;
	this->MitCrdUsrAvail = MitCrdUsrAvail;
	this->MitCrdOrgAvail = MitCrdOrgAvail;
	this->MitCrdPrsAvail = MitCrdPrsAvail;
	this->MitCrdAdrAvail = MitCrdAdrAvail;
	this->MitCrdFilAvail = MitCrdFilAvail;
	this->MspCrd2Avail = MspCrd2Avail;
	this->MitCrdStpAvail = MitCrdStpAvail;
	this->MitCrdPrjAvail = MitCrdPrjAvail;
	this->MitCrdRunAvail = MitCrdRunAvail;
	this->MitCrdActAvail = MitCrdActAvail;
	this->MitCrdActActive = MitCrdActActive;
	this->MitCrdSepAvail = MitCrdSepAvail;
	this->MitCrdSepActive = MitCrdSepActive;
	this->MitCrdSmpAvail = MitCrdSmpAvail;
	this->MspCrd3Avail = MspCrd3Avail;
	this->MitCrdFabAvail = MitCrdFabAvail;
	this->MitCrdFusAvail = MitCrdFusAvail;
	this->MitCrdFusActive = MitCrdFusActive;
	this->MitCrdTtyAvail = MitCrdTtyAvail;
	this->MitCrdTolAvail = MitCrdTolAvail;
	this->MitCrdTolActive = MitCrdTolActive;
	this->MitCrdFpjAvail = MitCrdFpjAvail;
	this->MitCrdFpjActive = MitCrdFpjActive;
	this->MitCrdBilAvail = MitCrdBilAvail;
	this->MitCrdBilActive = MitCrdBilActive;
	this->MspCrd4Avail = MspCrd4Avail;
	this->MitCrdArtAvail = MitCrdArtAvail;
	this->MitCrdSkiAvail = MitCrdSkiAvail;
	this->MitCrdPcoAvail = MitCrdPcoAvail;
	this->MspApp2Avail = MspApp2Avail;
	this->MitAppLoiAvail = MitAppLoiAvail;

	mask = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFLABBOOK, PNLLABBOOKAVAIL, SCRJREFFABMGMT, PNLFABMGMTAVAIL, SCRJREFSUPPLY, PNLSUPPLYAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDORGAVAIL, MITCRDPRSAVAIL, MITCRDADRAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDSTPAVAIL, MITCRDPRJAVAIL, MITCRDRUNAVAIL, MITCRDACTAVAIL, MITCRDACTACTIVE, MITCRDSEPAVAIL, MITCRDSEPACTIVE, MITCRDSMPAVAIL, MSPCRD3AVAIL, MITCRDFABAVAIL, MITCRDFUSAVAIL, MITCRDFUSACTIVE, MITCRDTTYAVAIL, MITCRDTOLAVAIL, MITCRDTOLACTIVE, MITCRDFPJAVAIL, MITCRDFPJACTIVE, MITCRDBILAVAIL, MITCRDBILACTIVE, MSPCRD4AVAIL, MITCRDARTAVAIL, MITCRDSKIAVAIL, MITCRDPCOAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

bool CrdFmncNav::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", scrJrefDlgloaini)) add(SCRJREFDLGLOAINI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlpreAvail", pnlpreAvail)) add(PNLPREAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", scrJrefAdmin)) add(SCRJREFADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnladminAvail", pnladminAvail)) add(PNLADMINAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefLabbook", scrJrefLabbook)) add(SCRJREFLABBOOK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnllabbookAvail", pnllabbookAvail)) add(PNLLABBOOKAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFabmgmt", scrJrefFabmgmt)) add(SCRJREFFABMGMT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlfabmgmtAvail", pnlfabmgmtAvail)) add(PNLFABMGMTAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSupply", scrJrefSupply)) add(SCRJREFSUPPLY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlsupplyAvail", pnlsupplyAvail)) add(PNLSUPPLYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", MitCrdUsgAvail)) add(MITCRDUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", MitCrdUsrAvail)) add(MITCRDUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdOrgAvail", MitCrdOrgAvail)) add(MITCRDORGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", MitCrdPrsAvail)) add(MITCRDPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdAdrAvail", MitCrdAdrAvail)) add(MITCRDADRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", MitCrdFilAvail)) add(MITCRDFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", MspCrd2Avail)) add(MSPCRD2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdStpAvail", MitCrdStpAvail)) add(MITCRDSTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrjAvail", MitCrdPrjAvail)) add(MITCRDPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRunAvail", MitCrdRunAvail)) add(MITCRDRUNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdActAvail", MitCrdActAvail)) add(MITCRDACTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdActActive", MitCrdActActive)) add(MITCRDACTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSepAvail", MitCrdSepAvail)) add(MITCRDSEPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSepActive", MitCrdSepActive)) add(MITCRDSEPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSmpAvail", MitCrdSmpAvail)) add(MITCRDSMPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", MspCrd3Avail)) add(MSPCRD3AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFabAvail", MitCrdFabAvail)) add(MITCRDFABAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFusAvail", MitCrdFusAvail)) add(MITCRDFUSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFusActive", MitCrdFusActive)) add(MITCRDFUSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTtyAvail", MitCrdTtyAvail)) add(MITCRDTTYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTolAvail", MitCrdTolAvail)) add(MITCRDTOLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTolActive", MitCrdTolActive)) add(MITCRDTOLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFpjAvail", MitCrdFpjAvail)) add(MITCRDFPJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFpjActive", MitCrdFpjActive)) add(MITCRDFPJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdBilAvail", MitCrdBilAvail)) add(MITCRDBILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdBilActive", MitCrdBilActive)) add(MITCRDBILACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", MspCrd4Avail)) add(MSPCRD4AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdArtAvail", MitCrdArtAvail)) add(MITCRDARTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSkiAvail", MitCrdSkiAvail)) add(MITCRDSKIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPcoAvail", MitCrdPcoAvail)) add(MITCRDPCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspApp2Avail", MspApp2Avail)) add(MSPAPP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", MitAppLoiAvail)) add(MITAPPLOIAVAIL);
	};

	return basefound;
};

set<uint> CrdFmncNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgloaini.compare(comp->scrJrefDlgloaini) == 0) insert(items, SCRJREFDLGLOAINI);
	if (scrJrefHeadbar.compare(comp->scrJrefHeadbar) == 0) insert(items, SCRJREFHEADBAR);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (scrJrefAdmin.compare(comp->scrJrefAdmin) == 0) insert(items, SCRJREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (scrJrefLabbook.compare(comp->scrJrefLabbook) == 0) insert(items, SCRJREFLABBOOK);
	if (pnllabbookAvail == comp->pnllabbookAvail) insert(items, PNLLABBOOKAVAIL);
	if (scrJrefFabmgmt.compare(comp->scrJrefFabmgmt) == 0) insert(items, SCRJREFFABMGMT);
	if (pnlfabmgmtAvail == comp->pnlfabmgmtAvail) insert(items, PNLFABMGMTAVAIL);
	if (scrJrefSupply.compare(comp->scrJrefSupply) == 0) insert(items, SCRJREFSUPPLY);
	if (pnlsupplyAvail == comp->pnlsupplyAvail) insert(items, PNLSUPPLYAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdOrgAvail == comp->MitCrdOrgAvail) insert(items, MITCRDORGAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdAdrAvail == comp->MitCrdAdrAvail) insert(items, MITCRDADRAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdStpAvail == comp->MitCrdStpAvail) insert(items, MITCRDSTPAVAIL);
	if (MitCrdPrjAvail == comp->MitCrdPrjAvail) insert(items, MITCRDPRJAVAIL);
	if (MitCrdRunAvail == comp->MitCrdRunAvail) insert(items, MITCRDRUNAVAIL);
	if (MitCrdActAvail == comp->MitCrdActAvail) insert(items, MITCRDACTAVAIL);
	if (MitCrdActActive == comp->MitCrdActActive) insert(items, MITCRDACTACTIVE);
	if (MitCrdSepAvail == comp->MitCrdSepAvail) insert(items, MITCRDSEPAVAIL);
	if (MitCrdSepActive == comp->MitCrdSepActive) insert(items, MITCRDSEPACTIVE);
	if (MitCrdSmpAvail == comp->MitCrdSmpAvail) insert(items, MITCRDSMPAVAIL);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MitCrdFabAvail == comp->MitCrdFabAvail) insert(items, MITCRDFABAVAIL);
	if (MitCrdFusAvail == comp->MitCrdFusAvail) insert(items, MITCRDFUSAVAIL);
	if (MitCrdFusActive == comp->MitCrdFusActive) insert(items, MITCRDFUSACTIVE);
	if (MitCrdTtyAvail == comp->MitCrdTtyAvail) insert(items, MITCRDTTYAVAIL);
	if (MitCrdTolAvail == comp->MitCrdTolAvail) insert(items, MITCRDTOLAVAIL);
	if (MitCrdTolActive == comp->MitCrdTolActive) insert(items, MITCRDTOLACTIVE);
	if (MitCrdFpjAvail == comp->MitCrdFpjAvail) insert(items, MITCRDFPJAVAIL);
	if (MitCrdFpjActive == comp->MitCrdFpjActive) insert(items, MITCRDFPJACTIVE);
	if (MitCrdBilAvail == comp->MitCrdBilAvail) insert(items, MITCRDBILAVAIL);
	if (MitCrdBilActive == comp->MitCrdBilActive) insert(items, MITCRDBILACTIVE);
	if (MspCrd4Avail == comp->MspCrd4Avail) insert(items, MSPCRD4AVAIL);
	if (MitCrdArtAvail == comp->MitCrdArtAvail) insert(items, MITCRDARTAVAIL);
	if (MitCrdSkiAvail == comp->MitCrdSkiAvail) insert(items, MITCRDSKIAVAIL);
	if (MitCrdPcoAvail == comp->MitCrdPcoAvail) insert(items, MITCRDPCOAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdFmncNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFLABBOOK, PNLLABBOOKAVAIL, SCRJREFFABMGMT, PNLFABMGMTAVAIL, SCRJREFSUPPLY, PNLSUPPLYAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDORGAVAIL, MITCRDPRSAVAIL, MITCRDADRAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDSTPAVAIL, MITCRDPRJAVAIL, MITCRDRUNAVAIL, MITCRDACTAVAIL, MITCRDACTACTIVE, MITCRDSEPAVAIL, MITCRDSEPACTIVE, MITCRDSMPAVAIL, MSPCRD3AVAIL, MITCRDFABAVAIL, MITCRDFUSAVAIL, MITCRDFUSACTIVE, MITCRDTTYAVAIL, MITCRDTOLAVAIL, MITCRDTOLACTIVE, MITCRDFPJAVAIL, MITCRDFPJACTIVE, MITCRDBILAVAIL, MITCRDBILACTIVE, MSPCRD4AVAIL, MITCRDARTAVAIL, MITCRDSKIAVAIL, MITCRDPCOAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdFmncNav::Tag
 ******************************************************************************/

CrdFmncNav::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitSesTrm
			, const string& MitCrdUsg
			, const string& MitCrdUsr
			, const string& MitCrdOrg
			, const string& MitCrdPrs
			, const string& MitCrdAdr
			, const string& MitCrdFil
			, const string& MitCrdStp
			, const string& MitCrdPrj
			, const string& MitCrdRun
			, const string& MitCrdAct
			, const string& MitCrdSep
			, const string& MitCrdSmp
			, const string& MitCrdFab
			, const string& MitCrdFus
			, const string& MitCrdTty
			, const string& MitCrdTol
			, const string& MitCrdFpj
			, const string& MitCrdBil
			, const string& MitCrdArt
			, const string& MitCrdSki
			, const string& MitCrdPco
			, const string& MitAppLoi
		) : Block() {
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitSesTrm = MitSesTrm;
	this->MitCrdUsg = MitCrdUsg;
	this->MitCrdUsr = MitCrdUsr;
	this->MitCrdOrg = MitCrdOrg;
	this->MitCrdPrs = MitCrdPrs;
	this->MitCrdAdr = MitCrdAdr;
	this->MitCrdFil = MitCrdFil;
	this->MitCrdStp = MitCrdStp;
	this->MitCrdPrj = MitCrdPrj;
	this->MitCrdRun = MitCrdRun;
	this->MitCrdAct = MitCrdAct;
	this->MitCrdSep = MitCrdSep;
	this->MitCrdSmp = MitCrdSmp;
	this->MitCrdFab = MitCrdFab;
	this->MitCrdFus = MitCrdFus;
	this->MitCrdTty = MitCrdTty;
	this->MitCrdTol = MitCrdTol;
	this->MitCrdFpj = MitCrdFpj;
	this->MitCrdBil = MitCrdBil;
	this->MitCrdArt = MitCrdArt;
	this->MitCrdSki = MitCrdSki;
	this->MitCrdPco = MitCrdPco;
	this->MitAppLoi = MitAppLoi;

	mask = {MITAPPABT, MRLAPPHLP, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDORG, MITCRDPRS, MITCRDADR, MITCRDFIL, MITCRDSTP, MITCRDPRJ, MITCRDRUN, MITCRDACT, MITCRDSEP, MITCRDSMP, MITCRDFAB, MITCRDFUS, MITCRDTTY, MITCRDTOL, MITCRDFPJ, MITCRDBIL, MITCRDART, MITCRDSKI, MITCRDPCO, MITAPPLOI};
};

bool CrdFmncNav::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesTrm", MitSesTrm)) add(MITSESTRM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", MitCrdUsg)) add(MITCRDUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", MitCrdUsr)) add(MITCRDUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdOrg", MitCrdOrg)) add(MITCRDORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", MitCrdPrs)) add(MITCRDPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdAdr", MitCrdAdr)) add(MITCRDADR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFil", MitCrdFil)) add(MITCRDFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdStp", MitCrdStp)) add(MITCRDSTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrj", MitCrdPrj)) add(MITCRDPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdRun", MitCrdRun)) add(MITCRDRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdAct", MitCrdAct)) add(MITCRDACT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSep", MitCrdSep)) add(MITCRDSEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSmp", MitCrdSmp)) add(MITCRDSMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFab", MitCrdFab)) add(MITCRDFAB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFus", MitCrdFus)) add(MITCRDFUS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTty", MitCrdTty)) add(MITCRDTTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTol", MitCrdTol)) add(MITCRDTOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFpj", MitCrdFpj)) add(MITCRDFPJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdBil", MitCrdBil)) add(MITCRDBIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdArt", MitCrdArt)) add(MITCRDART);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSki", MitCrdSki)) add(MITCRDSKI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPco", MitCrdPco)) add(MITCRDPCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppLoi", MitAppLoi)) add(MITAPPLOI);
	};

	return basefound;
};

/******************************************************************************
 class CrdFmncNav::DpchAppDo
 ******************************************************************************/

CrdFmncNav::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdFmncNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdFmncNav::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncNavDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdFmncNav::DpchEngData
 ******************************************************************************/

CrdFmncNav::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVDATA) {
	feedFSge.tag = "FeedFSge";
};

string CrdFmncNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdFmncNav::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncNavData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

