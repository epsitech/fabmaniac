/**
  * \file PnlFmncNavLabbook_blks.cpp
  * job handler for job PnlFmncNavLabbook (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncNavLabbook::VecVDo
 ******************************************************************************/

uint PnlFmncNavLabbook::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butstpviewclick") return BUTSTPVIEWCLICK;
	else if (s == "butstpnewcrdclick") return BUTSTPNEWCRDCLICK;
	else if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	else if (s == "butprjnewcrdclick") return BUTPRJNEWCRDCLICK;
	else if (s == "butrunviewclick") return BUTRUNVIEWCLICK;
	else if (s == "butrunnewcrdclick") return BUTRUNNEWCRDCLICK;
	else if (s == "butactviewclick") return BUTACTVIEWCLICK;
	else if (s == "butactnewcrdclick") return BUTACTNEWCRDCLICK;
	else if (s == "butsepviewclick") return BUTSEPVIEWCLICK;
	else if (s == "butsepnewcrdclick") return BUTSEPNEWCRDCLICK;
	else if (s == "butsmpviewclick") return BUTSMPVIEWCLICK;
	else if (s == "butsmpnewcrdclick") return BUTSMPNEWCRDCLICK;

	return(0);
};

string PnlFmncNavLabbook::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSTPVIEWCLICK) return("ButStpViewClick");
	else if (ix == BUTSTPNEWCRDCLICK) return("ButStpNewcrdClick");
	else if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	else if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
	else if (ix == BUTRUNVIEWCLICK) return("ButRunViewClick");
	else if (ix == BUTRUNNEWCRDCLICK) return("ButRunNewcrdClick");
	else if (ix == BUTACTVIEWCLICK) return("ButActViewClick");
	else if (ix == BUTACTNEWCRDCLICK) return("ButActNewcrdClick");
	else if (ix == BUTSEPVIEWCLICK) return("ButSepViewClick");
	else if (ix == BUTSEPNEWCRDCLICK) return("ButSepNewcrdClick");
	else if (ix == BUTSMPVIEWCLICK) return("ButSmpViewClick");
	else if (ix == BUTSMPNEWCRDCLICK) return("ButSmpNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlFmncNavLabbook::ContIac
 ******************************************************************************/

PnlFmncNavLabbook::ContIac::ContIac(
			const uint numFLstStp
			, const uint numFLstPrj
			, const uint numFLstRun
			, const uint numFLstAct
			, const uint numFLstSep
			, const uint numFLstSmp
		) : Block() {
	this->numFLstStp = numFLstStp;
	this->numFLstPrj = numFLstPrj;
	this->numFLstRun = numFLstRun;
	this->numFLstAct = numFLstAct;
	this->numFLstSep = numFLstSep;
	this->numFLstSmp = numFLstSmp;

	mask = {NUMFLSTSTP, NUMFLSTPRJ, NUMFLSTRUN, NUMFLSTACT, NUMFLSTSEP, NUMFLSTSMP};
};

bool PnlFmncNavLabbook::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncNavLabbook");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncNavLabbook";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstStp", numFLstStp)) add(NUMFLSTSTP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrj", numFLstPrj)) add(NUMFLSTPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRun", numFLstRun)) add(NUMFLSTRUN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstAct", numFLstAct)) add(NUMFLSTACT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSep", numFLstSep)) add(NUMFLSTSEP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSmp", numFLstSmp)) add(NUMFLSTSMP);
	};

	return basefound;
};

void PnlFmncNavLabbook::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncNavLabbook";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncNavLabbook";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstStp", numFLstStp);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrj", numFLstPrj);
		writeUintAttr(wr, itemtag, "sref", "numFLstRun", numFLstRun);
		writeUintAttr(wr, itemtag, "sref", "numFLstAct", numFLstAct);
		writeUintAttr(wr, itemtag, "sref", "numFLstSep", numFLstSep);
		writeUintAttr(wr, itemtag, "sref", "numFLstSmp", numFLstSmp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavLabbook::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstStp == comp->numFLstStp) insert(items, NUMFLSTSTP);
	if (numFLstPrj == comp->numFLstPrj) insert(items, NUMFLSTPRJ);
	if (numFLstRun == comp->numFLstRun) insert(items, NUMFLSTRUN);
	if (numFLstAct == comp->numFLstAct) insert(items, NUMFLSTACT);
	if (numFLstSep == comp->numFLstSep) insert(items, NUMFLSTSEP);
	if (numFLstSmp == comp->numFLstSmp) insert(items, NUMFLSTSMP);

	return(items);
};

set<uint> PnlFmncNavLabbook::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTSTP, NUMFLSTPRJ, NUMFLSTRUN, NUMFLSTACT, NUMFLSTSEP, NUMFLSTSMP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavLabbook::StatApp
 ******************************************************************************/

void PnlFmncNavLabbook::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
			, const bool LstStpAlt
			, const bool LstPrjAlt
			, const bool LstRunAlt
			, const bool LstActAlt
			, const bool LstSepAlt
			, const bool LstSmpAlt
			, const uint LstStpNumFirstdisp
			, const uint LstPrjNumFirstdisp
			, const uint LstRunNumFirstdisp
			, const uint LstActNumFirstdisp
			, const uint LstSepNumFirstdisp
			, const uint LstSmpNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncNavLabbook";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncNavLabbook";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstStpAlt", LstStpAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAlt", LstPrjAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRunAlt", LstRunAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstActAlt", LstActAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSepAlt", LstSepAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSmpAlt", LstSmpAlt);
		writeUintAttr(wr, itemtag, "sref", "LstStpNumFirstdisp", LstStpNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRunNumFirstdisp", LstRunNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstActNumFirstdisp", LstActNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSepNumFirstdisp", LstSepNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSmpNumFirstdisp", LstSmpNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavLabbook::StatShr
 ******************************************************************************/

PnlFmncNavLabbook::StatShr::StatShr(
			const bool LstStpAvail
			, const bool ButStpViewActive
			, const bool LstPrjAvail
			, const bool ButPrjViewActive
			, const bool LstRunAvail
			, const bool ButRunViewActive
			, const bool LstActAvail
			, const bool ButActViewActive
			, const bool ButActNewcrdActive
			, const bool LstSepAvail
			, const bool ButSepViewActive
			, const bool ButSepNewcrdActive
			, const bool LstSmpAvail
			, const bool ButSmpViewActive
		) : Block() {
	this->LstStpAvail = LstStpAvail;
	this->ButStpViewActive = ButStpViewActive;
	this->LstPrjAvail = LstPrjAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->LstRunAvail = LstRunAvail;
	this->ButRunViewActive = ButRunViewActive;
	this->LstActAvail = LstActAvail;
	this->ButActViewActive = ButActViewActive;
	this->ButActNewcrdActive = ButActNewcrdActive;
	this->LstSepAvail = LstSepAvail;
	this->ButSepViewActive = ButSepViewActive;
	this->ButSepNewcrdActive = ButSepNewcrdActive;
	this->LstSmpAvail = LstSmpAvail;
	this->ButSmpViewActive = ButSmpViewActive;

	mask = {LSTSTPAVAIL, BUTSTPVIEWACTIVE, LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTRUNAVAIL, BUTRUNVIEWACTIVE, LSTACTAVAIL, BUTACTVIEWACTIVE, BUTACTNEWCRDACTIVE, LSTSEPAVAIL, BUTSEPVIEWACTIVE, BUTSEPNEWCRDACTIVE, LSTSMPAVAIL, BUTSMPVIEWACTIVE};
};

void PnlFmncNavLabbook::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncNavLabbook";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncNavLabbook";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstStpAvail", LstStpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStpViewActive", ButStpViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAvail", LstPrjAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewActive", ButPrjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRunAvail", LstRunAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRunViewActive", ButRunViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstActAvail", LstActAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButActViewActive", ButActViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButActNewcrdActive", ButActNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSepAvail", LstSepAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSepViewActive", ButSepViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSepNewcrdActive", ButSepNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSmpAvail", LstSmpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSmpViewActive", ButSmpViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavLabbook::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstStpAvail == comp->LstStpAvail) insert(items, LSTSTPAVAIL);
	if (ButStpViewActive == comp->ButStpViewActive) insert(items, BUTSTPVIEWACTIVE);
	if (LstPrjAvail == comp->LstPrjAvail) insert(items, LSTPRJAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (LstRunAvail == comp->LstRunAvail) insert(items, LSTRUNAVAIL);
	if (ButRunViewActive == comp->ButRunViewActive) insert(items, BUTRUNVIEWACTIVE);
	if (LstActAvail == comp->LstActAvail) insert(items, LSTACTAVAIL);
	if (ButActViewActive == comp->ButActViewActive) insert(items, BUTACTVIEWACTIVE);
	if (ButActNewcrdActive == comp->ButActNewcrdActive) insert(items, BUTACTNEWCRDACTIVE);
	if (LstSepAvail == comp->LstSepAvail) insert(items, LSTSEPAVAIL);
	if (ButSepViewActive == comp->ButSepViewActive) insert(items, BUTSEPVIEWACTIVE);
	if (ButSepNewcrdActive == comp->ButSepNewcrdActive) insert(items, BUTSEPNEWCRDACTIVE);
	if (LstSmpAvail == comp->LstSmpAvail) insert(items, LSTSMPAVAIL);
	if (ButSmpViewActive == comp->ButSmpViewActive) insert(items, BUTSMPVIEWACTIVE);

	return(items);
};

set<uint> PnlFmncNavLabbook::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTSTPAVAIL, BUTSTPVIEWACTIVE, LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTRUNAVAIL, BUTRUNVIEWACTIVE, LSTACTAVAIL, BUTACTVIEWACTIVE, BUTACTNEWCRDACTIVE, LSTSEPAVAIL, BUTSEPVIEWACTIVE, BUTSEPNEWCRDACTIVE, LSTSMPAVAIL, BUTSMPVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavLabbook::Tag
 ******************************************************************************/

void PnlFmncNavLabbook::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncNavLabbook";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncNavLabbook";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Electronic labbook module");
			writeStringAttr(wr, itemtag, "sref", "CptStp", "recipes");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "projects");
			writeStringAttr(wr, itemtag, "sref", "CptRun", "runs");
			writeStringAttr(wr, itemtag, "sref", "CptAct", "activities");
			writeStringAttr(wr, itemtag, "sref", "CptSep", "steps");
			writeStringAttr(wr, itemtag, "sref", "CptSmp", "samples");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Elektronisches Laborbuch");
			writeStringAttr(wr, itemtag, "sref", "CptStp", "Rezepte");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "Projekte");
			writeStringAttr(wr, itemtag, "sref", "CptRun", "L\\u00e4ufe");
			writeStringAttr(wr, itemtag, "sref", "CptAct", "Aktivit\\u00e4ten");
			writeStringAttr(wr, itemtag, "sref", "CptSep", "Schritte");
			writeStringAttr(wr, itemtag, "sref", "CptSmp", "Samples");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Partie cahier \\u00e9lectronique");
			writeStringAttr(wr, itemtag, "sref", "CptStp", "recettes");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "projets");
			writeStringAttr(wr, itemtag, "sref", "CptRun", "d\\u00e9roulements");
			writeStringAttr(wr, itemtag, "sref", "CptAct", "activit\\u00e9s");
			writeStringAttr(wr, itemtag, "sref", "CptSep", "\\u00e9tapes");
			writeStringAttr(wr, itemtag, "sref", "CptSmp", "\\u00e9chantillons");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavLabbook::DpchAppData
 ******************************************************************************/

PnlFmncNavLabbook::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVLABBOOKDATA) {
};

string PnlFmncNavLabbook::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavLabbook::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavLabbookData");
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
 class PnlFmncNavLabbook::DpchAppDo
 ******************************************************************************/

PnlFmncNavLabbook::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVLABBOOKDO) {
	ixVDo = 0;
};

string PnlFmncNavLabbook::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavLabbook::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavLabbookDo");
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
 class PnlFmncNavLabbook::DpchEngData
 ******************************************************************************/

PnlFmncNavLabbook::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstAct
			, Feed* feedFLstPrj
			, Feed* feedFLstRun
			, Feed* feedFLstSep
			, Feed* feedFLstSmp
			, Feed* feedFLstStp
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVLABBOOKDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTACT, FEEDFLSTPRJ, FEEDFLSTRUN, FEEDFLSTSEP, FEEDFLSTSMP, FEEDFLSTSTP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTACT) && feedFLstAct) this->feedFLstAct = *feedFLstAct;
	if (find(this->mask, FEEDFLSTPRJ) && feedFLstPrj) this->feedFLstPrj = *feedFLstPrj;
	if (find(this->mask, FEEDFLSTRUN) && feedFLstRun) this->feedFLstRun = *feedFLstRun;
	if (find(this->mask, FEEDFLSTSEP) && feedFLstSep) this->feedFLstSep = *feedFLstSep;
	if (find(this->mask, FEEDFLSTSMP) && feedFLstSmp) this->feedFLstSmp = *feedFLstSmp;
	if (find(this->mask, FEEDFLSTSTP) && feedFLstStp) this->feedFLstStp = *feedFLstStp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncNavLabbook::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTACT)) ss.push_back("feedFLstAct");
	if (has(FEEDFLSTPRJ)) ss.push_back("feedFLstPrj");
	if (has(FEEDFLSTRUN)) ss.push_back("feedFLstRun");
	if (has(FEEDFLSTSEP)) ss.push_back("feedFLstSep");
	if (has(FEEDFLSTSMP)) ss.push_back("feedFLstSmp");
	if (has(FEEDFLSTSTP)) ss.push_back("feedFLstStp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavLabbook::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTACT)) {feedFLstAct = src->feedFLstAct; add(FEEDFLSTACT);};
	if (src->has(FEEDFLSTPRJ)) {feedFLstPrj = src->feedFLstPrj; add(FEEDFLSTPRJ);};
	if (src->has(FEEDFLSTRUN)) {feedFLstRun = src->feedFLstRun; add(FEEDFLSTRUN);};
	if (src->has(FEEDFLSTSEP)) {feedFLstSep = src->feedFLstSep; add(FEEDFLSTSEP);};
	if (src->has(FEEDFLSTSMP)) {feedFLstSmp = src->feedFLstSmp; add(FEEDFLSTSMP);};
	if (src->has(FEEDFLSTSTP)) {feedFLstStp = src->feedFLstStp; add(FEEDFLSTSTP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncNavLabbook::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncNavLabbookData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTACT)) feedFLstAct.writeXML(wr);
		if (has(FEEDFLSTPRJ)) feedFLstPrj.writeXML(wr);
		if (has(FEEDFLSTRUN)) feedFLstRun.writeXML(wr);
		if (has(FEEDFLSTSEP)) feedFLstSep.writeXML(wr);
		if (has(FEEDFLSTSMP)) feedFLstSmp.writeXML(wr);
		if (has(FEEDFLSTSTP)) feedFLstStp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


