/**
  * \file FmncQSmpList.cpp
  * API code for table TblFmncQSmpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSmpList.h"

/******************************************************************************
 class FmncQSmpList
 ******************************************************************************/

FmncQSmpList::FmncQSmpList(
			const uint jnum
			, const string sref
			, const string stubSupRefFmncMSample
			, const string stubRefFmncMArticle
			, const string Material
			, const string srefIxVState
			, const string titIxVState
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubSupRefFmncMSample = stubSupRefFmncMSample;
	this->stubRefFmncMArticle = stubRefFmncMArticle;
	this->Material = Material;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

bool FmncQSmpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSmpList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubSupRefFmncMSample", "sup", stubSupRefFmncMSample);
		extractStringUclc(docctx, basexpath, "stubRefFmncMArticle", "art", stubRefFmncMArticle);
		extractStringUclc(docctx, basexpath, "Material", "mat", Material);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQSmpList
 ******************************************************************************/

ListFmncQSmpList::ListFmncQSmpList() {
};

ListFmncQSmpList::ListFmncQSmpList(
			const ListFmncQSmpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpList(*(src.nodes[i]));
};

ListFmncQSmpList& ListFmncQSmpList::operator=(
			const ListFmncQSmpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpList(*(src.nodes[i]));

	return *this;
};

ListFmncQSmpList::~ListFmncQSmpList() {
	clear();
};

void ListFmncQSmpList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSmpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSmpList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSmpList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSmpList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSmpList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSmpList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

