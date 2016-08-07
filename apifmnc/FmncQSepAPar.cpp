/**
  * \file FmncQSepAPar.cpp
  * API code for table TblFmncQSepAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSepAPar.h"

/******************************************************************************
 class FmncQSepAPar
 ******************************************************************************/

FmncQSepAPar::FmncQSepAPar(
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

bool FmncQSepAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSepAPar");
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
 class ListFmncQSepAPar
 ******************************************************************************/

ListFmncQSepAPar::ListFmncQSepAPar() {
};

ListFmncQSepAPar::ListFmncQSepAPar(
			const ListFmncQSepAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepAPar(*(src.nodes[i]));
};

ListFmncQSepAPar& ListFmncQSepAPar::operator=(
			const ListFmncQSepAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepAPar(*(src.nodes[i]));

	return *this;
};

ListFmncQSepAPar::~ListFmncQSepAPar() {
	clear();
};

void ListFmncQSepAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSepAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSepAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSepAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSepAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSepAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSepAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

