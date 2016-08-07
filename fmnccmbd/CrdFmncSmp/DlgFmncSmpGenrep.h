/**
  * \file DlgFmncSmpGenrep.h
  * job handler for job DlgFmncSmpGenrep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef DLGFMNCSMPGENREP_H
#define DLGFMNCSMPGENREP_H

// IP custInclude --- INSERT

/**
  * DlgFmncSmpGenrep
  */
class DlgFmncSmpGenrep : public JobFmnc {

public:
	/**
		* VecVDit (full: VecVDlgFmncSmpGenrepDit)
		*/
	class VecVDit {

	public:
		static const uint OPT = 1;
		static const uint GEN = 2;
		static const uint FIA = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixFmncVLocale);

		static void fillFeed(const uint ixFmncVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgFmncSmpGenrepDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoGen (full: VecVDlgFmncSmpGenrepDoGen)
		*/
	class VecVDoGen {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgFmncSmpGenrepSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRPIDLE = 2;
		static const uint PREPARE = 3;
		static const uint TYPESET = 4;
		static const uint PACK = 5;
		static const uint DONE = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgFmncSmpGenrep)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgFmncSmpGenrep)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfGen (full: ContInfDlgFmncSmpGenrepGen)
	  */
	class ContInfGen : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfGen(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfGen* comp);
		set<uint> diff(const ContInfGen* comp);
	};

	/**
		* StatApp (full: StatAppDlgFmncSmpGenrep)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgFmncSmpGenrep)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StatShrGen (full: StatShrDlgFmncSmpGenrepGen)
		*/
	class StatShrGen : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrGen(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrGen* comp);
		set<uint> diff(const StatShrGen* comp);
	};

	/**
		* Tag (full: TagDlgFmncSmpGenrep)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgFmncSmpGenrepFia)
		*/
	class TagFia {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagGen (full: TagDlgFmncSmpGenrepGen)
		*/
	class TagGen {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgFmncSmpGenrepData)
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
		* DpchAppDo (full: DpchAppDlgFmncSmpGenrepDo)
		*/
	class DpchAppDo : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOGEN = 3;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoGen;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgFmncSmpGenrepData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFGEN = 4;
		static const uint FEEDFDSE = 5;
		static const uint FEEDFSGE = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint STATSHRGEN = 9;
		static const uint TAG = 10;
		static const uint TAGFIA = 11;
		static const uint TAGGEN = 12;
		static const uint ALL = 13;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfGen* continfgen = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrGen* statshrgen = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfGen continfgen;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrGen statshrgen;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalGenButRunActive(DbsFmnc* dbsfmnc);
	bool evalGenButStoActive(DbsFmnc* dbsfmnc);
	bool evalButDneActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	DlgFmncSmpGenrep(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~DlgFmncSmpGenrep();

public:
	ContIac contiac;
	ContInf continf;
	ContInfGen continfgen;
	StatShr statshr;
	StatShrGen statshrgen;

	Feed feedFDse;
	Feed feedFSge;

	uint ixVDit;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshOpt(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshGen(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshFia(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

public:
// IP dpchchangeStage --- BEGIN
	void changeStage(DbsFmnc* dbsfmnc, uint _ixVSge, DpchEngFmnc** dpcheng = NULL);
// IP dpchchangeStage --- END

	uint enterSgeIdle(DbsFmnc* dbsfmnc);
	void leaveSgeIdle(DbsFmnc* dbsfmnc);
	uint enterSgePrpidle(DbsFmnc* dbsfmnc);
	void leaveSgePrpidle(DbsFmnc* dbsfmnc);
	uint enterSgePrepare(DbsFmnc* dbsfmnc);
	void leaveSgePrepare(DbsFmnc* dbsfmnc);
	uint enterSgeTypeset(DbsFmnc* dbsfmnc);
	void leaveSgeTypeset(DbsFmnc* dbsfmnc);
	uint enterSgePack(DbsFmnc* dbsfmnc);
	void leaveSgePack(DbsFmnc* dbsfmnc);
	uint enterSgeDone(DbsFmnc* dbsfmnc);
	void leaveSgeDone(DbsFmnc* dbsfmnc);

// IP getSquawk --- BEGIN
	string getSquawk(DbsFmnc* dbsfmnc);
// IP getSquawk --- END

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButDneClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

	void handleDpchAppDoGenButRunClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoGenButStoClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleDownload --- BEGIN
	string handleDownload(DbsFmnc* dbsfmnc);
// IP handleDownload --- END
// IP handleTimer --- BEGIN
	void handleTimer(DbsFmnc* dbsfmnc, const string& sref);
// IP handleTimer --- END

};

#endif


