/**
  * \file PnlFmncArtDetail.cpp
  * API code for job PnlFmncArtDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncArtDetail.h"

/******************************************************************************
 class PnlFmncArtDetail::VecVDo
 ******************************************************************************/

uint PnlFmncArtDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butorgviewclick") == 0) return BUTORGVIEWCLICK;
	else if (s.compare("buttolviewclick") == 0) return BUTTOLVIEWCLICK;
	else if (s.compare("buttypeditclick") == 0) return BUTTYPEDITCLICK;

	return(0);
};

string PnlFmncArtDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTORGVIEWCLICK) return("ButOrgViewClick");
	else if (ix == BUTTOLVIEWCLICK) return("ButTolViewClick");
	else if (ix == BUTTYPEDITCLICK) return("ButTypEditClick");

	return("");
};

/******************************************************************************
 class PnlFmncArtDetail::ContIac
 ******************************************************************************/

PnlFmncArtDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupTyp
			, const string& TxfTyp
			, const string& TxfCmt
		) : Block() {
	this->TxfTit = TxfTit;
	this->numFPupTyp = numFPupTyp;
	this->TxfTyp = TxfTyp;
	this->TxfCmt = TxfCmt;

	mask = {TXFTIT, NUMFPUPTYP, TXFTYP, TXFCMT};
};

bool PnlFmncArtDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncArtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncArtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTyp", TxfTyp)) add(TXFTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlFmncArtDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncArtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncArtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfTyp", TxfTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncArtDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit.compare(comp->TxfTit) == 0) insert(items, TXFTIT);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfTyp.compare(comp->TxfTyp) == 0) insert(items, TXFTYP);
	if (TxfCmt.compare(comp->TxfCmt) == 0) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlFmncArtDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPTYP, TXFTYP, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncArtDetail::ContInf
 ******************************************************************************/

PnlFmncArtDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtOrg
			, const string& TxtTol
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtOrg = TxtOrg;
	this->TxtTol = TxtTol;

	mask = {TXTSRF, TXTORG, TXTTOL};
};

bool PnlFmncArtDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncArtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncArtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtOrg", TxtOrg)) add(TXTORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTol", TxtTol)) add(TXTTOL);
	};

	return basefound;
};

set<uint> PnlFmncArtDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtOrg.compare(comp->TxtOrg) == 0) insert(items, TXTORG);
	if (TxtTol.compare(comp->TxtTol) == 0) insert(items, TXTTOL);

	return(items);
};

set<uint> PnlFmncArtDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTORG, TXTTOL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncArtDetail::StatApp
 ******************************************************************************/

PnlFmncArtDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool PupTypAlt
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->PupTypAlt = PupTypAlt;

	mask = {IXFMNCVEXPSTATE, PUPTYPALT};
};

bool PnlFmncArtDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncArtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncArtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypAlt", PupTypAlt)) add(PUPTYPALT);
	};

	return basefound;
};

set<uint> PnlFmncArtDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (PupTypAlt == comp->PupTypAlt) insert(items, PUPTYPALT);

	return(items);
};

set<uint> PnlFmncArtDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, PUPTYPALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncArtDetail::StatShr
 ******************************************************************************/

PnlFmncArtDetail::StatShr::StatShr(
			const bool TxfTypValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButOrgViewAvail
			, const bool ButTolViewAvail
			, const bool ButTypEditAvail
		) : Block() {
	this->TxfTypValid = TxfTypValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButOrgViewAvail = ButOrgViewAvail;
	this->ButTolViewAvail = ButTolViewAvail;
	this->ButTypEditAvail = ButTypEditAvail;

	mask = {TXFTYPVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTORGVIEWAVAIL, BUTTOLVIEWAVAIL, BUTTYPEDITAVAIL};
};

bool PnlFmncArtDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncArtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncArtDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTypValid", TxfTypValid)) add(TXFTYPVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOrgViewAvail", ButOrgViewAvail)) add(BUTORGVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTolViewAvail", ButTolViewAvail)) add(BUTTOLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTypEditAvail", ButTypEditAvail)) add(BUTTYPEDITAVAIL);
	};

	return basefound;
};

set<uint> PnlFmncArtDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfTypValid == comp->TxfTypValid) insert(items, TXFTYPVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButOrgViewAvail == comp->ButOrgViewAvail) insert(items, BUTORGVIEWAVAIL);
	if (ButTolViewAvail == comp->ButTolViewAvail) insert(items, BUTTOLVIEWAVAIL);
	if (ButTypEditAvail == comp->ButTypEditAvail) insert(items, BUTTYPEDITAVAIL);

	return(items);
};

set<uint> PnlFmncArtDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTYPVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTORGVIEWAVAIL, BUTTOLVIEWAVAIL, BUTTYPEDITAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncArtDetail::Tag
 ******************************************************************************/

PnlFmncArtDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptOrg
			, const string& CptTol
			, const string& CptTyp
			, const string& CptCmt
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptOrg = CptOrg;
	this->CptTol = CptTol;
	this->CptTyp = CptTyp;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTTIT, CPTORG, CPTTOL, CPTTYP, CPTCMT};
};

bool PnlFmncArtDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncArtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncArtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOrg", CptOrg)) add(CPTORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTol", CptTol)) add(CPTTOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncArtDetail::DpchAppData
 ******************************************************************************/

PnlFmncArtDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCARTDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncArtDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncArtDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncArtDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncArtDetail::DpchAppDo
 ******************************************************************************/

PnlFmncArtDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCARTDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncArtDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncArtDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncArtDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncArtDetail::DpchEngData
 ******************************************************************************/

PnlFmncArtDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCARTDETAILDATA) {
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlFmncArtDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncArtDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncArtDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

