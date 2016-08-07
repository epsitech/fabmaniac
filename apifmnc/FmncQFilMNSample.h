/**
  * \file FmncQFilMNSample.h
  * API code for table TblFmncQFilMNSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFILMNSAMPLE_H
#define FMNCQFILMNSAMPLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFilMNSample
  */
class FmncQFilMNSample {

public:
	FmncQFilMNSample(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFilMNSample
  */
class ListFmncQFilMNSample {

public:
	ListFmncQFilMNSample();
	ListFmncQFilMNSample(const ListFmncQFilMNSample& src);
	ListFmncQFilMNSample& operator=(const ListFmncQFilMNSample& src);
	~ListFmncQFilMNSample();

	void clear();

public:
	vector<FmncQFilMNSample*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

