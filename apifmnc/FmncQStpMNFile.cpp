/**
  * \file FmncQStpMNFile.cpp
  * API code for table TblFmncQStpMNFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQStpMNFile.h"

/******************************************************************************
 class FmncQStpMNFile
 ******************************************************************************/

FmncQStpMNFile::FmncQStpMNFile(
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

bool FmncQStpMNFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQStpMNFile");
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
 class ListFmncQStpMNFile
 ******************************************************************************/

ListFmncQStpMNFile::ListFmncQStpMNFile() {
};

ListFmncQStpMNFile::ListFmncQStpMNFile(
			const ListFmncQStpMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpMNFile(*(src.nodes[i]));
};

ListFmncQStpMNFile& ListFmncQStpMNFile::operator=(
			const ListFmncQStpMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQStpMNFile(*(src.nodes[i]));

	return *this;
};

ListFmncQStpMNFile::~ListFmncQStpMNFile() {
	clear();
};

void ListFmncQStpMNFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQStpMNFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQStpMNFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQStpMNFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQStpMNFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQStpMNFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQStpMNFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

