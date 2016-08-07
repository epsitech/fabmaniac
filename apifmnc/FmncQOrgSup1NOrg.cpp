/**
  * \file FmncQOrgSup1NOrg.cpp
  * API code for table TblFmncQOrgSup1NOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgSup1NOrg.h"

/******************************************************************************
 class FmncQOrgSup1NOrg
 ******************************************************************************/

FmncQOrgSup1NOrg::FmncQOrgSup1NOrg(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQOrgSup1NOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgSup1NOrg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgSup1NOrg
 ******************************************************************************/

ListFmncQOrgSup1NOrg::ListFmncQOrgSup1NOrg() {
};

ListFmncQOrgSup1NOrg::ListFmncQOrgSup1NOrg(
			const ListFmncQOrgSup1NOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgSup1NOrg(*(src.nodes[i]));
};

ListFmncQOrgSup1NOrg& ListFmncQOrgSup1NOrg::operator=(
			const ListFmncQOrgSup1NOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgSup1NOrg(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgSup1NOrg::~ListFmncQOrgSup1NOrg() {
	clear();
};

void ListFmncQOrgSup1NOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgSup1NOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgSup1NOrg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgSup1NOrg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgSup1NOrg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgSup1NOrg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgSup1NOrg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

