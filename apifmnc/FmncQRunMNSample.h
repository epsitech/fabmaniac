/**
  * \file FmncQRunMNSample.h
  * API code for table TblFmncQRunMNSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNMNSAMPLE_H
#define FMNCQRUNMNSAMPLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunMNSample
  */
class FmncQRunMNSample {

public:
	FmncQRunMNSample(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQRunMNSample
  */
class ListFmncQRunMNSample {

public:
	ListFmncQRunMNSample();
	ListFmncQRunMNSample(const ListFmncQRunMNSample& src);
	ListFmncQRunMNSample& operator=(const ListFmncQRunMNSample& src);
	~ListFmncQRunMNSample();

	void clear();

public:
	vector<FmncQRunMNSample*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

