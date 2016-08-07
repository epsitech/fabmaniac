/**
  * \file FmncQSmpAPar.cpp
  * API code for table TblFmncQSmpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSmpAPar.h"

/******************************************************************************
 class FmncQSmpAPar
 ******************************************************************************/

FmncQSmpAPar::FmncQSmpAPar(
			const uint jnum
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string osrefKVal
			, const string titOsrefKVal
		) {
	this->jnum = jnum;
	this->x1SrefKKey = x1SrefKKey;
	this->titX1SrefKKey = titX1SrefKKey;
	this->osrefKVal = osrefKVal;
	this->titOsrefKVal = titOsrefKVal;
};

bool FmncQSmpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSmpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey);
		extractStringUclc(docctx, basexpath, "titX1SrefKKey", "key2", titX1SrefKKey);
		extractStringUclc(docctx, basexpath, "osrefKVal", "val", osrefKVal);
		extractStringUclc(docctx, basexpath, "titOsrefKVal", "val2", titOsrefKVal);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQSmpAPar
 ******************************************************************************/

ListFmncQSmpAPar::ListFmncQSmpAPar() {
};

ListFmncQSmpAPar::ListFmncQSmpAPar(
			const ListFmncQSmpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpAPar(*(src.nodes[i]));
};

ListFmncQSmpAPar& ListFmncQSmpAPar::operator=(
			const ListFmncQSmpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpAPar(*(src.nodes[i]));

	return *this;
};

ListFmncQSmpAPar::~ListFmncQSmpAPar() {
	clear();
};

void ListFmncQSmpAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSmpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSmpAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSmpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSmpAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSmpAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSmpAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

