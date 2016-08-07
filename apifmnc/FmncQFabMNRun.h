/**
  * \file FmncQFabMNRun.h
  * API code for table TblFmncQFabMNRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFABMNRUN_H
#define FMNCQFABMNRUN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFabMNRun
  */
class FmncQFabMNRun {

public:
	FmncQFabMNRun(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFabMNRun
  */
class ListFmncQFabMNRun {

public:
	ListFmncQFabMNRun();
	ListFmncQFabMNRun(const ListFmncQFabMNRun& src);
	ListFmncQFabMNRun& operator=(const ListFmncQFabMNRun& src);
	~ListFmncQFabMNRun();

	void clear();

public:
	vector<FmncQFabMNRun*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

