/**
  * \file FmncQTolList.h
  * API code for table TblFmncQTolList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLLIST_H
#define FMNCQTOLLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolList
  */
class FmncQTolList {

public:
	FmncQTolList(const uint jnum = 0, const string Title = "", const string stubFabRefFmncMFab = "", const string stubMnfRefFmncMOrg = "", const double Unitprice = 0.0, const string Training = "");

public:
	uint jnum;
	string Title;
	string stubFabRefFmncMFab;
	string stubMnfRefFmncMOrg;
	double Unitprice;
	string Training;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolList
  */
class ListFmncQTolList {

public:
	ListFmncQTolList();
	ListFmncQTolList(const ListFmncQTolList& src);
	ListFmncQTolList& operator=(const ListFmncQTolList& src);
	~ListFmncQTolList();

	void clear();

public:
	vector<FmncQTolList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

