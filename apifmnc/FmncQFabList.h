/**
  * \file FmncQFabList.h
  * API code for table TblFmncQFabList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFABLIST_H
#define FMNCQFABLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFabList
  */
class FmncQFabList {

public:
	FmncQFabList(const uint jnum = 0, const string stubRefFmncMOrg = "");

public:
	uint jnum;
	string stubRefFmncMOrg;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFabList
  */
class ListFmncQFabList {

public:
	ListFmncQFabList();
	ListFmncQFabList(const ListFmncQFabList& src);
	ListFmncQFabList& operator=(const ListFmncQFabList& src);
	~ListFmncQFabList();

	void clear();

public:
	vector<FmncQFabList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

