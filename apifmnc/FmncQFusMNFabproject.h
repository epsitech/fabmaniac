/**
  * \file FmncQFusMNFabproject.h
  * API code for table TblFmncQFusMNFabproject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFUSMNFABPROJECT_H
#define FMNCQFUSMNFABPROJECT_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFusMNFabproject
  */
class FmncQFusMNFabproject {

public:
	FmncQFusMNFabproject(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFusMNFabproject
  */
class ListFmncQFusMNFabproject {

public:
	ListFmncQFusMNFabproject();
	ListFmncQFusMNFabproject(const ListFmncQFusMNFabproject& src);
	ListFmncQFusMNFabproject& operator=(const ListFmncQFusMNFabproject& src);
	~ListFmncQFusMNFabproject();

	void clear();

public:
	vector<FmncQFusMNFabproject*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

