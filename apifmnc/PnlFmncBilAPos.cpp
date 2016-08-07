/**
  * \file PnlFmncBilAPos.cpp
  * API code for job PnlFmncBilAPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncBilAPos.h"

/******************************************************************************
 class PnlFmncBilAPos::VecVDo
 ******************************************************************************/

uint PnlFmncBilAPos::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butupclick") == 0) return BUTUPCLICK;
	else if (s.compare("butdownclick") == 0) return BUTDOWNCLICK;
	else if (s.compare("butnewclick") == 0) return BUTNEWCLICK;
	else if (s.compare("butduplicateclick") == 0) return BUTDUPLICATECLICK;
	else if (s.compare("butdeleteclick") == 0) return BUTDELETECLICK;
	else if (s.compare("butrefreshclick") == 0) return BUTREFRESHCLICK;

	return(0);
};

string PnlFmncBilAPos::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUPCLICK) return("ButUpClick");
	else if (ix == BUTDOWNCLICK) return("ButDownClick");
	else if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlFmncBilAPos::ContInf
 ******************************************************************************/

PnlFmncBilAPos::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlFmncBilAPos::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncBilAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncBilAPos";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlFmncBilAPos::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlFmncBilAPos::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncBilAPos::StatApp
 ******************************************************************************/

PnlFmncBilAPos::StatApp::StatApp(
			const uint ixFmncVExpstate
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;

	mask = {IXFMNCVEXPSTATE};
};

bool PnlFmncBilAPos::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncBilAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncBilAPos";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlFmncBilAPos::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);

	return(items);
};

set<uint> PnlFmncBilAPos::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncBilAPos::StatShr
 ******************************************************************************/

PnlFmncBilAPos::StatShr::StatShr(
			const bool ButUpActive
			, const bool ButDownActive
			, const bool ButDuplicateActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButUpActive = ButUpActive;
	this->ButDownActive = ButDownActive;
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTUPACTIVE, BUTDOWNACTIVE, BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
};

bool PnlFmncBilAPos::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncBilAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncBilAPos";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUpActive", ButUpActive)) add(BUTUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDownActive", ButDownActive)) add(BUTDOWNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncBilAPos::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlFmncBilAPos::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUPACTIVE, BUTDOWNACTIVE, BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncBilAPos::StgIac
 ******************************************************************************/

PnlFmncBilAPos::StgIac::StgIac(
			const uint TcoFusWidth
			, const uint TcoTolWidth
			, const uint TcoQtyWidth
			, const uint TcoArtWidth
			, const uint TcoUprWidth
			, const uint TcoPrcWidth
		) : Block() {
	this->TcoFusWidth = TcoFusWidth;
	this->TcoTolWidth = TcoTolWidth;
	this->TcoQtyWidth = TcoQtyWidth;
	this->TcoArtWidth = TcoArtWidth;
	this->TcoUprWidth = TcoUprWidth;
	this->TcoPrcWidth = TcoPrcWidth;

	mask = {TCOFUSWIDTH, TCOTOLWIDTH, TCOQTYWIDTH, TCOARTWIDTH, TCOUPRWIDTH, TCOPRCWIDTH};
};

bool PnlFmncBilAPos::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacFmncBilAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacFmncBilAPos";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFusWidth", TcoFusWidth)) add(TCOFUSWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTolWidth", TcoTolWidth)) add(TCOTOLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoQtyWidth", TcoQtyWidth)) add(TCOQTYWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoArtWidth", TcoArtWidth)) add(TCOARTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUprWidth", TcoUprWidth)) add(TCOUPRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrcWidth", TcoPrcWidth)) add(TCOPRCWIDTH);
	};

	return basefound;
};

void PnlFmncBilAPos::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacFmncBilAPos";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacFmncBilAPos";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoFusWidth", TcoFusWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTolWidth", TcoTolWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoQtyWidth", TcoQtyWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoArtWidth", TcoArtWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUprWidth", TcoUprWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoPrcWidth", TcoPrcWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncBilAPos::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoFusWidth == comp->TcoFusWidth) insert(items, TCOFUSWIDTH);
	if (TcoTolWidth == comp->TcoTolWidth) insert(items, TCOTOLWIDTH);
	if (TcoQtyWidth == comp->TcoQtyWidth) insert(items, TCOQTYWIDTH);
	if (TcoArtWidth == comp->TcoArtWidth) insert(items, TCOARTWIDTH);
	if (TcoUprWidth == comp->TcoUprWidth) insert(items, TCOUPRWIDTH);
	if (TcoPrcWidth == comp->TcoPrcWidth) insert(items, TCOPRCWIDTH);

	return(items);
};

set<uint> PnlFmncBilAPos::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOFUSWIDTH, TCOTOLWIDTH, TCOQTYWIDTH, TCOARTWIDTH, TCOUPRWIDTH, TCOPRCWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncBilAPos::Tag
 ******************************************************************************/

PnlFmncBilAPos::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoFus
			, const string& TcoTol
			, const string& TcoQty
			, const string& TcoArt
			, const string& TcoUpr
			, const string& TcoPrc
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoFus = TcoFus;
	this->TcoTol = TcoTol;
	this->TcoQty = TcoQty;
	this->TcoArt = TcoArt;
	this->TcoUpr = TcoUpr;
	this->TcoPrc = TcoPrc;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOFUS, TCOTOL, TCOQTY, TCOART, TCOUPR, TCOPRC};
};

bool PnlFmncBilAPos::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncBilAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncBilAPos";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoFus", TcoFus)) add(TCOFUS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTol", TcoTol)) add(TCOTOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoQty", TcoQty)) add(TCOQTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoArt", TcoArt)) add(TCOART);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoUpr", TcoUpr)) add(TCOUPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoPrc", TcoPrc)) add(TCOPRC);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncBilAPos::DpchAppData
 ******************************************************************************/

PnlFmncBilAPos::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryFmncBilAPos::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCBILAPOSDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlFmncBilAPos::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncBilAPos::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncBilAPosData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncBilAPos::DpchAppDo
 ******************************************************************************/

PnlFmncBilAPos::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCBILAPOSDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncBilAPos::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncBilAPos::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncBilAPosDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncBilAPos::DpchEngData
 ******************************************************************************/

PnlFmncBilAPos::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCBILAPOSDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlFmncBilAPos::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncBilAPos::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncBilAPosData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		continf = ContInf();
		feedFCsiQst.clear();
		statapp = StatApp();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryFmncBilAPos::StatApp();
		statshrqry = QryFmncBilAPos::StatShr();
		stgiacqry = QryFmncBilAPos::StgIac();
	};
};

