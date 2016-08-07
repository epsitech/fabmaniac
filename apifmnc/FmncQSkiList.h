/**
  * \file FmncQSkiList.h
  * API code for table TblFmncQSkiList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSKILIST_H
#define FMNCQSKILIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSkiList
  */
class FmncQSkiList {

public:
	FmncQSkiList(const uint jnum = 0, const string stubRefFmncMOrg = "", const string stubRefFmncMArticle = "", const string Quantity = "", const string osrefFmncKStocklcn = "", const string titOsrefFmncKStocklcn = "", const string ftmExpdate = "");

public:
	uint jnum;
	string stubRefFmncMOrg;
	string stubRefFmncMArticle;
	string Quantity;
	string osrefFmncKStocklcn;
	string titOsrefFmncKStocklcn;
	string ftmExpdate;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSkiList
  */
class ListFmncQSkiList {

public:
	ListFmncQSkiList();
	ListFmncQSkiList(const ListFmncQSkiList& src);
	ListFmncQSkiList& operator=(const ListFmncQSkiList& src);
	~ListFmncQSkiList();

	void clear();

public:
	vector<FmncQSkiList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

