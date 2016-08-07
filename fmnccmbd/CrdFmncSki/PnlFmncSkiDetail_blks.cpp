/**
  * \file PnlFmncSkiDetail_blks.cpp
  * job handler for job PnlFmncSkiDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncSkiDetail::VecVDo
 ******************************************************************************/

uint PnlFmncSkiDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butorgviewclick") return BUTORGVIEWCLICK;
	else if (s == "butartviewclick") return BUTARTVIEWCLICK;
	else if (s == "butjeditclick") return BUTJEDITCLICK;
	else if (s == "butlcneditclick") return BUTLCNEDITCLICK;

	return(0);
};

string PnlFmncSkiDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTORGVIEWCLICK) return("ButOrgViewClick");
	else if (ix == BUTARTVIEWCLICK) return("ButArtViewClick");
	else if (ix == BUTJEDITCLICK) return("ButJEditClick");
	else if (ix == BUTLCNEDITCLICK) return("ButLcnEditClick");

	return("");
};

/******************************************************************************
 class PnlFmncSkiDetail::ContIac
 ******************************************************************************/

PnlFmncSkiDetail::ContIac::ContIac(
			const uint numFPupJ
			, const uint numFPupLcn
			, const string& TxfLcn
			, const string& TxfExd
			, const string& TxfCmt
		) : Block() {
	this->numFPupJ = numFPupJ;
	this->numFPupLcn = numFPupLcn;
	this->TxfLcn = TxfLcn;
	this->TxfExd = TxfExd;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPJ, NUMFPUPLCN, TXFLCN, TXFEXD, TXFCMT};
};

bool PnlFmncSkiDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncSkiDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncSkiDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupLcn", numFPupLcn)) add(NUMFPUPLCN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLcn", TxfLcn)) add(TXFLCN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfExd", TxfExd)) add(TXFEXD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlFmncSkiDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncSkiDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncSkiDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintAttr(wr, itemtag, "sref", "numFPupLcn", numFPupLcn);
		writeStringAttr(wr, itemtag, "sref", "TxfLcn", TxfLcn);
		writeStringAttr(wr, itemtag, "sref", "TxfExd", TxfExd);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncSkiDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (numFPupLcn == comp->numFPupLcn) insert(items, NUMFPUPLCN);
	if (TxfLcn == comp->TxfLcn) insert(items, TXFLCN);
	if (TxfExd == comp->TxfExd) insert(items, TXFEXD);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlFmncSkiDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJ, NUMFPUPLCN, TXFLCN, TXFEXD, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncSkiDetail::ContInf
 ******************************************************************************/

PnlFmncSkiDetail::ContInf::ContInf(
			const string& TxtOrg
			, const string& TxtArt
			, const string& TxtQty
		) : Block() {
	this->TxtOrg = TxtOrg;
	this->TxtArt = TxtArt;
	this->TxtQty = TxtQty;

	mask = {TXTORG, TXTART, TXTQTY};
};

void PnlFmncSkiDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncSkiDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncSkiDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtOrg", TxtOrg);
		writeStringAttr(wr, itemtag, "sref", "TxtArt", TxtArt);
		writeStringAttr(wr, itemtag, "sref", "TxtQty", TxtQty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncSkiDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtOrg == comp->TxtOrg) insert(items, TXTORG);
	if (TxtArt == comp->TxtArt) insert(items, TXTART);
	if (TxtQty == comp->TxtQty) insert(items, TXTQTY);

	return(items);
};

set<uint> PnlFmncSkiDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTORG, TXTART, TXTQTY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncSkiDetail::StatApp
 ******************************************************************************/

void PnlFmncSkiDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
			, const bool PupLcnAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncSkiDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncSkiDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupLcnAlt", PupLcnAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncSkiDetail::StatShr
 ******************************************************************************/

PnlFmncSkiDetail::StatShr::StatShr(
			const bool TxfLcnValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButOrgViewAvail
			, const bool ButArtViewAvail
			, const bool ButJEditAvail
			, const bool ButLcnEditAvail
		) : Block() {
	this->TxfLcnValid = TxfLcnValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButOrgViewAvail = ButOrgViewAvail;
	this->ButArtViewAvail = ButArtViewAvail;
	this->ButJEditAvail = ButJEditAvail;
	this->ButLcnEditAvail = ButLcnEditAvail;

	mask = {TXFLCNVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTORGVIEWAVAIL, BUTARTVIEWAVAIL, BUTJEDITAVAIL, BUTLCNEDITAVAIL};
};

void PnlFmncSkiDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncSkiDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncSkiDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfLcnValid", TxfLcnValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOrgViewAvail", ButOrgViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButArtViewAvail", ButArtViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJEditAvail", ButJEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLcnEditAvail", ButLcnEditAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncSkiDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfLcnValid == comp->TxfLcnValid) insert(items, TXFLCNVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButOrgViewAvail == comp->ButOrgViewAvail) insert(items, BUTORGVIEWAVAIL);
	if (ButArtViewAvail == comp->ButArtViewAvail) insert(items, BUTARTVIEWAVAIL);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (ButLcnEditAvail == comp->ButLcnEditAvail) insert(items, BUTLCNEDITAVAIL);

	return(items);
};

set<uint> PnlFmncSkiDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFLCNVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTORGVIEWAVAIL, BUTARTVIEWAVAIL, BUTJEDITAVAIL, BUTLCNEDITAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncSkiDetail::Tag
 ******************************************************************************/

void PnlFmncSkiDetail::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncSkiDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncSkiDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptOrg", "owner");
			writeStringAttr(wr, itemtag, "sref", "CptArt", "article");
			writeStringAttr(wr, itemtag, "sref", "CptQty", "quantity");
			writeStringAttr(wr, itemtag, "sref", "CptLcn", "location");
			writeStringAttr(wr, itemtag, "sref", "CptExd", "expiry date");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptOrg", "Eigent\\u00fcmer");
			writeStringAttr(wr, itemtag, "sref", "CptArt", "Artikel");
			writeStringAttr(wr, itemtag, "sref", "CptQty", "Menge");
			writeStringAttr(wr, itemtag, "sref", "CptLcn", "Ort");
			writeStringAttr(wr, itemtag, "sref", "CptExd", "Ablaufdatum");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Notiz");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptOrg", "proprietaire");
			writeStringAttr(wr, itemtag, "sref", "CptArt", "article");
			writeStringAttr(wr, itemtag, "sref", "CptQty", "quantit\\u00e9");
			writeStringAttr(wr, itemtag, "sref", "CptLcn", "endroit");
			writeStringAttr(wr, itemtag, "sref", "CptExd", "\\u00e9ch\\u00e9ance");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "remarque");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DETAIL, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncSkiDetail::DpchAppData
 ******************************************************************************/

PnlFmncSkiDetail::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSKIDETAILDATA) {
};

string PnlFmncSkiDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncSkiDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncSkiDetailData");
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
 class PnlFmncSkiDetail::DpchAppDo
 ******************************************************************************/

PnlFmncSkiDetail::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSKIDETAILDO) {
	ixVDo = 0;
};

string PnlFmncSkiDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncSkiDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncSkiDetailDo");
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
 class PnlFmncSkiDetail::DpchEngData
 ******************************************************************************/

PnlFmncSkiDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupJ
			, Feed* feedFPupLcn
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCSKIDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPJ, FEEDFPUPLCN, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPJ) && feedFPupJ) this->feedFPupJ = *feedFPupJ;
	if (find(this->mask, FEEDFPUPLCN) && feedFPupLcn) this->feedFPupLcn = *feedFPupLcn;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncSkiDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(FEEDFPUPLCN)) ss.push_back("feedFPupLcn");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncSkiDetail::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPJ)) {feedFPupJ = src->feedFPupJ; add(FEEDFPUPJ);};
	if (src->has(FEEDFPUPLCN)) {feedFPupLcn = src->feedFPupLcn; add(FEEDFPUPLCN);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncSkiDetail::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncSkiDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPJ)) feedFPupJ.writeXML(wr);
		if (has(FEEDFPUPLCN)) feedFPupLcn.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


