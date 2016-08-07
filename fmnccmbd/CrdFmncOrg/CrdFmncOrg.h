/**
  * \file CrdFmncOrg.h
  * job handler for job CrdFmncOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef CRDFMNCORG_H
#define CRDFMNCORG_H

// IP custInclude --- INSERT

#include "DlgFmncOrgExporg.h"
#include "DlgFmncOrgImporg.h"
#include "DlgFmncOrgNew.h"
#include "PnlFmncOrgRec.h"
#include "PnlFmncOrgHeadbar.h"
#include "PnlFmncOrgList.h"

/**
  * CrdFmncOrg
  */
class CrdFmncOrg : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncOrgDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDNEWCLICK = 3;
		static const uint MITCRDIMOCLICK = 4;
		static const uint MITCRDEXOCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVFmncOrgSge)
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
	  * ContInf (full: ContInfFmncOrg)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDORG = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdOrg = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdOrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncOrg)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVReqitmode = VecFmncVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrFmncOrg)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGEXPORG = 1;
		static const uint JREFDLGIMPORG = 2;
		static const uint JREFDLGNEW = 3;
		static const uint JREFHEADBAR = 4;
		static const uint JREFLIST = 5;
		static const uint JREFREC = 6;
		static const uint MSPCRD1AVAIL = 7;
		static const uint MITCRDNEWAVAIL = 8;
		static const uint MITCRDIMOAVAIL = 9;
		static const uint MITCRDEXOACTIVE = 10;

	public:
		StatShr(const ubigint jrefDlgexporg = 0, const ubigint jrefDlgimporg = 0, const ubigint jrefDlgnew = 0, const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdImoAvail = true, const bool MitCrdExoActive = true);

	public:
		ubigint jrefDlgexporg;
		ubigint jrefDlgimporg;
		ubigint jrefDlgnew;
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdImoAvail;
		bool MitCrdExoActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncOrg)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppFmncOrgDo)
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
		* DpchEngData (full: DpchEngFmncOrgData)
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
	bool evalMitCrdImoAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdExoActive(DbsFmnc* dbsfmnc);

public:
	CrdFmncOrg(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale, const ubigint ref = 0);
	~CrdFmncOrg();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgFmncOrgExporg* dlgexporg;
	DlgFmncOrgImporg* dlgimporg;
	DlgFmncOrgNew* dlgnew;
	PnlFmncOrgRec* pnlrec;
	PnlFmncOrgHeadbar* pnlheadbar;
	PnlFmncOrgList* pnllist;

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
	void handleDpchAppDoMitCrdImoClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdExoClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppFmncAlert(DbsFmnc* dbsfmnc, DpchAppFmncAlert* dpchappfmncalert, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncDlgClose(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
	bool handleCallFmncStatChg(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
	bool handleCallFmncRefPreSet(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


