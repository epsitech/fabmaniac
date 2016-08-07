/**
  * \file FmncQArt1NSample.h
  * API code for table TblFmncQArt1NSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQART1NSAMPLE_H
#define FMNCQART1NSAMPLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArt1NSample
  */
class FmncQArt1NSample {

public:
	FmncQArt1NSample(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQArt1NSample
  */
class ListFmncQArt1NSample {

public:
	ListFmncQArt1NSample();
	ListFmncQArt1NSample(const ListFmncQArt1NSample& src);
	ListFmncQArt1NSample& operator=(const ListFmncQArt1NSample& src);
	~ListFmncQArt1NSample();

	void clear();

public:
	vector<FmncQArt1NSample*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

