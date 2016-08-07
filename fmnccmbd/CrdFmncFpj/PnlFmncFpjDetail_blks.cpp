/**
  * \file PnlFmncFpjDetail_blks.cpp
  * job handler for job PnlFmncFpjDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncFpjDetail::VecVDo
 ******************************************************************************/

uint PnlFmncFpjDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butfabviewclick") return BUTFABVIEWCLICK;
	else if (s == "butbioviewclick") return BUTBIOVIEWCLICK;
	else if (s == "butjeditclick") return BUTJEDITCLICK;
	else if (s == "butbipviewclick") return BUTBIPVIEWCLICK;

	return(0);
};

string PnlFmncFpjDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTFABVIEWCLICK) return("ButFabViewClick");
	else if (ix == BUTBIOVIEWCLICK) return("ButBioViewClick");
	else if (ix == BUTJEDITCLICK) return("ButJEditClick");
	else if (ix == BUTBIPVIEWCLICK) return("ButBipViewClick");

	return("");
};

/******************************************************************************
 class PnlFmncFpjDetail::ContIac
 ******************************************************************************/

PnlFmncFpjDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupJ
			, const uint numFPupSte
			, const string& TxfCmt
		) : Block() {
	this->TxfTit = TxfTit;
	this->numFPupJ = numFPupJ;
	this->numFPupSte = numFPupSte;
	this->TxfCmt = TxfCmt;

	mask = {TXFTIT, NUMFPUPJ, NUMFPUPSTE, TXFCMT};
};

bool PnlFmncFpjDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncFpjDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncFpjDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlFmncFpjDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncFpjDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncFpjDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncFpjDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlFmncFpjDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPJ, NUMFPUPSTE, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncFpjDetail::ContInf
 ******************************************************************************/

PnlFmncFpjDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtFab
			, const string& TxtBio
			, const string& TxtBip
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtFab = TxtFab;
	this->TxtBio = TxtBio;
	this->TxtBip = TxtBip;

	mask = {TXTSRF, TXTFAB, TXTBIO, TXTBIP};
};

void PnlFmncFpjDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncFpjDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncFpjDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtFab", TxtFab);
		writeStringAttr(wr, itemtag, "sref", "TxtBio", TxtBio);
		writeStringAttr(wr, itemtag, "sref", "TxtBip", TxtBip);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncFpjDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtFab == comp->TxtFab) insert(items, TXTFAB);
	if (TxtBio == comp->TxtBio) insert(items, TXTBIO);
	if (TxtBip == comp->TxtBip) insert(items, TXTBIP);

	return(items);
};

set<uint> PnlFmncFpjDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTFAB, TXTBIO, TXTBIP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncFpjDetail::StatApp
 ******************************************************************************/

void PnlFmncFpjDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncFpjDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncFpjDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncFpjDetail::StatShr
 ******************************************************************************/

PnlFmncFpjDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButFabViewAvail
			, const bool ButBioViewAvail
			, const bool ButJEditAvail
			, const bool ButBipViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButFabViewAvail = ButFabViewAvail;
	this->ButBioViewAvail = ButBioViewAvail;
	this->ButJEditAvail = ButJEditAvail;
	this->ButBipViewAvail = ButBipViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTFABVIEWAVAIL, BUTBIOVIEWAVAIL, BUTJEDITAVAIL, BUTBIPVIEWAVAIL};
};

void PnlFmncFpjDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncFpjDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncFpjDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFabViewAvail", ButFabViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBioViewAvail", ButBioViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJEditAvail", ButJEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBipViewAvail", ButBipViewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncFpjDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButFabViewAvail == comp->ButFabViewAvail) insert(items, BUTFABVIEWAVAIL);
	if (ButBioViewAvail == comp->ButBioViewAvail) insert(items, BUTBIOVIEWAVAIL);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (ButBipViewAvail == comp->ButBipViewAvail) insert(items, BUTBIPVIEWAVAIL);

	return(items);
};

set<uint> PnlFmncFpjDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTFABVIEWAVAIL, BUTBIOVIEWAVAIL, BUTJEDITAVAIL, BUTBIPVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncFpjDetail::Tag
 ******************************************************************************/

void PnlFmncFpjDetail::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncFpjDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncFpjDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "fab");
			writeStringAttr(wr, itemtag, "sref", "CptBio", "organization for billing");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "CptBip", "person for billing");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "Referenz");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "Reinraum");
			writeStringAttr(wr, itemtag, "sref", "CptBio", "Organisation zur Rechnungsstellung");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "Status");
			writeStringAttr(wr, itemtag, "sref", "CptBip", "Person zur Rechnungsstellung");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Notiz");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "r\\u00e9f\\u00e9rence");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "nom");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "salle blanche");
			writeStringAttr(wr, itemtag, "sref", "CptBio", "organisme pour facturisation");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "\\u00e9tat");
			writeStringAttr(wr, itemtag, "sref", "CptBip", "individu pour facturisation");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "remarque");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DETAIL, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncFpjDetail::DpchAppData
 ******************************************************************************/

PnlFmncFpjDetail::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCFPJDETAILDATA) {
};

string PnlFmncFpjDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncFpjDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncFpjDetailData");
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
 class PnlFmncFpjDetail::DpchAppDo
 ******************************************************************************/

PnlFmncFpjDetail::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCFPJDETAILDO) {
	ixVDo = 0;
};

string PnlFmncFpjDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncFpjDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncFpjDetailDo");
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
 class PnlFmncFpjDetail::DpchEngData
 ******************************************************************************/

PnlFmncFpjDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupJ
			, Feed* feedFPupSte
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCFPJDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPJ, FEEDFPUPSTE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPJ) && feedFPupJ) this->feedFPupJ = *feedFPupJ;
	if (find(this->mask, FEEDFPUPSTE) && feedFPupSte) this->feedFPupSte = *feedFPupSte;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncFpjDetail::DpchEngData::getSrefsMask() {
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

void PnlFmncFpjDetail::DpchEngData::merge(
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

void PnlFmncFpjDetail::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncFpjDetailData");
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


