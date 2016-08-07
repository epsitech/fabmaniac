/**
  * \file FmncQFusList.cpp
  * API code for table TblFmncQFusList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFusList.h"

/******************************************************************************
 class FmncQFusList
 ******************************************************************************/

FmncQFusList::FmncQFusList(
			const uint jnum
			, const string stubRefFmncMPerson
			, const string sref
			, const string stubRefFmncMFab
			, const string stubRefFmncMFabproject
			, const string srefIxVState
			, const string titIxVState
		) {
	this->jnum = jnum;
	this->stubRefFmncMPerson = stubRefFmncMPerson;
	this->sref = sref;
	this->stubRefFmncMFab = stubRefFmncMFab;
	this->stubRefFmncMFabproject = stubRefFmncMFabproject;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

bool FmncQFusList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFusList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefFmncMPerson", "prs", stubRefFmncMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefFmncMFab", "fab", stubRefFmncMFab);
		extractStringUclc(docctx, basexpath, "stubRefFmncMFabproject", "fpj", stubRefFmncMFabproject);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFusList
 ******************************************************************************/

ListFmncQFusList::ListFmncQFusList() {
};

ListFmncQFusList::ListFmncQFusList(
			const ListFmncQFusList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFusList(*(src.nodes[i]));
};

ListFmncQFusList& ListFmncQFusList::operator=(
			const ListFmncQFusList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFusList(*(src.nodes[i]));

	return *this;
};

ListFmncQFusList::~ListFmncQFusList() {
	clear();
};

void ListFmncQFusList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFusList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFusList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFusList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFusList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFusList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFusList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

