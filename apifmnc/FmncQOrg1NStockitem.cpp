/**
  * \file FmncQOrg1NStockitem.cpp
  * API code for table TblFmncQOrg1NStockitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrg1NStockitem.h"

/******************************************************************************
 class FmncQOrg1NStockitem
 ******************************************************************************/

FmncQOrg1NStockitem::FmncQOrg1NStockitem(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQOrg1NStockitem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrg1NStockitem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrg1NStockitem
 ******************************************************************************/

ListFmncQOrg1NStockitem::ListFmncQOrg1NStockitem() {
};

ListFmncQOrg1NStockitem::ListFmncQOrg1NStockitem(
			const ListFmncQOrg1NStockitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrg1NStockitem(*(src.nodes[i]));
};

ListFmncQOrg1NStockitem& ListFmncQOrg1NStockitem::operator=(
			const ListFmncQOrg1NStockitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrg1NStockitem(*(src.nodes[i]));

	return *this;
};

ListFmncQOrg1NStockitem::~ListFmncQOrg1NStockitem() {
	clear();
};

void ListFmncQOrg1NStockitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrg1NStockitem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrg1NStockitem* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrg1NStockitem");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrg1NStockitem", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrg1NStockitem(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrg1NStockitem[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

