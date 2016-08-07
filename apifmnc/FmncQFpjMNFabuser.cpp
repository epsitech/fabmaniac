/**
  * \file FmncQFpjMNFabuser.cpp
  * API code for table TblFmncQFpjMNFabuser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQFpjMNFabuser.h"

/******************************************************************************
 class FmncQFpjMNFabuser
 ******************************************************************************/

FmncQFpjMNFabuser::FmncQFpjMNFabuser(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool FmncQFpjMNFabuser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQFpjMNFabuser");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQFpjMNFabuser
 ******************************************************************************/

ListFmncQFpjMNFabuser::ListFmncQFpjMNFabuser() {
};

ListFmncQFpjMNFabuser::ListFmncQFpjMNFabuser(
			const ListFmncQFpjMNFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFpjMNFabuser(*(src.nodes[i]));
};

ListFmncQFpjMNFabuser& ListFmncQFpjMNFabuser::operator=(
			const ListFmncQFpjMNFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQFpjMNFabuser(*(src.nodes[i]));

	return *this;
};

ListFmncQFpjMNFabuser::~ListFmncQFpjMNFabuser() {
	clear();
};

void ListFmncQFpjMNFabuser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQFpjMNFabuser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQFpjMNFabuser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQFpjMNFabuser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQFpjMNFabuser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQFpjMNFabuser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQFpjMNFabuser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

