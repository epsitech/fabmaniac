/**
  * \file FmncQPcoAPos.cpp
  * API code for table TblFmncQPcoAPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPcoAPos.h"

/******************************************************************************
 class FmncQPcoAPos
 ******************************************************************************/

FmncQPcoAPos::FmncQPcoAPos(
			const uint jnum
			, const double Quantity
			, const string Itemno
			, const string stubRefFmncMArticle
			, const double Unitprice
			, const double Price
		) {
	this->jnum = jnum;
	this->Quantity = Quantity;
	this->Itemno = Itemno;
	this->stubRefFmncMArticle = stubRefFmncMArticle;
	this->Unitprice = Unitprice;
	this->Price = Price;
};

bool FmncQPcoAPos::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQPcoAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractDoubleUclc(docctx, basexpath, "Quantity", "qty", Quantity);
		extractStringUclc(docctx, basexpath, "Itemno", "itn", Itemno);
		extractStringUclc(docctx, basexpath, "stubRefFmncMArticle", "art", stubRefFmncMArticle);
		extractDoubleUclc(docctx, basexpath, "Unitprice", "upr", Unitprice);
		extractDoubleUclc(docctx, basexpath, "Price", "prc", Price);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQPcoAPos
 ******************************************************************************/

ListFmncQPcoAPos::ListFmncQPcoAPos() {
};

ListFmncQPcoAPos::ListFmncQPcoAPos(
			const ListFmncQPcoAPos& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPcoAPos(*(src.nodes[i]));
};

ListFmncQPcoAPos& ListFmncQPcoAPos::operator=(
			const ListFmncQPcoAPos& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPcoAPos(*(src.nodes[i]));

	return *this;
};

ListFmncQPcoAPos::~ListFmncQPcoAPos() {
	clear();
};

void ListFmncQPcoAPos::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQPcoAPos::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQPcoAPos* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQPcoAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQPcoAPos", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQPcoAPos(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQPcoAPos[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

