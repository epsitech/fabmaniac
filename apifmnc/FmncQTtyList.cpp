/**
  * \file FmncQTtyList.cpp
  * API code for table TblFmncQTtyList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTtyList.h"

/******************************************************************************
 class FmncQTtyList
 ******************************************************************************/

FmncQTtyList::FmncQTtyList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubSupRefFmncMTooltype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubSupRefFmncMTooltype = stubSupRefFmncMTooltype;
};

bool FmncQTtyList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubSupRefFmncMTooltype", "sup", stubSupRefFmncMTooltype);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTtyList
 ******************************************************************************/

ListFmncQTtyList::ListFmncQTtyList() {
};

ListFmncQTtyList::ListFmncQTtyList(
			const ListFmncQTtyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyList(*(src.nodes[i]));
};

ListFmncQTtyList& ListFmncQTtyList::operator=(
			const ListFmncQTtyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyList(*(src.nodes[i]));

	return *this;
};

ListFmncQTtyList::~ListFmncQTtyList() {
	clear();
};

void ListFmncQTtyList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTtyList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTtyList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTtyList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTtyList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTtyList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

