/**
  * \file PnlFmncPrsRec.cpp
  * API code for job PnlFmncPrsRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncPrsRec.h"

/******************************************************************************
 class PnlFmncPrsRec::VecVDo
 ******************************************************************************/

uint PnlFmncPrsRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlFmncPrsRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlFmncPrsRec::ContInf
 ******************************************************************************/

PnlFmncPrsRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlFmncPrsRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncPrsRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncPrsRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlFmncPrsRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlFmncPrsRec::ContInf::diff(
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
 class PnlFmncPrsRec::StatApp
 ******************************************************************************/

PnlFmncPrsRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneADetail
			, const bool initdoneHk1NAddress
			, const bool initdoneMNRun
			, const bool initdoneMNOrg
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneADetail = initdoneADetail;
	this->initdoneHk1NAddress = initdoneHk1NAddress;
	this->initdoneMNRun = initdoneMNRun;
	this->initdoneMNOrg = initdoneMNOrg;

	mask = {INITDONEDETAIL, INITDONEADETAIL, INITDONEHK1NADDRESS, INITDONEMNRUN, INITDONEMNORG};
};

bool PnlFmncPrsRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncPrsRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncPrsRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneADetail", initdoneADetail)) add(INITDONEADETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NAddress", initdoneHk1NAddress)) add(INITDONEHK1NADDRESS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNRun", initdoneMNRun)) add(INITDONEMNRUN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNOrg", initdoneMNOrg)) add(INITDONEMNORG);
	};

	return basefound;
};

set<uint> PnlFmncPrsRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneADetail == comp->initdoneADetail) insert(items, INITDONEADETAIL);
	if (initdoneHk1NAddress == comp->initdoneHk1NAddress) insert(items, INITDONEHK1NADDRESS);
	if (initdoneMNRun == comp->initdoneMNRun) insert(items, INITDONEMNRUN);
	if (initdoneMNOrg == comp->initdoneMNOrg) insert(items, INITDONEMNORG);

	return(items);
};

set<uint> PnlFmncPrsRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEADETAIL, INITDONEHK1NADDRESS, INITDONEMNRUN, INITDONEMNORG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPrsRec::StatShr
 ******************************************************************************/

PnlFmncPrsRec::StatShr::StatShr(
			const uint ixFmncVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefADetail
			, const string& scrJrefHk1NAddress
			, const string& scrJrefMNRun
			, const string& scrJrefMNOrg
			, const bool ButRegularizeActive
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefADetail = scrJrefADetail;
	this->scrJrefHk1NAddress = scrJrefHk1NAddress;
	this->scrJrefMNRun = scrJrefMNRun;
	this->scrJrefMNOrg = scrJrefMNOrg;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFADETAIL, SCRJREFHK1NADDRESS, SCRJREFMNRUN, SCRJREFMNORG, BUTREGULARIZEACTIVE};
};

bool PnlFmncPrsRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncPrsRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncPrsRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefADetail", scrJrefADetail)) add(SCRJREFADETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NAddress", scrJrefHk1NAddress)) add(SCRJREFHK1NADDRESS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNRun", scrJrefMNRun)) add(SCRJREFMNRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNOrg", scrJrefMNOrg)) add(SCRJREFMNORG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncPrsRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefADetail.compare(comp->scrJrefADetail) == 0) insert(items, SCRJREFADETAIL);
	if (scrJrefHk1NAddress.compare(comp->scrJrefHk1NAddress) == 0) insert(items, SCRJREFHK1NADDRESS);
	if (scrJrefMNRun.compare(comp->scrJrefMNRun) == 0) insert(items, SCRJREFMNRUN);
	if (scrJrefMNOrg.compare(comp->scrJrefMNOrg) == 0) insert(items, SCRJREFMNORG);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlFmncPrsRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFADETAIL, SCRJREFHK1NADDRESS, SCRJREFMNRUN, SCRJREFMNORG, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncPrsRec::Tag
 ******************************************************************************/

PnlFmncPrsRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlFmncPrsRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncPrsRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncPrsRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncPrsRec::DpchAppDo
 ******************************************************************************/

PnlFmncPrsRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCPRSRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncPrsRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncPrsRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncPrsRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncPrsRec::DpchEngData
 ******************************************************************************/

PnlFmncPrsRec::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCPRSRECDATA) {
};

string PnlFmncPrsRec::DpchEngData::getSrefsMask() {
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

void PnlFmncPrsRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncPrsRecData");
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

