/**
  * \file DlgFmncRunGenrep.cpp
  * API code for job DlgFmncRunGenrep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "DlgFmncRunGenrep.h"

/******************************************************************************
 class DlgFmncRunGenrep::VecVDit
 ******************************************************************************/

uint DlgFmncRunGenrep::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("opt") == 0) return OPT;
	else if (s.compare("sto") == 0) return STO;
	else if (s.compare("gen") == 0) return GEN;
	else if (s.compare("fia") == 0) return FIA;

	return(0);
};

string DlgFmncRunGenrep::VecVDit::getSref(
			const uint ix
		) {
	if (ix == OPT) return("Opt");
	else if (ix == STO) return("Sto");
	else if (ix == GEN) return("Gen");
	else if (ix == FIA) return("Fia");

	return("");
};

/******************************************************************************
 class DlgFmncRunGenrep::VecVDo
 ******************************************************************************/

uint DlgFmncRunGenrep::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdneclick") == 0) return BUTDNECLICK;

	return(0);
};

string DlgFmncRunGenrep::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgFmncRunGenrep::VecVDoGen
 ******************************************************************************/

uint DlgFmncRunGenrep::VecVDoGen::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butrunclick") == 0) return BUTRUNCLICK;
	else if (s.compare("butstoclick") == 0) return BUTSTOCLICK;

	return(0);
};

string DlgFmncRunGenrep::VecVDoGen::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgFmncRunGenrep::VecVSge
 ******************************************************************************/

uint DlgFmncRunGenrep::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("prpidle") == 0) return PRPIDLE;
	else if (s.compare("prepare") == 0) return PREPARE;
	else if (s.compare("typeset") == 0) return TYPESET;
	else if (s.compare("pack") == 0) return PACK;
	else if (s.compare("done") == 0) return DONE;

	return(0);
};

string DlgFmncRunGenrep::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == PRPIDLE) return("prpidle");
	else if (ix == PREPARE) return("prepare");
	else if (ix == TYPESET) return("typeset");
	else if (ix == PACK) return("pack");
	else if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgFmncRunGenrep::ContIac
 ******************************************************************************/

DlgFmncRunGenrep::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgFmncRunGenrep::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgFmncRunGenrep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgFmncRunGenrep";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgFmncRunGenrep::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgFmncRunGenrep";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgFmncRunGenrep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncRunGenrep::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgFmncRunGenrep::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDSE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::ContIacOpt
 ******************************************************************************/

DlgFmncRunGenrep::ContIacOpt::ContIacOpt(
			const uint numFRbuHis
			, const bool ChkSsu
			, const uint numFRbuFab
			, const uint numFRbuPrs
			, const uint numFRbuFil
			, const uint numFRbuSmp
			, const uint numFLstSpa
		) : Block() {
	this->numFRbuHis = numFRbuHis;
	this->ChkSsu = ChkSsu;
	this->numFRbuFab = numFRbuFab;
	this->numFRbuPrs = numFRbuPrs;
	this->numFRbuFil = numFRbuFil;
	this->numFRbuSmp = numFRbuSmp;
	this->numFLstSpa = numFLstSpa;

	mask = {NUMFRBUHIS, CHKSSU, NUMFRBUFAB, NUMFRBUPRS, NUMFRBUFIL, NUMFRBUSMP, NUMFLSTSPA};
};

bool DlgFmncRunGenrep::ContIacOpt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgFmncRunGenrepOpt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgFmncRunGenrepOpt";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuHis", numFRbuHis)) add(NUMFRBUHIS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkSsu", ChkSsu)) add(CHKSSU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuFab", numFRbuFab)) add(NUMFRBUFAB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuPrs", numFRbuPrs)) add(NUMFRBUPRS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuFil", numFRbuFil)) add(NUMFRBUFIL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuSmp", numFRbuSmp)) add(NUMFRBUSMP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSpa", numFLstSpa)) add(NUMFLSTSPA);
	};

	return basefound;
};

void DlgFmncRunGenrep::ContIacOpt::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgFmncRunGenrepOpt";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgFmncRunGenrepOpt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFRbuHis", numFRbuHis);
		writeBoolAttr(wr, itemtag, "sref", "ChkSsu", ChkSsu);
		writeUintAttr(wr, itemtag, "sref", "numFRbuFab", numFRbuFab);
		writeUintAttr(wr, itemtag, "sref", "numFRbuPrs", numFRbuPrs);
		writeUintAttr(wr, itemtag, "sref", "numFRbuFil", numFRbuFil);
		writeUintAttr(wr, itemtag, "sref", "numFRbuSmp", numFRbuSmp);
		writeUintAttr(wr, itemtag, "sref", "numFLstSpa", numFLstSpa);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncRunGenrep::ContIacOpt::comm(
			const ContIacOpt* comp
		) {
	set<uint> items;

	if (numFRbuHis == comp->numFRbuHis) insert(items, NUMFRBUHIS);
	if (ChkSsu == comp->ChkSsu) insert(items, CHKSSU);
	if (numFRbuFab == comp->numFRbuFab) insert(items, NUMFRBUFAB);
	if (numFRbuPrs == comp->numFRbuPrs) insert(items, NUMFRBUPRS);
	if (numFRbuFil == comp->numFRbuFil) insert(items, NUMFRBUFIL);
	if (numFRbuSmp == comp->numFRbuSmp) insert(items, NUMFRBUSMP);
	if (numFLstSpa == comp->numFLstSpa) insert(items, NUMFLSTSPA);

	return(items);
};

set<uint> DlgFmncRunGenrep::ContIacOpt::diff(
			const ContIacOpt* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFRBUHIS, CHKSSU, NUMFRBUFAB, NUMFRBUPRS, NUMFRBUFIL, NUMFRBUSMP, NUMFLSTSPA};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::ContIacSto
 ******************************************************************************/

DlgFmncRunGenrep::ContIacSto::ContIacSto(
			const bool ChkDet
			, const uint numFRbuFil
			, const uint numFLstImf
			, const uint numFLstPar
			, const uint numFRbuCpa
			, const uint numFRbuFsp
			, const uint numFRbuSsp
		) : Block() {
	this->ChkDet = ChkDet;
	this->numFRbuFil = numFRbuFil;
	this->numFLstImf = numFLstImf;
	this->numFLstPar = numFLstPar;
	this->numFRbuCpa = numFRbuCpa;
	this->numFRbuFsp = numFRbuFsp;
	this->numFRbuSsp = numFRbuSsp;

	mask = {CHKDET, NUMFRBUFIL, NUMFLSTIMF, NUMFLSTPAR, NUMFRBUCPA, NUMFRBUFSP, NUMFRBUSSP};
};

bool DlgFmncRunGenrep::ContIacSto::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgFmncRunGenrepSto");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgFmncRunGenrepSto";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkDet", ChkDet)) add(CHKDET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuFil", numFRbuFil)) add(NUMFRBUFIL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstImf", numFLstImf)) add(NUMFLSTIMF);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPar", numFLstPar)) add(NUMFLSTPAR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuCpa", numFRbuCpa)) add(NUMFRBUCPA);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuFsp", numFRbuFsp)) add(NUMFRBUFSP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuSsp", numFRbuSsp)) add(NUMFRBUSSP);
	};

	return basefound;
};

void DlgFmncRunGenrep::ContIacSto::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgFmncRunGenrepSto";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgFmncRunGenrepSto";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ChkDet", ChkDet);
		writeUintAttr(wr, itemtag, "sref", "numFRbuFil", numFRbuFil);
		writeUintAttr(wr, itemtag, "sref", "numFLstImf", numFLstImf);
		writeUintAttr(wr, itemtag, "sref", "numFLstPar", numFLstPar);
		writeUintAttr(wr, itemtag, "sref", "numFRbuCpa", numFRbuCpa);
		writeUintAttr(wr, itemtag, "sref", "numFRbuFsp", numFRbuFsp);
		writeUintAttr(wr, itemtag, "sref", "numFRbuSsp", numFRbuSsp);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncRunGenrep::ContIacSto::comm(
			const ContIacSto* comp
		) {
	set<uint> items;

	if (ChkDet == comp->ChkDet) insert(items, CHKDET);
	if (numFRbuFil == comp->numFRbuFil) insert(items, NUMFRBUFIL);
	if (numFLstImf == comp->numFLstImf) insert(items, NUMFLSTIMF);
	if (numFLstPar == comp->numFLstPar) insert(items, NUMFLSTPAR);
	if (numFRbuCpa == comp->numFRbuCpa) insert(items, NUMFRBUCPA);
	if (numFRbuFsp == comp->numFRbuFsp) insert(items, NUMFRBUFSP);
	if (numFRbuSsp == comp->numFRbuSsp) insert(items, NUMFRBUSSP);

	return(items);
};

set<uint> DlgFmncRunGenrep::ContIacSto::diff(
			const ContIacSto* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {CHKDET, NUMFRBUFIL, NUMFLSTIMF, NUMFLSTPAR, NUMFRBUCPA, NUMFRBUFSP, NUMFRBUSSP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::ContInf
 ******************************************************************************/

DlgFmncRunGenrep::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgFmncRunGenrep::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgFmncRunGenrep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgFmncRunGenrep";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgFmncRunGenrep::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgFmncRunGenrep::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::ContInfGen
 ******************************************************************************/

DlgFmncRunGenrep::ContInfGen::ContInfGen(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgFmncRunGenrep::ContInfGen::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgFmncRunGenrepGen");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgFmncRunGenrepGen";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgFmncRunGenrep::ContInfGen::comm(
			const ContInfGen* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgFmncRunGenrep::ContInfGen::diff(
			const ContInfGen* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::StatApp
 ******************************************************************************/

DlgFmncRunGenrep::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) : Block() {
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgFmncRunGenrep::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgFmncRunGenrep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgFmncRunGenrep";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgFmncRunGenrep::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgFmncRunGenrep::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONE, SHORTMENU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::StatAppOpt
 ******************************************************************************/

DlgFmncRunGenrep::StatAppOpt::StatAppOpt(
			const uint LstSpaNumFirstdisp
		) : Block() {
	this->LstSpaNumFirstdisp = LstSpaNumFirstdisp;

	mask = {LSTSPANUMFIRSTDISP};
};

bool DlgFmncRunGenrep::StatAppOpt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgFmncRunGenrepOpt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgFmncRunGenrepOpt";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSpaNumFirstdisp", LstSpaNumFirstdisp)) add(LSTSPANUMFIRSTDISP);
	};

	return basefound;
};

set<uint> DlgFmncRunGenrep::StatAppOpt::comm(
			const StatAppOpt* comp
		) {
	set<uint> items;

	if (LstSpaNumFirstdisp == comp->LstSpaNumFirstdisp) insert(items, LSTSPANUMFIRSTDISP);

	return(items);
};

set<uint> DlgFmncRunGenrep::StatAppOpt::diff(
			const StatAppOpt* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTSPANUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::StatAppSto
 ******************************************************************************/

DlgFmncRunGenrep::StatAppSto::StatAppSto(
			const uint LstImfNumFirstdisp
			, const uint LstParNumFirstdisp
		) : Block() {
	this->LstImfNumFirstdisp = LstImfNumFirstdisp;
	this->LstParNumFirstdisp = LstParNumFirstdisp;

	mask = {LSTIMFNUMFIRSTDISP, LSTPARNUMFIRSTDISP};
};

bool DlgFmncRunGenrep::StatAppSto::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgFmncRunGenrepSto");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgFmncRunGenrepSto";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstImfNumFirstdisp", LstImfNumFirstdisp)) add(LSTIMFNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstParNumFirstdisp", LstParNumFirstdisp)) add(LSTPARNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> DlgFmncRunGenrep::StatAppSto::comm(
			const StatAppSto* comp
		) {
	set<uint> items;

	if (LstImfNumFirstdisp == comp->LstImfNumFirstdisp) insert(items, LSTIMFNUMFIRSTDISP);
	if (LstParNumFirstdisp == comp->LstParNumFirstdisp) insert(items, LSTPARNUMFIRSTDISP);

	return(items);
};

set<uint> DlgFmncRunGenrep::StatAppSto::diff(
			const StatAppSto* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTIMFNUMFIRSTDISP, LSTPARNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::StatShr
 ******************************************************************************/

DlgFmncRunGenrep::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgFmncRunGenrep::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgFmncRunGenrep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgFmncRunGenrep";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgFmncRunGenrep::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgFmncRunGenrep::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDNEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::StatShrGen
 ******************************************************************************/

DlgFmncRunGenrep::StatShrGen::StatShrGen(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgFmncRunGenrep::StatShrGen::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgFmncRunGenrepGen");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgFmncRunGenrepGen";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgFmncRunGenrep::StatShrGen::comm(
			const StatShrGen* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgFmncRunGenrep::StatShrGen::diff(
			const StatShrGen* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncRunGenrep::Tag
 ******************************************************************************/

DlgFmncRunGenrep::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgFmncRunGenrep::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgFmncRunGenrep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgFmncRunGenrep";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgFmncRunGenrep::TagFia
 ******************************************************************************/

DlgFmncRunGenrep::TagFia::TagFia(
			const string& Dld
		) : Block() {
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgFmncRunGenrep::TagFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgFmncRunGenrepFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgFmncRunGenrepFia";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgFmncRunGenrep::TagGen
 ******************************************************************************/

DlgFmncRunGenrep::TagGen::TagGen(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgFmncRunGenrep::TagGen::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgFmncRunGenrepGen");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgFmncRunGenrepGen";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgFmncRunGenrep::TagOpt
 ******************************************************************************/

DlgFmncRunGenrep::TagOpt::TagOpt(
			const string& CptHis
			, const string& CptSsu
			, const string& CptFab
			, const string& CptPrs
			, const string& CptFil
			, const string& CptSmp
			, const string& CptSpa
		) : Block() {
	this->CptHis = CptHis;
	this->CptSsu = CptSsu;
	this->CptFab = CptFab;
	this->CptPrs = CptPrs;
	this->CptFil = CptFil;
	this->CptSmp = CptSmp;
	this->CptSpa = CptSpa;

	mask = {CPTHIS, CPTSSU, CPTFAB, CPTPRS, CPTFIL, CPTSMP, CPTSPA};
};

bool DlgFmncRunGenrep::TagOpt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgFmncRunGenrepOpt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgFmncRunGenrepOpt";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHis", CptHis)) add(CPTHIS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSsu", CptSsu)) add(CPTSSU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFab", CptFab)) add(CPTFAB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrs", CptPrs)) add(CPTPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSmp", CptSmp)) add(CPTSMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSpa", CptSpa)) add(CPTSPA);
	};

	return basefound;
};

/******************************************************************************
 class DlgFmncRunGenrep::TagSto
 ******************************************************************************/

DlgFmncRunGenrep::TagSto::TagSto(
			const string& CptDet
			, const string& CptFil
			, const string& CptImf
			, const string& CptPar
			, const string& CptCpa
			, const string& CptFsp
			, const string& CptSsp
		) : Block() {
	this->CptDet = CptDet;
	this->CptFil = CptFil;
	this->CptImf = CptImf;
	this->CptPar = CptPar;
	this->CptCpa = CptCpa;
	this->CptFsp = CptFsp;
	this->CptSsp = CptSsp;

	mask = {CPTDET, CPTFIL, CPTIMF, CPTPAR, CPTCPA, CPTFSP, CPTSSP};
};

bool DlgFmncRunGenrep::TagSto::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgFmncRunGenrepSto");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgFmncRunGenrepSto";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDet", CptDet)) add(CPTDET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImf", CptImf)) add(CPTIMF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPar", CptPar)) add(CPTPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCpa", CptCpa)) add(CPTCPA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFsp", CptFsp)) add(CPTFSP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSsp", CptSsp)) add(CPTSSP);
	};

	return basefound;
};

/******************************************************************************
 class DlgFmncRunGenrep::DpchAppData
 ******************************************************************************/

DlgFmncRunGenrep::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacOpt* contiacopt
			, ContIacSto* contiacsto
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPDLGFMNCRUNGENREPDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACOPT, CONTIACSTO};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACOPT) && contiacopt) this->contiacopt = *contiacopt;
		if (find(this->mask, CONTIACSTO) && contiacsto) this->contiacsto = *contiacsto;
};

string DlgFmncRunGenrep::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACOPT)) ss.push_back("contiacopt");
	if (has(CONTIACSTO)) ss.push_back("contiacsto");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncRunGenrep::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgFmncRunGenrepData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACOPT)) contiacopt.writeXML(wr);
		if (has(CONTIACSTO)) contiacsto.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::DpchAppDo
 ******************************************************************************/

DlgFmncRunGenrep::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoGen
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPDLGFMNCRUNGENREPDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOGEN};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoGen = ixVDoGen;
};

string DlgFmncRunGenrep::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOGEN)) ss.push_back("ixVDoGen");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncRunGenrep::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgFmncRunGenrepDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOGEN)) writeString(wr, "srefIxVDoGen", VecVDoGen::getSref(ixVDoGen));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::DpchEngData
 ******************************************************************************/

DlgFmncRunGenrep::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGDLGFMNCRUNGENREPDATA) {
	feedFDse.tag = "FeedFDse";
	feedFOptLstSpa.tag = "FeedFOptLstSpa";
	feedFOptRbuFab.tag = "FeedFOptRbuFab";
	feedFOptRbuFil.tag = "FeedFOptRbuFil";
	feedFOptRbuHis.tag = "FeedFOptRbuHis";
	feedFOptRbuPrs.tag = "FeedFOptRbuPrs";
	feedFOptRbuSmp.tag = "FeedFOptRbuSmp";
	feedFSge.tag = "FeedFSge";
	feedFStoLstImf.tag = "FeedFStoLstImf";
	feedFStoLstPar.tag = "FeedFStoLstPar";
	feedFStoRbuCpa.tag = "FeedFStoRbuCpa";
	feedFStoRbuFil.tag = "FeedFStoRbuFil";
	feedFStoRbuFsp.tag = "FeedFStoRbuFsp";
	feedFStoRbuSsp.tag = "FeedFStoRbuSsp";
};

string DlgFmncRunGenrep::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACOPT)) ss.push_back("contiacopt");
	if (has(CONTIACSTO)) ss.push_back("contiacsto");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFGEN)) ss.push_back("continfgen");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFOPTLSTSPA)) ss.push_back("feedFOptLstSpa");
	if (has(FEEDFOPTRBUFAB)) ss.push_back("feedFOptRbuFab");
	if (has(FEEDFOPTRBUFIL)) ss.push_back("feedFOptRbuFil");
	if (has(FEEDFOPTRBUHIS)) ss.push_back("feedFOptRbuHis");
	if (has(FEEDFOPTRBUPRS)) ss.push_back("feedFOptRbuPrs");
	if (has(FEEDFOPTRBUSMP)) ss.push_back("feedFOptRbuSmp");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(FEEDFSTOLSTIMF)) ss.push_back("feedFStoLstImf");
	if (has(FEEDFSTOLSTPAR)) ss.push_back("feedFStoLstPar");
	if (has(FEEDFSTORBUCPA)) ss.push_back("feedFStoRbuCpa");
	if (has(FEEDFSTORBUFIL)) ss.push_back("feedFStoRbuFil");
	if (has(FEEDFSTORBUFSP)) ss.push_back("feedFStoRbuFsp");
	if (has(FEEDFSTORBUSSP)) ss.push_back("feedFStoRbuSsp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATAPPOPT)) ss.push_back("statappopt");
	if (has(STATAPPSTO)) ss.push_back("statappsto");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRGEN)) ss.push_back("statshrgen");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGFIA)) ss.push_back("tagfia");
	if (has(TAGGEN)) ss.push_back("taggen");
	if (has(TAGOPT)) ss.push_back("tagopt");
	if (has(TAGSTO)) ss.push_back("tagsto");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncRunGenrep::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgFmncRunGenrepData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacopt.readXML(docctx, basexpath, true)) add(CONTIACOPT);
		if (contiacsto.readXML(docctx, basexpath, true)) add(CONTIACSTO);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfgen.readXML(docctx, basexpath, true)) add(CONTINFGEN);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFOptLstSpa.readXML(docctx, basexpath, true)) add(FEEDFOPTLSTSPA);
		if (feedFOptRbuFab.readXML(docctx, basexpath, true)) add(FEEDFOPTRBUFAB);
		if (feedFOptRbuFil.readXML(docctx, basexpath, true)) add(FEEDFOPTRBUFIL);
		if (feedFOptRbuHis.readXML(docctx, basexpath, true)) add(FEEDFOPTRBUHIS);
		if (feedFOptRbuPrs.readXML(docctx, basexpath, true)) add(FEEDFOPTRBUPRS);
		if (feedFOptRbuSmp.readXML(docctx, basexpath, true)) add(FEEDFOPTRBUSMP);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (feedFStoLstImf.readXML(docctx, basexpath, true)) add(FEEDFSTOLSTIMF);
		if (feedFStoLstPar.readXML(docctx, basexpath, true)) add(FEEDFSTOLSTPAR);
		if (feedFStoRbuCpa.readXML(docctx, basexpath, true)) add(FEEDFSTORBUCPA);
		if (feedFStoRbuFil.readXML(docctx, basexpath, true)) add(FEEDFSTORBUFIL);
		if (feedFStoRbuFsp.readXML(docctx, basexpath, true)) add(FEEDFSTORBUFSP);
		if (feedFStoRbuSsp.readXML(docctx, basexpath, true)) add(FEEDFSTORBUSSP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statappopt.readXML(docctx, basexpath, true)) add(STATAPPOPT);
		if (statappsto.readXML(docctx, basexpath, true)) add(STATAPPSTO);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrgen.readXML(docctx, basexpath, true)) add(STATSHRGEN);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagfia.readXML(docctx, basexpath, true)) add(TAGFIA);
		if (taggen.readXML(docctx, basexpath, true)) add(TAGGEN);
		if (tagopt.readXML(docctx, basexpath, true)) add(TAGOPT);
		if (tagsto.readXML(docctx, basexpath, true)) add(TAGSTO);
	} else {
		contiac = ContIac();
		contiacopt = ContIacOpt();
		contiacsto = ContIacSto();
		continf = ContInf();
		continfgen = ContInfGen();
		feedFDse.clear();
		feedFOptLstSpa.clear();
		feedFOptRbuFab.clear();
		feedFOptRbuFil.clear();
		feedFOptRbuHis.clear();
		feedFOptRbuPrs.clear();
		feedFOptRbuSmp.clear();
		feedFSge.clear();
		feedFStoLstImf.clear();
		feedFStoLstPar.clear();
		feedFStoRbuCpa.clear();
		feedFStoRbuFil.clear();
		feedFStoRbuFsp.clear();
		feedFStoRbuSsp.clear();
		statapp = StatApp();
		statappopt = StatAppOpt();
		statappsto = StatAppSto();
		statshr = StatShr();
		statshrgen = StatShrGen();
		tag = Tag();
		tagfia = TagFia();
		taggen = TagGen();
		tagopt = TagOpt();
		tagsto = TagSto();
	};
};

