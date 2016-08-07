/**
  * \file FmncQRunMNPerson.h
  * API code for table TblFmncQRunMNPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNMNPERSON_H
#define FMNCQRUNMNPERSON_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunMNPerson
  */
class FmncQRunMNPerson {

public:
	FmncQRunMNPerson(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQRunMNPerson
  */
class ListFmncQRunMNPerson {

public:
	ListFmncQRunMNPerson();
	ListFmncQRunMNPerson(const ListFmncQRunMNPerson& src);
	ListFmncQRunMNPerson& operator=(const ListFmncQRunMNPerson& src);
	~ListFmncQRunMNPerson();

	void clear();

public:
	vector<FmncQRunMNPerson*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

