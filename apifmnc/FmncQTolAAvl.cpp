/**
  * \file FmncQTolAAvl.cpp
  * API code for table TblFmncQTolAAvl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolAAvl.h"

/******************************************************************************
 class FmncQTolAAvl
 ******************************************************************************/

FmncQTolAAvl::FmncQTolAAvl(
			const uint jnum
			, const string ftmX1Startd
			, const string srefX2IxVWkday
			, const string ftmX3Startt
			, const string ftmX3Stopt
			, const string srefKAvltype
			, const string titSrefKAvltype
		) {
	this->jnum = jnum;
	this->ftmX1Startd = ftmX1Startd;
	this->srefX2IxVWkday = srefX2IxVWkday;
	this->ftmX3Startt = ftmX3Startt;
	this->ftmX3Stopt = ftmX3Stopt;
	this->srefKAvltype = srefKAvltype;
	this->titSrefKAvltype = titSrefKAvltype;
};

bool FmncQTolAAvl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolAAvl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "ftmX1Startd", "dat", ftmX1Startd);
		extractStringUclc(docctx, basexpath, "srefX2IxVWkday", "wdy", srefX2IxVWkday);
		extractStringUclc(docctx, basexpath, "ftmX3Startt", "sta", ftmX3Startt);
		extractStringUclc(docctx, basexpath, "ftmX3Stopt", "sto", ftmX3Stopt);
		extractStringUclc(docctx, basexpath, "srefKAvltype", "aty", srefKAvltype);
		extractStringUclc(docctx, basexpath, "titSrefKAvltype", "aty2", titSrefKAvltype);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTolAAvl
 ******************************************************************************/

ListFmncQTolAAvl::ListFmncQTolAAvl() {
};

ListFmncQTolAAvl::ListFmncQTolAAvl(
			const ListFmncQTolAAvl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAAvl(*(src.nodes[i]));
};

ListFmncQTolAAvl& ListFmncQTolAAvl::operator=(
			const ListFmncQTolAAvl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAAvl(*(src.nodes[i]));

	return *this;
};

ListFmncQTolAAvl::~ListFmncQTolAAvl() {
	clear();
};

void ListFmncQTolAAvl::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolAAvl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolAAvl* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolAAvl");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolAAvl", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolAAvl(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolAAvl[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

