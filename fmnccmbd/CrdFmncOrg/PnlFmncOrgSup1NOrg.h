/**
  * \file PnlFmncOrgSup1NOrg.h
  * job handler for job PnlFmncOrgSup1NOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCORGSUP1NORG_H
#define PNLFMNCORGSUP1NORG_H

// IP custInclude --- INSERT

#include "QryFmncOrgSup1NOrg.h"

/**
  * PnlFmncOrgSup1NOrg
  */
class PnlFmncOrgSup1NOrg : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncOrgSup1NOrgDo)
		*/
	class VecVDo {

	public:
		static const uint BUTVIEWCLICK = 1;
		static const uint BUTNEWCLICK = 2;
		static const uint BUTDELETECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfFmncOrgSup1NOrg)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppFmncOrgSup1NOrg)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixFmncVExpstate = VecFmncVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrFmncOrgSup1NOrg)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTVIEWACTIVE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const bool ButViewActive = true, const bool ButDeleteActive = true);

	public:
		bool ButViewActive;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacFmncOrgSup1NOrg)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagFmncOrgSup1NOrg)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncOrgSup1NOrgData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryFmncOrgSup1NOrg::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppFmncOrgSup1NOrgDo)
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
		* DpchEngData (full: DpchEngFmncOrgSup1NOrgData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListFmncQOrgSup1NOrg* rst = NULL, QryFmncOrgSup1NOrg::StatShr* statshrqry = NULL, QryFmncOrgSup1NOrg::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListFmncQOrgSup1NOrg rst;
		QryFmncOrgSup1NOrg::StatShr statshrqry;
		QryFmncOrgSup1NOrg::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButViewActive(DbsFmnc* dbsfmnc);
	bool evalButDeleteActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncOrgSup1NOrg(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncOrgSup1NOrg();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryFmncOrgSup1NOrg* qry;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataStgiac(DbsFmnc* dbsfmnc, StgIac* _stgiac, DpchEngFmnc** dpcheng);
	void handleDpchAppDataStgiacqry(DbsFmnc* dbsfmnc, QryFmncOrgSup1NOrg::StgIac* _stgiacqry, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButViewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButNewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncStatChg(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
};

#endif


