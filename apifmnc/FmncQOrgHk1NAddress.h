/**
  * \file FmncQOrgHk1NAddress.h
  * API code for table TblFmncQOrgHk1NAddress (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGHK1NADDRESS_H
#define FMNCQORGHK1NADDRESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgHk1NAddress
  */
class FmncQOrgHk1NAddress {

public:
	FmncQOrgHk1NAddress(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgHk1NAddress
  */
class ListFmncQOrgHk1NAddress {

public:
	ListFmncQOrgHk1NAddress();
	ListFmncQOrgHk1NAddress(const ListFmncQOrgHk1NAddress& src);
	ListFmncQOrgHk1NAddress& operator=(const ListFmncQOrgHk1NAddress& src);
	~ListFmncQOrgHk1NAddress();

	void clear();

public:
	vector<FmncQOrgHk1NAddress*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

