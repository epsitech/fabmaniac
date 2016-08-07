/**
  * \file FmncQOrgPco1NPurchorder.h
  * API code for table TblFmncQOrgPco1NPurchorder (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGPCO1NPURCHORDER_H
#define FMNCQORGPCO1NPURCHORDER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgPco1NPurchorder
  */
class FmncQOrgPco1NPurchorder {

public:
	FmncQOrgPco1NPurchorder(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgPco1NPurchorder
  */
class ListFmncQOrgPco1NPurchorder {

public:
	ListFmncQOrgPco1NPurchorder();
	ListFmncQOrgPco1NPurchorder(const ListFmncQOrgPco1NPurchorder& src);
	ListFmncQOrgPco1NPurchorder& operator=(const ListFmncQOrgPco1NPurchorder& src);
	~ListFmncQOrgPco1NPurchorder();

	void clear();

public:
	vector<FmncQOrgPco1NPurchorder*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

