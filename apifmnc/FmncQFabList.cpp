/**
  * \file FmncQFabList.cpp
  * API code for table TblFmncQFabList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFabList.h"

/******************************************************************************
 class FmncQFabList
 ******************************************************************************/

FmncQFabList::FmncQFabList(
			const uint jnum
			, const string stubRefFmncMOrg
		) {
	this->jnum = jnum;
	this->stubRefFmncMOrg = stubRefFmncMOrg;
};

bool FmncQFabList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFabList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefFmncMOrg", "org", stubRefFmncMOrg);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFabList
 ******************************************************************************/

ListFmncQFabList::ListFmncQFabList() {
};

ListFmncQFabList::ListFmncQFabList(
			const ListFmncQFabList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFabList(*(src.nodes[i]));
};

ListFmncQFabList& ListFmncQFabList::operator=(
			const ListFmncQFabList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFabList(*(src.nodes[i]));

	return *this;
};

ListFmncQFabList::~ListFmncQFabList() {
	clear();
};

void ListFmncQFabList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFabList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFabList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFabList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFabList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFabList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFabList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

