/**
  * \file FmncQTolMNTooltype.h
  * API code for table TblFmncQTolMNTooltype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLMNTOOLTYPE_H
#define FMNCQTOLMNTOOLTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolMNTooltype
  */
class FmncQTolMNTooltype {

public:
	FmncQTolMNTooltype(const uint jnum = 0, const string stubMref = "", const string srefsFmncKToolchar = "", const string titsSrefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string titsDefSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "", const string titsOptSrefsFmncKSteppar = "");

public:
	uint jnum;
	string stubMref;
	string srefsFmncKToolchar;
	string titsSrefsFmncKToolchar;
	string defSrefsFmncKSteppar;
	string titsDefSrefsFmncKSteppar;
	string optSrefsFmncKSteppar;
	string titsOptSrefsFmncKSteppar;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolMNTooltype
  */
class ListFmncQTolMNTooltype {

public:
	ListFmncQTolMNTooltype();
	ListFmncQTolMNTooltype(const ListFmncQTolMNTooltype& src);
	ListFmncQTolMNTooltype& operator=(const ListFmncQTolMNTooltype& src);
	~ListFmncQTolMNTooltype();

	void clear();

public:
	vector<FmncQTolMNTooltype*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

