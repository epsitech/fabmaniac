/**
  * \file FmncQSepMNSample.h
  * API code for table TblFmncQSepMNSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPMNSAMPLE_H
#define FMNCQSEPMNSAMPLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepMNSample
  */
class FmncQSepMNSample {

public:
	FmncQSepMNSample(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSepMNSample
  */
class ListFmncQSepMNSample {

public:
	ListFmncQSepMNSample();
	ListFmncQSepMNSample(const ListFmncQSepMNSample& src);
	ListFmncQSepMNSample& operator=(const ListFmncQSepMNSample& src);
	~ListFmncQSepMNSample();

	void clear();

public:
	vector<FmncQSepMNSample*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

