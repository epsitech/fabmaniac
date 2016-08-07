/**
  * \file FmncJMFabuserState.h
  * database access for table TblFmncJMFabuserState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMFABUSERSTATE_H
#define FMNCJMFABUSERSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMFabuserState: record of TblFmncJMFabuserState
  */
class FmncJMFabuserState {

public:
	FmncJMFabuserState(const ubigint ref = 0, const ubigint refFmncMFabuser = 0, const uint x1Startd = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refFmncMFabuser;
	uint x1Startd;
	uint ixVState;

public:
	bool operator==(const FmncJMFabuserState& comp);
	bool operator!=(const FmncJMFabuserState& comp);
};

/**
  * ListFmncJMFabuserState: recordset of TblFmncJMFabuserState
  */
class ListFmncJMFabuserState {

public:
	ListFmncJMFabuserState();
	ListFmncJMFabuserState(const ListFmncJMFabuserState& src);
	~ListFmncJMFabuserState();

	void clear();
	unsigned int size() const;
	void append(FmncJMFabuserState* rec);

	FmncJMFabuserState* operator[](const uint ix);
	ListFmncJMFabuserState& operator=(const ListFmncJMFabuserState& src);
	bool operator==(const ListFmncJMFabuserState& comp);
	bool operator!=(const ListFmncJMFabuserState& comp);

public:
	vector<FmncJMFabuserState*> nodes;
};

/**
  * TblFmncJMFabuserState: C++ wrapper for table TblFmncJMFabuserState
  */
class TblFmncJMFabuserState {

public:
	TblFmncJMFabuserState();
	virtual ~TblFmncJMFabuserState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMFabuserState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMFabuserState& rst);

	virtual void insertRec(FmncJMFabuserState* rec);
	ubigint insertNewRec(FmncJMFabuserState** rec = NULL, const ubigint refFmncMFabuser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncJMFabuserState& rst, FmncJMFabuserState** rec = NULL, const ubigint refFmncMFabuser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncJMFabuserState& rst, bool transact = false);
	virtual void updateRec(FmncJMFabuserState* rec);
	virtual void updateRst(ListFmncJMFabuserState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMFabuserState** rec);
	virtual bool loadRecByFusSta(ubigint refFmncMFabuser, uint x1Startd, FmncJMFabuserState** rec);
	virtual ubigint loadRstByFus(ubigint refFmncMFabuser, const bool append, ListFmncJMFabuserState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMFabuserState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMFabuserState: C++ wrapper for table TblFmncJMFabuserState (MySQL database)
  */
class MyTblFmncJMFabuserState : public TblFmncJMFabuserState, public MyTable {

public:
	MyTblFmncJMFabuserState();
	~MyTblFmncJMFabuserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMFabuserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMFabuserState& rst);

	void insertRec(FmncJMFabuserState* rec);
	void insertRst(ListFmncJMFabuserState& rst, bool transact = false);
	void updateRec(FmncJMFabuserState* rec);
	void updateRst(ListFmncJMFabuserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMFabuserState** rec);
	bool loadRecByFusSta(ubigint refFmncMFabuser, uint x1Startd, FmncJMFabuserState** rec);
	ubigint loadRstByFus(ubigint refFmncMFabuser, const bool append, ListFmncJMFabuserState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMFabuserState: C++ wrapper for table TblFmncJMFabuserState (PgSQL database)
  */
class PgTblFmncJMFabuserState : public TblFmncJMFabuserState, public PgTable {

public:
	PgTblFmncJMFabuserState();
	~PgTblFmncJMFabuserState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMFabuserState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMFabuserState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMFabuserState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMFabuserState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMFabuserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMFabuserState& rst);

	void insertRec(FmncJMFabuserState* rec);
	void insertRst(ListFmncJMFabuserState& rst, bool transact = false);
	void updateRec(FmncJMFabuserState* rec);
	void updateRst(ListFmncJMFabuserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMFabuserState** rec);
	bool loadRecByFusSta(ubigint refFmncMFabuser, uint x1Startd, FmncJMFabuserState** rec);
	ubigint loadRstByFus(ubigint refFmncMFabuser, const bool append, ListFmncJMFabuserState& rst);
};
// IP pgTbl --- END

#endif

