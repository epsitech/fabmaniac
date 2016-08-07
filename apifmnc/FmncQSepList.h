/**
  * \file FmncQSepList.h
  * API code for table TblFmncQSepList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPLIST_H
#define FMNCQSEPLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepList
  */
class FmncQSepList {

public:
	FmncQSepList(const uint jnum = 0, const string Title = "", const string stubRefFmncMActivity = "", const string srefRlvIxVTbl = "", const string titRlvIxVTbl = "", const string stubRlvUref = "", const string stubTplRefFmncMStep = "", const string ftmStart = "");

public:
	uint jnum;
	string Title;
	string stubRefFmncMActivity;
	string srefRlvIxVTbl;
	string titRlvIxVTbl;
	string stubRlvUref;
	string stubTplRefFmncMStep;
	string ftmStart;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSepList
  */
class ListFmncQSepList {

public:
	ListFmncQSepList();
	ListFmncQSepList(const ListFmncQSepList& src);
	ListFmncQSepList& operator=(const ListFmncQSepList& src);
	~ListFmncQSepList();

	void clear();

public:
	vector<FmncQSepList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

