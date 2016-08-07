/**
  * \file PnlFmncSepDetail.cpp
  * API code for job PnlFmncSepDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncSepDetail.h"

/******************************************************************************
 class PnlFmncSepDetail::VecVDo
 ******************************************************************************/

uint PnlFmncSepDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butactviewclick") == 0) return BUTACTVIEWCLICK;
	else if (s.compare("butrluviewclick") == 0) return BUTRLUVIEWCLICK;
	else if (s.compare("butprsviewclick") == 0) return BUTPRSVIEWCLICK;

	return(0);
};

string PnlFmncSepDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTACTVIEWCLICK) return("ButActViewClick");
	else if (ix == BUTRLUVIEWCLICK) return("ButRluViewClick");
	else if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");

	return("");
};

/******************************************************************************
 class PnlFmncSepDetail::ContIac
 ******************************************************************************/

PnlFmncSepDetail::ContIac::ContIac(
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

bool PnlFmncSepDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncSepDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncSepDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRlt", numFPupRlt)) add(NUMFPUPRLT);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstFcf", numsFLstFcf)) add(NUMSFLSTFCF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
	};

	return basefound;
};

void PnlFmncSepDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncSepDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncSepDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupRlt", numFPupRlt);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstFcf", numsFLstFcf);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncSepDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit.compare(comp->TxfTit) == 0) insert(items, TXFTIT);
	if (numFPupRlt == comp->numFPupRlt) insert(items, NUMFPUPRLT);
	if (compareUintvec(numsFLstFcf, comp->numsFLstFcf)) insert(items, NUMSFLSTFCF);
	if (TxfSta.compare(comp->TxfSta) == 0) insert(items, TXFSTA);

	return(items);
};

set<uint> PnlFmncSepDetail::ContIac::diff(
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
 class PnlFmncSepDetail::ContInf
 ******************************************************************************/

PnlFmncSepDetail::ContInf::ContInf(
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

bool PnlFmncSepDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncSepDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncSepDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAct", TxtAct)) add(TXTACT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRlu", TxtRlu)) add(TXTRLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtStp", TxtStp)) add(TXTSTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFcf", TxtFcf)) add(TXTFCF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrs", TxtPrs)) add(TXTPRS);
	};

	return basefound;
};

set<uint> PnlFmncSepDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtAct.compare(comp->TxtAct) == 0) insert(items, TXTACT);
	if (TxtRlu.compare(comp->TxtRlu) == 0) insert(items, TXTRLU);
	if (TxtStp.compare(comp->TxtStp) == 0) insert(items, TXTSTP);
	if (TxtFcf.compare(comp->TxtFcf) == 0) insert(items, TXTFCF);
	if (TxtPrs.compare(comp->TxtPrs) == 0) insert(items, TXTPRS);

	return(items);
};

set<uint> PnlFmncSepDetail::ContInf::diff(
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
 class PnlFmncSepDetail::StatApp
 ******************************************************************************/

PnlFmncSepDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool LstFcfAlt
			, const uint LstFcfNumFirstdisp
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->LstFcfAlt = LstFcfAlt;
	this->LstFcfNumFirstdisp = LstFcfNumFirstdisp;

	mask = {IXFMNCVEXPSTATE, LSTFCFALT, LSTFCFNUMFIRSTDISP};
};

bool PnlFmncSepDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncSepDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncSepDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFcfAlt", LstFcfAlt)) add(LSTFCFALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFcfNumFirstdisp", LstFcfNumFirstdisp)) add(LSTFCFNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlFmncSepDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (LstFcfAlt == comp->LstFcfAlt) insert(items, LSTFCFALT);
	if (LstFcfNumFirstdisp == comp->LstFcfNumFirstdisp) insert(items, LSTFCFNUMFIRSTDISP);

	return(items);
};

set<uint> PnlFmncSepDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, LSTFCFALT, LSTFCFNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncSepDetail::StatShr
 ******************************************************************************/

PnlFmncSepDetail::StatShr::StatShr(
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

bool PnlFmncSepDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncSepDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncSepDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButActViewAvail", ButActViewAvail)) add(BUTACTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrsViewAvail", ButPrsViewAvail)) add(BUTPRSVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlFmncSepDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButActViewAvail == comp->ButActViewAvail) insert(items, BUTACTVIEWAVAIL);
	if (ButPrsViewAvail == comp->ButPrsViewAvail) insert(items, BUTPRSVIEWAVAIL);

	return(items);
};

set<uint> PnlFmncSepDetail::StatShr::diff(
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
 class PnlFmncSepDetail::Tag
 ******************************************************************************/

PnlFmncSepDetail::Tag::Tag(
			const string& Cpt
			, const string& CptTit
			, const string& CptAct
			, const string& CptRlu
			, const string& CptStp
			, const string& CptFcf
			, const string& CptSta
			, const string& CptPrs
		) : Block() {
	this->Cpt = Cpt;
	this->CptTit = CptTit;
	this->CptAct = CptAct;
	this->CptRlu = CptRlu;
	this->CptStp = CptStp;
	this->CptFcf = CptFcf;
	this->CptSta = CptSta;
	this->CptPrs = CptPrs;

	mask = {CPT, CPTTIT, CPTACT, CPTRLU, CPTSTP, CPTFCF, CPTSTA, CPTPRS};
};

bool PnlFmncSepDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncSepDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncSepDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAct", CptAct)) add(CPTACT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRlu", CptRlu)) add(CPTRLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStp", CptStp)) add(CPTSTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFcf", CptFcf)) add(CPTFCF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrs", CptPrs)) add(CPTPRS);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncSepDetail::DpchAppData
 ******************************************************************************/

PnlFmncSepDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSEPDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncSepDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncSepDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncSepDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncSepDetail::DpchAppDo
 ******************************************************************************/

PnlFmncSepDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCSEPDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncSepDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncSepDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncSepDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncSepDetail::DpchEngData
 ******************************************************************************/

PnlFmncSepDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCSEPDETAILDATA) {
	feedFLstFcf.tag = "FeedFLstFcf";
	feedFPupRlt.tag = "FeedFPupRlt";
};

string PnlFmncSepDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlFmncSepDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncSepDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstFcf.readXML(docctx, basexpath, true)) add(FEEDFLSTFCF);
		if (feedFPupRlt.readXML(docctx, basexpath, true)) add(FEEDFPUPRLT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstFcf.clear();
		feedFPupRlt.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

