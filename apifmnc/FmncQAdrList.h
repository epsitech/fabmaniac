/**
  * \file FmncQAdrList.h
  * API code for table TblFmncQAdrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQADRLIST_H
#define FMNCQADRLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQAdrList
  */
class FmncQAdrList {

public:
	FmncQAdrList(const uint jnum = 0, const string Address1 = "", const string City = "", const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const string stubHkUref = "", const string srefKAdrtype = "", const string titSrefKAdrtype = "", const string Zipcode = "", const string srefKCountry = "", const string titSrefKCountry = "");

public:
	uint jnum;
	string Address1;
	string City;
	string srefHkIxVTbl;
	string titHkIxVTbl;
	string stubHkUref;
	string srefKAdrtype;
	string titSrefKAdrtype;
	string Zipcode;
	string srefKCountry;
	string titSrefKCountry;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQAdrList
  */
class ListFmncQAdrList {

public:
	ListFmncQAdrList();
	ListFmncQAdrList(const ListFmncQAdrList& src);
	ListFmncQAdrList& operator=(const ListFmncQAdrList& src);
	~ListFmncQAdrList();

	void clear();

public:
	vector<FmncQAdrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

