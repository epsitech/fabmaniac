/**
  * \file FmncQSepRef1NFile.h
  * API code for table TblFmncQSepRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPREF1NFILE_H
#define FMNCQSEPREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepRef1NFile
  */
class FmncQSepRef1NFile {

public:
	FmncQSepRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSepRef1NFile
  */
class ListFmncQSepRef1NFile {

public:
	ListFmncQSepRef1NFile();
	ListFmncQSepRef1NFile(const ListFmncQSepRef1NFile& src);
	ListFmncQSepRef1NFile& operator=(const ListFmncQSepRef1NFile& src);
	~ListFmncQSepRef1NFile();

	void clear();

public:
	vector<FmncQSepRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

