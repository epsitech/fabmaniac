/**
  * \file FmncQSepAPar.h
  * API code for table TblFmncQSepAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPAPAR_H
#define FMNCQSEPAPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepAPar
  */
class FmncQSepAPar {

public:
	FmncQSepAPar(const uint jnum = 0, const string x1OsrefFmncKSteppar = "", const string titX1OsrefFmncKSteppar = "", const string srefX2IxVTbl = "", const string titX2IxVTbl = "", const string stubX2Uref = "", const string Val = "", const string Comment = "");

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
  * ListFmncQSepAPar
  */
class ListFmncQSepAPar {

public:
	ListFmncQSepAPar();
	ListFmncQSepAPar(const ListFmncQSepAPar& src);
	ListFmncQSepAPar& operator=(const ListFmncQSepAPar& src);
	~ListFmncQSepAPar();

	void clear();

public:
	vector<FmncQSepAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

