/**
  * \file FmncQRunList.h
  * API code for table TblFmncQRunList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNLIST_H
#define FMNCQRUNLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunList
  */
class FmncQRunList {

public:
	FmncQRunList(const uint jnum = 0, const string Title = "", const string stubRefFmncMProject = "", const string srefIxVState = "", const string titIxVState = "");

public:
	uint jnum;
	string Title;
	string stubRefFmncMProject;
	string srefIxVState;
	string titIxVState;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQRunList
  */
class ListFmncQRunList {

public:
	ListFmncQRunList();
	ListFmncQRunList(const ListFmncQRunList& src);
	ListFmncQRunList& operator=(const ListFmncQRunList& src);
	~ListFmncQRunList();

	void clear();

public:
	vector<FmncQRunList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

