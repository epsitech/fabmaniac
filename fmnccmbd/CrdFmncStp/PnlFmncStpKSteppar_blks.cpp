/**
  * \file PnlFmncStpKSteppar_blks.cpp
  * job handler for job PnlFmncStpKSteppar (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncStpKSteppar::VecVDo
 ******************************************************************************/

uint PnlFmncStpKSteppar::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butupclick") return BUTUPCLICK;
	else if (s == "butdownclick") return BUTDOWNCLICK;
	else if (s == "butnewclick") return BUTNEWCLICK;
	else if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	else if (s == "butdeleteclick") return BUTDELETECLICK;
	else if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlFmncStpKSteppar::VecVDo::getSref(
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
 class PnlFmncStpKSteppar::ContInf
 ******************************************************************************/

PnlFmncStpKSteppar::ContInf::ContInf(
			const uint numFCsiQst
		) : Block() {
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlFmncStpKSteppar::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncStpKSteppar";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncStpKSteppar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncStpKSteppar::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlFmncStpKSteppar::ContInf::diff(
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
 class PnlFmncStpKSteppar::StatApp
 ******************************************************************************/

void PnlFmncStpKSteppar::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncStpKSteppar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncStpKSteppar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncStpKSteppar::StatShr
 ******************************************************************************/

PnlFmncStpKSteppar::StatShr::StatShr(
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

void PnlFmncStpKSteppar::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncStpKSteppar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncStpKSteppar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButUpActive", ButUpActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDownActive", ButDownActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncStpKSteppar::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlFmncStpKSteppar::StatShr::diff(
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
 class PnlFmncStpKSteppar::StgIac
 ******************************************************************************/

PnlFmncStpKSteppar::StgIac::StgIac(
			const uint TcoFixWidth
			, const uint TcoSrfWidth
			, const uint TcoAvlWidth
			, const uint TcoImpWidth
			, const uint TcoTitWidth
			, const uint TcoCmtWidth
		) : Block() {
	this->TcoFixWidth = TcoFixWidth;
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoAvlWidth = TcoAvlWidth;
	this->TcoImpWidth = TcoImpWidth;
	this->TcoTitWidth = TcoTitWidth;
	this->TcoCmtWidth = TcoCmtWidth;
	mask = {TCOFIXWIDTH, TCOSRFWIDTH, TCOAVLWIDTH, TCOIMPWIDTH, TCOTITWIDTH, TCOCMTWIDTH};
};

bool PnlFmncStpKSteppar::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacFmncStpKSteppar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacFmncStpKSteppar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFixWidth", TcoFixWidth)) add(TCOFIXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoAvlWidth", TcoAvlWidth)) add(TCOAVLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoImpWidth", TcoImpWidth)) add(TCOIMPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTitWidth", TcoTitWidth)) add(TCOTITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", TcoCmtWidth)) add(TCOCMTWIDTH);
	};

	return basefound;
};

void PnlFmncStpKSteppar::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacFmncStpKSteppar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacFmncStpKSteppar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoFixWidth", TcoFixWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoAvlWidth", TcoAvlWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoImpWidth", TcoImpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncStpKSteppar::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoFixWidth == comp->TcoFixWidth) insert(items, TCOFIXWIDTH);
	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoAvlWidth == comp->TcoAvlWidth) insert(items, TCOAVLWIDTH);
	if (TcoImpWidth == comp->TcoImpWidth) insert(items, TCOIMPWIDTH);
	if (TcoTitWidth == comp->TcoTitWidth) insert(items, TCOTITWIDTH);
	if (TcoCmtWidth == comp->TcoCmtWidth) insert(items, TCOCMTWIDTH);

	return(items);
};

set<uint> PnlFmncStpKSteppar::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOFIXWIDTH, TCOSRFWIDTH, TCOAVLWIDTH, TCOIMPWIDTH, TCOTITWIDTH, TCOCMTWIDTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncStpKSteppar::Tag
 ******************************************************************************/

void PnlFmncStpKSteppar::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncStpKSteppar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncStpKSteppar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Parameter");
			writeStringAttr(wr, itemtag, "sref", "TcoFix", "Fixed");
			writeStringAttr(wr, itemtag, "sref", "TcoSrf", "Identifier");
			writeStringAttr(wr, itemtag, "sref", "TcoAvl", "Avail. rule");
			writeStringAttr(wr, itemtag, "sref", "TcoImp", "Impl. rule");
			writeStringAttr(wr, itemtag, "sref", "TcoTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "TcoCmt", "Comment");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Parameter");
			writeStringAttr(wr, itemtag, "sref", "TcoFix", "Statisch");
			writeStringAttr(wr, itemtag, "sref", "TcoSrf", "Bezeichner");
			writeStringAttr(wr, itemtag, "sref", "TcoAvl", "Verf\\u00fcgbar");
			writeStringAttr(wr, itemtag, "sref", "TcoImp", "Impliziert");
			writeStringAttr(wr, itemtag, "sref", "TcoTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "TcoCmt", "Notiz");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Param\\u00e8tre");
			writeStringAttr(wr, itemtag, "sref", "TcoFix", "Fix\\u00e9");
			writeStringAttr(wr, itemtag, "sref", "TcoSrf", "Identifiant");
			writeStringAttr(wr, itemtag, "sref", "TcoAvl", "Disponible");
			writeStringAttr(wr, itemtag, "sref", "TcoImp", "Impliqu\\u00e9");
			writeStringAttr(wr, itemtag, "sref", "TcoTit", "Nom");
			writeStringAttr(wr, itemtag, "sref", "TcoCmt", "Remarque");
		};
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::GOTO, ixFmncVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecFmncVTag::getTitle(VecFmncVTag::SHOWSHORT, ixFmncVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecFmncVTag::getTitle(VecFmncVTag::EMPSHORT, ixFmncVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncStpKSteppar::DpchAppData
 ******************************************************************************/

PnlFmncStpKSteppar::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSTPKSTEPPARDATA) {
};

string PnlFmncStpKSteppar::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncStpKSteppar::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncStpKStepparData");
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
		stgiacqry = QryFmncStpKSteppar::StgIac();
	};
};

/******************************************************************************
 class PnlFmncStpKSteppar::DpchAppDo
 ******************************************************************************/

PnlFmncStpKSteppar::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSTPKSTEPPARDO) {
	ixVDo = 0;
};

string PnlFmncStpKSteppar::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncStpKSteppar::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncStpKStepparDo");
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
 class PnlFmncStpKSteppar::DpchEngData
 ******************************************************************************/

PnlFmncStpKSteppar::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListFmncQStpKSteppar* rst
			, QryFmncStpKSteppar::StatShr* statshrqry
			, QryFmncStpKSteppar::StgIac* stgiacqry
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCSTPKSTEPPARDATA, jref) {
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

string PnlFmncStpKSteppar::DpchEngData::getSrefsMask() {
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

void PnlFmncStpKSteppar::DpchEngData::merge(
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

void PnlFmncStpKSteppar::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncStpKStepparData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryFmncStpKSteppar::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

