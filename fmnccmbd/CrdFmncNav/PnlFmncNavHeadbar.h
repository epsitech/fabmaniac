/**
  * \file PnlFmncNavHeadbar.h
  * job handler for job PnlFmncNavHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef PNLFMNCNAVHEADBAR_H
#define PNLFMNCNAVHEADBAR_H

// IP custInclude --- INSERT

/**
  * PnlFmncNavHeadbar
  */
class PnlFmncNavHeadbar : public JobFmnc {

public:
	/**
		* StatShr (full: StatShrFmncNavHeadbar)
		*/
	class StatShr : public Block {

	public:
		static const uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfFmncNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagFmncNavHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixFmncVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngFmncNavHeadbarData)
		*/
	class DpchEngData : public DpchEngFmnc {

	public:
		static const uint JREF = 1;
		static const uint STATSHR = 2;
		static const uint STGINF = 3;
		static const uint TAG = 4;
		static const uint ALL = 5;

	public:
		DpchEngData(const ubigint jref = 0, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngFmnc* dpcheng);

		void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalMenCrdAvail(DbsFmnc* dbsfmnc);
	bool evalMspCrd1Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdUsgAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdUsrAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdOrgAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdPrsAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdAdrAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFilAvail(DbsFmnc* dbsfmnc);
	bool evalMspCrd2Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdStpAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdPrjAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdRunAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdActAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdSepAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdSmpAvail(DbsFmnc* dbsfmnc);
	bool evalMspCrd3Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFabAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFusAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdTtyAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdTolAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdFpjAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdBilAvail(DbsFmnc* dbsfmnc);
	bool evalMspCrd4Avail(DbsFmnc* dbsfmnc);
	bool evalMitCrdArtAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdSkiAvail(DbsFmnc* dbsfmnc);
	bool evalMitCrdPcoAvail(DbsFmnc* dbsfmnc);

public:
// IP constructor --- BEGIN
	PnlFmncNavHeadbar(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~PnlFmncNavHeadbar();

public:
	StatShr statshr;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngFmnc* getNewDpchEng(set<uint> items);

	void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	void handleDpchAppFmncInit(DbsFmnc* dbsfmnc, DpchAppFmncInit* dpchappfmncinit, DpchEngFmnc** dpcheng);

};

#endif


