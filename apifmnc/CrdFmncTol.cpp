/**
  * \file CrdFmncTol.cpp
  * API code for job CrdFmncTol (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "CrdFmncTol.h"

/******************************************************************************
 class CrdFmncTol::VecVDo
 ******************************************************************************/

uint CrdFmncTol::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("close") == 0) return CLOSE;
	else if (s.compare("mitappabtclick") == 0) return MITAPPABTCLICK;

	return(0);
};

string CrdFmncTol::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdFmncTol::VecVSge
 ******************************************************************************/

uint CrdFmncTol::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("idle") == 0) return IDLE;
	else if (s.compare("alrfmncabt") == 0) return ALRFMNCABT;
	else if (s.compare("close") == 0) return CLOSE;

	return(0);
};

string CrdFmncTol::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRFMNCABT) return("alrfmncabt");
	else if (ix == CLOSE) return("close");

	return("");
};

/******************************************************************************
 class CrdFmncTol::ContInf
 ******************************************************************************/

CrdFmncTol::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdTol
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdTol = MtxCrdTol;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDTOL};
};

bool CrdFmncTol::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncTol");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncTol";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdTol", MtxCrdTol)) add(MTXCRDTOL);
	};

	return basefound;
};

set<uint> CrdFmncTol::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp.compare(comp->MrlAppHlp) == 0) insert(items, MRLAPPHLP);
	if (MtxCrdTol.compare(comp->MtxCrdTol) == 0) insert(items, MTXCRDTOL);

	return(items);
};

set<uint> CrdFmncTol::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDTOL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdFmncTol::StatApp
 ******************************************************************************/

CrdFmncTol::StatApp::StatApp(
			const uint ixFmncVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) : Block() {
	this->ixFmncVReqitmode = ixFmncVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneList = initdoneList;
	this->initdoneRec = initdoneRec;

	mask = {IXFMNCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdFmncTol::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncTol");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncTol";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVReqitmode", srefIxFmncVReqitmode)) {
			ixFmncVReqitmode = VecFmncVReqitmode::getIx(srefIxFmncVReqitmode);
			add(IXFMNCVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneList", initdoneList)) add(INITDONELIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRec", initdoneRec)) add(INITDONEREC);
	};

	return basefound;
};

set<uint> CrdFmncTol::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVReqitmode == comp->ixFmncVReqitmode) insert(items, IXFMNCVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu.compare(comp->shortMenu) == 0) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneList == comp->initdoneList) insert(items, INITDONELIST);
	if (initdoneRec == comp->initdoneRec) insert(items, INITDONEREC);

	return(items);
};

set<uint> CrdFmncTol::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdFmncTol::StatShr
 ******************************************************************************/

CrdFmncTol::StatShr::StatShr(
			const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
		) : Block() {
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;

	mask = {SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC};
};

bool CrdFmncTol::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncTol");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncTol";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
	};

	return basefound;
};

set<uint> CrdFmncTol::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefHeadbar.compare(comp->scrJrefHeadbar) == 0) insert(items, SCRJREFHEADBAR);
	if (scrJrefList.compare(comp->scrJrefList) == 0) insert(items, SCRJREFLIST);
	if (scrJrefRec.compare(comp->scrJrefRec) == 0) insert(items, SCRJREFREC);

	return(items);
};

set<uint> CrdFmncTol::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdFmncTol::Tag
 ******************************************************************************/

CrdFmncTol::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
		) : Block() {
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;

	mask = {MITAPPABT, MRLAPPHLP};
};

bool CrdFmncTol::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncTol");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncTol";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

/******************************************************************************
 class CrdFmncTol::DpchAppDo
 ******************************************************************************/

CrdFmncTol::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCTOLDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdFmncTol::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdFmncTol::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncTolDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdFmncTol::DpchEngData
 ******************************************************************************/

CrdFmncTol::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCTOLDATA) {
	feedFSge.tag = "FeedFSge";
};

string CrdFmncTol::DpchEngData::getSrefsMask() {
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

void CrdFmncTol::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncTolData");
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

