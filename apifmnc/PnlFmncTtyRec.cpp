/**
  * \file PnlFmncTtyRec.cpp
  * API code for job PnlFmncTtyRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncTtyRec.h"

/******************************************************************************
 class PnlFmncTtyRec::VecVDo
 ******************************************************************************/

uint PnlFmncTtyRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlFmncTtyRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlFmncTtyRec::ContInf
 ******************************************************************************/

PnlFmncTtyRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlFmncTtyRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncTtyRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncTtyRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlFmncTtyRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlFmncTtyRec::ContInf::diff(
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
 class PnlFmncTtyRec::StatApp
 ******************************************************************************/

PnlFmncTtyRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneKSteppar
			, const bool initdoneKToolchar
			, const bool initdoneSup1NTooltype
			, const bool initdoneRlv1NStep
			, const bool initdoneMNTool
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneKSteppar = initdoneKSteppar;
	this->initdoneKToolchar = initdoneKToolchar;
	this->initdoneSup1NTooltype = initdoneSup1NTooltype;
	this->initdoneRlv1NStep = initdoneRlv1NStep;
	this->initdoneMNTool = initdoneMNTool;

	mask = {INITDONEDETAIL, INITDONEKSTEPPAR, INITDONEKTOOLCHAR, INITDONESUP1NTOOLTYPE, INITDONERLV1NSTEP, INITDONEMNTOOL};
};

bool PnlFmncTtyRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncTtyRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncTtyRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKSteppar", initdoneKSteppar)) add(INITDONEKSTEPPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKToolchar", initdoneKToolchar)) add(INITDONEKTOOLCHAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NTooltype", initdoneSup1NTooltype)) add(INITDONESUP1NTOOLTYPE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRlv1NStep", initdoneRlv1NStep)) add(INITDONERLV1NSTEP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNTool", initdoneMNTool)) add(INITDONEMNTOOL);
	};

	return basefound;
};

set<uint> PnlFmncTtyRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneKSteppar == comp->initdoneKSteppar) insert(items, INITDONEKSTEPPAR);
	if (initdoneKToolchar == comp->initdoneKToolchar) insert(items, INITDONEKTOOLCHAR);
	if (initdoneSup1NTooltype == comp->initdoneSup1NTooltype) insert(items, INITDONESUP1NTOOLTYPE);
	if (initdoneRlv1NStep == comp->initdoneRlv1NStep) insert(items, INITDONERLV1NSTEP);
	if (initdoneMNTool == comp->initdoneMNTool) insert(items, INITDONEMNTOOL);

	return(items);
};

set<uint> PnlFmncTtyRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEKSTEPPAR, INITDONEKTOOLCHAR, INITDONESUP1NTOOLTYPE, INITDONERLV1NSTEP, INITDONEMNTOOL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncTtyRec::StatShr
 ******************************************************************************/

PnlFmncTtyRec::StatShr::StatShr(
			const uint ixFmncVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefKSteppar
			, const string& scrJrefKToolchar
			, const string& scrJrefSup1NTooltype
			, const string& scrJrefRlv1NStep
			, const string& scrJrefMNTool
			, const bool ButRegularizeActive
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefKSteppar = scrJrefKSteppar;
	this->scrJrefKToolchar = scrJrefKToolchar;
	this->scrJrefSup1NTooltype = scrJrefSup1NTooltype;
	this->scrJrefRlv1NStep = scrJrefRlv1NStep;
	this->scrJrefMNTool = scrJrefMNTool;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFKSTEPPAR, SCRJREFKTOOLCHAR, SCRJREFSUP1NTOOLTYPE, SCRJREFRLV1NSTEP, SCRJREFMNTOOL, BUTREGULARIZEACTIVE};
};

bool PnlFmncTtyRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncTtyRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncTtyRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKSteppar", scrJrefKSteppar)) add(SCRJREFKSTEPPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKToolchar", scrJrefKToolchar)) add(SCRJREFKTOOLCHAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NTooltype", scrJrefSup1NTooltype)) add(SCRJREFSUP1NTOOLTYPE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRlv1NStep", scrJrefRlv1NStep)) add(SCRJREFRLV1NSTEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNTool", scrJrefMNTool)) add(SCRJREFMNTOOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncTtyRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefKSteppar.compare(comp->scrJrefKSteppar) == 0) insert(items, SCRJREFKSTEPPAR);
	if (scrJrefKToolchar.compare(comp->scrJrefKToolchar) == 0) insert(items, SCRJREFKTOOLCHAR);
	if (scrJrefSup1NTooltype.compare(comp->scrJrefSup1NTooltype) == 0) insert(items, SCRJREFSUP1NTOOLTYPE);
	if (scrJrefRlv1NStep.compare(comp->scrJrefRlv1NStep) == 0) insert(items, SCRJREFRLV1NSTEP);
	if (scrJrefMNTool.compare(comp->scrJrefMNTool) == 0) insert(items, SCRJREFMNTOOL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlFmncTtyRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFKSTEPPAR, SCRJREFKTOOLCHAR, SCRJREFSUP1NTOOLTYPE, SCRJREFRLV1NSTEP, SCRJREFMNTOOL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncTtyRec::Tag
 ******************************************************************************/

PnlFmncTtyRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlFmncTtyRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncTtyRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncTtyRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncTtyRec::DpchAppDo
 ******************************************************************************/

PnlFmncTtyRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCTTYRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncTtyRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncTtyRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncTtyRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncTtyRec::DpchEngData
 ******************************************************************************/

PnlFmncTtyRec::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCTTYRECDATA) {
};

string PnlFmncTtyRec::DpchEngData::getSrefsMask() {
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

void PnlFmncTtyRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncTtyRecData");
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

