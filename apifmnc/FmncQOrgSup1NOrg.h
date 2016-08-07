/**
  * \file FmncQOrgSup1NOrg.h
  * API code for table TblFmncQOrgSup1NOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGSUP1NORG_H
#define FMNCQORGSUP1NORG_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgSup1NOrg
  */
class FmncQOrgSup1NOrg {

public:
	FmncQOrgSup1NOrg(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgSup1NOrg
  */
class ListFmncQOrgSup1NOrg {

public:
	ListFmncQOrgSup1NOrg();
	ListFmncQOrgSup1NOrg(const ListFmncQOrgSup1NOrg& src);
	ListFmncQOrgSup1NOrg& operator=(const ListFmncQOrgSup1NOrg& src);
	~ListFmncQOrgSup1NOrg();

	void clear();

public:
	vector<FmncQOrgSup1NOrg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

