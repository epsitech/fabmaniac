/**
  * \file FmncQOrgBio1NFabproject.h
  * API code for table TblFmncQOrgBio1NFabproject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGBIO1NFABPROJECT_H
#define FMNCQORGBIO1NFABPROJECT_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgBio1NFabproject
  */
class FmncQOrgBio1NFabproject {

public:
	FmncQOrgBio1NFabproject(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgBio1NFabproject
  */
class ListFmncQOrgBio1NFabproject {

public:
	ListFmncQOrgBio1NFabproject();
	ListFmncQOrgBio1NFabproject(const ListFmncQOrgBio1NFabproject& src);
	ListFmncQOrgBio1NFabproject& operator=(const ListFmncQOrgBio1NFabproject& src);
	~ListFmncQOrgBio1NFabproject();

	void clear();

public:
	vector<FmncQOrgBio1NFabproject*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

