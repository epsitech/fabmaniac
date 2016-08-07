/**
  * \file FmncQFab1NFabuser.h
  * API code for table TblFmncQFab1NFabuser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFAB1NFABUSER_H
#define FMNCQFAB1NFABUSER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFab1NFabuser
  */
class FmncQFab1NFabuser {

public:
	FmncQFab1NFabuser(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFab1NFabuser
  */
class ListFmncQFab1NFabuser {

public:
	ListFmncQFab1NFabuser();
	ListFmncQFab1NFabuser(const ListFmncQFab1NFabuser& src);
	ListFmncQFab1NFabuser& operator=(const ListFmncQFab1NFabuser& src);
	~ListFmncQFab1NFabuser();

	void clear();

public:
	vector<FmncQFab1NFabuser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

