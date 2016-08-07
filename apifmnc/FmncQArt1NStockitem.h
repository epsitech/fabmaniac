/**
  * \file FmncQArt1NStockitem.h
  * API code for table TblFmncQArt1NStockitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQART1NSTOCKITEM_H
#define FMNCQART1NSTOCKITEM_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArt1NStockitem
  */
class FmncQArt1NStockitem {

public:
	FmncQArt1NStockitem(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQArt1NStockitem
  */
class ListFmncQArt1NStockitem {

public:
	ListFmncQArt1NStockitem();
	ListFmncQArt1NStockitem(const ListFmncQArt1NStockitem& src);
	ListFmncQArt1NStockitem& operator=(const ListFmncQArt1NStockitem& src);
	~ListFmncQArt1NStockitem();

	void clear();

public:
	vector<FmncQArt1NStockitem*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

