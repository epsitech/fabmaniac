/**
  * \file QryFmncPcoList.h
  * job handler for job QryFmncPcoList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef QRYFMNCPCOLIST_H
#define QRYFMNCPCOLIST_H

// IP custInclude --- INSERT

/**
  * QryFmncPcoList
  */
class QryFmncPcoList : public JobFmnc {

public:
	/**
		* VecVOrd (full: VecVQryFmncPcoListOrd)
		*/
	class VecVOrd {

	public:
		static const uint SRF = 1;
		static const uint DAT = 2;
		static const uint PCO = 3;
		static const uint SPL = 4;
		static const uint FIL = 5;
		static const uint STE = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryFmncPcoList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 8, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryFmncPcoList)
		*/
	class StatShr : public Block {

	public:
		static const uint NTOT = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StatShr(const uint ntot = 0, const uint jnumFirstload = 0, const uint nload = 0);

	public:
		uint ntot;
		uint jnumFirstload;
		uint nload;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryFmncPcoList)
		*/
	class StgIac : public Block {

	public:
		static const uint JNUM = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StgIac(const uint jnum = 0, const uint jnumFirstload = 1, const uint nload = 100);

	public:
		uint jnum;
		uint jnumFirstload;
		uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

public:
// IP constructor --- BEGIN
	QryFmncPcoList(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~QryFmncPcoList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListFmncQPcoList rst;

	uint ixFmncVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsFmnc* dbsfmnc, const bool call = false);
	void refresh_filtSQL(string& sqlstr, const string& preSrf, const int preDat, const ubigint prePco, const ubigint preSpl, const ubigint preFil, const uint preSte, const bool addwhere);
	void refresh_filtSQL_append(string& sqlstr, bool& first);
	void refresh_orderSQL(string& sqlstr, const uint preIxOrd);
	void fetch(DbsFmnc* dbsfmnc);
	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	bool handleRefresh(DbsFmnc* dbsfmnc);
	bool handleShow(DbsFmnc* dbsfmnc);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncStubChg(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
	bool handleCallFmncPcoMod(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
	bool handleCallFmncPcoUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


