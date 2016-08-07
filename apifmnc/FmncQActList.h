/**
  * \file FmncQActList.h
  * API code for table TblFmncQActList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQACTLIST_H
#define FMNCQACTLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQActList
  */
class FmncQActList {

public:
	FmncQActList(const uint jnum = 0, const string Title = "", const string stubRunRefFmncMRun = "");

public:
	uint jnum;
	string Title;
	string stubRunRefFmncMRun;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQActList
  */
class ListFmncQActList {

public:
	ListFmncQActList();
	ListFmncQActList(const ListFmncQActList& src);
	ListFmncQActList& operator=(const ListFmncQActList& src);
	~ListFmncQActList();

	void clear();

public:
	vector<FmncQActList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

