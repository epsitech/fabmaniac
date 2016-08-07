/**
  * \file PnlFmncAdrDetail_blks.cpp
  * job handler for job PnlFmncAdrDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncAdrDetail::VecVDo
 ******************************************************************************/

uint PnlFmncAdrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "buthkuviewclick") return BUTHKUVIEWCLICK;
	else if (s == "butatyeditclick") return BUTATYEDITCLICK;
	else if (s == "butcryeditclick") return BUTCRYEDITCLICK;

	return(0);
};

string PnlFmncAdrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	else if (ix == BUTATYEDITCLICK) return("ButAtyEditClick");
	else if (ix == BUTCRYEDITCLICK) return("ButCryEditClick");

	return("");
};

/******************************************************************************
 class PnlFmncAdrDetail::ContIac
 ******************************************************************************/

PnlFmncAdrDetail::ContIac::ContIac(
			const string& TxfAd1
			, const string& TxfCty
			, const string& TxfSta
			, const uint numFPupHkt
			, const uint numFPupAty
			, const string& TxfAty
			, const string& TxfAd2
			, const string& TxfZip
			, const string& TxfSte
			, const uint numFPupCry
			, const string& TxfCry
		) : Block() {
	this->TxfAd1 = TxfAd1;
	this->TxfCty = TxfCty;
	this->TxfSta = TxfSta;
	this->numFPupHkt = numFPupHkt;
	this->numFPupAty = numFPupAty;
	this->TxfAty = TxfAty;
	this->TxfAd2 = TxfAd2;
	this->TxfZip = TxfZip;
	this->TxfSte = TxfSte;
	this->numFPupCry = numFPupCry;
	this->TxfCry = TxfCry;

	mask = {TXFAD1, TXFCTY, TXFSTA, NUMFPUPHKT, NUMFPUPATY, TXFATY, TXFAD2, TXFZIP, TXFSTE, NUMFPUPCRY, TXFCRY};
};

bool PnlFmncAdrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncAdrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncAdrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAd1", TxfAd1)) add(TXFAD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCty", TxfCty)) add(TXFCTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAty", numFPupAty)) add(NUMFPUPATY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAty", TxfAty)) add(TXFATY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAd2", TxfAd2)) add(TXFAD2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfZip", TxfZip)) add(TXFZIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSte", TxfSte)) add(TXFSTE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCry", numFPupCry)) add(NUMFPUPCRY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCry", TxfCry)) add(TXFCRY);
	};

	return basefound;
};

void PnlFmncAdrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncAdrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncAdrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfAd1", TxfAd1);
		writeStringAttr(wr, itemtag, "sref", "TxfCty", TxfCty);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeUintAttr(wr, itemtag, "sref", "numFPupAty", numFPupAty);
		writeStringAttr(wr, itemtag, "sref", "TxfAty", TxfAty);
		writeStringAttr(wr, itemtag, "sref", "TxfAd2", TxfAd2);
		writeStringAttr(wr, itemtag, "sref", "TxfZip", TxfZip);
		writeStringAttr(wr, itemtag, "sref", "TxfSte", TxfSte);
		writeUintAttr(wr, itemtag, "sref", "numFPupCry", numFPupCry);
		writeStringAttr(wr, itemtag, "sref", "TxfCry", TxfCry);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncAdrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfAd1 == comp->TxfAd1) insert(items, TXFAD1);
	if (TxfCty == comp->TxfCty) insert(items, TXFCTY);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (numFPupAty == comp->numFPupAty) insert(items, NUMFPUPATY);
	if (TxfAty == comp->TxfAty) insert(items, TXFATY);
	if (TxfAd2 == comp->TxfAd2) insert(items, TXFAD2);
	if (TxfZip == comp->TxfZip) insert(items, TXFZIP);
	if (TxfSte == comp->TxfSte) insert(items, TXFSTE);
	if (numFPupCry == comp->numFPupCry) insert(items, NUMFPUPCRY);
	if (TxfCry == comp->TxfCry) insert(items, TXFCRY);

	return(items);
};

set<uint> PnlFmncAdrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFAD1, TXFCTY, TXFSTA, NUMFPUPHKT, NUMFPUPATY, TXFATY, TXFAD2, TXFZIP, TXFSTE, NUMFPUPCRY, TXFCRY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncAdrDetail::ContInf
 ******************************************************************************/

PnlFmncAdrDetail::ContInf::ContInf(
			const string& TxtHku
		) : Block() {
	this->TxtHku = TxtHku;

	mask = {TXTHKU};
};

void PnlFmncAdrDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncAdrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncAdrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtHku", TxtHku);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncAdrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtHku == comp->TxtHku) insert(items, TXTHKU);

	return(items);
};

set<uint> PnlFmncAdrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTHKU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncAdrDetail::StatApp
 ******************************************************************************/

void PnlFmncAdrDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
			, const bool PupAtyAlt
			, const bool PupCryAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncAdrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncAdrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupAtyAlt", PupAtyAlt);
		writeBoolAttr(wr, itemtag, "sref", "PupCryAlt", PupCryAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncAdrDetail::StatShr
 ******************************************************************************/

PnlFmncAdrDetail::StatShr::StatShr(
			const bool TxfAtyValid
			, const bool TxfCryValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButAtyEditAvail
			, const bool ButCryEditAvail
		) : Block() {
	this->TxfAtyValid = TxfAtyValid;
	this->TxfCryValid = TxfCryValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButAtyEditAvail = ButAtyEditAvail;
	this->ButCryEditAvail = ButCryEditAvail;

	mask = {TXFATYVALID, TXFCRYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTATYEDITAVAIL, BUTCRYEDITAVAIL};
};

void PnlFmncAdrDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncAdrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncAdrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfAtyValid", TxfAtyValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfCryValid", TxfCryValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButAtyEditAvail", ButAtyEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCryEditAvail", ButCryEditAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncAdrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfAtyValid == comp->TxfAtyValid) insert(items, TXFATYVALID);
	if (TxfCryValid == comp->TxfCryValid) insert(items, TXFCRYVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButAtyEditAvail == comp->ButAtyEditAvail) insert(items, BUTATYEDITAVAIL);
	if (ButCryEditAvail == comp->ButCryEditAvail) insert(items, BUTCRYEDITAVAIL);

	return(items);
};

set<uint> PnlFmncAdrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFATYVALID, TXFCRYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTATYEDITAVAIL, BUTCRYEDITAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncAdrDetail::Tag
 ******************************************************************************/

void PnlFmncAdrDetail::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncAdrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncAdrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptAd1", "Address1");
			writeStringAttr(wr, itemtag, "sref", "CptCty", "City");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "x1Startd");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "hook");
			writeStringAttr(wr, itemtag, "sref", "CptAty", "address type");
			writeStringAttr(wr, itemtag, "sref", "CptAd2", "Address2");
			writeStringAttr(wr, itemtag, "sref", "CptZip", "Zipcode");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "State");
			writeStringAttr(wr, itemtag, "sref", "CptCry", "country");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptAd1", "Address1");
			writeStringAttr(wr, itemtag, "sref", "CptCty", "City");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "x1Startd");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "Aufh\\u00e4nger");
			writeStringAttr(wr, itemtag, "sref", "CptAty", "Adresstyp");
			writeStringAttr(wr, itemtag, "sref", "CptAd2", "Address2");
			writeStringAttr(wr, itemtag, "sref", "CptZip", "Zipcode");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "State");
			writeStringAttr(wr, itemtag, "sref", "CptCry", "Land");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptAd1", "Address1");
			writeStringAttr(wr, itemtag, "sref", "CptCty", "City");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "x1Startd");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "attache");
			writeStringAttr(wr, itemtag, "sref", "CptAty", "type d'addresse");
			writeStringAttr(wr, itemtag, "sref", "CptAd2", "Address2");
			writeStringAttr(wr, itemtag, "sref", "CptZip", "Zipcode");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "State");
			writeStringAttr(wr, itemtag, "sref", "CptCry", "pays");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DETAIL, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncAdrDetail::DpchAppData
 ******************************************************************************/

PnlFmncAdrDetail::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCADRDETAILDATA) {
};

string PnlFmncAdrDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncAdrDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncAdrDetailData");
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
 class PnlFmncAdrDetail::DpchAppDo
 ******************************************************************************/

PnlFmncAdrDetail::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCADRDETAILDO) {
	ixVDo = 0;
};

string PnlFmncAdrDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncAdrDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncAdrDetailDo");
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
 class PnlFmncAdrDetail::DpchEngData
 ******************************************************************************/

PnlFmncAdrDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupAty
			, Feed* feedFPupCry
			, Feed* feedFPupHkt
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCADRDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPATY, FEEDFPUPCRY, FEEDFPUPHKT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPATY) && feedFPupAty) this->feedFPupAty = *feedFPupAty;
	if (find(this->mask, FEEDFPUPCRY) && feedFPupCry) this->feedFPupCry = *feedFPupCry;
	if (find(this->mask, FEEDFPUPHKT) && feedFPupHkt) this->feedFPupHkt = *feedFPupHkt;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncAdrDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPATY)) ss.push_back("feedFPupAty");
	if (has(FEEDFPUPCRY)) ss.push_back("feedFPupCry");
	if (has(FEEDFPUPHKT)) ss.push_back("feedFPupHkt");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncAdrDetail::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPATY)) {feedFPupAty = src->feedFPupAty; add(FEEDFPUPATY);};
	if (src->has(FEEDFPUPCRY)) {feedFPupCry = src->feedFPupCry; add(FEEDFPUPCRY);};
	if (src->has(FEEDFPUPHKT)) {feedFPupHkt = src->feedFPupHkt; add(FEEDFPUPHKT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncAdrDetail::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncAdrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPATY)) feedFPupAty.writeXML(wr);
		if (has(FEEDFPUPCRY)) feedFPupCry.writeXML(wr);
		if (has(FEEDFPUPHKT)) feedFPupHkt.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


