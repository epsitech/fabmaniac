/**
  * \file CrdFmncPrj.h
  * job handler for job CrdFmncPrj (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef CRDFMNCPRJ_H
#define CRDFMNCPRJ_H

// IP custInclude --- INSERT

#include "DlgFmncPrjExpelb.h"
#include "DlgFmncPrjImpelb.h"
#include "DlgFmncPrjNew.h"
#include "PnlFmncPrjRec.h"
#include "PnlFmncPrjHeadbar.h"
#include "PnlFmncPrjList.h"

/**
  * CrdFmncPrj
  */
class CrdFmncPrj : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncPrjDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDNEWCLICK = 3;
		static const uint MITCRDIMECLICK = 4;
		static const uint MITCRDEXECLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVFmncPrjSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRFMNCABT = 2;
		static const uint CLOSE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContInf (full: ContInfFmncPrj)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDPRJ = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdPrj = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdPrj;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncPrj)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVReqitmode = VecFmncVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrFmncPrj)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGEXPELB = 1;
		static const uint JREFDLGIMPELB = 2;
		static const uint JREFDLGNEW = 3;
		static const uint JREFHEADBAR = 4;
		static const uint JREFLIST = 5;
		static const uint JREFREC = 6;
		static const uint MSPCRD1AVAIL = 7;
		static const uint MITCRDNEWAVAIL = 8;
		static const uint MITCRDIMEAVAIL = 9;
		static const uint MITCRDEXEACTIVE = 10;

	public:
		StatShr(const ubigint jrefDlgexpelb = 0, const ubigint jrefDlgimpelb = 0, const ubigint jrefDlgnew = 0, const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdImeAvail = true, const bool MitCrdExeActive = true);

	public:
		ubigint jrefDlgexpelb;
		ubigint jrefDlgimpelb;
		ubigint jrefDlgnew;
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdImeAvail;
		bool MitCrdExeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncPrj)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppFmncPrjDo)
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
		* DpchEngData (full: DpchEngFmncPrjData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalMspCrd1Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdNewAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdImeAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdExeActive(DbsFmnc* dbsfmnc);

public:
	CrdFmncPrj(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale, const ubigint ref = 0);
	~CrdFmncPrj();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgFmncPrjExpelb* dlgexpelb;
	DlgFmncPrjImpelb* dlgimpelb;
	DlgFmncPrjNew* dlgnew;
	PnlFmncPrjRec* pnlrec;
	PnlFmncPrjHeadbar* pnlheadbar;
	PnlFmncPrjList* pnllist;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);
	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void changeRef(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint ref, const bool notif = false);
	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:
// IP dpchchangeStage --- BEGIN
	void changeStage(DbsFmnc* dbsfmnc, uint _ixVSge, DpchEngFmnc** dpcheng = NULL);
// IP dpchchangeStage --- END

	uint enterSgeIdle(DbsFmnc* dbsfmnc);
	void leaveSgeIdle(DbsFmnc* dbsfmnc);
	uint enterSgeAlrfmncabt(DbsFmnc* dbsfmnc);
	void leaveSgeAlrfmncabt(DbsFmnc* dbsfmnc);
	uint enterSgeClose(DbsFmnc* dbsfmnc);
	void leaveSgeClose(DbsFmnc* dbsfmnc);

// IP getSquawk --- BEGIN
	string getSquawk(DbsFmnc* dbsfmnc);
// IP getSquawk --- END

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);

	void handleDpchAppDoClose(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdNewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdImeClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdExeClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppFmncAlert(DbsFmnc* dbsfmnc, DpchAppFmncAlert* dpchappfmncalert, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncDlgClose(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
	bool handleCallFmncStatChg(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
	bool handleCallFmncRefPreSet(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


