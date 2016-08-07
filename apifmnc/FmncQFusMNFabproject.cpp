/**
  * \file FmncQFusMNFabproject.cpp
  * API code for table TblFmncQFusMNFabproject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFusMNFabproject.h"

/******************************************************************************
 class FmncQFusMNFabproject
 ******************************************************************************/

FmncQFusMNFabproject::FmncQFusMNFabproject(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool FmncQFusMNFabproject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFusMNFabproject");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFusMNFabproject
 ******************************************************************************/

ListFmncQFusMNFabproject::ListFmncQFusMNFabproject() {
};

ListFmncQFusMNFabproject::ListFmncQFusMNFabproject(
			const ListFmncQFusMNFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFusMNFabproject(*(src.nodes[i]));
};

ListFmncQFusMNFabproject& ListFmncQFusMNFabproject::operator=(
			const ListFmncQFusMNFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFusMNFabproject(*(src.nodes[i]));

	return *this;
};

ListFmncQFusMNFabproject::~ListFmncQFusMNFabproject() {
	clear();
};

void ListFmncQFusMNFabproject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFusMNFabproject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFusMNFabproject* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFusMNFabproject");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFusMNFabproject", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFusMNFabproject(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFusMNFabproject[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

