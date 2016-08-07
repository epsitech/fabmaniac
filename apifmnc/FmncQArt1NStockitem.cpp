/**
  * \file FmncQArt1NStockitem.cpp
  * API code for table TblFmncQArt1NStockitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQArt1NStockitem.h"

/******************************************************************************
 class FmncQArt1NStockitem
 ******************************************************************************/

FmncQArt1NStockitem::FmncQArt1NStockitem(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQArt1NStockitem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQArt1NStockitem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQArt1NStockitem
 ******************************************************************************/

ListFmncQArt1NStockitem::ListFmncQArt1NStockitem() {
};

ListFmncQArt1NStockitem::ListFmncQArt1NStockitem(
			const ListFmncQArt1NStockitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArt1NStockitem(*(src.nodes[i]));
};

ListFmncQArt1NStockitem& ListFmncQArt1NStockitem::operator=(
			const ListFmncQArt1NStockitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArt1NStockitem(*(src.nodes[i]));

	return *this;
};

ListFmncQArt1NStockitem::~ListFmncQArt1NStockitem() {
	clear();
};

void ListFmncQArt1NStockitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQArt1NStockitem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQArt1NStockitem* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQArt1NStockitem");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQArt1NStockitem", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQArt1NStockitem(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQArt1NStockitem[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

