/**
  * \file FmncQTolKToolchar.h
  * API code for table TblFmncQTolKToolchar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLKTOOLCHAR_H
#define FMNCQTOLKTOOLCHAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolKToolchar
  */
class FmncQTolKToolchar {

public:
	FmncQTolKToolchar(const uint jnum = 0, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const string Title = "", const string Comment = "");

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
  * ListFmncQTolKToolchar
  */
class ListFmncQTolKToolchar {

public:
	ListFmncQTolKToolchar();
	ListFmncQTolKToolchar(const ListFmncQTolKToolchar& src);
	ListFmncQTolKToolchar& operator=(const ListFmncQTolKToolchar& src);
	~ListFmncQTolKToolchar();

	void clear();

public:
	vector<FmncQTolKToolchar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

