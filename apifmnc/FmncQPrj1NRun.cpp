/**
  * \file FmncQPrj1NRun.cpp
  * API code for table TblFmncQPrj1NRun (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPrj1NRun.h"

/******************************************************************************
 class FmncQPrj1NRun
 ******************************************************************************/

FmncQPrj1NRun::FmncQPrj1NRun(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQPrj1NRun::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQPrj1NRun");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQPrj1NRun
 ******************************************************************************/

ListFmncQPrj1NRun::ListFmncQPrj1NRun() {
};

ListFmncQPrj1NRun::ListFmncQPrj1NRun(
			const ListFmncQPrj1NRun& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrj1NRun(*(src.nodes[i]));
};

ListFmncQPrj1NRun& ListFmncQPrj1NRun::operator=(
			const ListFmncQPrj1NRun& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrj1NRun(*(src.nodes[i]));

	return *this;
};

ListFmncQPrj1NRun::~ListFmncQPrj1NRun() {
	clear();
};

void ListFmncQPrj1NRun::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQPrj1NRun::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQPrj1NRun* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQPrj1NRun");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQPrj1NRun", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQPrj1NRun(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQPrj1NRun[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

