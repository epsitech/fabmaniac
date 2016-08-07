/**
  * \file PnlFmncSkiDetail.h
  * job handler for job PnlFmncSkiDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSKIDETAIL_H
#define PNLFMNCSKIDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlFmncSkiDetail
  */
class PnlFmncSkiDetail : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncSkiDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTORGVIEWCLICK = 2;
		static const uint BUTARTVIEWCLICK = 3;
		static const uint BUTJEDITCLICK = 4;
		static const uint BUTLCNEDITCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncSkiDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJ = 1;
		static const uint NUMFPUPLCN = 2;
		static const uint TXFLCN = 3;
		static const uint TXFEXD = 4;
		static const uint TXFCMT = 5;

	public:
		ContIac(const uint numFPupJ = 1, const uint numFPupLcn = 1, const string& TxfLcn = "", const string& TxfExd = "", const string& TxfCmt = "");

	public:
		uint numFPupJ;
		uint numFPupLcn;
		string TxfLcn;
		string TxfExd;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncSkiDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTORG = 1;
		static const uint TXTART = 2;
		static const uint TXTQTY = 3;

	public:
		ContInf(const string& TxtOrg = "", const string& TxtArt = "", const string& TxtQty = "");

	public:
		string TxtOrg;
		string TxtArt;
		string TxtQty;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncSkiDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool PupLcnAlt = false);
	};

	/**
		* StatShr (full: StatShrFmncSkiDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFLCNVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint BUTORGVIEWAVAIL = 4;
		static const uint BUTARTVIEWAVAIL = 5;
		static const uint BUTJEDITAVAIL = 6;
		static const uint BUTLCNEDITAVAIL = 7;

	public:
		StatShr(const bool TxfLcnValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButOrgViewAvail = true, const bool ButArtViewAvail = true, const bool ButJEditAvail = true, const bool ButLcnEditAvail = true);

	public:
		bool TxfLcnValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButOrgViewAvail;
		bool ButArtViewAvail;
		bool ButJEditAvail;
		bool ButLcnEditAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncSkiDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncSkiDetailData)
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
		* DpchAppDo (full: DpchAppFmncSkiDetailDo)
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
		* DpchEngData (full: DpchEngFmncSkiDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPJ = 4;
		static const uint FEEDFPUPLCN = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupJ = NULL, Feed* feedFPupLcn = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupJ;
		Feed feedFPupLcn;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsFmnc* dbsfmnc);
	bool evalButSaveActive(DbsFmnc* dbsfmnc);
	bool evalButOrgViewAvail(DbsFmnc* dbsfmnc);
	bool evalButArtViewAvail(DbsFmnc* dbsfmnc);
	bool evalButJEditAvail(DbsFmnc* dbsfmnc);
	bool evalButLcnEditAvail(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncSkiDetail(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncSkiDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupJ;
	Feed feedFPupLcn;

	FmncMStockitem recSki;
	FmncJMStockitemQuantity recSkiJqty;
	bool dirty;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshJ(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshPupLcn(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshTxfLcn(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLcn(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refreshRecSki(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshRecSkiJqty(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButOrgViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButArtViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButJEditClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButLcnEditClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncSkiUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallFmncKlsAkeyMod_klsMtbUrfEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv);
	bool handleCallFmncSkiJqtyMod_skiEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


