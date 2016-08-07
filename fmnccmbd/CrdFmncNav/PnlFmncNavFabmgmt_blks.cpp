/**
  * \file PnlFmncNavFabmgmt_blks.cpp
  * job handler for job PnlFmncNavFabmgmt (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncNavFabmgmt::VecVDo
 ******************************************************************************/

uint PnlFmncNavFabmgmt::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butfabviewclick") return BUTFABVIEWCLICK;
	else if (s == "butfabnewcrdclick") return BUTFABNEWCRDCLICK;
	else if (s == "butfusviewclick") return BUTFUSVIEWCLICK;
	else if (s == "butfusnewcrdclick") return BUTFUSNEWCRDCLICK;
	else if (s == "butttyviewclick") return BUTTTYVIEWCLICK;
	else if (s == "butttynewcrdclick") return BUTTTYNEWCRDCLICK;
	else if (s == "buttolviewclick") return BUTTOLVIEWCLICK;
	else if (s == "buttolnewcrdclick") return BUTTOLNEWCRDCLICK;
	else if (s == "butfpjviewclick") return BUTFPJVIEWCLICK;
	else if (s == "butfpjnewcrdclick") return BUTFPJNEWCRDCLICK;
	else if (s == "butbilviewclick") return BUTBILVIEWCLICK;
	else if (s == "butbilnewcrdclick") return BUTBILNEWCRDCLICK;

	return(0);
};

string PnlFmncNavFabmgmt::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTFABVIEWCLICK) return("ButFabViewClick");
	else if (ix == BUTFABNEWCRDCLICK) return("ButFabNewcrdClick");
	else if (ix == BUTFUSVIEWCLICK) return("ButFusViewClick");
	else if (ix == BUTFUSNEWCRDCLICK) return("ButFusNewcrdClick");
	else if (ix == BUTTTYVIEWCLICK) return("ButTtyViewClick");
	else if (ix == BUTTTYNEWCRDCLICK) return("ButTtyNewcrdClick");
	else if (ix == BUTTOLVIEWCLICK) return("ButTolViewClick");
	else if (ix == BUTTOLNEWCRDCLICK) return("ButTolNewcrdClick");
	else if (ix == BUTFPJVIEWCLICK) return("ButFpjViewClick");
	else if (ix == BUTFPJNEWCRDCLICK) return("ButFpjNewcrdClick");
	else if (ix == BUTBILVIEWCLICK) return("ButBilViewClick");
	else if (ix == BUTBILNEWCRDCLICK) return("ButBilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlFmncNavFabmgmt::ContIac
 ******************************************************************************/

PnlFmncNavFabmgmt::ContIac::ContIac(
			const uint numFLstFab
			, const uint numFLstFus
			, const uint numFLstTty
			, const uint numFLstTol
			, const uint numFLstFpj
			, const uint numFLstBil
		) : Block() {
	this->numFLstFab = numFLstFab;
	this->numFLstFus = numFLstFus;
	this->numFLstTty = numFLstTty;
	this->numFLstTol = numFLstTol;
	this->numFLstFpj = numFLstFpj;
	this->numFLstBil = numFLstBil;

	mask = {NUMFLSTFAB, NUMFLSTFUS, NUMFLSTTTY, NUMFLSTTOL, NUMFLSTFPJ, NUMFLSTBIL};
};

bool PnlFmncNavFabmgmt::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncNavFabmgmt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncNavFabmgmt";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFab", numFLstFab)) add(NUMFLSTFAB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFus", numFLstFus)) add(NUMFLSTFUS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTty", numFLstTty)) add(NUMFLSTTTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTol", numFLstTol)) add(NUMFLSTTOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFpj", numFLstFpj)) add(NUMFLSTFPJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstBil", numFLstBil)) add(NUMFLSTBIL);
	};

	return basefound;
};

void PnlFmncNavFabmgmt::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncNavFabmgmt";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncNavFabmgmt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstFab", numFLstFab);
		writeUintAttr(wr, itemtag, "sref", "numFLstFus", numFLstFus);
		writeUintAttr(wr, itemtag, "sref", "numFLstTty", numFLstTty);
		writeUintAttr(wr, itemtag, "sref", "numFLstTol", numFLstTol);
		writeUintAttr(wr, itemtag, "sref", "numFLstFpj", numFLstFpj);
		writeUintAttr(wr, itemtag, "sref", "numFLstBil", numFLstBil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavFabmgmt::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstFab == comp->numFLstFab) insert(items, NUMFLSTFAB);
	if (numFLstFus == comp->numFLstFus) insert(items, NUMFLSTFUS);
	if (numFLstTty == comp->numFLstTty) insert(items, NUMFLSTTTY);
	if (numFLstTol == comp->numFLstTol) insert(items, NUMFLSTTOL);
	if (numFLstFpj == comp->numFLstFpj) insert(items, NUMFLSTFPJ);
	if (numFLstBil == comp->numFLstBil) insert(items, NUMFLSTBIL);

	return(items);
};

set<uint> PnlFmncNavFabmgmt::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTFAB, NUMFLSTFUS, NUMFLSTTTY, NUMFLSTTOL, NUMFLSTFPJ, NUMFLSTBIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::StatApp
 ******************************************************************************/

void PnlFmncNavFabmgmt::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
			, const bool LstFabAlt
			, const bool LstFusAlt
			, const bool LstTtyAlt
			, const bool LstTolAlt
			, const bool LstFpjAlt
			, const bool LstBilAlt
			, const uint LstFabNumFirstdisp
			, const uint LstFusNumFirstdisp
			, const uint LstTtyNumFirstdisp
			, const uint LstTolNumFirstdisp
			, const uint LstFpjNumFirstdisp
			, const uint LstBilNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncNavFabmgmt";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncNavFabmgmt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstFabAlt", LstFabAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFusAlt", LstFusAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstTtyAlt", LstTtyAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstTolAlt", LstTolAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFpjAlt", LstFpjAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstBilAlt", LstBilAlt);
		writeUintAttr(wr, itemtag, "sref", "LstFabNumFirstdisp", LstFabNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFusNumFirstdisp", LstFusNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstTtyNumFirstdisp", LstTtyNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstTolNumFirstdisp", LstTolNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFpjNumFirstdisp", LstFpjNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstBilNumFirstdisp", LstBilNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::StatShr
 ******************************************************************************/

PnlFmncNavFabmgmt::StatShr::StatShr(
			const bool LstFabAvail
			, const bool ButFabViewActive
			, const bool LstFusAvail
			, const bool ButFusViewActive
			, const bool ButFusNewcrdActive
			, const bool LstTtyAvail
			, const bool ButTtyViewActive
			, const bool LstTolAvail
			, const bool ButTolViewActive
			, const bool ButTolNewcrdActive
			, const bool LstFpjAvail
			, const bool ButFpjViewActive
			, const bool ButFpjNewcrdActive
			, const bool LstBilAvail
			, const bool ButBilViewActive
			, const bool ButBilNewcrdActive
		) : Block() {
	this->LstFabAvail = LstFabAvail;
	this->ButFabViewActive = ButFabViewActive;
	this->LstFusAvail = LstFusAvail;
	this->ButFusViewActive = ButFusViewActive;
	this->ButFusNewcrdActive = ButFusNewcrdActive;
	this->LstTtyAvail = LstTtyAvail;
	this->ButTtyViewActive = ButTtyViewActive;
	this->LstTolAvail = LstTolAvail;
	this->ButTolViewActive = ButTolViewActive;
	this->ButTolNewcrdActive = ButTolNewcrdActive;
	this->LstFpjAvail = LstFpjAvail;
	this->ButFpjViewActive = ButFpjViewActive;
	this->ButFpjNewcrdActive = ButFpjNewcrdActive;
	this->LstBilAvail = LstBilAvail;
	this->ButBilViewActive = ButBilViewActive;
	this->ButBilNewcrdActive = ButBilNewcrdActive;

	mask = {LSTFABAVAIL, BUTFABVIEWACTIVE, LSTFUSAVAIL, BUTFUSVIEWACTIVE, BUTFUSNEWCRDACTIVE, LSTTTYAVAIL, BUTTTYVIEWACTIVE, LSTTOLAVAIL, BUTTOLVIEWACTIVE, BUTTOLNEWCRDACTIVE, LSTFPJAVAIL, BUTFPJVIEWACTIVE, BUTFPJNEWCRDACTIVE, LSTBILAVAIL, BUTBILVIEWACTIVE, BUTBILNEWCRDACTIVE};
};

void PnlFmncNavFabmgmt::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncNavFabmgmt";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncNavFabmgmt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstFabAvail", LstFabAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFabViewActive", ButFabViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFusAvail", LstFusAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFusViewActive", ButFusViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFusNewcrdActive", ButFusNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstTtyAvail", LstTtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTtyViewActive", ButTtyViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstTolAvail", LstTolAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTolViewActive", ButTolViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTolNewcrdActive", ButTolNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFpjAvail", LstFpjAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFpjViewActive", ButFpjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFpjNewcrdActive", ButFpjNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstBilAvail", LstBilAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBilViewActive", ButBilViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBilNewcrdActive", ButBilNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavFabmgmt::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstFabAvail == comp->LstFabAvail) insert(items, LSTFABAVAIL);
	if (ButFabViewActive == comp->ButFabViewActive) insert(items, BUTFABVIEWACTIVE);
	if (LstFusAvail == comp->LstFusAvail) insert(items, LSTFUSAVAIL);
	if (ButFusViewActive == comp->ButFusViewActive) insert(items, BUTFUSVIEWACTIVE);
	if (ButFusNewcrdActive == comp->ButFusNewcrdActive) insert(items, BUTFUSNEWCRDACTIVE);
	if (LstTtyAvail == comp->LstTtyAvail) insert(items, LSTTTYAVAIL);
	if (ButTtyViewActive == comp->ButTtyViewActive) insert(items, BUTTTYVIEWACTIVE);
	if (LstTolAvail == comp->LstTolAvail) insert(items, LSTTOLAVAIL);
	if (ButTolViewActive == comp->ButTolViewActive) insert(items, BUTTOLVIEWACTIVE);
	if (ButTolNewcrdActive == comp->ButTolNewcrdActive) insert(items, BUTTOLNEWCRDACTIVE);
	if (LstFpjAvail == comp->LstFpjAvail) insert(items, LSTFPJAVAIL);
	if (ButFpjViewActive == comp->ButFpjViewActive) insert(items, BUTFPJVIEWACTIVE);
	if (ButFpjNewcrdActive == comp->ButFpjNewcrdActive) insert(items, BUTFPJNEWCRDACTIVE);
	if (LstBilAvail == comp->LstBilAvail) insert(items, LSTBILAVAIL);
	if (ButBilViewActive == comp->ButBilViewActive) insert(items, BUTBILVIEWACTIVE);
	if (ButBilNewcrdActive == comp->ButBilNewcrdActive) insert(items, BUTBILNEWCRDACTIVE);

	return(items);
};

set<uint> PnlFmncNavFabmgmt::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTFABAVAIL, BUTFABVIEWACTIVE, LSTFUSAVAIL, BUTFUSVIEWACTIVE, BUTFUSNEWCRDACTIVE, LSTTTYAVAIL, BUTTTYVIEWACTIVE, LSTTOLAVAIL, BUTTOLVIEWACTIVE, BUTTOLNEWCRDACTIVE, LSTFPJAVAIL, BUTFPJVIEWACTIVE, BUTFPJNEWCRDACTIVE, LSTBILAVAIL, BUTBILVIEWACTIVE, BUTBILNEWCRDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::Tag
 ******************************************************************************/

void PnlFmncNavFabmgmt::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncNavFabmgmt";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncNavFabmgmt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Fab management module");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "fabs");
			writeStringAttr(wr, itemtag, "sref", "CptFus", "fab users");
			writeStringAttr(wr, itemtag, "sref", "CptTty", "tool types");
			writeStringAttr(wr, itemtag, "sref", "CptTol", "tools");
			writeStringAttr(wr, itemtag, "sref", "CptFpj", "fab projects");
			writeStringAttr(wr, itemtag, "sref", "CptBil", "bills");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Reinraum-Verwaltung");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "Reinr\\u00e4ume");
			writeStringAttr(wr, itemtag, "sref", "CptFus", "Reinraumnutzer");
			writeStringAttr(wr, itemtag, "sref", "CptTty", "Ger\\u00e4tetypen");
			writeStringAttr(wr, itemtag, "sref", "CptTol", "Ger\\u00e4te");
			writeStringAttr(wr, itemtag, "sref", "CptFpj", "Reinraumprojekte");
			writeStringAttr(wr, itemtag, "sref", "CptBil", "Rechnungen");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Partie gestion salle blanche");
			writeStringAttr(wr, itemtag, "sref", "CptFab", "salles blanches");
			writeStringAttr(wr, itemtag, "sref", "CptFus", "utilisateurs salle blanche");
			writeStringAttr(wr, itemtag, "sref", "CptTty", "types d'\\u00e9quipement");
			writeStringAttr(wr, itemtag, "sref", "CptTol", "\\u00e9quipements");
			writeStringAttr(wr, itemtag, "sref", "CptFpj", "projets salle blanche");
			writeStringAttr(wr, itemtag, "sref", "CptBil", "factures");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavFabmgmt::DpchAppData
 ******************************************************************************/

PnlFmncNavFabmgmt::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVFABMGMTDATA) {
};

string PnlFmncNavFabmgmt::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavFabmgmt::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavFabmgmtData");
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
 class PnlFmncNavFabmgmt::DpchAppDo
 ******************************************************************************/

PnlFmncNavFabmgmt::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVFABMGMTDO) {
	ixVDo = 0;
};

string PnlFmncNavFabmgmt::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavFabmgmt::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavFabmgmtDo");
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
 class PnlFmncNavFabmgmt::DpchEngData
 ******************************************************************************/

PnlFmncNavFabmgmt::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstBil
			, Feed* feedFLstFab
			, Feed* feedFLstFpj
			, Feed* feedFLstFus
			, Feed* feedFLstTol
			, Feed* feedFLstTty
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVFABMGMTDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTBIL, FEEDFLSTFAB, FEEDFLSTFPJ, FEEDFLSTFUS, FEEDFLSTTOL, FEEDFLSTTTY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTBIL) && feedFLstBil) this->feedFLstBil = *feedFLstBil;
	if (find(this->mask, FEEDFLSTFAB) && feedFLstFab) this->feedFLstFab = *feedFLstFab;
	if (find(this->mask, FEEDFLSTFPJ) && feedFLstFpj) this->feedFLstFpj = *feedFLstFpj;
	if (find(this->mask, FEEDFLSTFUS) && feedFLstFus) this->feedFLstFus = *feedFLstFus;
	if (find(this->mask, FEEDFLSTTOL) && feedFLstTol) this->feedFLstTol = *feedFLstTol;
	if (find(this->mask, FEEDFLSTTTY) && feedFLstTty) this->feedFLstTty = *feedFLstTty;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncNavFabmgmt::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTBIL)) ss.push_back("feedFLstBil");
	if (has(FEEDFLSTFAB)) ss.push_back("feedFLstFab");
	if (has(FEEDFLSTFPJ)) ss.push_back("feedFLstFpj");
	if (has(FEEDFLSTFUS)) ss.push_back("feedFLstFus");
	if (has(FEEDFLSTTOL)) ss.push_back("feedFLstTol");
	if (has(FEEDFLSTTTY)) ss.push_back("feedFLstTty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavFabmgmt::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTBIL)) {feedFLstBil = src->feedFLstBil; add(FEEDFLSTBIL);};
	if (src->has(FEEDFLSTFAB)) {feedFLstFab = src->feedFLstFab; add(FEEDFLSTFAB);};
	if (src->has(FEEDFLSTFPJ)) {feedFLstFpj = src->feedFLstFpj; add(FEEDFLSTFPJ);};
	if (src->has(FEEDFLSTFUS)) {feedFLstFus = src->feedFLstFus; add(FEEDFLSTFUS);};
	if (src->has(FEEDFLSTTOL)) {feedFLstTol = src->feedFLstTol; add(FEEDFLSTTOL);};
	if (src->has(FEEDFLSTTTY)) {feedFLstTty = src->feedFLstTty; add(FEEDFLSTTTY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncNavFabmgmt::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncNavFabmgmtData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTBIL)) feedFLstBil.writeXML(wr);
		if (has(FEEDFLSTFAB)) feedFLstFab.writeXML(wr);
		if (has(FEEDFLSTFPJ)) feedFLstFpj.writeXML(wr);
		if (has(FEEDFLSTFUS)) feedFLstFus.writeXML(wr);
		if (has(FEEDFLSTTOL)) feedFLstTol.writeXML(wr);
		if (has(FEEDFLSTTTY)) feedFLstTty.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


