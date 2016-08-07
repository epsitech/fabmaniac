/**
  * \file FmncQArtMNOrg.h
  * API code for table TblFmncQArtMNOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQARTMNORG_H
#define FMNCQARTMNORG_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArtMNOrg
  */
class FmncQArtMNOrg {

public:
	FmncQArtMNOrg(const uint jnum = 0, const string stubMref = "", const string Itemno = "");

public:
	uint jnum;
	string stubMref;
	string Itemno;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQArtMNOrg
  */
class ListFmncQArtMNOrg {

public:
	ListFmncQArtMNOrg();
	ListFmncQArtMNOrg(const ListFmncQArtMNOrg& src);
	ListFmncQArtMNOrg& operator=(const ListFmncQArtMNOrg& src);
	~ListFmncQArtMNOrg();

	void clear();

public:
	vector<FmncQArtMNOrg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

