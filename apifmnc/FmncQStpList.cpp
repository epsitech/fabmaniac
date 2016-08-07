/**
  * \file FmncQStpList.cpp
  * API code for table TblFmncQStpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQStpList.h"

/******************************************************************************
 class FmncQStpList
 ******************************************************************************/

FmncQStpList::FmncQStpList(
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

bool FmncQStpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQStpList");
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
 class ListFmncQStpList
 ******************************************************************************/

ListFmncQStpList::ListFmncQStpList() {
};

ListFmncQStpList::ListFmncQStpList(
			const ListFmncQStpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpList(*(src.nodes[i]));
};

ListFmncQStpList& ListFmncQStpList::operator=(
			const ListFmncQStpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpList(*(src.nodes[i]));

	return *this;
};

ListFmncQStpList::~ListFmncQStpList() {
	clear();
};

void ListFmncQStpList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQStpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQStpList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQStpList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQStpList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQStpList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQStpList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

