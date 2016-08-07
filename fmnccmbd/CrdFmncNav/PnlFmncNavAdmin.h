/**
  * \file PnlFmncNavAdmin.h
  * job handler for job PnlFmncNavAdmin (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVADMIN_H
#define PNLFMNCNAVADMIN_H

// IP custInclude --- INSERT

/**
  * PnlFmncNavAdmin
  */
class PnlFmncNavAdmin : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncNavAdminDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUSGVIEWCLICK = 1;
		static const uint BUTUSGNEWCRDCLICK = 2;
		static const uint BUTUSRVIEWCLICK = 3;
		static const uint BUTUSRNEWCRDCLICK = 4;
		static const uint BUTORGVIEWCLICK = 5;
		static const uint BUTORGNEWCRDCLICK = 6;
		static const uint BUTPRSVIEWCLICK = 7;
		static const uint BUTPRSNEWCRDCLICK = 8;
		static const uint BUTADRVIEWCLICK = 9;
		static const uint BUTADRNEWCRDCLICK = 10;
		static const uint BUTFILVIEWCLICK = 11;
		static const uint BUTFILNEWCRDCLICK = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncNavAdmin)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTUSG = 1;
		static const uint NUMFLSTUSR = 2;
		static const uint NUMFLSTORG = 3;
		static const uint NUMFLSTPRS = 4;
		static const uint NUMFLSTADR = 5;
		static const uint NUMFLSTFIL = 6;

	public:
		ContIac(const uint numFLstUsg = 1, const uint numFLstUsr = 1, const uint numFLstOrg = 1, const uint numFLstPrs = 1, const uint numFLstAdr = 1, const uint numFLstFil = 1);

	public:
		uint numFLstUsg;
		uint numFLstUsr;
		uint numFLstOrg;
		uint numFLstPrs;
		uint numFLstAdr;
		uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppFmncNavAdmin)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstOrgAlt = true, const bool LstPrsAlt = true, const bool LstAdrAlt = true, const bool LstFilAlt = true, const uint LstUsgNumFirstdisp = 1, const uint LstUsrNumFirstdisp = 1, const uint LstOrgNumFirstdisp = 1, const uint LstPrsNumFirstdisp = 1, const uint LstAdrNumFirstdisp = 1, const uint LstFilNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrFmncNavAdmin)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTUSGAVAIL = 1;
		static const uint BUTUSGVIEWACTIVE = 2;
		static const uint LSTUSRAVAIL = 3;
		static const uint BUTUSRVIEWACTIVE = 4;
		static const uint LSTORGAVAIL = 5;
		static const uint BUTORGVIEWACTIVE = 6;
		static const uint LSTPRSAVAIL = 7;
		static const uint BUTPRSVIEWACTIVE = 8;
		static const uint LSTADRAVAIL = 9;
		static const uint BUTADRVIEWACTIVE = 10;
		static const uint LSTFILAVAIL = 11;
		static const uint BUTFILVIEWACTIVE = 12;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstOrgAvail = true, const bool ButOrgViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstAdrAvail = true, const bool ButAdrViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstOrgAvail;
		bool ButOrgViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstAdrAvail;
		bool ButAdrViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagFmncNavAdmin)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncNavAdminData)
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
		* DpchAppDo (full: DpchAppFmncNavAdminDo)
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
		* DpchEngData (full: DpchEngFmncNavAdminData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTADR = 3;
		static const uint FEEDFLSTFIL = 4;
		static const uint FEEDFLSTORG = 5;
		static const uint FEEDFLSTPRS = 6;
		static const uint FEEDFLSTUSG = 7;
		static const uint FEEDFLSTUSR = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstAdr = NULL, Feed* feedFLstFil = NULL, Feed* feedFLstOrg = NULL, Feed* feedFLstPrs = NULL, Feed* feedFLstUsg = NULL, Feed* feedFLstUsr = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstAdr;
		Feed feedFLstFil;
		Feed feedFLstOrg;
		Feed feedFLstPrs;
		Feed feedFLstUsg;
		Feed feedFLstUsr;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstUsgAvail(DbsFmnc* dbsfmnc);
	bool evalButUsgViewActive(DbsFmnc* dbsfmnc);
	bool evalLstUsrAvail(DbsFmnc* dbsfmnc);
	bool evalButUsrViewActive(DbsFmnc* dbsfmnc);
	bool evalLstOrgAvail(DbsFmnc* dbsfmnc);
	bool evalButOrgViewActive(DbsFmnc* dbsfmnc);
	bool evalLstPrsAvail(DbsFmnc* dbsfmnc);
	bool evalButPrsViewActive(DbsFmnc* dbsfmnc);
	bool evalLstAdrAvail(DbsFmnc* dbsfmnc);
	bool evalButAdrViewActive(DbsFmnc* dbsfmnc);
	bool evalLstFilAvail(DbsFmnc* dbsfmnc);
	bool evalButFilViewActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncNavAdmin(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncNavAdmin();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstAdr;
	Feed feedFLstFil;
	Feed feedFLstOrg;
	Feed feedFLstPrs;
	Feed feedFLstUsg;
	Feed feedFLstUsr;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refreshLstUsg(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshUsg(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstUsr(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshUsr(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstOrg(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshOrg(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstPrs(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshPrs(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstAdr(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshAdr(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshLstFil(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshFil(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButUsgViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButUsgNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButUsrViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButUsrNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButOrgViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButOrgNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButPrsNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButAdrViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButAdrNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFilNewcrdClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncHusrRunvMod_crdUsrEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


