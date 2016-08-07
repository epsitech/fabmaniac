/**
  * \file FmncQRunMNFab.cpp
  * API code for table TblFmncQRunMNFab (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQRunMNFab.h"

/******************************************************************************
 class FmncQRunMNFab
 ******************************************************************************/

FmncQRunMNFab::FmncQRunMNFab(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool FmncQRunMNFab::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQRunMNFab");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQRunMNFab
 ******************************************************************************/

ListFmncQRunMNFab::ListFmncQRunMNFab() {
};

ListFmncQRunMNFab::ListFmncQRunMNFab(
			const ListFmncQRunMNFab& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunMNFab(*(src.nodes[i]));
};

ListFmncQRunMNFab& ListFmncQRunMNFab::operator=(
			const ListFmncQRunMNFab& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunMNFab(*(src.nodes[i]));

	return *this;
};

ListFmncQRunMNFab::~ListFmncQRunMNFab() {
	clear();
};

void ListFmncQRunMNFab::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQRunMNFab::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQRunMNFab* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQRunMNFab");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQRunMNFab", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQRunMNFab(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQRunMNFab[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

