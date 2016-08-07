/**
  * \file FmncQSmpMNRun.h
  * API code for table TblFmncQSmpMNRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPMNRUN_H
#define FMNCQSMPMNRUN_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpMNRun
  */
class FmncQSmpMNRun {

public:
	FmncQSmpMNRun(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSmpMNRun
  */
class ListFmncQSmpMNRun {

public:
	ListFmncQSmpMNRun();
	ListFmncQSmpMNRun(const ListFmncQSmpMNRun& src);
	ListFmncQSmpMNRun& operator=(const ListFmncQSmpMNRun& src);
	~ListFmncQSmpMNRun();

	void clear();

public:
	vector<FmncQSmpMNRun*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

