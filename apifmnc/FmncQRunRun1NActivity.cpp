/**
  * \file FmncQRunRun1NActivity.cpp
  * API code for table TblFmncQRunRun1NActivity (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQRunRun1NActivity.h"

/******************************************************************************
 class FmncQRunRun1NActivity
 ******************************************************************************/

FmncQRunRun1NActivity::FmncQRunRun1NActivity(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQRunRun1NActivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQRunRun1NActivity");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQRunRun1NActivity
 ******************************************************************************/

ListFmncQRunRun1NActivity::ListFmncQRunRun1NActivity() {
};

ListFmncQRunRun1NActivity::ListFmncQRunRun1NActivity(
			const ListFmncQRunRun1NActivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunRun1NActivity(*(src.nodes[i]));
};

ListFmncQRunRun1NActivity& ListFmncQRunRun1NActivity::operator=(
			const ListFmncQRunRun1NActivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunRun1NActivity(*(src.nodes[i]));

	return *this;
};

ListFmncQRunRun1NActivity::~ListFmncQRunRun1NActivity() {
	clear();
};

void ListFmncQRunRun1NActivity::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQRunRun1NActivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQRunRun1NActivity* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQRunRun1NActivity");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQRunRun1NActivity", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQRunRun1NActivity(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQRunRun1NActivity[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

