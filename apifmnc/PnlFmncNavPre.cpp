/**
  * \file PnlFmncNavPre.cpp
  * API code for job PnlFmncNavPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncNavPre.h"

/******************************************************************************
 class PnlFmncNavPre::VecVDo
 ******************************************************************************/

uint PnlFmncNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butfabremoveclick") == 0) return BUTFABREMOVECLICK;
	else if (s.compare("butrunremoveclick") == 0) return BUTRUNREMOVECLICK;

	return(0);
};

string PnlFmncNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTFABREMOVECLICK) return("ButFabRemoveClick");
	else if (ix == BUTRUNREMOVECLICK) return("ButRunRemoveClick");

	return("");
};

/******************************************************************************
 class PnlFmncNavPre::ContInf
 ******************************************************************************/

PnlFmncNavPre::ContInf::ContInf(
			const string& TxtFab
			, const string& TxtRun
		) : Block() {
	this->TxtFab = TxtFab;
	this->TxtRun = TxtRun;

	mask = {TXTFAB, TXTRUN};
};

bool PnlFmncNavPre::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFab", TxtFab)) add(TXTFAB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRun", TxtRun)) add(TXTRUN);
	};

	return basefound;
};

set<uint> PnlFmncNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFab.compare(comp->TxtFab) == 0) insert(items, TXTFAB);
	if (TxtRun.compare(comp->TxtRun) == 0) insert(items, TXTRUN);

	return(items);
};

set<uint> PnlFmncNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFAB, TXTRUN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavPre::StatShr
 ******************************************************************************/

PnlFmncNavPre::StatShr::StatShr(
			const bool TxtFabAvail
			, const bool TxtRunAvail
		) : Block() {
	this->TxtFabAvail = TxtFabAvail;
	this->TxtRunAvail = TxtRunAvail;

	mask = {TXTFABAVAIL, TXTRUNAVAIL};
};

bool PnlFmncNavPre::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncNavPre";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFabAvail", TxtFabAvail)) add(TXTFABAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtRunAvail", TxtRunAvail)) add(TXTRUNAVAIL);
	};

	return basefound;
};

set<uint> PnlFmncNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtFabAvail == comp->TxtFabAvail) insert(items, TXTFABAVAIL);
	if (TxtRunAvail == comp->TxtRunAvail) insert(items, TXTRUNAVAIL);

	return(items);
};

set<uint> PnlFmncNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFABAVAIL, TXTRUNAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavPre::Tag
 ******************************************************************************/

PnlFmncNavPre::Tag::Tag(
			const string& CptFab
			, const string& CptRun
		) : Block() {
	this->CptFab = CptFab;
	this->CptRun = CptRun;

	mask = {CPTFAB, CPTRUN};
};

bool PnlFmncNavPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFab", CptFab)) add(CPTFAB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRun", CptRun)) add(CPTRUN);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncNavPre::DpchAppDo
 ******************************************************************************/

PnlFmncNavPre::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVPREDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavPre::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncNavPreDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavPre::DpchEngData
 ******************************************************************************/

PnlFmncNavPre::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVPREDATA) {
};

string PnlFmncNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncNavPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};

