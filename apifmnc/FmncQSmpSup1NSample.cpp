/**
  * \file FmncQSmpSup1NSample.cpp
  * API code for table TblFmncQSmpSup1NSample (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSmpSup1NSample.h"

/******************************************************************************
 class FmncQSmpSup1NSample
 ******************************************************************************/

FmncQSmpSup1NSample::FmncQSmpSup1NSample(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQSmpSup1NSample::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSmpSup1NSample");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQSmpSup1NSample
 ******************************************************************************/

ListFmncQSmpSup1NSample::ListFmncQSmpSup1NSample() {
};

ListFmncQSmpSup1NSample::ListFmncQSmpSup1NSample(
			const ListFmncQSmpSup1NSample& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpSup1NSample(*(src.nodes[i]));
};

ListFmncQSmpSup1NSample& ListFmncQSmpSup1NSample::operator=(
			const ListFmncQSmpSup1NSample& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpSup1NSample(*(src.nodes[i]));

	return *this;
};

ListFmncQSmpSup1NSample::~ListFmncQSmpSup1NSample() {
	clear();
};

void ListFmncQSmpSup1NSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSmpSup1NSample::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSmpSup1NSample* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSmpSup1NSample");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSmpSup1NSample", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSmpSup1NSample(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSmpSup1NSample[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

