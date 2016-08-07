/**
  * \file FmncJMSampleState.h
  * database access for table TblFmncJMSampleState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMSAMPLESTATE_H
#define FMNCJMSAMPLESTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMSampleState: record of TblFmncJMSampleState
  */
class FmncJMSampleState {

public:
	FmncJMSampleState(const ubigint ref = 0, const ubigint refFmncMSample = 0, const uint x1Start = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refFmncMSample;
	uint x1Start;
	uint ixVState;

public:
	bool operator==(const FmncJMSampleState& comp);
	bool operator!=(const FmncJMSampleState& comp);
};

/**
  * ListFmncJMSampleState: recordset of TblFmncJMSampleState
  */
class ListFmncJMSampleState {

public:
	ListFmncJMSampleState();
	ListFmncJMSampleState(const ListFmncJMSampleState& src);
	~ListFmncJMSampleState();

	void clear();
	unsigned int size() const;
	void append(FmncJMSampleState* rec);

	FmncJMSampleState* operator[](const uint ix);
	ListFmncJMSampleState& operator=(const ListFmncJMSampleState& src);
	bool operator==(const ListFmncJMSampleState& comp);
	bool operator!=(const ListFmncJMSampleState& comp);

public:
	vector<FmncJMSampleState*> nodes;
};

/**
  * TblFmncJMSampleState: C++ wrapper for table TblFmncJMSampleState
  */
class TblFmncJMSampleState {

public:
	TblFmncJMSampleState();
	virtual ~TblFmncJMSampleState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMSampleState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMSampleState& rst);

	virtual void insertRec(FmncJMSampleState* rec);
	ubigint insertNewRec(FmncJMSampleState** rec = NULL, const ubigint refFmncMSample = 0, const uint x1Start = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncJMSampleState& rst, FmncJMSampleState** rec = NULL, const ubigint refFmncMSample = 0, const uint x1Start = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncJMSampleState& rst, bool transact = false);
	virtual void updateRec(FmncJMSampleState* rec);
	virtual void updateRst(ListFmncJMSampleState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMSampleState** rec);
	virtual bool loadRecBySmpSta(ubigint refFmncMSample, uint x1Start, FmncJMSampleState** rec);
	virtual ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstBySmp(ubigint refFmncMSample, const bool append, ListFmncJMSampleState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMSampleState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMSampleState: C++ wrapper for table TblFmncJMSampleState (MySQL database)
  */
class MyTblFmncJMSampleState : public TblFmncJMSampleState, public MyTable {

public:
	MyTblFmncJMSampleState();
	~MyTblFmncJMSampleState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMSampleState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMSampleState& rst);

	void insertRec(FmncJMSampleState* rec);
	void insertRst(ListFmncJMSampleState& rst, bool transact = false);
	void updateRec(FmncJMSampleState* rec);
	void updateRst(ListFmncJMSampleState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMSampleState** rec);
	bool loadRecBySmpSta(ubigint refFmncMSample, uint x1Start, FmncJMSampleState** rec);
	ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySmp(ubigint refFmncMSample, const bool append, ListFmncJMSampleState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMSampleState: C++ wrapper for table TblFmncJMSampleState (PgSQL database)
  */
class PgTblFmncJMSampleState : public TblFmncJMSampleState, public PgTable {

public:
	PgTblFmncJMSampleState();
	~PgTblFmncJMSampleState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMSampleState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMSampleState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMSampleState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMSampleState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMSampleState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMSampleState& rst);

	void insertRec(FmncJMSampleState* rec);
	void insertRst(ListFmncJMSampleState& rst, bool transact = false);
	void updateRec(FmncJMSampleState* rec);
	void updateRst(ListFmncJMSampleState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMSampleState** rec);
	bool loadRecBySmpSta(ubigint refFmncMSample, uint x1Start, FmncJMSampleState** rec);
	ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySmp(ubigint refFmncMSample, const bool append, ListFmncJMSampleState& rst);
};
// IP pgTbl --- END

#endif

