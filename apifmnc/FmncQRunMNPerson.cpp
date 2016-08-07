/**
  * \file FmncQRunMNPerson.cpp
  * API code for table TblFmncQRunMNPerson (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQRunMNPerson.h"

/******************************************************************************
 class FmncQRunMNPerson
 ******************************************************************************/

FmncQRunMNPerson::FmncQRunMNPerson(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool FmncQRunMNPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQRunMNPerson");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQRunMNPerson
 ******************************************************************************/

ListFmncQRunMNPerson::ListFmncQRunMNPerson() {
};

ListFmncQRunMNPerson::ListFmncQRunMNPerson(
			const ListFmncQRunMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunMNPerson(*(src.nodes[i]));
};

ListFmncQRunMNPerson& ListFmncQRunMNPerson::operator=(
			const ListFmncQRunMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQRunMNPerson(*(src.nodes[i]));

	return *this;
};

ListFmncQRunMNPerson::~ListFmncQRunMNPerson() {
	clear();
};

void ListFmncQRunMNPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQRunMNPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQRunMNPerson* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQRunMNPerson");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQRunMNPerson", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQRunMNPerson(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQRunMNPerson[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

