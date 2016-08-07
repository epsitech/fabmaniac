/**
  * \file FmncQSkiList.cpp
  * API code for table TblFmncQSkiList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSkiList.h"

/******************************************************************************
 class FmncQSkiList
 ******************************************************************************/

FmncQSkiList::FmncQSkiList(
			const uint jnum
			, const string stubRefFmncMOrg
			, const string stubRefFmncMArticle
			, const string Quantity
			, const string osrefFmncKStocklcn
			, const string titOsrefFmncKStocklcn
			, const string ftmExpdate
		) {
	this->jnum = jnum;
	this->stubRefFmncMOrg = stubRefFmncMOrg;
	this->stubRefFmncMArticle = stubRefFmncMArticle;
	this->Quantity = Quantity;
	this->osrefFmncKStocklcn = osrefFmncKStocklcn;
	this->titOsrefFmncKStocklcn = titOsrefFmncKStocklcn;
	this->ftmExpdate = ftmExpdate;
};

bool FmncQSkiList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSkiList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefFmncMOrg", "org", stubRefFmncMOrg);
		extractStringUclc(docctx, basexpath, "stubRefFmncMArticle", "art", stubRefFmncMArticle);
		extractStringUclc(docctx, basexpath, "Quantity", "qty", Quantity);
		extractStringUclc(docctx, basexpath, "osrefFmncKStocklcn", "lcn", osrefFmncKStocklcn);
		extractStringUclc(docctx, basexpath, "titOsrefFmncKStocklcn", "lcn2", titOsrefFmncKStocklcn);
		extractStringUclc(docctx, basexpath, "ftmExpdate", "exd", ftmExpdate);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQSkiList
 ******************************************************************************/

ListFmncQSkiList::ListFmncQSkiList() {
};

ListFmncQSkiList::ListFmncQSkiList(
			const ListFmncQSkiList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSkiList(*(src.nodes[i]));
};

ListFmncQSkiList& ListFmncQSkiList::operator=(
			const ListFmncQSkiList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSkiList(*(src.nodes[i]));

	return *this;
};

ListFmncQSkiList::~ListFmncQSkiList() {
	clear();
};

void ListFmncQSkiList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSkiList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSkiList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSkiList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSkiList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSkiList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSkiList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

