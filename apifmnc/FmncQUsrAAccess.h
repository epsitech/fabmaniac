/**
  * \file FmncQUsrAAccess.h
  * API code for table TblFmncQUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSRAACCESS_H
#define FMNCQUSRAACCESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsrAAccess
  */
class FmncQUsrAAccess {

public:
	FmncQUsrAAccess(const uint jnum = 0, const string srefX1IxFmncVCard = "", const string titX1IxFmncVCard = "", const string srefsIxFmncWUiaccess = "", const string titsIxFmncWUiaccess = "");

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
  * ListFmncQUsrAAccess
  */
class ListFmncQUsrAAccess {

public:
	ListFmncQUsrAAccess();
	ListFmncQUsrAAccess(const ListFmncQUsrAAccess& src);
	ListFmncQUsrAAccess& operator=(const ListFmncQUsrAAccess& src);
	~ListFmncQUsrAAccess();

	void clear();

public:
	vector<FmncQUsrAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

