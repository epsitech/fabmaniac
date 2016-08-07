/**
  * \file FmncQTolRlv1NStep.cpp
  * API code for table TblFmncQTolRlv1NStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolRlv1NStep.h"

/******************************************************************************
 class FmncQTolRlv1NStep
 ******************************************************************************/

FmncQTolRlv1NStep::FmncQTolRlv1NStep(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQTolRlv1NStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolRlv1NStep");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTolRlv1NStep
 ******************************************************************************/

ListFmncQTolRlv1NStep::ListFmncQTolRlv1NStep() {
};

ListFmncQTolRlv1NStep::ListFmncQTolRlv1NStep(
			const ListFmncQTolRlv1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolRlv1NStep(*(src.nodes[i]));
};

ListFmncQTolRlv1NStep& ListFmncQTolRlv1NStep::operator=(
			const ListFmncQTolRlv1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolRlv1NStep(*(src.nodes[i]));

	return *this;
};

ListFmncQTolRlv1NStep::~ListFmncQTolRlv1NStep() {
	clear();
};

void ListFmncQTolRlv1NStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolRlv1NStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolRlv1NStep* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolRlv1NStep");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolRlv1NStep", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolRlv1NStep(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolRlv1NStep[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

