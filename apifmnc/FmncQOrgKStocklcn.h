/**
  * \file FmncQOrgKStocklcn.h
  * API code for table TblFmncQOrgKStocklcn (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGKSTOCKLCN_H
#define FMNCQORGKSTOCKLCN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgKStocklcn
  */
class FmncQOrgKStocklcn {

public:
	FmncQOrgKStocklcn(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

public:
	uint jnum;
	string yesnoFixed;
	string sref;
	string Avail;
	string Implied;
	string Title;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgKStocklcn
  */
class ListFmncQOrgKStocklcn {

public:
	ListFmncQOrgKStocklcn();
	ListFmncQOrgKStocklcn(const ListFmncQOrgKStocklcn& src);
	ListFmncQOrgKStocklcn& operator=(const ListFmncQOrgKStocklcn& src);
	~ListFmncQOrgKStocklcn();

	void clear();

public:
	vector<FmncQOrgKStocklcn*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

