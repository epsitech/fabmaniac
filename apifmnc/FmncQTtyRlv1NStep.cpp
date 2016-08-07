/**
  * \file FmncQTtyRlv1NStep.cpp
  * API code for table TblFmncQTtyRlv1NStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTtyRlv1NStep.h"

/******************************************************************************
 class FmncQTtyRlv1NStep
 ******************************************************************************/

FmncQTtyRlv1NStep::FmncQTtyRlv1NStep(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQTtyRlv1NStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTtyRlv1NStep");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTtyRlv1NStep
 ******************************************************************************/

ListFmncQTtyRlv1NStep::ListFmncQTtyRlv1NStep() {
};

ListFmncQTtyRlv1NStep::ListFmncQTtyRlv1NStep(
			const ListFmncQTtyRlv1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyRlv1NStep(*(src.nodes[i]));
};

ListFmncQTtyRlv1NStep& ListFmncQTtyRlv1NStep::operator=(
			const ListFmncQTtyRlv1NStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyRlv1NStep(*(src.nodes[i]));

	return *this;
};

ListFmncQTtyRlv1NStep::~ListFmncQTtyRlv1NStep() {
	clear();
};

void ListFmncQTtyRlv1NStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTtyRlv1NStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTtyRlv1NStep* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTtyRlv1NStep");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTtyRlv1NStep", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTtyRlv1NStep(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTtyRlv1NStep[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

