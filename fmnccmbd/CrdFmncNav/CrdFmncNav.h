/**
  * \file CrdFmncNav.h
  * job handler for job CrdFmncNav (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef CRDFMNCNAV_H
#define CRDFMNCNAV_H

// IP custInclude --- INSERT

#include "DlgFmncNavLoaini.h"
#include "PnlFmncNavHeadbar.h"
#include "PnlFmncNavPre.h"
#include "PnlFmncNavAdmin.h"
#include "PnlFmncNavLabbook.h"
#include "PnlFmncNavFabmgmt.h"
#include "PnlFmncNavSupply.h"

/**
  * CrdFmncNav
  */
class CrdFmncNav : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncNavDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITSESTRMCLICK = 3;
		static const uint MITCRDUSGCLICK = 4;
		static const uint MITCRDUSRCLICK = 5;
		static const uint MITCRDORGCLICK = 6;
		static const uint MITCRDPRSCLICK = 7;
		static const uint MITCRDADRCLICK = 8;
		static const uint MITCRDFILCLICK = 9;
		static const uint MITCRDSTPCLICK = 10;
		static const uint MITCRDPRJCLICK = 11;
		static const uint MITCRDRUNCLICK = 12;
		static const uint MITCRDACTCLICK = 13;
		static const uint MITCRDSEPCLICK = 14;
		static const uint MITCRDSMPCLICK = 15;
		static const uint MITCRDFABCLICK = 16;
		static const uint MITCRDFUSCLICK = 17;
		static const uint MITCRDTTYCLICK = 18;
		static const uint MITCRDTOLCLICK = 19;
		static const uint MITCRDFPJCLICK = 20;
		static const uint MITCRDBILCLICK = 21;
		static const uint MITCRDARTCLICK = 22;
		static const uint MITCRDSKICLICK = 23;
		static const uint MITCRDPCOCLICK = 24;
		static const uint MITAPPLOICLICK = 25;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVFmncNavSge)
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
	  * ContInf (full: ContInfFmncNav)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXSESSES1 = 3;
		static const uint MTXSESSES2 = 4;
		static const uint MTXSESSES3 = 5;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxSesSes1 = "", const string& MtxSesSes2 = "", const string& MtxSesSes3 = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxSesSes1;
		string MtxSesSes2;
		string MtxSesSes3;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncNav)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVReqitmode = VecFmncVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneLabbook = false, const bool initdoneFabmgmt = false, const bool initdoneSupply = false);
	};

	/**
		* StatShr (full: StatShrFmncNav)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGLOAINI = 1;
		static const uint JREFHEADBAR = 2;
		static const uint JREFPRE = 3;
		static const uint PNLPREAVAIL = 4;
		static const uint JREFADMIN = 5;
		static const uint PNLADMINAVAIL = 6;
		static const uint JREFLABBOOK = 7;
		static const uint PNLLABBOOKAVAIL = 8;
		static const uint JREFFABMGMT = 9;
		static const uint PNLFABMGMTAVAIL = 10;
		static const uint JREFSUPPLY = 11;
		static const uint PNLSUPPLYAVAIL = 12;
		static const uint MSPCRD1AVAIL = 13;
		static const uint MITCRDUSGAVAIL = 14;
		static const uint MITCRDUSRAVAIL = 15;
		static const uint MITCRDORGAVAIL = 16;
		static const uint MITCRDPRSAVAIL = 17;
		static const uint MITCRDADRAVAIL = 18;
		static const uint MITCRDFILAVAIL = 19;
		static const uint MSPCRD2AVAIL = 20;
		static const uint MITCRDSTPAVAIL = 21;
		static const uint MITCRDPRJAVAIL = 22;
		static const uint MITCRDRUNAVAIL = 23;
		static const uint MITCRDACTAVAIL = 24;
		static const uint MITCRDACTACTIVE = 25;
		static const uint MITCRDSEPAVAIL = 26;
		static const uint MITCRDSEPACTIVE = 27;
		static const uint MITCRDSMPAVAIL = 28;
		static const uint MSPCRD3AVAIL = 29;
		static const uint MITCRDFABAVAIL = 30;
		static const uint MITCRDFUSAVAIL = 31;
		static const uint MITCRDFUSACTIVE = 32;
		static const uint MITCRDTTYAVAIL = 33;
		static const uint MITCRDTOLAVAIL = 34;
		static const uint MITCRDTOLACTIVE = 35;
		static const uint MITCRDFPJAVAIL = 36;
		static const uint MITCRDFPJACTIVE = 37;
		static const uint MITCRDBILAVAIL = 38;
		static const uint MITCRDBILACTIVE = 39;
		static const uint MSPCRD4AVAIL = 40;
		static const uint MITCRDARTAVAIL = 41;
		static const uint MITCRDSKIAVAIL = 42;
		static const uint MITCRDPCOAVAIL = 43;
		static const uint MSPAPP2AVAIL = 44;
		static const uint MITAPPLOIAVAIL = 45;

	public:
		StatShr(const ubigint jrefDlgloaini = 0, const ubigint jrefHeadbar = 0, const ubigint jrefPre = 0, const bool pnlpreAvail = false, const ubigint jrefAdmin = 0, const bool pnladminAvail = false, const ubigint jrefLabbook = 0, const bool pnllabbookAvail = false, const ubigint jrefFabmgmt = 0, const bool pnlfabmgmtAvail = false, const ubigint jrefSupply = 0, const bool pnlsupplyAvail = false, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdOrgAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdAdrAvail = true, const bool MitCrdFilAvail = true, const bool MspCrd2Avail = true, const bool MitCrdStpAvail = true, const bool MitCrdPrjAvail = true, const bool MitCrdRunAvail = true, const bool MitCrdActAvail = true, const bool MitCrdActActive = true, const bool MitCrdSepAvail = true, const bool MitCrdSepActive = true, const bool MitCrdSmpAvail = true, const bool MspCrd3Avail = true, const bool MitCrdFabAvail = true, const bool MitCrdFusAvail = true, const bool MitCrdFusActive = true, const bool MitCrdTtyAvail = true, const bool MitCrdTolAvail = true, const bool MitCrdTolActive = true, const bool MitCrdFpjAvail = true, const bool MitCrdFpjActive = true, const bool MitCrdBilAvail = true, const bool MitCrdBilActive = true, const bool MspCrd4Avail = true, const bool MitCrdArtAvail = true, const bool MitCrdSkiAvail = true, const bool MitCrdPcoAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		ubigint jrefDlgloaini;
		ubigint jrefHeadbar;
		ubigint jrefPre;
		bool pnlpreAvail;
		ubigint jrefAdmin;
		bool pnladminAvail;
		ubigint jrefLabbook;
		bool pnllabbookAvail;
		ubigint jrefFabmgmt;
		bool pnlfabmgmtAvail;
		ubigint jrefSupply;
		bool pnlsupplyAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdOrgAvail;
		bool MitCrdPrsAvail;
		bool MitCrdAdrAvail;
		bool MitCrdFilAvail;
		bool MspCrd2Avail;
		bool MitCrdStpAvail;
		bool MitCrdPrjAvail;
		bool MitCrdRunAvail;
		bool MitCrdActAvail;
		bool MitCrdActActive;
		bool MitCrdSepAvail;
		bool MitCrdSepActive;
		bool MitCrdSmpAvail;
		bool MspCrd3Avail;
		bool MitCrdFabAvail;
		bool MitCrdFusAvail;
		bool MitCrdFusActive;
		bool MitCrdTtyAvail;
		bool MitCrdTolAvail;
		bool MitCrdTolActive;
		bool MitCrdFpjAvail;
		bool MitCrdFpjActive;
		bool MitCrdBilAvail;
		bool MitCrdBilActive;
		bool MspCrd4Avail;
		bool MitCrdArtAvail;
		bool MitCrdSkiAvail;
		bool MitCrdPcoAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncNav)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppFmncNavDo)
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
		* DpchEngData (full: DpchEngFmncNavData)
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

	bool evalPnlpreAvail(DbsFmnc* dbsfmnc);
	bool evalPnladminAvail(DbsFmnc* dbsfmnc);
	bool evalPnllabbookAvail(DbsFmnc* dbsfmnc);
	bool evalPnlfabmgmtAvail(DbsFmnc* dbsfmnc);
	bool evalPnlsupplyAvail(DbsFmnc* dbsfmnc);
	bool evalMspCrd1Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdUsgAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdUsrAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdOrgAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdPrsAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdAdrAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFilAvail(DbsFmnc* dbsfmnc);
	bool evalMspCrd2Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdStpAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdPrjAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdRunAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdActAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdActActive(DbsFmnc* dbsfmnc);
	bool evalMitCrdSepAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdSepActive(DbsFmnc* dbsfmnc);
	bool evalMitCrdSmpAvail(DbsFmnc* dbsfmnc);
	bool evalMspCrd3Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFabAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFusAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFusActive(DbsFmnc* dbsfmnc);
	bool evalMitCrdTtyAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdTolAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdTolActive(DbsFmnc* dbsfmnc);
	bool evalMitCrdFpjAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFpjActive(DbsFmnc* dbsfmnc);
	bool evalMitCrdBilAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdBilActive(DbsFmnc* dbsfmnc);
	bool evalMspCrd4Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdArtAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdSkiAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdPcoAvail(DbsFmnc* dbsfmnc);
	bool evalMspApp2Avail(DbsFmnc* dbsfmnc);
	bool evalMitAppLoiAvail(DbsFmnc* dbsfmnc);

public:
	CrdFmncNav(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
	~CrdFmncNav();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgFmncNavLoaini* dlgloaini;
	PnlFmncNavHeadbar* pnlheadbar;
	PnlFmncNavPre* pnlpre;
	PnlFmncNavAdmin* pnladmin;
	PnlFmncNavLabbook* pnllabbook;
	PnlFmncNavFabmgmt* pnlfabmgmt;
	PnlFmncNavSupply* pnlsupply;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);
	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);
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
	void handleDpchAppDoMitSesTrmClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdOrgClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdAdrClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdStpClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdPrjClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdRunClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdActClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdSepClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdSmpClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdFabClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdFusClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdTtyClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdTolClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdFpjClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdBilClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdArtClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdSkiClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitCrdPcoClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppFmncAlert(DbsFmnc* dbsfmnc, DpchAppFmncAlert* dpchappfmncalert, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncDlgClose(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
};

#endif


