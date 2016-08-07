/**
  * \file FmncQOrgADetail.h
  * API code for table TblFmncQOrgADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGADETAIL_H
#define FMNCQORGADETAIL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgADetail
  */
class FmncQOrgADetail {

public:
	FmncQOrgADetail(const uint jnum = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");

public:
	uint jnum;
	string x1SrefKType;
	string titX1SrefKType;
	string Val;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgADetail
  */
class ListFmncQOrgADetail {

public:
	ListFmncQOrgADetail();
	ListFmncQOrgADetail(const ListFmncQOrgADetail& src);
	ListFmncQOrgADetail& operator=(const ListFmncQOrgADetail& src);
	~ListFmncQOrgADetail();

	void clear();

public:
	vector<FmncQOrgADetail*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

