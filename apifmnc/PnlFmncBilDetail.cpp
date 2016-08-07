/**
  * \file PnlFmncBilDetail.cpp
  * API code for job PnlFmncBilDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncBilDetail.h"

/******************************************************************************
 class PnlFmncBilDetail::VecVDo
 ******************************************************************************/

uint PnlFmncBilDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butprjviewclick") == 0) return BUTPRJVIEWCLICK;
	else if (s.compare("butfilviewclick") == 0) return BUTFILVIEWCLICK;
	else if (s.compare("butjeditclick") == 0) return BUTJEDITCLICK;

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

	if (TxfDat.compare(comp->TxfDat) == 0) insert(items, TXFDAT);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (TxfPra.compare(comp->TxfPra) == 0) insert(items, TXFPRA);
	if (TxfPro.compare(comp->TxfPro) == 0) insert(items, TXFPRO);
	if (TxfAmt.compare(comp->TxfAmt) == 0) insert(items, TXFAMT);
	if (TxfCmt.compare(comp->TxfCmt) == 0) insert(items, TXFCMT);

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

bool PnlFmncBilDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncBilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncBilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrj", TxtPrj)) add(TXTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFil", TxtFil)) add(TXTFIL);
	};

	return basefound;
};

set<uint> PnlFmncBilDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtPrj.compare(comp->TxtPrj) == 0) insert(items, TXTPRJ);
	if (TxtFil.compare(comp->TxtFil) == 0) insert(items, TXTFIL);

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

PnlFmncBilDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;

	mask = {IXFMNCVEXPSTATE};
};

bool PnlFmncBilDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncBilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncBilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlFmncBilDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);

	return(items);
};

set<uint> PnlFmncBilDetail::StatApp::diff(
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

bool PnlFmncBilDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncBilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncBilDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewAvail", ButPrjViewAvail)) add(BUTPRJVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewAvail", ButFilViewAvail)) add(BUTFILVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJEditAvail", ButJEditAvail)) add(BUTJEDITAVAIL);
	};

	return basefound;
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

PnlFmncBilDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptDat
			, const string& CptPrj
			, const string& CptFil
			, const string& CptSte
			, const string& CptPra
			, const string& CptPro
			, const string& CptAmt
			, const string& CptCmt
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptDat = CptDat;
	this->CptPrj = CptPrj;
	this->CptFil = CptFil;
	this->CptSte = CptSte;
	this->CptPra = CptPra;
	this->CptPro = CptPro;
	this->CptAmt = CptAmt;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTDAT, CPTPRJ, CPTFIL, CPTSTE, CPTPRA, CPTPRO, CPTAMT, CPTCMT};
};

bool PnlFmncBilDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncBilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncBilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDat", CptDat)) add(CPTDAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPra", CptPra)) add(CPTPRA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPro", CptPro)) add(CPTPRO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAmt", CptAmt)) add(CPTAMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncBilDetail::DpchAppData
 ******************************************************************************/

PnlFmncBilDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCBILDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncBilDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncBilDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncBilDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncBilDetail::DpchAppDo
 ******************************************************************************/

PnlFmncBilDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCBILDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncBilDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncBilDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncBilDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncBilDetail::DpchEngData
 ******************************************************************************/

PnlFmncBilDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCBILDETAILDATA) {
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSte.tag = "FeedFPupSte";
};

string PnlFmncBilDetail::DpchEngData::getSrefsMask() {
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

void PnlFmncBilDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncBilDetailData");
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

