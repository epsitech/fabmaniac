/**
  * \file FmncQArtRef1NFile.h
  * API code for table TblFmncQArtRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQARTREF1NFILE_H
#define FMNCQARTREF1NFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArtRef1NFile
  */
class FmncQArtRef1NFile {

public:
	FmncQArtRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQArtRef1NFile
  */
class ListFmncQArtRef1NFile {

public:
	ListFmncQArtRef1NFile();
	ListFmncQArtRef1NFile(const ListFmncQArtRef1NFile& src);
	ListFmncQArtRef1NFile& operator=(const ListFmncQArtRef1NFile& src);
	~ListFmncQArtRef1NFile();

	void clear();

public:
	vector<FmncQArtRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

