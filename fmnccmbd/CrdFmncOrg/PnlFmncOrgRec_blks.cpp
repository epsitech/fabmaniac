/**
  * \file PnlFmncOrgRec_blks.cpp
  * job handler for job PnlFmncOrgRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncOrgRec::VecVDo
 ******************************************************************************/

uint PnlFmncOrgRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

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

void PnlFmncOrgRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncOrgRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncOrgRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncOrgRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

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

void PnlFmncOrgRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
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
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncOrgRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncOrgRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKStocklcn", initdoneKStocklcn);
		writeBoolAttr(wr, itemtag, "sref", "initdoneADetail", initdoneADetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneBio1NFabproject", initdoneBio1NFabproject);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMnf1NTool", initdoneMnf1NTool);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NArticle", initdone1NArticle);
		writeBoolAttr(wr, itemtag, "sref", "initdonePco1NPurchorder", initdonePco1NPurchorder);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSpl1NPurchorder", initdoneSpl1NPurchorder);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NStockitem", initdone1NStockitem);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NOrg", initdoneSup1NOrg);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NAddress", initdoneHk1NAddress);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNPerson", initdoneMNPerson);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSvcMNTool", initdoneSvcMNTool);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNArticle", initdoneMNArticle);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncOrgRec::StatShr
 ******************************************************************************/

PnlFmncOrgRec::StatShr::StatShr(
			const uint ixFmncVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefKStocklcn
			, const ubigint jrefADetail
			, const ubigint jrefBio1NFabproject
			, const ubigint jrefMnf1NTool
			, const ubigint jref1NArticle
			, const ubigint jrefPco1NPurchorder
			, const ubigint jrefSpl1NPurchorder
			, const ubigint jref1NStockitem
			, const ubigint jrefSup1NOrg
			, const ubigint jrefHk1NAddress
			, const ubigint jrefMNPerson
			, const ubigint jrefSvcMNTool
			, const ubigint jrefMNArticle
			, const bool ButRegularizeActive
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefKStocklcn = jrefKStocklcn;
	this->jrefADetail = jrefADetail;
	this->jrefBio1NFabproject = jrefBio1NFabproject;
	this->jrefMnf1NTool = jrefMnf1NTool;
	this->jref1NArticle = jref1NArticle;
	this->jrefPco1NPurchorder = jrefPco1NPurchorder;
	this->jrefSpl1NPurchorder = jrefSpl1NPurchorder;
	this->jref1NStockitem = jref1NStockitem;
	this->jrefSup1NOrg = jrefSup1NOrg;
	this->jrefHk1NAddress = jrefHk1NAddress;
	this->jrefMNPerson = jrefMNPerson;
	this->jrefSvcMNTool = jrefSvcMNTool;
	this->jrefMNArticle = jrefMNArticle;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXFMNCVEXPSTATE, JREFDETAIL, JREFKSTOCKLCN, JREFADETAIL, JREFBIO1NFABPROJECT, JREFMNF1NTOOL, JREF1NARTICLE, JREFPCO1NPURCHORDER, JREFSPL1NPURCHORDER, JREF1NSTOCKITEM, JREFSUP1NORG, JREFHK1NADDRESS, JREFMNPERSON, JREFSVCMNTOOL, JREFMNARTICLE, BUTREGULARIZEACTIVE};
};

void PnlFmncOrgRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncOrgRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncOrgRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKStocklcn", Scr::scramble(mScr, scr, descr, jrefKStocklcn));
		writeStringAttr(wr, itemtag, "sref", "scrJrefADetail", Scr::scramble(mScr, scr, descr, jrefADetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefBio1NFabproject", Scr::scramble(mScr, scr, descr, jrefBio1NFabproject));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMnf1NTool", Scr::scramble(mScr, scr, descr, jrefMnf1NTool));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NArticle", Scr::scramble(mScr, scr, descr, jref1NArticle));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPco1NPurchorder", Scr::scramble(mScr, scr, descr, jrefPco1NPurchorder));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSpl1NPurchorder", Scr::scramble(mScr, scr, descr, jrefSpl1NPurchorder));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NStockitem", Scr::scramble(mScr, scr, descr, jref1NStockitem));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NOrg", Scr::scramble(mScr, scr, descr, jrefSup1NOrg));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NAddress", Scr::scramble(mScr, scr, descr, jrefHk1NAddress));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNPerson", Scr::scramble(mScr, scr, descr, jrefMNPerson));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSvcMNTool", Scr::scramble(mScr, scr, descr, jrefSvcMNTool));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNArticle", Scr::scramble(mScr, scr, descr, jrefMNArticle));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncOrgRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefKStocklcn == comp->jrefKStocklcn) insert(items, JREFKSTOCKLCN);
	if (jrefADetail == comp->jrefADetail) insert(items, JREFADETAIL);
	if (jrefBio1NFabproject == comp->jrefBio1NFabproject) insert(items, JREFBIO1NFABPROJECT);
	if (jrefMnf1NTool == comp->jrefMnf1NTool) insert(items, JREFMNF1NTOOL);
	if (jref1NArticle == comp->jref1NArticle) insert(items, JREF1NARTICLE);
	if (jrefPco1NPurchorder == comp->jrefPco1NPurchorder) insert(items, JREFPCO1NPURCHORDER);
	if (jrefSpl1NPurchorder == comp->jrefSpl1NPurchorder) insert(items, JREFSPL1NPURCHORDER);
	if (jref1NStockitem == comp->jref1NStockitem) insert(items, JREF1NSTOCKITEM);
	if (jrefSup1NOrg == comp->jrefSup1NOrg) insert(items, JREFSUP1NORG);
	if (jrefHk1NAddress == comp->jrefHk1NAddress) insert(items, JREFHK1NADDRESS);
	if (jrefMNPerson == comp->jrefMNPerson) insert(items, JREFMNPERSON);
	if (jrefSvcMNTool == comp->jrefSvcMNTool) insert(items, JREFSVCMNTOOL);
	if (jrefMNArticle == comp->jrefMNArticle) insert(items, JREFMNARTICLE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlFmncOrgRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, JREFDETAIL, JREFKSTOCKLCN, JREFADETAIL, JREFBIO1NFABPROJECT, JREFMNF1NTOOL, JREF1NARTICLE, JREFPCO1NPURCHORDER, JREFSPL1NPURCHORDER, JREF1NSTOCKITEM, JREFSUP1NORG, JREFHK1NADDRESS, JREFMNPERSON, JREFSVCMNTOOL, JREFMNARTICLE, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncOrgRec::Tag
 ******************************************************************************/

void PnlFmncOrgRec::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncOrgRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncOrgRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Organization");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Organisation");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Organisme");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncOrgRec::DpchAppDo
 ******************************************************************************/

PnlFmncOrgRec::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCORGRECDO) {
	ixVDo = 0;
};

string PnlFmncOrgRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncOrgRec::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncOrgRecDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlFmncOrgRec::DpchEngData
 ******************************************************************************/

PnlFmncOrgRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCORGRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncOrgRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncOrgRec::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncOrgRec::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncOrgRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


