/**
  * \file FmncJMPurchorderState.h
  * database access for table TblFmncJMPurchorderState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMPURCHORDERSTATE_H
#define FMNCJMPURCHORDERSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMPurchorderState: record of TblFmncJMPurchorderState
  */
class FmncJMPurchorderState {

public:
	FmncJMPurchorderState(const ubigint ref = 0, const ubigint refFmncMPurchorder = 0, const uint x1Start = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refFmncMPurchorder;
	uint x1Start;
	uint ixVState;

public:
	bool operator==(const FmncJMPurchorderState& comp);
	bool operator!=(const FmncJMPurchorderState& comp);
};

/**
  * ListFmncJMPurchorderState: recordset of TblFmncJMPurchorderState
  */
class ListFmncJMPurchorderState {

public:
	ListFmncJMPurchorderState();
	ListFmncJMPurchorderState(const ListFmncJMPurchorderState& src);
	~ListFmncJMPurchorderState();

	void clear();
	unsigned int size() const;
	void append(FmncJMPurchorderState* rec);

	FmncJMPurchorderState* operator[](const uint ix);
	ListFmncJMPurchorderState& operator=(const ListFmncJMPurchorderState& src);
	bool operator==(const ListFmncJMPurchorderState& comp);
	bool operator!=(const ListFmncJMPurchorderState& comp);

public:
	vector<FmncJMPurchorderState*> nodes;
};

/**
  * TblFmncJMPurchorderState: C++ wrapper for table TblFmncJMPurchorderState
  */
class TblFmncJMPurchorderState {

public:
	TblFmncJMPurchorderState();
	virtual ~TblFmncJMPurchorderState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMPurchorderState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMPurchorderState& rst);

	virtual void insertRec(FmncJMPurchorderState* rec);
	ubigint insertNewRec(FmncJMPurchorderState** rec = NULL, const ubigint refFmncMPurchorder = 0, const uint x1Start = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncJMPurchorderState& rst, FmncJMPurchorderState** rec = NULL, const ubigint refFmncMPurchorder = 0, const uint x1Start = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncJMPurchorderState& rst, bool transact = false);
	virtual void updateRec(FmncJMPurchorderState* rec);
	virtual void updateRst(ListFmncJMPurchorderState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMPurchorderState** rec);
	virtual bool loadRecByPcoSta(ubigint refFmncMPurchorder, uint x1Start, FmncJMPurchorderState** rec);
	virtual ubigint loadRstByPco(ubigint refFmncMPurchorder, const bool append, ListFmncJMPurchorderState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMPurchorderState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMPurchorderState: C++ wrapper for table TblFmncJMPurchorderState (MySQL database)
  */
class MyTblFmncJMPurchorderState : public TblFmncJMPurchorderState, public MyTable {

public:
	MyTblFmncJMPurchorderState();
	~MyTblFmncJMPurchorderState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMPurchorderState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMPurchorderState& rst);

	void insertRec(FmncJMPurchorderState* rec);
	void insertRst(ListFmncJMPurchorderState& rst, bool transact = false);
	void updateRec(FmncJMPurchorderState* rec);
	void updateRst(ListFmncJMPurchorderState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMPurchorderState** rec);
	bool loadRecByPcoSta(ubigint refFmncMPurchorder, uint x1Start, FmncJMPurchorderState** rec);
	ubigint loadRstByPco(ubigint refFmncMPurchorder, const bool append, ListFmncJMPurchorderState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMPurchorderState: C++ wrapper for table TblFmncJMPurchorderState (PgSQL database)
  */
class PgTblFmncJMPurchorderState : public TblFmncJMPurchorderState, public PgTable {

public:
	PgTblFmncJMPurchorderState();
	~PgTblFmncJMPurchorderState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMPurchorderState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMPurchorderState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMPurchorderState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMPurchorderState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMPurchorderState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMPurchorderState& rst);

	void insertRec(FmncJMPurchorderState* rec);
	void insertRst(ListFmncJMPurchorderState& rst, bool transact = false);
	void updateRec(FmncJMPurchorderState* rec);
	void updateRst(ListFmncJMPurchorderState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMPurchorderState** rec);
	bool loadRecByPcoSta(ubigint refFmncMPurchorder, uint x1Start, FmncJMPurchorderState** rec);
	ubigint loadRstByPco(ubigint refFmncMPurchorder, const bool append, ListFmncJMPurchorderState& rst);
};
// IP pgTbl --- END

#endif

