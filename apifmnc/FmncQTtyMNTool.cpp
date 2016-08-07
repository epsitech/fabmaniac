/**
  * \file FmncQTtyMNTool.cpp
  * API code for table TblFmncQTtyMNTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTtyMNTool.h"

/******************************************************************************
 class FmncQTtyMNTool
 ******************************************************************************/

FmncQTtyMNTool::FmncQTtyMNTool(
			const uint jnum
			, const string stubMref
			, const string srefsFmncKToolchar
			, const string titsSrefsFmncKToolchar
			, const string defSrefsFmncKSteppar
			, const string titsDefSrefsFmncKSteppar
			, const string optSrefsFmncKSteppar
			, const string titsOptSrefsFmncKSteppar
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefsFmncKToolchar = srefsFmncKToolchar;
	this->titsSrefsFmncKToolchar = titsSrefsFmncKToolchar;
	this->defSrefsFmncKSteppar = defSrefsFmncKSteppar;
	this->titsDefSrefsFmncKSteppar = titsDefSrefsFmncKSteppar;
	this->optSrefsFmncKSteppar = optSrefsFmncKSteppar;
	this->titsOptSrefsFmncKSteppar = titsOptSrefsFmncKSteppar;
};

bool FmncQTtyMNTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTtyMNTool");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefsFmncKToolchar", "tch", srefsFmncKToolchar);
		extractStringUclc(docctx, basexpath, "titsSrefsFmncKToolchar", "tch2", titsSrefsFmncKToolchar);
		extractStringUclc(docctx, basexpath, "defSrefsFmncKSteppar", "def", defSrefsFmncKSteppar);
		extractStringUclc(docctx, basexpath, "titsDefSrefsFmncKSteppar", "def2", titsDefSrefsFmncKSteppar);
		extractStringUclc(docctx, basexpath, "optSrefsFmncKSteppar", "opt", optSrefsFmncKSteppar);
		extractStringUclc(docctx, basexpath, "titsOptSrefsFmncKSteppar", "opt2", titsOptSrefsFmncKSteppar);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTtyMNTool
 ******************************************************************************/

ListFmncQTtyMNTool::ListFmncQTtyMNTool() {
};

ListFmncQTtyMNTool::ListFmncQTtyMNTool(
			const ListFmncQTtyMNTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyMNTool(*(src.nodes[i]));
};

ListFmncQTtyMNTool& ListFmncQTtyMNTool::operator=(
			const ListFmncQTtyMNTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTtyMNTool(*(src.nodes[i]));

	return *this;
};

ListFmncQTtyMNTool::~ListFmncQTtyMNTool() {
	clear();
};

void ListFmncQTtyMNTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTtyMNTool::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTtyMNTool* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTtyMNTool");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTtyMNTool", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTtyMNTool(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTtyMNTool[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

