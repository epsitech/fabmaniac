/**
  * \file FmncQTolAChar.cpp
  * API code for table TblFmncQTolAChar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolAChar.h"

/******************************************************************************
 class FmncQTolAChar
 ******************************************************************************/

FmncQTolAChar::FmncQTolAChar(
			const uint jnum
			, const string x1OsrefFmncKToolchar
			, const string titX1OsrefFmncKToolchar
			, const string Val
			, const string Comment
		) {
	this->jnum = jnum;
	this->x1OsrefFmncKToolchar = x1OsrefFmncKToolchar;
	this->titX1OsrefFmncKToolchar = titX1OsrefFmncKToolchar;
	this->Val = Val;
	this->Comment = Comment;
};

bool FmncQTolAChar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolAChar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1OsrefFmncKToolchar", "tch", x1OsrefFmncKToolchar);
		extractStringUclc(docctx, basexpath, "titX1OsrefFmncKToolchar", "tch2", titX1OsrefFmncKToolchar);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTolAChar
 ******************************************************************************/

ListFmncQTolAChar::ListFmncQTolAChar() {
};

ListFmncQTolAChar::ListFmncQTolAChar(
			const ListFmncQTolAChar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAChar(*(src.nodes[i]));
};

ListFmncQTolAChar& ListFmncQTolAChar::operator=(
			const ListFmncQTolAChar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAChar(*(src.nodes[i]));

	return *this;
};

ListFmncQTolAChar::~ListFmncQTolAChar() {
	clear();
};

void ListFmncQTolAChar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolAChar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolAChar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolAChar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolAChar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolAChar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolAChar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

