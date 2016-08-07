/**
  * \file FmncQArtList.h
  * API code for table TblFmncQArtList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQARTLIST_H
#define FMNCQARTLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArtList
  */
class FmncQArtList {

public:
	FmncQArtList(const uint jnum = 0, const string sref = "", const string Title = "", const string stubRefFmncMOrg = "", const string stubRefFmncMTool = "", const string srefKType = "", const string titSrefKType = "");

public:
	uint jnum;
	string sref;
	string Title;
	string stubRefFmncMOrg;
	string stubRefFmncMTool;
	string srefKType;
	string titSrefKType;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQArtList
  */
class ListFmncQArtList {

public:
	ListFmncQArtList();
	ListFmncQArtList(const ListFmncQArtList& src);
	ListFmncQArtList& operator=(const ListFmncQArtList& src);
	~ListFmncQArtList();

	void clear();

public:
	vector<FmncQArtList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

