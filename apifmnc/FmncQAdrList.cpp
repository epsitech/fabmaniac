/**
  * \file FmncQAdrList.cpp
  * API code for table TblFmncQAdrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQAdrList.h"

/******************************************************************************
 class FmncQAdrList
 ******************************************************************************/

FmncQAdrList::FmncQAdrList(
			const uint jnum
			, const string Address1
			, const string City
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const string stubHkUref
			, const string srefKAdrtype
			, const string titSrefKAdrtype
			, const string Zipcode
			, const string srefKCountry
			, const string titSrefKCountry
		) {
	this->jnum = jnum;
	this->Address1 = Address1;
	this->City = City;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->stubHkUref = stubHkUref;
	this->srefKAdrtype = srefKAdrtype;
	this->titSrefKAdrtype = titSrefKAdrtype;
	this->Zipcode = Zipcode;
	this->srefKCountry = srefKCountry;
	this->titSrefKCountry = titSrefKCountry;
};

bool FmncQAdrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "FmncQAdrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Address1", "ad1", Address1);
		extractStringUclc(docctx, basexpath, "City", "cty", City);
		extractStringUclc(docctx, basexpath, "srefHkIxVTbl", "hkt", srefHkIxVTbl);
		extractStringUclc(docctx, basexpath, "titHkIxVTbl", "hkt2", titHkIxVTbl);
		extractStringUclc(docctx, basexpath, "stubHkUref", "hku", stubHkUref);
		extractStringUclc(docctx, basexpath, "srefKAdrtype", "aty", srefKAdrtype);
		extractStringUclc(docctx, basexpath, "titSrefKAdrtype", "aty2", titSrefKAdrtype);
		extractStringUclc(docctx, basexpath, "Zipcode", "zip", Zipcode);
		extractStringUclc(docctx, basexpath, "srefKCountry", "cry", srefKCountry);
		extractStringUclc(docctx, basexpath, "titSrefKCountry", "cry2", titSrefKCountry);
	};

	return basefound;
};

/******************************************************************************
 class ListFmncQAdrList
 ******************************************************************************/

ListFmncQAdrList::ListFmncQAdrList() {
};

ListFmncQAdrList::ListFmncQAdrList(
			const ListFmncQAdrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQAdrList(*(src.nodes[i]));
};

ListFmncQAdrList& ListFmncQAdrList::operator=(
			const ListFmncQAdrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQAdrList(*(src.nodes[i]));

	return *this;
};

ListFmncQAdrList::~ListFmncQAdrList() {
	clear();
};

void ListFmncQAdrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool ListFmncQAdrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	FmncQAdrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListFmncQAdrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "FmncQAdrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new FmncQAdrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/FmncQAdrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

