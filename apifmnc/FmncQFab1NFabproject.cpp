/**
  * \file FmncQFab1NFabproject.cpp
  * API code for table TblFmncQFab1NFabproject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFab1NFabproject.h"

/******************************************************************************
 class FmncQFab1NFabproject
 ******************************************************************************/

FmncQFab1NFabproject::FmncQFab1NFabproject(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQFab1NFabproject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFab1NFabproject");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFab1NFabproject
 ******************************************************************************/

ListFmncQFab1NFabproject::ListFmncQFab1NFabproject() {
};

ListFmncQFab1NFabproject::ListFmncQFab1NFabproject(
			const ListFmncQFab1NFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFab1NFabproject(*(src.nodes[i]));
};

ListFmncQFab1NFabproject& ListFmncQFab1NFabproject::operator=(
			const ListFmncQFab1NFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFab1NFabproject(*(src.nodes[i]));

	return *this;
};

ListFmncQFab1NFabproject::~ListFmncQFab1NFabproject() {
	clear();
};

void ListFmncQFab1NFabproject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFab1NFabproject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFab1NFabproject* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFab1NFabproject");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFab1NFabproject", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFab1NFabproject(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFab1NFabproject[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

