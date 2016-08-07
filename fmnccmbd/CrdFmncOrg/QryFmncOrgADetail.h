/**
  * \file QryFmncOrgADetail.h
  * job handler for job QryFmncOrgADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef QRYFMNCORGADETAIL_H
#define QRYFMNCORGADETAIL_H

// IP custInclude --- INSERT

/**
  * QryFmncOrgADetail
  */
class QryFmncOrgADetail : public JobFmnc {

public:
	/**
		* StatApp (full: StatAppQryFmncOrgADetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 3, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryFmncOrgADetail)
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
		* StgIac (full: StgIacQryFmncOrgADetail)
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
	QryFmncOrgADetail(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~QryFmncOrgADetail();

public:
	StatShr statshr;
	StgIac stgiac;

	ListFmncQOrgADetail rst;

	uint ixFmncVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsFmnc* dbsfmnc, const bool call = false);
	void refresh_filtSQL(string& sqlstr, const string& preX1, const bool addwhere);
	void refresh_filtSQL_append(string& sqlstr, bool& first);
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
	bool handleCallFmncOrgAdetMod_orgEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


