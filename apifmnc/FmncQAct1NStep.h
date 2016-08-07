/**
  * \file FmncQAct1NStep.h
  * API code for table TblFmncQAct1NStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQACT1NSTEP_H
#define FMNCQACT1NSTEP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQAct1NStep
  */
class FmncQAct1NStep {

public:
	FmncQAct1NStep(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQAct1NStep
  */
class ListFmncQAct1NStep {

public:
	ListFmncQAct1NStep();
	ListFmncQAct1NStep(const ListFmncQAct1NStep& src);
	ListFmncQAct1NStep& operator=(const ListFmncQAct1NStep& src);
	~ListFmncQAct1NStep();

	void clear();

public:
	vector<FmncQAct1NStep*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

