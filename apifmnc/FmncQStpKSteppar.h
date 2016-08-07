/**
  * \file FmncQStpKSteppar.h
  * API code for table TblFmncQStpKSteppar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPKSTEPPAR_H
#define FMNCQSTPKSTEPPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpKSteppar
  */
class FmncQStpKSteppar {

public:
	FmncQStpKSteppar(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

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
  * ListFmncQStpKSteppar
  */
class ListFmncQStpKSteppar {

public:
	ListFmncQStpKSteppar();
	ListFmncQStpKSteppar(const ListFmncQStpKSteppar& src);
	ListFmncQStpKSteppar& operator=(const ListFmncQStpKSteppar& src);
	~ListFmncQStpKSteppar();

	void clear();

public:
	vector<FmncQStpKSteppar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

