/**
  * \file FmncQTolAUtil.h
  * API code for table TblFmncQTolAUtil (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLAUTIL_H
#define FMNCQTOLAUTIL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolAUtil
  */
class FmncQTolAUtil {

public:
	FmncQTolAUtil(const uint jnum = 0, const string stubX1RefFmncMFabproject = "", const string stubX2RefFmncMFabuser = "", const string ftmStartd = "", const string ftmStartt = "", const string ftmStopt = "", const double Unitprice = 0.0, const string Comment = "");

public:
	uint jnum;
	string stubX1RefFmncMFabproject;
	string stubX2RefFmncMFabuser;
	string ftmStartd;
	string ftmStartt;
	string ftmStopt;
	double Unitprice;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolAUtil
  */
class ListFmncQTolAUtil {

public:
	ListFmncQTolAUtil();
	ListFmncQTolAUtil(const ListFmncQTolAUtil& src);
	ListFmncQTolAUtil& operator=(const ListFmncQTolAUtil& src);
	~ListFmncQTolAUtil();

	void clear();

public:
	vector<FmncQTolAUtil*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

