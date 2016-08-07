/**
  * \file FmncQAct1NStep.cpp
  * API code for table TblFmncQAct1NStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQAct1NStep.h"

/******************************************************************************
 class FmncQAct1NStep
 ******************************************************************************/

FmncQAct1NStep::FmncQAct1NStep(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQAct1NStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQAct1NStep");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQAct1NStep
 ******************************************************************************/

ListFmncQAct1NStep::ListFmncQAct1NStep() {
};

ListFmncQAct1NStep::ListFmncQAct1NStep(
			const ListFmncQAct1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQAct1NStep(*(src.nodes[i]));
};

ListFmncQAct1NStep& ListFmncQAct1NStep::operator=(
			const ListFmncQAct1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQAct1NStep(*(src.nodes[i]));

	return *this;
};

ListFmncQAct1NStep::~ListFmncQAct1NStep() {
	clear();
};

void ListFmncQAct1NStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQAct1NStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQAct1NStep* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQAct1NStep");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQAct1NStep", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQAct1NStep(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQAct1NStep[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

