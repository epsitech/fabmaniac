/**
  * \file FmncQFabFab1NTool.cpp
  * API code for table TblFmncQFabFab1NTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFabFab1NTool.h"

/******************************************************************************
 class FmncQFabFab1NTool
 ******************************************************************************/

FmncQFabFab1NTool::FmncQFabFab1NTool(
			const uint jnum
			, const string stubRef
			, const string stubsSrefFmncMPerson
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
	this->stubsSrefFmncMPerson = stubsSrefFmncMPerson;
};

bool FmncQFabFab1NTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFabFab1NTool");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
		extractStringUclc(docctx, basexpath, "stubsSrefFmncMPerson", "sprs", stubsSrefFmncMPerson);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFabFab1NTool
 ******************************************************************************/

ListFmncQFabFab1NTool::ListFmncQFabFab1NTool() {
};

ListFmncQFabFab1NTool::ListFmncQFabFab1NTool(
			const ListFmncQFabFab1NTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFabFab1NTool(*(src.nodes[i]));
};

ListFmncQFabFab1NTool& ListFmncQFabFab1NTool::operator=(
			const ListFmncQFabFab1NTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFabFab1NTool(*(src.nodes[i]));

	return *this;
};

ListFmncQFabFab1NTool::~ListFmncQFabFab1NTool() {
	clear();
};

void ListFmncQFabFab1NTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFabFab1NTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFabFab1NTool* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFabFab1NTool");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFabFab1NTool", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFabFab1NTool(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFabFab1NTool[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

