/**
  * \file FmncQUsrList.cpp
  * API code for table TblFmncQUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsrList.h"

/******************************************************************************
 class FmncQUsrList
 ******************************************************************************/

FmncQUsrList::FmncQUsrList(
			const uint jnum
			, const string stubRefFmncMPerson
			, const string sref
			, const string stubRefFmncMUsergroup
			, const string srefIxVState
			, const string titIxVState
			, const string srefIxFmncVLocale
			, const string titIxFmncVLocale
			, const string srefIxFmncVUserlevel
			, const string titIxFmncVUserlevel
		) {
	this->jnum = jnum;
	this->stubRefFmncMPerson = stubRefFmncMPerson;
	this->sref = sref;
	this->stubRefFmncMUsergroup = stubRefFmncMUsergroup;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->srefIxFmncVLocale = srefIxFmncVLocale;
	this->titIxFmncVLocale = titIxFmncVLocale;
	this->srefIxFmncVUserlevel = srefIxFmncVUserlevel;
	this->titIxFmncVUserlevel = titIxFmncVUserlevel;
};

bool FmncQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefFmncMPerson", "prs", stubRefFmncMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefFmncMUsergroup", "usg", stubRefFmncMUsergroup);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefIxFmncVLocale", "lcl", srefIxFmncVLocale);
		extractStringUclc(docctx, basexpath, "titIxFmncVLocale", "lcl2", titIxFmncVLocale);
		extractStringUclc(docctx, basexpath, "srefIxFmncVUserlevel", "ulv", srefIxFmncVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxFmncVUserlevel", "ulv2", titIxFmncVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQUsrList
 ******************************************************************************/

ListFmncQUsrList::ListFmncQUsrList() {
};

ListFmncQUsrList::ListFmncQUsrList(
			const ListFmncQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsrList(*(src.nodes[i]));
};

ListFmncQUsrList& ListFmncQUsrList::operator=(
			const ListFmncQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsrList(*(src.nodes[i]));

	return *this;
};

ListFmncQUsrList::~ListFmncQUsrList() {
	clear();
};

void ListFmncQUsrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQUsrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQUsrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQUsrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQUsrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

