/**
  * \file Fmnccmbd.h
  * inter-thread exchange object for Fmnc combined daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCCMBD_H
#define FMNCCMBD_H

#include <unistd.h>
#ifndef _WIN32
	#include <sys/socket.h>
#endif

#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <unistd.h>

#include <microhttpd.h>

#include <dartcore/Engtypes.h>
#include <dartcore/Txtrd.h>
#include <dartcore/DbsMon.h>

#include "Fmnc.h"

// IP incl --- INSERT

class XchgFmnccmbd;
typedef XchgFmnccmbd XchgFmnc;

/**
	* DpchAppFmnc
	*/
class DpchAppFmnc : public DpchFmnc {

public:
	static const uint JREF = 1;

public:
	DpchAppFmnc(const uint ixFmncVDpch = 0);
	virtual ~DpchAppFmnc();

public:
	ubigint jref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchAppFmncAlert
  */
class DpchAppFmncAlert : public DpchAppFmnc {

public:
	static const uint JREF = 1;
	static const uint NUMFMCB = 2;

public:
	DpchAppFmncAlert();

public:
	uint numFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchAppFmncInit
  */
class DpchAppFmncInit : public DpchAppFmnc {

public:
	DpchAppFmncInit();
};

/**
  * DpchAppFmncResume
  */
class DpchAppFmncResume : public DpchAppFmnc {

public:
	DpchAppFmncResume();
};

/**
	* DpchEngFmnc
	*/
class DpchEngFmnc : public DpchFmnc {

public:
	static const uint JREF = 1;

public:
	DpchEngFmnc(const uint ixFmncVDpch = 0, const ubigint jref = 0);
	virtual ~DpchEngFmnc();

public:
	ubigint jref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();
	virtual void merge(DpchEngFmnc* dpcheng);

	virtual void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngFmncAck
  */
class DpchEngFmncAck : public DpchEngFmnc {

public:
	DpchEngFmncAck(const ubigint jref = 0);
};

/**
  * DpchEngFmncAlert
  */
class DpchEngFmncAlert : public DpchEngFmnc {

public:
	static const uint JREF = 1;
	static const uint CONTINF = 2;
	static const uint FEEDFMCB = 3;
	static const uint ALL = 4;

public:
	DpchEngFmncAlert(const ubigint jref = 0, ContInfFmncAlert* continf = NULL, Feed* feedFMcb = NULL, const set<uint>& mask = {NONE});

public:
	ContInfFmncAlert continf;
	Feed feedFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();
	void merge(DpchEngFmnc* dpcheng);

	void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngFmncConfirm
  */
class DpchEngFmncConfirm : public DpchEngFmnc {

public:
	static const uint ACCEPTED = 1;
	static const uint JREF = 2;
	static const uint SREF = 3;
	static const uint ALL = 4;

public:
	DpchEngFmncConfirm(const bool accepted = false, const ubigint jref = 0, const string& sref = "", const set<uint>& mask = {ALL});

public:
	bool accepted;
	string sref;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();
	void merge(DpchEngFmnc* dpcheng);

	void writeXML(const uint ixFmncVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngFmncSuspend
  */
class DpchEngFmncSuspend : public DpchEngFmnc {

public:
	DpchEngFmncSuspend(const ubigint jref = 0);
};

/**
	* StgFmnccmbd
	*/
class StgFmnccmbd : public Block {

public:
	static const uint JOBPRCN = 1;
	static const uint OPPRCN = 2;
	static const uint APPSRVPORT = 3;
	static const uint HISTLENGTH = 4;

public:
	StgFmnccmbd(const usmallint jobprcn = 1, const usmallint opprcn = 1, const usmallint appsrvport = 0, const usmallint histlength = 20);

public:
	usmallint jobprcn;
	usmallint opprcn;
	usmallint appsrvport;
	usmallint histlength;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgFmnccmbd* comp);
	set<uint> diff(const StgFmnccmbd* comp);
};

/**
	* StgFmncDatabase
	*/
class StgFmncDatabase : public Block {

public:
	static const uint IXDBSVDBSTYPE = 1;
	static const uint DBSPATH = 2;
	static const uint DBSNAME = 3;
	static const uint USERNAME = 4;
	static const uint PASSWORD = 5;
	static const uint IP = 6;
	static const uint PORT = 7;

public:
	StgFmncDatabase(const uint ixDbsVDbstype = 0, const string& dbspath = "", const string& dbsname = "", const string& username = "epsi", const string& password = "f9w8feeh", const string& ip = "", const usmallint port = 0);

public:
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string username;
	string password;
	string ip;
	usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgFmncDatabase* comp);
	set<uint> diff(const StgFmncDatabase* comp);
};

/**
	* StgFmncMonitor
	*/
class StgFmncMonitor : public Block {

public:
	static const uint USERNAME = 1;
	static const uint PASSWORD = 2;
	static const uint IP = 3;
	static const uint PORT = 4;
	static const uint IXDBSVDBSTYPE = 5;
	static const uint DBSPATH = 6;
	static const uint DBSNAME = 7;
	static const uint DBSUSERNAME = 8;
	static const uint DBSPASSWORD = 9;

public:
	StgFmncMonitor(const string& username = "", const string& password = "", const string& ip = "", const usmallint port = 0, const uint ixDbsVDbstype = 0, const string& dbspath = "", const string& dbsname = "", const string& dbsusername = "", const string& dbspassword = "");

public:
	string username;
	string password;
	string ip;
	usmallint port;
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string dbsusername;
	string dbspassword;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgFmncMonitor* comp);
	set<uint> diff(const StgFmncMonitor* comp);
};

/**
	* StgFmncPath
	*/
class StgFmncPath : public Block {

public:
	static const uint ACVPATH = 1;
	static const uint MONPATH = 2;
	static const uint TMPPATH = 3;
	static const uint WEBPATH = 4;
	static const uint HELPURL = 5;

public:
	StgFmncPath(const string& acvpath = "", const string& monpath = "", const string& tmppath = "", const string& webpath = "", const string& helpurl = "");

public:
	string acvpath;
	string monpath;
	string tmppath;
	string webpath;
	string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgFmncPath* comp);
	set<uint> diff(const StgFmncPath* comp);
};

/**
  * AlrFmnc
  */
namespace AlrFmnc {
	DpchEngFmncAlert* prepareAlrAbt(const ubigint jref, const uint ixFmncVLocale, Feed& feedFMcbAlert);
	DpchEngFmncAlert* prepareAlrPer(const ubigint jref, const uint ixFmncVLocale, const string& lineno, Feed& feedFMcbAlert);
	DpchEngFmncAlert* prepareAlrSav(const ubigint jref, const uint ixFmncVLocale, Feed& feedFMcbAlert);
};

/**
  * ReqFmnc
  */
class ReqFmnc {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const uint NONE = 0; // invalid
		static const uint WEB = 1; // web-client triggered ui file request (GET)
		static const uint CMD = 2; // command-line request
		static const uint REGULAR = 3; // web-client triggered Dpch request (POST+Dpch)
		static const uint NOTIFY = 4; // web-client triggered notify-on-Dpch request (POST/empty)
		static const uint POLL = 5; // web-client triggered Dpch poll request (POST/empty)
		static const uint UPLOAD = 6; // web-client triggered file upload request (POST)
		static const uint DOWNLOAD = 7; // web-client triggered file download request (GET)
		static const uint RET = 8; // op-engine or opprc triggered op return (DpchRet)
		static const uint TIMER = 9; // timer triggered request
		static const uint EXTCALL = 10; // externally triggered call request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const uint NONE = 0; // invalid
		static const uint RECEIVE = 1; // during data reception - appsrv internal
		static const uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const uint PRC = 3; // while being processesd by job processor - still in reqs list ; appsrv thread waiting on cReply
		static const uint REPLY = 4; // while reply being transmitted by appsrv - appsrv internal
	};

public:
	ReqFmnc(const uint ixVBasetype = VecVBasetype::NONE, const uint ixVState = VecVState::RECEIVE, const string& ip = "");
	~ReqFmnc();

public:
	uint ixVBasetype;
	uint ixVState;

	// specific data for base type CMD
	string cmd;

	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD, DOWNLOAD
	string ip;

	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, REGULAR, NOTIFY, UPLOAD, DOWNLOAD
	bool retain;
	pthread_mutex_t mcReady; // also protects compare/set of ixVState to REPLY
	pthread_cond_t cReady;

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	string filename; // full path
	fstream* file;
	size_t filelen;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	char* request;
	size_t requestlen;

	// specific data for base types CMD, REGULAR, NOTIFY, POLL, UPLOAD, DOWNLOAD, RET, TIMER
	ubigint jref;

	// specific data for base type TIMER
	ubigint wref;
	string sref;

	// specific data for base type EXTCALL
	Call* call;

	// specific data for base types CMD, REGULAR, UPLOAD, DOWNLOAD, RET, TIMER
	bool weak;

	// specific data for base type REGULAR
	DpchAppFmnc* dpchapp;

	// specific data for base types REGULAR, NOTIFY, POLL
	DpchEngFmnc* dpcheng;
	uint ixFmncVLocale;

	// specific data for base type RET
	DpchInvFmnc* dpchinv;
	DpchRetFmnc* dpchret;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	char* reply;
	size_t replylen;

public:
	void setStateReply();
};

/**
	* DcolFmnc
	*/
class DcolFmnc {

public:
	DcolFmnc(const ubigint jref = 0, const uint ixFmncVLocale = VecFmncVLocale::ENUS);
	~DcolFmnc();

public:
	ubigint jref;

	uint ixFmncVLocale;

	pthread_mutex_t mAccess;

	bool hot;

	list<DpchEngFmnc*> dpchs;

	ReqFmnc* req;

public:
	int lockAccess(const string& srefObject = "", const string& srefMember = "");
	int unlockAccess(const string& srefObject = "", const string& srefMember = "");
};

/**
  * JobFmnc
  */
class JobFmnc {

public:
	JobFmnc(XchgFmnc* xchg, const uint ixFmncVJob = 0, const ubigint jrefSup = 0, const uint ixFmncVLocale = VecFmncVLocale::ENUS, const bool prefmast = false);
	virtual ~JobFmnc();

public:
	XchgFmnc* xchg;

	ubigint jref;

	uint ixFmncVJob;

	ubigint jrefSup;
	set<ubigint> jrefsSub;

	uint ixFmncVLocale;

	ubigint jrefMast;
	list<ubigint> jrefsSlv;

	bool prefmast;

	pthread_mutex_t mAccess;

	bool muteRefresh;

	uint ixVSge;
	uint nextIxVSge;

	uint opNdone;
	uint opN;

	vector<DpchInvFmnc*> invs;

	pthread_mutex_t mOps;
	list<Op*> ops;
	string opsqkLast;

	ubigint wrefLast;
	ubigint wrefMin;

	ReqFmnc* reqCmd;

public:
	virtual DpchEngFmnc* getNewDpchEng(set<uint> items);

	virtual void refresh(DbsFmnc* dbsfmnc, set<uint>& moditems);
	void refreshWithDpchEng(DbsFmnc* dbsfmnc, DpchEngFmnc** dpcheng = NULL);

	virtual string getSquawk(DbsFmnc* dbsfmnc);

	virtual void giveupMaster(DbsFmnc* dbsfmnc);
	virtual void giveupSlave(DbsFmnc* dbsfmnc);
	virtual void becomeMaster(DbsFmnc* dbsfmnc);
	virtual void becomeSlave(DbsFmnc* dbsfmnc);

	virtual bool handleClaimMaster(DbsFmnc* dbsfmnc);
	virtual void handleRequest(DbsFmnc* dbsfmnc, ReqFmnc* req);
	virtual void handleCall(DbsFmnc* dbsfmnc, Call* call);

	int lockAccess(const string& srefObject, const string& srefMember);
	int trylockAccess(const string& srefObject, const string& srefMember);
	int unlockAccess(const string& srefObject, const string& srefMember);
	int lockAccess(const string& srefMember);
	int unlockAccess(const string& srefMember);

	void clearInvs();
	void addInv(DpchInvFmnc* inv);
	void addInvs(vector<DpchInvFmnc*>& _invs);
	void submitInvs(DbsFmnc* dbsfmnc, const uint emptyIxVSge, uint& _ixVSge);

	void clearOps();
	void addOp(DbsFmnc* dbsfmnc, DpchInvFmnc* inv);
	void removeOp(const ubigint oref);
	string getOpsqkLast();

	void callback(const uint _nextIxVSge);
	void invalidateWakeups();
};

/**
  * StmgrFmnc
  */
class StmgrFmnc {

public:
	StmgrFmnc(XchgFmnc* xchg, const ubigint jref, const uint ixVNonetype);
	~StmgrFmnc();

public:
	XchgFmnc* xchg;

	ubigint jref;
	uint ixVNonetype;

	Stcch* stcch;

	pthread_mutex_t mAccess;

public:
	void handleCall(DbsFmnc* dbsfmnc, Call* call);
	bool refresh(DbsFmnc* dbsfmnc, Stcchitem* stit);

	void begin();
	void commit();

	int lockAccess(const string& srefObject = "", const string& srefMember = "");
	int unlockAccess(const string& srefObject = "", const string& srefMember = "");
};

/**
  * WakeupFmnc
  */
class WakeupFmnc {

public:
	WakeupFmnc(XchgFmnc* xchg, const ubigint wref, const ubigint jref, const string sref, const unsigned int deltat = 0, const bool weak = false);

public:
	XchgFmnc* xchg;

	ubigint wref;

	ubigint jref;
	string sref;
	unsigned int deltat;
	bool weak;
};

/**
  * ExtcallFmnc
  */
class ExtcallFmnc {

public:
	ExtcallFmnc(XchgFmnc* xchg, Call* call);

public:
	XchgFmnc* xchg;
	Call* call;
};

/**
  * XchgdataFmncJobprc
  */
class XchgdataFmncJobprc {

public:
	XchgdataFmncJobprc();

public:
// IP datajobprc --- INSERT
};

/**
  * XchgdataFmncOpprc
  */
class XchgdataFmncOpprc {

public:
	XchgdataFmncOpprc();

public:
// IP dataopprc --- INSERT
};

/**
  * XchgFmnccmbd
  */
class XchgFmnccmbd {

public:
	XchgFmnccmbd();
	~XchgFmnccmbd();

public:
	StgFmnccmbd stgfmnccmbd;
	StgFmncDatabase stgfmncdatabase;
	StgFmncMonitor stgfmncmonitor;
	StgFmncPath stgfmncpath;

	XchgdataFmncJobprc datajobprc;
	XchgdataFmncOpprc dataopprc;

public:
// IP cust --- INSERT

public:
	// archive/temporary folder paths and help URL
	string acvpath;
	string tmppath;
	string helpurl;

	// root job
	ubigint jrefRoot;

	// job receiving commands
	ubigint jrefCmd;

	// scrambled ref codes
	pthread_mutex_t mScr;
	map<ubigint,string> scr;
	map<string,ubigint> descr;

	// monitor object
	DbsMon mon;

	// log file
	pthread_mutex_t mLogfile;

	// condition for job processors
	pthread_mutex_t mcJobprcs;
	pthread_cond_t cJobprcs;

	// condition for op processors
	pthread_mutex_t mcOpprcs;
	pthread_cond_t cOpprcs;

	// request list
	pthread_mutex_t mReqs;
	list<ReqFmnc*> reqs;

	// operation invocation list
	Refseq* orefseq;
	pthread_mutex_t mInvs;
	list<DpchInvFmnc*> invs;

	// presetting list
	pthread_mutex_t mPresets;
	multimap<pref_t,Preset*> presets;

	// stub manager list
	pthread_mutex_t mStmgrs;
	map<ubigint,StmgrFmnc*> stmgrs;

	// call listener list
	pthread_mutex_t mClstns;
	multimap<cref_t,Clstn*> clstns;
	multimap<cref2_t,cref_t> cref2sClstns;

	// dispatch collector list
	pthread_mutex_t mDcols;
	map<ubigint,DcolFmnc*> dcols;

	// job list
	Refseq* jrefseq;
	pthread_mutex_t mJobs;
	map<ubigint,JobFmnc*> jobs;

	// sequence for wakeup references
	Refseq* wrefseq;

public:
	// monitor object methods
	void startMon();
	void stopMon();

	// log file methods
	void appendToLogfile(const string& str);

	// request list methods
	void addReq(ReqFmnc* req);
	ReqFmnc* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsFmnc* dbsfmnc, const ubigint jref, vector<DpchInvFmnc*>& dpchinvs);
	DpchInvFmnc* pullFirstInv();

	// presetting methods
	Preset* addPreset(const uint ixFmncVPreset, const ubigint jref, const Arg& arg);

	Preset* addIxPreset(const uint ixFmncVPreset, const ubigint jref, const uint ix);
	Preset* addRefPreset(const uint ixFmncVPreset, const ubigint jref, const ubigint ref);
	Preset* addRefsPreset(const uint ixFmncVPreset, const ubigint jref, const vector<ubigint>& refs);
	Preset* addSrefPreset(const uint ixFmncVPreset, const ubigint jref, const string& sref);
	Preset* addIntvalPreset(const uint ixFmncVPreset, const ubigint jref, const int intval);
	Preset* addDblvalPreset(const uint ixFmncVPreset, const ubigint jref, const double dblval);
	Preset* addBoolvalPreset(const uint ixFmncVPreset, const ubigint jref, const bool boolval);
	Preset* addTxtvalPreset(const uint ixFmncVPreset, const ubigint jref, const string& txtval);

	Preset* getPresetByPref(const pref_t& pref);

	Arg getPreset(const uint ixFmncVPreset, const ubigint jref);

	uint getIxPreset(const uint ixFmncVPreset, const ubigint jref);
	ubigint getRefPreset(const uint ixFmncVPreset, const ubigint jref);
	vector<ubigint> getRefsPreset(const uint ixFmncVPreset, const ubigint jref);
	string getSrefPreset(const uint ixFmncVPreset, const ubigint jref);
	int getIntvalPreset(const uint ixFmncVPreset, const ubigint jref);
	double getDblvalPreset(const uint ixFmncVPreset, const ubigint jref);
	bool getBoolvalPreset(const uint ixFmncVPreset, const ubigint jref);
	string getTxtvalPreset(const uint ixFmncVPreset, const ubigint jref);

	void getPresetsByJref(const ubigint jref, vector<uint>& icsFmncVPreset, vector<Arg>& args);

	void removePreset(const uint ixFmncVPreset, const ubigint jref);
	void removePresetsByJref(const ubigint jref);

	// stub manager methods
	StmgrFmnc* addStmgr(const ubigint jref, const uint ixVNonetype);
	StmgrFmnc* getStmgrByJref(const ubigint jref);
	void removeStmgrByJref(const ubigint jref);

	// call listener list methods
	Clstn* addClstn(const uint ixFmncVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const Arg& argMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);

	Clstn* addIxClstn(const uint ixFmncVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addRefClstn(const uint ixFmncVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const ubigint refMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addIxRefClstn(const uint ixFmncVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const ubigint refMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addIxRefSrefClstn(const uint ixFmncVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const ubigint refMask, const string& srefMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);

	Clstn* addClstnStmgr(const uint ixFmncVCall, const ubigint jref);

	Clstn* getClstnByCref(const cref_t& cref);
	void getClstnsByJref(const ubigint jref, const bool stmgr, vector<uint>& icsFmncVCall, vector<uint>& icsVJobmask);

	void removeClstns(const uint ixFmncVCall, const ubigint jref, const bool stmgr = false);
	void removeClstnsByJref(const ubigint jref, const bool stmgr = false);

	// call methods
	void findJrefsByCall(Call* call, vector<ubigint>& jrefs, vector<bool>& stmgrs, vector<uint>& icsVJactype);

	void triggerCall(DbsFmnc* dbsfmnc, Call* call);

	bool triggerArgToArgCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const Arg& argInv, Arg& argRet);
	bool triggerCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref);
	bool triggerIxCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv);
	bool triggerRefCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const ubigint refInv);
	bool triggerIntvalCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const ubigint refInv);
	bool triggerIxSrefCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const string& srefInv);
	bool triggerIxIntvalCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const double dblvalInv);
	bool triggerToBoolvalCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, bool& boolvalRet);
	bool triggerRefToSrefCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const ubigint refInv, string& srefRet);
	bool triggerRefToBoolvalCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const ubigint refInv, uint& ixRet);
	bool triggerIxRefToRefCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const ubigint refInv, ubigint& refRet);
	bool triggerIxRefSrefCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv, ubigint& refRet);
	bool triggerRefToIxCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const ubigint refInv, uint& ixRet);
	bool triggerSrefToRefCall(DbsFmnc* dbsfmnc, const uint ixFmncVCall, const ubigint jref, const string& srefInv, ubigint& refRet);

	// dispatch collector list methods
	DcolFmnc* addDcol(const ubigint jref);
	DcolFmnc* getDcolByJref(const ubigint jref, const bool tree = true);
	void removeDcolByJref(const ubigint jref);

	void submitDpch(DpchEngFmnc* dpcheng);
	DpchEngFmnc* pullFirstDpch(DcolFmnc* dcol);

	// job list methods
	ubigint addJob(JobFmnc* job);
	ubigint addJob(DbsFmnc* dbsfmnc, JobFmnc* job);

	JobFmnc* getJobByJref(const ubigint jref);

	void removeJobByJref(const ubigint jref);

	void transferMaster(DbsFmnc* dbsfmnc, JobFmnc* fromjob, JobFmnc* tojob);
	void offerMaster(DbsFmnc* dbsfmnc, const ubigint jref);
	bool claimMaster(DbsFmnc* dbsfmnc, const ubigint jref);

	// timer methods
	ubigint addWakeup(const ubigint jref, const string sref, const unsigned int deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// external call methods
	static void runExtcall(void* arg);
};
#endif


