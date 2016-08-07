/**
  * \file FmncQOrg1NArticle.h
  * API code for table TblFmncQOrg1NArticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORG1NARTICLE_H
#define FMNCQORG1NARTICLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrg1NArticle
  */
class FmncQOrg1NArticle {

public:
	FmncQOrg1NArticle(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrg1NArticle
  */
class ListFmncQOrg1NArticle {

public:
	ListFmncQOrg1NArticle();
	ListFmncQOrg1NArticle(const ListFmncQOrg1NArticle& src);
	ListFmncQOrg1NArticle& operator=(const ListFmncQOrg1NArticle& src);
	~ListFmncQOrg1NArticle();

	void clear();

public:
	vector<FmncQOrg1NArticle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

