/**
  * \file PnlFmncNavLabbook.h
  * job handler for job PnlFmncNavLabbook (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVLABBOOK_H
#define PNLFMNCNAVLABBOOK_H

// IP custInclude --- INSERT

/**
  * PnlFmncNavLabbook
  */
class PnlFmncNavLabbook : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncNavLabbookDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSTPVIEWCLICK = 1;
		static const uint BUTSTPNEWCRDCLICK = 2;
		static const uint BUTPRJVIEWCLICK = 3;
		static const uint BUTPRJNEWCRDCLICK = 4;
		static const uint BUTRUNVIEWCLICK = 5;
		static const uint BUTRUNNEWCRDCLICK = 6;
		static const uint BUTACTVIEWCLICK = 7;
		static const uint BUTACTNEWCRDCLICK = 8;
		static const uint BUTSEPVIEWCLICK = 9;
		static const uint BUTSEPNEWCRDCLICK = 10;
		static const uint BUTSMPVIEWCLICK = 11;
		static const uint BUTSMPNEWCRDCLICK = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncNavLabbook)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTSTP = 1;
		static const uint NUMFLSTPRJ = 2;
		static const uint NUMFLSTRUN = 3;
		static const uint NUMFLSTACT = 4;
		static const uint NUMFLSTSEP = 5;
		static const uint NUMFLSTSMP = 6;

	public:
		ContIac(const uint numFLstStp = 1, const uint numFLstPrj = 1, const uint numFLstRun = 1, const uint numFLstAct = 1, const uint numFLstSep = 1, const uint numFLstSmp = 1);

	public:
		uint numFLstStp;
		uint numFLstPrj;
		uint numFLstRun;
		uint numFLstAct;
		uint numFLstSep;
		uint numFLstSmp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppFmncNavLabbook)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstStpAlt = true, const bool LstPrjAlt = true, const bool LstRunAlt = true, const bool LstActAlt = true, const bool LstSepAlt = true, const bool LstSmpAlt = true, const uint LstStpNumFirstdisp = 1, const uint LstPrjNumFirstdisp = 1, const uint LstRunNumFirstdisp = 1, const uint LstActNumFirstdisp = 1, const uint LstSepNumFirstdisp = 1, const uint LstSmpNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrFmncNavLabbook)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTSTPAVAIL = 1;
		static const uint BUTSTPVIEWACTIVE = 2;
		static const uint LSTPRJAVAIL = 3;
		static const uint BUTPRJVIEWACTIVE = 4;
		static const uint LSTRUNAVAIL = 5;
		static const uint BUTRUNVIEWACTIVE = 6;
		static const uint LSTACTAVAIL = 7;
		static const uint BUTACTVIEWACTIVE = 8;
		static const uint BUTACTNEWCRDACTIVE = 9;
		static const uint LSTSEPAVAIL = 10;
		static const uint BUTSEPVIEWACTIVE = 11;
		static const uint BUTSEPNEWCRDACTIVE = 12;
		static const uint LSTSMPAVAIL = 13;
		static const uint BUTSMPVIEWACTIVE = 14;

	public:
		StatShr(const bool LstStpAvail = true, const bool ButStpViewActive = true, const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstRunAvail = true, const bool ButRunViewActive = true, const bool LstActAvail = true, const bool ButActViewActive = true, const bool ButActNewcrdActive = true, const bool LstSepAvail = true, const bool ButSepViewActive = true, const bool ButSepNewcrdActive = true, const bool LstSmpAvail = true, const bool ButSmpViewActive = true);

	public:
		bool LstStpAvail;
		bool ButStpViewActive;
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstRunAvail;
		bool ButRunViewActive;
		bool LstActAvail;
		bool ButActViewActive;
		bool ButActNewcrdActive;
		bool LstSepAvail;
		bool ButSepViewActive;
		bool ButSepNewcrdActive;
		bool LstSmpAvail;
		bool ButSmpViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncNavLabbook)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncNavLabbookData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppFmncNavLabbookDo)
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
		* DpchEngData (full: DpchEngFmncNavLabbookData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTACT = 3;
		static const uint FEEDFLSTPRJ = 4;
		static const uint FEEDFLSTRUN = 5;
		static const uint FEEDFLSTSEP = 6;
		static const uint FEEDFLSTSMP = 7;
		static const uint FEEDFLSTSTP = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstAct = NULL, Feed* feedFLstPrj = NULL, Feed* feedFLstRun = NULL, Feed* feedFLstSep = NULL, Feed* feedFLstSmp = NULL, Feed* feedFLstStp = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstAct;
		Feed feedFLstPrj;
		Feed feedFLstRun;
		Feed feedFLstSep;
		Feed feedFLstSmp;
		Feed feedFLstStp;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstStpAvail(DbsFmnc* dbsfmnc);
	bool evalButStpViewActive(DbsFmnc* dbsfmnc);
	bool evalLstPrjAvail(DbsFmnc* dbsfmnc);
	bool evalButPrjViewActive(DbsFmnc* dbsfmnc);
	bool evalLstRunAvail(DbsFmnc* dbsfmnc);
	bool evalButRunViewActive(DbsFmnc* dbsfmnc);
	bool evalLstActAvail(DbsFmnc* dbsfmnc);
	bool evalButActViewActive(DbsFmnc* dbsfmnc);
	bool evalButActNewcrdActive(DbsFmnc* dbsfmnc);
	bool evalLstSepAvail(DbsFmnc* dbsfmnc);
	bool evalButSepViewActive(DbsFmnc* dbsfmnc);
	bool evalButSepNewcrdActive(DbsFmnc* dbsfmnc);
	bool evalLstSmpAvail(DbsFmnc* dbsfmnc);
	bool evalButSmpViewActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncNavLabbook(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncNavLabbook();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstAct;
	Feed feedFLstPrj;
	Feed feedFLstRun;
	Feed feedFLstSep;
	Feed feedFLstSmp;
	Feed feedFLstStp;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshLstStp(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshStp(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstPrj(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshPrj(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstRun(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshRun(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstAct(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshAct(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstSep(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshSep(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstSmp(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshSmp(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButStpViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButStpNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButPrjViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButPrjNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButRunViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButRunNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButActViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButActNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButSepViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButSepNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButSmpViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButSmpNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncHusrRunvMod_crdUsrEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


