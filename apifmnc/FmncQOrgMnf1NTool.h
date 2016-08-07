/**
  * \file FmncQOrgMnf1NTool.h
  * API code for table TblFmncQOrgMnf1NTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGMNF1NTOOL_H
#define FMNCQORGMNF1NTOOL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgMnf1NTool
  */
class FmncQOrgMnf1NTool {

public:
	FmncQOrgMnf1NTool(const uint jnum = 0, const string stubRef = "", const string stubsSrefFmncMPerson = "");

public:
	uint jnum;
	string stubRef;
	string stubsSrefFmncMPerson;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgMnf1NTool
  */
class ListFmncQOrgMnf1NTool {

public:
	ListFmncQOrgMnf1NTool();
	ListFmncQOrgMnf1NTool(const ListFmncQOrgMnf1NTool& src);
	ListFmncQOrgMnf1NTool& operator=(const ListFmncQOrgMnf1NTool& src);
	~ListFmncQOrgMnf1NTool();

	void clear();

public:
	vector<FmncQOrgMnf1NTool*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

