/**
  * \file PnlFmncSkiRec.h
  * job handler for job PnlFmncSkiRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSKIREC_H
#define PNLFMNCSKIREC_H

// IP custInclude --- INSERT

#include "PnlFmncSkiDetail.h"

/**
  * PnlFmncSkiRec
  */
class PnlFmncSkiRec : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncSkiRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncSkiRec)
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
		* StatApp (full: StatAppFmncSkiRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false);
	};

	/**
		* StatShr (full: StatShrFmncSkiRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint BUTREGULARIZEACTIVE = 3;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const ubigint jrefDetail = 0, const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		ubigint jrefDetail;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncSkiRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppFmncSkiRecDo)
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
		* DpchEngData (full: DpchEngFmncSkiRecData)
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
	PnlFmncSkiRec(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncSkiRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlFmncSkiDetail* pnldetail;

	FmncMStockitem recSki;

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

	bool handleCallFmncSkiUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


