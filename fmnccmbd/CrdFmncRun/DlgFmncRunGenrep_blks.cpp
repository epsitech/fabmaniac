/**
  * \file DlgFmncRunGenrep_blks.cpp
  * job handler for job DlgFmncRunGenrep (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class DlgFmncRunGenrep::VecVDit
 ******************************************************************************/

uint DlgFmncRunGenrep::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "opt") return OPT;
	else if (s == "sto") return STO;
	else if (s == "gen") return GEN;
	else if (s == "fia") return FIA;

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

string DlgFmncRunGenrep::VecVDit::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == OPT) return("Options");
		else if (ix == STO) return("Step options");
		else if (ix == GEN) return("Generation");
		else if (ix == FIA) return("File archive");
	} else if (ixFmncVLocale == 2) {
		if (ix == OPT) return("Optionen");
		else if (ix == STO) return("Schritt-Optionen");
		else if (ix == GEN) return("Erstellung");
		else if (ix == FIA) return("Dateiarchiv");
	} else if (ixFmncVLocale == 3) {
		if (ix == OPT) return("Options");
		else if (ix == STO) return("Options d'\\u00e9tapes");
		else if (ix == GEN) return("G\\u00e9n\\u00e9ration");
		else if (ix == FIA) return("Archive");
	};

	return("");
};

void DlgFmncRunGenrep::VecVDit::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

/******************************************************************************
 class DlgFmncRunGenrep::VecVDo
 ******************************************************************************/

uint DlgFmncRunGenrep::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

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

	if (s == "butrunclick") return BUTRUNCLICK;
	else if (s == "butstoclick") return BUTSTOCLICK;

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

	if (s == "idle") return IDLE;
	else if (s == "prpidle") return PRPIDLE;
	else if (s == "prepare") return PREPARE;
	else if (s == "typeset") return TYPESET;
	else if (s == "pack") return PACK;
	else if (s == "done") return DONE;

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

void DlgFmncRunGenrep::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=6;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void DlgFmncRunGenrep::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgFmncRunGenrep";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgFmncRunGenrep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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

void DlgFmncRunGenrep::ContInfGen::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgFmncRunGenrepGen";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgFmncRunGenrepGen";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncRunGenrep::ContInfGen::comm(
			const ContInfGen* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

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

void DlgFmncRunGenrep::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgFmncRunGenrep";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgFmncRunGenrep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::StatAppOpt
 ******************************************************************************/

void DlgFmncRunGenrep::StatAppOpt::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint LstSpaNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgFmncRunGenrepOpt";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgFmncRunGenrepOpt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "LstSpaNumFirstdisp", LstSpaNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::StatAppSto
 ******************************************************************************/

void DlgFmncRunGenrep::StatAppSto::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint LstImfNumFirstdisp
			, const uint LstParNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgFmncRunGenrepSto";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgFmncRunGenrepSto";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "LstImfNumFirstdisp", LstImfNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstParNumFirstdisp", LstParNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void DlgFmncRunGenrep::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgFmncRunGenrep";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgFmncRunGenrep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
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

void DlgFmncRunGenrep::StatShrGen::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgFmncRunGenrepGen";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgFmncRunGenrepGen";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
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

void DlgFmncRunGenrep::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgFmncRunGenrep";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgFmncRunGenrep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Generate report");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Bericht erstellen");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "G\\u00e9n\\u00e9rer rapport");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DONE, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::TagFia
 ******************************************************************************/

void DlgFmncRunGenrep::TagFia::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgFmncRunGenrepFia";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgFmncRunGenrepFia";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DOWNLOAD, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::TagGen
 ******************************************************************************/

void DlgFmncRunGenrep::TagGen::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgFmncRunGenrepGen";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgFmncRunGenrepGen";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::PROGRESS, ixFmncVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::RUN, ixFmncVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::STOP, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::TagOpt
 ******************************************************************************/

void DlgFmncRunGenrep::TagOpt::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgFmncRunGenrepOpt";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgFmncRunGenrepOpt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptHis", "History");
			writeStringAttr(wr, itemtag, "sref", "CptSsu", "Step summary");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "Fabs");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "Persons");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Files");
			writeStringAttr(wr, itemtag, "sref", "CptSmp", "Samples");
			writeStringAttr(wr, itemtag, "sref", "CptSpa", "Sample parameters");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptHis", "Verlauf");
			writeStringAttr(wr, itemtag, "sref", "CptSsu", "Schritt-\\u00dcbersicht");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "Reinr\\u00e4ume");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "Personen");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Dateien");
			writeStringAttr(wr, itemtag, "sref", "CptSmp", "Samples");
			writeStringAttr(wr, itemtag, "sref", "CptSpa", "Sample-Parameter");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptHis", "Historique");
			writeStringAttr(wr, itemtag, "sref", "CptSsu", "Aper\\u00e7u d'\\u00e9tapes");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "Salles blanches");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "Individus");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Fichiers");
			writeStringAttr(wr, itemtag, "sref", "CptSmp", "\\u00c9chantillons");
			writeStringAttr(wr, itemtag, "sref", "CptSpa", "Param\\u00e8tres d'\\u00e9chantillons");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::TagSto
 ******************************************************************************/

void DlgFmncRunGenrep::TagSto::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgFmncRunGenrepSto";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgFmncRunGenrepSto";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptDet", "Details");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Files");
			writeStringAttr(wr, itemtag, "sref", "CptImf", "Image files");
			writeStringAttr(wr, itemtag, "sref", "CptPar", "Parameters");
			writeStringAttr(wr, itemtag, "sref", "CptCpa", "Common parameters");
			writeStringAttr(wr, itemtag, "sref", "CptFsp", "File-specific parameters");
			writeStringAttr(wr, itemtag, "sref", "CptSsp", "Sample-specific parameters");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptDet", "Details");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Dateien");
			writeStringAttr(wr, itemtag, "sref", "CptImf", "Bilddateien");
			writeStringAttr(wr, itemtag, "sref", "CptPar", "Parameter");
			writeStringAttr(wr, itemtag, "sref", "CptCpa", "Gemeinsame Parameter");
			writeStringAttr(wr, itemtag, "sref", "CptFsp", "Datei-spezifische Parameter");
			writeStringAttr(wr, itemtag, "sref", "CptSsp", "Sample-spezifische Parameter");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptDet", "D\\u00e9tails");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Fichiers");
			writeStringAttr(wr, itemtag, "sref", "CptImf", "Fichiers d'images");
			writeStringAttr(wr, itemtag, "sref", "CptPar", "Param\\u00e8tres");
			writeStringAttr(wr, itemtag, "sref", "CptCpa", "Param\\u00e8tres communs");
			writeStringAttr(wr, itemtag, "sref", "CptFsp", "Param\\u00e8tres par fichier");
			writeStringAttr(wr, itemtag, "sref", "CptSsp", "Param\\u00e8tres par \\u00e9chantillon");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncRunGenrep::DpchAppData
 ******************************************************************************/

DlgFmncRunGenrep::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPDLGFMNCRUNGENREPDATA) {
};

string DlgFmncRunGenrep::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACOPT)) ss.push_back("contiacopt");
	if (has(CONTIACSTO)) ss.push_back("contiacsto");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncRunGenrep::DpchAppData::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgFmncRunGenrepData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacopt.readXML(docctx, basexpath, true)) add(CONTIACOPT);
		if (contiacsto.readXML(docctx, basexpath, true)) add(CONTIACSTO);
	} else {
		contiac = ContIac();
		contiacopt = ContIacOpt();
		contiacsto = ContIacSto();
	};
};

/******************************************************************************
 class DlgFmncRunGenrep::DpchAppDo
 ******************************************************************************/

DlgFmncRunGenrep::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPDLGFMNCRUNGENREPDO) {
	ixVDo = 0;
	ixVDoGen = 0;
};

string DlgFmncRunGenrep::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOGEN)) ss.push_back("ixVDoGen");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncRunGenrep::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoGen;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgFmncRunGenrepDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoGen", "", srefIxVDoGen)) {
			ixVDoGen = VecVDoGen::getIx(srefIxVDoGen);
			add(IXVDOGEN);
		};
	} else {
	};
};

/******************************************************************************
 class DlgFmncRunGenrep::DpchEngData
 ******************************************************************************/

DlgFmncRunGenrep::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacOpt* contiacopt
			, ContIacSto* contiacsto
			, ContInf* continf
			, ContInfGen* continfgen
			, Feed* feedFDse
			, Feed* feedFOptLstSpa
			, Feed* feedFOptRbuFab
			, Feed* feedFOptRbuFil
			, Feed* feedFOptRbuHis
			, Feed* feedFOptRbuPrs
			, Feed* feedFOptRbuSmp
			, Feed* feedFSge
			, Feed* feedFStoLstImf
			, Feed* feedFStoLstPar
			, Feed* feedFStoRbuCpa
			, Feed* feedFStoRbuFil
			, Feed* feedFStoRbuFsp
			, Feed* feedFStoRbuSsp
			, StatShr* statshr
			, StatShrGen* statshrgen
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGDLGFMNCRUNGENREPDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACOPT, CONTIACSTO, CONTINF, CONTINFGEN, FEEDFDSE, FEEDFOPTLSTSPA, FEEDFOPTRBUFAB, FEEDFOPTRBUFIL, FEEDFOPTRBUHIS, FEEDFOPTRBUPRS, FEEDFOPTRBUSMP, FEEDFSGE, FEEDFSTOLSTIMF, FEEDFSTOLSTPAR, FEEDFSTORBUCPA, FEEDFSTORBUFIL, FEEDFSTORBUFSP, FEEDFSTORBUSSP, STATAPP, STATAPPOPT, STATAPPSTO, STATSHR, STATSHRGEN, TAG, TAGFIA, TAGGEN, TAGOPT, TAGSTO};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACOPT) && contiacopt) this->contiacopt = *contiacopt;
	if (find(this->mask, CONTIACSTO) && contiacsto) this->contiacsto = *contiacsto;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFGEN) && continfgen) this->continfgen = *continfgen;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFOPTLSTSPA) && feedFOptLstSpa) this->feedFOptLstSpa = *feedFOptLstSpa;
	if (find(this->mask, FEEDFOPTRBUFAB) && feedFOptRbuFab) this->feedFOptRbuFab = *feedFOptRbuFab;
	if (find(this->mask, FEEDFOPTRBUFIL) && feedFOptRbuFil) this->feedFOptRbuFil = *feedFOptRbuFil;
	if (find(this->mask, FEEDFOPTRBUHIS) && feedFOptRbuHis) this->feedFOptRbuHis = *feedFOptRbuHis;
	if (find(this->mask, FEEDFOPTRBUPRS) && feedFOptRbuPrs) this->feedFOptRbuPrs = *feedFOptRbuPrs;
	if (find(this->mask, FEEDFOPTRBUSMP) && feedFOptRbuSmp) this->feedFOptRbuSmp = *feedFOptRbuSmp;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, FEEDFSTOLSTIMF) && feedFStoLstImf) this->feedFStoLstImf = *feedFStoLstImf;
	if (find(this->mask, FEEDFSTOLSTPAR) && feedFStoLstPar) this->feedFStoLstPar = *feedFStoLstPar;
	if (find(this->mask, FEEDFSTORBUCPA) && feedFStoRbuCpa) this->feedFStoRbuCpa = *feedFStoRbuCpa;
	if (find(this->mask, FEEDFSTORBUFIL) && feedFStoRbuFil) this->feedFStoRbuFil = *feedFStoRbuFil;
	if (find(this->mask, FEEDFSTORBUFSP) && feedFStoRbuFsp) this->feedFStoRbuFsp = *feedFStoRbuFsp;
	if (find(this->mask, FEEDFSTORBUSSP) && feedFStoRbuSsp) this->feedFStoRbuSsp = *feedFStoRbuSsp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRGEN) && statshrgen) this->statshrgen = *statshrgen;
};

string DlgFmncRunGenrep::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void DlgFmncRunGenrep::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACOPT)) {contiacopt = src->contiacopt; add(CONTIACOPT);};
	if (src->has(CONTIACSTO)) {contiacsto = src->contiacsto; add(CONTIACSTO);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFGEN)) {continfgen = src->continfgen; add(CONTINFGEN);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFOPTLSTSPA)) {feedFOptLstSpa = src->feedFOptLstSpa; add(FEEDFOPTLSTSPA);};
	if (src->has(FEEDFOPTRBUFAB)) {feedFOptRbuFab = src->feedFOptRbuFab; add(FEEDFOPTRBUFAB);};
	if (src->has(FEEDFOPTRBUFIL)) {feedFOptRbuFil = src->feedFOptRbuFil; add(FEEDFOPTRBUFIL);};
	if (src->has(FEEDFOPTRBUHIS)) {feedFOptRbuHis = src->feedFOptRbuHis; add(FEEDFOPTRBUHIS);};
	if (src->has(FEEDFOPTRBUPRS)) {feedFOptRbuPrs = src->feedFOptRbuPrs; add(FEEDFOPTRBUPRS);};
	if (src->has(FEEDFOPTRBUSMP)) {feedFOptRbuSmp = src->feedFOptRbuSmp; add(FEEDFOPTRBUSMP);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(FEEDFSTOLSTIMF)) {feedFStoLstImf = src->feedFStoLstImf; add(FEEDFSTOLSTIMF);};
	if (src->has(FEEDFSTOLSTPAR)) {feedFStoLstPar = src->feedFStoLstPar; add(FEEDFSTOLSTPAR);};
	if (src->has(FEEDFSTORBUCPA)) {feedFStoRbuCpa = src->feedFStoRbuCpa; add(FEEDFSTORBUCPA);};
	if (src->has(FEEDFSTORBUFIL)) {feedFStoRbuFil = src->feedFStoRbuFil; add(FEEDFSTORBUFIL);};
	if (src->has(FEEDFSTORBUFSP)) {feedFStoRbuFsp = src->feedFStoRbuFsp; add(FEEDFSTORBUFSP);};
	if (src->has(FEEDFSTORBUSSP)) {feedFStoRbuSsp = src->feedFStoRbuSsp; add(FEEDFSTORBUSSP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATAPPOPT)) add(STATAPPOPT);
	if (src->has(STATAPPSTO)) add(STATAPPSTO);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRGEN)) {statshrgen = src->statshrgen; add(STATSHRGEN);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGFIA)) add(TAGFIA);
	if (src->has(TAGGEN)) add(TAGGEN);
	if (src->has(TAGOPT)) add(TAGOPT);
	if (src->has(TAGSTO)) add(TAGSTO);
};

void DlgFmncRunGenrep::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgFmncRunGenrepData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACOPT)) contiacopt.writeXML(wr);
		if (has(CONTIACSTO)) contiacsto.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFGEN)) continfgen.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFOPTLSTSPA)) feedFOptLstSpa.writeXML(wr);
		if (has(FEEDFOPTRBUFAB)) feedFOptRbuFab.writeXML(wr);
		if (has(FEEDFOPTRBUFIL)) feedFOptRbuFil.writeXML(wr);
		if (has(FEEDFOPTRBUHIS)) feedFOptRbuHis.writeXML(wr);
		if (has(FEEDFOPTRBUPRS)) feedFOptRbuPrs.writeXML(wr);
		if (has(FEEDFOPTRBUSMP)) feedFOptRbuSmp.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(FEEDFSTOLSTIMF)) feedFStoLstImf.writeXML(wr);
		if (has(FEEDFSTOLSTPAR)) feedFStoLstPar.writeXML(wr);
		if (has(FEEDFSTORBUCPA)) feedFStoRbuCpa.writeXML(wr);
		if (has(FEEDFSTORBUFIL)) feedFStoRbuFil.writeXML(wr);
		if (has(FEEDFSTORBUFSP)) feedFStoRbuFsp.writeXML(wr);
		if (has(FEEDFSTORBUSSP)) feedFStoRbuSsp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATAPPOPT)) StatAppOpt::writeXML(wr);
		if (has(STATAPPSTO)) StatAppSto::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRGEN)) statshrgen.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
		if (has(TAGFIA)) TagFia::writeXML(ixFmncVLocale, wr);
		if (has(TAGGEN)) TagGen::writeXML(ixFmncVLocale, wr);
		if (has(TAGOPT)) TagOpt::writeXML(ixFmncVLocale, wr);
		if (has(TAGSTO)) TagSto::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


