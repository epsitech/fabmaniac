/**
  * \file PnlFmncAdrDetail.cpp
  * API code for job PnlFmncAdrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncAdrDetail.h"

/******************************************************************************
 class PnlFmncAdrDetail::VecVDo
 ******************************************************************************/

uint PnlFmncAdrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("buthkuviewclick") == 0) return BUTHKUVIEWCLICK;
	else if (s.compare("butatyeditclick") == 0) return BUTATYEDITCLICK;
	else if (s.compare("butcryeditclick") == 0) return BUTCRYEDITCLICK;

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

	if (TxfAd1.compare(comp->TxfAd1) == 0) insert(items, TXFAD1);
	if (TxfCty.compare(comp->TxfCty) == 0) insert(items, TXFCTY);
	if (TxfSta.compare(comp->TxfSta) == 0) insert(items, TXFSTA);
	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (numFPupAty == comp->numFPupAty) insert(items, NUMFPUPATY);
	if (TxfAty.compare(comp->TxfAty) == 0) insert(items, TXFATY);
	if (TxfAd2.compare(comp->TxfAd2) == 0) insert(items, TXFAD2);
	if (TxfZip.compare(comp->TxfZip) == 0) insert(items, TXFZIP);
	if (TxfSte.compare(comp->TxfSte) == 0) insert(items, TXFSTE);
	if (numFPupCry == comp->numFPupCry) insert(items, NUMFPUPCRY);
	if (TxfCry.compare(comp->TxfCry) == 0) insert(items, TXFCRY);

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

bool PnlFmncAdrDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncAdrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncAdrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtHku", TxtHku)) add(TXTHKU);
	};

	return basefound;
};

set<uint> PnlFmncAdrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtHku.compare(comp->TxtHku) == 0) insert(items, TXTHKU);

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

PnlFmncAdrDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool PupAtyAlt
			, const bool PupCryAlt
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->PupAtyAlt = PupAtyAlt;
	this->PupCryAlt = PupCryAlt;

	mask = {IXFMNCVEXPSTATE, PUPATYALT, PUPCRYALT};
};

bool PnlFmncAdrDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncAdrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncAdrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAtyAlt", PupAtyAlt)) add(PUPATYALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupCryAlt", PupCryAlt)) add(PUPCRYALT);
	};

	return basefound;
};

set<uint> PnlFmncAdrDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (PupAtyAlt == comp->PupAtyAlt) insert(items, PUPATYALT);
	if (PupCryAlt == comp->PupCryAlt) insert(items, PUPCRYALT);

	return(items);
};

set<uint> PnlFmncAdrDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, PUPATYALT, PUPCRYALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlFmncAdrDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncAdrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncAdrDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAtyValid", TxfAtyValid)) add(TXFATYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCryValid", TxfCryValid)) add(TXFCRYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAtyEditAvail", ButAtyEditAvail)) add(BUTATYEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCryEditAvail", ButCryEditAvail)) add(BUTCRYEDITAVAIL);
	};

	return basefound;
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

PnlFmncAdrDetail::Tag::Tag(
			const string& Cpt
			, const string& CptAd1
			, const string& CptCty
			, const string& CptSta
			, const string& CptHku
			, const string& CptAty
			, const string& CptAd2
			, const string& CptZip
			, const string& CptSte
			, const string& CptCry
		) : Block() {
	this->Cpt = Cpt;
	this->CptAd1 = CptAd1;
	this->CptCty = CptCty;
	this->CptSta = CptSta;
	this->CptHku = CptHku;
	this->CptAty = CptAty;
	this->CptAd2 = CptAd2;
	this->CptZip = CptZip;
	this->CptSte = CptSte;
	this->CptCry = CptCry;

	mask = {CPT, CPTAD1, CPTCTY, CPTSTA, CPTHKU, CPTATY, CPTAD2, CPTZIP, CPTSTE, CPTCRY};
};

bool PnlFmncAdrDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncAdrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncAdrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAd1", CptAd1)) add(CPTAD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCty", CptCty)) add(CPTCTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHku", CptHku)) add(CPTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAty", CptAty)) add(CPTATY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAd2", CptAd2)) add(CPTAD2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptZip", CptZip)) add(CPTZIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCry", CptCry)) add(CPTCRY);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncAdrDetail::DpchAppData
 ******************************************************************************/

PnlFmncAdrDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCADRDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncAdrDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncAdrDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncAdrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncAdrDetail::DpchAppDo
 ******************************************************************************/

PnlFmncAdrDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCADRDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncAdrDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncAdrDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncAdrDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncAdrDetail::DpchEngData
 ******************************************************************************/

PnlFmncAdrDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCADRDETAILDATA) {
	feedFPupAty.tag = "FeedFPupAty";
	feedFPupCry.tag = "FeedFPupCry";
	feedFPupHkt.tag = "FeedFPupHkt";
};

string PnlFmncAdrDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlFmncAdrDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncAdrDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupAty.readXML(docctx, basexpath, true)) add(FEEDFPUPATY);
		if (feedFPupCry.readXML(docctx, basexpath, true)) add(FEEDFPUPCRY);
		if (feedFPupHkt.readXML(docctx, basexpath, true)) add(FEEDFPUPHKT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupAty.clear();
		feedFPupCry.clear();
		feedFPupHkt.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

