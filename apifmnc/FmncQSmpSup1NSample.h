/**
  * \file FmncQSmpSup1NSample.h
  * API code for table TblFmncQSmpSup1NSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPSUP1NSAMPLE_H
#define FMNCQSMPSUP1NSAMPLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpSup1NSample
  */
class FmncQSmpSup1NSample {

public:
	FmncQSmpSup1NSample(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSmpSup1NSample
  */
class ListFmncQSmpSup1NSample {

public:
	ListFmncQSmpSup1NSample();
	ListFmncQSmpSup1NSample(const ListFmncQSmpSup1NSample& src);
	ListFmncQSmpSup1NSample& operator=(const ListFmncQSmpSup1NSample& src);
	~ListFmncQSmpSup1NSample();

	void clear();

public:
	vector<FmncQSmpSup1NSample*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

