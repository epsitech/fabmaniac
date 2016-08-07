/**
  * \file FmncQTolAChar.h
  * API code for table TblFmncQTolAChar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLACHAR_H
#define FMNCQTOLACHAR_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolAChar
  */
class FmncQTolAChar {

public:
	FmncQTolAChar(const uint jnum = 0, const string x1OsrefFmncKToolchar = "", const string titX1OsrefFmncKToolchar = "", const string Val = "", const string Comment = "");

public:
	uint jnum;
	string x1OsrefFmncKToolchar;
	string titX1OsrefFmncKToolchar;
	string Val;
	string Comment;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolAChar
  */
class ListFmncQTolAChar {

public:
	ListFmncQTolAChar();
	ListFmncQTolAChar(const ListFmncQTolAChar& src);
	ListFmncQTolAChar& operator=(const ListFmncQTolAChar& src);
	~ListFmncQTolAChar();

	void clear();

public:
	vector<FmncQTolAChar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

