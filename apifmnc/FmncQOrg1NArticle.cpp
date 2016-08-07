/**
  * \file FmncQOrg1NArticle.cpp
  * API code for table TblFmncQOrg1NArticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrg1NArticle.h"

/******************************************************************************
 class FmncQOrg1NArticle
 ******************************************************************************/

FmncQOrg1NArticle::FmncQOrg1NArticle(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool FmncQOrg1NArticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrg1NArticle");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrg1NArticle
 ******************************************************************************/

ListFmncQOrg1NArticle::ListFmncQOrg1NArticle() {
};

ListFmncQOrg1NArticle::ListFmncQOrg1NArticle(
			const ListFmncQOrg1NArticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrg1NArticle(*(src.nodes[i]));
};

ListFmncQOrg1NArticle& ListFmncQOrg1NArticle::operator=(
			const ListFmncQOrg1NArticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrg1NArticle(*(src.nodes[i]));

	return *this;
};

ListFmncQOrg1NArticle::~ListFmncQOrg1NArticle() {
	clear();
};

void ListFmncQOrg1NArticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrg1NArticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrg1NArticle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrg1NArticle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrg1NArticle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrg1NArticle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrg1NArticle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

