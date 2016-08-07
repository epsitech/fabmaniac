/**
  * \file FmncQOrg1NStockitem.h
  * API code for table TblFmncQOrg1NStockitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORG1NSTOCKITEM_H
#define FMNCQORG1NSTOCKITEM_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrg1NStockitem
  */
class FmncQOrg1NStockitem {

public:
	FmncQOrg1NStockitem(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrg1NStockitem
  */
class ListFmncQOrg1NStockitem {

public:
	ListFmncQOrg1NStockitem();
	ListFmncQOrg1NStockitem(const ListFmncQOrg1NStockitem& src);
	ListFmncQOrg1NStockitem& operator=(const ListFmncQOrg1NStockitem& src);
	~ListFmncQOrg1NStockitem();

	void clear();

public:
	vector<FmncQOrg1NStockitem*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

