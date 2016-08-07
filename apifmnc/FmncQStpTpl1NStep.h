/**
  * \file FmncQStpTpl1NStep.h
  * API code for table TblFmncQStpTpl1NStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPTPL1NSTEP_H
#define FMNCQSTPTPL1NSTEP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpTpl1NStep
  */
class FmncQStpTpl1NStep {

public:
	FmncQStpTpl1NStep(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQStpTpl1NStep
  */
class ListFmncQStpTpl1NStep {

public:
	ListFmncQStpTpl1NStep();
	ListFmncQStpTpl1NStep(const ListFmncQStpTpl1NStep& src);
	ListFmncQStpTpl1NStep& operator=(const ListFmncQStpTpl1NStep& src);
	~ListFmncQStpTpl1NStep();

	void clear();

public:
	vector<FmncQStpTpl1NStep*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

