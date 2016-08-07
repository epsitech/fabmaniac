/**
  * \file FmncQUsr1NSession.h
  * API code for table TblFmncQUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSR1NSESSION_H
#define FMNCQUSR1NSESSION_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsr1NSession
  */
class FmncQUsr1NSession {

public:
	FmncQUsr1NSession(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQUsr1NSession
  */
class ListFmncQUsr1NSession {

public:
	ListFmncQUsr1NSession();
	ListFmncQUsr1NSession(const ListFmncQUsr1NSession& src);
	ListFmncQUsr1NSession& operator=(const ListFmncQUsr1NSession& src);
	~ListFmncQUsr1NSession();

	void clear();

public:
	vector<FmncQUsr1NSession*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

