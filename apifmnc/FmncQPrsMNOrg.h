/**
  * \file FmncQPrsMNOrg.h
  * API code for table TblFmncQPrsMNOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSMNORG_H
#define FMNCQPRSMNORG_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsMNOrg
  */
class FmncQPrsMNOrg {

public:
	FmncQPrsMNOrg(const uint jnum = 0, const string stubMref = "", const string ftmX1Startd = "", const string ftmX1Stopd = "", const string srefKFunction = "", const string titSrefKFunction = "");

public:
	uint jnum;
	string stubMref;
	string ftmX1Startd;
	string ftmX1Stopd;
	string srefKFunction;
	string titSrefKFunction;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPrsMNOrg
  */
class ListFmncQPrsMNOrg {

public:
	ListFmncQPrsMNOrg();
	ListFmncQPrsMNOrg(const ListFmncQPrsMNOrg& src);
	ListFmncQPrsMNOrg& operator=(const ListFmncQPrsMNOrg& src);
	~ListFmncQPrsMNOrg();

	void clear();

public:
	vector<FmncQPrsMNOrg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

