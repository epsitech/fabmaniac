/**
  * \file FmncQTolAUtil.cpp
  * API code for table TblFmncQTolAUtil (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQTolAUtil.h"

/******************************************************************************
 class FmncQTolAUtil
 ******************************************************************************/

FmncQTolAUtil::FmncQTolAUtil(
			const uint jnum
			, const string stubX1RefFmncMFabproject
			, const string stubX2RefFmncMFabuser
			, const string ftmStartd
			, const string ftmStartt
			, const string ftmStopt
			, const double Unitprice
			, const string Comment
		) {
	this->jnum = jnum;
	this->stubX1RefFmncMFabproject = stubX1RefFmncMFabproject;
	this->stubX2RefFmncMFabuser = stubX2RefFmncMFabuser;
	this->ftmStartd = ftmStartd;
	this->ftmStartt = ftmStartt;
	this->ftmStopt = ftmStopt;
	this->Unitprice = Unitprice;
	this->Comment = Comment;
};

bool FmncQTolAUtil::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQTolAUtil");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefFmncMFabproject", "fpj", stubX1RefFmncMFabproject);
		extractStringUclc(docctx, basexpath, "stubX2RefFmncMFabuser", "fus", stubX2RefFmncMFabuser);
		extractStringUclc(docctx, basexpath, "ftmStartd", "dat", ftmStartd);
		extractStringUclc(docctx, basexpath, "ftmStartt", "sta", ftmStartt);
		extractStringUclc(docctx, basexpath, "ftmStopt", "sto", ftmStopt);
		extractDoubleUclc(docctx, basexpath, "Unitprice", "upr", Unitprice);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQTolAUtil
 ******************************************************************************/

ListFmncQTolAUtil::ListFmncQTolAUtil() {
};

ListFmncQTolAUtil::ListFmncQTolAUtil(
			const ListFmncQTolAUtil& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAUtil(*(src.nodes[i]));
};

ListFmncQTolAUtil& ListFmncQTolAUtil::operator=(
			const ListFmncQTolAUtil& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQTolAUtil(*(src.nodes[i]));

	return *this;
};

ListFmncQTolAUtil::~ListFmncQTolAUtil() {
	clear();
};

void ListFmncQTolAUtil::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQTolAUtil::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQTolAUtil* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQTolAUtil");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQTolAUtil", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQTolAUtil(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQTolAUtil[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

