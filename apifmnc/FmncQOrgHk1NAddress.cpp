/**
  * \file FmncQOrgHk1NAddress.cpp
  * API code for table TblFmncQOrgHk1NAddress (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgHk1NAddress.h"

/******************************************************************************
 class FmncQOrgHk1NAddress
 ******************************************************************************/

FmncQOrgHk1NAddress::FmncQOrgHk1NAddress(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQOrgHk1NAddress::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgHk1NAddress");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgHk1NAddress
 ******************************************************************************/

ListFmncQOrgHk1NAddress::ListFmncQOrgHk1NAddress() {
};

ListFmncQOrgHk1NAddress::ListFmncQOrgHk1NAddress(
			const ListFmncQOrgHk1NAddress& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgHk1NAddress(*(src.nodes[i]));
};

ListFmncQOrgHk1NAddress& ListFmncQOrgHk1NAddress::operator=(
			const ListFmncQOrgHk1NAddress& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgHk1NAddress(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgHk1NAddress::~ListFmncQOrgHk1NAddress() {
	clear();
};

void ListFmncQOrgHk1NAddress::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgHk1NAddress::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgHk1NAddress* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgHk1NAddress");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgHk1NAddress", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgHk1NAddress(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgHk1NAddress[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

