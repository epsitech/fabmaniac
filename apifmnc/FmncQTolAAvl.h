/**
  * \file FmncQTolAAvl.h
  * API code for table TblFmncQTolAAvl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLAAVL_H
#define FMNCQTOLAAVL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolAAvl
  */
class FmncQTolAAvl {

public:
	FmncQTolAAvl(const uint jnum = 0, const string ftmX1Startd = "", const string srefX2IxVWkday = "", const string ftmX3Startt = "", const string ftmX3Stopt = "", const string srefKAvltype = "", const string titSrefKAvltype = "");

public:
	uint jnum;
	string ftmX1Startd;
	string srefX2IxVWkday;
	string ftmX3Startt;
	string ftmX3Stopt;
	string srefKAvltype;
	string titSrefKAvltype;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolAAvl
  */
class ListFmncQTolAAvl {

public:
	ListFmncQTolAAvl();
	ListFmncQTolAAvl(const ListFmncQTolAAvl& src);
	ListFmncQTolAAvl& operator=(const ListFmncQTolAAvl& src);
	~ListFmncQTolAAvl();

	void clear();

public:
	vector<FmncQTolAAvl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

