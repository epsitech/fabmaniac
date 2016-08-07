/**
  * \file FmncQOrgBio1NFabproject.cpp
  * API code for table TblFmncQOrgBio1NFabproject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgBio1NFabproject.h"

/******************************************************************************
 class FmncQOrgBio1NFabproject
 ******************************************************************************/

FmncQOrgBio1NFabproject::FmncQOrgBio1NFabproject(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQOrgBio1NFabproject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgBio1NFabproject");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgBio1NFabproject
 ******************************************************************************/

ListFmncQOrgBio1NFabproject::ListFmncQOrgBio1NFabproject() {
};

ListFmncQOrgBio1NFabproject::ListFmncQOrgBio1NFabproject(
			const ListFmncQOrgBio1NFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgBio1NFabproject(*(src.nodes[i]));
};

ListFmncQOrgBio1NFabproject& ListFmncQOrgBio1NFabproject::operator=(
			const ListFmncQOrgBio1NFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgBio1NFabproject(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgBio1NFabproject::~ListFmncQOrgBio1NFabproject() {
	clear();
};

void ListFmncQOrgBio1NFabproject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgBio1NFabproject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgBio1NFabproject* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgBio1NFabproject");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgBio1NFabproject", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgBio1NFabproject(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgBio1NFabproject[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

