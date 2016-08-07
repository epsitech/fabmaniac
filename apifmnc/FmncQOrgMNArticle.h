/**
  * \file FmncQOrgMNArticle.h
  * API code for table TblFmncQOrgMNArticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGMNARTICLE_H
#define FMNCQORGMNARTICLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgMNArticle
  */
class FmncQOrgMNArticle {

public:
	FmncQOrgMNArticle(const uint jnum = 0, const string stubMref = "", const string Itemno = "");

public:
	uint jnum;
	string stubMref;
	string Itemno;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgMNArticle
  */
class ListFmncQOrgMNArticle {

public:
	ListFmncQOrgMNArticle();
	ListFmncQOrgMNArticle(const ListFmncQOrgMNArticle& src);
	ListFmncQOrgMNArticle& operator=(const ListFmncQOrgMNArticle& src);
	~ListFmncQOrgMNArticle();

	void clear();

public:
	vector<FmncQOrgMNArticle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

