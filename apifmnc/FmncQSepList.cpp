/**
  * \file FmncQSepList.cpp
  * API code for table TblFmncQSepList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSepList.h"

/******************************************************************************
 class FmncQSepList
 ******************************************************************************/

FmncQSepList::FmncQSepList(
			const uint jnum
			, const string Title
			, const string stubRefFmncMActivity
			, const string srefRlvIxVTbl
			, const string titRlvIxVTbl
			, const string stubRlvUref
			, const string stubTplRefFmncMStep
			, const string ftmStart
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->stubRefFmncMActivity = stubRefFmncMActivity;
	this->srefRlvIxVTbl = srefRlvIxVTbl;
	this->titRlvIxVTbl = titRlvIxVTbl;
	this->stubRlvUref = stubRlvUref;
	this->stubTplRefFmncMStep = stubTplRefFmncMStep;
	this->ftmStart = ftmStart;
};

bool FmncQSepList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSepList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefFmncMActivity", "act", stubRefFmncMActivity);
		extractStringUclc(docctx, basexpath, "srefRlvIxVTbl", "rlt", srefRlvIxVTbl);
		extractStringUclc(docctx, basexpath, "titRlvIxVTbl", "rlt2", titRlvIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRlvUref", "rlu", stubRlvUref);
		extractStringUclc(docctx, basexpath, "stubTplRefFmncMStep", "stp", stubTplRefFmncMStep);
		extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQSepList
 ******************************************************************************/

ListFmncQSepList::ListFmncQSepList() {
};

ListFmncQSepList::ListFmncQSepList(
			const ListFmncQSepList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepList(*(src.nodes[i]));
};

ListFmncQSepList& ListFmncQSepList::operator=(
			const ListFmncQSepList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepList(*(src.nodes[i]));

	return *this;
};

ListFmncQSepList::~ListFmncQSepList() {
	clear();
};

void ListFmncQSepList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSepList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSepList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSepList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSepList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSepList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSepList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

