/**
  * \file FmncQSmpMNStep.h
  * API code for table TblFmncQSmpMNStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPMNSTEP_H
#define FMNCQSMPMNSTEP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpMNStep
  */
class FmncQSmpMNStep {

public:
	FmncQSmpMNStep(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSmpMNStep
  */
class ListFmncQSmpMNStep {

public:
	ListFmncQSmpMNStep();
	ListFmncQSmpMNStep(const ListFmncQSmpMNStep& src);
	ListFmncQSmpMNStep& operator=(const ListFmncQSmpMNStep& src);
	~ListFmncQSmpMNStep();

	void clear();

public:
	vector<FmncQSmpMNStep*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

