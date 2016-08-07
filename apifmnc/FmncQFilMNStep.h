/**
  * \file FmncQFilMNStep.h
  * API code for table TblFmncQFilMNStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFILMNSTEP_H
#define FMNCQFILMNSTEP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFilMNStep
  */
class FmncQFilMNStep {

public:
	FmncQFilMNStep(const uint jnum = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const string srefIxVDir = "", const string titIxVDir = "");

public:
	uint jnum;
	string stubMref;
	string stubsTrefFmncMSample;
	string srefIxVDir;
	string titIxVDir;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFilMNStep
  */
class ListFmncQFilMNStep {

public:
	ListFmncQFilMNStep();
	ListFmncQFilMNStep(const ListFmncQFilMNStep& src);
	ListFmncQFilMNStep& operator=(const ListFmncQFilMNStep& src);
	~ListFmncQFilMNStep();

	void clear();

public:
	vector<FmncQFilMNStep*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

