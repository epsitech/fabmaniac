/**
  * \file QryFmncRunList.h
  * job handler for job QryFmncRunList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef QRYFMNCRUNLIST_H
#define QRYFMNCRUNLIST_H

// IP custInclude --- INSERT

/**
  * QryFmncRunList
  */
class QryFmncRunList : public JobFmnc {

public:
	/**
		* VecVOrd (full: VecVQryFmncRunListOrd)
		*/
	class VecVOrd {

	public:
		static const uint TIT = 1;
		static const uint PRJ = 2;
		static const uint STE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryFmncRunList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 4, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryFmncRunList)
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
		* StgIac (full: StgIacQryFmncRunList)
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
	QryFmncRunList(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~QryFmncRunList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListFmncQRunList rst;

	uint ixFmncVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsFmnc* dbsfmnc, const bool call = false);
	void refresh_filtSQL(string& sqlstr, const string& preTit, const ubigint prePrj, const uint preSte, const bool addwhere);
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
	bool handleCallFmncRunMod(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
	bool handleCallFmncRunUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


