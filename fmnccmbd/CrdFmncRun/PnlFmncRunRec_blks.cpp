/**
  * \file PnlFmncRunRec_blks.cpp
  * job handler for job PnlFmncRunRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncRunRec::VecVDo
 ******************************************************************************/

uint PnlFmncRunRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

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

void PnlFmncRunRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncRunRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncRunRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncRunRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

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

void PnlFmncRunRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneRun1NActivity
			, const bool initdoneRef1NFile
			, const bool initdoneMNSample
			, const bool initdoneMNPerson
			, const bool initdoneMNFab
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncRunRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncRunRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRun1NActivity", initdoneRun1NActivity);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NFile", initdoneRef1NFile);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNSample", initdoneMNSample);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNPerson", initdoneMNPerson);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNFab", initdoneMNFab);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncRunRec::StatShr
 ******************************************************************************/

PnlFmncRunRec::StatShr::StatShr(
			const uint ixFmncVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefRun1NActivity
			, const ubigint jrefRef1NFile
			, const ubigint jrefMNSample
			, const ubigint jrefMNPerson
			, const ubigint jrefMNFab
			, const bool ButRegularizeActive
		) : Block() {
	this->ixFmncVExpstate = ixFmncVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefRun1NActivity = jrefRun1NActivity;
	this->jrefRef1NFile = jrefRef1NFile;
	this->jrefMNSample = jrefMNSample;
	this->jrefMNPerson = jrefMNPerson;
	this->jrefMNFab = jrefMNFab;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXFMNCVEXPSTATE, JREFDETAIL, JREFRUN1NACTIVITY, JREFREF1NFILE, JREFMNSAMPLE, JREFMNPERSON, JREFMNFAB, BUTREGULARIZEACTIVE};
};

void PnlFmncRunRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncRunRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncRunRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRun1NActivity", Scr::scramble(mScr, scr, descr, jrefRun1NActivity));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NFile", Scr::scramble(mScr, scr, descr, jrefRef1NFile));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNSample", Scr::scramble(mScr, scr, descr, jrefMNSample));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNPerson", Scr::scramble(mScr, scr, descr, jrefMNPerson));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNFab", Scr::scramble(mScr, scr, descr, jrefMNFab));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncRunRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixFmncVExpstate == comp->ixFmncVExpstate) insert(items, IXFMNCVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefRun1NActivity == comp->jrefRun1NActivity) insert(items, JREFRUN1NACTIVITY);
	if (jrefRef1NFile == comp->jrefRef1NFile) insert(items, JREFREF1NFILE);
	if (jrefMNSample == comp->jrefMNSample) insert(items, JREFMNSAMPLE);
	if (jrefMNPerson == comp->jrefMNPerson) insert(items, JREFMNPERSON);
	if (jrefMNFab == comp->jrefMNFab) insert(items, JREFMNFAB);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlFmncRunRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXFMNCVEXPSTATE, JREFDETAIL, JREFRUN1NACTIVITY, JREFREF1NFILE, JREFMNSAMPLE, JREFMNPERSON, JREFMNFAB, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncRunRec::Tag
 ******************************************************************************/

void PnlFmncRunRec::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncRunRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncRunRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Run");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Lauf");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "D\\u00e9roulement");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncRunRec::DpchAppDo
 ******************************************************************************/

PnlFmncRunRec::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCRUNRECDO) {
	ixVDo = 0;
};

string PnlFmncRunRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncRunRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncRunRecDo");
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
 class PnlFmncRunRec::DpchEngData
 ******************************************************************************/

PnlFmncRunRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCRUNRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncRunRec::DpchEngData::getSrefsMask() {
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

void PnlFmncRunRec::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncRunRec::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncRunRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


