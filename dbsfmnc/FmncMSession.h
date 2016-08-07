/**
  * \file FmncMSession.h
  * database access for table TblFmncMSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMSESSION_H
#define FMNCMSESSION_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMSession: record of TblFmncMSession
  */
class FmncMSession {

public:
	FmncMSession(const ubigint ref = 0, const ubigint refFmncMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");

public:
	ubigint ref;
	ubigint refFmncMUser;
	uint start;
	uint stop;
	string Ip;

public:
	bool operator==(const FmncMSession& comp);
	bool operator!=(const FmncMSession& comp);
};

/**
  * ListFmncMSession: recordset of TblFmncMSession
  */
class ListFmncMSession {

public:
	ListFmncMSession();
	ListFmncMSession(const ListFmncMSession& src);
	~ListFmncMSession();

	void clear();
	unsigned int size() const;
	void append(FmncMSession* rec);

	FmncMSession* operator[](const uint ix);
	ListFmncMSession& operator=(const ListFmncMSession& src);
	bool operator==(const ListFmncMSession& comp);
	bool operator!=(const ListFmncMSession& comp);

public:
	vector<FmncMSession*> nodes;
};

/**
  * TblFmncMSession: C++ wrapper for table TblFmncMSession
  */
class TblFmncMSession {

public:
	TblFmncMSession();
	virtual ~TblFmncMSession();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMSession** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMSession& rst);

	virtual void insertRec(FmncMSession* rec);
	ubigint insertNewRec(FmncMSession** rec = NULL, const ubigint refFmncMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");
	ubigint appendNewRecToRst(ListFmncMSession& rst, FmncMSession** rec = NULL, const ubigint refFmncMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");
	virtual void insertRst(ListFmncMSession& rst, bool transact = false);
	virtual void updateRec(FmncMSession* rec);
	virtual void updateRst(ListFmncMSession& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMSession** rec);
	virtual ubigint loadRefsByUsr(ubigint refFmncMUser, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncMSession& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMSession& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMSession: C++ wrapper for table TblFmncMSession (MySQL database)
  */
class MyTblFmncMSession : public TblFmncMSession, public MyTable {

public:
	MyTblFmncMSession();
	~MyTblFmncMSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMSession& rst);

	void insertRec(FmncMSession* rec);
	void insertRst(ListFmncMSession& rst, bool transact = false);
	void updateRec(FmncMSession* rec);
	void updateRst(ListFmncMSession& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMSession** rec);
	ubigint loadRefsByUsr(ubigint refFmncMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncMSession& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMSession: C++ wrapper for table TblFmncMSession (PgSQL database)
  */
class PgTblFmncMSession : public TblFmncMSession, public PgTable {

public:
	PgTblFmncMSession();
	~PgTblFmncMSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMSession** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMSession& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMSession** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncMSession& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncMSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMSession& rst);

	void insertRec(FmncMSession* rec);
	void insertRst(ListFmncMSession& rst, bool transact = false);
	void updateRec(FmncMSession* rec);
	void updateRst(ListFmncMSession& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMSession** rec);
	ubigint loadRefsByUsr(ubigint refFmncMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncMSession& rst);
};
// IP pgTbl --- END

#endif

