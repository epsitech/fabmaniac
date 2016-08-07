/**
  * \file FmncQTolARes.h
  * API code for table TblFmncQTolARes (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLARES_H
#define FMNCQTOLARES_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolARes
  */
class FmncQTolARes {

public:
	FmncQTolARes(const uint jnum = 0, const string stubX1RefFmncMFabuser = "", const string ftmStartd = "", const string ftmStartt = "", const string ftmStopt = "", const string srefKRestype = "", const string titSrefKRestype = "", const string Comment = "");

public:
	uint jnum;
	string stubX1RefFmncMFabuser;
	string ftmStartd;
	string ftmStartt;
	string ftmStopt;
	string srefKRestype;
	string titSrefKRestype;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolARes
  */
class ListFmncQTolARes {

public:
	ListFmncQTolARes();
	ListFmncQTolARes(const ListFmncQTolARes& src);
	ListFmncQTolARes& operator=(const ListFmncQTolARes& src);
	~ListFmncQTolARes();

	void clear();

public:
	vector<FmncQTolARes*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

