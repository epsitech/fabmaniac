/**
  * \file FmncQUsgList.h
  * API code for table TblFmncQUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSGLIST_H
#define FMNCQUSGLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsgList
  */
class FmncQUsgList {

public:
	FmncQUsgList(const uint jnum = 0, const string sref = "");

public:
	uint jnum;
	string sref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQUsgList
  */
class ListFmncQUsgList {

public:
	ListFmncQUsgList();
	ListFmncQUsgList(const ListFmncQUsgList& src);
	ListFmncQUsgList& operator=(const ListFmncQUsgList& src);
	~ListFmncQUsgList();

	void clear();

public:
	vector<FmncQUsgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

