/**
  * \file PnlFmncOrgRec.cpp
  * API code for job PnlFmncOrgRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "PnlFmncOrgRec.h"

/******************************************************************************
 class PnlFmncOrgRec::VecVDo
 ******************************************************************************/

uint PnlFmncOrgRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

	return(0);
};

string PnlFmncOrgRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlFmncOrgRec::ContInf
 ******************************************************************************/

PnlFmncOrgRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlFmncOrgRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfFmncOrgRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfFmncOrgRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlFmncOrgRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

	return(items);
};

set<uint> PnlFmncOrgRec::ContInf::diff(
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
 class PnlFmncOrgRec::StatApp
 ******************************************************************************/

PnlFmncOrgRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneKStocklcn
			, const bool initdoneADetail
			, const bool initdoneBio1NFabproject
			, const bool initdoneMnf1NTool
			, const bool initdone1NArticle
			, const bool initdonePco1NPurchorder
			, const bool initdoneSpl1NPurchorder
			, const bool initdone1NStockitem
			, const bool initdoneSup1NOrg
			, const bool initdoneHk1NAddress
			, const bool initdoneMNPerson
			, const bool initdoneSvcMNTool
			, const bool initdoneMNArticle
		) : Block() {
	this->initdoneDetail = initdoneDetail;
	this->initdoneKStocklcn = initdoneKStocklcn;
	this->initdoneADetail = initdoneADetail;
	this->initdoneBio1NFabproject = initdoneBio1NFabproject;
	this->initdoneMnf1NTool = initdoneMnf1NTool;
	this->initdone1NArticle = initdone1NArticle;
	this->initdonePco1NPurchorder = initdonePco1NPurchorder;
	this->initdoneSpl1NPurchorder = initdoneSpl1NPurchorder;
	this->initdone1NStockitem = initdone1NStockitem;
	this->initdoneSup1NOrg = initdoneSup1NOrg;
	this->initdoneHk1NAddress = initdoneHk1NAddress;
	this->initdoneMNPerson = initdoneMNPerson;
	this->initdoneSvcMNTool = initdoneSvcMNTool;
	this->initdoneMNArticle = initdoneMNArticle;

	mask = {INITDONEDETAIL, INITDONEKSTOCKLCN, INITDONEADETAIL, INITDONEBIO1NFABPROJECT, INITDONEMNF1NTOOL, INITDONE1NARTICLE, INITDONEPCO1NPURCHORDER, INITDONESPL1NPURCHORDER, INITDONE1NSTOCKITEM, INITDONESUP1NORG, INITDONEHK1NADDRESS, INITDONEMNPERSON, INITDONESVCMNTOOL, INITDONEMNARTICLE};
};

bool PnlFmncOrgRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppFmncOrgRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppFmncOrgRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKStocklcn", initdoneKStocklcn)) add(INITDONEKSTOCKLCN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneADetail", initdoneADetail)) add(INITDONEADETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneBio1NFabproject", initdoneBio1NFabproject)) add(INITDONEBIO1NFABPROJECT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMnf1NTool", initdoneMnf1NTool)) add(INITDONEMNF1NTOOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NArticle", initdone1NArticle)) add(INITDONE1NARTICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePco1NPurchorder", initdonePco1NPurchorder)) add(INITDONEPCO1NPURCHORDER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSpl1NPurchorder", initdoneSpl1NPurchorder)) add(INITDONESPL1NPURCHORDER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NStockitem", initdone1NStockitem)) add(INITDONE1NSTOCKITEM);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NOrg", initdoneSup1NOrg)) add(INITDONESUP1NORG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NAddress", initdoneHk1NAddress)) add(INITDONEHK1NADDRESS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNPerson", initdoneMNPerson)) add(INITDONEMNPERSON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSvcMNTool", initdoneSvcMNTool)) add(INITDONESVCMNTOOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNArticle", initdoneMNArticle)) add(INITDONEMNARTICLE);
	};

	return basefound;
};

set<uint> PnlFmncOrgRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneKStocklcn == comp->initdoneKStocklcn) insert(items, INITDONEKSTOCKLCN);
	if (initdoneADetail == comp->initdoneADetail) insert(items, INITDONEADETAIL);
	if (initdoneBio1NFabproject == comp->initdoneBio1NFabproject) insert(items, INITDONEBIO1NFABPROJECT);
	if (initdoneMnf1NTool == comp->initdoneMnf1NTool) insert(items, INITDONEMNF1NTOOL);
	if (initdone1NArticle == comp->initdone1NArticle) insert(items, INITDONE1NARTICLE);
	if (initdonePco1NPurchorder == comp->initdonePco1NPurchorder) insert(items, INITDONEPCO1NPURCHORDER);
	if (initdoneSpl1NPurchorder == comp->initdoneSpl1NPurchorder) insert(items, INITDONESPL1NPURCHORDER);
	if (initdone1NStockitem == comp->initdone1NStockitem) insert(items, INITDONE1NSTOCKITEM);
	if (initdoneSup1NOrg == comp->initdoneSup1NOrg) insert(items, INITDONESUP1NORG);
	if (initdoneHk1NAddress == comp->initdoneHk1NAddress) insert(items, INITDONEHK1NADDRESS);
	if (initdoneMNPerson == comp->initdoneMNPerson) insert(items, INITDONEMNPERSON);
	if (initdoneSvcMNTool == comp->initdoneSvcMNTool) insert(items, INITDONESVCMNTOOL);
	if (initdoneMNArticle == comp->initdoneMNArticle) insert(items, INITDONEMNARTICLE);

	return(items);
};

set<uint> PnlFmncOrgRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEKSTOCKLCN, INITDONEADETAIL, INITDONEBIO1NFABPROJECT, INITDONEMNF1NTOOL, INITDONE1NARTICLE, INITDONEPCO1NPURCHORDER, INITDONESPL1NPURCHORDER, INITDONE1NSTOCKITEM, INITDONESUP1NORG, INITDONEHK1NADDRESS, INITDONEMNPERSON, INITDONESVCMNTOOL, INITDONEMNARTICLE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncOrgRec::StatShr
 ******************************************************************************/

PnlFmncOrgRec::StatShr::StatShr(
			const uint ixFmncVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefKStocklcn
			, const string& scrJrefADetail
			, const string& scrJrefBio1NFabproject
			, const string& scrJrefMnf1NTool
			, const string& scrJref1NArticle
			, const string& scrJrefPco1NPurchorder
			, const string& scrJrefSpl1NPurchorder
			, const string& scrJref1NStockitem
			, const string& scrJrefSup1NOrg
			, const string& scrJrefHk1NAddress
			, const string& scrJrefMNPerson
			, const string& scrJrefSvcMNTool
			, const string& scrJrefMNArticle
			, const bool ButRegularizeActive
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefKStocklcn = scrJrefKStocklcn;
	this->scrJrefADetail = scrJrefADetail;
	this->scrJrefBio1NFabproject = scrJrefBio1NFabproject;
	this->scrJrefMnf1NTool = scrJrefMnf1NTool;
	this->scrJref1NArticle = scrJref1NArticle;
	this->scrJrefPco1NPurchorder = scrJrefPco1NPurchorder;
	this->scrJrefSpl1NPurchorder = scrJrefSpl1NPurchorder;
	this->scrJref1NStockitem = scrJref1NStockitem;
	this->scrJrefSup1NOrg = scrJrefSup1NOrg;
	this->scrJrefHk1NAddress = scrJrefHk1NAddress;
	this->scrJrefMNPerson = scrJrefMNPerson;
	this->scrJrefSvcMNTool = scrJrefSvcMNTool;
	this->scrJrefMNArticle = scrJrefMNArticle;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFKSTOCKLCN, SCRJREFADETAIL, SCRJREFBIO1NFABPROJECT, SCRJREFMNF1NTOOL, SCRJREF1NARTICLE, SCRJREFPCO1NPURCHORDER, SCRJREFSPL1NPURCHORDER, SCRJREF1NSTOCKITEM, SCRJREFSUP1NORG, SCRJREFHK1NADDRESS, SCRJREFMNPERSON, SCRJREFSVCMNTOOL, SCRJREFMNARTICLE, BUTREGULARIZEACTIVE};
};

bool PnlFmncOrgRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxFmncVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrFmncOrgRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrFmncOrgRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxFmncVExpstate", srefIxFmncVExpstate)) {
			ixFmncVExpstate = VecFmncVExpstate::getIx(srefIxFmncVExpstate);
			add(IXFMNCVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKStocklcn", scrJrefKStocklcn)) add(SCRJREFKSTOCKLCN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefADetail", scrJrefADetail)) add(SCRJREFADETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefBio1NFabproject", scrJrefBio1NFabproject)) add(SCRJREFBIO1NFABPROJECT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMnf1NTool", scrJrefMnf1NTool)) add(SCRJREFMNF1NTOOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NArticle", scrJref1NArticle)) add(SCRJREF1NARTICLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPco1NPurchorder", scrJrefPco1NPurchorder)) add(SCRJREFPCO1NPURCHORDER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSpl1NPurchorder", scrJrefSpl1NPurchorder)) add(SCRJREFSPL1NPURCHORDER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NStockitem", scrJref1NStockitem)) add(SCRJREF1NSTOCKITEM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NOrg", scrJrefSup1NOrg)) add(SCRJREFSUP1NORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NAddress", scrJrefHk1NAddress)) add(SCRJREFHK1NADDRESS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNPerson", scrJrefMNPerson)) add(SCRJREFMNPERSON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSvcMNTool", scrJrefSvcMNTool)) add(SCRJREFSVCMNTOOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNArticle", scrJrefMNArticle)) add(SCRJREFMNARTICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlFmncOrgRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefKStocklcn.compare(comp->scrJrefKStocklcn) == 0) insert(items, SCRJREFKSTOCKLCN);
	if (scrJrefADetail.compare(comp->scrJrefADetail) == 0) insert(items, SCRJREFADETAIL);
	if (scrJrefBio1NFabproject.compare(comp->scrJrefBio1NFabproject) == 0) insert(items, SCRJREFBIO1NFABPROJECT);
	if (scrJrefMnf1NTool.compare(comp->scrJrefMnf1NTool) == 0) insert(items, SCRJREFMNF1NTOOL);
	if (scrJref1NArticle.compare(comp->scrJref1NArticle) == 0) insert(items, SCRJREF1NARTICLE);
	if (scrJrefPco1NPurchorder.compare(comp->scrJrefPco1NPurchorder) == 0) insert(items, SCRJREFPCO1NPURCHORDER);
	if (scrJrefSpl1NPurchorder.compare(comp->scrJrefSpl1NPurchorder) == 0) insert(items, SCRJREFSPL1NPURCHORDER);
	if (scrJref1NStockitem.compare(comp->scrJref1NStockitem) == 0) insert(items, SCRJREF1NSTOCKITEM);
	if (scrJrefSup1NOrg.compare(comp->scrJrefSup1NOrg) == 0) insert(items, SCRJREFSUP1NORG);
	if (scrJrefHk1NAddress.compare(comp->scrJrefHk1NAddress) == 0) insert(items, SCRJREFHK1NADDRESS);
	if (scrJrefMNPerson.compare(comp->scrJrefMNPerson) == 0) insert(items, SCRJREFMNPERSON);
	if (scrJrefSvcMNTool.compare(comp->scrJrefSvcMNTool) == 0) insert(items, SCRJREFSVCMNTOOL);
	if (scrJrefMNArticle.compare(comp->scrJrefMNArticle) == 0) insert(items, SCRJREFMNARTICLE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlFmncOrgRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, SCRJREFDETAIL, SCRJREFKSTOCKLCN, SCRJREFADETAIL, SCRJREFBIO1NFABPROJECT, SCRJREFMNF1NTOOL, SCRJREF1NARTICLE, SCRJREFPCO1NPURCHORDER, SCRJREFSPL1NPURCHORDER, SCRJREF1NSTOCKITEM, SCRJREFSUP1NORG, SCRJREFHK1NADDRESS, SCRJREFMNPERSON, SCRJREFSVCMNTOOL, SCRJREFMNARTICLE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncOrgRec::Tag
 ******************************************************************************/

PnlFmncOrgRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlFmncOrgRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagFmncOrgRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemFmncOrgRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlFmncOrgRec::DpchAppDo
 ******************************************************************************/

PnlFmncOrgRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCORGRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlFmncOrgRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncOrgRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppFmncOrgRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncOrgRec::DpchEngData
 ******************************************************************************/

PnlFmncOrgRec::DpchEngData::DpchEngData() : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCORGRECDATA) {
};

string PnlFmncOrgRec::DpchEngData::getSrefsMask() {
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

void PnlFmncOrgRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngFmncOrgRecData");
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

