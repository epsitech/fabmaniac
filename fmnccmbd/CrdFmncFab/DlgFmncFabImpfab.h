/**
  * \file DlgFmncFabImpfab.h
  * job handler for job DlgFmncFabImpfab (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef DLGFMNCFABIMPFAB_H
#define DLGFMNCFABIMPFAB_H

// IP custInclude --- IBEGIN
#include <sys/types.h>
#include <dirent.h>
// IP custInclude --- IEND

#include "IexFmncFab.h"

/**
  * DlgFmncFabImpfab
  */
class DlgFmncFabImpfab : public JobFmnc {

public:
	/**
		* VecVDit (full: VecVDlgFmncFabImpfabDit)
		*/
	class VecVDit {

	public:
		static const uint IFI = 1;
		static const uint IMP = 2;
		static const uint FIA = 3;
		static const uint LFI = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixFmncVLocale);

		static void fillFeed(const uint ixFmncVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgFmncFabImpfabDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgFmncFabImpfabDoImp)
		*/
	class VecVDoImp {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgFmncFabImpfabSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRSIDLE = 2;
		static const uint PARSE = 3;
		static const uint ALRFMNCPER = 4;
		static const uint PRSDONE = 5;
		static const uint IMPIDLE = 6;
		static const uint IMPORT = 7;
		static const uint IMPDONE = 8;
		static const uint UPKIDLE = 9;
		static const uint UNPACK = 10;
		static const uint DONE = 11;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgFmncFabImpfab)
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
	  * ContInf (full: ContInfDlgFmncFabImpfab)
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
	  * ContInfImp (full: ContInfDlgFmncFabImpfabImp)
	  */
	class ContInfImp : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfImp(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfImp* comp);
		set<uint> diff(const ContInfImp* comp);
	};

	/**
		* StatApp (full: StatAppDlgFmncFabImpfab)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgFmncFabImpfab)
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
		* StatShrFia (full: StatShrDlgFmncFabImpfabFia)
		*/
	class StatShrFia : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrFia(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrFia* comp);
		set<uint> diff(const StatShrFia* comp);
	};

	/**
		* StatShrIfi (full: StatShrDlgFmncFabImpfabIfi)
		*/
	class StatShrIfi : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrIfi* comp);
		set<uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgFmncFabImpfabImp)
		*/
	class StatShrImp : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrImp* comp);
		set<uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgFmncFabImpfabLfi)
		*/
	class StatShrLfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrLfi* comp);
		set<uint> diff(const StatShrLfi* comp);
	};

	/**
		* Tag (full: TagDlgFmncFabImpfab)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgFmncFabImpfabFia)
		*/
	class TagFia {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgFmncFabImpfabIfi)
		*/
	class TagIfi {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgFmncFabImpfabImp)
		*/
	class TagImp {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgFmncFabImpfabLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgFmncFabImpfabData)
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
		* DpchAppDo (full: DpchAppDlgFmncFabImpfabDo)
		*/
	class DpchAppDo : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOIMP = 3;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoImp;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgFmncFabImpfabData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFIMP = 4;
		static const uint FEEDFDSE = 5;
		static const uint FEEDFSGE = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint STATSHRFIA = 9;
		static const uint STATSHRIFI = 10;
		static const uint STATSHRIMP = 11;
		static const uint STATSHRLFI = 12;
		static const uint TAG = 13;
		static const uint TAGFIA = 14;
		static const uint TAGIFI = 15;
		static const uint TAGIMP = 16;
		static const uint TAGLFI = 17;
		static const uint ALL = 18;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrFia* statshrfia = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrFia statshrfia;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalIfiUldActive(DbsFmnc* dbsfmnc);
	bool evalImpButRunActive(DbsFmnc* dbsfmnc);
	bool evalImpButStoActive(DbsFmnc* dbsfmnc);
	bool evalFiaUldActive(DbsFmnc* dbsfmnc);
	bool evalLfiDldActive(DbsFmnc* dbsfmnc);
	bool evalButDneActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	DlgFmncFabImpfab(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~DlgFmncFabImpfab();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	StatShr statshr;
	StatShrFia statshrfia;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;

	Feed feedFMcbAlert;
	Feed feedFDse;
	Feed feedFSge;

	IexFmncFab* iex;

	uint ixVDit;

// IP custVar --- IBEGIN
	string infilename;
// IP custVar --- IEND

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshIfi(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshImp(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshFia(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLfi(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

public:
// IP dpchchangeStage --- BEGIN
	void changeStage(DbsFmnc* dbsfmnc, uint _ixVSge, DpchEngFmnc** dpcheng = NULL);
// IP dpchchangeStage --- END

	uint enterSgeIdle(DbsFmnc* dbsfmnc);
	void leaveSgeIdle(DbsFmnc* dbsfmnc);
	uint enterSgePrsidle(DbsFmnc* dbsfmnc);
	void leaveSgePrsidle(DbsFmnc* dbsfmnc);
	uint enterSgeParse(DbsFmnc* dbsfmnc);
	void leaveSgeParse(DbsFmnc* dbsfmnc);
	uint enterSgeAlrfmncper(DbsFmnc* dbsfmnc);
	void leaveSgeAlrfmncper(DbsFmnc* dbsfmnc);
	uint enterSgePrsdone(DbsFmnc* dbsfmnc);
	void leaveSgePrsdone(DbsFmnc* dbsfmnc);
	uint enterSgeImpidle(DbsFmnc* dbsfmnc);
	void leaveSgeImpidle(DbsFmnc* dbsfmnc);
	uint enterSgeImport(DbsFmnc* dbsfmnc);
	void leaveSgeImport(DbsFmnc* dbsfmnc);
	uint enterSgeImpdone(DbsFmnc* dbsfmnc);
	void leaveSgeImpdone(DbsFmnc* dbsfmnc);
	uint enterSgeUpkidle(DbsFmnc* dbsfmnc);
	void leaveSgeUpkidle(DbsFmnc* dbsfmnc);
	uint enterSgeUnpack(DbsFmnc* dbsfmnc);
	void leaveSgeUnpack(DbsFmnc* dbsfmnc);
	uint enterSgeDone(DbsFmnc* dbsfmnc);
	void leaveSgeDone(DbsFmnc* dbsfmnc);

// IP getSquawk --- BEGIN
	string getSquawk(DbsFmnc* dbsfmnc);
// IP getSquawk --- END

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButDneClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

	void handleDpchAppDoImpButRunClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppFmncAlert(DbsFmnc* dbsfmnc, DpchAppFmncAlert* dpchappfmncalert, DpchEngFmnc** dpcheng);

// IP handleUpload --- BEGIN
	void handleUpload(DbsFmnc* dbsfmnc, const string& filename);
// IP handleUpload --- END
// IP handleDownload --- BEGIN
	string handleDownload(DbsFmnc* dbsfmnc);
// IP handleDownload --- END
// IP handleTimer --- BEGIN
	void handleTimer(DbsFmnc* dbsfmnc, const string& sref);
// IP handleTimer --- END

};

#endif


