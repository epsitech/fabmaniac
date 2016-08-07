/**
  * \file PnlFmncNavAdmin_blks.cpp
  * job handler for job PnlFmncNavAdmin (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

/******************************************************************************
 class PnlFmncNavAdmin::VecVDo
 ******************************************************************************/

uint PnlFmncNavAdmin::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;
	else if (s == "butusgnewcrdclick") return BUTUSGNEWCRDCLICK;
	else if (s == "butusrviewclick") return BUTUSRVIEWCLICK;
	else if (s == "butusrnewcrdclick") return BUTUSRNEWCRDCLICK;
	else if (s == "butorgviewclick") return BUTORGVIEWCLICK;
	else if (s == "butorgnewcrdclick") return BUTORGNEWCRDCLICK;
	else if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	else if (s == "butprsnewcrdclick") return BUTPRSNEWCRDCLICK;
	else if (s == "butadrviewclick") return BUTADRVIEWCLICK;
	else if (s == "butadrnewcrdclick") return BUTADRNEWCRDCLICK;
	else if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	else if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;

	return(0);
};

string PnlFmncNavAdmin::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	else if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
	else if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
	else if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
	else if (ix == BUTORGVIEWCLICK) return("ButOrgViewClick");
	else if (ix == BUTORGNEWCRDCLICK) return("ButOrgNewcrdClick");
	else if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	else if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");
	else if (ix == BUTADRVIEWCLICK) return("ButAdrViewClick");
	else if (ix == BUTADRNEWCRDCLICK) return("ButAdrNewcrdClick");
	else if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	else if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlFmncNavAdmin::ContIac
 ******************************************************************************/

PnlFmncNavAdmin::ContIac::ContIac(
			const uint numFLstUsg
			, const uint numFLstUsr
			, const uint numFLstOrg
			, const uint numFLstPrs
			, const uint numFLstAdr
			, const uint numFLstFil
		) : Block() {
	this->numFLstUsg = numFLstUsg;
	this->numFLstUsr = numFLstUsr;
	this->numFLstOrg = numFLstOrg;
	this->numFLstPrs = numFLstPrs;
	this->numFLstAdr = numFLstAdr;
	this->numFLstFil = numFLstFil;

	mask = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTORG, NUMFLSTPRS, NUMFLSTADR, NUMFLSTFIL};
};

bool PnlFmncNavAdmin::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacFmncNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacFmncNavAdmin";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsg", numFLstUsg)) add(NUMFLSTUSG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsr", numFLstUsr)) add(NUMFLSTUSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOrg", numFLstOrg)) add(NUMFLSTORG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrs", numFLstPrs)) add(NUMFLSTPRS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstAdr", numFLstAdr)) add(NUMFLSTADR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
	};

	return basefound;
};

void PnlFmncNavAdmin::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacFmncNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacFmncNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstUsg", numFLstUsg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUsr", numFLstUsr);
		writeUintAttr(wr, itemtag, "sref", "numFLstOrg", numFLstOrg);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrs", numFLstPrs);
		writeUintAttr(wr, itemtag, "sref", "numFLstAdr", numFLstAdr);
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavAdmin::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstUsg == comp->numFLstUsg) insert(items, NUMFLSTUSG);
	if (numFLstUsr == comp->numFLstUsr) insert(items, NUMFLSTUSR);
	if (numFLstOrg == comp->numFLstOrg) insert(items, NUMFLSTORG);
	if (numFLstPrs == comp->numFLstPrs) insert(items, NUMFLSTPRS);
	if (numFLstAdr == comp->numFLstAdr) insert(items, NUMFLSTADR);
	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);

	return(items);
};

set<uint> PnlFmncNavAdmin::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTORG, NUMFLSTPRS, NUMFLSTADR, NUMFLSTFIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavAdmin::StatApp
 ******************************************************************************/

void PnlFmncNavAdmin::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixFmncVExpstate
			, const bool LstUsgAlt
			, const bool LstUsrAlt
			, const bool LstOrgAlt
			, const bool LstPrsAlt
			, const bool LstAdrAlt
			, const bool LstFilAlt
			, const uint LstUsgNumFirstdisp
			, const uint LstUsrNumFirstdisp
			, const uint LstOrgNumFirstdisp
			, const uint LstPrsNumFirstdisp
			, const uint LstAdrNumFirstdisp
			, const uint LstFilNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppFmncNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppFmncNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxFmncVExpstate", VecFmncVExpstate::getSref(ixFmncVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstUsgAlt", LstUsgAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstUsrAlt", LstUsrAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstOrgAlt", LstOrgAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPrsAlt", LstPrsAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstAdrAlt", LstAdrAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAlt", LstFilAlt);
		writeUintAttr(wr, itemtag, "sref", "LstUsgNumFirstdisp", LstUsgNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstUsrNumFirstdisp", LstUsrNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstOrgNumFirstdisp", LstOrgNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPrsNumFirstdisp", LstPrsNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstAdrNumFirstdisp", LstAdrNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavAdmin::StatShr
 ******************************************************************************/

PnlFmncNavAdmin::StatShr::StatShr(
			const bool LstUsgAvail
			, const bool ButUsgViewActive
			, const bool LstUsrAvail
			, const bool ButUsrViewActive
			, const bool LstOrgAvail
			, const bool ButOrgViewActive
			, const bool LstPrsAvail
			, const bool ButPrsViewActive
			, const bool LstAdrAvail
			, const bool ButAdrViewActive
			, const bool LstFilAvail
			, const bool ButFilViewActive
		) : Block() {
	this->LstUsgAvail = LstUsgAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->LstUsrAvail = LstUsrAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->LstOrgAvail = LstOrgAvail;
	this->ButOrgViewActive = ButOrgViewActive;
	this->LstPrsAvail = LstPrsAvail;
	this->ButPrsViewActive = ButPrsViewActive;
	this->LstAdrAvail = LstAdrAvail;
	this->ButAdrViewActive = ButAdrViewActive;
	this->LstFilAvail = LstFilAvail;
	this->ButFilViewActive = ButFilViewActive;

	mask = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTORGAVAIL, BUTORGVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTADRAVAIL, BUTADRVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE};
};

void PnlFmncNavAdmin::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrFmncNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrFmncNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstUsgAvail", LstUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUsgViewActive", ButUsgViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstUsrAvail", LstUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUsrViewActive", ButUsrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOrgAvail", LstOrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButOrgViewActive", ButOrgViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPrsAvail", LstPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrsViewActive", ButPrsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstAdrAvail", LstAdrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButAdrViewActive", ButAdrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAvail", LstFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewActive", ButFilViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlFmncNavAdmin::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstUsgAvail == comp->LstUsgAvail) insert(items, LSTUSGAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (LstUsrAvail == comp->LstUsrAvail) insert(items, LSTUSRAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (LstOrgAvail == comp->LstOrgAvail) insert(items, LSTORGAVAIL);
	if (ButOrgViewActive == comp->ButOrgViewActive) insert(items, BUTORGVIEWACTIVE);
	if (LstPrsAvail == comp->LstPrsAvail) insert(items, LSTPRSAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);
	if (LstAdrAvail == comp->LstAdrAvail) insert(items, LSTADRAVAIL);
	if (ButAdrViewActive == comp->ButAdrViewActive) insert(items, BUTADRVIEWACTIVE);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);

	return(items);
};

set<uint> PnlFmncNavAdmin::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTORGAVAIL, BUTORGVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTADRAVAIL, BUTADRVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlFmncNavAdmin::Tag
 ******************************************************************************/

void PnlFmncNavAdmin::Tag::writeXML(
			const uint ixFmncVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagFmncNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemFmncNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixFmncVLocale == VecFmncVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Administration module");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "user groups");
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "users");
			writeStringAttr(wr, itemtag, "sref", "CptOrg", "organizations");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "persons");
			writeStringAttr(wr, itemtag, "sref", "CptAdr", "addresses");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "files");
		} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Verwaltung");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "Benutzergruppen");
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "Benutzer");
			writeStringAttr(wr, itemtag, "sref", "CptOrg", "Organisationen");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "Personen");
			writeStringAttr(wr, itemtag, "sref", "CptAdr", "Adressen");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Dateien");
		} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Partie gestion");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "groupes d'utilisateurs");
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "utilisateurs");
			writeStringAttr(wr, itemtag, "sref", "CptOrg", "organismes");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "individus");
			writeStringAttr(wr, itemtag, "sref", "CptAdr", "adresses");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "fichiers");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlFmncNavAdmin::DpchAppData
 ******************************************************************************/

PnlFmncNavAdmin::DpchAppData::DpchAppData() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVADMINDATA) {
};

string PnlFmncNavAdmin::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavAdmin::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavAdminData");
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
 class PnlFmncNavAdmin::DpchAppDo
 ******************************************************************************/

PnlFmncNavAdmin::DpchAppDo::DpchAppDo() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCNAVADMINDO) {
	ixVDo = 0;
};

string PnlFmncNavAdmin::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavAdmin::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncNavAdminDo");
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
 class PnlFmncNavAdmin::DpchEngData
 ******************************************************************************/

PnlFmncNavAdmin::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstAdr
			, Feed* feedFLstFil
			, Feed* feedFLstOrg
			, Feed* feedFLstPrs
			, Feed* feedFLstUsg
			, Feed* feedFLstUsr
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCNAVADMINDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTADR, FEEDFLSTFIL, FEEDFLSTORG, FEEDFLSTPRS, FEEDFLSTUSG, FEEDFLSTUSR, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTADR) && feedFLstAdr) this->feedFLstAdr = *feedFLstAdr;
	if (find(this->mask, FEEDFLSTFIL) && feedFLstFil) this->feedFLstFil = *feedFLstFil;
	if (find(this->mask, FEEDFLSTORG) && feedFLstOrg) this->feedFLstOrg = *feedFLstOrg;
	if (find(this->mask, FEEDFLSTPRS) && feedFLstPrs) this->feedFLstPrs = *feedFLstPrs;
	if (find(this->mask, FEEDFLSTUSG) && feedFLstUsg) this->feedFLstUsg = *feedFLstUsg;
	if (find(this->mask, FEEDFLSTUSR) && feedFLstUsr) this->feedFLstUsr = *feedFLstUsr;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlFmncNavAdmin::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTADR)) ss.push_back("feedFLstAdr");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(FEEDFLSTORG)) ss.push_back("feedFLstOrg");
	if (has(FEEDFLSTPRS)) ss.push_back("feedFLstPrs");
	if (has(FEEDFLSTUSG)) ss.push_back("feedFLstUsg");
	if (has(FEEDFLSTUSR)) ss.push_back("feedFLstUsr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlFmncNavAdmin::DpchEngData::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTADR)) {feedFLstAdr = src->feedFLstAdr; add(FEEDFLSTADR);};
	if (src->has(FEEDFLSTFIL)) {feedFLstFil = src->feedFLstFil; add(FEEDFLSTFIL);};
	if (src->has(FEEDFLSTORG)) {feedFLstOrg = src->feedFLstOrg; add(FEEDFLSTORG);};
	if (src->has(FEEDFLSTPRS)) {feedFLstPrs = src->feedFLstPrs; add(FEEDFLSTPRS);};
	if (src->has(FEEDFLSTUSG)) {feedFLstUsg = src->feedFLstUsg; add(FEEDFLSTUSG);};
	if (src->has(FEEDFLSTUSR)) {feedFLstUsr = src->feedFLstUsr; add(FEEDFLSTUSR);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlFmncNavAdmin::DpchEngData::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncNavAdminData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTADR)) feedFLstAdr.writeXML(wr);
		if (has(FEEDFLSTFIL)) feedFLstFil.writeXML(wr);
		if (has(FEEDFLSTORG)) feedFLstOrg.writeXML(wr);
		if (has(FEEDFLSTPRS)) feedFLstPrs.writeXML(wr);
		if (has(FEEDFLSTUSG)) feedFLstUsg.writeXML(wr);
		if (has(FEEDFLSTUSR)) feedFLstUsr.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixFmncVLocale, wr);
	xmlTextWriterEndElement(wr);
};


