/**
  * \file FmncQStpAPar.h
  * API code for table TblFmncQStpAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPAPAR_H
#define FMNCQSTPAPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpAPar
  */
class FmncQStpAPar {

public:
	FmncQStpAPar(const uint jnum = 0, const string x1OsrefFmncKSteppar = "", const string titX1OsrefFmncKSteppar = "", const string srefX2IxVTbl = "", const string titX2IxVTbl = "", const string stubX2Uref = "", const string Val = "", const string Comment = "");

public:
	uint jnum;
	string x1OsrefFmncKSteppar;
	string titX1OsrefFmncKSteppar;
	string srefX2IxVTbl;
	string titX2IxVTbl;
	string stubX2Uref;
	string Val;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQStpAPar
  */
class ListFmncQStpAPar {

public:
	ListFmncQStpAPar();
	ListFmncQStpAPar(const ListFmncQStpAPar& src);
	ListFmncQStpAPar& operator=(const ListFmncQStpAPar& src);
	~ListFmncQStpAPar();

	void clear();

public:
	vector<FmncQStpAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

