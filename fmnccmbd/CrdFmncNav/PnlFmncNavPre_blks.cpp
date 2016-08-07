/**
  * \file PnlFmncNavPre_blks.cpp
  * job handler for job PnlFmncNavPre (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncNavPre::VecVDo
 ******************************************************************************/

uint PnlFmncNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butfabremoveclick") return BUTFABREMOVECLICK;
	else if (s == "butrunremoveclick") return BUTRUNREMOVECLICK;

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

void PnlFmncNavPre::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfFmncNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfFmncNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFab", TxtFab);
		writeStringAttr(wr, itemtag, "sref", "TxtRun", TxtRun);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFab == comp->TxtFab) insert(items, TXTFAB);
	if (TxtRun == comp->TxtRun) insert(items, TXTRUN);

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

void PnlFmncNavPre::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncNavPre";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxtFabAvail", TxtFabAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtRunAvail", TxtRunAvail);
	xmlTextWriterEndElement(wr);
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

void PnlFmncNavPre::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptFab", "fab");
			writeStringAttr(wr, itemtag, "sref", "CptRun", "run");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptFab", "Reinraum");
			writeStringAttr(wr, itemtag, "sref", "CptRun", "Lauf");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "CptFab", "salle blanche");
			writeStringAttr(wr, itemtag, "sref", "CptRun", "d\\u00e9roulement");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavPre::DpchAppDo
 ******************************************************************************/

PnlFmncNavPre::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVPREDO) {
	ixVDo = 0;
};

string PnlFmncNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavPre::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavPreDo");
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
 class PnlFmncNavPre::DpchEngData
 ******************************************************************************/

PnlFmncNavPre::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVPREDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavPre::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncNavPre::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncNavPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


