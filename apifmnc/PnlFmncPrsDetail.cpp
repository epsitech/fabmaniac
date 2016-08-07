/**
  * \file PnlFmncPrsDetail.cpp
  * API code for job PnlFmncPrsDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncPrsDetail.h"

/******************************************************************************
 class PnlFmncPrsDetail::VecVDo
 ******************************************************************************/

uint PnlFmncPrsDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butjeditclick") == 0) return BUTJEDITCLICK;
	else if (s.compare("butorgviewclick") == 0) return BUTORGVIEWCLICK;
	else if (s.compare("butadrviewclick") == 0) return BUTADRVIEWCLICK;

	return(0);
};

string PnlFmncPrsDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTJEDITCLICK) return("ButJEditClick");
	else if (ix == BUTORGVIEWCLICK) return("ButOrgViewClick");
	else if (ix == BUTADRVIEWCLICK) return("ButAdrViewClick");

	return("");
};

/******************************************************************************
 class PnlFmncPrsDetail::ContIac
 ******************************************************************************/

PnlFmncPrsDetail::ContIac::ContIac(
			const string& TxfTit
			, const string& TxfFnm
			, const uint numFPupJ
			, const vector<uint>& numsFLstDrv
			, const uint numFPupSex
			, const string& TxfTel
			, const string& TxfEml
			, const string& TxfSal
		) : Block() {
	this->TxfTit = TxfTit;
	this->TxfFnm = TxfFnm;
	this->numFPupJ = numFPupJ;
	this->numsFLstDrv = numsFLstDrv;
	this->numFPupSex = numFPupSex;
	this->TxfTel = TxfTel;
	this->TxfEml = TxfEml;
	this->TxfSal = TxfSal;

	mask = {TXFTIT, TXFFNM, NUMFPUPJ, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
};

bool PnlFmncPrsDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstDrv", numsFLstDrv)) add(NUMSFLSTDRV);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSex", numFPupSex)) add(NUMFPUPSEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTel", TxfTel)) add(TXFTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEml", TxfEml)) add(TXFEML);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSal", TxfSal)) add(TXFSAL);
	};

	return basefound;
};

void PnlFmncPrsDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstDrv", numsFLstDrv);
		writeUintAttr(wr, itemtag, "sref", "numFPupSex", numFPupSex);
		writeStringAttr(wr, itemtag, "sref", "TxfTel", TxfTel);
		writeStringAttr(wr, itemtag, "sref", "TxfEml", TxfEml);
		writeStringAttr(wr, itemtag, "sref", "TxfSal", TxfSal);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncPrsDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit.compare(comp->TxfTit) == 0) insert(items, TXFTIT);
	if (TxfFnm.compare(comp->TxfFnm) == 0) insert(items, TXFFNM);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (compareUintvec(numsFLstDrv, comp->numsFLstDrv)) insert(items, NUMSFLSTDRV);
	if (numFPupSex == comp->numFPupSex) insert(items, NUMFPUPSEX);
	if (TxfTel.compare(comp->TxfTel) == 0) insert(items, TXFTEL);
	if (TxfEml.compare(comp->TxfEml) == 0) insert(items, TXFEML);
	if (TxfSal.compare(comp->TxfSal) == 0) insert(items, TXFSAL);

	return(items);
};

set<uint> PnlFmncPrsDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, TXFFNM, NUMFPUPJ, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPrsDetail::ContInf
 ******************************************************************************/

PnlFmncPrsDetail::ContInf::ContInf(
			const string& TxtLnm
			, const string& TxtDrv
			, const string& TxtOrg
			, const string& TxtAdr
		) : Block() {
	this->TxtLnm = TxtLnm;
	this->TxtDrv = TxtDrv;
	this->TxtOrg = TxtOrg;
	this->TxtAdr = TxtAdr;

	mask = {TXTLNM, TXTDRV, TXTORG, TXTADR};
};

bool PnlFmncPrsDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLnm", TxtLnm)) add(TXTLNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDrv", TxtDrv)) add(TXTDRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtOrg", TxtOrg)) add(TXTORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAdr", TxtAdr)) add(TXTADR);
	};

	return basefound;
};

set<uint> PnlFmncPrsDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtLnm.compare(comp->TxtLnm) == 0) insert(items, TXTLNM);
	if (TxtDrv.compare(comp->TxtDrv) == 0) insert(items, TXTDRV);
	if (TxtOrg.compare(comp->TxtOrg) == 0) insert(items, TXTORG);
	if (TxtAdr.compare(comp->TxtAdr) == 0) insert(items, TXTADR);

	return(items);
};

set<uint> PnlFmncPrsDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTLNM, TXTDRV, TXTORG, TXTADR};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPrsDetail::StatApp
 ******************************************************************************/

PnlFmncPrsDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool LstDrvAlt
			, const uint LstDrvNumFirstdisp
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->LstDrvAlt = LstDrvAlt;
	this->LstDrvNumFirstdisp = LstDrvNumFirstdisp;

	mask = {IXFMNCVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP};
};

bool PnlFmncPrsDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDrvAlt", LstDrvAlt)) add(LSTDRVALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDrvNumFirstdisp", LstDrvNumFirstdisp)) add(LSTDRVNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlFmncPrsDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (LstDrvAlt == comp->LstDrvAlt) insert(items, LSTDRVALT);
	if (LstDrvNumFirstdisp == comp->LstDrvNumFirstdisp) insert(items, LSTDRVNUMFIRSTDISP);

	return(items);
};

set<uint> PnlFmncPrsDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPrsDetail::StatShr
 ******************************************************************************/

PnlFmncPrsDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButJEditAvail
			, const bool ButOrgViewAvail
			, const bool ButAdrViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButJEditAvail = ButJEditAvail;
	this->ButOrgViewAvail = ButOrgViewAvail;
	this->ButAdrViewAvail = ButAdrViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTJEDITAVAIL, BUTORGVIEWAVAIL, BUTADRVIEWAVAIL};
};

bool PnlFmncPrsDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncPrsDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJEditAvail", ButJEditAvail)) add(BUTJEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOrgViewAvail", ButOrgViewAvail)) add(BUTORGVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAdrViewAvail", ButAdrViewAvail)) add(BUTADRVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlFmncPrsDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (ButOrgViewAvail == comp->ButOrgViewAvail) insert(items, BUTORGVIEWAVAIL);
	if (ButAdrViewAvail == comp->ButAdrViewAvail) insert(items, BUTADRVIEWAVAIL);

	return(items);
};

set<uint> PnlFmncPrsDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTJEDITAVAIL, BUTORGVIEWAVAIL, BUTADRVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPrsDetail::Tag
 ******************************************************************************/

PnlFmncPrsDetail::Tag::Tag(
			const string& Cpt
			, const string& CptTit
			, const string& CptFnm
			, const string& CptLnm
			, const string& CptDrv
			, const string& CptOrg
			, const string& CptAdr
			, const string& CptSex
			, const string& CptTel
			, const string& CptEml
			, const string& CptSal
		) : Block() {
	this->Cpt = Cpt;
	this->CptTit = CptTit;
	this->CptFnm = CptFnm;
	this->CptLnm = CptLnm;
	this->CptDrv = CptDrv;
	this->CptOrg = CptOrg;
	this->CptAdr = CptAdr;
	this->CptSex = CptSex;
	this->CptTel = CptTel;
	this->CptEml = CptEml;
	this->CptSal = CptSal;

	mask = {CPT, CPTTIT, CPTFNM, CPTLNM, CPTDRV, CPTORG, CPTADR, CPTSEX, CPTTEL, CPTEML, CPTSAL};
};

bool PnlFmncPrsDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFnm", CptFnm)) add(CPTFNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLnm", CptLnm)) add(CPTLNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDrv", CptDrv)) add(CPTDRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOrg", CptOrg)) add(CPTORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAdr", CptAdr)) add(CPTADR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSex", CptSex)) add(CPTSEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTel", CptTel)) add(CPTTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEml", CptEml)) add(CPTEML);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSal", CptSal)) add(CPTSAL);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncPrsDetail::DpchAppData
 ******************************************************************************/

PnlFmncPrsDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCPRSDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncPrsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncPrsDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncPrsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncPrsDetail::DpchAppDo
 ******************************************************************************/

PnlFmncPrsDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCPRSDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncPrsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncPrsDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncPrsDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncPrsDetail::DpchEngData
 ******************************************************************************/

PnlFmncPrsDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCPRSDETAILDATA) {
	feedFLstDrv.tag = "FeedFLstDrv";
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSex.tag = "FeedFPupSex";
};

string PnlFmncPrsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDRV)) ss.push_back("feedFLstDrv");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(FEEDFPUPSEX)) ss.push_back("feedFPupSex");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncPrsDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncPrsDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstDrv.readXML(docctx, basexpath, true)) add(FEEDFLSTDRV);
		if (feedFPupJ.readXML(docctx, basexpath, true)) add(FEEDFPUPJ);
		if (feedFPupSex.readXML(docctx, basexpath, true)) add(FEEDFPUPSEX);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstDrv.clear();
		feedFPupJ.clear();
		feedFPupSex.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

