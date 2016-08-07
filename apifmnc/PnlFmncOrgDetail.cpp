/**
  * \file PnlFmncOrgDetail.cpp
  * API code for job PnlFmncOrgDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncOrgDetail.h"

/******************************************************************************
 class PnlFmncOrgDetail::VecVDo
 ******************************************************************************/

uint PnlFmncOrgDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butsaveclick") == 0) return BUTSAVECLICK;
	else if (s.compare("butjeditclick") == 0) return BUTJEDITCLICK;
	else if (s.compare("butadrviewclick") == 0) return BUTADRVIEWCLICK;
	else if (s.compare("butsupviewclick") == 0) return BUTSUPVIEWCLICK;

	return(0);
};

string PnlFmncOrgDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTJEDITCLICK) return("ButJEditClick");
	else if (ix == BUTADRVIEWCLICK) return("ButAdrViewClick");
	else if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");

	return("");
};

/******************************************************************************
 class PnlFmncOrgDetail::ContIac
 ******************************************************************************/

PnlFmncOrgDetail::ContIac::ContIac(
			const uint numFPupJ
			, const vector<uint>& numsFLstDrv
			, const string& TxfTel
			, const string& TxfEml
		) : Block() {
	this->numFPupJ = numFPupJ;
	this->numsFLstDrv = numsFLstDrv;
	this->TxfTel = TxfTel;
	this->TxfEml = TxfEml;

	mask = {NUMFPUPJ, NUMSFLSTDRV, TXFTEL, TXFEML};
};

bool PnlFmncOrgDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncOrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncOrgDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstDrv", numsFLstDrv)) add(NUMSFLSTDRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTel", TxfTel)) add(TXFTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEml", TxfEml)) add(TXFEML);
	};

	return basefound;
};

void PnlFmncOrgDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncOrgDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncOrgDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstDrv", numsFLstDrv);
		writeStringAttr(wr, itemtag, "sref", "TxfTel", TxfTel);
		writeStringAttr(wr, itemtag, "sref", "TxfEml", TxfEml);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncOrgDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (compareUintvec(numsFLstDrv, comp->numsFLstDrv)) insert(items, NUMSFLSTDRV);
	if (TxfTel.compare(comp->TxfTel) == 0) insert(items, TXFTEL);
	if (TxfEml.compare(comp->TxfEml) == 0) insert(items, TXFEML);

	return(items);
};

set<uint> PnlFmncOrgDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJ, NUMSFLSTDRV, TXFTEL, TXFEML};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncOrgDetail::ContInf
 ******************************************************************************/

PnlFmncOrgDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtDrv
			, const string& TxtAdr
			, const string& TxtSup
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtTit = TxtTit;
	this->TxtDrv = TxtDrv;
	this->TxtAdr = TxtAdr;
	this->TxtSup = TxtSup;

	mask = {TXTSRF, TXTTIT, TXTDRV, TXTADR, TXTSUP};
};

bool PnlFmncOrgDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncOrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncOrgDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTit", TxtTit)) add(TXTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDrv", TxtDrv)) add(TXTDRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAdr", TxtAdr)) add(TXTADR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
	};

	return basefound;
};

set<uint> PnlFmncOrgDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtTit.compare(comp->TxtTit) == 0) insert(items, TXTTIT);
	if (TxtDrv.compare(comp->TxtDrv) == 0) insert(items, TXTDRV);
	if (TxtAdr.compare(comp->TxtAdr) == 0) insert(items, TXTADR);
	if (TxtSup.compare(comp->TxtSup) == 0) insert(items, TXTSUP);

	return(items);
};

set<uint> PnlFmncOrgDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTDRV, TXTADR, TXTSUP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncOrgDetail::StatApp
 ******************************************************************************/

PnlFmncOrgDetail::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool LstDrvAlt
			, const uint LstDrvNumFirstdisp
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->LstDrvAlt = LstDrvAlt;
	this->LstDrvNumFirstdisp = LstDrvNumFirstdisp;

	mask = {IXFMNCVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP};
};

bool PnlFmncOrgDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncOrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncOrgDetail";

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

set<uint> PnlFmncOrgDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (LstDrvAlt == comp->LstDrvAlt) insert(items, LSTDRVALT);
	if (LstDrvNumFirstdisp == comp->LstDrvNumFirstdisp) insert(items, LSTDRVNUMFIRSTDISP);

	return(items);
};

set<uint> PnlFmncOrgDetail::StatApp::diff(
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
 class PnlFmncOrgDetail::StatShr
 ******************************************************************************/

PnlFmncOrgDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool ButJEditAvail
			, const bool ButAdrViewAvail
			, const bool ButSupViewAvail
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->ButJEditAvail = ButJEditAvail;
	this->ButAdrViewAvail = ButAdrViewAvail;
	this->ButSupViewAvail = ButSupViewAvail;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTJEDITAVAIL, BUTADRVIEWAVAIL, BUTSUPVIEWAVAIL};
};

bool PnlFmncOrgDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncOrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncOrgDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJEditAvail", ButJEditAvail)) add(BUTJEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAdrViewAvail", ButAdrViewAvail)) add(BUTADRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
	};

	return basefound;
};

set<uint> PnlFmncOrgDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (ButAdrViewAvail == comp->ButAdrViewAvail) insert(items, BUTADRVIEWAVAIL);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);

	return(items);
};

set<uint> PnlFmncOrgDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, BUTJEDITAVAIL, BUTADRVIEWAVAIL, BUTSUPVIEWAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncOrgDetail::Tag
 ******************************************************************************/

PnlFmncOrgDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptDrv
			, const string& CptAdr
			, const string& CptSup
			, const string& CptTel
			, const string& CptEml
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptDrv = CptDrv;
	this->CptAdr = CptAdr;
	this->CptSup = CptSup;
	this->CptTel = CptTel;
	this->CptEml = CptEml;

	mask = {CPT, CPTSRF, CPTTIT, CPTDRV, CPTADR, CPTSUP, CPTTEL, CPTEML};
};

bool PnlFmncOrgDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncOrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncOrgDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDrv", CptDrv)) add(CPTDRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAdr", CptAdr)) add(CPTADR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTel", CptTel)) add(CPTTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEml", CptEml)) add(CPTEML);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncOrgDetail::DpchAppData
 ******************************************************************************/

PnlFmncOrgDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCORGDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncOrgDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncOrgDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncOrgDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncOrgDetail::DpchAppDo
 ******************************************************************************/

PnlFmncOrgDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCORGDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncOrgDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncOrgDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncOrgDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncOrgDetail::DpchEngData
 ******************************************************************************/

PnlFmncOrgDetail::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCORGDETAILDATA) {
	feedFLstDrv.tag = "FeedFLstDrv";
	feedFPupJ.tag = "FeedFPupJ";
};

string PnlFmncOrgDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDRV)) ss.push_back("feedFLstDrv");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncOrgDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncOrgDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstDrv.readXML(docctx, basexpath, true)) add(FEEDFLSTDRV);
		if (feedFPupJ.readXML(docctx, basexpath, true)) add(FEEDFPUPJ);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstDrv.clear();
		feedFPupJ.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

