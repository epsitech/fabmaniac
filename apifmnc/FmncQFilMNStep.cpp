/**
  * \file FmncQFilMNStep.cpp
  * API code for table TblFmncQFilMNStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFilMNStep.h"

/******************************************************************************
 class FmncQFilMNStep
 ******************************************************************************/

FmncQFilMNStep::FmncQFilMNStep(
			const uint jnum
			, const string stubMref
			, const string stubsTrefFmncMSample
			, const string srefIxVDir
			, const string titIxVDir
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubsTrefFmncMSample = stubsTrefFmncMSample;
	this->srefIxVDir = srefIxVDir;
	this->titIxVDir = titIxVDir;
};

bool FmncQFilMNStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFilMNStep");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubsTrefFmncMSample", "tsmp", stubsTrefFmncMSample);
		extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir);
		extractStringUclc(docctx, basexpath, "titIxVDir", "dir2", titIxVDir);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFilMNStep
 ******************************************************************************/

ListFmncQFilMNStep::ListFmncQFilMNStep() {
};

ListFmncQFilMNStep::ListFmncQFilMNStep(
			const ListFmncQFilMNStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFilMNStep(*(src.nodes[i]));
};

ListFmncQFilMNStep& ListFmncQFilMNStep::operator=(
			const ListFmncQFilMNStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFilMNStep(*(src.nodes[i]));

	return *this;
};

ListFmncQFilMNStep::~ListFmncQFilMNStep() {
	clear();
};

void ListFmncQFilMNStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFilMNStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFilMNStep* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFilMNStep");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFilMNStep", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFilMNStep(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFilMNStep[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

