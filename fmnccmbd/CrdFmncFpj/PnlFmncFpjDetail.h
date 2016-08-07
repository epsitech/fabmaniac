/**
  * \file PnlFmncFpjDetail.h
  * job handler for job PnlFmncFpjDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCFPJDETAIL_H
#define PNLFMNCFPJDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlFmncFpjDetail
  */
class PnlFmncFpjDetail : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncFpjDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTFABVIEWCLICK = 2;
		static const uint BUTBIOVIEWCLICK = 3;
		static const uint BUTJEDITCLICK = 4;
		static const uint BUTBIPVIEWCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncFpjDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPJ = 2;
		static const uint NUMFPUPSTE = 3;
		static const uint TXFCMT = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupJ = 1, const uint numFPupSte = 1, const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupJ;
		uint numFPupSte;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncFpjDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTFAB = 2;
		static const uint TXTBIO = 3;
		static const uint TXTBIP = 4;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtFab = "", const string& TxtBio = "", const string& TxtBip = "");

	public:
		string TxtSrf;
		string TxtFab;
		string TxtBio;
		string TxtBip;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncFpjDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrFmncFpjDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTFABVIEWAVAIL = 3;
		static const uint BUTBIOVIEWAVAIL = 4;
		static const uint BUTJEDITAVAIL = 5;
		static const uint BUTBIPVIEWAVAIL = 6;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButFabViewAvail = true, const bool ButBioViewAvail = true, const bool ButJEditAvail = true, const bool ButBipViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButFabViewAvail;
		bool ButBioViewAvail;
		bool ButJEditAvail;
		bool ButBipViewAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncFpjDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncFpjDetailData)
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
		* DpchAppDo (full: DpchAppFmncFpjDetailDo)
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
		* DpchEngData (full: DpchEngFmncFpjDetailData)
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
	bool evalButFabViewAvail(DbsFmnc* dbsfmnc);
	bool evalButBioViewAvail(DbsFmnc* dbsfmnc);
	bool evalButJEditAvail(DbsFmnc* dbsfmnc);
	bool evalButBipViewAvail(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncFpjDetail(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncFpjDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupJ;
	Feed feedFPupSte;

	FmncMFabproject recFpj;
	FmncJMFabprojectState recFpjJste;
	bool dirty;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshJ(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refreshRecFpj(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshRecFpjJste(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFabViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButBioViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButJEditClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButBipViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncFpjUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallFmncFpjJsteMod_fpjEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


