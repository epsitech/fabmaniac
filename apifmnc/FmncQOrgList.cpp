/**
  * \file FmncQOrgList.cpp
  * API code for table TblFmncQOrgList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQOrgList.h"

/******************************************************************************
 class FmncQOrgList
 ******************************************************************************/

FmncQOrgList::FmncQOrgList(
			const uint jnum
			, const string sref
			, const string Title
			, const string srefsIxWDerivate
			, const string titsIxWDerivate
			, const string stubRefFmncMAddress
			, const string stubSupRefFmncMOrg
			, const string Tel
			, const string Eml
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->srefsIxWDerivate = srefsIxWDerivate;
	this->titsIxWDerivate = titsIxWDerivate;
	this->stubRefFmncMAddress = stubRefFmncMAddress;
	this->stubSupRefFmncMOrg = stubSupRefFmncMOrg;
	this->Tel = Tel;
	this->Eml = Eml;
};

bool FmncQOrgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQOrgList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefsIxWDerivate", "drv", srefsIxWDerivate);
		extractStringUclc(docctx, basexpath, "titsIxWDerivate", "drv2", titsIxWDerivate);
		extractStringUclc(docctx, basexpath, "stubRefFmncMAddress", "adr", stubRefFmncMAddress);
		extractStringUclc(docctx, basexpath, "stubSupRefFmncMOrg", "sup", stubSupRefFmncMOrg);
		extractStringUclc(docctx, basexpath, "Tel", "tel", Tel);
		extractStringUclc(docctx, basexpath, "Eml", "eml", Eml);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQOrgList
 ******************************************************************************/

ListFmncQOrgList::ListFmncQOrgList() {
};

ListFmncQOrgList::ListFmncQOrgList(
			const ListFmncQOrgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgList(*(src.nodes[i]));
};

ListFmncQOrgList& ListFmncQOrgList::operator=(
			const ListFmncQOrgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQOrgList(*(src.nodes[i]));

	return *this;
};

ListFmncQOrgList::~ListFmncQOrgList() {
	clear();
};

void ListFmncQOrgList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQOrgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQOrgList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQOrgList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQOrgList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQOrgList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQOrgList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

