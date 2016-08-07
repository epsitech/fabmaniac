/**
  * \file FmncQStpAPar.cpp
  * API code for table TblFmncQStpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQStpAPar.h"

/******************************************************************************
 class FmncQStpAPar
 ******************************************************************************/

FmncQStpAPar::FmncQStpAPar(
			const uint jnum
			, const string x1OsrefFmncKSteppar
			, const string titX1OsrefFmncKSteppar
			, const string srefX2IxVTbl
			, const string titX2IxVTbl
			, const string stubX2Uref
			, const string Val
			, const string Comment
		) {
	this->jnum = jnum;
	this->x1OsrefFmncKSteppar = x1OsrefFmncKSteppar;
	this->titX1OsrefFmncKSteppar = titX1OsrefFmncKSteppar;
	this->srefX2IxVTbl = srefX2IxVTbl;
	this->titX2IxVTbl = titX2IxVTbl;
	this->stubX2Uref = stubX2Uref;
	this->Val = Val;
	this->Comment = Comment;
};

bool FmncQStpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQStpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1OsrefFmncKSteppar", "spa", x1OsrefFmncKSteppar);
		extractStringUclc(docctx, basexpath, "titX1OsrefFmncKSteppar", "spa2", titX1OsrefFmncKSteppar);
		extractStringUclc(docctx, basexpath, "srefX2IxVTbl", "ret", srefX2IxVTbl);
		extractStringUclc(docctx, basexpath, "titX2IxVTbl", "ret2", titX2IxVTbl);
		extractStringUclc(docctx, basexpath, "stubX2Uref", "reu", stubX2Uref);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQStpAPar
 ******************************************************************************/

ListFmncQStpAPar::ListFmncQStpAPar() {
};

ListFmncQStpAPar::ListFmncQStpAPar(
			const ListFmncQStpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpAPar(*(src.nodes[i]));
};

ListFmncQStpAPar& ListFmncQStpAPar::operator=(
			const ListFmncQStpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpAPar(*(src.nodes[i]));

	return *this;
};

ListFmncQStpAPar::~ListFmncQStpAPar() {
	clear();
};

void ListFmncQStpAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQStpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQStpAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQStpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQStpAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQStpAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQStpAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

