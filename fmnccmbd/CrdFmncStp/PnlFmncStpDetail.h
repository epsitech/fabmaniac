/**
  * \file PnlFmncStpDetail.h
  * job handler for job PnlFmncStpDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSTPDETAIL_H
#define PNLFMNCSTPDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlFmncStpDetail
  */
class PnlFmncStpDetail : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncStpDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTACTVIEWCLICK = 2;
		static const uint BUTRLUVIEWCLICK = 3;
		static const uint BUTPRSVIEWCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncStpDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPRLT = 2;
		static const uint NUMSFLSTFCF = 3;
		static const uint TXFSTA = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupRlt = 1, const vector<uint>& numsFLstFcf = {}, const string& TxfSta = "");

	public:
		string TxfTit;
		uint numFPupRlt;
		vector<uint> numsFLstFcf;
		string TxfSta;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncStpDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTACT = 1;
		static const uint TXTRLU = 2;
		static const uint TXTSTP = 3;
		static const uint TXTFCF = 4;
		static const uint TXTPRS = 5;

	public:
		ContInf(const string& TxtAct = "", const string& TxtRlu = "", const string& TxtStp = "", const string& TxtFcf = "", const string& TxtPrs = "");

	public:
		string TxtAct;
		string TxtRlu;
		string TxtStp;
		string TxtFcf;
		string TxtPrs;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncStpDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstFcfAlt = true, const uint LstFcfNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrFmncStpDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTACTVIEWAVAIL = 3;
		static const uint BUTPRSVIEWAVAIL = 4;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButActViewAvail = true, const bool ButPrsViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButActViewAvail;
		bool ButPrsViewAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncStpDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncStpDetailData)
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
		* DpchAppDo (full: DpchAppFmncStpDetailDo)
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
		* DpchEngData (full: DpchEngFmncStpDetailData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTFCF = 4;
		static const uint FEEDFPUPRLT = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstFcf = NULL, Feed* feedFPupRlt = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstFcf;
		Feed feedFPupRlt;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsFmnc* dbsfmnc);
	bool evalButSaveActive(DbsFmnc* dbsfmnc);
	bool evalButActViewAvail(DbsFmnc* dbsfmnc);
	bool evalButPrsViewAvail(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncStpDetail(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncStpDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstFcf;
	Feed feedFPupRlt;

	FmncMStep recSte;
	bool dirty;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshTxtFcf(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refreshRecSte(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButActViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButRluViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncSteUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


