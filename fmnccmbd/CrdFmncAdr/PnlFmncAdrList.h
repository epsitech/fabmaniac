/**
  * \file PnlFmncAdrList.h
  * job handler for job PnlFmncAdrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCADRLIST_H
#define PNLFMNCADRLIST_H

// IP custInclude --- INSERT

#include "QryFmncAdrList.h"

/**
  * PnlFmncAdrList
  */
class PnlFmncAdrList : public JobFmnc {

public:
	/**
		* VecVDo (full: VecVFmncAdrListDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDELETECLICK = 4;
		static const uint BUTFILTERCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacFmncAdrList)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFTOS = 1;

	public:
		ContIac(const uint numFTos = 1);

	public:
		uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfFmncAdrList)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTFILTERON = 1;
		static const uint NUMFCSIQST = 2;

	public:
		ContInf(const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrFmncAdrList)
		*/
	class StatShr : public Block {

	public:
		static const uint IXFMNCVEXPSTATE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const uint ixFmncVExpstate = VecFmncVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		uint ixFmncVExpstate;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacFmncAdrList)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOAD1WIDTH = 1;
		static const uint TCOCTYWIDTH = 2;
		static const uint TCOHKTWIDTH = 3;
		static const uint TCOHKUWIDTH = 4;
		static const uint TCOATYWIDTH = 5;
		static const uint TCOZIPWIDTH = 6;
		static const uint TCOCRYWIDTH = 7;

	public:
		StgIac(const uint TcoAd1Width = 100, const uint TcoCtyWidth = 100, const uint TcoHktWidth = 100, const uint TcoHkuWidth = 100, const uint TcoAtyWidth = 100, const uint TcoZipWidth = 100, const uint TcoCryWidth = 100);

	public:
		uint TcoAd1Width;
		uint TcoCtyWidth;
		uint TcoHktWidth;
		uint TcoHkuWidth;
		uint TcoAtyWidth;
		uint TcoZipWidth;
		uint TcoCryWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagFmncAdrList)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppFmncAdrListData)
		*/
	class DpchAppData : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		StgIac stgiac;
		QryFmncAdrList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppFmncAdrListDo)
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
		* DpchEngData (full: DpchEngFmncAdrListData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFCSIQST = 4;
		static const uint FEEDFTOS = 5;
		static const uint STATSHR = 6;
		static const uint STGIAC = 7;
		static const uint TAG = 8;
		static const uint RST = 9;
		static const uint STATAPPQRY = 10;
		static const uint STATSHRQRY = 11;
		static const uint STGIACQRY = 12;
		static const uint ALL = 13;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, Feed* feedFTos = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListFmncQAdrList* rst = NULL, QryFmncAdrList::StatShr* statshrqry = NULL, QryFmncAdrList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFCsiQst;
		Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		ListFmncQAdrList rst;
		QryFmncAdrList::StatShr statshrqry;
		QryFmncAdrList::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButDeleteActive(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncAdrList(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncAdrList();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;
	Feed feedFTos;

	QryFmncAdrList* qry;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

	void updatePreset(DbsFmnc* dbsfmnc, const uint ixFmncVPreset, const ubigint jrefTrig, const bool notif = false);
	void minimize(DbsFmnc* dbsfmnc, const bool notif = false, DpchEngFmnc** dpcheng = NULL);
	void regularize(DbsFmnc* dbsfmnc, const bool notif = false, DpchEngFmnc** dpcheng = NULL);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);
	void handleDpchAppDataContiac(DbsFmnc* dbsfmnc, ContIac* _contiac, DpchEngFmnc** dpcheng);
	void handleDpchAppDataStgiac(DbsFmnc* dbsfmnc, StgIac* _stgiac, DpchEngFmnc** dpcheng);
	void handleDpchAppDataStgiacqry(DbsFmnc* dbsfmnc, QryFmncAdrList::StgIac* _stgiacqry, DpchEngFmnc** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButNewClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButFilterClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncStatChg(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
};

#endif


