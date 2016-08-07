/**
  * \file FmncQOrgSpl1NPurchorder.h
  * API code for table TblFmncQOrgSpl1NPurchorder (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGSPL1NPURCHORDER_H
#define FMNCQORGSPL1NPURCHORDER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgSpl1NPurchorder
  */
class FmncQOrgSpl1NPurchorder {

public:
	FmncQOrgSpl1NPurchorder(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgSpl1NPurchorder
  */
class ListFmncQOrgSpl1NPurchorder {

public:
	ListFmncQOrgSpl1NPurchorder();
	ListFmncQOrgSpl1NPurchorder(const ListFmncQOrgSpl1NPurchorder& src);
	ListFmncQOrgSpl1NPurchorder& operator=(const ListFmncQOrgSpl1NPurchorder& src);
	~ListFmncQOrgSpl1NPurchorder();

	void clear();

public:
	vector<FmncQOrgSpl1NPurchorder*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

