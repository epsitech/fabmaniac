/**
  * \file PnlFmncPcoDetail_blks.cpp
  * job handler for job PnlFmncPcoDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncPcoDetail::VecVDo
 ******************************************************************************/

uint PnlFmncPcoDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butpcoviewclick") return BUTPCOVIEWCLICK;
	else if (s == "butsplviewclick") return BUTSPLVIEWCLICK;
	else if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	else if (s == "butjeditclick") return BUTJEDITCLICK;
	else if (s == "butpcpviewclick") return BUTPCPVIEWCLICK;

	return(0);
};

string PnlFmncPcoDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTPCOVIEWCLICK) return("ButPcoViewClick");
	else if (ix == BUTSPLVIEWCLICK) return("ButSplViewClick");
	else if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	else if (ix == BUTJEDITCLICK) return("ButJEditClick");
	else if (ix == BUTPCPVIEWCLICK) return("ButPcpViewClick");

	return("");
};

/******************************************************************************
 class PnlFmncPcoDetail::ContIac
 ******************************************************************************/

PnlFmncPcoDetail::ContIac::ContIac(
			const string& TxfDat
			, const uint numFPupJ
			, const uint numFPupSte
			, const string& TxfAmt
			, const string& TxfCmt
		) : Block() {
	this->TxfDat = TxfDat;
	this->numFPupJ = numFPupJ;
	this->numFPupSte = numFPupSte;
	this->TxfAmt = TxfAmt;
	this->TxfCmt = TxfCmt;

	mask = {TXFDAT, NUMFPUPJ, NUMFPUPSTE, TXFAMT, TXFCMT};
};

bool PnlFmncPcoDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncPcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncPcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDat", TxfDat)) add(TXFDAT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAmt", TxfAmt)) add(TXFAMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlFmncPcoDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncPcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncPcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfDat", TxfDat);
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeStringAttr(wr, itemtag, "sref", "TxfAmt", TxfAmt);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncPcoDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfDat == comp->TxfDat) insert(items, TXFDAT);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (TxfAmt == comp->TxfAmt) insert(items, TXFAMT);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlFmncPcoDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFDAT, NUMFPUPJ, NUMFPUPSTE, TXFAMT, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPcoDetail::ContInf
 ******************************************************************************/

PnlFmncPcoDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtPco
			, const string& TxtSpl
			, const string& TxtFil
			, const string& TxtPcp
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtPco = TxtPco;
	this->TxtSpl = TxtSpl;
	this->TxtFil = TxtFil;
	this->TxtPcp = TxtPcp;

	mask = {TXTSRF, TXTPCO, TXTSPL, TXTFIL, TXTPCP};
};

void PnlFmncPcoDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncPcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncPcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtPco", TxtPco);
		writeStringAttr(wr, itemtag, "sref", "TxtSpl", TxtSpl);
		writeStringAttr(wr, itemtag, "sref", "TxtFil", TxtFil);
		writeStringAttr(wr, itemtag, "sref", "TxtPcp", TxtPcp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncPcoDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtPco == comp->TxtPco) insert(items, TXTPCO);
	if (TxtSpl == comp->TxtSpl) insert(items, TXTSPL);
	if (TxtFil == comp->TxtFil) insert(items, TXTFIL);
	if (TxtPcp == comp->TxtPcp) insert(items, TXTPCP);

	return(items);
};

set<uint> PnlFmncPcoDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTPCO, TXTSPL, TXTFIL, TXTPCP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPcoDetail::StatApp
 ******************************************************************************/

void PnlFmncPcoDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncPcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncPcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncPcoDetail::StatShr
 ******************************************************************************/

PnlFmncPcoDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButPcoViewAvail
			, const bool ButSplViewAvail
			, const bool ButFilViewAvail
			, const bool ButJEditAvail
			, const bool ButPcpViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButPcoViewAvail = ButPcoViewAvail;
	this->ButSplViewAvail = ButSplViewAvail;
	this->ButFilViewAvail = ButFilViewAvail;
	this->ButJEditAvail = ButJEditAvail;
	this->ButPcpViewAvail = ButPcpViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPCOVIEWAVAIL, BUTSPLVIEWAVAIL, BUTFILVIEWAVAIL, BUTJEDITAVAIL, BUTPCPVIEWAVAIL};
};

void PnlFmncPcoDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncPcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncPcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPcoViewAvail", ButPcoViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSplViewAvail", ButSplViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewAvail", ButFilViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJEditAvail", ButJEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPcpViewAvail", ButPcpViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncPcoDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButPcoViewAvail == comp->ButPcoViewAvail) insert(items, BUTPCOVIEWAVAIL);
	if (ButSplViewAvail == comp->ButSplViewAvail) insert(items, BUTSPLVIEWAVAIL);
	if (ButFilViewAvail == comp->ButFilViewAvail) insert(items, BUTFILVIEWAVAIL);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (ButPcpViewAvail == comp->ButPcpViewAvail) insert(items, BUTPCPVIEWAVAIL);

	return(items);
};

set<uint> PnlFmncPcoDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTPCOVIEWAVAIL, BUTSPLVIEWAVAIL, BUTFILVIEWAVAIL, BUTJEDITAVAIL, BUTPCPVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPcoDetail::Tag
 ******************************************************************************/

void PnlFmncPcoDetail::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncPcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncPcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptDat", "date");
			writeStringAttr(wr, itemtag, "sref", "CptPco", "client organization");
			writeStringAttr(wr, itemtag, "sref", "CptSpl", "supplier");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "file");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "CptAmt", "amount");
			writeStringAttr(wr, itemtag, "sref", "CptPcp", "buyer");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "Referenz");
			writeStringAttr(wr, itemtag, "sref", "CptDat", "Datum");
			writeStringAttr(wr, itemtag, "sref", "CptPco", "Kundenorganisation");
			writeStringAttr(wr, itemtag, "sref", "CptSpl", "Lieferant");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Datei");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "Status");
			writeStringAttr(wr, itemtag, "sref", "CptAmt", "Betrag");
			writeStringAttr(wr, itemtag, "sref", "CptPcp", "Besteller");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Notiz");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "r\\u00e9f\\u00e9rence");
			writeStringAttr(wr, itemtag, "sref", "CptDat", "date");
			writeStringAttr(wr, itemtag, "sref", "CptPco", "organisme client");
			writeStringAttr(wr, itemtag, "sref", "CptSpl", "fournisseur");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "fichier");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "\\u00e9tat");
			writeStringAttr(wr, itemtag, "sref", "CptAmt", "montant");
			writeStringAttr(wr, itemtag, "sref", "CptPcp", "acheteur");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "remarque");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DETAIL, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncPcoDetail::DpchAppData
 ******************************************************************************/

PnlFmncPcoDetail::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCPCODETAILDATA) {
};

string PnlFmncPcoDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncPcoDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncPcoDetailData");
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
 class PnlFmncPcoDetail::DpchAppDo
 ******************************************************************************/

PnlFmncPcoDetail::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCPCODETAILDO) {
	ixVDo = 0;
};

string PnlFmncPcoDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncPcoDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncPcoDetailDo");
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
 class PnlFmncPcoDetail::DpchEngData
 ******************************************************************************/

PnlFmncPcoDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupJ
			, Feed* feedFPupSte
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCPCODETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPJ, FEEDFPUPSTE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPJ) && feedFPupJ) this->feedFPupJ = *feedFPupJ;
	if (find(this->mask, FEEDFPUPSTE) && feedFPupSte) this->feedFPupSte = *feedFPupSte;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncPcoDetail::DpchEngData::getSrefsMask() {
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

void PnlFmncPcoDetail::DpchEngData::merge(
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

void PnlFmncPcoDetail::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncPcoDetailData");
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


