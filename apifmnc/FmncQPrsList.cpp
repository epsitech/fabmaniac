/**
  * \file FmncQPrsList.cpp
  * API code for table TblFmncQPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPrsList.h"

/******************************************************************************
 class FmncQPrsList
 ******************************************************************************/

FmncQPrsList::FmncQPrsList(
			const uint jnum
			, const string Title
			, const string Firstname
			, const string Lastname
			, const string stubGrp
			, const string stubOwn
			, const string stubRefFmncMOrg
			, const string stubRefFmncMAddress
			, const string srefIxVSex
			, const string titIxVSex
			, const string Tel
			, const string Eml
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->stubRefFmncMOrg = stubRefFmncMOrg;
	this->stubRefFmncMAddress = stubRefFmncMAddress;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->Tel = Tel;
	this->Eml = Eml;
};

bool FmncQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname);
		extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname);
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "stubRefFmncMOrg", "org", stubRefFmncMOrg);
		extractStringUclc(docctx, basexpath, "stubRefFmncMAddress", "adr", stubRefFmncMAddress);
		extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex);
		extractStringUclc(docctx, basexpath, "titIxVSex", "sex2", titIxVSex);
		extractStringUclc(docctx, basexpath, "Tel", "tel", Tel);
		extractStringUclc(docctx, basexpath, "Eml", "eml", Eml);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQPrsList
 ******************************************************************************/

ListFmncQPrsList::ListFmncQPrsList() {
};

ListFmncQPrsList::ListFmncQPrsList(
			const ListFmncQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsList(*(src.nodes[i]));
};

ListFmncQPrsList& ListFmncQPrsList::operator=(
			const ListFmncQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPrsList(*(src.nodes[i]));

	return *this;
};

ListFmncQPrsList::~ListFmncQPrsList() {
	clear();
};

void ListFmncQPrsList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQPrsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQPrsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQPrsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQPrsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

