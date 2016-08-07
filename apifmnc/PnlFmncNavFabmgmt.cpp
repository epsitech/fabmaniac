/**
  * \file PnlFmncNavFabmgmt.cpp
  * API code for job PnlFmncNavFabmgmt (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncNavFabmgmt.h"

/******************************************************************************
 class PnlFmncNavFabmgmt::VecVDo
 ******************************************************************************/

uint PnlFmncNavFabmgmt::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butfabviewclick") == 0) return BUTFABVIEWCLICK;
	else if (s.compare("butfabnewcrdclick") == 0) return BUTFABNEWCRDCLICK;
	else if (s.compare("butfusviewclick") == 0) return BUTFUSVIEWCLICK;
	else if (s.compare("butfusnewcrdclick") == 0) return BUTFUSNEWCRDCLICK;
	else if (s.compare("butttyviewclick") == 0) return BUTTTYVIEWCLICK;
	else if (s.compare("butttynewcrdclick") == 0) return BUTTTYNEWCRDCLICK;
	else if (s.compare("buttolviewclick") == 0) return BUTTOLVIEWCLICK;
	else if (s.compare("buttolnewcrdclick") == 0) return BUTTOLNEWCRDCLICK;
	else if (s.compare("butfpjviewclick") == 0) return BUTFPJVIEWCLICK;
	else if (s.compare("butfpjnewcrdclick") == 0) return BUTFPJNEWCRDCLICK;
	else if (s.compare("butbilviewclick") == 0) return BUTBILVIEWCLICK;
	else if (s.compare("butbilnewcrdclick") == 0) return BUTBILNEWCRDCLICK;

	return(0);
};

string PnlFmncNavFabmgmt::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTFABVIEWCLICK) return("ButFabViewClick");
	else if (ix == BUTFABNEWCRDCLICK) return("ButFabNewcrdClick");
	else if (ix == BUTFUSVIEWCLICK) return("ButFusViewClick");
	else if (ix == BUTFUSNEWCRDCLICK) return("ButFusNewcrdClick");
	else if (ix == BUTTTYVIEWCLICK) return("ButTtyViewClick");
	else if (ix == BUTTTYNEWCRDCLICK) return("ButTtyNewcrdClick");
	else if (ix == BUTTOLVIEWCLICK) return("ButTolViewClick");
	else if (ix == BUTTOLNEWCRDCLICK) return("ButTolNewcrdClick");
	else if (ix == BUTFPJVIEWCLICK) return("ButFpjViewClick");
	else if (ix == BUTFPJNEWCRDCLICK) return("ButFpjNewcrdClick");
	else if (ix == BUTBILVIEWCLICK) return("ButBilViewClick");
	else if (ix == BUTBILNEWCRDCLICK) return("ButBilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlFmncNavFabmgmt::ContIac
 ******************************************************************************/

PnlFmncNavFabmgmt::ContIac::ContIac(
			const uint numFLstFab
			, const uint numFLstFus
			, const uint numFLstTty
			, const uint numFLstTol
			, const uint numFLstFpj
			, const uint numFLstBil
		) : Block() {
	this->numFLstFab = numFLstFab;
	this->numFLstFus = numFLstFus;
	this->numFLstTty = numFLstTty;
	this->numFLstTol = numFLstTol;
	this->numFLstFpj = numFLstFpj;
	this->numFLstBil = numFLstBil;

	mask = {NUMFLSTFAB, NUMFLSTFUS, NUMFLSTTTY, NUMFLSTTOL, NUMFLSTFPJ, NUMFLSTBIL};
};

bool PnlFmncNavFabmgmt::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncNavFabmgmt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncNavFabmgmt";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFab", numFLstFab)) add(NUMFLSTFAB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFus", numFLstFus)) add(NUMFLSTFUS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTty", numFLstTty)) add(NUMFLSTTTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTol", numFLstTol)) add(NUMFLSTTOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFpj", numFLstFpj)) add(NUMFLSTFPJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstBil", numFLstBil)) add(NUMFLSTBIL);
	};

	return basefound;
};

void PnlFmncNavFabmgmt::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncNavFabmgmt";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncNavFabmgmt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstFab", numFLstFab);
		writeUintAttr(wr, itemtag, "sref", "numFLstFus", numFLstFus);
		writeUintAttr(wr, itemtag, "sref", "numFLstTty", numFLstTty);
		writeUintAttr(wr, itemtag, "sref", "numFLstTol", numFLstTol);
		writeUintAttr(wr, itemtag, "sref", "numFLstFpj", numFLstFpj);
		writeUintAttr(wr, itemtag, "sref", "numFLstBil", numFLstBil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavFabmgmt::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstFab == comp->numFLstFab) insert(items, NUMFLSTFAB);
	if (numFLstFus == comp->numFLstFus) insert(items, NUMFLSTFUS);
	if (numFLstTty == comp->numFLstTty) insert(items, NUMFLSTTTY);
	if (numFLstTol == comp->numFLstTol) insert(items, NUMFLSTTOL);
	if (numFLstFpj == comp->numFLstFpj) insert(items, NUMFLSTFPJ);
	if (numFLstBil == comp->numFLstBil) insert(items, NUMFLSTBIL);

	return(items);
};

set<uint> PnlFmncNavFabmgmt::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTFAB, NUMFLSTFUS, NUMFLSTTTY, NUMFLSTTOL, NUMFLSTFPJ, NUMFLSTBIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::StatApp
 ******************************************************************************/

PnlFmncNavFabmgmt::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool LstFabAlt
			, const bool LstFusAlt
			, const bool LstTtyAlt
			, const bool LstTolAlt
			, const bool LstFpjAlt
			, const bool LstBilAlt
			, const uint LstFabNumFirstdisp
			, const uint LstFusNumFirstdisp
			, const uint LstTtyNumFirstdisp
			, const uint LstTolNumFirstdisp
			, const uint LstFpjNumFirstdisp
			, const uint LstBilNumFirstdisp
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->LstFabAlt = LstFabAlt;
	this->LstFusAlt = LstFusAlt;
	this->LstTtyAlt = LstTtyAlt;
	this->LstTolAlt = LstTolAlt;
	this->LstFpjAlt = LstFpjAlt;
	this->LstBilAlt = LstBilAlt;
	this->LstFabNumFirstdisp = LstFabNumFirstdisp;
	this->LstFusNumFirstdisp = LstFusNumFirstdisp;
	this->LstTtyNumFirstdisp = LstTtyNumFirstdisp;
	this->LstTolNumFirstdisp = LstTolNumFirstdisp;
	this->LstFpjNumFirstdisp = LstFpjNumFirstdisp;
	this->LstBilNumFirstdisp = LstBilNumFirstdisp;

	mask = {IXFMNCVEXPSTATE, LSTFABALT, LSTFUSALT, LSTTTYALT, LSTTOLALT, LSTFPJALT, LSTBILALT, LSTFABNUMFIRSTDISP, LSTFUSNUMFIRSTDISP, LSTTTYNUMFIRSTDISP, LSTTOLNUMFIRSTDISP, LSTFPJNUMFIRSTDISP, LSTBILNUMFIRSTDISP};
};

bool PnlFmncNavFabmgmt::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncNavFabmgmt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncNavFabmgmt";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFabAlt", LstFabAlt)) add(LSTFABALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFusAlt", LstFusAlt)) add(LSTFUSALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTtyAlt", LstTtyAlt)) add(LSTTTYALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTolAlt", LstTolAlt)) add(LSTTOLALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFpjAlt", LstFpjAlt)) add(LSTFPJALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBilAlt", LstBilAlt)) add(LSTBILALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFabNumFirstdisp", LstFabNumFirstdisp)) add(LSTFABNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFusNumFirstdisp", LstFusNumFirstdisp)) add(LSTFUSNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTtyNumFirstdisp", LstTtyNumFirstdisp)) add(LSTTTYNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTolNumFirstdisp", LstTolNumFirstdisp)) add(LSTTOLNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFpjNumFirstdisp", LstFpjNumFirstdisp)) add(LSTFPJNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBilNumFirstdisp", LstBilNumFirstdisp)) add(LSTBILNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlFmncNavFabmgmt::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (LstFabAlt == comp->LstFabAlt) insert(items, LSTFABALT);
	if (LstFusAlt == comp->LstFusAlt) insert(items, LSTFUSALT);
	if (LstTtyAlt == comp->LstTtyAlt) insert(items, LSTTTYALT);
	if (LstTolAlt == comp->LstTolAlt) insert(items, LSTTOLALT);
	if (LstFpjAlt == comp->LstFpjAlt) insert(items, LSTFPJALT);
	if (LstBilAlt == comp->LstBilAlt) insert(items, LSTBILALT);
	if (LstFabNumFirstdisp == comp->LstFabNumFirstdisp) insert(items, LSTFABNUMFIRSTDISP);
	if (LstFusNumFirstdisp == comp->LstFusNumFirstdisp) insert(items, LSTFUSNUMFIRSTDISP);
	if (LstTtyNumFirstdisp == comp->LstTtyNumFirstdisp) insert(items, LSTTTYNUMFIRSTDISP);
	if (LstTolNumFirstdisp == comp->LstTolNumFirstdisp) insert(items, LSTTOLNUMFIRSTDISP);
	if (LstFpjNumFirstdisp == comp->LstFpjNumFirstdisp) insert(items, LSTFPJNUMFIRSTDISP);
	if (LstBilNumFirstdisp == comp->LstBilNumFirstdisp) insert(items, LSTBILNUMFIRSTDISP);

	return(items);
};

set<uint> PnlFmncNavFabmgmt::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, LSTFABALT, LSTFUSALT, LSTTTYALT, LSTTOLALT, LSTFPJALT, LSTBILALT, LSTFABNUMFIRSTDISP, LSTFUSNUMFIRSTDISP, LSTTTYNUMFIRSTDISP, LSTTOLNUMFIRSTDISP, LSTFPJNUMFIRSTDISP, LSTBILNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::StatShr
 ******************************************************************************/

PnlFmncNavFabmgmt::StatShr::StatShr(
			const bool LstFabAvail
			, const bool ButFabViewActive
			, const bool LstFusAvail
			, const bool ButFusViewActive
			, const bool ButFusNewcrdActive
			, const bool LstTtyAvail
			, const bool ButTtyViewActive
			, const bool LstTolAvail
			, const bool ButTolViewActive
			, const bool ButTolNewcrdActive
			, const bool LstFpjAvail
			, const bool ButFpjViewActive
			, const bool ButFpjNewcrdActive
			, const bool LstBilAvail
			, const bool ButBilViewActive
			, const bool ButBilNewcrdActive
		) : Block() {
	this->LstFabAvail = LstFabAvail;
	this->ButFabViewActive = ButFabViewActive;
	this->LstFusAvail = LstFusAvail;
	this->ButFusViewActive = ButFusViewActive;
	this->ButFusNewcrdActive = ButFusNewcrdActive;
	this->LstTtyAvail = LstTtyAvail;
	this->ButTtyViewActive = ButTtyViewActive;
	this->LstTolAvail = LstTolAvail;
	this->ButTolViewActive = ButTolViewActive;
	this->ButTolNewcrdActive = ButTolNewcrdActive;
	this->LstFpjAvail = LstFpjAvail;
	this->ButFpjViewActive = ButFpjViewActive;
	this->ButFpjNewcrdActive = ButFpjNewcrdActive;
	this->LstBilAvail = LstBilAvail;
	this->ButBilViewActive = ButBilViewActive;
	this->ButBilNewcrdActive = ButBilNewcrdActive;

	mask = {LSTFABAVAIL, BUTFABVIEWACTIVE, LSTFUSAVAIL, BUTFUSVIEWACTIVE, BUTFUSNEWCRDACTIVE, LSTTTYAVAIL, BUTTTYVIEWACTIVE, LSTTOLAVAIL, BUTTOLVIEWACTIVE, BUTTOLNEWCRDACTIVE, LSTFPJAVAIL, BUTFPJVIEWACTIVE, BUTFPJNEWCRDACTIVE, LSTBILAVAIL, BUTBILVIEWACTIVE, BUTBILNEWCRDACTIVE};
};

bool PnlFmncNavFabmgmt::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncNavFabmgmt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncNavFabmgmt";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFabAvail", LstFabAvail)) add(LSTFABAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFabViewActive", ButFabViewActive)) add(BUTFABVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFusAvail", LstFusAvail)) add(LSTFUSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFusViewActive", ButFusViewActive)) add(BUTFUSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFusNewcrdActive", ButFusNewcrdActive)) add(BUTFUSNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTtyAvail", LstTtyAvail)) add(LSTTTYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTtyViewActive", ButTtyViewActive)) add(BUTTTYVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTolAvail", LstTolAvail)) add(LSTTOLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTolViewActive", ButTolViewActive)) add(BUTTOLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTolNewcrdActive", ButTolNewcrdActive)) add(BUTTOLNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFpjAvail", LstFpjAvail)) add(LSTFPJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFpjViewActive", ButFpjViewActive)) add(BUTFPJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFpjNewcrdActive", ButFpjNewcrdActive)) add(BUTFPJNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBilAvail", LstBilAvail)) add(LSTBILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBilViewActive", ButBilViewActive)) add(BUTBILVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBilNewcrdActive", ButBilNewcrdActive)) add(BUTBILNEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncNavFabmgmt::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstFabAvail == comp->LstFabAvail) insert(items, LSTFABAVAIL);
	if (ButFabViewActive == comp->ButFabViewActive) insert(items, BUTFABVIEWACTIVE);
	if (LstFusAvail == comp->LstFusAvail) insert(items, LSTFUSAVAIL);
	if (ButFusViewActive == comp->ButFusViewActive) insert(items, BUTFUSVIEWACTIVE);
	if (ButFusNewcrdActive == comp->ButFusNewcrdActive) insert(items, BUTFUSNEWCRDACTIVE);
	if (LstTtyAvail == comp->LstTtyAvail) insert(items, LSTTTYAVAIL);
	if (ButTtyViewActive == comp->ButTtyViewActive) insert(items, BUTTTYVIEWACTIVE);
	if (LstTolAvail == comp->LstTolAvail) insert(items, LSTTOLAVAIL);
	if (ButTolViewActive == comp->ButTolViewActive) insert(items, BUTTOLVIEWACTIVE);
	if (ButTolNewcrdActive == comp->ButTolNewcrdActive) insert(items, BUTTOLNEWCRDACTIVE);
	if (LstFpjAvail == comp->LstFpjAvail) insert(items, LSTFPJAVAIL);
	if (ButFpjViewActive == comp->ButFpjViewActive) insert(items, BUTFPJVIEWACTIVE);
	if (ButFpjNewcrdActive == comp->ButFpjNewcrdActive) insert(items, BUTFPJNEWCRDACTIVE);
	if (LstBilAvail == comp->LstBilAvail) insert(items, LSTBILAVAIL);
	if (ButBilViewActive == comp->ButBilViewActive) insert(items, BUTBILVIEWACTIVE);
	if (ButBilNewcrdActive == comp->ButBilNewcrdActive) insert(items, BUTBILNEWCRDACTIVE);

	return(items);
};

set<uint> PnlFmncNavFabmgmt::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTFABAVAIL, BUTFABVIEWACTIVE, LSTFUSAVAIL, BUTFUSVIEWACTIVE, BUTFUSNEWCRDACTIVE, LSTTTYAVAIL, BUTTTYVIEWACTIVE, LSTTOLAVAIL, BUTTOLVIEWACTIVE, BUTTOLNEWCRDACTIVE, LSTFPJAVAIL, BUTFPJVIEWACTIVE, BUTFPJNEWCRDACTIVE, LSTBILAVAIL, BUTBILVIEWACTIVE, BUTBILNEWCRDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::Tag
 ******************************************************************************/

PnlFmncNavFabmgmt::Tag::Tag(
			const string& Cpt
			, const string& CptFab
			, const string& CptFus
			, const string& CptTty
			, const string& CptTol
			, const string& CptFpj
			, const string& CptBil
		) : Block() {
	this->Cpt = Cpt;
	this->CptFab = CptFab;
	this->CptFus = CptFus;
	this->CptTty = CptTty;
	this->CptTol = CptTol;
	this->CptFpj = CptFpj;
	this->CptBil = CptBil;

	mask = {CPT, CPTFAB, CPTFUS, CPTTTY, CPTTOL, CPTFPJ, CPTBIL};
};

bool PnlFmncNavFabmgmt::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncNavFabmgmt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncNavFabmgmt";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFab", CptFab)) add(CPTFAB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFus", CptFus)) add(CPTFUS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTty", CptTty)) add(CPTTTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTol", CptTol)) add(CPTTOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFpj", CptFpj)) add(CPTFPJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBil", CptBil)) add(CPTBIL);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncNavFabmgmt::DpchAppData
 ******************************************************************************/

PnlFmncNavFabmgmt::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVFABMGMTDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncNavFabmgmt::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavFabmgmt::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncNavFabmgmtData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::DpchAppDo
 ******************************************************************************/

PnlFmncNavFabmgmt::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVFABMGMTDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncNavFabmgmt::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavFabmgmt::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncNavFabmgmtDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::DpchEngData
 ******************************************************************************/

PnlFmncNavFabmgmt::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVFABMGMTDATA) {
	feedFLstBil.tag = "FeedFLstBil";
	feedFLstFab.tag = "FeedFLstFab";
	feedFLstFpj.tag = "FeedFLstFpj";
	feedFLstFus.tag = "FeedFLstFus";
	feedFLstTol.tag = "FeedFLstTol";
	feedFLstTty.tag = "FeedFLstTty";
};

string PnlFmncNavFabmgmt::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTBIL)) ss.push_back("feedFLstBil");
	if (has(FEEDFLSTFAB)) ss.push_back("feedFLstFab");
	if (has(FEEDFLSTFPJ)) ss.push_back("feedFLstFpj");
	if (has(FEEDFLSTFUS)) ss.push_back("feedFLstFus");
	if (has(FEEDFLSTTOL)) ss.push_back("feedFLstTol");
	if (has(FEEDFLSTTTY)) ss.push_back("feedFLstTty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavFabmgmt::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncNavFabmgmtData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstBil.readXML(docctx, basexpath, true)) add(FEEDFLSTBIL);
		if (feedFLstFab.readXML(docctx, basexpath, true)) add(FEEDFLSTFAB);
		if (feedFLstFpj.readXML(docctx, basexpath, true)) add(FEEDFLSTFPJ);
		if (feedFLstFus.readXML(docctx, basexpath, true)) add(FEEDFLSTFUS);
		if (feedFLstTol.readXML(docctx, basexpath, true)) add(FEEDFLSTTOL);
		if (feedFLstTty.readXML(docctx, basexpath, true)) add(FEEDFLSTTTY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstBil.clear();
		feedFLstFab.clear();
		feedFLstFpj.clear();
		feedFLstFus.clear();
		feedFLstTol.clear();
		feedFLstTty.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

