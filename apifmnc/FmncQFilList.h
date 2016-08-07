/**
  * \file FmncQFilList.h
  * API code for table TblFmncQFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFILLIST_H
#define FMNCQFILLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFilList
  */
class FmncQFilList {

public:
	FmncQFilList(const uint jnum = 0, const string Filename = "", const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);

public:
	uint jnum;
	string Filename;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	string stubRefUref;
	string osrefKContent;
	string titOsrefKContent;
	string srefKMimetype;
	string titSrefKMimetype;
	usmallint Size;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFilList
  */
class ListFmncQFilList {

public:
	ListFmncQFilList();
	ListFmncQFilList(const ListFmncQFilList& src);
	ListFmncQFilList& operator=(const ListFmncQFilList& src);
	~ListFmncQFilList();

	void clear();

public:
	vector<FmncQFilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

