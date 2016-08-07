/**
  * \file ApiFmnc_blks.h
  * Fmnc API library global data blocks (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef APIFMNC_BLKS_H
#define APIFMNC_BLKS_H

#include "VecFmncVDpch.h"
#include "VecFmncVExpstate.h"
#include "VecFmncVQrystate.h"
#include "VecFmncVReqitmode.h"

/**
	* ContInfFmncAlert
	*/
class ContInfFmncAlert : public Block {

public:
	static const uint TXTCPT = 1;
	static const uint TXTMSG1 = 2;
	static const uint TXTMSG2 = 3;
	static const uint TXTMSG3 = 4;
	static const uint TXTMSG4 = 5;
	static const uint TXTMSG5 = 6;
	static const uint TXTMSG6 = 7;
	static const uint TXTMSG7 = 8;
	static const uint TXTMSG8 = 9;
	static const uint TXTMSG9 = 10;
	static const uint TXTMSG10 = 11;

public:
	ContInfFmncAlert(const string& TxtCpt = "", const string& TxtMsg1 = "", const string& TxtMsg2 = "", const string& TxtMsg3 = "", const string& TxtMsg4 = "", const string& TxtMsg5 = "", const string& TxtMsg6 = "", const string& TxtMsg7 = "", const string& TxtMsg8 = "", const string& TxtMsg9 = "", const string& TxtMsg10 = "");

public:
	string TxtCpt;
	string TxtMsg1;
	string TxtMsg2;
	string TxtMsg3;
	string TxtMsg4;
	string TxtMsg5;
	string TxtMsg6;
	string TxtMsg7;
	string TxtMsg8;
	string TxtMsg9;
	string TxtMsg10;

public:
	static bool all(const set<uint>& items);
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	set<uint> compare(const ContInfFmncAlert* comp);
};

/**
	* DpchFmnc
	*/
class DpchFmnc : public Block {

public:
	DpchFmnc(const uint ixFmncVDpch = 0);
	virtual ~DpchFmnc();

public:
	uint ixFmncVDpch;
};

/**
	* DpchAppFmnc
	*/
class DpchAppFmnc : public DpchFmnc {

public:
	static const uint SCRJREF = 1;

public:
	DpchAppFmnc(const uint ixFmncVDpch = 0, const string& scrJref = "");
	virtual ~DpchAppFmnc();

public:
	string scrJref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppFmncAlert
	*/
class DpchAppFmncAlert : public DpchAppFmnc {

public:
	static const uint SCRJREF = 1;
	static const uint NUMFMCB = 2;
	static const uint ALL = 3;

public:
	DpchAppFmncAlert(const string& scrJref = "", const uint numFMcb = 0, const set<uint>& mask = {NONE});

public:
	uint numFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppFmncInit
	*/
class DpchAppFmncInit : public DpchAppFmnc {

public:
	DpchAppFmncInit(const string& scrJref = "");
};

/**
	* DpchAppFmncResume
	*/
class DpchAppFmncResume : public DpchAppFmnc {

public:
	DpchAppFmncResume(const string& scrJref = "");
};

/**
	* DpchEngFmnc
	*/
class DpchEngFmnc : public DpchFmnc {

public:
	static const uint SCRJREF = 1;

public:
	DpchEngFmnc(const uint ixFmncVDpch = 0);
	virtual ~DpchEngFmnc();

public:
	string scrJref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngFmncAck
	*/
class DpchEngFmncAck : public DpchEngFmnc {

public:
	DpchEngFmncAck();
};

/**
	* DpchEngFmncAlert
	*/
class DpchEngFmncAlert : public DpchEngFmnc {

public:
	static const uint SCRJREF = 1;
	static const uint CONTINF = 2;
	static const uint FEEDFMCB = 3;

public:
	DpchEngFmncAlert();

public:
	ContInfFmncAlert continf;
	Feed feedFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngFmncConfirm
	*/
class DpchEngFmncConfirm : public DpchEngFmnc {

public:
	static const uint ACCEPTED = 1;
	static const uint SCRJREF = 2;
	static const uint SREF = 3;

public:
	DpchEngFmncConfirm();

public:
	bool accepted;
	string sref;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngFmncSuspend
	*/
class DpchEngFmncSuspend : public DpchEngFmnc {

public:
	DpchEngFmncSuspend();
};

#endif

