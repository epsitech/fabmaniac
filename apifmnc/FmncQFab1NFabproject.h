/**
  * \file FmncQFab1NFabproject.h
  * API code for table TblFmncQFab1NFabproject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFAB1NFABPROJECT_H
#define FMNCQFAB1NFABPROJECT_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFab1NFabproject
  */
class FmncQFab1NFabproject {

public:
	FmncQFab1NFabproject(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFab1NFabproject
  */
class ListFmncQFab1NFabproject {

public:
	ListFmncQFab1NFabproject();
	ListFmncQFab1NFabproject(const ListFmncQFab1NFabproject& src);
	ListFmncQFab1NFabproject& operator=(const ListFmncQFab1NFabproject& src);
	~ListFmncQFab1NFabproject();

	void clear();

public:
	vector<FmncQFab1NFabproject*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

