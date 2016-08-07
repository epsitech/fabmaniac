/**
  * \file PnlFmncTolRec.h
  * job handler for job PnlFmncTolRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCTOLREC_H
#define PNLFMNCTOLREC_H

// IP custInclude --- INSERT

#include "PnlFmncTolDetail.h"
#include "PnlFmncTolKSteppar.h"
#include "PnlFmncTolKToolchar.h"
#include "PnlFmncTolAAvl.h"
#include "PnlFmncTolAChar.h"
#include "PnlFmncTolARes.h"
#include "PnlFmncTolAUtil.h"
#include "PnlFmncTol1NArticle.h"
#include "PnlFmncTolRlv1NStep.h"
#include "PnlFmncTolRef1NFile.h"
#include "PnlFmncTolMNTooltype.h"
#include "PnlFmncTolMNFabuser.h"
#include "PnlFmncTolSvcMNOrg.h"

/**
  * PnlFmncTolRec
  */
class PnlFmncTolRec : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncTolRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncTolRec)
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
		* StatApp (full: StatAppFmncTolRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneKSteppar = false, const bool initdoneKToolchar = false, const bool initdoneAAvl = false, const bool initdoneAChar = false, const bool initdoneARes = false, const bool initdoneAUtil = false, const bool initdone1NArticle = false, const bool initdoneRlv1NStep = false, const bool initdoneRef1NFile = false, const bool initdoneMNTooltype = false, const bool initdoneMNFabuser = false, const bool initdoneSvcMNOrg = false);
	};

	/**
		* StatShr (full: StatShrFmncTolRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFKSTEPPAR = 3;
		static const uint JREFKTOOLCHAR = 4;
		static const uint JREFAAVL = 5;
		static const uint JREFACHAR = 6;
		static const uint JREFARES = 7;
		static const uint JREFAUTIL = 8;
		static const uint JREF1NARTICLE = 9;
		static const uint JREFRLV1NSTEP = 10;
		static const uint JREFREF1NFILE = 11;
		static const uint JREFMNTOOLTYPE = 12;
		static const uint JREFMNFABUSER = 13;
		static const uint JREFSVCMNORG = 14;
		static const uint BUTREGULARIZEACTIVE = 15;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefKSteppar = 0, const ubigint jrefKToolchar = 0, const ubigint jrefAAvl = 0, const ubigint jrefAChar = 0, const ubigint jrefARes = 0, const ubigint jrefAUtil = 0, const ubigint jref1NArticle = 0, const ubigint jrefRlv1NStep = 0, const ubigint jrefRef1NFile = 0, const ubigint jrefMNTooltype = 0, const ubigint jrefMNFabuser = 0, const ubigint jrefSvcMNOrg = 0, const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		ubigint jrefDetail;
		ubigint jrefKSteppar;
		ubigint jrefKToolchar;
		ubigint jrefAAvl;
		ubigint jrefAChar;
		ubigint jrefARes;
		ubigint jrefAUtil;
		ubigint jref1NArticle;
		ubigint jrefRlv1NStep;
		ubigint jrefRef1NFile;
		ubigint jrefMNTooltype;
		ubigint jrefMNFabuser;
		ubigint jrefSvcMNOrg;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncTolRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppFmncTolRecDo)
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
		* DpchEngData (full: DpchEngFmncTolRecData)
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
	PnlFmncTolRec(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncTolRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlFmncTolDetail* pnldetail;
	PnlFmncTolKSteppar* pnlksteppar;
	PnlFmncTolKToolchar* pnlktoolchar;
	PnlFmncTolAAvl* pnlaavl;
	PnlFmncTolAChar* pnlachar;
	PnlFmncTolARes* pnlares;
	PnlFmncTolAUtil* pnlautil;
	PnlFmncTol1NArticle* pnl1narticle;
	PnlFmncTolRlv1NStep* pnlrlv1nstep;
	PnlFmncTolRef1NFile* pnlref1nfile;
	PnlFmncTolMNTooltype* pnlmntooltype;
	PnlFmncTolMNFabuser* pnlmnfabuser;
	PnlFmncTolSvcMNOrg* pnlsvcmnorg;

	FmncMTool recTol;

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

	bool handleCallFmncTolUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


