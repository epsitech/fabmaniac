/**
  * \file FmncQOrgPco1NPurchorder.cpp
  * API code for table TblFmncQOrgPco1NPurchorder (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgPco1NPurchorder.h"

/******************************************************************************
 class FmncQOrgPco1NPurchorder
 ******************************************************************************/

FmncQOrgPco1NPurchorder::FmncQOrgPco1NPurchorder(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQOrgPco1NPurchorder::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgPco1NPurchorder");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgPco1NPurchorder
 ******************************************************************************/

ListFmncQOrgPco1NPurchorder::ListFmncQOrgPco1NPurchorder() {
};

ListFmncQOrgPco1NPurchorder::ListFmncQOrgPco1NPurchorder(
			const ListFmncQOrgPco1NPurchorder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgPco1NPurchorder(*(src.nodes[i]));
};

ListFmncQOrgPco1NPurchorder& ListFmncQOrgPco1NPurchorder::operator=(
			const ListFmncQOrgPco1NPurchorder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgPco1NPurchorder(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgPco1NPurchorder::~ListFmncQOrgPco1NPurchorder() {
	clear();
};

void ListFmncQOrgPco1NPurchorder::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgPco1NPurchorder::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgPco1NPurchorder* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgPco1NPurchorder");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgPco1NPurchorder", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgPco1NPurchorder(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgPco1NPurchorder[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

