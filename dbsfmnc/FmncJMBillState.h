/**
  * \file FmncJMBillState.h
  * database access for table TblFmncJMBillState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMBILLSTATE_H
#define FMNCJMBILLSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMBillState: record of TblFmncJMBillState
  */
class FmncJMBillState {

public:
	FmncJMBillState(const ubigint ref = 0, const ubigint refFmncMBill = 0, const uint x1Startd = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refFmncMBill;
	uint x1Startd;
	uint ixVState;

public:
	bool operator==(const FmncJMBillState& comp);
	bool operator!=(const FmncJMBillState& comp);
};

/**
  * ListFmncJMBillState: recordset of TblFmncJMBillState
  */
class ListFmncJMBillState {

public:
	ListFmncJMBillState();
	ListFmncJMBillState(const ListFmncJMBillState& src);
	~ListFmncJMBillState();

	void clear();
	unsigned int size() const;
	void append(FmncJMBillState* rec);

	FmncJMBillState* operator[](const uint ix);
	ListFmncJMBillState& operator=(const ListFmncJMBillState& src);
	bool operator==(const ListFmncJMBillState& comp);
	bool operator!=(const ListFmncJMBillState& comp);

public:
	vector<FmncJMBillState*> nodes;
};

/**
  * TblFmncJMBillState: C++ wrapper for table TblFmncJMBillState
  */
class TblFmncJMBillState {

public:
	TblFmncJMBillState();
	virtual ~TblFmncJMBillState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMBillState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMBillState& rst);

	virtual void insertRec(FmncJMBillState* rec);
	ubigint insertNewRec(FmncJMBillState** rec = NULL, const ubigint refFmncMBill = 0, const uint x1Startd = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncJMBillState& rst, FmncJMBillState** rec = NULL, const ubigint refFmncMBill = 0, const uint x1Startd = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncJMBillState& rst, bool transact = false);
	virtual void updateRec(FmncJMBillState* rec);
	virtual void updateRst(ListFmncJMBillState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMBillState** rec);
	virtual bool loadRecByBilSta(ubigint refFmncMBill, uint x1Startd, FmncJMBillState** rec);
	virtual ubigint loadRstByBil(ubigint refFmncMBill, const bool append, ListFmncJMBillState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMBillState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMBillState: C++ wrapper for table TblFmncJMBillState (MySQL database)
  */
class MyTblFmncJMBillState : public TblFmncJMBillState, public MyTable {

public:
	MyTblFmncJMBillState();
	~MyTblFmncJMBillState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMBillState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMBillState& rst);

	void insertRec(FmncJMBillState* rec);
	void insertRst(ListFmncJMBillState& rst, bool transact = false);
	void updateRec(FmncJMBillState* rec);
	void updateRst(ListFmncJMBillState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMBillState** rec);
	bool loadRecByBilSta(ubigint refFmncMBill, uint x1Startd, FmncJMBillState** rec);
	ubigint loadRstByBil(ubigint refFmncMBill, const bool append, ListFmncJMBillState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMBillState: C++ wrapper for table TblFmncJMBillState (PgSQL database)
  */
class PgTblFmncJMBillState : public TblFmncJMBillState, public PgTable {

public:
	PgTblFmncJMBillState();
	~PgTblFmncJMBillState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMBillState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMBillState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMBillState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMBillState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMBillState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMBillState& rst);

	void insertRec(FmncJMBillState* rec);
	void insertRst(ListFmncJMBillState& rst, bool transact = false);
	void updateRec(FmncJMBillState* rec);
	void updateRst(ListFmncJMBillState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMBillState** rec);
	bool loadRecByBilSta(ubigint refFmncMBill, uint x1Startd, FmncJMBillState** rec);
	ubigint loadRstByBil(ubigint refFmncMBill, const bool append, ListFmncJMBillState& rst);
};
// IP pgTbl --- END

#endif

