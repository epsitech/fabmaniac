/**
  * \file FmncQPrjList.cpp
  * API code for table TblFmncQPrjList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPrjList.h"

/******************************************************************************
 class FmncQPrjList
 ******************************************************************************/

FmncQPrjList::FmncQPrjList(
			const uint jnum
			, const string Title
			, const string srefIxVState
			, const string titIxVState
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

bool FmncQPrjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQPrjList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQPrjList
 ******************************************************************************/

ListFmncQPrjList::ListFmncQPrjList() {
};

ListFmncQPrjList::ListFmncQPrjList(
			const ListFmncQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrjList(*(src.nodes[i]));
};

ListFmncQPrjList& ListFmncQPrjList::operator=(
			const ListFmncQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrjList(*(src.nodes[i]));

	return *this;
};

ListFmncQPrjList::~ListFmncQPrjList() {
	clear();
};

void ListFmncQPrjList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQPrjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQPrjList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQPrjList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQPrjList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQPrjList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQPrjList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

