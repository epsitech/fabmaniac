/**
  * \file FmncQBilList.cpp
  * API code for table TblFmncQBilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQBilList.h"

/******************************************************************************
 class FmncQBilList
 ******************************************************************************/

FmncQBilList::FmncQBilList(
			const uint jnum
			, const string sref
			, const string ftmDate
			, const string stubRefFmncMFabproject
			, const string stubRefFmncMFile
			, const string srefIxVState
			, const string titIxVState
			, const string ftmPrdstart
			, const string ftmPrdstop
			, const double Amount
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->ftmDate = ftmDate;
	this->stubRefFmncMFabproject = stubRefFmncMFabproject;
	this->stubRefFmncMFile = stubRefFmncMFile;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ftmPrdstart = ftmPrdstart;
	this->ftmPrdstop = ftmPrdstop;
	this->Amount = Amount;
};

bool FmncQBilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQBilList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "ftmDate", "dat", ftmDate);
		extractStringUclc(docctx, basexpath, "stubRefFmncMFabproject", "prj", stubRefFmncMFabproject);
		extractStringUclc(docctx, basexpath, "stubRefFmncMFile", "fil", stubRefFmncMFile);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "ftmPrdstart", "pra", ftmPrdstart);
		extractStringUclc(docctx, basexpath, "ftmPrdstop", "pro", ftmPrdstop);
		extractDoubleUclc(docctx, basexpath, "Amount", "amt", Amount);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQBilList
 ******************************************************************************/

ListFmncQBilList::ListFmncQBilList() {
};

ListFmncQBilList::ListFmncQBilList(
			const ListFmncQBilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQBilList(*(src.nodes[i]));
};

ListFmncQBilList& ListFmncQBilList::operator=(
			const ListFmncQBilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQBilList(*(src.nodes[i]));

	return *this;
};

ListFmncQBilList::~ListFmncQBilList() {
	clear();
};

void ListFmncQBilList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQBilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQBilList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQBilList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQBilList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQBilList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQBilList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

