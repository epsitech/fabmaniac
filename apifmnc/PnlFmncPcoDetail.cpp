/**
  * \file PnlFmncPcoDetail.cpp
  * API code for job PnlFmncPcoDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncPcoDetail.h"

/******************************************************************************
 class PnlFmncPcoDetail::VecVDo
 ******************************************************************************/

uint PnlFmncPcoDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butpcoviewclick") == 0) return BUTPCOVIEWCLICK;
	else if (s.compare("butsplviewclick") == 0) return BUTSPLVIEWCLICK;
	else if (s.compare("butfilviewclick") == 0) return BUTFILVIEWCLICK;
	else if (s.compare("butjeditclick") == 0) return BUTJEDITCLICK;
	else if (s.compare("butpcpviewclick") == 0) return BUTPCPVIEWCLICK;

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

	if (TxfDat.compare(comp->TxfDat) == 0) insert(items, TXFDAT);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (TxfAmt.compare(comp->TxfAmt) == 0) insert(items, TXFAMT);
	if (TxfCmt.compare(comp->TxfCmt) == 0) insert(items, TXFCMT);

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

bool PnlFmncPcoDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncPcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncPcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPco", TxtPco)) add(TXTPCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSpl", TxtSpl)) add(TXTSPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFil", TxtFil)) add(TXTFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPcp", TxtPcp)) add(TXTPCP);
	};

	return basefound;
};

set<uint> PnlFmncPcoDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtPco.compare(comp->TxtPco) == 0) insert(items, TXTPCO);
	if (TxtSpl.compare(comp->TxtSpl) == 0) insert(items, TXTSPL);
	if (TxtFil.compare(comp->TxtFil) == 0) insert(items, TXTFIL);
	if (TxtPcp.compare(comp->TxtPcp) == 0) insert(items, TXTPCP);

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

PnlFmncPcoDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;

	mask = {IXFMNCVEXPSTATE};
};

bool PnlFmncPcoDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncPcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncPcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlFmncPcoDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);

	return(items);
};

set<uint> PnlFmncPcoDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlFmncPcoDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncPcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncPcoDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPcoViewAvail", ButPcoViewAvail)) add(BUTPCOVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSplViewAvail", ButSplViewAvail)) add(BUTSPLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewAvail", ButFilViewAvail)) add(BUTFILVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJEditAvail", ButJEditAvail)) add(BUTJEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPcpViewAvail", ButPcpViewAvail)) add(BUTPCPVIEWAVAIL);
	};

	return basefound;
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

PnlFmncPcoDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptDat
			, const string& CptPco
			, const string& CptSpl
			, const string& CptFil
			, const string& CptSte
			, const string& CptAmt
			, const string& CptPcp
			, const string& CptCmt
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptDat = CptDat;
	this->CptPco = CptPco;
	this->CptSpl = CptSpl;
	this->CptFil = CptFil;
	this->CptSte = CptSte;
	this->CptAmt = CptAmt;
	this->CptPcp = CptPcp;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTDAT, CPTPCO, CPTSPL, CPTFIL, CPTSTE, CPTAMT, CPTPCP, CPTCMT};
};

bool PnlFmncPcoDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncPcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncPcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDat", CptDat)) add(CPTDAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPco", CptPco)) add(CPTPCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSpl", CptSpl)) add(CPTSPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAmt", CptAmt)) add(CPTAMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPcp", CptPcp)) add(CPTPCP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncPcoDetail::DpchAppData
 ******************************************************************************/

PnlFmncPcoDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCPCODETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncPcoDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncPcoDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncPcoDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncPcoDetail::DpchAppDo
 ******************************************************************************/

PnlFmncPcoDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCPCODETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncPcoDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncPcoDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncPcoDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncPcoDetail::DpchEngData
 ******************************************************************************/

PnlFmncPcoDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCPCODETAILDATA) {
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
};

string PnlFmncPcoDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlFmncPcoDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncPcoDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupJ.readXML(docctx, basexpath, true)) add(FEEDFPUPJ);
		if (feedFPupSte.readXML(docctx, basexpath, true)) add(FEEDFPUPSTE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupJ.clear();
		feedFPupSte.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

