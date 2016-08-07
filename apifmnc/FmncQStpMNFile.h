/**
  * \file FmncQStpMNFile.h
  * API code for table TblFmncQStpMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPMNFILE_H
#define FMNCQSTPMNFILE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpMNFile
  */
class FmncQStpMNFile {

public:
	FmncQStpMNFile(const uint jnum = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const string srefIxVDir = "", const string titIxVDir = "");

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
  * ListFmncQStpMNFile
  */
class ListFmncQStpMNFile {

public:
	ListFmncQStpMNFile();
	ListFmncQStpMNFile(const ListFmncQStpMNFile& src);
	ListFmncQStpMNFile& operator=(const ListFmncQStpMNFile& src);
	~ListFmncQStpMNFile();

	void clear();

public:
	vector<FmncQStpMNFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

