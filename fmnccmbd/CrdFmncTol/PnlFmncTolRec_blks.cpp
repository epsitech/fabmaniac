/**
  * \file PnlFmncTolRec_blks.cpp
  * job handler for job PnlFmncTolRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncTolRec::VecVDo
 ******************************************************************************/

uint PnlFmncTolRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

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

void PnlFmncTolRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncTolRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncTolRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncTolRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

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

void PnlFmncTolRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
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
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncTolRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncTolRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKSteppar", initdoneKSteppar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKToolchar", initdoneKToolchar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAAvl", initdoneAAvl);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAChar", initdoneAChar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneARes", initdoneARes);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAUtil", initdoneAUtil);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NArticle", initdone1NArticle);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRlv1NStep", initdoneRlv1NStep);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NFile", initdoneRef1NFile);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNTooltype", initdoneMNTooltype);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNFabuser", initdoneMNFabuser);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSvcMNOrg", initdoneSvcMNOrg);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncTolRec::StatShr
 ******************************************************************************/

PnlFmncTolRec::StatShr::StatShr(
			const uint ixFmncVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefKSteppar
			, const ubigint jrefKToolchar
			, const ubigint jrefAAvl
			, const ubigint jrefAChar
			, const ubigint jrefARes
			, const ubigint jrefAUtil
			, const ubigint jref1NArticle
			, const ubigint jrefRlv1NStep
			, const ubigint jrefRef1NFile
			, const ubigint jrefMNTooltype
			, const ubigint jrefMNFabuser
			, const ubigint jrefSvcMNOrg
			, const bool ButRegularizeActive
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefKSteppar = jrefKSteppar;
	this->jrefKToolchar = jrefKToolchar;
	this->jrefAAvl = jrefAAvl;
	this->jrefAChar = jrefAChar;
	this->jrefARes = jrefARes;
	this->jrefAUtil = jrefAUtil;
	this->jref1NArticle = jref1NArticle;
	this->jrefRlv1NStep = jrefRlv1NStep;
	this->jrefRef1NFile = jrefRef1NFile;
	this->jrefMNTooltype = jrefMNTooltype;
	this->jrefMNFabuser = jrefMNFabuser;
	this->jrefSvcMNOrg = jrefSvcMNOrg;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXFMNCVEXPSTATE, JREFDETAIL, JREFKSTEPPAR, JREFKTOOLCHAR, JREFAAVL, JREFACHAR, JREFARES, JREFAUTIL, JREF1NARTICLE, JREFRLV1NSTEP, JREFREF1NFILE, JREFMNTOOLTYPE, JREFMNFABUSER, JREFSVCMNORG, BUTREGULARIZEACTIVE};
};

void PnlFmncTolRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncTolRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncTolRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKSteppar", Scr::scramble(mScr, scr, descr, jrefKSteppar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKToolchar", Scr::scramble(mScr, scr, descr, jrefKToolchar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAAvl", Scr::scramble(mScr, scr, descr, jrefAAvl));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAChar", Scr::scramble(mScr, scr, descr, jrefAChar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefARes", Scr::scramble(mScr, scr, descr, jrefARes));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAUtil", Scr::scramble(mScr, scr, descr, jrefAUtil));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NArticle", Scr::scramble(mScr, scr, descr, jref1NArticle));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRlv1NStep", Scr::scramble(mScr, scr, descr, jrefRlv1NStep));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NFile", Scr::scramble(mScr, scr, descr, jrefRef1NFile));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNTooltype", Scr::scramble(mScr, scr, descr, jrefMNTooltype));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNFabuser", Scr::scramble(mScr, scr, descr, jrefMNFabuser));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSvcMNOrg", Scr::scramble(mScr, scr, descr, jrefSvcMNOrg));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncTolRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefKSteppar == comp->jrefKSteppar) insert(items, JREFKSTEPPAR);
	if (jrefKToolchar == comp->jrefKToolchar) insert(items, JREFKTOOLCHAR);
	if (jrefAAvl == comp->jrefAAvl) insert(items, JREFAAVL);
	if (jrefAChar == comp->jrefAChar) insert(items, JREFACHAR);
	if (jrefARes == comp->jrefARes) insert(items, JREFARES);
	if (jrefAUtil == comp->jrefAUtil) insert(items, JREFAUTIL);
	if (jref1NArticle == comp->jref1NArticle) insert(items, JREF1NARTICLE);
	if (jrefRlv1NStep == comp->jrefRlv1NStep) insert(items, JREFRLV1NSTEP);
	if (jrefRef1NFile == comp->jrefRef1NFile) insert(items, JREFREF1NFILE);
	if (jrefMNTooltype == comp->jrefMNTooltype) insert(items, JREFMNTOOLTYPE);
	if (jrefMNFabuser == comp->jrefMNFabuser) insert(items, JREFMNFABUSER);
	if (jrefSvcMNOrg == comp->jrefSvcMNOrg) insert(items, JREFSVCMNORG);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlFmncTolRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, JREFDETAIL, JREFKSTEPPAR, JREFKTOOLCHAR, JREFAAVL, JREFACHAR, JREFARES, JREFAUTIL, JREF1NARTICLE, JREFRLV1NSTEP, JREFREF1NFILE, JREFMNTOOLTYPE, JREFMNFABUSER, JREFSVCMNORG, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncTolRec::Tag
 ******************************************************************************/

void PnlFmncTolRec::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncTolRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncTolRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Tool");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Ger\\u00e4t");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "\\u00e9quipement");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncTolRec::DpchAppDo
 ******************************************************************************/

PnlFmncTolRec::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCTOLRECDO) {
	ixVDo = 0;
};

string PnlFmncTolRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncTolRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncTolRecDo");
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
 class PnlFmncTolRec::DpchEngData
 ******************************************************************************/

PnlFmncTolRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCTOLRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncTolRec::DpchEngData::getSrefsMask() {
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

void PnlFmncTolRec::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncTolRec::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncTolRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


