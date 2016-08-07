/**
  * \file FmncQOrgMNPerson.h
  * API code for table TblFmncQOrgMNPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGMNPERSON_H
#define FMNCQORGMNPERSON_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgMNPerson
  */
class FmncQOrgMNPerson {

public:
	FmncQOrgMNPerson(const uint jnum = 0, const string stubMref = "", const string ftmX1Startd = "", const string ftmX1Stopd = "", const string srefKFunction = "", const string titSrefKFunction = "");

public:
	uint jnum;
	string stubMref;
	string ftmX1Startd;
	string ftmX1Stopd;
	string srefKFunction;
	string titSrefKFunction;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgMNPerson
  */
class ListFmncQOrgMNPerson {

public:
	ListFmncQOrgMNPerson();
	ListFmncQOrgMNPerson(const ListFmncQOrgMNPerson& src);
	ListFmncQOrgMNPerson& operator=(const ListFmncQOrgMNPerson& src);
	~ListFmncQOrgMNPerson();

	void clear();

public:
	vector<FmncQOrgMNPerson*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

