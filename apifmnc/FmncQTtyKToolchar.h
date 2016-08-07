/**
  * \file FmncQTtyKToolchar.h
  * API code for table TblFmncQTtyKToolchar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYKTOOLCHAR_H
#define FMNCQTTYKTOOLCHAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyKToolchar
  */
class FmncQTtyKToolchar {

public:
	FmncQTtyKToolchar(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

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
  * ListFmncQTtyKToolchar
  */
class ListFmncQTtyKToolchar {

public:
	ListFmncQTtyKToolchar();
	ListFmncQTtyKToolchar(const ListFmncQTtyKToolchar& src);
	ListFmncQTtyKToolchar& operator=(const ListFmncQTtyKToolchar& src);
	~ListFmncQTtyKToolchar();

	void clear();

public:
	vector<FmncQTtyKToolchar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

