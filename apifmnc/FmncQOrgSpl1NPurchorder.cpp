/**
  * \file FmncQOrgSpl1NPurchorder.cpp
  * API code for table TblFmncQOrgSpl1NPurchorder (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgSpl1NPurchorder.h"

/******************************************************************************
 class FmncQOrgSpl1NPurchorder
 ******************************************************************************/

FmncQOrgSpl1NPurchorder::FmncQOrgSpl1NPurchorder(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQOrgSpl1NPurchorder::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgSpl1NPurchorder");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgSpl1NPurchorder
 ******************************************************************************/

ListFmncQOrgSpl1NPurchorder::ListFmncQOrgSpl1NPurchorder() {
};

ListFmncQOrgSpl1NPurchorder::ListFmncQOrgSpl1NPurchorder(
			const ListFmncQOrgSpl1NPurchorder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgSpl1NPurchorder(*(src.nodes[i]));
};

ListFmncQOrgSpl1NPurchorder& ListFmncQOrgSpl1NPurchorder::operator=(
			const ListFmncQOrgSpl1NPurchorder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgSpl1NPurchorder(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgSpl1NPurchorder::~ListFmncQOrgSpl1NPurchorder() {
	clear();
};

void ListFmncQOrgSpl1NPurchorder::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgSpl1NPurchorder::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgSpl1NPurchorder* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgSpl1NPurchorder");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgSpl1NPurchorder", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgSpl1NPurchorder(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgSpl1NPurchorder[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

