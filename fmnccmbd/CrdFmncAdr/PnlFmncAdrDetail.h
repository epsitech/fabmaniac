/**
  * \file PnlFmncAdrDetail.h
  * job handler for job PnlFmncAdrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCADRDETAIL_H
#define PNLFMNCADRDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlFmncAdrDetail
  */
class PnlFmncAdrDetail : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncAdrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTHKUVIEWCLICK = 2;
		static const uint BUTATYEDITCLICK = 3;
		static const uint BUTCRYEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncAdrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFAD1 = 1;
		static const uint TXFCTY = 2;
		static const uint TXFSTA = 3;
		static const uint NUMFPUPHKT = 4;
		static const uint NUMFPUPATY = 5;
		static const uint TXFATY = 6;
		static const uint TXFAD2 = 7;
		static const uint TXFZIP = 8;
		static const uint TXFSTE = 9;
		static const uint NUMFPUPCRY = 10;
		static const uint TXFCRY = 11;

	public:
		ContIac(const string& TxfAd1 = "", const string& TxfCty = "", const string& TxfSta = "", const uint numFPupHkt = 1, const uint numFPupAty = 1, const string& TxfAty = "", const string& TxfAd2 = "", const string& TxfZip = "", const string& TxfSte = "", const uint numFPupCry = 1, const string& TxfCry = "");

	public:
		string TxfAd1;
		string TxfCty;
		string TxfSta;
		uint numFPupHkt;
		uint numFPupAty;
		string TxfAty;
		string TxfAd2;
		string TxfZip;
		string TxfSte;
		uint numFPupCry;
		string TxfCry;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncAdrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTHKU = 1;

	public:
		ContInf(const string& TxtHku = "");

	public:
		string TxtHku;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncAdrDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool PupAtyAlt = false, const bool PupCryAlt = false);
	};

	/**
		* StatShr (full: StatShrFmncAdrDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFATYVALID = 1;
		static const uint TXFCRYVALID = 2;
		static const uint BUTSAVEAVAIL = 3;
		static const uint BUTSAVEACTIVE = 4;
		static const uint BUTATYEDITAVAIL = 5;
		static const uint BUTCRYEDITAVAIL = 6;

	public:
		StatShr(const bool TxfAtyValid = false, const bool TxfCryValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButAtyEditAvail = true, const bool ButCryEditAvail = true);

	public:
		bool TxfAtyValid;
		bool TxfCryValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButAtyEditAvail;
		bool ButCryEditAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncAdrDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncAdrDetailData)
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
		* DpchAppDo (full: DpchAppFmncAdrDetailDo)
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
		* DpchEngData (full: DpchEngFmncAdrDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPATY = 4;
		static const uint FEEDFPUPCRY = 5;
		static const uint FEEDFPUPHKT = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupAty = NULL, Feed* feedFPupCry = NULL, Feed* feedFPupHkt = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAty;
		Feed feedFPupCry;
		Feed feedFPupHkt;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsFmnc* dbsfmnc);
	bool evalButSaveActive(DbsFmnc* dbsfmnc);
	bool evalButAtyEditAvail(DbsFmnc* dbsfmnc);
	bool evalButCryEditAvail(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncAdrDetail(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncAdrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupAty;
	Feed feedFPupCry;
	Feed feedFPupHkt;

	FmncMAddress recAdr;
	bool dirty;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshPupAty(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshTxfAty(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshAty(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshPupCry(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshTxfCry(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshCry(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refreshRecAdr(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButHkuViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButAtyEditClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButCryEditClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncAdrUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallFmncKlsAkeyMod_klsEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv);
};

#endif


