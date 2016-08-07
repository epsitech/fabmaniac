/**
  * \file FmncQRunList.cpp
  * API code for table TblFmncQRunList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQRunList.h"

/******************************************************************************
 class FmncQRunList
 ******************************************************************************/

FmncQRunList::FmncQRunList(
			const uint jnum
			, const string Title
			, const string stubRefFmncMProject
			, const string srefIxVState
			, const string titIxVState
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->stubRefFmncMProject = stubRefFmncMProject;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

bool FmncQRunList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQRunList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefFmncMProject", "prj", stubRefFmncMProject);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQRunList
 ******************************************************************************/

ListFmncQRunList::ListFmncQRunList() {
};

ListFmncQRunList::ListFmncQRunList(
			const ListFmncQRunList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunList(*(src.nodes[i]));
};

ListFmncQRunList& ListFmncQRunList::operator=(
			const ListFmncQRunList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunList(*(src.nodes[i]));

	return *this;
};

ListFmncQRunList::~ListFmncQRunList() {
	clear();
};

void ListFmncQRunList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQRunList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQRunList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQRunList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQRunList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQRunList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQRunList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

