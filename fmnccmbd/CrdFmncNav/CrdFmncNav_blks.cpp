/**
  * \file CrdFmncNav_blks.cpp
  * job handler for job CrdFmncNav (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class CrdFmncNav::VecVDo
 ******************************************************************************/

uint CrdFmncNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;
	else if (s == "mitsestrmclick") return MITSESTRMCLICK;
	else if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	else if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	else if (s == "mitcrdorgclick") return MITCRDORGCLICK;
	else if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	else if (s == "mitcrdadrclick") return MITCRDADRCLICK;
	else if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	else if (s == "mitcrdstpclick") return MITCRDSTPCLICK;
	else if (s == "mitcrdprjclick") return MITCRDPRJCLICK;
	else if (s == "mitcrdrunclick") return MITCRDRUNCLICK;
	else if (s == "mitcrdactclick") return MITCRDACTCLICK;
	else if (s == "mitcrdsepclick") return MITCRDSEPCLICK;
	else if (s == "mitcrdsmpclick") return MITCRDSMPCLICK;
	else if (s == "mitcrdfabclick") return MITCRDFABCLICK;
	else if (s == "mitcrdfusclick") return MITCRDFUSCLICK;
	else if (s == "mitcrdttyclick") return MITCRDTTYCLICK;
	else if (s == "mitcrdtolclick") return MITCRDTOLCLICK;
	else if (s == "mitcrdfpjclick") return MITCRDFPJCLICK;
	else if (s == "mitcrdbilclick") return MITCRDBILCLICK;
	else if (s == "mitcrdartclick") return MITCRDARTCLICK;
	else if (s == "mitcrdskiclick") return MITCRDSKICLICK;
	else if (s == "mitcrdpcoclick") return MITCRDPCOCLICK;
	else if (s == "mitapploiclick") return MITAPPLOICLICK;

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

	if (s == "idle") return IDLE;
	else if (s == "alrfmncabt") return ALRFMNCABT;
	else if (s == "close") return CLOSE;

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

void CrdFmncNav::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void CrdFmncNav::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncNav";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes1", MtxSesSes1);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes2", MtxSesSes2);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes3", MtxSesSes3);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdFmncNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

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

void CrdFmncNav::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneLabbook
			, const bool initdoneFabmgmt
			, const bool initdoneSupply
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVReqitmode", VecFmncVReqitmode::getSref(ixFmncVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAdmin", initdoneAdmin);
		writeBoolAttr(wr, itemtag, "sref", "initdoneLabbook", initdoneLabbook);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFabmgmt", initdoneFabmgmt);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSupply", initdoneSupply);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdFmncNav::StatShr
 ******************************************************************************/

CrdFmncNav::StatShr::StatShr(
			const ubigint jrefDlgloaini
			, const ubigint jrefHeadbar
			, const ubigint jrefPre
			, const bool pnlpreAvail
			, const ubigint jrefAdmin
			, const bool pnladminAvail
			, const ubigint jrefLabbook
			, const bool pnllabbookAvail
			, const ubigint jrefFabmgmt
			, const bool pnlfabmgmtAvail
			, const ubigint jrefSupply
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
	this->jrefDlgloaini = jrefDlgloaini;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefPre = jrefPre;
	this->pnlpreAvail = pnlpreAvail;
	this->jrefAdmin = jrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->jrefLabbook = jrefLabbook;
	this->pnllabbookAvail = pnllabbookAvail;
	this->jrefFabmgmt = jrefFabmgmt;
	this->pnlfabmgmtAvail = pnlfabmgmtAvail;
	this->jrefSupply = jrefSupply;
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

	mask = {JREFDLGLOAINI, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFLABBOOK, PNLLABBOOKAVAIL, JREFFABMGMT, PNLFABMGMTAVAIL, JREFSUPPLY, PNLSUPPLYAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDORGAVAIL, MITCRDPRSAVAIL, MITCRDADRAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDSTPAVAIL, MITCRDPRJAVAIL, MITCRDRUNAVAIL, MITCRDACTAVAIL, MITCRDACTACTIVE, MITCRDSEPAVAIL, MITCRDSEPACTIVE, MITCRDSMPAVAIL, MSPCRD3AVAIL, MITCRDFABAVAIL, MITCRDFUSAVAIL, MITCRDFUSACTIVE, MITCRDTTYAVAIL, MITCRDTOLAVAIL, MITCRDTOLACTIVE, MITCRDFPJAVAIL, MITCRDFPJACTIVE, MITCRDBILAVAIL, MITCRDBILACTIVE, MSPCRD4AVAIL, MITCRDARTAVAIL, MITCRDSKIAVAIL, MITCRDPCOAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

void CrdFmncNav::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgloaini", Scr::scramble(mScr, scr, descr, jrefDlgloaini));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(mScr, scr, descr, jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeBoolAttr(wr, itemtag, "sref", "pnlpreAvail", pnlpreAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAdmin", Scr::scramble(mScr, scr, descr, jrefAdmin));
		writeBoolAttr(wr, itemtag, "sref", "pnladminAvail", pnladminAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefLabbook", Scr::scramble(mScr, scr, descr, jrefLabbook));
		writeBoolAttr(wr, itemtag, "sref", "pnllabbookAvail", pnllabbookAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefFabmgmt", Scr::scramble(mScr, scr, descr, jrefFabmgmt));
		writeBoolAttr(wr, itemtag, "sref", "pnlfabmgmtAvail", pnlfabmgmtAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefSupply", Scr::scramble(mScr, scr, descr, jrefSupply));
		writeBoolAttr(wr, itemtag, "sref", "pnlsupplyAvail", pnlsupplyAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsgAvail", MitCrdUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsrAvail", MitCrdUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOrgAvail", MitCrdOrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrsAvail", MitCrdPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdAdrAvail", MitCrdAdrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFilAvail", MitCrdFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd2Avail", MspCrd2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdStpAvail", MitCrdStpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrjAvail", MitCrdPrjAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRunAvail", MitCrdRunAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdActAvail", MitCrdActAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdActActive", MitCrdActActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSepAvail", MitCrdSepAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSepActive", MitCrdSepActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSmpAvail", MitCrdSmpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Avail", MspCrd3Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFabAvail", MitCrdFabAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFusAvail", MitCrdFusAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFusActive", MitCrdFusActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTtyAvail", MitCrdTtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTolAvail", MitCrdTolAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTolActive", MitCrdTolActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFpjAvail", MitCrdFpjAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFpjActive", MitCrdFpjActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdBilAvail", MitCrdBilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdBilActive", MitCrdBilActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd4Avail", MspCrd4Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdArtAvail", MitCrdArtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSkiAvail", MitCrdSkiAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPcoAvail", MitCrdPcoAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspApp2Avail", MspApp2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppLoiAvail", MitAppLoiAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdFmncNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgloaini == comp->jrefDlgloaini) insert(items, JREFDLGLOAINI);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (jrefAdmin == comp->jrefAdmin) insert(items, JREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (jrefLabbook == comp->jrefLabbook) insert(items, JREFLABBOOK);
	if (pnllabbookAvail == comp->pnllabbookAvail) insert(items, PNLLABBOOKAVAIL);
	if (jrefFabmgmt == comp->jrefFabmgmt) insert(items, JREFFABMGMT);
	if (pnlfabmgmtAvail == comp->pnlfabmgmtAvail) insert(items, PNLFABMGMTAVAIL);
	if (jrefSupply == comp->jrefSupply) insert(items, JREFSUPPLY);
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

	diffitems = {JREFDLGLOAINI, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFLABBOOK, PNLLABBOOKAVAIL, JREFFABMGMT, PNLFABMGMTAVAIL, JREFSUPPLY, PNLSUPPLYAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDORGAVAIL, MITCRDPRSAVAIL, MITCRDADRAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDSTPAVAIL, MITCRDPRJAVAIL, MITCRDRUNAVAIL, MITCRDACTAVAIL, MITCRDACTACTIVE, MITCRDSEPAVAIL, MITCRDSEPACTIVE, MITCRDSMPAVAIL, MSPCRD3AVAIL, MITCRDFABAVAIL, MITCRDFUSAVAIL, MITCRDFUSACTIVE, MITCRDTTYAVAIL, MITCRDTOLAVAIL, MITCRDTOLACTIVE, MITCRDFPJAVAIL, MITCRDFPJACTIVE, MITCRDBILAVAIL, MITCRDBILACTIVE, MSPCRD4AVAIL, MITCRDARTAVAIL, MITCRDSKIAVAIL, MITCRDPCOAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdFmncNav::Tag
 ******************************************************************************/

void CrdFmncNav::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncNav";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "User groups ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOrg", "Organizations ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Persons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdAdr", "Addresses ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Files ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdStp", "Recipes ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrj", "Projects ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRun", "Runs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdAct", "Activities ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSep", "Steps ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSmp", "Samples ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFab", "Fabs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFus", "Fab users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTty", "Tool types ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTol", "Tools ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFpj", "Fab projects ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdBil", "Bills ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdArt", "Articles ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSki", "Stock items ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPco", "Purchase orders ...");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "Benutzergruppen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Benutzer ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOrg", "Organisationen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Personen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdAdr", "Adressen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Dateien ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdStp", "Rezepte ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrj", "Projekte ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRun", "L\\u00e4ufe ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdAct", "Aktivit\\u00e4ten ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSep", "Schritte ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSmp", "Samples ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFab", "Reinr\\u00e4ume ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFus", "Reinraumnutzer ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTty", "Ger\\u00e4tetypen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTol", "Ger\\u00e4te ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFpj", "Reinraumprojekte ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdBil", "Rechnungen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdArt", "Artikel ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSki", "Lagerposten ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPco", "Bestellungen ...");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "Groupes d'utilisateurs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Utilisateurs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOrg", "Organismes ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Individus ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdAdr", "Adresses ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Fichiers ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdStp", "Recettes ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrj", "Projets ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRun", "D\\u00e9roulements ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdAct", "Activit\\u00e9s ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSep", "\\u00e9tapes ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSmp", "\\u00e9chantillons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFab", "Salles blanches ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFus", "Utilisateurs salle blanche ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTty", "Types d'\\u00e9quipement ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTol", "\\u00e9quipements ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFpj", "Projets salle blanche ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdBil", "Factures ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdArt", "Articles ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSki", "Postes du stock ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPco", "Commandes ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::ABOUT, ixFmncVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::HELP, ixFmncVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitSesTrm", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::CLSESS, ixFmncVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitAppLoi", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::LOAINI, ixFmncVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdFmncNav::DpchAppDo
 ******************************************************************************/

CrdFmncNav::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVDO) {
	ixVDo = 0;
};

string CrdFmncNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdFmncNav::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class CrdFmncNav::DpchEngData
 ******************************************************************************/

CrdFmncNav::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdFmncNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdFmncNav::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdFmncNav::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncNavData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


