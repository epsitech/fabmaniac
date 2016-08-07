/**
  * \file PnlFmncTolAUtil.cpp
  * API code for job PnlFmncTolAUtil (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncTolAUtil.h"

/******************************************************************************
 class PnlFmncTolAUtil::VecVDo
 ******************************************************************************/

uint PnlFmncTolAUtil::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butnewclick") == 0) return BUTNEWCLICK;
	else if (s.compare("butduplicateclick") == 0) return BUTDUPLICATECLICK;
	else if (s.compare("butdeleteclick") == 0) return BUTDELETECLICK;
	else if (s.compare("butrefreshclick") == 0) return BUTREFRESHCLICK;

	return(0);
};

string PnlFmncTolAUtil::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlFmncTolAUtil::ContInf
 ******************************************************************************/

PnlFmncTolAUtil::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlFmncTolAUtil::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncTolAUtil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncTolAUtil";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlFmncTolAUtil::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlFmncTolAUtil::ContInf::diff(
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
 class PnlFmncTolAUtil::StatApp
 ******************************************************************************/

PnlFmncTolAUtil::StatApp::StatApp(
			const uint ixFmncVExpstate
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;

	mask = {IXFMNCVEXPSTATE};
};

bool PnlFmncTolAUtil::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncTolAUtil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncTolAUtil";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlFmncTolAUtil::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);

	return(items);
};

set<uint> PnlFmncTolAUtil::StatApp::diff(
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
 class PnlFmncTolAUtil::StatShr
 ******************************************************************************/

PnlFmncTolAUtil::StatShr::StatShr(
			const bool ButDuplicateActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
};

bool PnlFmncTolAUtil::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncTolAUtil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncTolAUtil";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncTolAUtil::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlFmncTolAUtil::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncTolAUtil::StgIac
 ******************************************************************************/

PnlFmncTolAUtil::StgIac::StgIac(
			const uint TcoFpjWidth
			, const uint TcoFusWidth
			, const uint TcoDatWidth
			, const uint TcoStaWidth
			, const uint TcoStoWidth
			, const uint TcoUprWidth
			, const uint TcoCmtWidth
		) : Block() {
	this->TcoFpjWidth = TcoFpjWidth;
	this->TcoFusWidth = TcoFusWidth;
	this->TcoDatWidth = TcoDatWidth;
	this->TcoStaWidth = TcoStaWidth;
	this->TcoStoWidth = TcoStoWidth;
	this->TcoUprWidth = TcoUprWidth;
	this->TcoCmtWidth = TcoCmtWidth;

	mask = {TCOFPJWIDTH, TCOFUSWIDTH, TCODATWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOUPRWIDTH, TCOCMTWIDTH};
};

bool PnlFmncTolAUtil::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacFmncTolAUtil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacFmncTolAUtil";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFpjWidth", TcoFpjWidth)) add(TCOFPJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFusWidth", TcoFusWidth)) add(TCOFUSWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDatWidth", TcoDatWidth)) add(TCODATWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStaWidth", TcoStaWidth)) add(TCOSTAWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStoWidth", TcoStoWidth)) add(TCOSTOWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUprWidth", TcoUprWidth)) add(TCOUPRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", TcoCmtWidth)) add(TCOCMTWIDTH);
	};

	return basefound;
};

void PnlFmncTolAUtil::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacFmncTolAUtil";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacFmncTolAUtil";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoFpjWidth", TcoFpjWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoFusWidth", TcoFusWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDatWidth", TcoDatWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStaWidth", TcoStaWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStoWidth", TcoStoWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUprWidth", TcoUprWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncTolAUtil::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoFpjWidth == comp->TcoFpjWidth) insert(items, TCOFPJWIDTH);
	if (TcoFusWidth == comp->TcoFusWidth) insert(items, TCOFUSWIDTH);
	if (TcoDatWidth == comp->TcoDatWidth) insert(items, TCODATWIDTH);
	if (TcoStaWidth == comp->TcoStaWidth) insert(items, TCOSTAWIDTH);
	if (TcoStoWidth == comp->TcoStoWidth) insert(items, TCOSTOWIDTH);
	if (TcoUprWidth == comp->TcoUprWidth) insert(items, TCOUPRWIDTH);
	if (TcoCmtWidth == comp->TcoCmtWidth) insert(items, TCOCMTWIDTH);

	return(items);
};

set<uint> PnlFmncTolAUtil::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOFPJWIDTH, TCOFUSWIDTH, TCODATWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOUPRWIDTH, TCOCMTWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncTolAUtil::Tag
 ******************************************************************************/

PnlFmncTolAUtil::Tag::Tag(
			const string& Cpt
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoFpj
			, const string& TcoFus
			, const string& TcoDat
			, const string& TcoSta
			, const string& TcoSto
			, const string& TcoUpr
			, const string& TcoCmt
		) : Block() {
	this->Cpt = Cpt;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoFpj = TcoFpj;
	this->TcoFus = TcoFus;
	this->TcoDat = TcoDat;
	this->TcoSta = TcoSta;
	this->TcoSto = TcoSto;
	this->TcoUpr = TcoUpr;
	this->TcoCmt = TcoCmt;

	mask = {CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOFPJ, TCOFUS, TCODAT, TCOSTA, TCOSTO, TCOUPR, TCOCMT};
};

bool PnlFmncTolAUtil::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncTolAUtil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncTolAUtil";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoFpj", TcoFpj)) add(TCOFPJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoFus", TcoFus)) add(TCOFUS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoDat", TcoDat)) add(TCODAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSta", TcoSta)) add(TCOSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSto", TcoSto)) add(TCOSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoUpr", TcoUpr)) add(TCOUPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCmt", TcoCmt)) add(TCOCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncTolAUtil::DpchAppData
 ******************************************************************************/

PnlFmncTolAUtil::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryFmncTolAUtil::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCTOLAUTILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlFmncTolAUtil::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncTolAUtil::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncTolAUtilData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncTolAUtil::DpchAppDo
 ******************************************************************************/

PnlFmncTolAUtil::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCTOLAUTILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncTolAUtil::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncTolAUtil::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncTolAUtilDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncTolAUtil::DpchEngData
 ******************************************************************************/

PnlFmncTolAUtil::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCTOLAUTILDATA) {
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlFmncTolAUtil::DpchEngData::getSrefsMask() {
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

void PnlFmncTolAUtil::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncTolAUtilData");
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
		statappqry = QryFmncTolAUtil::StatApp();
		statshrqry = QryFmncTolAUtil::StatShr();
		stgiacqry = QryFmncTolAUtil::StgIac();
	};
};

