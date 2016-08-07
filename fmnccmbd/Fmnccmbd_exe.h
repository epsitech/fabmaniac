/**
  * \file Fmnccmbd_exe.h
  * Fmnc combined daemon main (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCCMBD_EXE_H
#define FMNCCMBD_EXE_H

#include <string>
#include <vector>

using namespace std;

#include <signal.h>

#include "FmnccmbdAppsrv.h"
#include "FmnccmbdJobprc.h"
#include "FmnccmbdOpprc.h"

/**
  * PrefFmnccmbd
  */
class PrefFmnccmbd : public Block {

public:
	static const uint STGFMNCCMBD = 1;
	static const uint STGFMNCDATABASE = 2;
	static const uint STGFMNCMONITOR = 3;
	static const uint STGFMNCPATH = 4;
	static const uint ALL = 5;

public:
	PrefFmnccmbd(StgFmnccmbd* stgfmnccmbd = NULL, StgFmncDatabase* stgfmncdatabase = NULL, StgFmncMonitor* stgfmncmonitor = NULL, StgFmncPath* stgfmncpath = NULL, const set<uint>& mask = {ALL});

public:
	StgFmnccmbd stgfmnccmbd;
	StgFmncDatabase stgfmncdatabase;
	StgFmncMonitor stgfmncmonitor;
	StgFmncPath stgfmncpath;

public:
	static bool all(const set<uint>& items);

	void readXMLFromFile(const string& fullpath);
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXMLToFile(const string& fullpath);
	void writeXML(xmlTextWriter* wr);
};

/**
  * Fmnccmbd
  */
class Fmnccmbd {

public:
	Fmnccmbd(const string& exedir);
	~Fmnccmbd();

	void init();
	bool initdone;
	void term();

public:
	string exedir;

	unsigned int jrefCmd;

	DbsFmnc dbsfmnc;

	XchgFmnccmbd* xchg;
	
	RootFmnc* root;

	MHD_Daemon* appsrv;

	vector<pthread_t> jobprcs;

	vector<pthread_t> opprcs;

public:
	void loadPref();
	void storePref();

	void initXchgdataJobprc();
	void termXchgdataJobprc();

	void initXchgdataOpprc();
	void termXchgdataOpprc();
};

Fmnccmbd* fmnccmbd;

#endif


