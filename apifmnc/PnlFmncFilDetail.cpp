/**
  * \file PnlFmncFilDetail.cpp
  * API code for job PnlFmncFilDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncFilDetail.h"

/******************************************************************************
 class PnlFmncFilDetail::VecVDo
 ******************************************************************************/

uint PnlFmncFilDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butcluviewclick") == 0) return BUTCLUVIEWCLICK;
	else if (s.compare("butcluclusterclick") == 0) return BUTCLUCLUSTERCLICK;
	else if (s.compare("butcluunclusterclick") == 0) return BUTCLUUNCLUSTERCLICK;
	else if (s.compare("butreuviewclick") == 0) return BUTREUVIEWCLICK;
	else if (s.compare("butcnteditclick") == 0) return BUTCNTEDITCLICK;
	else if (s.compare("butmimeditclick") == 0) return BUTMIMEDITCLICK;

	return(0);
};

string PnlFmncFilDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	else if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	else if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	else if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	else if (ix == BUTCNTEDITCLICK) return("ButCntEditClick");
	else if (ix == BUTMIMEDITCLICK) return("ButMimEditClick");

	return("");
};

/******************************************************************************
 class PnlFmncFilDetail::ContIac
 ******************************************************************************/

PnlFmncFilDetail::ContIac::ContIac(
			const string& TxfFnm
			, const uint numFLstClu
			, const uint numFPupRet
			, const uint numFPupCnt
			, const string& TxfCnt
			, const string& TxfAcv
			, const string& TxfAnm
			, const uint numFPupMim
			, const string& TxfMim
			, const string& TxfSiz
			, const string& TxfCmt
		) : Block() {
	this->TxfFnm = TxfFnm;
	this->numFLstClu = numFLstClu;
	this->numFPupRet = numFPupRet;
	this->numFPupCnt = numFPupCnt;
	this->TxfCnt = TxfCnt;
	this->TxfAcv = TxfAcv;
	this->TxfAnm = TxfAnm;
	this->numFPupMim = numFPupMim;
	this->TxfMim = TxfMim;
	this->TxfSiz = TxfSiz;
	this->TxfCmt = TxfCmt;

	mask = {TXFFNM, NUMFLSTCLU, NUMFPUPRET, NUMFPUPCNT, TXFCNT, TXFACV, TXFANM, NUMFPUPMIM, TXFMIM, TXFSIZ, TXFCMT};
};

bool PnlFmncFilDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncFilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCnt", numFPupCnt)) add(NUMFPUPCNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCnt", TxfCnt)) add(TXFCNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAcv", TxfAcv)) add(TXFACV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAnm", TxfAnm)) add(TXFANM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMim", numFPupMim)) add(NUMFPUPMIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMim", TxfMim)) add(TXFMIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSiz", TxfSiz)) add(TXFSIZ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlFmncFilDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncFilDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncFilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFPupCnt", numFPupCnt);
		writeStringAttr(wr, itemtag, "sref", "TxfCnt", TxfCnt);
		writeStringAttr(wr, itemtag, "sref", "TxfAcv", TxfAcv);
		writeStringAttr(wr, itemtag, "sref", "TxfAnm", TxfAnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupMim", numFPupMim);
		writeStringAttr(wr, itemtag, "sref", "TxfMim", TxfMim);
		writeStringAttr(wr, itemtag, "sref", "TxfSiz", TxfSiz);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncFilDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfFnm.compare(comp->TxfFnm) == 0) insert(items, TXFFNM);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFPupCnt == comp->numFPupCnt) insert(items, NUMFPUPCNT);
	if (TxfCnt.compare(comp->TxfCnt) == 0) insert(items, TXFCNT);
	if (TxfAcv.compare(comp->TxfAcv) == 0) insert(items, TXFACV);
	if (TxfAnm.compare(comp->TxfAnm) == 0) insert(items, TXFANM);
	if (numFPupMim == comp->numFPupMim) insert(items, NUMFPUPMIM);
	if (TxfMim.compare(comp->TxfMim) == 0) insert(items, TXFMIM);
	if (TxfSiz.compare(comp->TxfSiz) == 0) insert(items, TXFSIZ);
	if (TxfCmt.compare(comp->TxfCmt) == 0) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlFmncFilDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFNM, NUMFLSTCLU, NUMFPUPRET, NUMFPUPCNT, TXFCNT, TXFACV, TXFANM, NUMFPUPMIM, TXFMIM, TXFSIZ, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncFilDetail::ContInf
 ******************************************************************************/

PnlFmncFilDetail::ContInf::ContInf(
			const string& TxtClu
			, const string& TxtReu
		) : Block() {
	this->TxtClu = TxtClu;
	this->TxtReu = TxtReu;

	mask = {TXTCLU, TXTREU};
};

bool PnlFmncFilDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncFilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
	};

	return basefound;
};

set<uint> PnlFmncFilDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtClu.compare(comp->TxtClu) == 0) insert(items, TXTCLU);
	if (TxtReu.compare(comp->TxtReu) == 0) insert(items, TXTREU);

	return(items);
};

set<uint> PnlFmncFilDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCLU, TXTREU};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncFilDetail::StatApp
 ******************************************************************************/

PnlFmncFilDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool LstCluAlt
			, const bool PupCntAlt
			, const bool PupMimAlt
			, const uint LstCluNumFirstdisp
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->PupCntAlt = PupCntAlt;
	this->PupMimAlt = PupMimAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;

	mask = {IXFMNCVEXPSTATE, LSTCLUALT, PUPCNTALT, PUPMIMALT, LSTCLUNUMFIRSTDISP};
};

bool PnlFmncFilDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncFilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupCntAlt", PupCntAlt)) add(PUPCNTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupMimAlt", PupMimAlt)) add(PUPMIMALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlFmncFilDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (PupCntAlt == comp->PupCntAlt) insert(items, PUPCNTALT);
	if (PupMimAlt == comp->PupMimAlt) insert(items, PUPMIMALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlFmncFilDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, LSTCLUALT, PUPCNTALT, PUPMIMALT, LSTCLUNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncFilDetail::StatShr
 ******************************************************************************/

PnlFmncFilDetail::StatShr::StatShr(
			const bool TxfCntValid
			, const bool TxfMimValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool ButCntEditAvail
			, const bool ButMimEditAvail
		) : Block() {
	this->TxfCntValid = TxfCntValid;
	this->TxfMimValid = TxfMimValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->ButCntEditAvail = ButCntEditAvail;
	this->ButMimEditAvail = ButMimEditAvail;

	mask = {TXFCNTVALID, TXFMIMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, BUTCNTEDITAVAIL, BUTMIMEDITAVAIL};
};

bool PnlFmncFilDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncFilDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCntValid", TxfCntValid)) add(TXFCNTVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMimValid", TxfMimValid)) add(TXFMIMVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCntEditAvail", ButCntEditAvail)) add(BUTCNTEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMimEditAvail", ButMimEditAvail)) add(BUTMIMEDITAVAIL);
	};

	return basefound;
};

set<uint> PnlFmncFilDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfCntValid == comp->TxfCntValid) insert(items, TXFCNTVALID);
	if (TxfMimValid == comp->TxfMimValid) insert(items, TXFMIMVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (ButCntEditAvail == comp->ButCntEditAvail) insert(items, BUTCNTEDITAVAIL);
	if (ButMimEditAvail == comp->ButMimEditAvail) insert(items, BUTMIMEDITAVAIL);

	return(items);
};

set<uint> PnlFmncFilDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCNTVALID, TXFMIMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, BUTCNTEDITAVAIL, BUTMIMEDITAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncFilDetail::Tag
 ******************************************************************************/

PnlFmncFilDetail::Tag::Tag(
			const string& Cpt
			, const string& CptFnm
			, const string& CptClu
			, const string& CptReu
			, const string& CptCnt
			, const string& CptAcv
			, const string& CptAnm
			, const string& CptMim
			, const string& CptSiz
			, const string& CptCmt
		) : Block() {
	this->Cpt = Cpt;
	this->CptFnm = CptFnm;
	this->CptClu = CptClu;
	this->CptReu = CptReu;
	this->CptCnt = CptCnt;
	this->CptAcv = CptAcv;
	this->CptAnm = CptAnm;
	this->CptMim = CptMim;
	this->CptSiz = CptSiz;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTFNM, CPTCLU, CPTREU, CPTCNT, CPTACV, CPTANM, CPTMIM, CPTSIZ, CPTCMT};
};

bool PnlFmncFilDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncFilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFnm", CptFnm)) add(CPTFNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCnt", CptCnt)) add(CPTCNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAcv", CptAcv)) add(CPTACV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAnm", CptAnm)) add(CPTANM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMim", CptMim)) add(CPTMIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSiz", CptSiz)) add(CPTSIZ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncFilDetail::DpchAppData
 ******************************************************************************/

PnlFmncFilDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCFILDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncFilDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncFilDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncFilDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncFilDetail::DpchAppDo
 ******************************************************************************/

PnlFmncFilDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCFILDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncFilDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncFilDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncFilDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncFilDetail::DpchEngData
 ******************************************************************************/

PnlFmncFilDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCFILDETAILDATA) {
	feedFLstClu.tag = "FeedFLstClu";
	feedFPupCnt.tag = "FeedFPupCnt";
	feedFPupMim.tag = "FeedFPupMim";
	feedFPupRet.tag = "FeedFPupRet";
};

string PnlFmncFilDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPCNT)) ss.push_back("feedFPupCnt");
	if (has(FEEDFPUPMIM)) ss.push_back("feedFPupMim");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncFilDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncFilDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFPupCnt.readXML(docctx, basexpath, true)) add(FEEDFPUPCNT);
		if (feedFPupMim.readXML(docctx, basexpath, true)) add(FEEDFPUPMIM);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFPupCnt.clear();
		feedFPupMim.clear();
		feedFPupRet.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

