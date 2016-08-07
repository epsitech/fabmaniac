/**
  * \file FmncQFpj1NBill.cpp
  * API code for table TblFmncQFpj1NBill (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFpj1NBill.h"

/******************************************************************************
 class FmncQFpj1NBill
 ******************************************************************************/

FmncQFpj1NBill::FmncQFpj1NBill(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQFpj1NBill::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFpj1NBill");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFpj1NBill
 ******************************************************************************/

ListFmncQFpj1NBill::ListFmncQFpj1NBill() {
};

ListFmncQFpj1NBill::ListFmncQFpj1NBill(
			const ListFmncQFpj1NBill& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFpj1NBill(*(src.nodes[i]));
};

ListFmncQFpj1NBill& ListFmncQFpj1NBill::operator=(
			const ListFmncQFpj1NBill& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFpj1NBill(*(src.nodes[i]));

	return *this;
};

ListFmncQFpj1NBill::~ListFmncQFpj1NBill() {
	clear();
};

void ListFmncQFpj1NBill::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFpj1NBill::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFpj1NBill* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFpj1NBill");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFpj1NBill", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFpj1NBill(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFpj1NBill[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

