/**
  * \file PnlFmncSkiDetail.cpp
  * API code for job PnlFmncSkiDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncSkiDetail.h"

/******************************************************************************
 class PnlFmncSkiDetail::VecVDo
 ******************************************************************************/

uint PnlFmncSkiDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butorgviewclick") == 0) return BUTORGVIEWCLICK;
	else if (s.compare("butartviewclick") == 0) return BUTARTVIEWCLICK;
	else if (s.compare("butjeditclick") == 0) return BUTJEDITCLICK;
	else if (s.compare("butlcneditclick") == 0) return BUTLCNEDITCLICK;

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
	if (TxfLcn.compare(comp->TxfLcn) == 0) insert(items, TXFLCN);
	if (TxfExd.compare(comp->TxfExd) == 0) insert(items, TXFEXD);
	if (TxfCmt.compare(comp->TxfCmt) == 0) insert(items, TXFCMT);

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

bool PnlFmncSkiDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncSkiDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncSkiDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtOrg", TxtOrg)) add(TXTORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtArt", TxtArt)) add(TXTART);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtQty", TxtQty)) add(TXTQTY);
	};

	return basefound;
};

set<uint> PnlFmncSkiDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtOrg.compare(comp->TxtOrg) == 0) insert(items, TXTORG);
	if (TxtArt.compare(comp->TxtArt) == 0) insert(items, TXTART);
	if (TxtQty.compare(comp->TxtQty) == 0) insert(items, TXTQTY);

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

PnlFmncSkiDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool PupLcnAlt
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->PupLcnAlt = PupLcnAlt;

	mask = {IXFMNCVEXPSTATE, PUPLCNALT};
};

bool PnlFmncSkiDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncSkiDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncSkiDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupLcnAlt", PupLcnAlt)) add(PUPLCNALT);
	};

	return basefound;
};

set<uint> PnlFmncSkiDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (PupLcnAlt == comp->PupLcnAlt) insert(items, PUPLCNALT);

	return(items);
};

set<uint> PnlFmncSkiDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, PUPLCNALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlFmncSkiDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncSkiDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncSkiDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLcnValid", TxfLcnValid)) add(TXFLCNVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOrgViewAvail", ButOrgViewAvail)) add(BUTORGVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButArtViewAvail", ButArtViewAvail)) add(BUTARTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJEditAvail", ButJEditAvail)) add(BUTJEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLcnEditAvail", ButLcnEditAvail)) add(BUTLCNEDITAVAIL);
	};

	return basefound;
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

PnlFmncSkiDetail::Tag::Tag(
			const string& Cpt
			, const string& CptOrg
			, const string& CptArt
			, const string& CptQty
			, const string& CptLcn
			, const string& CptExd
			, const string& CptCmt
		) : Block() {
	this->Cpt = Cpt;
	this->CptOrg = CptOrg;
	this->CptArt = CptArt;
	this->CptQty = CptQty;
	this->CptLcn = CptLcn;
	this->CptExd = CptExd;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTORG, CPTART, CPTQTY, CPTLCN, CPTEXD, CPTCMT};
};

bool PnlFmncSkiDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncSkiDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncSkiDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOrg", CptOrg)) add(CPTORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptArt", CptArt)) add(CPTART);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptQty", CptQty)) add(CPTQTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLcn", CptLcn)) add(CPTLCN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptExd", CptExd)) add(CPTEXD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncSkiDetail::DpchAppData
 ******************************************************************************/

PnlFmncSkiDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSKIDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncSkiDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncSkiDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncSkiDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncSkiDetail::DpchAppDo
 ******************************************************************************/

PnlFmncSkiDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSKIDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncSkiDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncSkiDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncSkiDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncSkiDetail::DpchEngData
 ******************************************************************************/

PnlFmncSkiDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCSKIDETAILDATA) {
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupLcn.tag = "FeedFPupLcn";
};

string PnlFmncSkiDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlFmncSkiDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncSkiDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupJ.readXML(docctx, basexpath, true)) add(FEEDFPUPJ);
		if (feedFPupLcn.readXML(docctx, basexpath, true)) add(FEEDFPUPLCN);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupJ.clear();
		feedFPupLcn.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

