/**
  * \file FmncQPrsList.h
  * API code for table TblFmncQPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSLIST_H
#define FMNCQPRSLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsList
  */
class FmncQPrsList {

public:
	FmncQPrsList(const uint jnum = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const string stubGrp = "", const string stubOwn = "", const string stubRefFmncMOrg = "", const string stubRefFmncMAddress = "", const string srefIxVSex = "", const string titIxVSex = "", const string Tel = "", const string Eml = "");

public:
	uint jnum;
	string Title;
	string Firstname;
	string Lastname;
	string stubGrp;
	string stubOwn;
	string stubRefFmncMOrg;
	string stubRefFmncMAddress;
	string srefIxVSex;
	string titIxVSex;
	string Tel;
	string Eml;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPrsList
  */
class ListFmncQPrsList {

public:
	ListFmncQPrsList();
	ListFmncQPrsList(const ListFmncQPrsList& src);
	ListFmncQPrsList& operator=(const ListFmncQPrsList& src);
	~ListFmncQPrsList();

	void clear();

public:
	vector<FmncQPrsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

