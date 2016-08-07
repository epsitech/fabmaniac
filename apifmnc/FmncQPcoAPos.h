/**
  * \file FmncQPcoAPos.h
  * API code for table TblFmncQPcoAPos (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPCOAPOS_H
#define FMNCQPCOAPOS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPcoAPos
  */
class FmncQPcoAPos {

public:
	FmncQPcoAPos(const uint jnum = 0, const double Quantity = 0.0, const string Itemno = "", const string stubRefFmncMArticle = "", const double Unitprice = 0.0, const double Price = 0.0);

public:
	uint jnum;
	double Quantity;
	string Itemno;
	string stubRefFmncMArticle;
	double Unitprice;
	double Price;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPcoAPos
  */
class ListFmncQPcoAPos {

public:
	ListFmncQPcoAPos();
	ListFmncQPcoAPos(const ListFmncQPcoAPos& src);
	ListFmncQPcoAPos& operator=(const ListFmncQPcoAPos& src);
	~ListFmncQPcoAPos();

	void clear();

public:
	vector<FmncQPcoAPos*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

