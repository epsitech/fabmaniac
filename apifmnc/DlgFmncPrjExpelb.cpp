/**
  * \file DlgFmncPrjExpelb.cpp
  * API code for job DlgFmncPrjExpelb (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "DlgFmncPrjExpelb.h"

/******************************************************************************
 class DlgFmncPrjExpelb::VecVDit
 ******************************************************************************/

uint DlgFmncPrjExpelb::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("prp") == 0) return PRP;
	else if (s.compare("fia") == 0) return FIA;

	return(0);
};

string DlgFmncPrjExpelb::VecVDit::getSref(
			const uint ix
		) {
	if (ix == PRP) return("Prp");
	else if (ix == FIA) return("Fia");

	return("");
};

/******************************************************************************
 class DlgFmncPrjExpelb::VecVDo
 ******************************************************************************/

uint DlgFmncPrjExpelb::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butdneclick") == 0) return BUTDNECLICK;

	return(0);
};

string DlgFmncPrjExpelb::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgFmncPrjExpelb::VecVDoPrp
 ******************************************************************************/

uint DlgFmncPrjExpelb::VecVDoPrp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butrunclick") == 0) return BUTRUNCLICK;
	else if (s.compare("butstoclick") == 0) return BUTSTOCLICK;

	return(0);
};

string DlgFmncPrjExpelb::VecVDoPrp::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgFmncPrjExpelb::VecVSge
 ******************************************************************************/

uint DlgFmncPrjExpelb::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("colidle") == 0) return COLIDLE;
	else if (s.compare("collect") == 0) return COLLECT;
	else if (s.compare("export") == 0) return EXPORT;
	else if (s.compare("pack") == 0) return PACK;
	else if (s.compare("done") == 0) return DONE;

	return(0);
};

string DlgFmncPrjExpelb::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == COLIDLE) return("colidle");
	else if (ix == COLLECT) return("collect");
	else if (ix == EXPORT) return("export");
	else if (ix == PACK) return("pack");
	else if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgFmncPrjExpelb::ContIac
 ******************************************************************************/

DlgFmncPrjExpelb::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgFmncPrjExpelb::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgFmncPrjExpelb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgFmncPrjExpelb";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgFmncPrjExpelb::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgFmncPrjExpelb";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgFmncPrjExpelb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncPrjExpelb::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgFmncPrjExpelb::ContIac::diff(
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
 class DlgFmncPrjExpelb::ContInf
 ******************************************************************************/

DlgFmncPrjExpelb::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgFmncPrjExpelb::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgFmncPrjExpelb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgFmncPrjExpelb";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgFmncPrjExpelb::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgFmncPrjExpelb::ContInf::diff(
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
 class DlgFmncPrjExpelb::ContInfPrp
 ******************************************************************************/

DlgFmncPrjExpelb::ContInfPrp::ContInfPrp(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgFmncPrjExpelb::ContInfPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgFmncPrjExpelbPrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgFmncPrjExpelbPrp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgFmncPrjExpelb::ContInfPrp::comm(
			const ContInfPrp* comp
		) {
	set<uint> items;

	if (TxtPrg.compare(comp->TxtPrg) == 0) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgFmncPrjExpelb::ContInfPrp::diff(
			const ContInfPrp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncPrjExpelb::StatApp
 ******************************************************************************/

DlgFmncPrjExpelb::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) : Block() {
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgFmncPrjExpelb::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgFmncPrjExpelb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgFmncPrjExpelb";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgFmncPrjExpelb::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgFmncPrjExpelb::StatApp::diff(
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
 class DlgFmncPrjExpelb::StatShr
 ******************************************************************************/

DlgFmncPrjExpelb::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgFmncPrjExpelb::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgFmncPrjExpelb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgFmncPrjExpelb";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgFmncPrjExpelb::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgFmncPrjExpelb::StatShr::diff(
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
 class DlgFmncPrjExpelb::StatShrFia
 ******************************************************************************/

DlgFmncPrjExpelb::StatShrFia::StatShrFia(
			const bool DldActive
		) : Block() {
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgFmncPrjExpelb::StatShrFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgFmncPrjExpelbFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgFmncPrjExpelbFia";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgFmncPrjExpelb::StatShrFia::comm(
			const StatShrFia* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgFmncPrjExpelb::StatShrFia::diff(
			const StatShrFia* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncPrjExpelb::StatShrPrp
 ******************************************************************************/

DlgFmncPrjExpelb::StatShrPrp::StatShrPrp(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgFmncPrjExpelb::StatShrPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgFmncPrjExpelbPrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgFmncPrjExpelbPrp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgFmncPrjExpelb::StatShrPrp::comm(
			const StatShrPrp* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgFmncPrjExpelb::StatShrPrp::diff(
			const StatShrPrp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncPrjExpelb::Tag
 ******************************************************************************/

DlgFmncPrjExpelb::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) : Block() {
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgFmncPrjExpelb::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgFmncPrjExpelb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgFmncPrjExpelb";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgFmncPrjExpelb::TagFia
 ******************************************************************************/

DlgFmncPrjExpelb::TagFia::TagFia(
			const string& Dld
		) : Block() {
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgFmncPrjExpelb::TagFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgFmncPrjExpelbFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgFmncPrjExpelbFia";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgFmncPrjExpelb::TagPrp
 ******************************************************************************/

DlgFmncPrjExpelb::TagPrp::TagPrp(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) : Block() {
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgFmncPrjExpelb::TagPrp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgFmncPrjExpelbPrp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgFmncPrjExpelbPrp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgFmncPrjExpelb::DpchAppData
 ******************************************************************************/

DlgFmncPrjExpelb::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPDLGFMNCPRJEXPELBDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgFmncPrjExpelb::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncPrjExpelb::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgFmncPrjExpelbData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncPrjExpelb::DpchAppDo
 ******************************************************************************/

DlgFmncPrjExpelb::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoPrp
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPDLGFMNCPRJEXPELBDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOPRP};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoPrp = ixVDoPrp;
};

string DlgFmncPrjExpelb::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOPRP)) ss.push_back("ixVDoPrp");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncPrjExpelb::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgFmncPrjExpelbDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOPRP)) writeString(wr, "srefIxVDoPrp", VecVDoPrp::getSref(ixVDoPrp));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncPrjExpelb::DpchEngData
 ******************************************************************************/

DlgFmncPrjExpelb::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGDLGFMNCPRJEXPELBDATA) {
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgFmncPrjExpelb::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFPRP)) ss.push_back("continfprp");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRFIA)) ss.push_back("statshrfia");
	if (has(STATSHRPRP)) ss.push_back("statshrprp");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGFIA)) ss.push_back("tagfia");
	if (has(TAGPRP)) ss.push_back("tagprp");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncPrjExpelb::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgFmncPrjExpelbData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfprp.readXML(docctx, basexpath, true)) add(CONTINFPRP);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrfia.readXML(docctx, basexpath, true)) add(STATSHRFIA);
		if (statshrprp.readXML(docctx, basexpath, true)) add(STATSHRPRP);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagfia.readXML(docctx, basexpath, true)) add(TAGFIA);
		if (tagprp.readXML(docctx, basexpath, true)) add(TAGPRP);
	} else {
		contiac = ContIac();
		continf = ContInf();
		continfprp = ContInfPrp();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrfia = StatShrFia();
		statshrprp = StatShrPrp();
		tag = Tag();
		tagfia = TagFia();
		tagprp = TagPrp();
	};
};

