/**
  * \file PnlFmncSmpDetail.h
  * job handler for job PnlFmncSmpDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCSMPDETAIL_H
#define PNLFMNCSMPDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlFmncSmpDetail
  */
class PnlFmncSmpDetail : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncSmpDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTSUPVIEWCLICK = 2;
		static const uint BUTARTVIEWCLICK = 3;
		static const uint BUTJEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncSmpDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFMAT = 1;
		static const uint NUMFPUPJ = 2;
		static const uint NUMFPUPSTE = 3;
		static const uint TXFCMT = 4;

	public:
		ContIac(const string& TxfMat = "", const uint numFPupJ = 1, const uint numFPupSte = 1, const string& TxfCmt = "");

	public:
		string TxfMat;
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
	  * ContInf (full: ContInfFmncSmpDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTSUP = 2;
		static const uint TXTART = 3;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtSup = "", const string& TxtArt = "");

	public:
		string TxtSrf;
		string TxtSup;
		string TxtArt;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncSmpDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrFmncSmpDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTSUPVIEWAVAIL = 3;
		static const uint BUTARTVIEWAVAIL = 4;
		static const uint BUTJEDITAVAIL = 5;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButSupViewAvail = true, const bool ButArtViewAvail = true, const bool ButJEditAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButSupViewAvail;
		bool ButArtViewAvail;
		bool ButJEditAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncSmpDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncSmpDetailData)
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
		* DpchAppDo (full: DpchAppFmncSmpDetailDo)
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
		* DpchEngData (full: DpchEngFmncSmpDetailData)
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
	bool evalButSupViewAvail(DbsFmnc* dbsfmnc);
	bool evalButArtViewAvail(DbsFmnc* dbsfmnc);
	bool evalButJEditAvail(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncSmpDetail(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncSmpDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupJ;
	Feed feedFPupSte;

	FmncMSample recSmp;
	FmncJMSampleState recSmpJste;
	bool dirty;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshJ(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refreshRecSmp(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshRecSmpJste(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButArtViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButJEditClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncSmpUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallFmncSmpJsteMod_smpEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


