/**
  * \file FmncQPrsMNOrg.cpp
  * API code for table TblFmncQPrsMNOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPrsMNOrg.h"

/******************************************************************************
 class FmncQPrsMNOrg
 ******************************************************************************/

FmncQPrsMNOrg::FmncQPrsMNOrg(
			const uint jnum
			, const string stubMref
			, const string ftmX1Startd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->ftmX1Startd = ftmX1Startd;
	this->ftmX1Stopd = ftmX1Stopd;
	this->srefKFunction = srefKFunction;
	this->titSrefKFunction = titSrefKFunction;
};

bool FmncQPrsMNOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQPrsMNOrg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "ftmX1Startd", "sta", ftmX1Startd);
		extractStringUclc(docctx, basexpath, "ftmX1Stopd", "sto", ftmX1Stopd);
		extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction);
		extractStringUclc(docctx, basexpath, "titSrefKFunction", "fct2", titSrefKFunction);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQPrsMNOrg
 ******************************************************************************/

ListFmncQPrsMNOrg::ListFmncQPrsMNOrg() {
};

ListFmncQPrsMNOrg::ListFmncQPrsMNOrg(
			const ListFmncQPrsMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsMNOrg(*(src.nodes[i]));
};

ListFmncQPrsMNOrg& ListFmncQPrsMNOrg::operator=(
			const ListFmncQPrsMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsMNOrg(*(src.nodes[i]));

	return *this;
};

ListFmncQPrsMNOrg::~ListFmncQPrsMNOrg() {
	clear();
};

void ListFmncQPrsMNOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQPrsMNOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQPrsMNOrg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQPrsMNOrg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQPrsMNOrg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQPrsMNOrg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQPrsMNOrg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

