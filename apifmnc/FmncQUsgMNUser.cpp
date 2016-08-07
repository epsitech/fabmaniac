/**
  * \file FmncQUsgMNUser.cpp
  * API code for table TblFmncQUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsgMNUser.h"

/******************************************************************************
 class FmncQUsgMNUser
 ******************************************************************************/

FmncQUsgMNUser::FmncQUsgMNUser(
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

bool FmncQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQUsgMNUser");
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
 class ListFmncQUsgMNUser
 ******************************************************************************/

ListFmncQUsgMNUser::ListFmncQUsgMNUser() {
};

ListFmncQUsgMNUser::ListFmncQUsgMNUser(
			const ListFmncQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsgMNUser(*(src.nodes[i]));
};

ListFmncQUsgMNUser& ListFmncQUsgMNUser::operator=(
			const ListFmncQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsgMNUser(*(src.nodes[i]));

	return *this;
};

ListFmncQUsgMNUser::~ListFmncQUsgMNUser() {
	clear();
};

void ListFmncQUsgMNUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQUsgMNUser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQUsgMNUser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQUsgMNUser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQUsgMNUser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQUsgMNUser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

