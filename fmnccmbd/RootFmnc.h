/**
  * \file RootFmnc.h
  * job handler for job RootFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef ROOTFMNC_H
#define ROOTFMNC_H

// IP custInclude --- INSERT

#include "SessFmnc.h"

/**
  * RootFmnc
  */
class RootFmnc : public JobFmnc {

public:
	/**
		* DpchAppLogin (full: DpchAppRootFmncLogin)
		*/
	class DpchAppLogin : public DpchAppFmnc {

	public:
		static const uint JREF = 1;
		static const uint PASSWORD = 2;
		static const uint USERNAME = 3;

	public:
		DpchAppLogin();

	public:
		string password;
		string username;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

public:
	RootFmnc(XchgFmnc* xchg);
	~RootFmnc();

public:

	list<SessFmnc*> sesss;

// IP specVar --- INSERT

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void clearAll(DbsFmnc* dbsfmnc);
	void clearQtb(DbsFmnc* dbsfmnc);

public:

	void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);

	bool handleClearAll(DbsFmnc* dbsfmnc);
	bool handleCreateSess(DbsFmnc* dbsfmnc);
	bool handleEraseSess(DbsFmnc* dbsfmnc);

	void handleDpchAppLogin(DbsFmnc* dbsfmnc, DpchAppLogin* dpchapplogin, const string ip, DpchEngFmnc** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
// IP handleCall --- END

	bool handleCallFmncLogout(DbsFmnc* dbsfmnc, const ubigint jrefTrig);
};

#endif


