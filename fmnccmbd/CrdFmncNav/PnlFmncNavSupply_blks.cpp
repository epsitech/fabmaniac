/**
  * \file PnlFmncNavSupply_blks.cpp
  * job handler for job PnlFmncNavSupply (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncNavSupply::VecVDo
 ******************************************************************************/

uint PnlFmncNavSupply::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butartviewclick") return BUTARTVIEWCLICK;
	else if (s == "butartnewcrdclick") return BUTARTNEWCRDCLICK;
	else if (s == "butskiviewclick") return BUTSKIVIEWCLICK;
	else if (s == "butskinewcrdclick") return BUTSKINEWCRDCLICK;
	else if (s == "butpcoviewclick") return BUTPCOVIEWCLICK;
	else if (s == "butpconewcrdclick") return BUTPCONEWCRDCLICK;

	return(0);
};

string PnlFmncNavSupply::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTARTVIEWCLICK) return("ButArtViewClick");
	else if (ix == BUTARTNEWCRDCLICK) return("ButArtNewcrdClick");
	else if (ix == BUTSKIVIEWCLICK) return("ButSkiViewClick");
	else if (ix == BUTSKINEWCRDCLICK) return("ButSkiNewcrdClick");
	else if (ix == BUTPCOVIEWCLICK) return("ButPcoViewClick");
	else if (ix == BUTPCONEWCRDCLICK) return("ButPcoNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlFmncNavSupply::ContIac
 ******************************************************************************/

PnlFmncNavSupply::ContIac::ContIac(
			const uint numFLstArt
			, const uint numFLstSki
			, const uint numFLstPco
		) : Block() {
	this->numFLstArt = numFLstArt;
	this->numFLstSki = numFLstSki;
	this->numFLstPco = numFLstPco;

	mask = {NUMFLSTART, NUMFLSTSKI, NUMFLSTPCO};
};

bool PnlFmncNavSupply::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncNavSupply");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncNavSupply";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstArt", numFLstArt)) add(NUMFLSTART);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSki", numFLstSki)) add(NUMFLSTSKI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPco", numFLstPco)) add(NUMFLSTPCO);
	};

	return basefound;
};

void PnlFmncNavSupply::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncNavSupply";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncNavSupply";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstArt", numFLstArt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSki", numFLstSki);
		writeUintAttr(wr, itemtag, "sref", "numFLstPco", numFLstPco);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavSupply::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstArt == comp->numFLstArt) insert(items, NUMFLSTART);
	if (numFLstSki == comp->numFLstSki) insert(items, NUMFLSTSKI);
	if (numFLstPco == comp->numFLstPco) insert(items, NUMFLSTPCO);

	return(items);
};

set<uint> PnlFmncNavSupply::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTART, NUMFLSTSKI, NUMFLSTPCO};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavSupply::StatApp
 ******************************************************************************/

void PnlFmncNavSupply::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
			, const bool LstArtAlt
			, const bool LstSkiAlt
			, const bool LstPcoAlt
			, const uint LstArtNumFirstdisp
			, const uint LstSkiNumFirstdisp
			, const uint LstPcoNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncNavSupply";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncNavSupply";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstArtAlt", LstArtAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSkiAlt", LstSkiAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPcoAlt", LstPcoAlt);
		writeUintAttr(wr, itemtag, "sref", "LstArtNumFirstdisp", LstArtNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSkiNumFirstdisp", LstSkiNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPcoNumFirstdisp", LstPcoNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavSupply::StatShr
 ******************************************************************************/

PnlFmncNavSupply::StatShr::StatShr(
			const bool LstArtAvail
			, const bool ButArtViewActive
			, const bool LstSkiAvail
			, const bool ButSkiViewActive
			, const bool LstPcoAvail
			, const bool ButPcoViewActive
		) : Block() {
	this->LstArtAvail = LstArtAvail;
	this->ButArtViewActive = ButArtViewActive;
	this->LstSkiAvail = LstSkiAvail;
	this->ButSkiViewActive = ButSkiViewActive;
	this->LstPcoAvail = LstPcoAvail;
	this->ButPcoViewActive = ButPcoViewActive;

	mask = {LSTARTAVAIL, BUTARTVIEWACTIVE, LSTSKIAVAIL, BUTSKIVIEWACTIVE, LSTPCOAVAIL, BUTPCOVIEWACTIVE};
};

void PnlFmncNavSupply::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncNavSupply";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncNavSupply";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstArtAvail", LstArtAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButArtViewActive", ButArtViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSkiAvail", LstSkiAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSkiViewActive", ButSkiViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPcoAvail", LstPcoAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPcoViewActive", ButPcoViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavSupply::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstArtAvail == comp->LstArtAvail) insert(items, LSTARTAVAIL);
	if (ButArtViewActive == comp->ButArtViewActive) insert(items, BUTARTVIEWACTIVE);
	if (LstSkiAvail == comp->LstSkiAvail) insert(items, LSTSKIAVAIL);
	if (ButSkiViewActive == comp->ButSkiViewActive) insert(items, BUTSKIVIEWACTIVE);
	if (LstPcoAvail == comp->LstPcoAvail) insert(items, LSTPCOAVAIL);
	if (ButPcoViewActive == comp->ButPcoViewActive) insert(items, BUTPCOVIEWACTIVE);

	return(items);
};

set<uint> PnlFmncNavSupply::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTARTAVAIL, BUTARTVIEWACTIVE, LSTSKIAVAIL, BUTSKIVIEWACTIVE, LSTPCOAVAIL, BUTPCOVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavSupply::Tag
 ******************************************************************************/

void PnlFmncNavSupply::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncNavSupply";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncNavSupply";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Supplies module");
			writeStringAttr(wr, itemtag, "sref", "CptArt", "articles");
			writeStringAttr(wr, itemtag, "sref", "CptSki", "stock items");
			writeStringAttr(wr, itemtag, "sref", "CptPco", "purchase orders");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Lagerhaltung");
			writeStringAttr(wr, itemtag, "sref", "CptArt", "Artikel");
			writeStringAttr(wr, itemtag, "sref", "CptSki", "Lagerposten");
			writeStringAttr(wr, itemtag, "sref", "CptPco", "Bestellungen");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Partie stockage");
			writeStringAttr(wr, itemtag, "sref", "CptArt", "articles");
			writeStringAttr(wr, itemtag, "sref", "CptSki", "postes du stock");
			writeStringAttr(wr, itemtag, "sref", "CptPco", "commandes");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavSupply::DpchAppData
 ******************************************************************************/

PnlFmncNavSupply::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVSUPPLYDATA) {
};

string PnlFmncNavSupply::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavSupply::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavSupplyData");
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
 class PnlFmncNavSupply::DpchAppDo
 ******************************************************************************/

PnlFmncNavSupply::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVSUPPLYDO) {
	ixVDo = 0;
};

string PnlFmncNavSupply::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavSupply::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavSupplyDo");
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
 class PnlFmncNavSupply::DpchEngData
 ******************************************************************************/

PnlFmncNavSupply::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstArt
			, Feed* feedFLstPco
			, Feed* feedFLstSki
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVSUPPLYDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTART, FEEDFLSTPCO, FEEDFLSTSKI, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTART) && feedFLstArt) this->feedFLstArt = *feedFLstArt;
	if (find(this->mask, FEEDFLSTPCO) && feedFLstPco) this->feedFLstPco = *feedFLstPco;
	if (find(this->mask, FEEDFLSTSKI) && feedFLstSki) this->feedFLstSki = *feedFLstSki;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncNavSupply::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTART)) ss.push_back("feedFLstArt");
	if (has(FEEDFLSTPCO)) ss.push_back("feedFLstPco");
	if (has(FEEDFLSTSKI)) ss.push_back("feedFLstSki");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavSupply::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTART)) {feedFLstArt = src->feedFLstArt; add(FEEDFLSTART);};
	if (src->has(FEEDFLSTPCO)) {feedFLstPco = src->feedFLstPco; add(FEEDFLSTPCO);};
	if (src->has(FEEDFLSTSKI)) {feedFLstSki = src->feedFLstSki; add(FEEDFLSTSKI);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncNavSupply::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncNavSupplyData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTART)) feedFLstArt.writeXML(wr);
		if (has(FEEDFLSTPCO)) feedFLstPco.writeXML(wr);
		if (has(FEEDFLSTSKI)) feedFLstSki.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


