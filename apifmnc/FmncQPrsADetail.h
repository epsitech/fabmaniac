/**
  * \file FmncQPrsADetail.h
  * API code for table TblFmncQPrsADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSADETAIL_H
#define FMNCQPRSADETAIL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsADetail
  */
class FmncQPrsADetail {

public:
	FmncQPrsADetail(const uint jnum = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");

public:
	uint jnum;
	string x1SrefKType;
	string titX1SrefKType;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPrsADetail
  */
class ListFmncQPrsADetail {

public:
	ListFmncQPrsADetail();
	ListFmncQPrsADetail(const ListFmncQPrsADetail& src);
	ListFmncQPrsADetail& operator=(const ListFmncQPrsADetail& src);
	~ListFmncQPrsADetail();

	void clear();

public:
	vector<FmncQPrsADetail*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

