/**
  * \file PnlFmncUsrAAccess_blks.cpp
  * job handler for job PnlFmncUsrAAccess (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncUsrAAccess::VecVDo
 ******************************************************************************/

uint PnlFmncUsrAAccess::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butnewclick") return BUTNEWCLICK;
	else if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	else if (s == "butdeleteclick") return BUTDELETECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlFmncUsrAAccess::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTNEWCLICK) return("ButNewClick");
	else if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	else if (ix == BUTDELETECLICK) return("ButDeleteClick");
	else if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlFmncUsrAAccess::ContInf
 ******************************************************************************/

PnlFmncUsrAAccess::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlFmncUsrAAccess::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncUsrAAccess";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncUsrAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncUsrAAccess::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlFmncUsrAAccess::ContInf::diff(
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
 class PnlFmncUsrAAccess::StatApp
 ******************************************************************************/

void PnlFmncUsrAAccess::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncUsrAAccess";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncUsrAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncUsrAAccess::StatShr
 ******************************************************************************/

PnlFmncUsrAAccess::StatShr::StatShr(
			const bool ButDuplicateActive
			, const bool ButDeleteActive
		) : Block() {
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTDUPLICATEACTIVE, BUTDELETEACTIVE};
};

void PnlFmncUsrAAccess::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncUsrAAccess";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncUsrAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncUsrAAccess::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlFmncUsrAAccess::StatShr::diff(
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
 class PnlFmncUsrAAccess::StgIac
 ******************************************************************************/

PnlFmncUsrAAccess::StgIac::StgIac(
			const uint TcoCrdWidth
			, const uint TcoUacWidth
		) : Block() {
	this->TcoCrdWidth = TcoCrdWidth;
	this->TcoUacWidth = TcoUacWidth;
	mask = {TCOCRDWIDTH, TCOUACWIDTH};
};

bool PnlFmncUsrAAccess::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacFmncUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacFmncUsrAAccess";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCrdWidth", TcoCrdWidth)) add(TCOCRDWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoUacWidth", TcoUacWidth)) add(TCOUACWIDTH);
	};

	return basefound;
};

void PnlFmncUsrAAccess::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacFmncUsrAAccess";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacFmncUsrAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoCrdWidth", TcoCrdWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoUacWidth", TcoUacWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncUsrAAccess::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoCrdWidth == comp->TcoCrdWidth) insert(items, TCOCRDWIDTH);
	if (TcoUacWidth == comp->TcoUacWidth) insert(items, TCOUACWIDTH);

	return(items);
};

set<uint> PnlFmncUsrAAccess::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOCRDWIDTH, TCOUACWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncUsrAAccess::Tag
 ******************************************************************************/

void PnlFmncUsrAAccess::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncUsrAAccess";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncUsrAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Card access rights");
			writeStringAttr(wr, itemtag, "sref", "TcoCrd", "Card");
			writeStringAttr(wr, itemtag, "sref", "TcoUac", "UI access rights");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Karten-Zugriffsrechte");
			writeStringAttr(wr, itemtag, "sref", "TcoCrd", "Karte");
			writeStringAttr(wr, itemtag, "sref", "TcoUac", "UI Zugriffsrechte");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Droits d'acc\\u00e8s aux cartes");
			writeStringAttr(wr, itemtag, "sref", "TcoCrd", "Carte");
			writeStringAttr(wr, itemtag, "sref", "TcoUac", "Privil\\u00e8ges d'acc\\u00e8s UI");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::GOTO, ixFmncVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecFmncVTag::getTitle(VecFmncVTag::SHOWSHORT, ixFmncVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecFmncVTag::getTitle(VecFmncVTag::EMPSHORT, ixFmncVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncUsrAAccess::DpchAppData
 ******************************************************************************/

PnlFmncUsrAAccess::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCUSRAACCESSDATA) {
};

string PnlFmncUsrAAccess::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncUsrAAccess::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncUsrAAccessData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryFmncUsrAAccess::StgIac();
	};
};

/******************************************************************************
 class PnlFmncUsrAAccess::DpchAppDo
 ******************************************************************************/

PnlFmncUsrAAccess::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCUSRAACCESSDO) {
	ixVDo = 0;
};

string PnlFmncUsrAAccess::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncUsrAAccess::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncUsrAAccessDo");
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
 class PnlFmncUsrAAccess::DpchEngData
 ******************************************************************************/

PnlFmncUsrAAccess::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListFmncQUsrAAccess* rst
			, QryFmncUsrAAccess::StatShr* statshrqry
			, QryFmncUsrAAccess::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCUSRAACCESSDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFCSIQST, STATAPP, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlFmncUsrAAccess::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlFmncUsrAAccess::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlFmncUsrAAccess::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncUsrAAccessData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryFmncUsrAAccess::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};


