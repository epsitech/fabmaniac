/**
  * \file DlgFmncRunGenrep.h
  * job handler for job DlgFmncRunGenrep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef DLGFMNCRUNGENREP_H
#define DLGFMNCRUNGENREP_H

// IP custInclude --- INSERT

/**
  * DlgFmncRunGenrep
  */
class DlgFmncRunGenrep : public JobFmnc {

public:
	/**
		* VecVDit (full: VecVDlgFmncRunGenrepDit)
		*/
	class VecVDit {

	public:
		static const uint OPT = 1;
		static const uint STO = 2;
		static const uint GEN = 3;
		static const uint FIA = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixFmncVLocale);

		static void fillFeed(const uint ixFmncVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgFmncRunGenrepDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoGen (full: VecVDlgFmncRunGenrepDoGen)
		*/
	class VecVDoGen {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgFmncRunGenrepSge)
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
	  * ContIac (full: ContIacDlgFmncRunGenrep)
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
	  * ContIacOpt (full: ContIacDlgFmncRunGenrepOpt)
	  */
	class ContIacOpt : public Block {

	public:
		static const uint NUMFRBUHIS = 1;
		static const uint CHKSSU = 2;
		static const uint NUMFRBUFAB = 3;
		static const uint NUMFRBUPRS = 4;
		static const uint NUMFRBUFIL = 5;
		static const uint NUMFRBUSMP = 6;
		static const uint NUMFLSTSPA = 7;

	public:
		ContIacOpt(const uint numFRbuHis = 1, const bool ChkSsu = false, const uint numFRbuFab = 1, const uint numFRbuPrs = 1, const uint numFRbuFil = 1, const uint numFRbuSmp = 1, const uint numFLstSpa = 1);

	public:
		uint numFRbuHis;
		bool ChkSsu;
		uint numFRbuFab;
		uint numFRbuPrs;
		uint numFRbuFil;
		uint numFRbuSmp;
		uint numFLstSpa;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacOpt* comp);
		set<uint> diff(const ContIacOpt* comp);
	};

	/**
	  * ContIacSto (full: ContIacDlgFmncRunGenrepSto)
	  */
	class ContIacSto : public Block {

	public:
		static const uint CHKDET = 1;
		static const uint NUMFRBUFIL = 2;
		static const uint NUMFLSTIMF = 3;
		static const uint NUMFLSTPAR = 4;
		static const uint NUMFRBUCPA = 5;
		static const uint NUMFRBUFSP = 6;
		static const uint NUMFRBUSSP = 7;

	public:
		ContIacSto(const bool ChkDet = false, const uint numFRbuFil = 1, const uint numFLstImf = 1, const uint numFLstPar = 1, const uint numFRbuCpa = 1, const uint numFRbuFsp = 1, const uint numFRbuSsp = 1);

	public:
		bool ChkDet;
		uint numFRbuFil;
		uint numFLstImf;
		uint numFLstPar;
		uint numFRbuCpa;
		uint numFRbuFsp;
		uint numFRbuSsp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacSto* comp);
		set<uint> diff(const ContIacSto* comp);
	};

	/**
	  * ContInf (full: ContInfDlgFmncRunGenrep)
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
	  * ContInfGen (full: ContInfDlgFmncRunGenrepGen)
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
		* StatApp (full: StatAppDlgFmncRunGenrep)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatAppOpt (full: StatAppDlgFmncRunGenrepOpt)
		*/
	class StatAppOpt {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint LstSpaNumFirstdisp = 1);
	};

	/**
		* StatAppSto (full: StatAppDlgFmncRunGenrepSto)
		*/
	class StatAppSto {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint LstImfNumFirstdisp = 1, const uint LstParNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrDlgFmncRunGenrep)
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
		* StatShrGen (full: StatShrDlgFmncRunGenrepGen)
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
		* Tag (full: TagDlgFmncRunGenrep)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgFmncRunGenrepFia)
		*/
	class TagFia {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagGen (full: TagDlgFmncRunGenrepGen)
		*/
	class TagGen {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagOpt (full: TagDlgFmncRunGenrepOpt)
		*/
	class TagOpt {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagSto (full: TagDlgFmncRunGenrepSto)
		*/
	class TagSto {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgFmncRunGenrepData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACOPT = 3;
		static const uint CONTIACSTO = 4;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		ContIacOpt contiacopt;
		ContIacSto contiacsto;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgFmncRunGenrepDo)
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
		* DpchEngData (full: DpchEngDlgFmncRunGenrepData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACOPT = 3;
		static const uint CONTIACSTO = 4;
		static const uint CONTINF = 5;
		static const uint CONTINFGEN = 6;
		static const uint FEEDFDSE = 7;
		static const uint FEEDFOPTLSTSPA = 8;
		static const uint FEEDFOPTRBUFAB = 9;
		static const uint FEEDFOPTRBUFIL = 10;
		static const uint FEEDFOPTRBUHIS = 11;
		static const uint FEEDFOPTRBUPRS = 12;
		static const uint FEEDFOPTRBUSMP = 13;
		static const uint FEEDFSGE = 14;
		static const uint FEEDFSTOLSTIMF = 15;
		static const uint FEEDFSTOLSTPAR = 16;
		static const uint FEEDFSTORBUCPA = 17;
		static const uint FEEDFSTORBUFIL = 18;
		static const uint FEEDFSTORBUFSP = 19;
		static const uint FEEDFSTORBUSSP = 20;
		static const uint STATAPP = 21;
		static const uint STATAPPOPT = 22;
		static const uint STATAPPSTO = 23;
		static const uint STATSHR = 24;
		static const uint STATSHRGEN = 25;
		static const uint TAG = 26;
		static const uint TAGFIA = 27;
		static const uint TAGGEN = 28;
		static const uint TAGOPT = 29;
		static const uint TAGSTO = 30;
		static const uint ALL = 31;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContIacOpt* contiacopt = NULL, ContIacSto* contiacsto = NULL, ContInf* continf = NULL, ContInfGen* continfgen = NULL, Feed* feedFDse = NULL, Feed* feedFOptLstSpa = NULL, Feed* feedFOptRbuFab = NULL, Feed* feedFOptRbuFil = NULL, Feed* feedFOptRbuHis = NULL, Feed* feedFOptRbuPrs = NULL, Feed* feedFOptRbuSmp = NULL, Feed* feedFSge = NULL, Feed* feedFStoLstImf = NULL, Feed* feedFStoLstPar = NULL, Feed* feedFStoRbuCpa = NULL, Feed* feedFStoRbuFil = NULL, Feed* feedFStoRbuFsp = NULL, Feed* feedFStoRbuSsp = NULL, StatShr* statshr = NULL, StatShrGen* statshrgen = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacOpt contiacopt;
		ContIacSto contiacsto;
		ContInf continf;
		ContInfGen continfgen;
		Feed feedFDse;
		Feed feedFOptLstSpa;
		Feed feedFOptRbuFab;
		Feed feedFOptRbuFil;
		Feed feedFOptRbuHis;
		Feed feedFOptRbuPrs;
		Feed feedFOptRbuSmp;
		Feed feedFSge;
		Feed feedFStoLstImf;
		Feed feedFStoLstPar;
		Feed feedFStoRbuCpa;
		Feed feedFStoRbuFil;
		Feed feedFStoRbuFsp;
		Feed feedFStoRbuSsp;
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
	DlgFmncRunGenrep(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~DlgFmncRunGenrep();

public:
	ContIac contiac;
	ContIacOpt contiacopt;
	ContIacSto contiacsto;
	ContInf continf;
	ContInfGen continfgen;
	StatShr statshr;
	StatShrGen statshrgen;

	Feed feedFDse;
	Feed feedFOptLstSpa;
	Feed feedFOptRbuFab;
	Feed feedFOptRbuFil;
	Feed feedFOptRbuHis;
	Feed feedFOptRbuPrs;
	Feed feedFOptRbuSmp;
	Feed feedFSge;
	Feed feedFStoLstImf;
	Feed feedFStoLstPar;
	Feed feedFStoRbuCpa;
	Feed feedFStoRbuFil;
	Feed feedFStoRbuFsp;
	Feed feedFStoRbuSsp;

	uint ixVDit;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshOpt(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshSto(DbsFmnc* dbsfmnc, set<uint>& moditems);
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
	void handleDpchAppDataContiacopt(DbsFmnc* dbsfmnc, ContIacOpt* _contiacopt, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiacsto(DbsFmnc* dbsfmnc, ContIacSto* _contiacsto, DpchEngFmnc** dpcheng);

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


