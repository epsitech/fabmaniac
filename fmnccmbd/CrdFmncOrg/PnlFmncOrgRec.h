/**
  * \file PnlFmncOrgRec.h
  * job handler for job PnlFmncOrgRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCORGREC_H
#define PNLFMNCORGREC_H

// IP custInclude --- INSERT

#include "PnlFmncOrgDetail.h"
#include "PnlFmncOrgKStocklcn.h"
#include "PnlFmncOrgADetail.h"
#include "PnlFmncOrgBio1NFabproject.h"
#include "PnlFmncOrgMnf1NTool.h"
#include "PnlFmncOrg1NArticle.h"
#include "PnlFmncOrgPco1NPurchorder.h"
#include "PnlFmncOrgSpl1NPurchorder.h"
#include "PnlFmncOrg1NStockitem.h"
#include "PnlFmncOrgSup1NOrg.h"
#include "PnlFmncOrgHk1NAddress.h"
#include "PnlFmncOrgMNPerson.h"
#include "PnlFmncOrgSvcMNTool.h"
#include "PnlFmncOrgMNArticle.h"

/**
  * PnlFmncOrgRec
  */
class PnlFmncOrgRec : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncOrgRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncOrgRec)
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
		* StatApp (full: StatAppFmncOrgRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneKStocklcn = false, const bool initdoneADetail = false, const bool initdoneBio1NFabproject = false, const bool initdoneMnf1NTool = false, const bool initdone1NArticle = false, const bool initdonePco1NPurchorder = false, const bool initdoneSpl1NPurchorder = false, const bool initdone1NStockitem = false, const bool initdoneSup1NOrg = false, const bool initdoneHk1NAddress = false, const bool initdoneMNPerson = false, const bool initdoneSvcMNTool = false, const bool initdoneMNArticle = false);
	};

	/**
		* StatShr (full: StatShrFmncOrgRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFKSTOCKLCN = 3;
		static const uint JREFADETAIL = 4;
		static const uint JREFBIO1NFABPROJECT = 5;
		static const uint JREFMNF1NTOOL = 6;
		static const uint JREF1NARTICLE = 7;
		static const uint JREFPCO1NPURCHORDER = 8;
		static const uint JREFSPL1NPURCHORDER = 9;
		static const uint JREF1NSTOCKITEM = 10;
		static const uint JREFSUP1NORG = 11;
		static const uint JREFHK1NADDRESS = 12;
		static const uint JREFMNPERSON = 13;
		static const uint JREFSVCMNTOOL = 14;
		static const uint JREFMNARTICLE = 15;
		static const uint BUTREGULARIZEACTIVE = 16;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefKStocklcn = 0, const ubigint jrefADetail = 0, const ubigint jrefBio1NFabproject = 0, const ubigint jrefMnf1NTool = 0, const ubigint jref1NArticle = 0, const ubigint jrefPco1NPurchorder = 0, const ubigint jrefSpl1NPurchorder = 0, const ubigint jref1NStockitem = 0, const ubigint jrefSup1NOrg = 0, const ubigint jrefHk1NAddress = 0, const ubigint jrefMNPerson = 0, const ubigint jrefSvcMNTool = 0, const ubigint jrefMNArticle = 0, const bool ButRegularizeActive = true);

	public:
		uint ixFmncVExpstate;
		ubigint jrefDetail;
		ubigint jrefKStocklcn;
		ubigint jrefADetail;
		ubigint jrefBio1NFabproject;
		ubigint jrefMnf1NTool;
		ubigint jref1NArticle;
		ubigint jrefPco1NPurchorder;
		ubigint jrefSpl1NPurchorder;
		ubigint jref1NStockitem;
		ubigint jrefSup1NOrg;
		ubigint jrefHk1NAddress;
		ubigint jrefMNPerson;
		ubigint jrefSvcMNTool;
		ubigint jrefMNArticle;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncOrgRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppFmncOrgRecDo)
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
		* DpchEngData (full: DpchEngFmncOrgRecData)
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
	PnlFmncOrgRec(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncOrgRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlFmncOrgDetail* pnldetail;
	PnlFmncOrgKStocklcn* pnlkstocklcn;
	PnlFmncOrgADetail* pnladetail;
	PnlFmncOrgBio1NFabproject* pnlbio1nfabproject;
	PnlFmncOrgMnf1NTool* pnlmnf1ntool;
	PnlFmncOrg1NArticle* pnl1narticle;
	PnlFmncOrgPco1NPurchorder* pnlpco1npurchorder;
	PnlFmncOrgSpl1NPurchorder* pnlspl1npurchorder;
	PnlFmncOrg1NStockitem* pnl1nstockitem;
	PnlFmncOrgSup1NOrg* pnlsup1norg;
	PnlFmncOrgHk1NAddress* pnlhk1naddress;
	PnlFmncOrgMNPerson* pnlmnperson;
	PnlFmncOrgSvcMNTool* pnlsvcmntool;
	PnlFmncOrgMNArticle* pnlmnarticle;

	FmncMOrg recOrg;

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

	bool handleCallFmncOrgUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


