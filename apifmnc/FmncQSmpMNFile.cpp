/**
  * \file FmncQSmpMNFile.cpp
  * API code for table TblFmncQSmpMNFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSmpMNFile.h"

/******************************************************************************
 class FmncQSmpMNFile
 ******************************************************************************/

FmncQSmpMNFile::FmncQSmpMNFile(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool FmncQSmpMNFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSmpMNFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQSmpMNFile
 ******************************************************************************/

ListFmncQSmpMNFile::ListFmncQSmpMNFile() {
};

ListFmncQSmpMNFile::ListFmncQSmpMNFile(
			const ListFmncQSmpMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpMNFile(*(src.nodes[i]));
};

ListFmncQSmpMNFile& ListFmncQSmpMNFile::operator=(
			const ListFmncQSmpMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSmpMNFile(*(src.nodes[i]));

	return *this;
};

ListFmncQSmpMNFile::~ListFmncQSmpMNFile() {
	clear();
};

void ListFmncQSmpMNFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSmpMNFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSmpMNFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSmpMNFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSmpMNFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSmpMNFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSmpMNFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

