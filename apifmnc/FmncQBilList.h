/**
  * \file FmncQBilList.h
  * API code for table TblFmncQBilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQBILLIST_H
#define FMNCQBILLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQBilList
  */
class FmncQBilList {

public:
	FmncQBilList(const uint jnum = 0, const string sref = "", const string ftmDate = "", const string stubRefFmncMFabproject = "", const string stubRefFmncMFile = "", const string srefIxVState = "", const string titIxVState = "", const string ftmPrdstart = "", const string ftmPrdstop = "", const double Amount = 0.0);

public:
	uint jnum;
	string sref;
	string ftmDate;
	string stubRefFmncMFabproject;
	string stubRefFmncMFile;
	string srefIxVState;
	string titIxVState;
	string ftmPrdstart;
	string ftmPrdstop;
	double Amount;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQBilList
  */
class ListFmncQBilList {

public:
	ListFmncQBilList();
	ListFmncQBilList(const ListFmncQBilList& src);
	ListFmncQBilList& operator=(const ListFmncQBilList& src);
	~ListFmncQBilList();

	void clear();

public:
	vector<FmncQBilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

