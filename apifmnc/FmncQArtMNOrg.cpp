/**
  * \file FmncQArtMNOrg.cpp
  * API code for table TblFmncQArtMNOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQArtMNOrg.h"

/******************************************************************************
 class FmncQArtMNOrg
 ******************************************************************************/

FmncQArtMNOrg::FmncQArtMNOrg(
			const uint jnum
			, const string stubMref
			, const string Itemno
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->Itemno = Itemno;
};

bool FmncQArtMNOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQArtMNOrg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "Itemno", "itn", Itemno);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQArtMNOrg
 ******************************************************************************/

ListFmncQArtMNOrg::ListFmncQArtMNOrg() {
};

ListFmncQArtMNOrg::ListFmncQArtMNOrg(
			const ListFmncQArtMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArtMNOrg(*(src.nodes[i]));
};

ListFmncQArtMNOrg& ListFmncQArtMNOrg::operator=(
			const ListFmncQArtMNOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQArtMNOrg(*(src.nodes[i]));

	return *this;
};

ListFmncQArtMNOrg::~ListFmncQArtMNOrg() {
	clear();
};

void ListFmncQArtMNOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQArtMNOrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQArtMNOrg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQArtMNOrg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQArtMNOrg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQArtMNOrg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQArtMNOrg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

