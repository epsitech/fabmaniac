/**
  * \file PnlFmncNavLabbook.cpp
  * API code for job PnlFmncNavLabbook (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncNavLabbook.h"

/******************************************************************************
 class PnlFmncNavLabbook::VecVDo
 ******************************************************************************/

uint PnlFmncNavLabbook::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butstpviewclick") == 0) return BUTSTPVIEWCLICK;
	else if (s.compare("butstpnewcrdclick") == 0) return BUTSTPNEWCRDCLICK;
	else if (s.compare("butprjviewclick") == 0) return BUTPRJVIEWCLICK;
	else if (s.compare("butprjnewcrdclick") == 0) return BUTPRJNEWCRDCLICK;
	else if (s.compare("butrunviewclick") == 0) return BUTRUNVIEWCLICK;
	else if (s.compare("butrunnewcrdclick") == 0) return BUTRUNNEWCRDCLICK;
	else if (s.compare("butactviewclick") == 0) return BUTACTVIEWCLICK;
	else if (s.compare("butactnewcrdclick") == 0) return BUTACTNEWCRDCLICK;
	else if (s.compare("butsepviewclick") == 0) return BUTSEPVIEWCLICK;
	else if (s.compare("butsepnewcrdclick") == 0) return BUTSEPNEWCRDCLICK;
	else if (s.compare("butsmpviewclick") == 0) return BUTSMPVIEWCLICK;
	else if (s.compare("butsmpnewcrdclick") == 0) return BUTSMPNEWCRDCLICK;

	return(0);
};

string PnlFmncNavLabbook::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSTPVIEWCLICK) return("ButStpViewClick");
	else if (ix == BUTSTPNEWCRDCLICK) return("ButStpNewcrdClick");
	else if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	else if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
	else if (ix == BUTRUNVIEWCLICK) return("ButRunViewClick");
	else if (ix == BUTRUNNEWCRDCLICK) return("ButRunNewcrdClick");
	else if (ix == BUTACTVIEWCLICK) return("ButActViewClick");
	else if (ix == BUTACTNEWCRDCLICK) return("ButActNewcrdClick");
	else if (ix == BUTSEPVIEWCLICK) return("ButSepViewClick");
	else if (ix == BUTSEPNEWCRDCLICK) return("ButSepNewcrdClick");
	else if (ix == BUTSMPVIEWCLICK) return("ButSmpViewClick");
	else if (ix == BUTSMPNEWCRDCLICK) return("ButSmpNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlFmncNavLabbook::ContIac
 ******************************************************************************/

PnlFmncNavLabbook::ContIac::ContIac(
			const uint numFLstStp
			, const uint numFLstPrj
			, const uint numFLstRun
			, const uint numFLstAct
			, const uint numFLstSep
			, const uint numFLstSmp
		) : Block() {
	this->numFLstStp = numFLstStp;
	this->numFLstPrj = numFLstPrj;
	this->numFLstRun = numFLstRun;
	this->numFLstAct = numFLstAct;
	this->numFLstSep = numFLstSep;
	this->numFLstSmp = numFLstSmp;

	mask = {NUMFLSTSTP, NUMFLSTPRJ, NUMFLSTRUN, NUMFLSTACT, NUMFLSTSEP, NUMFLSTSMP};
};

bool PnlFmncNavLabbook::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncNavLabbook");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncNavLabbook";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstStp", numFLstStp)) add(NUMFLSTSTP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrj", numFLstPrj)) add(NUMFLSTPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRun", numFLstRun)) add(NUMFLSTRUN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstAct", numFLstAct)) add(NUMFLSTACT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSep", numFLstSep)) add(NUMFLSTSEP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSmp", numFLstSmp)) add(NUMFLSTSMP);
	};

	return basefound;
};

void PnlFmncNavLabbook::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncNavLabbook";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncNavLabbook";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstStp", numFLstStp);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrj", numFLstPrj);
		writeUintAttr(wr, itemtag, "sref", "numFLstRun", numFLstRun);
		writeUintAttr(wr, itemtag, "sref", "numFLstAct", numFLstAct);
		writeUintAttr(wr, itemtag, "sref", "numFLstSep", numFLstSep);
		writeUintAttr(wr, itemtag, "sref", "numFLstSmp", numFLstSmp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavLabbook::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstStp == comp->numFLstStp) insert(items, NUMFLSTSTP);
	if (numFLstPrj == comp->numFLstPrj) insert(items, NUMFLSTPRJ);
	if (numFLstRun == comp->numFLstRun) insert(items, NUMFLSTRUN);
	if (numFLstAct == comp->numFLstAct) insert(items, NUMFLSTACT);
	if (numFLstSep == comp->numFLstSep) insert(items, NUMFLSTSEP);
	if (numFLstSmp == comp->numFLstSmp) insert(items, NUMFLSTSMP);

	return(items);
};

set<uint> PnlFmncNavLabbook::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTSTP, NUMFLSTPRJ, NUMFLSTRUN, NUMFLSTACT, NUMFLSTSEP, NUMFLSTSMP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavLabbook::StatApp
 ******************************************************************************/

PnlFmncNavLabbook::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool LstStpAlt
			, const bool LstPrjAlt
			, const bool LstRunAlt
			, const bool LstActAlt
			, const bool LstSepAlt
			, const bool LstSmpAlt
			, const uint LstStpNumFirstdisp
			, const uint LstPrjNumFirstdisp
			, const uint LstRunNumFirstdisp
			, const uint LstActNumFirstdisp
			, const uint LstSepNumFirstdisp
			, const uint LstSmpNumFirstdisp
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->LstStpAlt = LstStpAlt;
	this->LstPrjAlt = LstPrjAlt;
	this->LstRunAlt = LstRunAlt;
	this->LstActAlt = LstActAlt;
	this->LstSepAlt = LstSepAlt;
	this->LstSmpAlt = LstSmpAlt;
	this->LstStpNumFirstdisp = LstStpNumFirstdisp;
	this->LstPrjNumFirstdisp = LstPrjNumFirstdisp;
	this->LstRunNumFirstdisp = LstRunNumFirstdisp;
	this->LstActNumFirstdisp = LstActNumFirstdisp;
	this->LstSepNumFirstdisp = LstSepNumFirstdisp;
	this->LstSmpNumFirstdisp = LstSmpNumFirstdisp;

	mask = {IXFMNCVEXPSTATE, LSTSTPALT, LSTPRJALT, LSTRUNALT, LSTACTALT, LSTSEPALT, LSTSMPALT, LSTSTPNUMFIRSTDISP, LSTPRJNUMFIRSTDISP, LSTRUNNUMFIRSTDISP, LSTACTNUMFIRSTDISP, LSTSEPNUMFIRSTDISP, LSTSMPNUMFIRSTDISP};
};

bool PnlFmncNavLabbook::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncNavLabbook");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncNavLabbook";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStpAlt", LstStpAlt)) add(LSTSTPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAlt", LstPrjAlt)) add(LSTPRJALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRunAlt", LstRunAlt)) add(LSTRUNALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstActAlt", LstActAlt)) add(LSTACTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSepAlt", LstSepAlt)) add(LSTSEPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSmpAlt", LstSmpAlt)) add(LSTSMPALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStpNumFirstdisp", LstStpNumFirstdisp)) add(LSTSTPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp)) add(LSTPRJNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRunNumFirstdisp", LstRunNumFirstdisp)) add(LSTRUNNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstActNumFirstdisp", LstActNumFirstdisp)) add(LSTACTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSepNumFirstdisp", LstSepNumFirstdisp)) add(LSTSEPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSmpNumFirstdisp", LstSmpNumFirstdisp)) add(LSTSMPNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlFmncNavLabbook::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (LstStpAlt == comp->LstStpAlt) insert(items, LSTSTPALT);
	if (LstPrjAlt == comp->LstPrjAlt) insert(items, LSTPRJALT);
	if (LstRunAlt == comp->LstRunAlt) insert(items, LSTRUNALT);
	if (LstActAlt == comp->LstActAlt) insert(items, LSTACTALT);
	if (LstSepAlt == comp->LstSepAlt) insert(items, LSTSEPALT);
	if (LstSmpAlt == comp->LstSmpAlt) insert(items, LSTSMPALT);
	if (LstStpNumFirstdisp == comp->LstStpNumFirstdisp) insert(items, LSTSTPNUMFIRSTDISP);
	if (LstPrjNumFirstdisp == comp->LstPrjNumFirstdisp) insert(items, LSTPRJNUMFIRSTDISP);
	if (LstRunNumFirstdisp == comp->LstRunNumFirstdisp) insert(items, LSTRUNNUMFIRSTDISP);
	if (LstActNumFirstdisp == comp->LstActNumFirstdisp) insert(items, LSTACTNUMFIRSTDISP);
	if (LstSepNumFirstdisp == comp->LstSepNumFirstdisp) insert(items, LSTSEPNUMFIRSTDISP);
	if (LstSmpNumFirstdisp == comp->LstSmpNumFirstdisp) insert(items, LSTSMPNUMFIRSTDISP);

	return(items);
};

set<uint> PnlFmncNavLabbook::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, LSTSTPALT, LSTPRJALT, LSTRUNALT, LSTACTALT, LSTSEPALT, LSTSMPALT, LSTSTPNUMFIRSTDISP, LSTPRJNUMFIRSTDISP, LSTRUNNUMFIRSTDISP, LSTACTNUMFIRSTDISP, LSTSEPNUMFIRSTDISP, LSTSMPNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavLabbook::StatShr
 ******************************************************************************/

PnlFmncNavLabbook::StatShr::StatShr(
			const bool LstStpAvail
			, const bool ButStpViewActive
			, const bool LstPrjAvail
			, const bool ButPrjViewActive
			, const bool LstRunAvail
			, const bool ButRunViewActive
			, const bool LstActAvail
			, const bool ButActViewActive
			, const bool ButActNewcrdActive
			, const bool LstSepAvail
			, const bool ButSepViewActive
			, const bool ButSepNewcrdActive
			, const bool LstSmpAvail
			, const bool ButSmpViewActive
		) : Block() {
	this->LstStpAvail = LstStpAvail;
	this->ButStpViewActive = ButStpViewActive;
	this->LstPrjAvail = LstPrjAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->LstRunAvail = LstRunAvail;
	this->ButRunViewActive = ButRunViewActive;
	this->LstActAvail = LstActAvail;
	this->ButActViewActive = ButActViewActive;
	this->ButActNewcrdActive = ButActNewcrdActive;
	this->LstSepAvail = LstSepAvail;
	this->ButSepViewActive = ButSepViewActive;
	this->ButSepNewcrdActive = ButSepNewcrdActive;
	this->LstSmpAvail = LstSmpAvail;
	this->ButSmpViewActive = ButSmpViewActive;

	mask = {LSTSTPAVAIL, BUTSTPVIEWACTIVE, LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTRUNAVAIL, BUTRUNVIEWACTIVE, LSTACTAVAIL, BUTACTVIEWACTIVE, BUTACTNEWCRDACTIVE, LSTSEPAVAIL, BUTSEPVIEWACTIVE, BUTSEPNEWCRDACTIVE, LSTSMPAVAIL, BUTSMPVIEWACTIVE};
};

bool PnlFmncNavLabbook::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncNavLabbook");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncNavLabbook";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStpAvail", LstStpAvail)) add(LSTSTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStpViewActive", ButStpViewActive)) add(BUTSTPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAvail", LstPrjAvail)) add(LSTPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", ButPrjViewActive)) add(BUTPRJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRunAvail", LstRunAvail)) add(LSTRUNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunViewActive", ButRunViewActive)) add(BUTRUNVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstActAvail", LstActAvail)) add(LSTACTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButActViewActive", ButActViewActive)) add(BUTACTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButActNewcrdActive", ButActNewcrdActive)) add(BUTACTNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSepAvail", LstSepAvail)) add(LSTSEPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSepViewActive", ButSepViewActive)) add(BUTSEPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSepNewcrdActive", ButSepNewcrdActive)) add(BUTSEPNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSmpAvail", LstSmpAvail)) add(LSTSMPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSmpViewActive", ButSmpViewActive)) add(BUTSMPVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncNavLabbook::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstStpAvail == comp->LstStpAvail) insert(items, LSTSTPAVAIL);
	if (ButStpViewActive == comp->ButStpViewActive) insert(items, BUTSTPVIEWACTIVE);
	if (LstPrjAvail == comp->LstPrjAvail) insert(items, LSTPRJAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (LstRunAvail == comp->LstRunAvail) insert(items, LSTRUNAVAIL);
	if (ButRunViewActive == comp->ButRunViewActive) insert(items, BUTRUNVIEWACTIVE);
	if (LstActAvail == comp->LstActAvail) insert(items, LSTACTAVAIL);
	if (ButActViewActive == comp->ButActViewActive) insert(items, BUTACTVIEWACTIVE);
	if (ButActNewcrdActive == comp->ButActNewcrdActive) insert(items, BUTACTNEWCRDACTIVE);
	if (LstSepAvail == comp->LstSepAvail) insert(items, LSTSEPAVAIL);
	if (ButSepViewActive == comp->ButSepViewActive) insert(items, BUTSEPVIEWACTIVE);
	if (ButSepNewcrdActive == comp->ButSepNewcrdActive) insert(items, BUTSEPNEWCRDACTIVE);
	if (LstSmpAvail == comp->LstSmpAvail) insert(items, LSTSMPAVAIL);
	if (ButSmpViewActive == comp->ButSmpViewActive) insert(items, BUTSMPVIEWACTIVE);

	return(items);
};

set<uint> PnlFmncNavLabbook::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTSTPAVAIL, BUTSTPVIEWACTIVE, LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTRUNAVAIL, BUTRUNVIEWACTIVE, LSTACTAVAIL, BUTACTVIEWACTIVE, BUTACTNEWCRDACTIVE, LSTSEPAVAIL, BUTSEPVIEWACTIVE, BUTSEPNEWCRDACTIVE, LSTSMPAVAIL, BUTSMPVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavLabbook::Tag
 ******************************************************************************/

PnlFmncNavLabbook::Tag::Tag(
			const string& Cpt
			, const string& CptStp
			, const string& CptPrj
			, const string& CptRun
			, const string& CptAct
			, const string& CptSep
			, const string& CptSmp
		) : Block() {
	this->Cpt = Cpt;
	this->CptStp = CptStp;
	this->CptPrj = CptPrj;
	this->CptRun = CptRun;
	this->CptAct = CptAct;
	this->CptSep = CptSep;
	this->CptSmp = CptSmp;

	mask = {CPT, CPTSTP, CPTPRJ, CPTRUN, CPTACT, CPTSEP, CPTSMP};
};

bool PnlFmncNavLabbook::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncNavLabbook");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncNavLabbook";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStp", CptStp)) add(CPTSTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRun", CptRun)) add(CPTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAct", CptAct)) add(CPTACT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSep", CptSep)) add(CPTSEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSmp", CptSmp)) add(CPTSMP);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncNavLabbook::DpchAppData
 ******************************************************************************/

PnlFmncNavLabbook::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVLABBOOKDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncNavLabbook::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavLabbook::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncNavLabbookData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavLabbook::DpchAppDo
 ******************************************************************************/

PnlFmncNavLabbook::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVLABBOOKDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncNavLabbook::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavLabbook::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncNavLabbookDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavLabbook::DpchEngData
 ******************************************************************************/

PnlFmncNavLabbook::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVLABBOOKDATA) {
	feedFLstAct.tag = "FeedFLstAct";
	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstRun.tag = "FeedFLstRun";
	feedFLstSep.tag = "FeedFLstSep";
	feedFLstSmp.tag = "FeedFLstSmp";
	feedFLstStp.tag = "FeedFLstStp";
};

string PnlFmncNavLabbook::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTACT)) ss.push_back("feedFLstAct");
	if (has(FEEDFLSTPRJ)) ss.push_back("feedFLstPrj");
	if (has(FEEDFLSTRUN)) ss.push_back("feedFLstRun");
	if (has(FEEDFLSTSEP)) ss.push_back("feedFLstSep");
	if (has(FEEDFLSTSMP)) ss.push_back("feedFLstSmp");
	if (has(FEEDFLSTSTP)) ss.push_back("feedFLstStp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavLabbook::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncNavLabbookData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstAct.readXML(docctx, basexpath, true)) add(FEEDFLSTACT);
		if (feedFLstPrj.readXML(docctx, basexpath, true)) add(FEEDFLSTPRJ);
		if (feedFLstRun.readXML(docctx, basexpath, true)) add(FEEDFLSTRUN);
		if (feedFLstSep.readXML(docctx, basexpath, true)) add(FEEDFLSTSEP);
		if (feedFLstSmp.readXML(docctx, basexpath, true)) add(FEEDFLSTSMP);
		if (feedFLstStp.readXML(docctx, basexpath, true)) add(FEEDFLSTSTP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstAct.clear();
		feedFLstPrj.clear();
		feedFLstRun.clear();
		feedFLstSep.clear();
		feedFLstSmp.clear();
		feedFLstStp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

