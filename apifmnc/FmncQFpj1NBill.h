/**
  * \file FmncQFpj1NBill.h
  * API code for table TblFmncQFpj1NBill (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFPJ1NBILL_H
#define FMNCQFPJ1NBILL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFpj1NBill
  */
class FmncQFpj1NBill {

public:
	FmncQFpj1NBill(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQFpj1NBill
  */
class ListFmncQFpj1NBill {

public:
	ListFmncQFpj1NBill();
	ListFmncQFpj1NBill(const ListFmncQFpj1NBill& src);
	ListFmncQFpj1NBill& operator=(const ListFmncQFpj1NBill& src);
	~ListFmncQFpj1NBill();

	void clear();

public:
	vector<FmncQFpj1NBill*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

