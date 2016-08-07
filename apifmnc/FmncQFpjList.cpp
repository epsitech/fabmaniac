/**
  * \file FmncQFpjList.cpp
  * API code for table TblFmncQFpjList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFpjList.h"

/******************************************************************************
 class FmncQFpjList
 ******************************************************************************/

FmncQFpjList::FmncQFpjList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubRefFmncMFab
			, const string stubBioRefFmncMOrg
			, const string srefIxVState
			, const string titIxVState
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubRefFmncMFab = stubRefFmncMFab;
	this->stubBioRefFmncMOrg = stubBioRefFmncMOrg;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

bool FmncQFpjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFpjList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefFmncMFab", "fab", stubRefFmncMFab);
		extractStringUclc(docctx, basexpath, "stubBioRefFmncMOrg", "bio", stubBioRefFmncMOrg);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFpjList
 ******************************************************************************/

ListFmncQFpjList::ListFmncQFpjList() {
};

ListFmncQFpjList::ListFmncQFpjList(
			const ListFmncQFpjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFpjList(*(src.nodes[i]));
};

ListFmncQFpjList& ListFmncQFpjList::operator=(
			const ListFmncQFpjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFpjList(*(src.nodes[i]));

	return *this;
};

ListFmncQFpjList::~ListFmncQFpjList() {
	clear();
};

void ListFmncQFpjList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFpjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFpjList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFpjList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFpjList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFpjList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFpjList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

