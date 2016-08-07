/**
  * \file FmncQUsgAAccess.h
  * API code for table TblFmncQUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSGAACCESS_H
#define FMNCQUSGAACCESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsgAAccess
  */
class FmncQUsgAAccess {

public:
	FmncQUsgAAccess(const uint jnum = 0, const string srefX1IxFmncVCard = "", const string titX1IxFmncVCard = "", const string srefsIxFmncWUiaccess = "", const string titsIxFmncWUiaccess = "");

public:
	uint jnum;
	string srefX1IxFmncVCard;
	string titX1IxFmncVCard;
	string srefsIxFmncWUiaccess;
	string titsIxFmncWUiaccess;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQUsgAAccess
  */
class ListFmncQUsgAAccess {

public:
	ListFmncQUsgAAccess();
	ListFmncQUsgAAccess(const ListFmncQUsgAAccess& src);
	ListFmncQUsgAAccess& operator=(const ListFmncQUsgAAccess& src);
	~ListFmncQUsgAAccess();

	void clear();

public:
	vector<FmncQUsgAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

