/**
  * \file FmncQTolSvcMNOrg.cpp
  * API code for table TblFmncQTolSvcMNOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolSvcMNOrg.h"

/******************************************************************************
 class FmncQTolSvcMNOrg
 ******************************************************************************/

FmncQTolSvcMNOrg::FmncQTolSvcMNOrg(
			const uint jnum
			, const string stubMref
			, const string stubsTrefFmncMPerson
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubsTrefFmncMPerson = stubsTrefFmncMPerson;
};

bool FmncQTolSvcMNOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolSvcMNOrg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubsTrefFmncMPerson", "tprs", stubsTrefFmncMPerson);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTolSvcMNOrg
 ******************************************************************************/

ListFmncQTolSvcMNOrg::ListFmncQTolSvcMNOrg() {
};

ListFmncQTolSvcMNOrg::ListFmncQTolSvcMNOrg(
			const ListFmncQTolSvcMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolSvcMNOrg(*(src.nodes[i]));
};

ListFmncQTolSvcMNOrg& ListFmncQTolSvcMNOrg::operator=(
			const ListFmncQTolSvcMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolSvcMNOrg(*(src.nodes[i]));

	return *this;
};

ListFmncQTolSvcMNOrg::~ListFmncQTolSvcMNOrg() {
	clear();
};

void ListFmncQTolSvcMNOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolSvcMNOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolSvcMNOrg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolSvcMNOrg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolSvcMNOrg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolSvcMNOrg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolSvcMNOrg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

