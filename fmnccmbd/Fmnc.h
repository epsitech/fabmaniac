/**
  * \file Fmnc.h
  * Fmnc global functionality (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNC_H
#define FMNC_H

// IP incl --- INSERT

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include "VecFmncVCall.h"
#include "VecFmncVDpch.h"
#include "VecFmncVExpstate.h"
#include "VecFmncVIop.h"
#include "VecFmncVJob.h"
#include "VecFmncVMimetype.h"
#include "VecFmncVQrystate.h"
#include "VecFmncVRepdisp.h"
#include "VecFmncVRepfsp.h"
#include "VecFmncVRepssp.h"
#include "VecFmncVReqitmode.h"
#include "VecFmncVStub.h"
#include "VecFmncVTag.h"

#include <DbsFmnc.h>

#include <dartcore/Stub.h>

// IP acv --- BEGIN
/**
  * Acv
  */
namespace Acv {
	ubigint addfile(DbsFmnc* dbsfmnc, const string& acvpath, const string& path, const uint refIxVTbl, const ubigint refUref, const string& osrefKContent, const string& Filename, const string& srefKMimetype, const string& Comment);
	void alterfile(DbsFmnc* dbsfmnc, const string& acvpath, const string& path, const ubigint ref);
	string getfile(DbsFmnc* dbsfmnc, const ubigint refFmncMFile);
};
// IP acv --- END

/**
  * Lop
  */
namespace Lop {
	void apply(const uint ixFmncVLop, vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);

	void insert(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
	void remove(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
};

/**
  * Oolop
  */
namespace Oolop {
	void apply(const uint ixFmncVOolop, vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);

	void insertBefore(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);
	void insertAfter(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);
	void remove(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
	void toBefore(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
	void toAfter(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
	void swap(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
};

/**
  * Tmp
  */
namespace Tmp {
	string newfile(const string& tmppath, const string& ext);
	string newfolder(const string& tmppath);
	string random();
};

// IP cust --- INSERT

/**
  * Fmnc
  */
namespace Fmnc {
// IP gbl --- INSERT
};

/**
  * StubFmnc
  */
namespace StubFmnc {
	string getStub(DbsFmnc* dbsfmnc, const uint ixFmncVStub, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);

	string getStubActStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubAdrStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubArtStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubBilStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubFabSref(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubFabStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubFilStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubFpjStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubFusStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubGrp(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubOrgHsref(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubOrgSref(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubOrgStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubOwn(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubPcoStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubPrjStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubPrsStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubPrsWorg(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubRunStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSepStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSesMenu(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSesStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSkiStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSmpHsref(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSmpStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSteStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubTolStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubTtyStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubUsgStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubUsrStd(DbsFmnc* dbsfmnc, const ubigint ref, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
};

/**
  * FmncException
  */
struct FmncException {
	string err;

	FmncException(string err) {
		this->err = err;
	};
};

/**
	* ContInfFmncAlert
	*/
class ContInfFmncAlert : public Block {

public:
	static const uint TXTCPT = 1;
	static const uint TXTMSG1 = 2;
	static const uint TXTMSG2 = 3;
	static const uint TXTMSG3 = 4;
	static const uint TXTMSG4 = 5;
	static const uint TXTMSG5 = 6;
	static const uint TXTMSG6 = 7;
	static const uint TXTMSG7 = 8;
	static const uint TXTMSG8 = 9;
	static const uint TXTMSG9 = 10;
	static const uint TXTMSG10 = 11;

public:
	ContInfFmncAlert(const string& TxtCpt = "", const string& TxtMsg1 = "", const string& TxtMsg2 = "", const string& TxtMsg3 = "", const string& TxtMsg4 = "", const string& TxtMsg5 = "", const string& TxtMsg6 = "", const string& TxtMsg7 = "", const string& TxtMsg8 = "", const string& TxtMsg9 = "", const string& TxtMsg10 = "");

public:
	string TxtCpt;
	string TxtMsg1;
	string TxtMsg2;
	string TxtMsg3;
	string TxtMsg4;
	string TxtMsg5;
	string TxtMsg6;
	string TxtMsg7;
	string TxtMsg8;
	string TxtMsg9;
	string TxtMsg10;

public:
	static bool all(const set<uint>& items);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> compare(const ContInfFmncAlert* comp);
};

/**
  * DpchFmnc
  */
class DpchFmnc : public Block {

public:
	DpchFmnc(const uint ixFmncVDpch = 0);
	virtual ~DpchFmnc();

public:
	uint ixFmncVDpch;
};

/**
  * DpchInvFmnc
  */
class DpchInvFmnc : public DpchFmnc {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALL = 3;

public:
	DpchInvFmnc(const uint ixFmncVDpch = VecFmncVDpch::DPCHINVFMNC, const ubigint oref = 0, const ubigint jref = 0, const set<uint>& mask = {ALL});
	virtual ~DpchInvFmnc();

public:
	string scrOref;
	ubigint oref;
	string scrJref;
	ubigint jref;

public:
	static bool all(const set<uint>& items);

	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	virtual void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetFmnc
  */
class DpchRetFmnc : public DpchFmnc {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint ALL = 4;

public:
	DpchRetFmnc(const uint ixFmncVDpch = VecFmncVDpch::DPCHRETFMNC, const string& scrOref = "", const string& scrJref = "", const bool success = false, const set<uint>& mask = {ALL});
	virtual ~DpchRetFmnc();

public:
	string scrOref;
	ubigint oref;
	string scrJref;
	ubigint jref;
	bool success;

public:
	static bool all(const set<uint>& items);

	virtual void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif


