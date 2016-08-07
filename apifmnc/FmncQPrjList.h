/**
  * \file FmncQPrjList.h
  * API code for table TblFmncQPrjList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRJLIST_H
#define FMNCQPRJLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrjList
  */
class FmncQPrjList {

public:
	FmncQPrjList(const uint jnum = 0, const string Title = "", const string srefIxVState = "", const string titIxVState = "");

public:
	uint jnum;
	string Title;
	string srefIxVState;
	string titIxVState;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPrjList
  */
class ListFmncQPrjList {

public:
	ListFmncQPrjList();
	ListFmncQPrjList(const ListFmncQPrjList& src);
	ListFmncQPrjList& operator=(const ListFmncQPrjList& src);
	~ListFmncQPrjList();

	void clear();

public:
	vector<FmncQPrjList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

