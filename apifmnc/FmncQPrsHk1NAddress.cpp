/**
  * \file FmncQPrsHk1NAddress.cpp
  * API code for table TblFmncQPrsHk1NAddress (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPrsHk1NAddress.h"

/******************************************************************************
 class FmncQPrsHk1NAddress
 ******************************************************************************/

FmncQPrsHk1NAddress::FmncQPrsHk1NAddress(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQPrsHk1NAddress::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQPrsHk1NAddress");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQPrsHk1NAddress
 ******************************************************************************/

ListFmncQPrsHk1NAddress::ListFmncQPrsHk1NAddress() {
};

ListFmncQPrsHk1NAddress::ListFmncQPrsHk1NAddress(
			const ListFmncQPrsHk1NAddress& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsHk1NAddress(*(src.nodes[i]));
};

ListFmncQPrsHk1NAddress& ListFmncQPrsHk1NAddress::operator=(
			const ListFmncQPrsHk1NAddress& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsHk1NAddress(*(src.nodes[i]));

	return *this;
};

ListFmncQPrsHk1NAddress::~ListFmncQPrsHk1NAddress() {
	clear();
};

void ListFmncQPrsHk1NAddress::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQPrsHk1NAddress::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQPrsHk1NAddress* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQPrsHk1NAddress");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQPrsHk1NAddress", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQPrsHk1NAddress(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQPrsHk1NAddress[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

