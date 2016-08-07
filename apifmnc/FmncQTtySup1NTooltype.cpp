/**
  * \file FmncQTtySup1NTooltype.cpp
  * API code for table TblFmncQTtySup1NTooltype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTtySup1NTooltype.h"

/******************************************************************************
 class FmncQTtySup1NTooltype
 ******************************************************************************/

FmncQTtySup1NTooltype::FmncQTtySup1NTooltype(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQTtySup1NTooltype::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTtySup1NTooltype");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTtySup1NTooltype
 ******************************************************************************/

ListFmncQTtySup1NTooltype::ListFmncQTtySup1NTooltype() {
};

ListFmncQTtySup1NTooltype::ListFmncQTtySup1NTooltype(
			const ListFmncQTtySup1NTooltype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtySup1NTooltype(*(src.nodes[i]));
};

ListFmncQTtySup1NTooltype& ListFmncQTtySup1NTooltype::operator=(
			const ListFmncQTtySup1NTooltype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtySup1NTooltype(*(src.nodes[i]));

	return *this;
};

ListFmncQTtySup1NTooltype::~ListFmncQTtySup1NTooltype() {
	clear();
};

void ListFmncQTtySup1NTooltype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTtySup1NTooltype::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTtySup1NTooltype* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTtySup1NTooltype");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTtySup1NTooltype", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTtySup1NTooltype(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTtySup1NTooltype[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

