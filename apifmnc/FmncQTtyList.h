/**
  * \file FmncQTtyList.h
  * API code for table TblFmncQTtyList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYLIST_H
#define FMNCQTTYLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyList
  */
class FmncQTtyList {

public:
	FmncQTtyList(const uint jnum = 0, const string sref = "", const string Title = "", const string stubSupRefFmncMTooltype = "");

public:
	uint jnum;
	string sref;
	string Title;
	string stubSupRefFmncMTooltype;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTtyList
  */
class ListFmncQTtyList {

public:
	ListFmncQTtyList();
	ListFmncQTtyList(const ListFmncQTtyList& src);
	ListFmncQTtyList& operator=(const ListFmncQTtyList& src);
	~ListFmncQTtyList();

	void clear();

public:
	vector<FmncQTtyList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

