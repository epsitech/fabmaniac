/**
  * \file FmncQSmpAPar.h
  * API code for table TblFmncQSmpAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPAPAR_H
#define FMNCQSMPAPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpAPar
  */
class FmncQSmpAPar {

public:
	FmncQSmpAPar(const uint jnum = 0, const string x1SrefKKey = "", const string titX1SrefKKey = "", const string osrefKVal = "", const string titOsrefKVal = "");

public:
	uint jnum;
	string x1SrefKKey;
	string titX1SrefKKey;
	string osrefKVal;
	string titOsrefKVal;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSmpAPar
  */
class ListFmncQSmpAPar {

public:
	ListFmncQSmpAPar();
	ListFmncQSmpAPar(const ListFmncQSmpAPar& src);
	ListFmncQSmpAPar& operator=(const ListFmncQSmpAPar& src);
	~ListFmncQSmpAPar();

	void clear();

public:
	vector<FmncQSmpAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

