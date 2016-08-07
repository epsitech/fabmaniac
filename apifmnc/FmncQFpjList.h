/**
  * \file FmncQFpjList.h
  * API code for table TblFmncQFpjList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFPJLIST_H
#define FMNCQFPJLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFpjList
  */
class FmncQFpjList {

public:
	FmncQFpjList(const uint jnum = 0, const string sref = "", const string Title = "", const string stubRefFmncMFab = "", const string stubBioRefFmncMOrg = "", const string srefIxVState = "", const string titIxVState = "");

public:
	uint jnum;
	string sref;
	string Title;
	string stubRefFmncMFab;
	string stubBioRefFmncMOrg;
	string srefIxVState;
	string titIxVState;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFpjList
  */
class ListFmncQFpjList {

public:
	ListFmncQFpjList();
	ListFmncQFpjList(const ListFmncQFpjList& src);
	ListFmncQFpjList& operator=(const ListFmncQFpjList& src);
	~ListFmncQFpjList();

	void clear();

public:
	vector<FmncQFpjList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

