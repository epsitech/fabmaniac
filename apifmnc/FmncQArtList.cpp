/**
  * \file FmncQArtList.cpp
  * API code for table TblFmncQArtList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQArtList.h"

/******************************************************************************
 class FmncQArtList
 ******************************************************************************/

FmncQArtList::FmncQArtList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubRefFmncMOrg
			, const string stubRefFmncMTool
			, const string srefKType
			, const string titSrefKType
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubRefFmncMOrg = stubRefFmncMOrg;
	this->stubRefFmncMTool = stubRefFmncMTool;
	this->srefKType = srefKType;
	this->titSrefKType = titSrefKType;
};

bool FmncQArtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQArtList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefFmncMOrg", "org", stubRefFmncMOrg);
		extractStringUclc(docctx, basexpath, "stubRefFmncMTool", "tol", stubRefFmncMTool);
		extractStringUclc(docctx, basexpath, "srefKType", "typ", srefKType);
		extractStringUclc(docctx, basexpath, "titSrefKType", "typ2", titSrefKType);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQArtList
 ******************************************************************************/

ListFmncQArtList::ListFmncQArtList() {
};

ListFmncQArtList::ListFmncQArtList(
			const ListFmncQArtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArtList(*(src.nodes[i]));
};

ListFmncQArtList& ListFmncQArtList::operator=(
			const ListFmncQArtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArtList(*(src.nodes[i]));

	return *this;
};

ListFmncQArtList::~ListFmncQArtList() {
	clear();
};

void ListFmncQArtList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQArtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQArtList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQArtList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQArtList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQArtList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQArtList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

