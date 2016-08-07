/**
  * \file FmncQOrgMnf1NTool.cpp
  * API code for table TblFmncQOrgMnf1NTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgMnf1NTool.h"

/******************************************************************************
 class FmncQOrgMnf1NTool
 ******************************************************************************/

FmncQOrgMnf1NTool::FmncQOrgMnf1NTool(
			const uint jnum
			, const string stubRef
			, const string stubsSrefFmncMPerson
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
	this->stubsSrefFmncMPerson = stubsSrefFmncMPerson;
};

bool FmncQOrgMnf1NTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgMnf1NTool");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
		extractStringUclc(docctx, basexpath, "stubsSrefFmncMPerson", "sprs", stubsSrefFmncMPerson);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgMnf1NTool
 ******************************************************************************/

ListFmncQOrgMnf1NTool::ListFmncQOrgMnf1NTool() {
};

ListFmncQOrgMnf1NTool::ListFmncQOrgMnf1NTool(
			const ListFmncQOrgMnf1NTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgMnf1NTool(*(src.nodes[i]));
};

ListFmncQOrgMnf1NTool& ListFmncQOrgMnf1NTool::operator=(
			const ListFmncQOrgMnf1NTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgMnf1NTool(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgMnf1NTool::~ListFmncQOrgMnf1NTool() {
	clear();
};

void ListFmncQOrgMnf1NTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgMnf1NTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgMnf1NTool* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgMnf1NTool");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgMnf1NTool", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgMnf1NTool(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgMnf1NTool[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

