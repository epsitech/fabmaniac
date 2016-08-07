/**
  * \file FmncQUsgMNUser.h
  * API code for table TblFmncQUsgMNUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSGMNUSER_H
#define FMNCQUSGMNUSER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsgMNUser
  */
class FmncQUsgMNUser {

public:
	FmncQUsgMNUser(const uint jnum = 0, const string stubMref = "", const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");

public:
	uint jnum;
	string stubMref;
	string srefIxFmncVUserlevel;
	string titIxFmncVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQUsgMNUser
  */
class ListFmncQUsgMNUser {

public:
	ListFmncQUsgMNUser();
	ListFmncQUsgMNUser(const ListFmncQUsgMNUser& src);
	ListFmncQUsgMNUser& operator=(const ListFmncQUsgMNUser& src);
	~ListFmncQUsgMNUser();

	void clear();

public:
	vector<FmncQUsgMNUser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

