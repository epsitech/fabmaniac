/**
  * \file FmncQStpRef1NFile.h
  * API code for table TblFmncQStpRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPREF1NFILE_H
#define FMNCQSTPREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpRef1NFile
  */
class FmncQStpRef1NFile {

public:
	FmncQStpRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQStpRef1NFile
  */
class ListFmncQStpRef1NFile {

public:
	ListFmncQStpRef1NFile();
	ListFmncQStpRef1NFile(const ListFmncQStpRef1NFile& src);
	ListFmncQStpRef1NFile& operator=(const ListFmncQStpRef1NFile& src);
	~ListFmncQStpRef1NFile();

	void clear();

public:
	vector<FmncQStpRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

