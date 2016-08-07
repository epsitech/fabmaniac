/**
  * \file FmncJMRunState.h
  * database access for table TblFmncJMRunState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMRUNSTATE_H
#define FMNCJMRUNSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMRunState: record of TblFmncJMRunState
  */
class FmncJMRunState {

public:
	FmncJMRunState(const ubigint ref = 0, const ubigint refFmncMRun = 0, const uint x1Start = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refFmncMRun;
	uint x1Start;
	uint ixVState;

public:
	bool operator==(const FmncJMRunState& comp);
	bool operator!=(const FmncJMRunState& comp);
};

/**
  * ListFmncJMRunState: recordset of TblFmncJMRunState
  */
class ListFmncJMRunState {

public:
	ListFmncJMRunState();
	ListFmncJMRunState(const ListFmncJMRunState& src);
	~ListFmncJMRunState();

	void clear();
	unsigned int size() const;
	void append(FmncJMRunState* rec);

	FmncJMRunState* operator[](const uint ix);
	ListFmncJMRunState& operator=(const ListFmncJMRunState& src);
	bool operator==(const ListFmncJMRunState& comp);
	bool operator!=(const ListFmncJMRunState& comp);

public:
	vector<FmncJMRunState*> nodes;
};

/**
  * TblFmncJMRunState: C++ wrapper for table TblFmncJMRunState
  */
class TblFmncJMRunState {

public:
	TblFmncJMRunState();
	virtual ~TblFmncJMRunState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMRunState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMRunState& rst);

	virtual void insertRec(FmncJMRunState* rec);
	ubigint insertNewRec(FmncJMRunState** rec = NULL, const ubigint refFmncMRun = 0, const uint x1Start = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncJMRunState& rst, FmncJMRunState** rec = NULL, const ubigint refFmncMRun = 0, const uint x1Start = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncJMRunState& rst, bool transact = false);
	virtual void updateRec(FmncJMRunState* rec);
	virtual void updateRst(ListFmncJMRunState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMRunState** rec);
	virtual bool loadRecByRunSta(ubigint refFmncMRun, uint x1Start, FmncJMRunState** rec);
	virtual ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByRun(ubigint refFmncMRun, const bool append, ListFmncJMRunState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMRunState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMRunState: C++ wrapper for table TblFmncJMRunState (MySQL database)
  */
class MyTblFmncJMRunState : public TblFmncJMRunState, public MyTable {

public:
	MyTblFmncJMRunState();
	~MyTblFmncJMRunState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMRunState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMRunState& rst);

	void insertRec(FmncJMRunState* rec);
	void insertRst(ListFmncJMRunState& rst, bool transact = false);
	void updateRec(FmncJMRunState* rec);
	void updateRst(ListFmncJMRunState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMRunState** rec);
	bool loadRecByRunSta(ubigint refFmncMRun, uint x1Start, FmncJMRunState** rec);
	ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRun(ubigint refFmncMRun, const bool append, ListFmncJMRunState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMRunState: C++ wrapper for table TblFmncJMRunState (PgSQL database)
  */
class PgTblFmncJMRunState : public TblFmncJMRunState, public PgTable {

public:
	PgTblFmncJMRunState();
	~PgTblFmncJMRunState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMRunState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMRunState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMRunState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMRunState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMRunState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMRunState& rst);

	void insertRec(FmncJMRunState* rec);
	void insertRst(ListFmncJMRunState& rst, bool transact = false);
	void updateRec(FmncJMRunState* rec);
	void updateRst(ListFmncJMRunState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMRunState** rec);
	bool loadRecByRunSta(ubigint refFmncMRun, uint x1Start, FmncJMRunState** rec);
	ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRun(ubigint refFmncMRun, const bool append, ListFmncJMRunState& rst);
};
// IP pgTbl --- END

#endif

