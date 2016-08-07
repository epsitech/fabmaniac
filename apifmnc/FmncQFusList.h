/**
  * \file FmncQFusList.h
  * API code for table TblFmncQFusList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFUSLIST_H
#define FMNCQFUSLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFusList
  */
class FmncQFusList {

public:
	FmncQFusList(const uint jnum = 0, const string stubRefFmncMPerson = "", const string sref = "", const string stubRefFmncMFab = "", const string stubRefFmncMFabproject = "", const string srefIxVState = "", const string titIxVState = "");

public:
	uint jnum;
	string stubRefFmncMPerson;
	string sref;
	string stubRefFmncMFab;
	string stubRefFmncMFabproject;
	string srefIxVState;
	string titIxVState;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFusList
  */
class ListFmncQFusList {

public:
	ListFmncQFusList();
	ListFmncQFusList(const ListFmncQFusList& src);
	ListFmncQFusList& operator=(const ListFmncQFusList& src);
	~ListFmncQFusList();

	void clear();

public:
	vector<FmncQFusList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

