/**
  * \file FmncQRunMNFab.h
  * API code for table TblFmncQRunMNFab (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNMNFAB_H
#define FMNCQRUNMNFAB_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunMNFab
  */
class FmncQRunMNFab {

public:
	FmncQRunMNFab(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQRunMNFab
  */
class ListFmncQRunMNFab {

public:
	ListFmncQRunMNFab();
	ListFmncQRunMNFab(const ListFmncQRunMNFab& src);
	ListFmncQRunMNFab& operator=(const ListFmncQRunMNFab& src);
	~ListFmncQRunMNFab();

	void clear();

public:
	vector<FmncQRunMNFab*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

