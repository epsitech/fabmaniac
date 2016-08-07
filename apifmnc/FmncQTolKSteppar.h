/**
  * \file FmncQTolKSteppar.h
  * API code for table TblFmncQTolKSteppar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLKSTEPPAR_H
#define FMNCQTOLKSTEPPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolKSteppar
  */
class FmncQTolKSteppar {

public:
	FmncQTolKSteppar(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

public:
	uint jnum;
	string yesnoFixed;
	string sref;
	string Avail;
	string Implied;
	string Title;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolKSteppar
  */
class ListFmncQTolKSteppar {

public:
	ListFmncQTolKSteppar();
	ListFmncQTolKSteppar(const ListFmncQTolKSteppar& src);
	ListFmncQTolKSteppar& operator=(const ListFmncQTolKSteppar& src);
	~ListFmncQTolKSteppar();

	void clear();

public:
	vector<FmncQTolKSteppar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

