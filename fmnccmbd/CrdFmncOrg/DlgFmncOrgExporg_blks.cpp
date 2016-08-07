/**
  * \file DlgFmncOrgExporg_blks.cpp
  * job handler for job DlgFmncOrgExporg (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class DlgFmncOrgExporg::VecVDit
 ******************************************************************************/

uint DlgFmncOrgExporg::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "prp") return PRP;
	else if (s == "fia") return FIA;

	return(0);
};

string DlgFmncOrgExporg::VecVDit::getSref(
			const uint ix
		) {
	if (ix == PRP) return("Prp");
	else if (ix == FIA) return("Fia");

	return("");
};

string DlgFmncOrgExporg::VecVDit::getTitle(
			const uint ix
			, const uint ixFmncVLocale
		) {
	if (ixFmncVLocale == 1) {
		if (ix == PRP) return("Preparation");
		else if (ix == FIA) return("File archive");
	} else if (ixFmncVLocale == 2) {
		if (ix == PRP) return("Vorbereitung");
		else if (ix == FIA) return("Dateiarchiv");
	} else if (ixFmncVLocale == 3) {
		if (ix == PRP) return("Pr\\u00e9paration");
		else if (ix == FIA) return("Archive");
	};

	return("");
};

void DlgFmncOrgExporg::VecVDit::fillFeed(
			const uint ixFmncVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixFmncVLocale));
};

/******************************************************************************
 class DlgFmncOrgExporg::VecVDo
 ******************************************************************************/

uint DlgFmncOrgExporg::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgFmncOrgExporg::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgFmncOrgExporg::VecVDoPrp
 ******************************************************************************/

uint DlgFmncOrgExporg::VecVDoPrp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	else if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgFmncOrgExporg::VecVDoPrp::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	else if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgFmncOrgExporg::VecVSge
 ******************************************************************************/

uint DlgFmncOrgExporg::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "colidle") return COLIDLE;
	else if (s == "collect") return COLLECT;
	else if (s == "export") return EXPORT;
	else if (s == "pack") return PACK;
	else if (s == "done") return DONE;

	return(0);
};

string DlgFmncOrgExporg::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == COLIDLE) return("colidle");
	else if (ix == COLLECT) return("collect");
	else if (ix == EXPORT) return("export");
	else if (ix == PACK) return("pack");
	else if (ix == DONE) return("done");

	return("");
};

void DlgFmncOrgExporg::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=6;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgFmncOrgExporg::ContIac
 ******************************************************************************/

DlgFmncOrgExporg::ContIac::ContIac(
			const uint numFDse
		) : Block() {
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgFmncOrgExporg::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgFmncOrgExporg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgFmncOrgExporg";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgFmncOrgExporg::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgFmncOrgExporg";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgFmncOrgExporg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncOrgExporg::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgFmncOrgExporg::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDSE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncOrgExporg::ContInf
 ******************************************************************************/

DlgFmncOrgExporg::ContInf::ContInf(
			const uint numFSge
		) : Block() {
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgFmncOrgExporg::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgFmncOrgExporg";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgFmncOrgExporg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncOrgExporg::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgFmncOrgExporg::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncOrgExporg::ContInfPrp
 ******************************************************************************/

DlgFmncOrgExporg::ContInfPrp::ContInfPrp(
			const string& TxtPrg
		) : Block() {
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgFmncOrgExporg::ContInfPrp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgFmncOrgExporgPrp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgFmncOrgExporgPrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncOrgExporg::ContInfPrp::comm(
			const ContInfPrp* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgFmncOrgExporg::ContInfPrp::diff(
			const ContInfPrp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncOrgExporg::StatApp
 ******************************************************************************/

void DlgFmncOrgExporg::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgFmncOrgExporg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgFmncOrgExporg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncOrgExporg::StatShr
 ******************************************************************************/

DlgFmncOrgExporg::StatShr::StatShr(
			const bool ButDneActive
		) : Block() {
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgFmncOrgExporg::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgFmncOrgExporg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgFmncOrgExporg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncOrgExporg::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgFmncOrgExporg::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDNEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncOrgExporg::StatShrFia
 ******************************************************************************/

DlgFmncOrgExporg::StatShrFia::StatShrFia(
			const bool DldActive
		) : Block() {
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

void DlgFmncOrgExporg::StatShrFia::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgFmncOrgExporgFia";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgFmncOrgExporgFia";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncOrgExporg::StatShrFia::comm(
			const StatShrFia* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgFmncOrgExporg::StatShrFia::diff(
			const StatShrFia* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncOrgExporg::StatShrPrp
 ******************************************************************************/

DlgFmncOrgExporg::StatShrPrp::StatShrPrp(
			const bool ButRunActive
			, const bool ButStoActive
		) : Block() {
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgFmncOrgExporg::StatShrPrp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgFmncOrgExporgPrp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgFmncOrgExporgPrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgFmncOrgExporg::StatShrPrp::comm(
			const StatShrPrp* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgFmncOrgExporg::StatShrPrp::diff(
			const StatShrPrp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgFmncOrgExporg::Tag
 ******************************************************************************/

void DlgFmncOrgExporg::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgFmncOrgExporg";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgFmncOrgExporg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Export organizational structure");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Organisationsstruktur exportieren");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Exporter structure organisationelle");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DONE, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncOrgExporg::TagFia
 ******************************************************************************/

void DlgFmncOrgExporg::TagFia::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgFmncOrgExporgFia";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgFmncOrgExporgFia";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::DOWNLOAD, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncOrgExporg::TagPrp
 ******************************************************************************/

void DlgFmncOrgExporg::TagPrp::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgFmncOrgExporgPrp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgFmncOrgExporgPrp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::PROGRESS, ixFmncVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::RUN, ixFmncVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecFmncVTag::getTitle(VecFmncVTag::STOP, ixFmncVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgFmncOrgExporg::DpchAppData
 ******************************************************************************/

DlgFmncOrgExporg::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPDLGFMNCORGEXPORGDATA) {
};

string DlgFmncOrgExporg::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncOrgExporg::DpchAppData::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgFmncOrgExporgData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class DlgFmncOrgExporg::DpchAppDo
 ******************************************************************************/

DlgFmncOrgExporg::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPDLGFMNCORGEXPORGDO) {
	ixVDo = 0;
	ixVDoPrp = 0;
};

string DlgFmncOrgExporg::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOPRP)) ss.push_back("ixVDoPrp");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncOrgExporg::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoPrp;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgFmncOrgExporgDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoPrp", "", srefIxVDoPrp)) {
			ixVDoPrp = VecVDoPrp::getIx(srefIxVDoPrp);
			add(IXVDOPRP);
		};
	} else {
	};
};

/******************************************************************************
 class DlgFmncOrgExporg::DpchEngData
 ******************************************************************************/

DlgFmncOrgExporg::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, ContInfPrp* continfprp
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrFia* statshrfia
			, StatShrPrp* statshrprp
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGDLGFMNCORGEXPORGDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, CONTINFPRP, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRFIA, STATSHRPRP, TAG, TAGFIA, TAGPRP};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFPRP) && continfprp) this->continfprp = *continfprp;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRFIA) && statshrfia) this->statshrfia = *statshrfia;
	if (find(this->mask, STATSHRPRP) && statshrprp) this->statshrprp = *statshrprp;
};

string DlgFmncOrgExporg::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFPRP)) ss.push_back("continfprp");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRFIA)) ss.push_back("statshrfia");
	if (has(STATSHRPRP)) ss.push_back("statshrprp");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGFIA)) ss.push_back("tagfia");
	if (has(TAGPRP)) ss.push_back("tagprp");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgFmncOrgExporg::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFPRP)) {continfprp = src->continfprp; add(CONTINFPRP);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRFIA)) {statshrfia = src->statshrfia; add(STATSHRFIA);};
	if (src->has(STATSHRPRP)) {statshrprp = src->statshrprp; add(STATSHRPRP);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGFIA)) add(TAGFIA);
	if (src->has(TAGPRP)) add(TAGPRP);
};

void DlgFmncOrgExporg::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgFmncOrgExporgData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFPRP)) continfprp.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRFIA)) statshrfia.writeXML(wr);
		if (has(STATSHRPRP)) statshrprp.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
		if (has(TAGFIA)) TagFia::writeXML(ixFmncVLocale, wr);
		if (has(TAGPRP)) TagPrp::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


