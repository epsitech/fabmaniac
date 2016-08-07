/**
  * \file SessFmnc.h
  * job handler for job SessFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef SESSFMNC_H
#define SESSFMNC_H

// IP custInclude --- INSERT

#include "CrdFmncNav.h"
#include "CrdFmncUsg.h"
#include "CrdFmncUsr.h"
#include "CrdFmncOrg.h"
#include "CrdFmncPrs.h"
#include "CrdFmncAdr.h"
#include "CrdFmncFil.h"
#include "CrdFmncStp.h"
#include "CrdFmncPrj.h"
#include "CrdFmncRun.h"
#include "CrdFmncAct.h"
#include "CrdFmncSep.h"
#include "CrdFmncSmp.h"
#include "CrdFmncFab.h"
#include "CrdFmncFus.h"
#include "CrdFmncTty.h"
#include "CrdFmncTol.h"
#include "CrdFmncFpj.h"
#include "CrdFmncBil.h"
#include "CrdFmncArt.h"
#include "CrdFmncSki.h"
#include "CrdFmncPco.h"

/**
  * SessFmnc
  */
class SessFmnc : public JobFmnc {

public:
	/**
		* StatShr (full: StatShrSessFmnc)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFCRDNAV = 1;

	public:
		StatShr(const ubigint jrefCrdnav = 0);

	public:
		ubigint jrefCrdnav;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessFmncData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint STATSHR = 2;
		static const uint ALL = 3;

	public:
		DpchEngData(const ubigint jref = 0, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	SessFmnc(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const ubigint refFmncMUser, const string& ip);
	~SessFmnc();

public:
	StatShr statshr;

	CrdFmncNav* crdnav;
	list<CrdFmncUsg*> crdusgs;
	list<CrdFmncUsr*> crdusrs;
	list<CrdFmncOrg*> crdorgs;
	list<CrdFmncPrs*> crdprss;
	list<CrdFmncAdr*> crdadrs;
	list<CrdFmncFil*> crdfils;
	list<CrdFmncStp*> crdstps;
	list<CrdFmncPrj*> crdprjs;
	list<CrdFmncRun*> crdruns;
	list<CrdFmncAct*> crdacts;
	list<CrdFmncSep*> crdseps;
	list<CrdFmncSmp*> crdsmps;
	list<CrdFmncFab*> crdfabs;
	list<CrdFmncFus*> crdfuss;
	list<CrdFmncTty*> crdttys;
	list<CrdFmncTol*> crdtols;
	list<CrdFmncFpj*> crdfpjs;
	list<CrdFmncBil*> crdbils;
	list<CrdFmncArt*> crdarts;
	list<CrdFmncSki*> crdskis;
	list<CrdFmncPco*> crdpcos;

	map<ubigint, uint> usgaccs;

	map<ubigint,string> scr;
	map<string,ubigint> descr;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	uint checkCrdActive(const uint ixFmncVCard);
	uint evalCrdactActive();
	uint evalCrdsepActive();
	uint evalCrdfusActive();
	uint evalCrdtolActive();
	uint evalCrdfpjActive();
	uint evalCrdbilActive();

	uint checkUiaccess(const uint ixFmncVCard);
	uint getIxUac(DbsFmnc* dbsfmnc, const uint ixFmncVCard, const bool adm, ListFmncRMUserMUsergroup& urus, const ubigint refFmncMUser);

	uint checkAccess(DbsFmnc* dbsfmnc, const uint ixFmncVCard, const ubigint ref);
	void logAccess(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint preUref, const uint ixFmncVCard, const ubigint unvUref);

	uint crdToMtb(const uint ixFmncVCard);
	uint preToMtb(const uint ixFmncVPreset);
	bool hasActive(const uint ixFmncVCard);
	bool hasGrpown(const uint ixFmncVMaintable);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	bool handleCreateCrdact(DbsFmnc* dbsfmnc);
	bool handleCreateCrdadr(DbsFmnc* dbsfmnc);
	bool handleCreateCrdart(DbsFmnc* dbsfmnc);
	bool handleCreateCrdbil(DbsFmnc* dbsfmnc);
	bool handleCreateCrdfab(DbsFmnc* dbsfmnc);
	bool handleCreateCrdfil(DbsFmnc* dbsfmnc);
	bool handleCreateCrdfpj(DbsFmnc* dbsfmnc);
	bool handleCreateCrdfus(DbsFmnc* dbsfmnc);
	bool handleCreateCrdorg(DbsFmnc* dbsfmnc);
	bool handleCreateCrdpco(DbsFmnc* dbsfmnc);
	bool handleCreateCrdprj(DbsFmnc* dbsfmnc);
	bool handleCreateCrdprs(DbsFmnc* dbsfmnc);
	bool handleCreateCrdrun(DbsFmnc* dbsfmnc);
	bool handleCreateCrdsep(DbsFmnc* dbsfmnc);
	bool handleCreateCrdski(DbsFmnc* dbsfmnc);
	bool handleCreateCrdsmp(DbsFmnc* dbsfmnc);
	bool handleCreateCrdstp(DbsFmnc* dbsfmnc);
	bool handleCreateCrdtol(DbsFmnc* dbsfmnc);
	bool handleCreateCrdtty(DbsFmnc* dbsfmnc);
	bool handleCreateCrdusg(DbsFmnc* dbsfmnc);
	bool handleCreateCrdusr(DbsFmnc* dbsfmnc);
	bool handleEraseCrdact(DbsFmnc* dbsfmnc);
	bool handleEraseCrdadr(DbsFmnc* dbsfmnc);
	bool handleEraseCrdart(DbsFmnc* dbsfmnc);
	bool handleEraseCrdbil(DbsFmnc* dbsfmnc);
	bool handleEraseCrdfab(DbsFmnc* dbsfmnc);
	bool handleEraseCrdfil(DbsFmnc* dbsfmnc);
	bool handleEraseCrdfpj(DbsFmnc* dbsfmnc);
	bool handleEraseCrdfus(DbsFmnc* dbsfmnc);
	bool handleEraseCrdorg(DbsFmnc* dbsfmnc);
	bool handleEraseCrdpco(DbsFmnc* dbsfmnc);
	bool handleEraseCrdprj(DbsFmnc* dbsfmnc);
	bool handleEraseCrdprs(DbsFmnc* dbsfmnc);
	bool handleEraseCrdrun(DbsFmnc* dbsfmnc);
	bool handleEraseCrdsep(DbsFmnc* dbsfmnc);
	bool handleEraseCrdski(DbsFmnc* dbsfmnc);
	bool handleEraseCrdsmp(DbsFmnc* dbsfmnc);
	bool handleEraseCrdstp(DbsFmnc* dbsfmnc);
	bool handleEraseCrdtol(DbsFmnc* dbsfmnc);
	bool handleEraseCrdtty(DbsFmnc* dbsfmnc);
	bool handleEraseCrdusg(DbsFmnc* dbsfmnc);
	bool handleEraseCrdusr(DbsFmnc* dbsfmnc);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncAccess(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, uint& ixRet);
	bool handleCallFmncCrdActive(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, uint& ixRet);
	bool handleCallFmncCrdClose(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv);
	bool handleCallFmncCrdOpen(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv, ubigint& refRet);
	bool handleCallFmncDescr(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const string& srefInv, ubigint& refRet);
	bool handleCallFmncLog(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv);
	bool handleCallFmncScr(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv, string& srefRet);
	bool handleCallFmncRefPreSet(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


