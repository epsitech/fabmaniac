/**
  * \file FmncQTtyRlv1NStep.h
  * API code for table TblFmncQTtyRlv1NStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYRLV1NSTEP_H
#define FMNCQTTYRLV1NSTEP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyRlv1NStep
  */
class FmncQTtyRlv1NStep {

public:
	FmncQTtyRlv1NStep(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTtyRlv1NStep
  */
class ListFmncQTtyRlv1NStep {

public:
	ListFmncQTtyRlv1NStep();
	ListFmncQTtyRlv1NStep(const ListFmncQTtyRlv1NStep& src);
	ListFmncQTtyRlv1NStep& operator=(const ListFmncQTtyRlv1NStep& src);
	~ListFmncQTtyRlv1NStep();

	void clear();

public:
	vector<FmncQTtyRlv1NStep*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

