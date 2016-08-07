/**
  * \file FmncQTolList.cpp
  * API code for table TblFmncQTolList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolList.h"

/******************************************************************************
 class FmncQTolList
 ******************************************************************************/

FmncQTolList::FmncQTolList(
			const uint jnum
			, const string Title
			, const string stubFabRefFmncMFab
			, const string stubMnfRefFmncMOrg
			, const double Unitprice
			, const string Training
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->stubFabRefFmncMFab = stubFabRefFmncMFab;
	this->stubMnfRefFmncMOrg = stubMnfRefFmncMOrg;
	this->Unitprice = Unitprice;
	this->Training = Training;
};

bool FmncQTolList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubFabRefFmncMFab", "fab", stubFabRefFmncMFab);
		extractStringUclc(docctx, basexpath, "stubMnfRefFmncMOrg", "mnf", stubMnfRefFmncMOrg);
		extractDoubleUclc(docctx, basexpath, "Unitprice", "upr", Unitprice);
		extractStringUclc(docctx, basexpath, "Training", "trn", Training);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTolList
 ******************************************************************************/

ListFmncQTolList::ListFmncQTolList() {
};

ListFmncQTolList::ListFmncQTolList(
			const ListFmncQTolList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolList(*(src.nodes[i]));
};

ListFmncQTolList& ListFmncQTolList::operator=(
			const ListFmncQTolList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolList(*(src.nodes[i]));

	return *this;
};

ListFmncQTolList::~ListFmncQTolList() {
	clear();
};

void ListFmncQTolList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

