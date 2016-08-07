/**
  * \file PnlFmncNavSupply.h
  * job handler for job PnlFmncNavSupply (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVSUPPLY_H
#define PNLFMNCNAVSUPPLY_H

// IP custInclude --- INSERT

/**
  * PnlFmncNavSupply
  */
class PnlFmncNavSupply : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncNavSupplyDo)
		*/
	class VecVDo {

	public:
		static const uint BUTARTVIEWCLICK = 1;
		static const uint BUTARTNEWCRDCLICK = 2;
		static const uint BUTSKIVIEWCLICK = 3;
		static const uint BUTSKINEWCRDCLICK = 4;
		static const uint BUTPCOVIEWCLICK = 5;
		static const uint BUTPCONEWCRDCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncNavSupply)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTART = 1;
		static const uint NUMFLSTSKI = 2;
		static const uint NUMFLSTPCO = 3;

	public:
		ContIac(const uint numFLstArt = 1, const uint numFLstSki = 1, const uint numFLstPco = 1);

	public:
		uint numFLstArt;
		uint numFLstSki;
		uint numFLstPco;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppFmncNavSupply)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstArtAlt = true, const bool LstSkiAlt = true, const bool LstPcoAlt = true, const uint LstArtNumFirstdisp = 1, const uint LstSkiNumFirstdisp = 1, const uint LstPcoNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrFmncNavSupply)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTARTAVAIL = 1;
		static const uint BUTARTVIEWACTIVE = 2;
		static const uint LSTSKIAVAIL = 3;
		static const uint BUTSKIVIEWACTIVE = 4;
		static const uint LSTPCOAVAIL = 5;
		static const uint BUTPCOVIEWACTIVE = 6;

	public:
		StatShr(const bool LstArtAvail = true, const bool ButArtViewActive = true, const bool LstSkiAvail = true, const bool ButSkiViewActive = true, const bool LstPcoAvail = true, const bool ButPcoViewActive = true);

	public:
		bool LstArtAvail;
		bool ButArtViewActive;
		bool LstSkiAvail;
		bool ButSkiViewActive;
		bool LstPcoAvail;
		bool ButPcoViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncNavSupply)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncNavSupplyData)
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
		* DpchAppDo (full: DpchAppFmncNavSupplyDo)
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
		* DpchEngData (full: DpchEngFmncNavSupplyData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTART = 3;
		static const uint FEEDFLSTPCO = 4;
		static const uint FEEDFLSTSKI = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstArt = NULL, Feed* feedFLstPco = NULL, Feed* feedFLstSki = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstArt;
		Feed feedFLstPco;
		Feed feedFLstSki;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstArtAvail(DbsFmnc* dbsfmnc);
	bool evalButArtViewActive(DbsFmnc* dbsfmnc);
	bool evalLstSkiAvail(DbsFmnc* dbsfmnc);
	bool evalButSkiViewActive(DbsFmnc* dbsfmnc);
	bool evalLstPcoAvail(DbsFmnc* dbsfmnc);
	bool evalButPcoViewActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncNavSupply(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncNavSupply();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstArt;
	Feed feedFLstPco;
	Feed feedFLstSki;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshLstArt(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshArt(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstSki(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshSki(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstPco(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshPco(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButArtViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButArtNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButSkiViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButSkiNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButPcoViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButPcoNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncHusrRunvMod_crdUsrEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


