/**
  * \file FmncQOrgSvcMNTool.h
  * API code for table TblFmncQOrgSvcMNTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGSVCMNTOOL_H
#define FMNCQORGSVCMNTOOL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgSvcMNTool
  */
class FmncQOrgSvcMNTool {

public:
	FmncQOrgSvcMNTool(const uint jnum = 0, const string stubMref = "", const string stubsTrefFmncMPerson = "");

public:
	uint jnum;
	string stubMref;
	string stubsTrefFmncMPerson;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQOrgSvcMNTool
  */
class ListFmncQOrgSvcMNTool {

public:
	ListFmncQOrgSvcMNTool();
	ListFmncQOrgSvcMNTool(const ListFmncQOrgSvcMNTool& src);
	ListFmncQOrgSvcMNTool& operator=(const ListFmncQOrgSvcMNTool& src);
	~ListFmncQOrgSvcMNTool();

	void clear();

public:
	vector<FmncQOrgSvcMNTool*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

