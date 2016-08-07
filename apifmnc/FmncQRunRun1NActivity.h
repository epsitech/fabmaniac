/**
  * \file FmncQRunRun1NActivity.h
  * API code for table TblFmncQRunRun1NActivity (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNRUN1NACTIVITY_H
#define FMNCQRUNRUN1NACTIVITY_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunRun1NActivity
  */
class FmncQRunRun1NActivity {

public:
	FmncQRunRun1NActivity(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQRunRun1NActivity
  */
class ListFmncQRunRun1NActivity {

public:
	ListFmncQRunRun1NActivity();
	ListFmncQRunRun1NActivity(const ListFmncQRunRun1NActivity& src);
	ListFmncQRunRun1NActivity& operator=(const ListFmncQRunRun1NActivity& src);
	~ListFmncQRunRun1NActivity();

	void clear();

public:
	vector<FmncQRunRun1NActivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

