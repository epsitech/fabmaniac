/**
  * \file FmncQRunRef1NFile.h
  * API code for table TblFmncQRunRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNREF1NFILE_H
#define FMNCQRUNREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunRef1NFile
  */
class FmncQRunRef1NFile {

public:
	FmncQRunRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQRunRef1NFile
  */
class ListFmncQRunRef1NFile {

public:
	ListFmncQRunRef1NFile();
	ListFmncQRunRef1NFile(const ListFmncQRunRef1NFile& src);
	ListFmncQRunRef1NFile& operator=(const ListFmncQRunRef1NFile& src);
	~ListFmncQRunRef1NFile();

	void clear();

public:
	vector<FmncQRunRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

