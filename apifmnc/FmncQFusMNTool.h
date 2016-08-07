/**
  * \file FmncQFusMNTool.h
  * API code for table TblFmncQFusMNTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFUSMNTOOL_H
#define FMNCQFUSMNTOOL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFusMNTool
  */
class FmncQFusMNTool {

public:
	FmncQFusMNTool(const uint jnum = 0, const string stubMref = "", const string stubTrnRefFmncMPerson = "", const string srefKLvl = "", const string titSrefKLvl = "");

public:
	uint jnum;
	string stubMref;
	string stubTrnRefFmncMPerson;
	string srefKLvl;
	string titSrefKLvl;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFusMNTool
  */
class ListFmncQFusMNTool {

public:
	ListFmncQFusMNTool();
	ListFmncQFusMNTool(const ListFmncQFusMNTool& src);
	ListFmncQFusMNTool& operator=(const ListFmncQFusMNTool& src);
	~ListFmncQFusMNTool();

	void clear();

public:
	vector<FmncQFusMNTool*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

