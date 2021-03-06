/**
  * \file FmncQOrgKStocklcn.cpp
  * API code for table TblFmncQOrgKStocklcn (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgKStocklcn.h"

/******************************************************************************
 class FmncQOrgKStocklcn
 ******************************************************************************/

FmncQOrgKStocklcn::FmncQOrgKStocklcn(
			const uint jnum
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const string Title
			, const string Comment
		) {
	this->jnum = jnum;
	this->yesnoFixed = yesnoFixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

bool FmncQOrgKStocklcn::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgKStocklcn");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "yesnoFixed", "fix", yesnoFixed);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Avail", "avl", Avail);
		extractStringUclc(docctx, basexpath, "Implied", "imp", Implied);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgKStocklcn
 ******************************************************************************/

ListFmncQOrgKStocklcn::ListFmncQOrgKStocklcn() {
};

ListFmncQOrgKStocklcn::ListFmncQOrgKStocklcn(
			const ListFmncQOrgKStocklcn& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgKStocklcn(*(src.nodes[i]));
};

ListFmncQOrgKStocklcn& ListFmncQOrgKStocklcn::operator=(
			const ListFmncQOrgKStocklcn& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgKStocklcn(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgKStocklcn::~ListFmncQOrgKStocklcn() {
	clear();
};

void ListFmncQOrgKStocklcn::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgKStocklcn::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgKStocklcn* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgKStocklcn");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgKStocklcn", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgKStocklcn(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgKStocklcn[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

