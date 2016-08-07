/**
  * \file PnlFmncNavSupply.cpp
  * API code for job PnlFmncNavSupply (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncNavSupply.h"

/******************************************************************************
 class PnlFmncNavSupply::VecVDo
 ******************************************************************************/

uint PnlFmncNavSupply::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butartviewclick") == 0) return BUTARTVIEWCLICK;
	else if (s.compare("butartnewcrdclick") == 0) return BUTARTNEWCRDCLICK;
	else if (s.compare("butskiviewclick") == 0) return BUTSKIVIEWCLICK;
	else if (s.compare("butskinewcrdclick") == 0) return BUTSKINEWCRDCLICK;
	else if (s.compare("butpcoviewclick") == 0) return BUTPCOVIEWCLICK;
	else if (s.compare("butpconewcrdclick") == 0) return BUTPCONEWCRDCLICK;

	return(0);
};

string PnlFmncNavSupply::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTARTVIEWCLICK) return("ButArtViewClick");
	else if (ix == BUTARTNEWCRDCLICK) return("ButArtNewcrdClick");
	else if (ix == BUTSKIVIEWCLICK) return("ButSkiViewClick");
	else if (ix == BUTSKINEWCRDCLICK) return("ButSkiNewcrdClick");
	else if (ix == BUTPCOVIEWCLICK) return("ButPcoViewClick");
	else if (ix == BUTPCONEWCRDCLICK) return("ButPcoNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlFmncNavSupply::ContIac
 ******************************************************************************/

PnlFmncNavSupply::ContIac::ContIac(
			const uint numFLstArt
			, const uint numFLstSki
			, const uint numFLstPco
		) : Block() {
	this->numFLstArt = numFLstArt;
	this->numFLstSki = numFLstSki;
	this->numFLstPco = numFLstPco;

	mask = {NUMFLSTART, NUMFLSTSKI, NUMFLSTPCO};
};

bool PnlFmncNavSupply::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncNavSupply");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncNavSupply";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstArt", numFLstArt)) add(NUMFLSTART);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSki", numFLstSki)) add(NUMFLSTSKI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPco", numFLstPco)) add(NUMFLSTPCO);
	};

	return basefound;
};

void PnlFmncNavSupply::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncNavSupply";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncNavSupply";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstArt", numFLstArt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSki", numFLstSki);
		writeUintAttr(wr, itemtag, "sref", "numFLstPco", numFLstPco);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavSupply::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstArt == comp->numFLstArt) insert(items, NUMFLSTART);
	if (numFLstSki == comp->numFLstSki) insert(items, NUMFLSTSKI);
	if (numFLstPco == comp->numFLstPco) insert(items, NUMFLSTPCO);

	return(items);
};

set<uint> PnlFmncNavSupply::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTART, NUMFLSTSKI, NUMFLSTPCO};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavSupply::StatApp
 ******************************************************************************/

PnlFmncNavSupply::StatApp::StatApp(
			const uint ixFmncVExpstate
			, const bool LstArtAlt
			, const bool LstSkiAlt
			, const bool LstPcoAlt
			, const uint LstArtNumFirstdisp
			, const uint LstSkiNumFirstdisp
			, const uint LstPcoNumFirstdisp
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->LstArtAlt = LstArtAlt;
	this->LstSkiAlt = LstSkiAlt;
	this->LstPcoAlt = LstPcoAlt;
	this->LstArtNumFirstdisp = LstArtNumFirstdisp;
	this->LstSkiNumFirstdisp = LstSkiNumFirstdisp;
	this->LstPcoNumFirstdisp = LstPcoNumFirstdisp;

	mask = {IXFMNCVEXPSTATE, LSTARTALT, LSTSKIALT, LSTPCOALT, LSTARTNUMFIRSTDISP, LSTSKINUMFIRSTDISP, LSTPCONUMFIRSTDISP};
};

bool PnlFmncNavSupply::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncNavSupply");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncNavSupply";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstArtAlt", LstArtAlt)) add(LSTARTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSkiAlt", LstSkiAlt)) add(LSTSKIALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPcoAlt", LstPcoAlt)) add(LSTPCOALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstArtNumFirstdisp", LstArtNumFirstdisp)) add(LSTARTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSkiNumFirstdisp", LstSkiNumFirstdisp)) add(LSTSKINUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPcoNumFirstdisp", LstPcoNumFirstdisp)) add(LSTPCONUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlFmncNavSupply::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (LstArtAlt == comp->LstArtAlt) insert(items, LSTARTALT);
	if (LstSkiAlt == comp->LstSkiAlt) insert(items, LSTSKIALT);
	if (LstPcoAlt == comp->LstPcoAlt) insert(items, LSTPCOALT);
	if (LstArtNumFirstdisp == comp->LstArtNumFirstdisp) insert(items, LSTARTNUMFIRSTDISP);
	if (LstSkiNumFirstdisp == comp->LstSkiNumFirstdisp) insert(items, LSTSKINUMFIRSTDISP);
	if (LstPcoNumFirstdisp == comp->LstPcoNumFirstdisp) insert(items, LSTPCONUMFIRSTDISP);

	return(items);
};

set<uint> PnlFmncNavSupply::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, LSTARTALT, LSTSKIALT, LSTPCOALT, LSTARTNUMFIRSTDISP, LSTSKINUMFIRSTDISP, LSTPCONUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavSupply::StatShr
 ******************************************************************************/

PnlFmncNavSupply::StatShr::StatShr(
			const bool LstArtAvail
			, const bool ButArtViewActive
			, const bool LstSkiAvail
			, const bool ButSkiViewActive
			, const bool LstPcoAvail
			, const bool ButPcoViewActive
		) : Block() {
	this->LstArtAvail = LstArtAvail;
	this->ButArtViewActive = ButArtViewActive;
	this->LstSkiAvail = LstSkiAvail;
	this->ButSkiViewActive = ButSkiViewActive;
	this->LstPcoAvail = LstPcoAvail;
	this->ButPcoViewActive = ButPcoViewActive;

	mask = {LSTARTAVAIL, BUTARTVIEWACTIVE, LSTSKIAVAIL, BUTSKIVIEWACTIVE, LSTPCOAVAIL, BUTPCOVIEWACTIVE};
};

bool PnlFmncNavSupply::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncNavSupply");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncNavSupply";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstArtAvail", LstArtAvail)) add(LSTARTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButArtViewActive", ButArtViewActive)) add(BUTARTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSkiAvail", LstSkiAvail)) add(LSTSKIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSkiViewActive", ButSkiViewActive)) add(BUTSKIVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPcoAvail", LstPcoAvail)) add(LSTPCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPcoViewActive", ButPcoViewActive)) add(BUTPCOVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncNavSupply::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstArtAvail == comp->LstArtAvail) insert(items, LSTARTAVAIL);
	if (ButArtViewActive == comp->ButArtViewActive) insert(items, BUTARTVIEWACTIVE);
	if (LstSkiAvail == comp->LstSkiAvail) insert(items, LSTSKIAVAIL);
	if (ButSkiViewActive == comp->ButSkiViewActive) insert(items, BUTSKIVIEWACTIVE);
	if (LstPcoAvail == comp->LstPcoAvail) insert(items, LSTPCOAVAIL);
	if (ButPcoViewActive == comp->ButPcoViewActive) insert(items, BUTPCOVIEWACTIVE);

	return(items);
};

set<uint> PnlFmncNavSupply::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTARTAVAIL, BUTARTVIEWACTIVE, LSTSKIAVAIL, BUTSKIVIEWACTIVE, LSTPCOAVAIL, BUTPCOVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavSupply::Tag
 ******************************************************************************/

PnlFmncNavSupply::Tag::Tag(
			const string& Cpt
			, const string& CptArt
			, const string& CptSki
			, const string& CptPco
		) : Block() {
	this->Cpt = Cpt;
	this->CptArt = CptArt;
	this->CptSki = CptSki;
	this->CptPco = CptPco;

	mask = {CPT, CPTART, CPTSKI, CPTPCO};
};

bool PnlFmncNavSupply::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncNavSupply");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncNavSupply";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptArt", CptArt)) add(CPTART);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSki", CptSki)) add(CPTSKI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPco", CptPco)) add(CPTPCO);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncNavSupply::DpchAppData
 ******************************************************************************/

PnlFmncNavSupply::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVSUPPLYDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlFmncNavSupply::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavSupply::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncNavSupplyData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavSupply::DpchAppDo
 ******************************************************************************/

PnlFmncNavSupply::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVSUPPLYDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncNavSupply::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavSupply::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncNavSupplyDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavSupply::DpchEngData
 ******************************************************************************/

PnlFmncNavSupply::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVSUPPLYDATA) {
	feedFLstArt.tag = "FeedFLstArt";
	feedFLstPco.tag = "FeedFLstPco";
	feedFLstSki.tag = "FeedFLstSki";
};

string PnlFmncNavSupply::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTART)) ss.push_back("feedFLstArt");
	if (has(FEEDFLSTPCO)) ss.push_back("feedFLstPco");
	if (has(FEEDFLSTSKI)) ss.push_back("feedFLstSki");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavSupply::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncNavSupplyData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstArt.readXML(docctx, basexpath, true)) add(FEEDFLSTART);
		if (feedFLstPco.readXML(docctx, basexpath, true)) add(FEEDFLSTPCO);
		if (feedFLstSki.readXML(docctx, basexpath, true)) add(FEEDFLSTSKI);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstArt.clear();
		feedFLstPco.clear();
		feedFLstSki.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

