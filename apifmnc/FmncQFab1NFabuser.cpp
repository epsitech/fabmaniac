/**
  * \file FmncQFab1NFabuser.cpp
  * API code for table TblFmncQFab1NFabuser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFab1NFabuser.h"

/******************************************************************************
 class FmncQFab1NFabuser
 ******************************************************************************/

FmncQFab1NFabuser::FmncQFab1NFabuser(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQFab1NFabuser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFab1NFabuser");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFab1NFabuser
 ******************************************************************************/

ListFmncQFab1NFabuser::ListFmncQFab1NFabuser() {
};

ListFmncQFab1NFabuser::ListFmncQFab1NFabuser(
			const ListFmncQFab1NFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFab1NFabuser(*(src.nodes[i]));
};

ListFmncQFab1NFabuser& ListFmncQFab1NFabuser::operator=(
			const ListFmncQFab1NFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFab1NFabuser(*(src.nodes[i]));

	return *this;
};

ListFmncQFab1NFabuser::~ListFmncQFab1NFabuser() {
	clear();
};

void ListFmncQFab1NFabuser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFab1NFabuser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFab1NFabuser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFab1NFabuser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFab1NFabuser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFab1NFabuser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFab1NFabuser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

