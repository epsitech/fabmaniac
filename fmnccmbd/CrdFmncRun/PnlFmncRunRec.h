/**
  * \file PnlFmncRunRec.h
  * job handler for job PnlFmncRunRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCRUNREC_H
#define PNLFMNCRUNREC_H

// IP custInclude --- INSERT

#include "PnlFmncRunDetail.h"
#include "PnlFmncRunRun1NActivity.h"
#include "PnlFmncRunRef1NFile.h"
#include "PnlFmncRunMNSample.h"
#include "PnlFmncRunMNPerson.h"
#include "PnlFmncRunMNFab.h"

/**
  * PnlFmncRunRec
  */
class PnlFmncRunRec : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncRunRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncRunRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncRunRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneRun1NActivity = false, const bool initdoneRef1NFile = false, const bool initdoneMNSample = false, const bool initdoneMNPerson = false, const bool initdoneMNFab = false);
	};

	/**
		* StatShr (full: StatShrFmncRunRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFRUN1NACTIVITY = 3;
		static const uint JREFREF1NFILE = 4;
		static const uint JREFMNSAMPLE = 5;
		static const uint JREFMNPERSON = 6;
		static const uint JREFMNFAB = 7;
		static const uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefRun1NActivity = 0, const ubigint jrefRef1NFile = 0, const ubigint jrefMNSample = 0, const ubigint jrefMNPerson = 0, const ubigint jrefMNFab = 0, const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		ubigint jrefDetail;
		ubigint jrefRun1NActivity;
		ubigint jrefRef1NFile;
		ubigint jrefMNSample;
		ubigint jrefMNPerson;
		ubigint jrefMNFab;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncRunRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppFmncRunRecDo)
		*/
	class DpchAppDo : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngFmncRunRecData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;
		static const uint ALL = 6;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncRunRec(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncRunRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlFmncRunDetail* pnldetail;
	PnlFmncRunRun1NActivity* pnlrun1nactivity;
	PnlFmncRunRef1NFile* pnlref1nfile;
	PnlFmncRunMNSample* pnlmnsample;
	PnlFmncRunMNPerson* pnlmnperson;
	PnlFmncRunMNFab* pnlmnfab;

	FmncMRun recRun;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);
	void minimize(DbsFmnc* dbsfmnc, const bool notif = false, DpchEngFmnc** dpcheng = NULL);
	void regularize(DbsFmnc* dbsfmnc, const bool notif = false, DpchEngFmnc** dpcheng = NULL);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncRunUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


