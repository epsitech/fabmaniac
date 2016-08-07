/**
  * \file FmncQPrsMNRun.h
  * API code for table TblFmncQPrsMNRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSMNRUN_H
#define FMNCQPRSMNRUN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsMNRun
  */
class FmncQPrsMNRun {

public:
	FmncQPrsMNRun(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPrsMNRun
  */
class ListFmncQPrsMNRun {

public:
	ListFmncQPrsMNRun();
	ListFmncQPrsMNRun(const ListFmncQPrsMNRun& src);
	ListFmncQPrsMNRun& operator=(const ListFmncQPrsMNRun& src);
	~ListFmncQPrsMNRun();

	void clear();

public:
	vector<FmncQPrsMNRun*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

