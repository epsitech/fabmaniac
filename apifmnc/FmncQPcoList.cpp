/**
  * \file FmncQPcoList.cpp
  * API code for table TblFmncQPcoList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPcoList.h"

/******************************************************************************
 class FmncQPcoList
 ******************************************************************************/

FmncQPcoList::FmncQPcoList(
			const uint jnum
			, const string sref
			, const string ftmDate
			, const string stubPcoRefFmncMOrg
			, const string stubSplRefFmncMOrg
			, const string stubRefFmncMFile
			, const string srefIxVState
			, const string titIxVState
			, const double Amount
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->ftmDate = ftmDate;
	this->stubPcoRefFmncMOrg = stubPcoRefFmncMOrg;
	this->stubSplRefFmncMOrg = stubSplRefFmncMOrg;
	this->stubRefFmncMFile = stubRefFmncMFile;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->Amount = Amount;
};

bool FmncQPcoList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQPcoList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "ftmDate", "dat", ftmDate);
		extractStringUclc(docctx, basexpath, "stubPcoRefFmncMOrg", "pco", stubPcoRefFmncMOrg);
		extractStringUclc(docctx, basexpath, "stubSplRefFmncMOrg", "spl", stubSplRefFmncMOrg);
		extractStringUclc(docctx, basexpath, "stubRefFmncMFile", "fil", stubRefFmncMFile);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractDoubleUclc(docctx, basexpath, "Amount", "amt", Amount);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQPcoList
 ******************************************************************************/

ListFmncQPcoList::ListFmncQPcoList() {
};

ListFmncQPcoList::ListFmncQPcoList(
			const ListFmncQPcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPcoList(*(src.nodes[i]));
};

ListFmncQPcoList& ListFmncQPcoList::operator=(
			const ListFmncQPcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPcoList(*(src.nodes[i]));

	return *this;
};

ListFmncQPcoList::~ListFmncQPcoList() {
	clear();
};

void ListFmncQPcoList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQPcoList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQPcoList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQPcoList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQPcoList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQPcoList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQPcoList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

