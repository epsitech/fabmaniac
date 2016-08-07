/**
  * \file FmncQSepMNFile.cpp
  * API code for table TblFmncQSepMNFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQSepMNFile.h"

/******************************************************************************
 class FmncQSepMNFile
 ******************************************************************************/

FmncQSepMNFile::FmncQSepMNFile(
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

bool FmncQSepMNFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQSepMNFile");
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
 class ListFmncQSepMNFile
 ******************************************************************************/

ListFmncQSepMNFile::ListFmncQSepMNFile() {
};

ListFmncQSepMNFile::ListFmncQSepMNFile(
			const ListFmncQSepMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepMNFile(*(src.nodes[i]));
};

ListFmncQSepMNFile& ListFmncQSepMNFile::operator=(
			const ListFmncQSepMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQSepMNFile(*(src.nodes[i]));

	return *this;
};

ListFmncQSepMNFile::~ListFmncQSepMNFile() {
	clear();
};

void ListFmncQSepMNFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQSepMNFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQSepMNFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQSepMNFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQSepMNFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQSepMNFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQSepMNFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

