/**
  * \file FmncJMFabprojectState.h
  * database access for table TblFmncJMFabprojectState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMFABPROJECTSTATE_H
#define FMNCJMFABPROJECTSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMFabprojectState: record of TblFmncJMFabprojectState
  */
class FmncJMFabprojectState {

public:
	FmncJMFabprojectState(const ubigint ref = 0, const ubigint refFmncMFabproject = 0, const uint x1Startd = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refFmncMFabproject;
	uint x1Startd;
	uint ixVState;

public:
	bool operator==(const FmncJMFabprojectState& comp);
	bool operator!=(const FmncJMFabprojectState& comp);
};

/**
  * ListFmncJMFabprojectState: recordset of TblFmncJMFabprojectState
  */
class ListFmncJMFabprojectState {

public:
	ListFmncJMFabprojectState();
	ListFmncJMFabprojectState(const ListFmncJMFabprojectState& src);
	~ListFmncJMFabprojectState();

	void clear();
	unsigned int size() const;
	void append(FmncJMFabprojectState* rec);

	FmncJMFabprojectState* operator[](const uint ix);
	ListFmncJMFabprojectState& operator=(const ListFmncJMFabprojectState& src);
	bool operator==(const ListFmncJMFabprojectState& comp);
	bool operator!=(const ListFmncJMFabprojectState& comp);

public:
	vector<FmncJMFabprojectState*> nodes;
};

/**
  * TblFmncJMFabprojectState: C++ wrapper for table TblFmncJMFabprojectState
  */
class TblFmncJMFabprojectState {

public:
	TblFmncJMFabprojectState();
	virtual ~TblFmncJMFabprojectState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMFabprojectState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMFabprojectState& rst);

	virtual void insertRec(FmncJMFabprojectState* rec);
	ubigint insertNewRec(FmncJMFabprojectState** rec = NULL, const ubigint refFmncMFabproject = 0, const uint x1Startd = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncJMFabprojectState& rst, FmncJMFabprojectState** rec = NULL, const ubigint refFmncMFabproject = 0, const uint x1Startd = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncJMFabprojectState& rst, bool transact = false);
	virtual void updateRec(FmncJMFabprojectState* rec);
	virtual void updateRst(ListFmncJMFabprojectState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMFabprojectState** rec);
	virtual bool loadRecByFpjSta(ubigint refFmncMFabproject, uint x1Startd, FmncJMFabprojectState** rec);
	virtual ubigint loadRstByFpj(ubigint refFmncMFabproject, const bool append, ListFmncJMFabprojectState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMFabprojectState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMFabprojectState: C++ wrapper for table TblFmncJMFabprojectState (MySQL database)
  */
class MyTblFmncJMFabprojectState : public TblFmncJMFabprojectState, public MyTable {

public:
	MyTblFmncJMFabprojectState();
	~MyTblFmncJMFabprojectState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMFabprojectState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMFabprojectState& rst);

	void insertRec(FmncJMFabprojectState* rec);
	void insertRst(ListFmncJMFabprojectState& rst, bool transact = false);
	void updateRec(FmncJMFabprojectState* rec);
	void updateRst(ListFmncJMFabprojectState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMFabprojectState** rec);
	bool loadRecByFpjSta(ubigint refFmncMFabproject, uint x1Startd, FmncJMFabprojectState** rec);
	ubigint loadRstByFpj(ubigint refFmncMFabproject, const bool append, ListFmncJMFabprojectState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMFabprojectState: C++ wrapper for table TblFmncJMFabprojectState (PgSQL database)
  */
class PgTblFmncJMFabprojectState : public TblFmncJMFabprojectState, public PgTable {

public:
	PgTblFmncJMFabprojectState();
	~PgTblFmncJMFabprojectState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMFabprojectState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMFabprojectState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMFabprojectState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMFabprojectState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMFabprojectState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMFabprojectState& rst);

	void insertRec(FmncJMFabprojectState* rec);
	void insertRst(ListFmncJMFabprojectState& rst, bool transact = false);
	void updateRec(FmncJMFabprojectState* rec);
	void updateRst(ListFmncJMFabprojectState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMFabprojectState** rec);
	bool loadRecByFpjSta(ubigint refFmncMFabproject, uint x1Startd, FmncJMFabprojectState** rec);
	ubigint loadRstByFpj(ubigint refFmncMFabproject, const bool append, ListFmncJMFabprojectState& rst);
};
// IP pgTbl --- END

#endif

