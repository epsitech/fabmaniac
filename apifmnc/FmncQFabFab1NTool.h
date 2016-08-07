/**
  * \file FmncQFabFab1NTool.h
  * API code for table TblFmncQFabFab1NTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFABFAB1NTOOL_H
#define FMNCQFABFAB1NTOOL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFabFab1NTool
  */
class FmncQFabFab1NTool {

public:
	FmncQFabFab1NTool(const uint jnum = 0, const string stubRef = "", const string stubsSrefFmncMPerson = "");

public:
	uint jnum;
	string stubRef;
	string stubsSrefFmncMPerson;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFabFab1NTool
  */
class ListFmncQFabFab1NTool {

public:
	ListFmncQFabFab1NTool();
	ListFmncQFabFab1NTool(const ListFmncQFabFab1NTool& src);
	ListFmncQFabFab1NTool& operator=(const ListFmncQFabFab1NTool& src);
	~ListFmncQFabFab1NTool();

	void clear();

public:
	vector<FmncQFabFab1NTool*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

