/**
  * \file QryFmncOrgList.h
  * job handler for job QryFmncOrgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef QRYFMNCORGLIST_H
#define QRYFMNCORGLIST_H

// IP custInclude --- INSERT

/**
  * QryFmncOrgList
  */
class QryFmncOrgList : public JobFmnc {

public:
	/**
		* VecVOrd (full: VecVQryFmncOrgListOrd)
		*/
	class VecVOrd {

	public:
		static const uint SRF = 1;
		static const uint TIT = 2;
		static const uint DRV = 3;
		static const uint ADR = 4;
		static const uint SUP = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryFmncOrgList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 8, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryFmncOrgList)
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
		* StgIac (full: StgIacQryFmncOrgList)
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
	QryFmncOrgList(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~QryFmncOrgList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListFmncQOrgList rst;

	uint ixFmncVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsFmnc* dbsfmnc, const bool call = false);
	void refresh_filtSQL(string& sqlstr, const string& preSrf, const string& preTit, const uint preDrv, const ubigint preAdr, const ubigint preSup, const bool addwhere);
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
	bool handleCallFmncOrgMod(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
	bool handleCallFmncOrgUpd_refEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


