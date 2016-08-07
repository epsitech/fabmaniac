/**
  * \file FmncQTolRef1NFile.h
  * API code for table TblFmncQTolRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLREF1NFILE_H
#define FMNCQTOLREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolRef1NFile
  */
class FmncQTolRef1NFile {

public:
	FmncQTolRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQTolRef1NFile
  */
class ListFmncQTolRef1NFile {

public:
	ListFmncQTolRef1NFile();
	ListFmncQTolRef1NFile(const ListFmncQTolRef1NFile& src);
	ListFmncQTolRef1NFile& operator=(const ListFmncQTolRef1NFile& src);
	~ListFmncQTolRef1NFile();

	void clear();

public:
	vector<FmncQTolRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

