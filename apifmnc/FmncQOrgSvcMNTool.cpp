/**
  * \file FmncQOrgSvcMNTool.cpp
  * API code for table TblFmncQOrgSvcMNTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgSvcMNTool.h"

/******************************************************************************
 class FmncQOrgSvcMNTool
 ******************************************************************************/

FmncQOrgSvcMNTool::FmncQOrgSvcMNTool(
			const uint jnum
			, const string stubMref
			, const string stubsTrefFmncMPerson
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubsTrefFmncMPerson = stubsTrefFmncMPerson;
};

bool FmncQOrgSvcMNTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgSvcMNTool");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubsTrefFmncMPerson", "tprs", stubsTrefFmncMPerson);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgSvcMNTool
 ******************************************************************************/

ListFmncQOrgSvcMNTool::ListFmncQOrgSvcMNTool() {
};

ListFmncQOrgSvcMNTool::ListFmncQOrgSvcMNTool(
			const ListFmncQOrgSvcMNTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgSvcMNTool(*(src.nodes[i]));
};

ListFmncQOrgSvcMNTool& ListFmncQOrgSvcMNTool::operator=(
			const ListFmncQOrgSvcMNTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgSvcMNTool(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgSvcMNTool::~ListFmncQOrgSvcMNTool() {
	clear();
};

void ListFmncQOrgSvcMNTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgSvcMNTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgSvcMNTool* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgSvcMNTool");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgSvcMNTool", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgSvcMNTool(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgSvcMNTool[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

