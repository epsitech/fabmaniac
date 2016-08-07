/**
  * \file FmncQBilAPos.h
  * API code for table TblFmncQBilAPos (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQBILAPOS_H
#define FMNCQBILAPOS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQBilAPos
  */
class FmncQBilAPos {

public:
	FmncQBilAPos(const uint jnum = 0, const string stubX1RefFmncMFabuser = "", const string stubX2RefFmncMTool = "", const double Quantity = 0.0, const string Article = "", const double Unitprice = 0.0, const double Price = 0.0);

public:
	uint jnum;
	string stubX1RefFmncMFabuser;
	string stubX2RefFmncMTool;
	double Quantity;
	string Article;
	double Unitprice;
	double Price;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQBilAPos
  */
class ListFmncQBilAPos {

public:
	ListFmncQBilAPos();
	ListFmncQBilAPos(const ListFmncQBilAPos& src);
	ListFmncQBilAPos& operator=(const ListFmncQBilAPos& src);
	~ListFmncQBilAPos();

	void clear();

public:
	vector<FmncQBilAPos*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

