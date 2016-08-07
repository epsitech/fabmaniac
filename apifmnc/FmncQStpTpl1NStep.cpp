/**
  * \file FmncQStpTpl1NStep.cpp
  * API code for table TblFmncQStpTpl1NStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQStpTpl1NStep.h"

/******************************************************************************
 class FmncQStpTpl1NStep
 ******************************************************************************/

FmncQStpTpl1NStep::FmncQStpTpl1NStep(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQStpTpl1NStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQStpTpl1NStep");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQStpTpl1NStep
 ******************************************************************************/

ListFmncQStpTpl1NStep::ListFmncQStpTpl1NStep() {
};

ListFmncQStpTpl1NStep::ListFmncQStpTpl1NStep(
			const ListFmncQStpTpl1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpTpl1NStep(*(src.nodes[i]));
};

ListFmncQStpTpl1NStep& ListFmncQStpTpl1NStep::operator=(
			const ListFmncQStpTpl1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpTpl1NStep(*(src.nodes[i]));

	return *this;
};

ListFmncQStpTpl1NStep::~ListFmncQStpTpl1NStep() {
	clear();
};

void ListFmncQStpTpl1NStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQStpTpl1NStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQStpTpl1NStep* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQStpTpl1NStep");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQStpTpl1NStep", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQStpTpl1NStep(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQStpTpl1NStep[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

