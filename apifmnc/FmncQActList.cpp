/**
  * \file FmncQActList.cpp
  * API code for table TblFmncQActList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQActList.h"

/******************************************************************************
 class FmncQActList
 ******************************************************************************/

FmncQActList::FmncQActList(
			const uint jnum
			, const string Title
			, const string stubRunRefFmncMRun
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->stubRunRefFmncMRun = stubRunRefFmncMRun;
};

bool FmncQActList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQActList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRunRefFmncMRun", "run", stubRunRefFmncMRun);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQActList
 ******************************************************************************/

ListFmncQActList::ListFmncQActList() {
};

ListFmncQActList::ListFmncQActList(
			const ListFmncQActList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQActList(*(src.nodes[i]));
};

ListFmncQActList& ListFmncQActList::operator=(
			const ListFmncQActList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQActList(*(src.nodes[i]));

	return *this;
};

ListFmncQActList::~ListFmncQActList() {
	clear();
};

void ListFmncQActList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQActList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQActList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQActList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQActList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQActList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQActList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

