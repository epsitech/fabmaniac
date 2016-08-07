/**
  * \file FmncQTtyMNTool.h
  * API code for table TblFmncQTtyMNTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYMNTOOL_H
#define FMNCQTTYMNTOOL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyMNTool
  */
class FmncQTtyMNTool {

public:
	FmncQTtyMNTool(const uint jnum = 0, const string stubMref = "", const string srefsFmncKToolchar = "", const string titsSrefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string titsDefSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "", const string titsOptSrefsFmncKSteppar = "");

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
  * ListFmncQTtyMNTool
  */
class ListFmncQTtyMNTool {

public:
	ListFmncQTtyMNTool();
	ListFmncQTtyMNTool(const ListFmncQTtyMNTool& src);
	ListFmncQTtyMNTool& operator=(const ListFmncQTtyMNTool& src);
	~ListFmncQTtyMNTool();

	void clear();

public:
	vector<FmncQTtyMNTool*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

