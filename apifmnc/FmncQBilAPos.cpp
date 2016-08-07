/**
  * \file FmncQBilAPos.cpp
  * API code for table TblFmncQBilAPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQBilAPos.h"

/******************************************************************************
 class FmncQBilAPos
 ******************************************************************************/

FmncQBilAPos::FmncQBilAPos(
			const uint jnum
			, const string stubX1RefFmncMFabuser
			, const string stubX2RefFmncMTool
			, const double Quantity
			, const string Article
			, const double Unitprice
			, const double Price
		) {
	this->jnum = jnum;
	this->stubX1RefFmncMFabuser = stubX1RefFmncMFabuser;
	this->stubX2RefFmncMTool = stubX2RefFmncMTool;
	this->Quantity = Quantity;
	this->Article = Article;
	this->Unitprice = Unitprice;
	this->Price = Price;
};

bool FmncQBilAPos::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQBilAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefFmncMFabuser", "fus", stubX1RefFmncMFabuser);
		extractStringUclc(docctx, basexpath, "stubX2RefFmncMTool", "tol", stubX2RefFmncMTool);
		extractDoubleUclc(docctx, basexpath, "Quantity", "qty", Quantity);
		extractStringUclc(docctx, basexpath, "Article", "art", Article);
		extractDoubleUclc(docctx, basexpath, "Unitprice", "upr", Unitprice);
		extractDoubleUclc(docctx, basexpath, "Price", "prc", Price);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQBilAPos
 ******************************************************************************/

ListFmncQBilAPos::ListFmncQBilAPos() {
};

ListFmncQBilAPos::ListFmncQBilAPos(
			const ListFmncQBilAPos& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQBilAPos(*(src.nodes[i]));
};

ListFmncQBilAPos& ListFmncQBilAPos::operator=(
			const ListFmncQBilAPos& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQBilAPos(*(src.nodes[i]));

	return *this;
};

ListFmncQBilAPos::~ListFmncQBilAPos() {
	clear();
};

void ListFmncQBilAPos::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQBilAPos::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQBilAPos* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQBilAPos");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQBilAPos", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQBilAPos(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQBilAPos[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

