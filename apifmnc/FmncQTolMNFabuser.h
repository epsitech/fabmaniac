/**
  * \file FmncQTolMNFabuser.h
  * API code for table TblFmncQTolMNFabuser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLMNFABUSER_H
#define FMNCQTOLMNFABUSER_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolMNFabuser
  */
class FmncQTolMNFabuser {

public:
	FmncQTolMNFabuser(const uint jnum = 0, const string stubMref = "", const string stubTrnRefFmncMPerson = "", const string srefKLvl = "", const string titSrefKLvl = "");

public:
	uint jnum;
	string stubMref;
	string stubTrnRefFmncMPerson;
	string srefKLvl;
	string titSrefKLvl;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolMNFabuser
  */
class ListFmncQTolMNFabuser {

public:
	ListFmncQTolMNFabuser();
	ListFmncQTolMNFabuser(const ListFmncQTolMNFabuser& src);
	ListFmncQTolMNFabuser& operator=(const ListFmncQTolMNFabuser& src);
	~ListFmncQTolMNFabuser();

	void clear();

public:
	vector<FmncQTolMNFabuser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

