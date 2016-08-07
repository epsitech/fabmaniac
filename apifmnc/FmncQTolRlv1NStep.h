/**
  * \file FmncQTolRlv1NStep.h
  * API code for table TblFmncQTolRlv1NStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLRLV1NSTEP_H
#define FMNCQTOLRLV1NSTEP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolRlv1NStep
  */
class FmncQTolRlv1NStep {

public:
	FmncQTolRlv1NStep(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolRlv1NStep
  */
class ListFmncQTolRlv1NStep {

public:
	ListFmncQTolRlv1NStep();
	ListFmncQTolRlv1NStep(const ListFmncQTolRlv1NStep& src);
	ListFmncQTolRlv1NStep& operator=(const ListFmncQTolRlv1NStep& src);
	~ListFmncQTolRlv1NStep();

	void clear();

public:
	vector<FmncQTolRlv1NStep*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

