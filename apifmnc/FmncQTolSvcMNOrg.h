/**
  * \file FmncQTolSvcMNOrg.h
  * API code for table TblFmncQTolSvcMNOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLSVCMNORG_H
#define FMNCQTOLSVCMNORG_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolSvcMNOrg
  */
class FmncQTolSvcMNOrg {

public:
	FmncQTolSvcMNOrg(const uint jnum = 0, const string stubMref = "", const string stubsTrefFmncMPerson = "");

public:
	uint jnum;
	string stubMref;
	string stubsTrefFmncMPerson;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolSvcMNOrg
  */
class ListFmncQTolSvcMNOrg {

public:
	ListFmncQTolSvcMNOrg();
	ListFmncQTolSvcMNOrg(const ListFmncQTolSvcMNOrg& src);
	ListFmncQTolSvcMNOrg& operator=(const ListFmncQTolSvcMNOrg& src);
	~ListFmncQTolSvcMNOrg();

	void clear();

public:
	vector<FmncQTolSvcMNOrg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

