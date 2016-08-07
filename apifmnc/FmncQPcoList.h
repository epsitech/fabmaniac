/**
  * \file FmncQPcoList.h
  * API code for table TblFmncQPcoList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPCOLIST_H
#define FMNCQPCOLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPcoList
  */
class FmncQPcoList {

public:
	FmncQPcoList(const uint jnum = 0, const string sref = "", const string ftmDate = "", const string stubPcoRefFmncMOrg = "", const string stubSplRefFmncMOrg = "", const string stubRefFmncMFile = "", const string srefIxVState = "", const string titIxVState = "", const double Amount = 0.0);

public:
	uint jnum;
	string sref;
	string ftmDate;
	string stubPcoRefFmncMOrg;
	string stubSplRefFmncMOrg;
	string stubRefFmncMFile;
	string srefIxVState;
	string titIxVState;
	double Amount;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPcoList
  */
class ListFmncQPcoList {

public:
	ListFmncQPcoList();
	ListFmncQPcoList(const ListFmncQPcoList& src);
	ListFmncQPcoList& operator=(const ListFmncQPcoList& src);
	~ListFmncQPcoList();

	void clear();

public:
	vector<FmncQPcoList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

