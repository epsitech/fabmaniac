/**
  * \file PnlFmncTolRec.cpp
  * API code for job PnlFmncTolRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncTolRec.h"

/******************************************************************************
 class PnlFmncTolRec::VecVDo
 ******************************************************************************/

uint PnlFmncTolRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlFmncTolRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlFmncTolRec::ContInf
 ******************************************************************************/

PnlFmncTolRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlFmncTolRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncTolRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncTolRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlFmncTolRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlFmncTolRec::ContInf::diff(
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
 class PnlFmncTolRec::StatApp
 ******************************************************************************/

PnlFmncTolRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneKSteppar
			, const bool initdoneKToolchar
			, const bool initdoneAAvl
			, const bool initdoneAChar
			, const bool initdoneARes
			, const bool initdoneAUtil
			, const bool initdone1NArticle
			, const bool initdoneRlv1NStep
			, const bool initdoneRef1NFile
			, const bool initdoneMNTooltype
			, const bool initdoneMNFabuser
			, const bool initdoneSvcMNOrg
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneKSteppar = initdoneKSteppar;
	this->initdoneKToolchar = initdoneKToolchar;
	this->initdoneAAvl = initdoneAAvl;
	this->initdoneAChar = initdoneAChar;
	this->initdoneARes = initdoneARes;
	this->initdoneAUtil = initdoneAUtil;
	this->initdone1NArticle = initdone1NArticle;
	this->initdoneRlv1NStep = initdoneRlv1NStep;
	this->initdoneRef1NFile = initdoneRef1NFile;
	this->initdoneMNTooltype = initdoneMNTooltype;
	this->initdoneMNFabuser = initdoneMNFabuser;
	this->initdoneSvcMNOrg = initdoneSvcMNOrg;

	mask = {INITDONEDETAIL, INITDONEKSTEPPAR, INITDONEKTOOLCHAR, INITDONEAAVL, INITDONEACHAR, INITDONEARES, INITDONEAUTIL, INITDONE1NARTICLE, INITDONERLV1NSTEP, INITDONEREF1NFILE, INITDONEMNTOOLTYPE, INITDONEMNFABUSER, INITDONESVCMNORG};
};

bool PnlFmncTolRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncTolRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncTolRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKSteppar", initdoneKSteppar)) add(INITDONEKSTEPPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKToolchar", initdoneKToolchar)) add(INITDONEKTOOLCHAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAAvl", initdoneAAvl)) add(INITDONEAAVL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAChar", initdoneAChar)) add(INITDONEACHAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneARes", initdoneARes)) add(INITDONEARES);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAUtil", initdoneAUtil)) add(INITDONEAUTIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NArticle", initdone1NArticle)) add(INITDONE1NARTICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRlv1NStep", initdoneRlv1NStep)) add(INITDONERLV1NSTEP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNTooltype", initdoneMNTooltype)) add(INITDONEMNTOOLTYPE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNFabuser", initdoneMNFabuser)) add(INITDONEMNFABUSER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSvcMNOrg", initdoneSvcMNOrg)) add(INITDONESVCMNORG);
	};

	return basefound;
};

set<uint> PnlFmncTolRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneKSteppar == comp->initdoneKSteppar) insert(items, INITDONEKSTEPPAR);
	if (initdoneKToolchar == comp->initdoneKToolchar) insert(items, INITDONEKTOOLCHAR);
	if (initdoneAAvl == comp->initdoneAAvl) insert(items, INITDONEAAVL);
	if (initdoneAChar == comp->initdoneAChar) insert(items, INITDONEACHAR);
	if (initdoneARes == comp->initdoneARes) insert(items, INITDONEARES);
	if (initdoneAUtil == comp->initdoneAUtil) insert(items, INITDONEAUTIL);
	if (initdone1NArticle == comp->initdone1NArticle) insert(items, INITDONE1NARTICLE);
	if (initdoneRlv1NStep == comp->initdoneRlv1NStep) insert(items, INITDONERLV1NSTEP);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);
	if (initdoneMNTooltype == comp->initdoneMNTooltype) insert(items, INITDONEMNTOOLTYPE);
	if (initdoneMNFabuser == comp->initdoneMNFabuser) insert(items, INITDONEMNFABUSER);
	if (initdoneSvcMNOrg == comp->initdoneSvcMNOrg) insert(items, INITDONESVCMNORG);

	return(items);
};

set<uint> PnlFmncTolRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEKSTEPPAR, INITDONEKTOOLCHAR, INITDONEAAVL, INITDONEACHAR, INITDONEARES, INITDONEAUTIL, INITDONE1NARTICLE, INITDONERLV1NSTEP, INITDONEREF1NFILE, INITDONEMNTOOLTYPE, INITDONEMNFABUSER, INITDONESVCMNORG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncTolRec::StatShr
 ******************************************************************************/

PnlFmncTolRec::StatShr::StatShr(
			const uint ixFmncVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefKSteppar
			, const string& scrJrefKToolchar
			, const string& scrJrefAAvl
			, const string& scrJrefAChar
			, const string& scrJrefARes
			, const string& scrJrefAUtil
			, const string& scrJref1NArticle
			, const string& scrJrefRlv1NStep
			, const string& scrJrefRef1NFile
			, const string& scrJrefMNTooltype
			, const string& scrJrefMNFabuser
			, const string& scrJrefSvcMNOrg
			, const bool ButRegularizeActive
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefKSteppar = scrJrefKSteppar;
	this->scrJrefKToolchar = scrJrefKToolchar;
	this->scrJrefAAvl = scrJrefAAvl;
	this->scrJrefAChar = scrJrefAChar;
	this->scrJrefARes = scrJrefARes;
	this->scrJrefAUtil = scrJrefAUtil;
	this->scrJref1NArticle = scrJref1NArticle;
	this->scrJrefRlv1NStep = scrJrefRlv1NStep;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->scrJrefMNTooltype = scrJrefMNTooltype;
	this->scrJrefMNFabuser = scrJrefMNFabuser;
	this->scrJrefSvcMNOrg = scrJrefSvcMNOrg;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFKSTEPPAR, SCRJREFKTOOLCHAR, SCRJREFAAVL, SCRJREFACHAR, SCRJREFARES, SCRJREFAUTIL, SCRJREF1NARTICLE, SCRJREFRLV1NSTEP, SCRJREFREF1NFILE, SCRJREFMNTOOLTYPE, SCRJREFMNFABUSER, SCRJREFSVCMNORG, BUTREGULARIZEACTIVE};
};

bool PnlFmncTolRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncTolRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncTolRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKSteppar", scrJrefKSteppar)) add(SCRJREFKSTEPPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKToolchar", scrJrefKToolchar)) add(SCRJREFKTOOLCHAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAAvl", scrJrefAAvl)) add(SCRJREFAAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAChar", scrJrefAChar)) add(SCRJREFACHAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefARes", scrJrefARes)) add(SCRJREFARES);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAUtil", scrJrefAUtil)) add(SCRJREFAUTIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NArticle", scrJref1NArticle)) add(SCRJREF1NARTICLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRlv1NStep", scrJrefRlv1NStep)) add(SCRJREFRLV1NSTEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNTooltype", scrJrefMNTooltype)) add(SCRJREFMNTOOLTYPE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNFabuser", scrJrefMNFabuser)) add(SCRJREFMNFABUSER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSvcMNOrg", scrJrefSvcMNOrg)) add(SCRJREFSVCMNORG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncTolRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefKSteppar.compare(comp->scrJrefKSteppar) == 0) insert(items, SCRJREFKSTEPPAR);
	if (scrJrefKToolchar.compare(comp->scrJrefKToolchar) == 0) insert(items, SCRJREFKTOOLCHAR);
	if (scrJrefAAvl.compare(comp->scrJrefAAvl) == 0) insert(items, SCRJREFAAVL);
	if (scrJrefAChar.compare(comp->scrJrefAChar) == 0) insert(items, SCRJREFACHAR);
	if (scrJrefARes.compare(comp->scrJrefARes) == 0) insert(items, SCRJREFARES);
	if (scrJrefAUtil.compare(comp->scrJrefAUtil) == 0) insert(items, SCRJREFAUTIL);
	if (scrJref1NArticle.compare(comp->scrJref1NArticle) == 0) insert(items, SCRJREF1NARTICLE);
	if (scrJrefRlv1NStep.compare(comp->scrJrefRlv1NStep) == 0) insert(items, SCRJREFRLV1NSTEP);
	if (scrJrefRef1NFile.compare(comp->scrJrefRef1NFile) == 0) insert(items, SCRJREFREF1NFILE);
	if (scrJrefMNTooltype.compare(comp->scrJrefMNTooltype) == 0) insert(items, SCRJREFMNTOOLTYPE);
	if (scrJrefMNFabuser.compare(comp->scrJrefMNFabuser) == 0) insert(items, SCRJREFMNFABUSER);
	if (scrJrefSvcMNOrg.compare(comp->scrJrefSvcMNOrg) == 0) insert(items, SCRJREFSVCMNORG);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlFmncTolRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFKSTEPPAR, SCRJREFKTOOLCHAR, SCRJREFAAVL, SCRJREFACHAR, SCRJREFARES, SCRJREFAUTIL, SCRJREF1NARTICLE, SCRJREFRLV1NSTEP, SCRJREFREF1NFILE, SCRJREFMNTOOLTYPE, SCRJREFMNFABUSER, SCRJREFSVCMNORG, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncTolRec::Tag
 ******************************************************************************/

PnlFmncTolRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlFmncTolRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncTolRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncTolRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncTolRec::DpchAppDo
 ******************************************************************************/

PnlFmncTolRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCTOLRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncTolRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncTolRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncTolRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncTolRec::DpchEngData
 ******************************************************************************/

PnlFmncTolRec::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCTOLRECDATA) {
};

string PnlFmncTolRec::DpchEngData::getSrefsMask() {
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

void PnlFmncTolRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncTolRecData");
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

