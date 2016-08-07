/**
  * \file FmncQPrj1NRun.h
  * API code for table TblFmncQPrj1NRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRJ1NRUN_H
#define FMNCQPRJ1NRUN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrj1NRun
  */
class FmncQPrj1NRun {

public:
	FmncQPrj1NRun(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPrj1NRun
  */
class ListFmncQPrj1NRun {

public:
	ListFmncQPrj1NRun();
	ListFmncQPrj1NRun(const ListFmncQPrj1NRun& src);
	ListFmncQPrj1NRun& operator=(const ListFmncQPrj1NRun& src);
	~ListFmncQPrj1NRun();

	void clear();

public:
	vector<FmncQPrj1NRun*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

