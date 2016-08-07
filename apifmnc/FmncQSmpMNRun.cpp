/**
  * \file FmncQSmpMNRun.cpp
  * API code for table TblFmncQSmpMNRun (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSmpMNRun.h"

/******************************************************************************
 class FmncQSmpMNRun
 ******************************************************************************/

FmncQSmpMNRun::FmncQSmpMNRun(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool FmncQSmpMNRun::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSmpMNRun");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQSmpMNRun
 ******************************************************************************/

ListFmncQSmpMNRun::ListFmncQSmpMNRun() {
};

ListFmncQSmpMNRun::ListFmncQSmpMNRun(
			const ListFmncQSmpMNRun& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpMNRun(*(src.nodes[i]));
};

ListFmncQSmpMNRun& ListFmncQSmpMNRun::operator=(
			const ListFmncQSmpMNRun& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpMNRun(*(src.nodes[i]));

	return *this;
};

ListFmncQSmpMNRun::~ListFmncQSmpMNRun() {
	clear();
};

void ListFmncQSmpMNRun::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSmpMNRun::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSmpMNRun* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSmpMNRun");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSmpMNRun", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSmpMNRun(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSmpMNRun[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

