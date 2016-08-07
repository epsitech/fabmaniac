/**
  * \file FmncQUsrMNUsergroup.cpp
  * API code for table TblFmncQUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsrMNUsergroup.h"

/******************************************************************************
 class FmncQUsrMNUsergroup
 ******************************************************************************/

FmncQUsrMNUsergroup::FmncQUsrMNUsergroup(
			const uint jnum
			, const string stubMref
			, const string srefIxFmncVUserlevel
			, const string titIxFmncVUserlevel
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxFmncVUserlevel = srefIxFmncVUserlevel;
	this->titIxFmncVUserlevel = titIxFmncVUserlevel;
};

bool FmncQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxFmncVUserlevel", "ulv", srefIxFmncVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxFmncVUserlevel", "ulv2", titIxFmncVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQUsrMNUsergroup
 ******************************************************************************/

ListFmncQUsrMNUsergroup::ListFmncQUsrMNUsergroup() {
};

ListFmncQUsrMNUsergroup::ListFmncQUsrMNUsergroup(
			const ListFmncQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsrMNUsergroup(*(src.nodes[i]));
};

ListFmncQUsrMNUsergroup& ListFmncQUsrMNUsergroup::operator=(
			const ListFmncQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsrMNUsergroup(*(src.nodes[i]));

	return *this;
};

ListFmncQUsrMNUsergroup::~ListFmncQUsrMNUsergroup() {
	clear();
};

void ListFmncQUsrMNUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQUsrMNUsergroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQUsrMNUsergroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQUsrMNUsergroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQUsrMNUsergroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

