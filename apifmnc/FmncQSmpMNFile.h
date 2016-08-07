/**
  * \file FmncQSmpMNFile.h
  * API code for table TblFmncQSmpMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPMNFILE_H
#define FMNCQSMPMNFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpMNFile
  */
class FmncQSmpMNFile {

public:
	FmncQSmpMNFile(const uint jnum = 0, const string stubMref = "");

public:
	uint jnum;
	string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSmpMNFile
  */
class ListFmncQSmpMNFile {

public:
	ListFmncQSmpMNFile();
	ListFmncQSmpMNFile(const ListFmncQSmpMNFile& src);
	ListFmncQSmpMNFile& operator=(const ListFmncQSmpMNFile& src);
	~ListFmncQSmpMNFile();

	void clear();

public:
	vector<FmncQSmpMNFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

