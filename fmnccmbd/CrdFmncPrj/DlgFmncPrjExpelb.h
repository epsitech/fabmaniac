/**
  * \file DlgFmncPrjExpelb.h
  * job handler for job DlgFmncPrjExpelb (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef DLGFMNCPRJEXPELB_H
#define DLGFMNCPRJEXPELB_H

// IP custInclude --- INSERT

#include "IexFmncElb.h"

/**
  * DlgFmncPrjExpelb
  */
class DlgFmncPrjExpelb : public JobFmnc {

public:
	/**
		* VecVDit (full: VecVDlgFmncPrjExpelbDit)
		*/
	class VecVDit {

	public:
		static const uint PRP = 1;
		static const uint FIA = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixFmncVLocale);

		static void fillFeed(const uint ixFmncVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgFmncPrjExpelbDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoPrp (full: VecVDlgFmncPrjExpelbDoPrp)
		*/
	class VecVDoPrp {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgFmncPrjExpelbSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint COLIDLE = 2;
		static const uint COLLECT = 3;
		static const uint EXPORT = 4;
		static const uint PACK = 5;
		static const uint DONE = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgFmncPrjExpelb)
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
	  * ContInf (full: ContInfDlgFmncPrjExpelb)
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
	  * ContInfPrp (full: ContInfDlgFmncPrjExpelbPrp)
	  */
	class ContInfPrp : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfPrp(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfPrp* comp);
		set<uint> diff(const ContInfPrp* comp);
	};

	/**
		* StatApp (full: StatAppDlgFmncPrjExpelb)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgFmncPrjExpelb)
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
		* StatShrFia (full: StatShrDlgFmncPrjExpelbFia)
		*/
	class StatShrFia : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrFia(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrFia* comp);
		set<uint> diff(const StatShrFia* comp);
	};

	/**
		* StatShrPrp (full: StatShrDlgFmncPrjExpelbPrp)
		*/
	class StatShrPrp : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrPrp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrPrp* comp);
		set<uint> diff(const StatShrPrp* comp);
	};

	/**
		* Tag (full: TagDlgFmncPrjExpelb)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgFmncPrjExpelbFia)
		*/
	class TagFia {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagPrp (full: TagDlgFmncPrjExpelbPrp)
		*/
	class TagPrp {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgFmncPrjExpelbData)
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
		* DpchAppDo (full: DpchAppDlgFmncPrjExpelbDo)
		*/
	class DpchAppDo : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOPRP = 3;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoPrp;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgFmncPrjExpelbData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFPRP = 4;
		static const uint FEEDFDSE = 5;
		static const uint FEEDFSGE = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint STATSHRFIA = 9;
		static const uint STATSHRPRP = 10;
		static const uint TAG = 11;
		static const uint TAGFIA = 12;
		static const uint TAGPRP = 13;
		static const uint ALL = 14;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfPrp* continfprp = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrFia* statshrfia = NULL, StatShrPrp* statshrprp = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfPrp continfprp;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrFia statshrfia;
		StatShrPrp statshrprp;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalPrpButRunActive(DbsFmnc* dbsfmnc);
	bool evalPrpButStoActive(DbsFmnc* dbsfmnc);
	bool evalFiaDldActive(DbsFmnc* dbsfmnc);
	bool evalButDneActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	DlgFmncPrjExpelb(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~DlgFmncPrjExpelb();

public:
	ContIac contiac;
	ContInf continf;
	ContInfPrp continfprp;
	StatShr statshr;
	StatShrFia statshrfia;
	StatShrPrp statshrprp;

	Feed feedFDse;
	Feed feedFSge;

	IexFmncElb* iex;

	uint ixVDit;

// IP custVar --- IBEGIN
	string outfolder;
// IP custVar --- IEND

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshPrp(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshFia(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

public:
// IP dpchchangeStage --- BEGIN
	void changeStage(DbsFmnc* dbsfmnc, uint _ixVSge, DpchEngFmnc** dpcheng = NULL);
// IP dpchchangeStage --- END

	uint enterSgeIdle(DbsFmnc* dbsfmnc);
	void leaveSgeIdle(DbsFmnc* dbsfmnc);
	uint enterSgeColidle(DbsFmnc* dbsfmnc);
	void leaveSgeColidle(DbsFmnc* dbsfmnc);
	uint enterSgeCollect(DbsFmnc* dbsfmnc);
	void leaveSgeCollect(DbsFmnc* dbsfmnc);
	uint enterSgeExport(DbsFmnc* dbsfmnc);
	void leaveSgeExport(DbsFmnc* dbsfmnc);
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

	void handleDpchAppDoPrpButRunClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoPrpButStoClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleDownload --- BEGIN
	string handleDownload(DbsFmnc* dbsfmnc);
// IP handleDownload --- END
// IP handleTimer --- BEGIN
	void handleTimer(DbsFmnc* dbsfmnc, const string& sref);
// IP handleTimer --- END

};

#endif


