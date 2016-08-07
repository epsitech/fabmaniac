/**
  * \file FmncQUsgAAccess.cpp
  * API code for table TblFmncQUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQUsgAAccess.h"

/******************************************************************************
 class FmncQUsgAAccess
 ******************************************************************************/

FmncQUsgAAccess::FmncQUsgAAccess(
			const uint jnum
			, const string srefX1IxFmncVCard
			, const string titX1IxFmncVCard
			, const string srefsIxFmncWUiaccess
			, const string titsIxFmncWUiaccess
		) {
	this->jnum = jnum;
	this->srefX1IxFmncVCard = srefX1IxFmncVCard;
	this->titX1IxFmncVCard = titX1IxFmncVCard;
	this->srefsIxFmncWUiaccess = srefsIxFmncWUiaccess;
	this->titsIxFmncWUiaccess = titsIxFmncWUiaccess;
};

bool FmncQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxFmncVCard", "crd", srefX1IxFmncVCard);
		extractStringUclc(docctx, basexpath, "titX1IxFmncVCard", "crd2", titX1IxFmncVCard);
		extractStringUclc(docctx, basexpath, "srefsIxFmncWUiaccess", "uac", srefsIxFmncWUiaccess);
		extractStringUclc(docctx, basexpath, "titsIxFmncWUiaccess", "uac2", titsIxFmncWUiaccess);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQUsgAAccess
 ******************************************************************************/

ListFmncQUsgAAccess::ListFmncQUsgAAccess() {
};

ListFmncQUsgAAccess::ListFmncQUsgAAccess(
			const ListFmncQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsgAAccess(*(src.nodes[i]));
};

ListFmncQUsgAAccess& ListFmncQUsgAAccess::operator=(
			const ListFmncQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQUsgAAccess(*(src.nodes[i]));

	return *this;
};

ListFmncQUsgAAccess::~ListFmncQUsgAAccess() {
	clear();
};

void ListFmncQUsgAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQUsgAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQUsgAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQUsgAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQUsgAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

