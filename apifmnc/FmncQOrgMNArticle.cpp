/**
  * \file FmncQOrgMNArticle.cpp
  * API code for table TblFmncQOrgMNArticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgMNArticle.h"

/******************************************************************************
 class FmncQOrgMNArticle
 ******************************************************************************/

FmncQOrgMNArticle::FmncQOrgMNArticle(
			const uint jnum
			, const string stubMref
			, const string Itemno
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->Itemno = Itemno;
};

bool FmncQOrgMNArticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgMNArticle");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "Itemno", "itn", Itemno);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgMNArticle
 ******************************************************************************/

ListFmncQOrgMNArticle::ListFmncQOrgMNArticle() {
};

ListFmncQOrgMNArticle::ListFmncQOrgMNArticle(
			const ListFmncQOrgMNArticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgMNArticle(*(src.nodes[i]));
};

ListFmncQOrgMNArticle& ListFmncQOrgMNArticle::operator=(
			const ListFmncQOrgMNArticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgMNArticle(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgMNArticle::~ListFmncQOrgMNArticle() {
	clear();
};

void ListFmncQOrgMNArticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgMNArticle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgMNArticle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgMNArticle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgMNArticle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgMNArticle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgMNArticle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

