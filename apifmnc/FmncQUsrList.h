/**
  * \file FmncQUsrList.h
  * API code for table TblFmncQUsrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSRLIST_H
#define FMNCQUSRLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsrList
  */
class FmncQUsrList {

public:
	FmncQUsrList(const uint jnum = 0, const string stubRefFmncMPerson = "", const string sref = "", const string stubRefFmncMUsergroup = "", const string srefIxVState = "", const string titIxVState = "", const string srefIxFmncVLocale = "", const string titIxFmncVLocale = "", const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");

public:
	uint jnum;
	string stubRefFmncMPerson;
	string sref;
	string stubRefFmncMUsergroup;
	string srefIxVState;
	string titIxVState;
	string srefIxFmncVLocale;
	string titIxFmncVLocale;
	string srefIxFmncVUserlevel;
	string titIxFmncVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQUsrList
  */
class ListFmncQUsrList {

public:
	ListFmncQUsrList();
	ListFmncQUsrList(const ListFmncQUsrList& src);
	ListFmncQUsrList& operator=(const ListFmncQUsrList& src);
	~ListFmncQUsrList();

	void clear();

public:
	vector<FmncQUsrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

