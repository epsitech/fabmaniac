/**
  * \file QryFmncOrgMnf1NTool.h
  * job handler for job QryFmncOrgMnf1NTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef QRYFMNCORGMNF1NTOOL_H
#define QRYFMNCORGMNF1NTOOL_H

// IP custInclude --- INSERT

/**
  * QryFmncOrgMnf1NTool
  */
class QryFmncOrgMnf1NTool : public JobFmnc {

public:
	/**
		* StatApp (full: StatAppQryFmncOrgMnf1NTool)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 2, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryFmncOrgMnf1NTool)
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
		* StgIac (full: StgIacQryFmncOrgMnf1NTool)
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
	QryFmncOrgMnf1NTool(XchgFmnc* xchg, DbsFmnc* dbsfmnc, const ubigint jrefSup, const uint ixFmncVLocale);
// IP constructor --- END
	~QryFmncOrgMnf1NTool();

public:
	StatShr statshr;
	StgIac stgiac;

	ListFmncQOrgMnf1NTool rst;

	uint ixFmncVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsFmnc* dbsfmnc, const bool call = false);
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
	bool handleCallFmncTolMod_mnfEq(DbsFmnc* dbsfmnc, const ubigint jrefTrig, const ubigint refInv);
};

#endif


