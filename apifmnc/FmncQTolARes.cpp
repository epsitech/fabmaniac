/**
  * \file FmncQTolARes.cpp
  * API code for table TblFmncQTolARes (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolARes.h"

/******************************************************************************
 class FmncQTolARes
 ******************************************************************************/

FmncQTolARes::FmncQTolARes(
			const uint jnum
			, const string stubX1RefFmncMFabuser
			, const string ftmStartd
			, const string ftmStartt
			, const string ftmStopt
			, const string srefKRestype
			, const string titSrefKRestype
			, const string Comment
		) {
	this->jnum = jnum;
	this->stubX1RefFmncMFabuser = stubX1RefFmncMFabuser;
	this->ftmStartd = ftmStartd;
	this->ftmStartt = ftmStartt;
	this->ftmStopt = ftmStopt;
	this->srefKRestype = srefKRestype;
	this->titSrefKRestype = titSrefKRestype;
	this->Comment = Comment;
};

bool FmncQTolARes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolARes");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefFmncMFabuser", "fus", stubX1RefFmncMFabuser);
		extractStringUclc(docctx, basexpath, "ftmStartd", "dat", ftmStartd);
		extractStringUclc(docctx, basexpath, "ftmStartt", "sta", ftmStartt);
		extractStringUclc(docctx, basexpath, "ftmStopt", "sto", ftmStopt);
		extractStringUclc(docctx, basexpath, "srefKRestype", "rty", srefKRestype);
		extractStringUclc(docctx, basexpath, "titSrefKRestype", "rty2", titSrefKRestype);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTolARes
 ******************************************************************************/

ListFmncQTolARes::ListFmncQTolARes() {
};

ListFmncQTolARes::ListFmncQTolARes(
			const ListFmncQTolARes& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolARes(*(src.nodes[i]));
};

ListFmncQTolARes& ListFmncQTolARes::operator=(
			const ListFmncQTolARes& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolARes(*(src.nodes[i]));

	return *this;
};

ListFmncQTolARes::~ListFmncQTolARes() {
	clear();
};

void ListFmncQTolARes::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolARes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolARes* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolARes");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolARes", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolARes(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolARes[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

