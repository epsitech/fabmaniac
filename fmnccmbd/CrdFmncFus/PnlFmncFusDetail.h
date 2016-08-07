/**
  * \file PnlFmncFusDetail.h
  * job handler for job PnlFmncFusDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCFUSDETAIL_H
#define PNLFMNCFUSDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlFmncFusDetail
  */
class PnlFmncFusDetail : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncFusDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTPRSVIEWCLICK = 2;
		static const uint BUTFABVIEWCLICK = 3;
		static const uint BUTFPJVIEWCLICK = 4;
		static const uint BUTJEDITCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncFusDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJ = 1;
		static const uint NUMFPUPSTE = 2;

	public:
		ContIac(const uint numFPupJ = 1, const uint numFPupSte = 1);

	public:
		uint numFPupJ;
		uint numFPupSte;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncFusDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRS = 1;
		static const uint TXTSRF = 2;
		static const uint TXTFAB = 3;
		static const uint TXTFPJ = 4;

	public:
		ContInf(const string& TxtPrs = "", const string& TxtSrf = "", const string& TxtFab = "", const string& TxtFpj = "");

	public:
		string TxtPrs;
		string TxtSrf;
		string TxtFab;
		string TxtFpj;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncFusDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrFmncFusDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTPRSVIEWAVAIL = 3;
		static const uint BUTFABVIEWAVAIL = 4;
		static const uint BUTFPJVIEWAVAIL = 5;
		static const uint BUTJEDITAVAIL = 6;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButPrsViewAvail = true, const bool ButFabViewAvail = true, const bool ButFpjViewAvail = true, const bool ButJEditAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButPrsViewAvail;
		bool ButFabViewAvail;
		bool ButFpjViewAvail;
		bool ButJEditAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncFusDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncFusDetailData)
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
		* DpchAppDo (full: DpchAppFmncFusDetailDo)
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
		* DpchEngData (full: DpchEngFmncFusDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPJ = 4;
		static const uint FEEDFPUPSTE = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupJ = NULL, Feed* feedFPupSte = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupJ;
		Feed feedFPupSte;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsFmnc* dbsfmnc);
	bool evalButSaveActive(DbsFmnc* dbsfmnc);
	bool evalButPrsViewAvail(DbsFmnc* dbsfmnc);
	bool evalButFabViewAvail(DbsFmnc* dbsfmnc);
	bool evalButFpjViewAvail(DbsFmnc* dbsfmnc);
	bool evalButJEditAvail(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncFusDetail(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncFusDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupJ;
	Feed feedFPupSte;

	FmncMFabuser recFus;
	FmncJMFabuserState recFusJste;
	bool dirty;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshJ(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refreshRecFus(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshRecFusJste(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFabViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFpjViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButJEditClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncFusUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallFmncFusJsteMod_fusEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


