/**
  * \file PnlFmncStpDetail_blks.cpp
  * job handler for job PnlFmncStpDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncStpDetail::VecVDo
 ******************************************************************************/

uint PnlFmncStpDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butactviewclick") return BUTACTVIEWCLICK;
	else if (s == "butrluviewclick") return BUTRLUVIEWCLICK;
	else if (s == "butprsviewclick") return BUTPRSVIEWCLICK;

	return(0);
};

string PnlFmncStpDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTACTVIEWCLICK) return("ButActViewClick");
	else if (ix == BUTRLUVIEWCLICK) return("ButRluViewClick");
	else if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");

	return("");
};

/******************************************************************************
 class PnlFmncStpDetail::ContIac
 ******************************************************************************/

PnlFmncStpDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupRlt
			, const vector<uint>& numsFLstFcf
			, const string& TxfSta
		) : Block() {
	this->TxfTit = TxfTit;
	this->numFPupRlt = numFPupRlt;
	this->numsFLstFcf = numsFLstFcf;
	this->TxfSta = TxfSta;

	mask = {TXFTIT, NUMFPUPRLT, NUMSFLSTFCF, TXFSTA};
};

bool PnlFmncStpDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncStpDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncStpDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRlt", numFPupRlt)) add(NUMFPUPRLT);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstFcf", numsFLstFcf)) add(NUMSFLSTFCF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
	};

	return basefound;
};

void PnlFmncStpDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncStpDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncStpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupRlt", numFPupRlt);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstFcf", numsFLstFcf);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncStpDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (numFPupRlt == comp->numFPupRlt) insert(items, NUMFPUPRLT);
	if (compareUintvec(numsFLstFcf, comp->numsFLstFcf)) insert(items, NUMSFLSTFCF);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);

	return(items);
};

set<uint> PnlFmncStpDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPRLT, NUMSFLSTFCF, TXFSTA};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncStpDetail::ContInf
 ******************************************************************************/

PnlFmncStpDetail::ContInf::ContInf(
			const string& TxtAct
			, const string& TxtRlu
			, const string& TxtStp
			, const string& TxtFcf
			, const string& TxtPrs
		) : Block() {
	this->TxtAct = TxtAct;
	this->TxtRlu = TxtRlu;
	this->TxtStp = TxtStp;
	this->TxtFcf = TxtFcf;
	this->TxtPrs = TxtPrs;

	mask = {TXTACT, TXTRLU, TXTSTP, TXTFCF, TXTPRS};
};

void PnlFmncStpDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncStpDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncStpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtAct", TxtAct);
		writeStringAttr(wr, itemtag, "sref", "TxtRlu", TxtRlu);
		writeStringAttr(wr, itemtag, "sref", "TxtStp", TxtStp);
		writeStringAttr(wr, itemtag, "sref", "TxtFcf", TxtFcf);
		writeStringAttr(wr, itemtag, "sref", "TxtPrs", TxtPrs);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncStpDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtAct == comp->TxtAct) insert(items, TXTACT);
	if (TxtRlu == comp->TxtRlu) insert(items, TXTRLU);
	if (TxtStp == comp->TxtStp) insert(items, TXTSTP);
	if (TxtFcf == comp->TxtFcf) insert(items, TXTFCF);
	if (TxtPrs == comp->TxtPrs) insert(items, TXTPRS);

	return(items);
};

set<uint> PnlFmncStpDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTACT, TXTRLU, TXTSTP, TXTFCF, TXTPRS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncStpDetail::StatApp
 ******************************************************************************/

void PnlFmncStpDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
			, const bool LstFcfAlt
			, const uint LstFcfNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncStpDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncStpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstFcfAlt", LstFcfAlt);
		writeUintAttr(wr, itemtag, "sref", "LstFcfNumFirstdisp", LstFcfNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncStpDetail::StatShr
 ******************************************************************************/

PnlFmncStpDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButActViewAvail
			, const bool ButPrsViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButActViewAvail = ButActViewAvail;
	this->ButPrsViewAvail = ButPrsViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTACTVIEWAVAIL, BUTPRSVIEWAVAIL};
};

void PnlFmncStpDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncStpDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncStpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButActViewAvail", ButActViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrsViewAvail", ButPrsViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncStpDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButActViewAvail == comp->ButActViewAvail) insert(items, BUTACTVIEWAVAIL);
	if (ButPrsViewAvail == comp->ButPrsViewAvail) insert(items, BUTPRSVIEWAVAIL);

	return(items);
};

set<uint> PnlFmncStpDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTACTVIEWAVAIL, BUTPRSVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncStpDetail::Tag
 ******************************************************************************/

void PnlFmncStpDetail::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncStpDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncStpDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptAct", "activity");
			writeStringAttr(wr, itemtag, "sref", "CptRlu", "relevance");
			writeStringAttr(wr, itemtag, "sref", "CptStp", "recipe step");
			writeStringAttr(wr, itemtag, "sref", "CptFcf", "file configurations");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "start");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "operator");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "CptAct", "Aktivit\\u00e4t");
			writeStringAttr(wr, itemtag, "sref", "CptRlu", "Relevanz");
			writeStringAttr(wr, itemtag, "sref", "CptStp", "Rezept-Schritt");
			writeStringAttr(wr, itemtag, "sref", "CptFcf", "Datei-Konfigurationen");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "Start");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "Bedienender");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "nom");
			writeStringAttr(wr, itemtag, "sref", "CptAct", "activit\\u00e9");
			writeStringAttr(wr, itemtag, "sref", "CptRlu", "r\\u00e9l\\u00e9vance");
			writeStringAttr(wr, itemtag, "sref", "CptStp", "\\u00e9tappe recette");
			writeStringAttr(wr, itemtag, "sref", "CptFcf", "configurations des fichiers");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "d\\u00e9but");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "op\\u00e9rateur");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DETAIL, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncStpDetail::DpchAppData
 ******************************************************************************/

PnlFmncStpDetail::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSTPDETAILDATA) {
};

string PnlFmncStpDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncStpDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncStpDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlFmncStpDetail::DpchAppDo
 ******************************************************************************/

PnlFmncStpDetail::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSTPDETAILDO) {
	ixVDo = 0;
};

string PnlFmncStpDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncStpDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncStpDetailDo");
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
 class PnlFmncStpDetail::DpchEngData
 ******************************************************************************/

PnlFmncStpDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstFcf
			, Feed* feedFPupRlt
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCSTPDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTFCF, FEEDFPUPRLT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTFCF) && feedFLstFcf) this->feedFLstFcf = *feedFLstFcf;
	if (find(this->mask, FEEDFPUPRLT) && feedFPupRlt) this->feedFPupRlt = *feedFPupRlt;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncStpDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTFCF)) ss.push_back("feedFLstFcf");
	if (has(FEEDFPUPRLT)) ss.push_back("feedFPupRlt");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncStpDetail::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTFCF)) {feedFLstFcf = src->feedFLstFcf; add(FEEDFLSTFCF);};
	if (src->has(FEEDFPUPRLT)) {feedFPupRlt = src->feedFPupRlt; add(FEEDFPUPRLT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncStpDetail::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncStpDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTFCF)) feedFLstFcf.writeXML(wr);
		if (has(FEEDFPUPRLT)) feedFPupRlt.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


