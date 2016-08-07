/**
  * \file PnlFmncNavFabmgmt.h
  * job handler for job PnlFmncNavFabmgmt (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVFABMGMT_H
#define PNLFMNCNAVFABMGMT_H

// IP custInclude --- INSERT

/**
  * PnlFmncNavFabmgmt
  */
class PnlFmncNavFabmgmt : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncNavFabmgmtDo)
		*/
	class VecVDo {

	public:
		static const uint BUTFABVIEWCLICK = 1;
		static const uint BUTFABNEWCRDCLICK = 2;
		static const uint BUTFUSVIEWCLICK = 3;
		static const uint BUTFUSNEWCRDCLICK = 4;
		static const uint BUTTTYVIEWCLICK = 5;
		static const uint BUTTTYNEWCRDCLICK = 6;
		static const uint BUTTOLVIEWCLICK = 7;
		static const uint BUTTOLNEWCRDCLICK = 8;
		static const uint BUTFPJVIEWCLICK = 9;
		static const uint BUTFPJNEWCRDCLICK = 10;
		static const uint BUTBILVIEWCLICK = 11;
		static const uint BUTBILNEWCRDCLICK = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncNavFabmgmt)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTFAB = 1;
		static const uint NUMFLSTFUS = 2;
		static const uint NUMFLSTTTY = 3;
		static const uint NUMFLSTTOL = 4;
		static const uint NUMFLSTFPJ = 5;
		static const uint NUMFLSTBIL = 6;

	public:
		ContIac(const uint numFLstFab = 1, const uint numFLstFus = 1, const uint numFLstTty = 1, const uint numFLstTol = 1, const uint numFLstFpj = 1, const uint numFLstBil = 1);

	public:
		uint numFLstFab;
		uint numFLstFus;
		uint numFLstTty;
		uint numFLstTol;
		uint numFLstFpj;
		uint numFLstBil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppFmncNavFabmgmt)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstFabAlt = true, const bool LstFusAlt = true, const bool LstTtyAlt = true, const bool LstTolAlt = true, const bool LstFpjAlt = true, const bool LstBilAlt = true, const uint LstFabNumFirstdisp = 1, const uint LstFusNumFirstdisp = 1, const uint LstTtyNumFirstdisp = 1, const uint LstTolNumFirstdisp = 1, const uint LstFpjNumFirstdisp = 1, const uint LstBilNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrFmncNavFabmgmt)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTFABAVAIL = 1;
		static const uint BUTFABVIEWACTIVE = 2;
		static const uint LSTFUSAVAIL = 3;
		static const uint BUTFUSVIEWACTIVE = 4;
		static const uint BUTFUSNEWCRDACTIVE = 5;
		static const uint LSTTTYAVAIL = 6;
		static const uint BUTTTYVIEWACTIVE = 7;
		static const uint LSTTOLAVAIL = 8;
		static const uint BUTTOLVIEWACTIVE = 9;
		static const uint BUTTOLNEWCRDACTIVE = 10;
		static const uint LSTFPJAVAIL = 11;
		static const uint BUTFPJVIEWACTIVE = 12;
		static const uint BUTFPJNEWCRDACTIVE = 13;
		static const uint LSTBILAVAIL = 14;
		static const uint BUTBILVIEWACTIVE = 15;
		static const uint BUTBILNEWCRDACTIVE = 16;

	public:
		StatShr(const bool LstFabAvail = true, const bool ButFabViewActive = true, const bool LstFusAvail = true, const bool ButFusViewActive = true, const bool ButFusNewcrdActive = true, const bool LstTtyAvail = true, const bool ButTtyViewActive = true, const bool LstTolAvail = true, const bool ButTolViewActive = true, const bool ButTolNewcrdActive = true, const bool LstFpjAvail = true, const bool ButFpjViewActive = true, const bool ButFpjNewcrdActive = true, const bool LstBilAvail = true, const bool ButBilViewActive = true, const bool ButBilNewcrdActive = true);

	public:
		bool LstFabAvail;
		bool ButFabViewActive;
		bool LstFusAvail;
		bool ButFusViewActive;
		bool ButFusNewcrdActive;
		bool LstTtyAvail;
		bool ButTtyViewActive;
		bool LstTolAvail;
		bool ButTolViewActive;
		bool ButTolNewcrdActive;
		bool LstFpjAvail;
		bool ButFpjViewActive;
		bool ButFpjNewcrdActive;
		bool LstBilAvail;
		bool ButBilViewActive;
		bool ButBilNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncNavFabmgmt)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncNavFabmgmtData)
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
		* DpchAppDo (full: DpchAppFmncNavFabmgmtDo)
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
		* DpchEngData (full: DpchEngFmncNavFabmgmtData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTBIL = 3;
		static const uint FEEDFLSTFAB = 4;
		static const uint FEEDFLSTFPJ = 5;
		static const uint FEEDFLSTFUS = 6;
		static const uint FEEDFLSTTOL = 7;
		static const uint FEEDFLSTTTY = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstBil = NULL, Feed* feedFLstFab = NULL, Feed* feedFLstFpj = NULL, Feed* feedFLstFus = NULL, Feed* feedFLstTol = NULL, Feed* feedFLstTty = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstBil;
		Feed feedFLstFab;
		Feed feedFLstFpj;
		Feed feedFLstFus;
		Feed feedFLstTol;
		Feed feedFLstTty;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstFabAvail(DbsFmnc* dbsfmnc);
	bool evalButFabViewActive(DbsFmnc* dbsfmnc);
	bool evalLstFusAvail(DbsFmnc* dbsfmnc);
	bool evalButFusViewActive(DbsFmnc* dbsfmnc);
	bool evalButFusNewcrdActive(DbsFmnc* dbsfmnc);
	bool evalLstTtyAvail(DbsFmnc* dbsfmnc);
	bool evalButTtyViewActive(DbsFmnc* dbsfmnc);
	bool evalLstTolAvail(DbsFmnc* dbsfmnc);
	bool evalButTolViewActive(DbsFmnc* dbsfmnc);
	bool evalButTolNewcrdActive(DbsFmnc* dbsfmnc);
	bool evalLstFpjAvail(DbsFmnc* dbsfmnc);
	bool evalButFpjViewActive(DbsFmnc* dbsfmnc);
	bool evalButFpjNewcrdActive(DbsFmnc* dbsfmnc);
	bool evalLstBilAvail(DbsFmnc* dbsfmnc);
	bool evalButBilViewActive(DbsFmnc* dbsfmnc);
	bool evalButBilNewcrdActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncNavFabmgmt(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncNavFabmgmt();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstBil;
	Feed feedFLstFab;
	Feed feedFLstFpj;
	Feed feedFLstFus;
	Feed feedFLstTol;
	Feed feedFLstTty;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshLstFab(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshFab(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstFus(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshFus(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstTty(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshTty(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstTol(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshTol(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstFpj(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshFpj(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstBil(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshBil(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButFabViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFabNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFusViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFusNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButTtyViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButTtyNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButTolViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButTolNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFpjViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFpjNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButBilViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButBilNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncHusrRunvMod_crdUsrEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


