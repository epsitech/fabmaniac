/**
  * \file FmncQSmpList.h
  * API code for table TblFmncQSmpList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPLIST_H
#define FMNCQSMPLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpList
  */
class FmncQSmpList {

public:
	FmncQSmpList(const uint jnum = 0, const string sref = "", const string stubSupRefFmncMSample = "", const string stubRefFmncMArticle = "", const string Material = "", const string srefIxVState = "", const string titIxVState = "");

public:
	uint jnum;
	string sref;
	string stubSupRefFmncMSample;
	string stubRefFmncMArticle;
	string Material;
	string srefIxVState;
	string titIxVState;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSmpList
  */
class ListFmncQSmpList {

public:
	ListFmncQSmpList();
	ListFmncQSmpList(const ListFmncQSmpList& src);
	ListFmncQSmpList& operator=(const ListFmncQSmpList& src);
	~ListFmncQSmpList();

	void clear();

public:
	vector<FmncQSmpList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

