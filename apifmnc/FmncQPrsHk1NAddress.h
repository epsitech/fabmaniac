/**
  * \file FmncQPrsHk1NAddress.h
  * API code for table TblFmncQPrsHk1NAddress (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSHK1NADDRESS_H
#define FMNCQPRSHK1NADDRESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsHk1NAddress
  */
class FmncQPrsHk1NAddress {

public:
	FmncQPrsHk1NAddress(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQPrsHk1NAddress
  */
class ListFmncQPrsHk1NAddress {

public:
	ListFmncQPrsHk1NAddress();
	ListFmncQPrsHk1NAddress(const ListFmncQPrsHk1NAddress& src);
	ListFmncQPrsHk1NAddress& operator=(const ListFmncQPrsHk1NAddress& src);
	~ListFmncQPrsHk1NAddress();

	void clear();

public:
	vector<FmncQPrsHk1NAddress*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

