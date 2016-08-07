/**
  * \file Fmnccmbd.cpp
  * inter-thread exchange object for Fmnc combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "Fmnccmbd.h"

/******************************************************************************
 class DpchAppFmnc
 ******************************************************************************/

DpchAppFmnc::DpchAppFmnc(
			const uint ixFmncVDpch
		) : DpchFmnc(ixFmncVDpch) {
	jref = 0;
};

DpchAppFmnc::~DpchAppFmnc() {
};

bool DpchAppFmnc::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchAppFmnc::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchAppFmnc::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecFmncVDpch::getSref(ixFmncVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppFmncAlert
 ******************************************************************************/

DpchAppFmncAlert::DpchAppFmncAlert() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCALERT) {
};

bool DpchAppFmncAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppFmncAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppFmncAlert::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppFmncAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppFmncInit
 ******************************************************************************/

DpchAppFmncInit::DpchAppFmncInit() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCINIT) {
};

/******************************************************************************
 class DpchAppFmncResume
 ******************************************************************************/

DpchAppFmncResume::DpchAppFmncResume() : DpchAppFmnc(VecFmncVDpch::DPCHAPPFMNCRESUME) {
};

/******************************************************************************
 class DpchEngFmnc
 ******************************************************************************/

DpchEngFmnc::DpchEngFmnc(
			const uint ixFmncVDpch
			, const ubigint jref
		) : DpchFmnc(ixFmncVDpch) {
	this->jref = jref;

	mask = {JREF};
};

DpchEngFmnc::~DpchEngFmnc() {
};

bool DpchEngFmnc::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchEngFmnc::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchEngFmnc::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngFmnc* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngFmnc::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	string tag = VecFmncVDpch::getSref(ixFmncVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngFmncAck
 ******************************************************************************/

DpchEngFmncAck::DpchEngFmncAck(
			const ubigint jref
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCACK, jref) {
};

/******************************************************************************
 class DpchEngFmncAlert
 ******************************************************************************/

DpchEngFmncAlert::DpchEngFmncAlert(
			const ubigint jref
			, ContInfFmncAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCALERT, jref) {
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngFmncAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngFmncAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngFmncAlert::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngFmncAlert* src = (DpchEngFmncAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngFmncAlert::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngFmncConfirm
 ******************************************************************************/

DpchEngFmncConfirm::DpchEngFmncConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCCONFIRM, jref) {
	this->accepted = accepted;
	this->jref = jref;
	this->sref = sref;

	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngFmncConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngFmncConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(JREF)) ss.push_back("jref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngFmncConfirm::merge(
			DpchEngFmnc* dpcheng
		) {
	DpchEngFmncConfirm* src = (DpchEngFmncConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngFmncConfirm::writeXML(
			const uint ixFmncVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngFmncConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/fmnc");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngFmncSuspend
 ******************************************************************************/

DpchEngFmncSuspend::DpchEngFmncSuspend(
			const ubigint jref
		) : DpchEngFmnc(VecFmncVDpch::DPCHENGFMNCSUSPEND, jref) {
};

/******************************************************************************
 class StgFmnccmbd
 ******************************************************************************/

StgFmnccmbd::StgFmnccmbd(
			const usmallint jobprcn
			, const usmallint opprcn
			, const usmallint appsrvport
			, const usmallint histlength
		) : Block() {
	this->jobprcn = jobprcn;
	this->opprcn = opprcn;
	this->appsrvport = appsrvport;
	this->histlength = histlength;
	mask = {JOBPRCN, OPPRCN, APPSRVPORT, HISTLENGTH};
};

bool StgFmnccmbd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgFmnccmbd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemFmnccmbd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrvport", appsrvport)) add(APPSRVPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
	};

	return basefound;
};

void StgFmnccmbd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgFmnccmbd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemFmnccmbd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "appsrvport", appsrvport);
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
	xmlTextWriterEndElement(wr);
};

set<uint> StgFmnccmbd::comm(
			const StgFmnccmbd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);
	if (appsrvport == comp->appsrvport) insert(items, APPSRVPORT);
	if (histlength == comp->histlength) insert(items, HISTLENGTH);

	return(items);
};

set<uint> StgFmnccmbd::diff(
			const StgFmnccmbd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPPRCN, APPSRVPORT, HISTLENGTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgFmncDatabase
 ******************************************************************************/

StgFmncDatabase::StgFmncDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) : Block() {
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgFmncDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgFmncDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemFmncDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgFmncDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgFmncDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemFmncDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgFmncDatabase::comm(
			const StgFmncDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgFmncDatabase::diff(
			const StgFmncDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgFmncMonitor
 ******************************************************************************/

StgFmncMonitor::StgFmncMonitor(
			const string& username
			, const string& password
			, const string& ip
			, const usmallint port
			, const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& dbsusername
			, const string& dbspassword
		) : Block() {
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->dbsusername = dbsusername;
	this->dbspassword = dbspassword;
	mask = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
};

bool StgFmncMonitor::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgFmncMonitor");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemFmncMonitor";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsusername", dbsusername)) add(DBSUSERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspassword", dbspassword)) add(DBSPASSWORD);
	};

	return basefound;
};

void StgFmncMonitor::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgFmncMonitor";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemFmncMonitor";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "dbsusername", dbsusername);
		writeStringAttr(wr, itemtag, "sref", "dbspassword", dbspassword);
	xmlTextWriterEndElement(wr);
};

set<uint> StgFmncMonitor::comm(
			const StgFmncMonitor* comp
		) {
	set<uint> items;

	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);
	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (dbsusername == comp->dbsusername) insert(items, DBSUSERNAME);
	if (dbspassword == comp->dbspassword) insert(items, DBSPASSWORD);

	return(items);
};

set<uint> StgFmncMonitor::diff(
			const StgFmncMonitor* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgFmncPath
 ******************************************************************************/

StgFmncPath::StgFmncPath(
			const string& acvpath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) : Block() {
	this->acvpath = acvpath;
	this->monpath = monpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgFmncPath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgFmncPath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemFmncPath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgFmncPath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgFmncPath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemFmncPath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgFmncPath::comm(
			const StgFmncPath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgFmncPath::diff(
			const StgFmncPath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 namespace AlrFmnc
 ******************************************************************************/

DpchEngFmncAlert* AlrFmnc::prepareAlrAbt(
			const ubigint jref
			, const uint ixFmncVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfFmncAlert continf;
// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecFmncVTag::getTitle(VecFmncVTag::ABOUT, ixFmncVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixFmncVLocale == VecFmncVLocale::ENUS) {
		continf.TxtMsg1 = "FabManiac version 0.1.40 released on 7-3-2016";
		continf.TxtMsg3 = "contributors: Alexander Wirthmueller";
		continf.TxtMsg5 = "libraries: libxml2 2.7.8, libMHD 0.9.16, libcurl 7.24, libmysqlclient 5.5.28 and libpq 9.x";
		continf.TxtMsg7 = "FabManiac is an electronic lab book for clean room processing.";
	} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
		continf.TxtMsg1 = "FabManiac Version 0.1.40 ver\\u00f6ffentlicht am 7-3-2016";
		continf.TxtMsg3 = "Mitwirkende: Alexander Wirthmueller";
		continf.TxtMsg5 = "Programmbibliotheken: libxml2 2.7.8, libMHD 0.9.16, libcurl 7.24, libmysqlclient 5.5.28 und libpq 9.x";
		continf.TxtMsg7 = "FabManiac ist ein elektronisches Laborbuch f\\u00fcr Reinraum-Anwendungen.";
	} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
		continf.TxtMsg1 = "FabManiac version 0.1.40 sorti le 7-3-2016";
		continf.TxtMsg3 = "coop\\u00e9rateurs: Alexander Wirthmueller";
		continf.TxtMsg5 = "biblioth\\u00e8ques: libxml2 2.7.8, libMHD 0.9.16, libcurl 7.24, libmysqlclient 5.5.28 et libpq 9.x";
		continf.TxtMsg7 = "FabManiac est un cahier \\u00e9lectronique pour des applications salle blanche.";
	};

	feedFMcbAlert.clear();

	VecFmncVTag::appendToFeed(VecFmncVTag::CLOSE, ixFmncVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
// IP prepareAlrAbt --- END
	return(new DpchEngFmncAlert(jref, &continf, &feedFMcbAlert, {DpchEngFmncAlert::ALL}));
};

DpchEngFmncAlert* AlrFmnc::prepareAlrPer(
			const ubigint jref
			, const uint ixFmncVLocale
			, const string& lineno
			, Feed& feedFMcbAlert
		) {
	ContInfFmncAlert continf;
// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecFmncVTag::getTitle(VecFmncVTag::ERROR, ixFmncVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixFmncVLocale == VecFmncVLocale::ENUS) {
		continf.TxtMsg1 = "Parse error in line " + lineno + ".";
	} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
		continf.TxtMsg1 = "Syntaxfehler in Zeile " + lineno + ".";
	} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
		continf.TxtMsg1 = "Erreur syntactique \\u00e0 la ligne " + lineno + ".";
	};

	feedFMcbAlert.clear();

	VecFmncVTag::appendToFeed(VecFmncVTag::OK, ixFmncVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
// IP prepareAlrPer --- END
	return(new DpchEngFmncAlert(jref, &continf, &feedFMcbAlert, {DpchEngFmncAlert::ALL}));
};

DpchEngFmncAlert* AlrFmnc::prepareAlrSav(
			const ubigint jref
			, const uint ixFmncVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfFmncAlert continf;
// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecFmncVTag::getTitle(VecFmncVTag::QUEST, ixFmncVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixFmncVLocale == VecFmncVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	} else if (ixFmncVLocale == VecFmncVLocale::DECH) {
		continf.TxtMsg1 = "\\u00c4nderungen speichern?";
	} else if (ixFmncVLocale == VecFmncVLocale::FRCH) {
		continf.TxtMsg1 = "Enregistrer modifications?";
	};

	feedFMcbAlert.clear();

	VecFmncVTag::appendToFeed(VecFmncVTag::CANCEL, ixFmncVLocale, feedFMcbAlert);
	VecFmncVTag::appendToFeed(VecFmncVTag::FLS, ixFmncVLocale, feedFMcbAlert);
	VecFmncVTag::appendToFeed(VecFmncVTag::TRU, ixFmncVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
// IP prepareAlrSav --- END
	return(new DpchEngFmncAlert(jref, &continf, &feedFMcbAlert, {DpchEngFmncAlert::ALL}));
};

/******************************************************************************
 class ReqFmnc
 ******************************************************************************/

ReqFmnc::ReqFmnc(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) {
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	if ((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::REGULAR) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD)) {
		retain = false;
		Mutex::init(&mcReady, false, "mcReady", "ReqFmnc", "ReqFmnc");
		Cond::init(&cReady, "cReady", "ReqFmnc", "ReqFmnc");

	} else {
		retain = true;
	};

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jref = 0;

	wref = 0;

	call = NULL;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixFmncVLocale = VecFmncVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;
};

ReqFmnc::~ReqFmnc() {
	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD
	if (pp) MHD_destroy_post_processor(pp);

	// specific data for base types CMD, REGULAR, NOTIFY, UPLOAD, DOWNLOAD
	if ((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::REGULAR) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD)) {
		Mutex::destroy(&mcReady, false, "mcReady", "ReqFmnc", "~ReqFmnc");
		Cond::destroy(&cReady, "cReady", "ReqFmnc", "~ReqFmnc");
	};

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	// specific data for base type EXTCALL
	if (call) delete call;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	if (request) delete[] request;

	// specific data for base types REGULAR
	if (dpchapp) delete dpchapp;

	// specific data for base types REGULAR, NOTIFY, POLL
	if (dpcheng) delete dpcheng;

	// specific data for base types RET
	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	// specific data for base types REGULAR, NOTIFY, POLL
	if (reply) delete[] reply;
};

void ReqFmnc::setStateReply() {
	Mutex::lock(&mcReady, "mcReady", "ReqFmnc", "setStateReply");

	ixVState = VecVState::REPLY;

	Cond::signal(&cReady, "cReady", "ReqFmnc", "setStateReply");
	Mutex::unlock(&mcReady, "mcReady", "ReqFmnc", "setStateReply");
};

/******************************************************************************
 class DcolFmnc
 ******************************************************************************/

DcolFmnc::DcolFmnc(
			const ubigint jref
			, const uint ixFmncVLocale
		) {
	this->jref = jref;
	this->ixFmncVLocale = ixFmncVLocale;

	Mutex::init(&mAccess, false, "mAccess", "DcolFmnc", "DcolFmnc");

	hot = false;

	req = NULL;
};

DcolFmnc::~DcolFmnc() {
	Mutex::lock(&mAccess, "mAccess", "DcolFmnc", "~DcolFmnc");
	Mutex::unlock(&mAccess, "mAccess", "DcolFmnc", "~DcolFmnc");
	Mutex::destroy(&mAccess, true, "mAccess", "DcolFmnc", "~DcolFmnc");

	for (auto it=dpchs.begin();it!=dpchs.end();it++) delete(*it);

	if (req) Cond::signal(&(req->cReady), "req->cReady", "DcolFmnc", "~DcolFmnc");
};

int DcolFmnc::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "dcol(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int DcolFmnc::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "dcol(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

/******************************************************************************
 class JobFmnc
 ******************************************************************************/

JobFmnc::JobFmnc(
			XchgFmnc* xchg
			, const uint ixFmncVJob
			, const ubigint jrefSup
			, const uint ixFmncVLocale
			, const bool prefmast
		) {
	this->xchg = xchg;

	jref = 0;

	this->ixFmncVJob = ixFmncVJob;

	this->jrefSup = jrefSup;

	this->ixFmncVLocale = ixFmncVLocale;

	jrefMast = 0;

	this->prefmast = prefmast;

	Mutex::init(&mAccess, true, "mAccess", VecFmncVJob::getSref(ixFmncVJob) + "(jrefSup=" + to_string(jrefSup) + ")", VecFmncVJob::getSref(ixFmncVJob));

	muteRefresh = false;

	ixVSge = 1;
	nextIxVSge = 1;

	opNdone = 0;
	opN = 0;

	Mutex::init(&mOps, true, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(jrefSup=" + to_string(jrefSup) + ")", VecFmncVJob::getSref(ixFmncVJob));

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobFmnc::~JobFmnc() {
	Mutex::lock(&mAccess, "mAccess", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "~" + VecFmncVJob::getSref(ixFmncVJob));
	Mutex::unlock(&mAccess, "mAccess", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "~" + VecFmncVJob::getSref(ixFmncVJob));
	Mutex::destroy(&mAccess, true, "mAccess", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "~" + VecFmncVJob::getSref(ixFmncVJob));

	Mutex::destroy(&mOps, true, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "~" + VecFmncVJob::getSref(ixFmncVJob));

	if (reqCmd) delete reqCmd;
};

DpchEngFmnc* JobFmnc::getNewDpchEng(
			set<uint> items
		) {
	return new DpchEngFmncConfirm(true, jref, "");
};

void JobFmnc::refresh(
			DbsFmnc* dbsfmnc
			, set<uint>& moditems
		) {
};

void JobFmnc::refreshWithDpchEng(
			DbsFmnc* dbsfmnc
			, DpchEngFmnc** dpcheng
		) {
	set<uint> moditems;

	DpchEngFmnc* _dpcheng = NULL;

	refresh(dbsfmnc, moditems);

	if (dpcheng) {
		_dpcheng = getNewDpchEng(moditems);

		if (*dpcheng) {
			if (_dpcheng->ixFmncVDpch == VecFmncVDpch::DPCHENGFMNCCONFIRM) delete _dpcheng;
			else if (_dpcheng->ixFmncVDpch == (*dpcheng)->ixFmncVDpch) {
				(*dpcheng)->merge(_dpcheng);
				delete _dpcheng;

			} else xchg->submitDpch(_dpcheng);

		} else *dpcheng = _dpcheng;

	} else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
};

string JobFmnc::getSquawk(
			DbsFmnc* dbsfmnc
		) {
	return "";
};

void JobFmnc::giveupMaster(
			DbsFmnc* dbsfmnc
		) {
};

void JobFmnc::giveupSlave(
			DbsFmnc* dbsfmnc
		) {
};

void JobFmnc::becomeMaster(
			DbsFmnc* dbsfmnc
		) {
};

void JobFmnc::becomeSlave(
			DbsFmnc* dbsfmnc
		) {
};

bool JobFmnc::handleClaimMaster(
			DbsFmnc* dbsfmnc
		) {
	return false;
};

void JobFmnc::handleRequest(
			DbsFmnc* dbsfmnc
			, ReqFmnc* req
		) {
};

void JobFmnc::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
};

int JobFmnc::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobFmnc::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::trylock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobFmnc::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobFmnc::lockAccess(
			const string& srefMember
		) {
	return Mutex::lock(&mAccess, "mAccess", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", srefMember);
};

int JobFmnc::unlockAccess(
			const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "mAccess", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", srefMember);
};

void JobFmnc::clearInvs() {
	for (unsigned int i=0;i<invs.size();i++) delete invs[i];
	invs.clear();
};

void JobFmnc::addInv(
			DpchInvFmnc* inv
		) {
	inv->oref = xchg->orefseq->getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;
};

void JobFmnc::addInvs(
			vector<DpchInvFmnc*>& _invs
		) {
	for (unsigned int i=0;i<_invs.size();i++) addInv(_invs[i]);
};

void JobFmnc::submitInvs(
			DbsFmnc* dbsfmnc
			, const uint emptyIxVSge
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = emptyIxVSge;

	} else {
		xchg->addInvs(dbsfmnc, jref, invs);
		invs.clear();
	};
};

void JobFmnc::clearOps() {
	Mutex::lock(&mOps, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "clearOps");

	for (auto it=ops.begin();it!=ops.end();it++) delete(*it);
	ops.clear();

	Mutex::unlock(&mOps, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "clearOps");
};

void JobFmnc::addOp(
			DbsFmnc* dbsfmnc
			, DpchInvFmnc* inv
		) {
	string squawk;

	Mutex::lock(&mOps, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "addOp");

	// generate squawk

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixFmncVDpch, squawk));

	Mutex::unlock(&mOps, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "addOp");
};

void JobFmnc::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	Mutex::lock(&mOps, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "removeOp");

	for (auto it=ops.begin();it!=ops.end();it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	Mutex::unlock(&mOps, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "removeOp");
};

string JobFmnc::getOpsqkLast() {
	string retval;

	Mutex::lock(&mOps, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "getOpsqkLast");

	retval = opsqkLast;

	Mutex::unlock(&mOps, "mOps", VecFmncVJob::getSref(ixFmncVJob) + "(" + to_string(jref) + ")", "getOpsqkLast");

	return retval;
};

void JobFmnc::callback(
			const uint _nextIxVSge
		) {
	nextIxVSge = _nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobFmnc::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class StmgrFmnc
 ******************************************************************************/

StmgrFmnc::StmgrFmnc(
			XchgFmnc* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) {
	this->xchg = xchg;

	this->jref = jref;
	this->ixVNonetype = ixVNonetype;

	stcch = new Stcch(true);

	Mutex::init(&mAccess, true, "mAccess", "StmgrFmnc(" + to_string(jref) + ")", "StmgrFmnc");
};

StmgrFmnc::~StmgrFmnc() {
	Mutex::lock(&mAccess, "mAccess", "StmgrFmnc(" + to_string(jref) + ")", "~StmgrFmnc");
	Mutex::unlock(&mAccess, "mAccess", "StmgrFmnc(" + to_string(jref) + ")", "~StmgrFmnc");
	Mutex::destroy(&mAccess, true, "mAccess", "StmgrFmnc(" + to_string(jref) + ")", "~StmgrFmnc");

	delete stcch;
};

void StmgrFmnc::handleCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	set<uint> icsFmncVStub;
	pair<multimap<stref_t,Stcchitem*>::iterator,multimap<stref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecFmncVCall::CALLFMNCACTUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCACTSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCADRUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCADRSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCARTUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCARTSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCBILUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCBILSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFABUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCFABSREF);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCFABSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFILUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCFILSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFPJUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCFPJSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCFUSUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCFUSSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCORGUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCORGSREF);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCORGSTD);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCORGHSREF);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPCOUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCPCOSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPRJUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCPRJSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCPRSUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCPRSWORG);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCPRSSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCRUNUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCRUNSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSESUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCSESSTD);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCSESMENU);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSKIUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCSKISTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSMPUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCSMPHSREF);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCSMPSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCSTEUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCSTESTD);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCSEPSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTOLUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCTOLSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCTTYUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCTTYSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCUSGUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCGRP);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCUSGSTD);
	} else if (call->ixVCall == VecFmncVCall::CALLFMNCUSRUPD_REFEQ) {
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCUSRSTD);
		insert(icsFmncVStub, VecFmncVStub::STUBFMNCOWN);
	};

	for (auto it=icsFmncVStub.begin();it!=icsFmncVStub.end();it++) {
		rng = stcch->nodes.equal_range(stref_t(*it, call->argInv.ref, 0));
		for (auto it2=rng.first;it2!=rng.second;it2++) if (refresh(dbsfmnc, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCSTUBCHG, jref);
};

bool StmgrFmnc::refresh(
			DbsFmnc* dbsfmnc
			, Stcchitem* stit
		) {
	set<stref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubFmnc::getStub(dbsfmnc, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it=strefsSub_backup.begin();it!=strefsSub_backup.end();it++) refresh(dbsfmnc, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrFmnc::begin() {
	stcch->begin();
};

void StmgrFmnc::commit() {
	for (auto it=stcch->icsVStubNew.begin();it!=stcch->icsVStubNew.end();it++) {
		if (*it == VecFmncVStub::STUBFMNCACTSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCACTUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCADRSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCADRUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCARTSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCARTUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCBILSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCBILUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCFABSREF) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCFABUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCFABSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCFABUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCFILSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCFILUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCFPJSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCFPJUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCFUSSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCFUSUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCGRP) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCUSGUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCORGHSREF) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCORGUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCORGSREF) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCORGUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCORGSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCORGUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCOWN) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCUSRUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCPCOSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCPCOUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCPRJSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCPRJUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCPRSSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCPRSUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCPRSWORG) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCPRSUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCRUNSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCRUNUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCSEPSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCSTEUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCSESMENU) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCSESUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCSESSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCSESUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCSKISTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCSKIUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCSMPHSREF) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCSMPUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCSMPSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCSMPUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCSTESTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCSTEUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCTOLSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCTOLUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCTTYSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCTTYUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCUSGSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCUSGUPD_REFEQ, jref);
		} else if (*it == VecFmncVStub::STUBFMNCUSRSTD) {
			xchg->addClstnStmgr(VecFmncVCall::CALLFMNCUSRUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

int StmgrFmnc::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "stmgr(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int StmgrFmnc::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "stmgr(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

/******************************************************************************
 class WakeupFmnc
 ******************************************************************************/

WakeupFmnc::WakeupFmnc(
			XchgFmnc* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const unsigned int deltat
			, const bool weak
		) {
	this->xchg = xchg;
	this->wref = wref;
	this->jref = jref;
	this->sref = sref;
	this->deltat = deltat;
	this->weak = weak;
};

/******************************************************************************
 class ExtcallFmnc
 ******************************************************************************/

ExtcallFmnc::ExtcallFmnc(
			XchgFmnc* xchg
			, Call* call
		) {
	this->xchg = xchg;
	this->call = call;
};

/******************************************************************************
 class XchgdataFmncJobprc
 ******************************************************************************/

XchgdataFmncJobprc::XchgdataFmncJobprc() {
};

/******************************************************************************
 class XchgdataFmncOpprc
 ******************************************************************************/

XchgdataFmncOpprc::XchgdataFmncOpprc() {
};

/******************************************************************************
 class XchgFmnccmbd
 ******************************************************************************/

XchgFmnccmbd::XchgFmnccmbd() {
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	// scrambled ref codes
	Mutex::init(&mScr, true, "mScr", "XchgFmnccmbd", "XchgFmnccmbd");

	// log file
	Mutex::init(&mLogfile, true, "mLogfile", "XchgFmnccmbd", "XchgFmnccmbd");

	// condition for job processors
	Mutex::init(&mcJobprcs, true, "mcJobprcs", "XchgFmnccmbd", "XchgFmnccmbd");
	Cond::init(&cJobprcs, "cJobprcs", "XchgFmnccmbd", "XchgFmnccmbd");

	// condition for op processors
	Mutex::init(&mcOpprcs, true, "mcOpprcs", "XchgFmnccmbd", "XchgFmnccmbd");
	Cond::init(&cOpprcs, "cOpprcs", "XchgFmnccmbd", "XchgFmnccmbd");

	// request list
	Mutex::init(&mReqs, true, "mReqs", "XchgFmnccmbd", "XchgFmnccmbd");

	// operation invocation list
	orefseq = new Refseq("orefseq");
	Mutex::init(&mInvs, true, "mInvs", "XchgFmnccmbd", "XchgFmnccmbd");

	// presetting list
	Mutex::init(&mPresets, true, "mPresets", "XchgFmnccmbd", "XchgFmnccmbd");

	// stub manager list
	Mutex::init(&mStmgrs, true, "mStmgrs", "XchgFmnccmbd", "XchgFmnccmbd");

	// call listener list
	Mutex::init(&mClstns, true, "mClstns", "XchgFmnccmbd", "XchgFmnccmbd");

	// dispatch collector list
	Mutex::init(&mDcols, true, "mDcols", "XchgFmnccmbd", "XchgFmnccmbd");

	// job list
	jrefseq = new Refseq("jrefseq");
	Mutex::init(&mJobs, true, "mJobs", "XchgFmnccmbd", "XchgFmnccmbd");

	// sequence for wakeup references
	wrefseq = new Refseq("wrefseq");
};

XchgFmnccmbd::~XchgFmnccmbd() {
	// empty out lists
	for (auto it=reqs.begin();it!=reqs.end();it++) delete(*it);
	for (auto it=invs.begin();it!=invs.end();it++) delete(*it);
	for (auto it=presets.begin();it!=presets.end();it++) delete(it->second);
	for (auto it=stmgrs.begin();it!=stmgrs.end();it++) delete(it->second);
	for (auto it=clstns.begin();it!=clstns.end();it++) delete(it->second);
	for (auto it=dcols.begin();it!=dcols.end();it++) delete(it->second);
	for (auto it=jobs.begin();it!=jobs.end();it++) delete(it->second);

	// scrambled ref codes
	Mutex::destroy(&mScr, true, "mScr", "XchgFmnccmbd", "~XchgFmnccmbd");

	// log file
	Mutex::destroy(&mLogfile, true, "mLogfile", "XchgFmnccmbd", "~XchgFmnccmbd");

	// condition for job processors
	Mutex::destroy(&mcJobprcs, true, "mcJobprcs", "XchgFmnccmbd", "~XchgFmnccmbd");
	Cond::destroy(&cJobprcs, "cJobprcs", "XchgFmnccmbd", "~XchgFmnccmbd");

	// condition for op processors
	Mutex::destroy(&mcOpprcs, true, "mcOpprcs", "XchgFmnccmbd", "~XchgFmnccmbd");
	Cond::destroy(&cOpprcs, "cOpprcs", "XchgFmnccmbd", "~XchgFmnccmbd");

	// request list
	Mutex::destroy(&mReqs, true, "mReqs", "XchgFmnccmbd", "~XchgFmnccmbd");

	// operation invocation list
	delete orefseq;
	Mutex::destroy(&mInvs, true, "mInvs", "XchgFmnccmbd", "~XchgFmnccmbd");

	// presetting list
	Mutex::destroy(&mPresets, true, "mPresets", "XchgFmnccmbd", "~XchgFmnccmbd");

	// stub manager list
	Mutex::destroy(&mStmgrs, true, "mStmgrs", "XchgFmnccmbd", "~XchgFmnccmbd");

	// call listener list
	Mutex::destroy(&mClstns, true, "mClstns", "XchgFmnccmbd", "~XchgFmnccmbd");

	// dispatch collector list
	Mutex::destroy(&mDcols, true, "mDcols", "XchgFmnccmbd", "~XchgFmnccmbd");

	// job list
	delete jrefseq;
	Mutex::destroy(&mJobs, true, "mJobs", "XchgFmnccmbd", "~XchgFmnccmbd");

	// sequence for wakeup references
	delete wrefseq;
};

// IP cust --- INSERT

void XchgFmnccmbd::startMon() {
	JobFmnc* job = NULL;

	DcolFmnc* dcol = NULL;
	bool Dcol;

	StmgrFmnc* stmgr = NULL;
	bool Stmgr;

	Clstn* clstn = NULL;
	Preset* preset = NULL;

	mon.start("FabManiac 0.1.40", stgfmncmonitor.ixDbsVDbstype, stgfmncmonitor.dbspath, stgfmncmonitor.dbsname, stgfmncmonitor.ip, stgfmncmonitor.port, stgfmncmonitor.dbsusername, stgfmncmonitor.dbspassword, stgfmncmonitor.username, stgfmncmonitor.password);

	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "startMon");
	for (auto it=jobs.begin();it!=jobs.end();it++) {
		job = it->second;

		dcol = getDcolByJref(job->jref, false);
		if (dcol) {
			Dcol = true;
			dcol->unlockAccess("XchgFmnccmbd", "startMon");
		} else Dcol = false;

		stmgr = getStmgrByJref(job->jref);
		if (stmgr) {
			Stmgr = true;
			stmgr->unlockAccess("XchgFmnccmbd", "startMon");
		} else Stmgr = false;

		mon.insertJob(job->jrefSup, VecFmncVJob::getSref(job->ixFmncVJob), job->jref, (job->jrefMast == job->jref), (job->jrefMast == job->jref) && (job->jrefMast != 0), Dcol, Stmgr);
	};
	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "startMon");

	Mutex::lock(&mClstns, "mClstns", "XchgFmnccmbd", "startMon");
	for (auto it=clstns.begin();it!=clstns.end();it++) {
		clstn = it->second;
		mon.insertClstn(clstn->cref.jref, VecFmncVCall::getSref(clstn->cref.ixVCall), clstn->cref.stmgr, Clstn::VecVJobmask::getSref(clstn->cref.ixVJobmask), clstn->cref.jrefTrig, clstn->argMask.writeText(), Clstn::VecVJactype::getSref(clstn->ixVJactype));
	};
	Mutex::unlock(&mClstns, "mClstns", "XchgFmnccmbd", "startMon");

	Mutex::lock(&mPresets, "mPresets", "XchgFmnccmbd", "startMon");
	for (auto it=presets.begin();it!=presets.end();it++) {
		preset = it->second;
		mon.insertPreset(preset->pref.jref, VecFmncVPreset::getSref(preset->pref.ixVPreset), preset->arg.writeText());
	};
	Mutex::unlock(&mPresets, "mPresets", "XchgFmnccmbd", "startMon");
};

void XchgFmnccmbd::stopMon() {
	mon.stop();
};

void XchgFmnccmbd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	Mutex::lock(&mLogfile, "mLogfile", "XchgFmnccmbd", "appendToLogfile");

	time(&rawtime);

	logfile.open("./log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	Mutex::unlock(&mLogfile, "mLogfile", "XchgFmnccmbd", "appendToLogfile");
};

void XchgFmnccmbd::addReq(
			ReqFmnc* req
		) {
	Mutex::lock(&mReqs, "mReqs", "XchgFmnccmbd", "addReq");

	req->ixVState = ReqFmnc::VecVState::WAITPRC;
	reqs.push_back(req);

	Mutex::unlock(&mReqs, "mReqs", "XchgFmnccmbd", "addReq");

	Cond::signal(&cJobprcs, "cJobprcs", "XchgFmnccmbd", "addReq");
};

ReqFmnc* XchgFmnccmbd::pullFirstReq() {
	ReqFmnc* req;

	// get first element from list
	Mutex::lock(&mReqs, "mReqs", "XchgFmnccmbd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqFmnc::VecVState::PRC;
		reqs.pop_front();
	};

	Mutex::unlock(&mReqs, "mReqs", "XchgFmnccmbd", "pullFirstReq");

	return req;
};

void XchgFmnccmbd::addInvs(
			DbsFmnc* dbsfmnc
			, const ubigint jref
			, vector<DpchInvFmnc*>& dpchinvs
		) {
	JobFmnc* job;

	job = getJobByJref(jref);

	if (job) {
		// append to inv list and signal the news (note the double-lock)
		Mutex::lock(&mInvs, "mInvs", "XchgFmnccmbd", "addInvs");
		Mutex::lock(&(job->mOps), "job->mOps", "XchgFmnccmbd", "addInvs");

		for (unsigned int i=0;i<dpchinvs.size();i++) {
			job->addOp(dbsfmnc, dpchinvs[i]);

			invs.push_back(dpchinvs[i]);

			mon.eventAddInv(jref, VecFmncVDpch::getSref(dpchinvs[i]->ixFmncVDpch), "", dpchinvs[i]->oref);
		};

		Mutex::unlock(&(job->mOps), "job->mOps", "XchgFmnccmbd", "addInvs");
		Mutex::unlock(&mInvs, "mInvs", "XchgFmnccmbd", "addInvs");

		Cond::signal(&cOpprcs, "cOpprcs", "XchgFmnccmbd", "addInvs");
	};
};

DpchInvFmnc* XchgFmnccmbd::pullFirstInv() {
	DpchInvFmnc* inv;

	// get first element from list
	Mutex::lock(&mInvs, "mInvs", "XchgFmnccmbd", "pullFirstInv");

	inv = NULL;

	if (!invs.empty()) {
		inv = *(invs.begin());
		invs.pop_front();
	};

	Mutex::unlock(&mInvs, "mInvs", "XchgFmnccmbd", "pullFirstInv");

	return inv;
};

Preset* XchgFmnccmbd::addPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	pref_t pref(jref, ixFmncVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	Mutex::lock(&mPresets, "mPresets", "XchgFmnccmbd", "addPreset");

	preset = getPresetByPref(pref);

	if (preset) {
		preset->arg = arg;

		mon.eventChangePreset(jref, VecFmncVPreset::getSref(ixFmncVPreset), arg.writeText());

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<pref_t,Preset*>(pref, preset));

		mon.eventAddPreset(jref, VecFmncVPreset::getSref(ixFmncVPreset), arg.writeText());
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgFmnccmbd", "addPreset");

	return(preset);
};

Preset* XchgFmnccmbd::addIxPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixFmncVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgFmnccmbd::addRefPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixFmncVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgFmnccmbd::addRefsPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixFmncVPreset, jref, arg));
};

Preset* XchgFmnccmbd::addSrefPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixFmncVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgFmnccmbd::addIntvalPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixFmncVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgFmnccmbd::addDblvalPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixFmncVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgFmnccmbd::addBoolvalPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixFmncVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgFmnccmbd::addTxtvalPreset(
			const uint ixFmncVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixFmncVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgFmnccmbd::getPresetByPref(
			const pref_t& pref
		) {
	Preset* preset = NULL;

	Mutex::lock(&mPresets, "mPresets", "XchgFmnccmbd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	Mutex::unlock(&mPresets, "mPresets", "XchgFmnccmbd", "getPresetByPref");

	return preset;
};

Arg XchgFmnccmbd::getPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg;

	JobFmnc* job = NULL;
	Preset* preset = NULL;

	if ( (ixFmncVPreset == VecFmncVPreset::PREFMNCSYSDATE) || (ixFmncVPreset == VecFmncVPreset::PREFMNCSYSTIME) || (ixFmncVPreset == VecFmncVPreset::PREFMNCSYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		arg.mask = Arg::INTVAL;

		if (ixFmncVPreset == VecFmncVPreset::PREFMNCSYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
		else if (ixFmncVPreset == VecFmncVPreset::PREFMNCSYSTIME) arg.intval = rawtime%(3600*24);
		else if (ixFmncVPreset == VecFmncVPreset::PREFMNCSYSSTAMP) arg.intval = rawtime;

	} else {
		Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "getPreset");
		Mutex::lock(&mPresets, "mPresets", "XchgFmnccmbd", "getPreset");
		
		job = getJobByJref(jref);

		if ( (job != NULL) && (ixFmncVPreset == VecFmncVPreset::PREFMNCIXLCL) ) {
			arg.mask = Arg::IX;
			arg.ix = job->ixFmncVLocale;

		} else {
			while (job && !preset) {
				preset = getPresetByPref(pref_t(job->jref, ixFmncVPreset));

				if (preset) arg = preset->arg;
				else job = getJobByJref(job->jrefSup);
			};
		};

		Mutex::unlock(&mPresets, "mPresets", "XchgFmnccmbd", "getPreset");
		Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "getPreset");
	};

	return(arg);
};

uint XchgFmnccmbd::getIxPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixFmncVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgFmnccmbd::getRefPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixFmncVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgFmnccmbd::getRefsPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixFmncVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgFmnccmbd::getSrefPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixFmncVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgFmnccmbd::getIntvalPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixFmncVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgFmnccmbd::getDblvalPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixFmncVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgFmnccmbd::getBoolvalPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixFmncVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgFmnccmbd::getTxtvalPreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixFmncVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgFmnccmbd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsFmncVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsFmncVPreset.clear();
	args.clear();

	Mutex::lock(&mPresets, "mPresets", "XchgFmnccmbd", "getPresetsByJref");

	auto rng = presets.equal_range(pref_t(jref, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		preset = it->second;

		icsFmncVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgFmnccmbd", "getPresetsByJref");
};

void XchgFmnccmbd::removePreset(
			const uint ixFmncVPreset
			, const ubigint jref
		) {
	Mutex::lock(&mPresets, "mPresets", "XchgFmnccmbd", "removePreset");

	auto it = presets.find(pref_t(jref, ixFmncVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);

		mon.eventRemovePreset(jref, VecFmncVPreset::getSref(ixFmncVPreset));
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgFmnccmbd", "removePreset");
};

void XchgFmnccmbd::removePresetsByJref(
			const ubigint jref
		) {
	Mutex::lock(&mPresets, "mPresets", "XchgFmnccmbd", "removePresetsByJref");

	uint ixVPreset;

	auto rng = presets.equal_range(pref_t(jref, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		ixVPreset = it->second->pref.ixVPreset;
		delete it->second;

		mon.eventRemovePreset(jref, VecFmncVPreset::getSref(ixVPreset));
	};
	presets.erase(rng.first, rng.second);

	Mutex::unlock(&mPresets, "mPresets", "XchgFmnccmbd", "removePresetsByJref");
};

StmgrFmnc* XchgFmnccmbd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrFmnc* stmgr = NULL;

	// create new stmgr and append to stmgr list
	Mutex::lock(&mStmgrs, "mStmgrs", "XchgFmnccmbd", "addStmgr");

	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		stmgr = new StmgrFmnc(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;

		mon.eventAddStmgr(jref);
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgFmnccmbd", "addStmgr");

	return(stmgr);
};

StmgrFmnc* XchgFmnccmbd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrFmnc* stmgr = NULL;

	Mutex::lock(&mStmgrs, "mStmgrs", "XchgFmnccmbd", "getStmgrByJref");

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgFmnccmbd", "getStmgrByJref");
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgFmnccmbd", "getStmgrByJref");

	return(stmgr);
};

void XchgFmnccmbd::removeStmgrByJref(
			const ubigint jref
		) {
	Mutex::lock(&mStmgrs, "mStmgrs", "XchgFmnccmbd", "removeStmgrByJref");

	removeClstnsByJref(jref, true);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);

		mon.eventRemoveStmgr(jref);
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgFmnccmbd", "removeStmgrByJref");
};

Clstn* XchgFmnccmbd::addClstn(
			const uint ixFmncVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const Arg& argMask
			, const uint ixVJactype
		) {
	cref_t cref(ixFmncVCall, jref, false, ixVJobmask, jrefTrig);
	cref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgFmnccmbd", "addClstn");

	clstn = getClstnByCref(cref);

	if (clstn) {
		clstn->argMask = argMask;
		clstn->ixVJactype = ixVJactype;

		mon.eventChangeClstn(jref, VecFmncVCall::getSref(ixFmncVCall), false, Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, argMask.writeText(), Clstn::VecVJactype::getSref(ixVJactype));

	} else {
		clstn = new Clstn(cref, argMask, ixVJactype);
		clstns.insert(pair<cref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<cref2_t,cref_t>(cref2, cref));

		mon.eventAddClstn(jref, VecFmncVCall::getSref(ixFmncVCall), false, Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, argMask.writeText(), Clstn::VecVJactype::getSref(ixVJactype));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgFmnccmbd", "addClstn");

	return(clstn);
};

Clstn* XchgFmnccmbd::addIxClstn(
			const uint ixFmncVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixFmncVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgFmnccmbd::addRefClstn(
			const uint ixFmncVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const ubigint refMask
			, const uint ixVJactype
		) {
	Arg argMask(0, refMask, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixFmncVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgFmnccmbd::addIxRefClstn(
			const uint ixFmncVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const ubigint refMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, refMask, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixFmncVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgFmnccmbd::addIxRefSrefClstn(
			const uint ixFmncVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const ubigint refMask
			, const string& srefMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, refMask, {}, srefMask, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixFmncVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgFmnccmbd::addClstnStmgr(
			const uint ixFmncVCall
			, const ubigint jref
		) {
	cref_t cref(ixFmncVCall, jref, true, Clstn::VecVJobmask::ALL, 0);
	cref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgFmnccmbd", "addClstnStmgr");

	clstn = getClstnByCref(cref);

	if (!clstn) {
		clstn = new Clstn(cref, Arg(), Clstn::VecVJactype::LOCK);
		clstns.insert(pair<cref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<cref2_t,cref_t>(cref2, cref));

		mon.eventAddClstn(jref, VecFmncVCall::getSref(ixFmncVCall), true, Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::ALL), 0, "", Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgFmnccmbd", "addClstnStmgr");

	return(clstn);
};

Clstn* XchgFmnccmbd::getClstnByCref(
			const cref_t& cref
		) {
	Clstn* clstn = NULL;

	Mutex::lock(&mClstns, "mClstns", "XchgFmnccmbd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	Mutex::unlock(&mClstns, "mClstns", "XchgFmnccmbd", "getClstnByCref");

	return clstn;
};

void XchgFmnccmbd::getClstnsByJref(
			const ubigint jref
			, const bool stmgr
			, vector<uint>& icsFmncVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsFmncVCall.clear();
	icsVJobmask.clear();

	Mutex::lock(&mClstns, "mClstns", "XchgFmnccmbd", "getClstnsByJref");

	auto rng = cref2sClstns.equal_range(cref2_t(jref, stmgr, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsFmncVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgFmnccmbd", "getClstnsByJref");
};

void XchgFmnccmbd::removeClstns(
			const uint ixFmncVCall
			, const ubigint jref
			, const bool stmgr
		) {
	Mutex::lock(&mClstns, "mClstns", "XchgFmnccmbd", "removeClstns");

	uint ixVJobmask;
	ubigint jrefTrig;

	auto rng = clstns.equal_range(cref_t(ixFmncVCall, jref, stmgr));
	for (auto it=rng.first;it!=rng.second;it++) {
		ixVJobmask = it->second->cref.ixVJobmask;
		jrefTrig = it->second->cref.jrefTrig;

		cref2sClstns.erase(cref2_t(it->first));
		delete it->second;

		mon.eventRemoveClstn(jref, VecFmncVCall::getSref(ixFmncVCall), stmgr, Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig);
	};
	clstns.erase(rng.first, rng.second);

	Mutex::unlock(&mClstns, "mClstns", "XchgFmnccmbd", "removeClstns");
};

void XchgFmnccmbd::removeClstnsByJref(
			const ubigint jref
			, const bool stmgr
		) {
	Mutex::lock(&mClstns, "mClstns", "XchgFmnccmbd", "removeClstnsByJref");

	uint ixVCall;
	uint ixVJobmask;
	ubigint jrefTrig;

	auto rng = cref2sClstns.equal_range(cref2_t(jref, stmgr));
	for (auto it=rng.first;it!=rng.second;it++) {
		auto it2 = clstns.find(it->second);

		ixVCall = it2->second->cref.ixVCall;
		ixVJobmask = it2->second->cref.ixVJobmask;
		jrefTrig = it2->second->cref.jrefTrig;

		delete it2->second;
		clstns.erase(it2);

		mon.eventRemoveClstn(jref, VecFmncVCall::getSref(ixVCall), stmgr, Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig);
	};
	cref2sClstns.erase(rng.first, rng.second);

	Mutex::unlock(&mClstns, "mClstns", "XchgFmnccmbd", "removeClstnsByJref");
};

void XchgFmnccmbd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefs
			, vector<bool>& stmgrs
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	JobFmnc* job = NULL;

	bool match;

	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "findJrefsByCall");
	Mutex::lock(&mClstns, "mClstns", "XchgFmnccmbd", "findJrefsByCall");

	auto rng = clstns.equal_range(cref_t(call->ixVCall, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		clstn = it->second;

		if (clstn->cref.stmgr) {
			jrefs.push_back(clstn->cref.jref);
			stmgrs.push_back(true);
			icsVJactype.push_back(0);

		} else {
			match = true;

			if (clstn->argMask.mask & Arg::IX) if (clstn->argMask.ix != call->argInv.ix) match = false;
			if (clstn->argMask.mask & Arg::REF) if (clstn->argMask.ref != call->argInv.ref) match = false;
			if (clstn->argMask.mask & Arg::SREF) if (clstn->argMask.sref.compare(call->argInv.sref) != 0) match = false;
			if (clstn->argMask.mask & Arg::INTVAL) if (clstn->argMask.intval != call->argInv.intval) match = false;
			if (clstn->argMask.mask & Arg::DBLVAL) if (clstn->argMask.dblval != call->argInv.dblval) match = false;
			if (clstn->argMask.mask & Arg::BOOLVAL) if (clstn->argMask.boolval != call->argInv.boolval) match = false;
			if (clstn->argMask.mask & Arg::TXTVAL) if (clstn->argMask.txtval.compare(call->argInv.txtval) != 0) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about call->jref
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					// check if trigger job is immediate sub-job to listener job
					job = getJobByJref(call->jref);
					if (job) if (job->jrefSup == clstn->cref.jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::MAST) {
					// check if trigger job is master-job to listener job
					if (call->jref != clstn->cref.jref) {
						job = getJobByJref(clstn->cref.jref);
						if (job) if (call->jref == job->jrefMast) match = true;
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SELF) {
					// check if trigger job is equivalent to listener job
					if (call->jref == clstn->cref.jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SLV) {
					// check if listener job is master-job to trigger job
					if (call->jref != clstn->cref.jref) {
						job = getJobByJref(call->jref);
						if (job) if (clstn->cref.jref == job->jrefMast) match = true;
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					// require specific jref
					if (clstn->cref.jrefTrig == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					// check if trigger job is down the tree from listener job ; note that the order in jobs is unordered (unfortunately)
					job = getJobByJref(call->jref);

					while (job != NULL) {
						if (job->jref == clstn->cref.jref) {
							// add
							match = true;
							break;
						};

						job = getJobByJref(job->jrefSup);
					};
				};
			};

			if (match) {
				jrefs.push_back(clstn->cref.jref);
				stmgrs.push_back(false);
				icsVJactype.push_back(clstn->ixVJactype);
			};
		};
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgFmnccmbd", "findJrefsByCall");
	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "findJrefsByCall");
};

void XchgFmnccmbd::triggerCall(
			DbsFmnc* dbsfmnc
			, Call* call
		) {
	vector<ubigint> jrefs;
	vector<bool> stmgrs;
	vector<uint> icsVJactype;

	ubigint jref;
	uint ixVJactype;

	StmgrFmnc* stmgr = NULL;

	JobFmnc* job = NULL;

	ubigint eref;

	Arg argRet_old;

	eref = mon.eventTriggerCall(call->jref, VecFmncVCall::getSref(call->ixVCall), call->argInv.writeText());

	findJrefsByCall(call, jrefs, stmgrs, icsVJactype);

	for (unsigned int i=0;i<jrefs.size();i++) {
		jref = jrefs[i];
		ixVJactype = icsVJactype[i];

		if (stmgrs[i]) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				stmgr->handleCall(dbsfmnc, call);

				if (!(call->argRet == argRet_old)) mon.eventRetCall(eref, jref, call->argRet.writeText());

				stmgr->unlockAccess("XchgFmnccmbd", "triggerCall");
			};

		} else {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgFmnccmbd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (Mutex::trylock(&(job->mAccess), "job(" + to_string(jref) + ")->mAccess", "XchgFmnccmbd", "triggerCall") == EBUSY) continue;
					};
				};

				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				job->handleCall(dbsfmnc, call);

				if (call->argRet != argRet_old) mon.eventRetCall(eref, jref, call->argRet.writeText());
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgFmnccmbd", "triggerCall");
			};
		};

		if (call->abort) break;
	};

	mon.eventFinalizeCall(eref);
};

bool XchgFmnccmbd::triggerArgToArgCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

  call = new Call(ixFmncVCall, jref, argInv);
	triggerCall(dbsfmnc, call);

	argRet = call->argRet;
	retval = call->abort;

  delete call;
	return retval;
};

bool XchgFmnccmbd::triggerCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerIxCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerRefCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerIntvalCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerBoolvalCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerIxRefCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerIxSrefCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerIxIntvalCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerIxDblvalCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet));
};

bool XchgFmnccmbd::triggerToBoolvalCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgFmnccmbd::triggerIxToBoolvalCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgFmnccmbd::triggerRefToSrefCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) srefRet = argRet.sref;

	return(retval);
};

bool XchgFmnccmbd::triggerRefToBoolvalCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgFmnccmbd::triggerIxRefToIxCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgFmnccmbd::triggerIxRefToRefCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgFmnccmbd::triggerIxRefSrefCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgFmnccmbd::triggerIxRefSrefIntvalCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgFmnccmbd::triggerIxRefSrefIntvalToRefCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgFmnccmbd::triggerRefToIxCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgFmnccmbd::triggerSrefToRefCall(
			DbsFmnc* dbsfmnc
			, const uint ixFmncVCall
			, const ubigint jref
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsfmnc, ixFmncVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

DcolFmnc* XchgFmnccmbd::addDcol(
			const ubigint jref
		) {
	JobFmnc* job = NULL;

	DcolFmnc* dcol = NULL;

	// create new dcol and append to dcol list
	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "addDcol");
	Mutex::lock(&mDcols, "mDcols", "XchgFmnccmbd", "addDcol");

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			dcol = new DcolFmnc(jref, job->ixFmncVLocale);
			dcols[jref] = dcol;

			mon.eventAddDcol(jref);

			dcol->lockAccess("XchgFmnccmbd", "addDcol");
		};

		// make dcol the session's active notify dcol
		triggerIxRefCall(NULL, VecFmncVCall::CALLFMNCREFPRESET, jref, VecFmncVPreset::PREFMNCJREFNOTIFY, jref);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgFmnccmbd", "addDcol");
	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "addDcol");

	return(dcol);
};

DcolFmnc* XchgFmnccmbd::getDcolByJref(
			const ubigint jref
			, const bool tree
		) {
	JobFmnc* job = NULL;

	DcolFmnc* dcol = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "getDcolByJref");
	Mutex::lock(&mDcols, "mDcols", "XchgFmnccmbd", "getDcolByJref");

	job = getJobByJref(jref);

	while (job != NULL) {
		auto it = dcols.find(job->jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgFmnccmbd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		job = getJobByJref(job->jrefSup);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgFmnccmbd", "addDcol");
	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "addDcol");

	return(dcol);
};

void XchgFmnccmbd::removeDcolByJref(
			const ubigint jref
		) {
	Mutex::lock(&mDcols, "mDcols", "XchgFmnccmbd", "removeDcolByJref");

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);

		mon.eventRemoveDcol(jref);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgFmnccmbd", "removeDcolByJref");
};

void XchgFmnccmbd::submitDpch(
			DpchEngFmnc* dpcheng
		) {
	DcolFmnc* dcol = NULL;
	pthread_cond_t* cReady_backup;

	DpchEngFmnc* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		mon.eventSubmitDpch(dpcheng->jref, VecFmncVDpch::getSref(dpcheng->ixFmncVDpch), dpcheng->getSrefsMask(), "");

		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);
			dcol->req = NULL;
			//cout << "XchgFmnccmbd::submitDpch() waiting request for ixFmncVDpch = " << dpcheng->ixFmncVDpch << ", jref = " << dpcheng->jref << endl;

			Cond::signal(cReady_backup, "dcol(" + to_string(dcol->jref) + ")->req->cReady", "XchgFmnccmbd", "submitDpch");

			dcol->unlockAccess("XchgFmnccmbd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it=dcol->dpchs.begin();it!=dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixFmncVDpch == dpcheng->ixFmncVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgFmnccmbd::submitDpch() merge for ixFmncVDpch = " << dpcheng->ixFmncVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgFmnccmbd::submitDpch() append for ixFmncVDpch = " << dpcheng->ixFmncVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgFmnccmbd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngFmnc* XchgFmnccmbd::pullFirstDpch(
			DcolFmnc* dcol
		) {
	DpchEngFmnc* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgFmnccmbd::addJob(
			JobFmnc* job
		) {
	JobFmnc* supjob = NULL;

	// get new jref and append to job list
	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "addJob");

	job->jref = jrefseq->getNewRef();
	jobs[job->jref] = job;

	supjob = getJobByJref(job->jrefSup);
	if (supjob) supjob->jrefsSub.insert(job->jref);

	mon.eventAddJob(job->jrefSup, VecFmncVJob::getSref(job->ixFmncVJob), job->jref);

	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "addJob");

	return(job->jref);
};

ubigint XchgFmnccmbd::addJob(
			DbsFmnc* dbsfmnc
			, JobFmnc* job
		) {
	JobFmnc* supjob = NULL;

	JobFmnc* mastjob = NULL;

	// get new jref, append to job list and integrate into master/slave structure
	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "addJob");

	job->jref = jrefseq->getNewRef();
	jobs[job->jref] = job;

	supjob = getJobByJref(job->jrefSup);
	if (supjob) supjob->jrefsSub.insert(job->jref);

	mon.eventAddJob(job->jrefSup, VecFmncVJob::getSref(job->ixFmncVJob), job->jref);

	// find current master job
	for (auto it=jobs.begin();it!=jobs.end();it++) {
		if (it->second->ixFmncVJob == job->ixFmncVJob) {
			mastjob = getJobByJref(it->second->jrefMast);
			break;
		};
	};

	if (mastjob) {
		job->jrefMast = mastjob->jref;

		if (job->prefmast) {
			// priority for becoming new master
			mastjob->jrefsSlv.push_front(job->jref);

			mon.eventBecomeSlave(job->jref);

			job->becomeSlave(dbsfmnc);

			claimMaster(dbsfmnc, job->jref);

		} else {
			mastjob->jrefsSlv.push_back(job->jref);

			mon.eventBecomeSlave(job->jref);

			job->becomeSlave(dbsfmnc);
		};

	} else {
		// only job of its type
		job->jrefMast = job->jref;

		mon.eventBecomeMaster(job->jref);

		job->becomeMaster(dbsfmnc);
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "addJob");

	return(job->jref);
};

JobFmnc* XchgFmnccmbd::getJobByJref(
			const ubigint jref
		) {
	JobFmnc* job = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "getJobByJref");

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "getJobByJref");

	return job;
};

void XchgFmnccmbd::removeJobByJref(
			const ubigint jref
		) {
	JobFmnc* supjob = NULL;
	JobFmnc* job = NULL;
	JobFmnc* subjob = NULL;

	JobFmnc* mastjob = NULL;
	JobFmnc* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "removeJobByJref");

	job = getJobByJref(jref);

	if (job) {
		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		// remove from master/slave structure
		if (job->jrefMast != 0) {
			if (job->jref == job->jrefMast) {
				mastjob = NULL;

				if (!job->jrefsSlv.empty()) {
					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL);

					mastjob = getJobByJref(job->jrefsSlv.front());
				};

				if (mastjob) {
					mon.eventGiveupSlave(mastjob->jref);
					mastjob->giveupSlave(NULL);

					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL);

					mastjob->jrefsSlv = job->jrefsSlv;
					mastjob->jrefsSlv.pop_front();

					mastjob->jrefMast = mastjob->jref;

					for (auto it=mastjob->jrefsSlv.begin();it!=mastjob->jrefsSlv.end();it++) {
						slvjob = getJobByJref(*it);
						if (slvjob) slvjob->jrefMast = mastjob->jref;
					};

					mon.eventBecomeMaster(mastjob->jref);
					mastjob->becomeMaster(NULL);

					triggerCall(NULL, VecFmncVCall::CALLFMNCMASTSLVCHG, mastjob->jref);

				} else {
					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL);
				};

			} else {
				mon.eventGiveupSlave(job->jref);
				job->giveupSlave(NULL);

				mastjob = getJobByJref(job->jrefMast);
				if (mastjob) mastjob->jrefsSlv.remove(job->jref);
			};
		};

		// super-job
		supjob = getJobByJref(job->jrefSup);
		if (supjob) supjob->jrefsSub.erase(jref);

		// sub-jobs
		while (job->jrefsSub.size() > 0) {
			subjob = getJobByJref(*(job->jrefsSub.begin()));
			if (subjob) delete subjob;
		};

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		mon.eventRemoveJob(jref);
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "removeJobByJref");
};

void XchgFmnccmbd::transferMaster(
			DbsFmnc* dbsfmnc
			, JobFmnc* fromjob
			, JobFmnc* tojob
		) {
	// requires mJobs locked and tojob at first position in fromjob->jrefsSlv
	JobFmnc* job = NULL;

	mon.eventGiveupSlave(tojob->jref);
	tojob->giveupSlave(dbsfmnc);

	mon.eventGiveupMaster(fromjob->jref);
	fromjob->giveupMaster(dbsfmnc);

	tojob->jrefsSlv = fromjob->jrefsSlv;
	fromjob->jrefsSlv.clear();
	tojob->jrefsSlv.pop_front();

	if (fromjob->prefmast) tojob->jrefsSlv.push_front(fromjob->jref);
	else tojob->jrefsSlv.push_back(fromjob->jref);

	tojob->jrefMast = tojob->jref;

	for (auto it=tojob->jrefsSlv.begin();it!=tojob->jrefsSlv.end();it++) {
		job = getJobByJref(*it);
		if (job) job->jrefMast = tojob->jref;
	};

	mon.eventBecomeMaster(tojob->jref);
	tojob->becomeMaster(dbsfmnc);

	mon.eventBecomeSlave(fromjob->jref);
	fromjob->becomeSlave(dbsfmnc);

	triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCMASTSLVCHG, tojob->jref);
	triggerCall(dbsfmnc, VecFmncVCall::CALLFMNCMASTSLVCHG, fromjob->jref);
};

void XchgFmnccmbd::offerMaster(
			DbsFmnc* dbsfmnc
			, const ubigint jref
		) {
	JobFmnc* mastjob = NULL;
	JobFmnc* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "offerMaster");

	mastjob = getJobByJref(jref);

	if (mastjob) {
		if (!mastjob->jrefsSlv.empty()) {
			slvjob = getJobByJref(mastjob->jrefsSlv.front());

			if (slvjob) if (slvjob->prefmast) transferMaster(dbsfmnc, mastjob, slvjob);
		};
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "offerMaster");
};

bool XchgFmnccmbd::claimMaster(
			DbsFmnc* dbsfmnc
			, const ubigint jref
		) {
	bool retval = false;

	JobFmnc* mastjob = NULL;
	JobFmnc* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgFmnccmbd", "claimMaster");

	slvjob = getJobByJref(jref);

	if (slvjob) {
		if (slvjob->jref != slvjob->jrefMast) {
			mastjob = getJobByJref(slvjob->jrefMast);

			if (mastjob) {
				for (auto it=mastjob->jrefsSlv.begin();it!=mastjob->jrefsSlv.end();it++) {
					// put slvjob first
					if (*it == jref) {
						*it = mastjob->jrefsSlv.front();
						mastjob->jrefsSlv.pop_front();
						mastjob->jrefsSlv.push_front(jref);

						break;
					};
				};

				if (mastjob->handleClaimMaster(dbsfmnc)) transferMaster(dbsfmnc, mastjob, slvjob);
			};
		};

		retval = (slvjob->jref == slvjob->jrefMast);
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgFmnccmbd", "claimMaster");

	return retval;
};

ubigint XchgFmnccmbd::addWakeup(
			const ubigint jref
			, const string sref
			, const unsigned int deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq->getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqFmnc* req = new ReqFmnc(ReqFmnc::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupFmnc* wakeup = new WakeupFmnc(this, wref, jref, sref, deltat, weak);

		res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
		if (res != 0) cout << "XchgFmnccmbd::addWakeup() error creating timer thread (" << res << ")" << endl;
		res = pthread_detach(timer);
		if (res != 0) cout << "XchgFmnccmbd::addWakeup() error detaching timer thread (" << res << ")" << endl;
	};

	return(wref);
};

void* XchgFmnccmbd::runWakeup(
			void* arg
		) {
	WakeupFmnc* wakeup = (WakeupFmnc*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqFmnc* req = new ReqFmnc(ReqFmnc::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

void XchgFmnccmbd::runExtcall(
			void* arg
		) {
	ExtcallFmnc* extcall = (ExtcallFmnc*) arg;

	// generate request to be treated by job processor
	ReqFmnc* req = new ReqFmnc(ReqFmnc::VecVBasetype::EXTCALL);
	req->call = new Call(*(extcall->call));

	extcall->xchg->addReq(req);
};


