/**
  * \file PnlFmncSepRec.h
  * job handler for job PnlFmncSepRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSEPREC_H
#define PNLFMNCSEPREC_H

// IP custInclude --- INSERT

#include "PnlFmncSepDetail.h"
#include "PnlFmncSepAPar.h"
#include "PnlFmncSepRef1NFile.h"
#include "PnlFmncSepMNFile.h"
#include "PnlFmncSepMNSample.h"

/**
  * PnlFmncSepRec
  */
class PnlFmncSepRec : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncSepRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncSepRec)
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
		* StatApp (full: StatAppFmncSepRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAPar = false, const bool initdoneRef1NFile = false, const bool initdoneMNFile = false, const bool initdoneMNSample = false);
	};

	/**
		* StatShr (full: StatShrFmncSepRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFAPAR = 3;
		static const uint JREFREF1NFILE = 4;
		static const uint JREFMNFILE = 5;
		static const uint JREFMNSAMPLE = 6;
		static const uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefAPar = 0, const ubigint jrefRef1NFile = 0, const ubigint jrefMNFile = 0, const ubigint jrefMNSample = 0, const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		ubigint jrefDetail;
		ubigint jrefAPar;
		ubigint jrefRef1NFile;
		ubigint jrefMNFile;
		ubigint jrefMNSample;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncSepRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppFmncSepRecDo)
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
		* DpchEngData (full: DpchEngFmncSepRecData)
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
	PnlFmncSepRec(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncSepRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlFmncSepDetail* pnldetail;
	PnlFmncSepAPar* pnlapar;
	PnlFmncSepRef1NFile* pnlref1nfile;
	PnlFmncSepMNFile* pnlmnfile;
	PnlFmncSepMNSample* pnlmnsample;

	FmncMStep recSte;

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

	bool handleCallFmncSteUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


