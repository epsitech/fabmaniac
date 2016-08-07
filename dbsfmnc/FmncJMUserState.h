/**
  * \file FmncJMUserState.h
  * database access for table TblFmncJMUserState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMUSERSTATE_H
#define FMNCJMUSERSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMUserState: record of TblFmncJMUserState
  */
class FmncJMUserState {

public:
	FmncJMUserState(const ubigint ref = 0, const ubigint refFmncMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refFmncMUser;
	uint x1Startd;
	uint ixVState;

public:
	bool operator==(const FmncJMUserState& comp);
	bool operator!=(const FmncJMUserState& comp);
};

/**
  * ListFmncJMUserState: recordset of TblFmncJMUserState
  */
class ListFmncJMUserState {

public:
	ListFmncJMUserState();
	ListFmncJMUserState(const ListFmncJMUserState& src);
	~ListFmncJMUserState();

	void clear();
	unsigned int size() const;
	void append(FmncJMUserState* rec);

	FmncJMUserState* operator[](const uint ix);
	ListFmncJMUserState& operator=(const ListFmncJMUserState& src);
	bool operator==(const ListFmncJMUserState& comp);
	bool operator!=(const ListFmncJMUserState& comp);

public:
	vector<FmncJMUserState*> nodes;
};

/**
  * TblFmncJMUserState: C++ wrapper for table TblFmncJMUserState
  */
class TblFmncJMUserState {

public:
	TblFmncJMUserState();
	virtual ~TblFmncJMUserState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMUserState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMUserState& rst);

	virtual void insertRec(FmncJMUserState* rec);
	ubigint insertNewRec(FmncJMUserState** rec = NULL, const ubigint refFmncMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncJMUserState& rst, FmncJMUserState** rec = NULL, const ubigint refFmncMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncJMUserState& rst, bool transact = false);
	virtual void updateRec(FmncJMUserState* rec);
	virtual void updateRst(ListFmncJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMUserState** rec);
	virtual bool loadRecByUsrSta(ubigint refFmncMUser, uint x1Startd, FmncJMUserState** rec);
	virtual ubigint loadRefsByUsr(ubigint refFmncMUser, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncJMUserState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMUserState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMUserState: C++ wrapper for table TblFmncJMUserState (MySQL database)
  */
class MyTblFmncJMUserState : public TblFmncJMUserState, public MyTable {

public:
	MyTblFmncJMUserState();
	~MyTblFmncJMUserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMUserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMUserState& rst);

	void insertRec(FmncJMUserState* rec);
	void insertRst(ListFmncJMUserState& rst, bool transact = false);
	void updateRec(FmncJMUserState* rec);
	void updateRst(ListFmncJMUserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMUserState** rec);
	bool loadRecByUsrSta(ubigint refFmncMUser, uint x1Startd, FmncJMUserState** rec);
	ubigint loadRefsByUsr(ubigint refFmncMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncJMUserState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMUserState: C++ wrapper for table TblFmncJMUserState (PgSQL database)
  */
class PgTblFmncJMUserState : public TblFmncJMUserState, public PgTable {

public:
	PgTblFmncJMUserState();
	~PgTblFmncJMUserState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMUserState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMUserState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMUserState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMUserState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMUserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMUserState& rst);

	void insertRec(FmncJMUserState* rec);
	void insertRst(ListFmncJMUserState& rst, bool transact = false);
	void updateRec(FmncJMUserState* rec);
	void updateRst(ListFmncJMUserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMUserState** rec);
	bool loadRecByUsrSta(ubigint refFmncMUser, uint x1Startd, FmncJMUserState** rec);
	ubigint loadRefsByUsr(ubigint refFmncMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncJMUserState& rst);
};
// IP pgTbl --- END

#endif

