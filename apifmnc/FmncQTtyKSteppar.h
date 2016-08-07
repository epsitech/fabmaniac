/**
  * \file FmncQTtyKSteppar.h
  * API code for table TblFmncQTtyKSteppar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYKSTEPPAR_H
#define FMNCQTTYKSTEPPAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyKSteppar
  */
class FmncQTtyKSteppar {

public:
	FmncQTtyKSteppar(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

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
  * ListFmncQTtyKSteppar
  */
class ListFmncQTtyKSteppar {

public:
	ListFmncQTtyKSteppar();
	ListFmncQTtyKSteppar(const ListFmncQTtyKSteppar& src);
	ListFmncQTtyKSteppar& operator=(const ListFmncQTtyKSteppar& src);
	~ListFmncQTtyKSteppar();

	void clear();

public:
	vector<FmncQTtyKSteppar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

