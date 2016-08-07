/**
  * \file FmncQTol1NArticle.h
  * API code for table TblFmncQTol1NArticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOL1NARTICLE_H
#define FMNCQTOL1NARTICLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTol1NArticle
  */
class FmncQTol1NArticle {

public:
	FmncQTol1NArticle(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTol1NArticle
  */
class ListFmncQTol1NArticle {

public:
	ListFmncQTol1NArticle();
	ListFmncQTol1NArticle(const ListFmncQTol1NArticle& src);
	ListFmncQTol1NArticle& operator=(const ListFmncQTol1NArticle& src);
	~ListFmncQTol1NArticle();

	void clear();

public:
	vector<FmncQTol1NArticle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

