/**
  * \file PnlFmncBilDetail_blks.cpp
  * job handler for job PnlFmncBilDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncBilDetail::VecVDo
 ******************************************************************************/

uint PnlFmncBilDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	else if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	else if (s == "butjeditclick") return BUTJEDITCLICK;

	return(0);
};

string PnlFmncBilDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	else if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	else if (ix == BUTJEDITCLICK) return("ButJEditClick");

	return("");
};

/******************************************************************************
 class PnlFmncBilDetail::ContIac
 ******************************************************************************/

PnlFmncBilDetail::ContIac::ContIac(
			const string& TxfDat
			, const uint numFPupJ
			, const uint numFPupSte
			, const string& TxfPra
			, const string& TxfPro
			, const string& TxfAmt
			, const string& TxfCmt
		) : Block() {
	this->TxfDat = TxfDat;
	this->numFPupJ = numFPupJ;
	this->numFPupSte = numFPupSte;
	this->TxfPra = TxfPra;
	this->TxfPro = TxfPro;
	this->TxfAmt = TxfAmt;
	this->TxfCmt = TxfCmt;

	mask = {TXFDAT, NUMFPUPJ, NUMFPUPSTE, TXFPRA, TXFPRO, TXFAMT, TXFCMT};
};

bool PnlFmncBilDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncBilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncBilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDat", TxfDat)) add(TXFDAT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPra", TxfPra)) add(TXFPRA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPro", TxfPro)) add(TXFPRO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAmt", TxfAmt)) add(TXFAMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlFmncBilDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncBilDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncBilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfDat", TxfDat);
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeStringAttr(wr, itemtag, "sref", "TxfPra", TxfPra);
		writeStringAttr(wr, itemtag, "sref", "TxfPro", TxfPro);
		writeStringAttr(wr, itemtag, "sref", "TxfAmt", TxfAmt);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncBilDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfDat == comp->TxfDat) insert(items, TXFDAT);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (TxfPra == comp->TxfPra) insert(items, TXFPRA);
	if (TxfPro == comp->TxfPro) insert(items, TXFPRO);
	if (TxfAmt == comp->TxfAmt) insert(items, TXFAMT);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlFmncBilDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFDAT, NUMFPUPJ, NUMFPUPSTE, TXFPRA, TXFPRO, TXFAMT, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncBilDetail::ContInf
 ******************************************************************************/

PnlFmncBilDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtPrj
			, const string& TxtFil
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtPrj = TxtPrj;
	this->TxtFil = TxtFil;

	mask = {TXTSRF, TXTPRJ, TXTFIL};
};

void PnlFmncBilDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncBilDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncBilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtPrj", TxtPrj);
		writeStringAttr(wr, itemtag, "sref", "TxtFil", TxtFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncBilDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtPrj == comp->TxtPrj) insert(items, TXTPRJ);
	if (TxtFil == comp->TxtFil) insert(items, TXTFIL);

	return(items);
};

set<uint> PnlFmncBilDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTPRJ, TXTFIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncBilDetail::StatApp
 ******************************************************************************/

void PnlFmncBilDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncBilDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncBilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncBilDetail::StatShr
 ******************************************************************************/

PnlFmncBilDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButPrjViewAvail
			, const bool ButFilViewAvail
			, const bool ButJEditAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButPrjViewAvail = ButPrjViewAvail;
	this->ButFilViewAvail = ButFilViewAvail;
	this->ButJEditAvail = ButJEditAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRJVIEWAVAIL, BUTFILVIEWAVAIL, BUTJEDITAVAIL};
};

void PnlFmncBilDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncBilDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncBilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewAvail", ButPrjViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewAvail", ButFilViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJEditAvail", ButJEditAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncBilDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButPrjViewAvail == comp->ButPrjViewAvail) insert(items, BUTPRJVIEWAVAIL);
	if (ButFilViewAvail == comp->ButFilViewAvail) insert(items, BUTFILVIEWAVAIL);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);

	return(items);
};

set<uint> PnlFmncBilDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPRJVIEWAVAIL, BUTFILVIEWAVAIL, BUTJEDITAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncBilDetail::Tag
 ******************************************************************************/

void PnlFmncBilDetail::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncBilDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncBilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptDat", "date");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "fab project");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "file");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "CptPra", "begin of billing period");
			writeStringAttr(wr, itemtag, "sref", "CptPro", "end of billing period");
			writeStringAttr(wr, itemtag, "sref", "CptAmt", "amount");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "Referenz");
			writeStringAttr(wr, itemtag, "sref", "CptDat", "Datum");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "Reinraumprojekt");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Datei");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "Status");
			writeStringAttr(wr, itemtag, "sref", "CptPra", "Anfang des Abrechnungszeitraums");
			writeStringAttr(wr, itemtag, "sref", "CptPro", "Ende des Abrechnungszeitraums");
			writeStringAttr(wr, itemtag, "sref", "CptAmt", "Betrag");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Notiz");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "r\\u00e9f\\u00e9rence");
			writeStringAttr(wr, itemtag, "sref", "CptDat", "date");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "projet salle blanche");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "fichier");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "\\u00e9tat");
			writeStringAttr(wr, itemtag, "sref", "CptPra", "d\\u00e9but de la p\\u00e9riode comptable");
			writeStringAttr(wr, itemtag, "sref", "CptPro", "fin de la p\\u00e9riode comptable");
			writeStringAttr(wr, itemtag, "sref", "CptAmt", "montant");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "remarque");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DETAIL, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncBilDetail::DpchAppData
 ******************************************************************************/

PnlFmncBilDetail::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCBILDETAILDATA) {
};

string PnlFmncBilDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncBilDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncBilDetailData");
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
 class PnlFmncBilDetail::DpchAppDo
 ******************************************************************************/

PnlFmncBilDetail::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCBILDETAILDO) {
	ixVDo = 0;
};

string PnlFmncBilDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncBilDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncBilDetailDo");
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
 class PnlFmncBilDetail::DpchEngData
 ******************************************************************************/

PnlFmncBilDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupJ
			, Feed* feedFPupSte
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCBILDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPJ, FEEDFPUPSTE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPJ) && feedFPupJ) this->feedFPupJ = *feedFPupJ;
	if (find(this->mask, FEEDFPUPSTE) && feedFPupSte) this->feedFPupSte = *feedFPupSte;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncBilDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(FEEDFPUPSTE)) ss.push_back("feedFPupSte");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncBilDetail::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPJ)) {feedFPupJ = src->feedFPupJ; add(FEEDFPUPJ);};
	if (src->has(FEEDFPUPSTE)) {feedFPupSte = src->feedFPupSte; add(FEEDFPUPSTE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncBilDetail::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncBilDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPJ)) feedFPupJ.writeXML(wr);
		if (has(FEEDFPUPSTE)) feedFPupSte.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


