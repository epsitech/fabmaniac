/**
  * \file FmncQFpjMNFabuser.h
  * API code for table TblFmncQFpjMNFabuser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFPJMNFABUSER_H
#define FMNCQFPJMNFABUSER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFpjMNFabuser
  */
class FmncQFpjMNFabuser {

public:
	FmncQFpjMNFabuser(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFpjMNFabuser
  */
class ListFmncQFpjMNFabuser {

public:
	ListFmncQFpjMNFabuser();
	ListFmncQFpjMNFabuser(const ListFmncQFpjMNFabuser& src);
	ListFmncQFpjMNFabuser& operator=(const ListFmncQFpjMNFabuser& src);
	~ListFmncQFpjMNFabuser();

	void clear();

public:
	vector<FmncQFpjMNFabuser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

