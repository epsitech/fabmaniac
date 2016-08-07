/**
  * \file FmncQOrgList.h
  * API code for table TblFmncQOrgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGLIST_H
#define FMNCQORGLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgList
  */
class FmncQOrgList {

public:
	FmncQOrgList(const uint jnum = 0, const string sref = "", const string Title = "", const string srefsIxWDerivate = "", const string titsIxWDerivate = "", const string stubRefFmncMAddress = "", const string stubSupRefFmncMOrg = "", const string Tel = "", const string Eml = "");

public:
	uint jnum;
	string sref;
	string Title;
	string srefsIxWDerivate;
	string titsIxWDerivate;
	string stubRefFmncMAddress;
	string stubSupRefFmncMOrg;
	string Tel;
	string Eml;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgList
  */
class ListFmncQOrgList {

public:
	ListFmncQOrgList();
	ListFmncQOrgList(const ListFmncQOrgList& src);
	ListFmncQOrgList& operator=(const ListFmncQOrgList& src);
	~ListFmncQOrgList();

	void clear();

public:
	vector<FmncQOrgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

