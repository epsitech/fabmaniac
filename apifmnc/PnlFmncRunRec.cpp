/**
  * \file PnlFmncRunRec.cpp
  * API code for job PnlFmncRunRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncRunRec.h"

/******************************************************************************
 class PnlFmncRunRec::VecVDo
 ******************************************************************************/

uint PnlFmncRunRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlFmncRunRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlFmncRunRec::ContInf
 ******************************************************************************/

PnlFmncRunRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlFmncRunRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncRunRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncRunRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlFmncRunRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlFmncRunRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncRunRec::StatApp
 ******************************************************************************/

PnlFmncRunRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneRun1NActivity
			, const bool initdoneRef1NFile
			, const bool initdoneMNSample
			, const bool initdoneMNPerson
			, const bool initdoneMNFab
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneRun1NActivity = initdoneRun1NActivity;
	this->initdoneRef1NFile = initdoneRef1NFile;
	this->initdoneMNSample = initdoneMNSample;
	this->initdoneMNPerson = initdoneMNPerson;
	this->initdoneMNFab = initdoneMNFab;

	mask = {INITDONEDETAIL, INITDONERUN1NACTIVITY, INITDONEREF1NFILE, INITDONEMNSAMPLE, INITDONEMNPERSON, INITDONEMNFAB};
};

bool PnlFmncRunRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncRunRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncRunRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRun1NActivity", initdoneRun1NActivity)) add(INITDONERUN1NACTIVITY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNSample", initdoneMNSample)) add(INITDONEMNSAMPLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNPerson", initdoneMNPerson)) add(INITDONEMNPERSON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNFab", initdoneMNFab)) add(INITDONEMNFAB);
	};

	return basefound;
};

set<uint> PnlFmncRunRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneRun1NActivity == comp->initdoneRun1NActivity) insert(items, INITDONERUN1NACTIVITY);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);
	if (initdoneMNSample == comp->initdoneMNSample) insert(items, INITDONEMNSAMPLE);
	if (initdoneMNPerson == comp->initdoneMNPerson) insert(items, INITDONEMNPERSON);
	if (initdoneMNFab == comp->initdoneMNFab) insert(items, INITDONEMNFAB);

	return(items);
};

set<uint> PnlFmncRunRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONERUN1NACTIVITY, INITDONEREF1NFILE, INITDONEMNSAMPLE, INITDONEMNPERSON, INITDONEMNFAB};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncRunRec::StatShr
 ******************************************************************************/

PnlFmncRunRec::StatShr::StatShr(
			const uint ixFmncVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefRun1NActivity
			, const string& scrJrefRef1NFile
			, const string& scrJrefMNSample
			, const string& scrJrefMNPerson
			, const string& scrJrefMNFab
			, const bool ButRegularizeActive
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefRun1NActivity = scrJrefRun1NActivity;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->scrJrefMNSample = scrJrefMNSample;
	this->scrJrefMNPerson = scrJrefMNPerson;
	this->scrJrefMNFab = scrJrefMNFab;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFRUN1NACTIVITY, SCRJREFREF1NFILE, SCRJREFMNSAMPLE, SCRJREFMNPERSON, SCRJREFMNFAB, BUTREGULARIZEACTIVE};
};

bool PnlFmncRunRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncRunRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncRunRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRun1NActivity", scrJrefRun1NActivity)) add(SCRJREFRUN1NACTIVITY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNSample", scrJrefMNSample)) add(SCRJREFMNSAMPLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNPerson", scrJrefMNPerson)) add(SCRJREFMNPERSON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNFab", scrJrefMNFab)) add(SCRJREFMNFAB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncRunRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefRun1NActivity.compare(comp->scrJrefRun1NActivity) == 0) insert(items, SCRJREFRUN1NACTIVITY);
	if (scrJrefRef1NFile.compare(comp->scrJrefRef1NFile) == 0) insert(items, SCRJREFREF1NFILE);
	if (scrJrefMNSample.compare(comp->scrJrefMNSample) == 0) insert(items, SCRJREFMNSAMPLE);
	if (scrJrefMNPerson.compare(comp->scrJrefMNPerson) == 0) insert(items, SCRJREFMNPERSON);
	if (scrJrefMNFab.compare(comp->scrJrefMNFab) == 0) insert(items, SCRJREFMNFAB);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlFmncRunRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFRUN1NACTIVITY, SCRJREFREF1NFILE, SCRJREFMNSAMPLE, SCRJREFMNPERSON, SCRJREFMNFAB, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncRunRec::Tag
 ******************************************************************************/

PnlFmncRunRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlFmncRunRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncRunRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncRunRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncRunRec::DpchAppDo
 ******************************************************************************/

PnlFmncRunRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCRUNRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncRunRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncRunRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncRunRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncRunRec::DpchEngData
 ******************************************************************************/

PnlFmncRunRec::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCRUNRECDATA) {
};

string PnlFmncRunRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncRunRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncRunRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

