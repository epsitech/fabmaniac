/**
  * \file FmncQStpList.h
  * API code for table TblFmncQStpList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPLIST_H
#define FMNCQSTPLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpList
  */
class FmncQStpList {

public:
	FmncQStpList(const uint jnum = 0, const string Title = "", const string stubRefFmncMActivity = "", const string srefRlvIxVTbl = "", const string titRlvIxVTbl = "", const string stubRlvUref = "", const string stubTplRefFmncMStep = "", const string ftmStart = "");

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
  * ListFmncQStpList
  */
class ListFmncQStpList {

public:
	ListFmncQStpList();
	ListFmncQStpList(const ListFmncQStpList& src);
	ListFmncQStpList& operator=(const ListFmncQStpList& src);
	~ListFmncQStpList();

	void clear();

public:
	vector<FmncQStpList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

