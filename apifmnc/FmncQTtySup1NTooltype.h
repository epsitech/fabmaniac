/**
  * \file FmncQTtySup1NTooltype.h
  * API code for table TblFmncQTtySup1NTooltype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYSUP1NTOOLTYPE_H
#define FMNCQTTYSUP1NTOOLTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtySup1NTooltype
  */
class FmncQTtySup1NTooltype {

public:
	FmncQTtySup1NTooltype(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTtySup1NTooltype
  */
class ListFmncQTtySup1NTooltype {

public:
	ListFmncQTtySup1NTooltype();
	ListFmncQTtySup1NTooltype(const ListFmncQTtySup1NTooltype& src);
	ListFmncQTtySup1NTooltype& operator=(const ListFmncQTtySup1NTooltype& src);
	~ListFmncQTtySup1NTooltype();

	void clear();

public:
	vector<FmncQTtySup1NTooltype*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

