/**
  * \file FmncQSepMNFile.h
  * API code for table TblFmncQSepMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPMNFILE_H
#define FMNCQSEPMNFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepMNFile
  */
class FmncQSepMNFile {

public:
	FmncQSepMNFile(const uint jnum = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const string srefIxVDir = "", const string titIxVDir = "");

public:
	uint jnum;
	string stubMref;
	string stubsTrefFmncMSample;
	string srefIxVDir;
	string titIxVDir;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListFmncQSepMNFile
  */
class ListFmncQSepMNFile {

public:
	ListFmncQSepMNFile();
	ListFmncQSepMNFile(const ListFmncQSepMNFile& src);
	ListFmncQSepMNFile& operator=(const ListFmncQSepMNFile& src);
	~ListFmncQSepMNFile();

	void clear();

public:
	vector<FmncQSepMNFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

