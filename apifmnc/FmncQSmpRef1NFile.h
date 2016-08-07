/**
  * \file FmncQSmpRef1NFile.h
  * API code for table TblFmncQSmpRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPREF1NFILE_H
#define FMNCQSMPREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpRef1NFile
  */
class FmncQSmpRef1NFile {

public:
	FmncQSmpRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSmpRef1NFile
  */
class ListFmncQSmpRef1NFile {

public:
	ListFmncQSmpRef1NFile();
	ListFmncQSmpRef1NFile(const ListFmncQSmpRef1NFile& src);
	ListFmncQSmpRef1NFile& operator=(const ListFmncQSmpRef1NFile& src);
	~ListFmncQSmpRef1NFile();

	void clear();

public:
	vector<FmncQSmpRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

