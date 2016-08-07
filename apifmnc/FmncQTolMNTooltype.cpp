/**
  * \file FmncQTolMNTooltype.cpp
  * API code for table TblFmncQTolMNTooltype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolMNTooltype.h"

/******************************************************************************
 class FmncQTolMNTooltype
 ******************************************************************************/

FmncQTolMNTooltype::FmncQTolMNTooltype(
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

bool FmncQTolMNTooltype::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolMNTooltype");
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
 class ListFmncQTolMNTooltype
 ******************************************************************************/

ListFmncQTolMNTooltype::ListFmncQTolMNTooltype() {
};

ListFmncQTolMNTooltype::ListFmncQTolMNTooltype(
			const ListFmncQTolMNTooltype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolMNTooltype(*(src.nodes[i]));
};

ListFmncQTolMNTooltype& ListFmncQTolMNTooltype::operator=(
			const ListFmncQTolMNTooltype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolMNTooltype(*(src.nodes[i]));

	return *this;
};

ListFmncQTolMNTooltype::~ListFmncQTolMNTooltype() {
	clear();
};

void ListFmncQTolMNTooltype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolMNTooltype::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolMNTooltype* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolMNTooltype");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolMNTooltype", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolMNTooltype(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolMNTooltype[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

