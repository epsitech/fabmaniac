/**
  * \file FmncQUsrMNUsergroup.h
  * API code for table TblFmncQUsrMNUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSRMNUSERGROUP_H
#define FMNCQUSRMNUSERGROUP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsrMNUsergroup
  */
class FmncQUsrMNUsergroup {

public:
	FmncQUsrMNUsergroup(const uint jnum = 0, const string stubMref = "", const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");

public:
	uint jnum;
	string stubMref;
	string srefIxFmncVUserlevel;
	string titIxFmncVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQUsrMNUsergroup
  */
class ListFmncQUsrMNUsergroup {

public:
	ListFmncQUsrMNUsergroup();
	ListFmncQUsrMNUsergroup(const ListFmncQUsrMNUsergroup& src);
	ListFmncQUsrMNUsergroup& operator=(const ListFmncQUsrMNUsergroup& src);
	~ListFmncQUsrMNUsergroup();

	void clear();

public:
	vector<FmncQUsrMNUsergroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

