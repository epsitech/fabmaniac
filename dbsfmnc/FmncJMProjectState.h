/**
  * \file FmncJMProjectState.h
  * database access for table TblFmncJMProjectState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMPROJECTSTATE_H
#define FMNCJMPROJECTSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMProjectState: record of TblFmncJMProjectState
  */
class FmncJMProjectState {

public:
	FmncJMProjectState(const ubigint ref = 0, const ubigint refFmncMProject = 0, const uint x1Start = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refFmncMProject;
	uint x1Start;
	uint ixVState;

public:
	bool operator==(const FmncJMProjectState& comp);
	bool operator!=(const FmncJMProjectState& comp);
};

/**
  * ListFmncJMProjectState: recordset of TblFmncJMProjectState
  */
class ListFmncJMProjectState {

public:
	ListFmncJMProjectState();
	ListFmncJMProjectState(const ListFmncJMProjectState& src);
	~ListFmncJMProjectState();

	void clear();
	unsigned int size() const;
	void append(FmncJMProjectState* rec);

	FmncJMProjectState* operator[](const uint ix);
	ListFmncJMProjectState& operator=(const ListFmncJMProjectState& src);
	bool operator==(const ListFmncJMProjectState& comp);
	bool operator!=(const ListFmncJMProjectState& comp);

public:
	vector<FmncJMProjectState*> nodes;
};

/**
  * TblFmncJMProjectState: C++ wrapper for table TblFmncJMProjectState
  */
class TblFmncJMProjectState {

public:
	TblFmncJMProjectState();
	virtual ~TblFmncJMProjectState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMProjectState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMProjectState& rst);

	virtual void insertRec(FmncJMProjectState* rec);
	ubigint insertNewRec(FmncJMProjectState** rec = NULL, const ubigint refFmncMProject = 0, const uint x1Start = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncJMProjectState& rst, FmncJMProjectState** rec = NULL, const ubigint refFmncMProject = 0, const uint x1Start = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncJMProjectState& rst, bool transact = false);
	virtual void updateRec(FmncJMProjectState* rec);
	virtual void updateRst(ListFmncJMProjectState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMProjectState** rec);
	virtual bool loadRecByPrjSta(ubigint refFmncMProject, uint x1Start, FmncJMProjectState** rec);
	virtual ubigint loadRefsByPrj(ubigint refFmncMProject, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByPrj(ubigint refFmncMProject, const bool append, ListFmncJMProjectState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMProjectState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMProjectState: C++ wrapper for table TblFmncJMProjectState (MySQL database)
  */
class MyTblFmncJMProjectState : public TblFmncJMProjectState, public MyTable {

public:
	MyTblFmncJMProjectState();
	~MyTblFmncJMProjectState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMProjectState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMProjectState& rst);

	void insertRec(FmncJMProjectState* rec);
	void insertRst(ListFmncJMProjectState& rst, bool transact = false);
	void updateRec(FmncJMProjectState* rec);
	void updateRst(ListFmncJMProjectState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMProjectState** rec);
	bool loadRecByPrjSta(ubigint refFmncMProject, uint x1Start, FmncJMProjectState** rec);
	ubigint loadRefsByPrj(ubigint refFmncMProject, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrj(ubigint refFmncMProject, const bool append, ListFmncJMProjectState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMProjectState: C++ wrapper for table TblFmncJMProjectState (PgSQL database)
  */
class PgTblFmncJMProjectState : public TblFmncJMProjectState, public PgTable {

public:
	PgTblFmncJMProjectState();
	~PgTblFmncJMProjectState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMProjectState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMProjectState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMProjectState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMProjectState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMProjectState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMProjectState& rst);

	void insertRec(FmncJMProjectState* rec);
	void insertRst(ListFmncJMProjectState& rst, bool transact = false);
	void updateRec(FmncJMProjectState* rec);
	void updateRst(ListFmncJMProjectState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMProjectState** rec);
	bool loadRecByPrjSta(ubigint refFmncMProject, uint x1Start, FmncJMProjectState** rec);
	ubigint loadRefsByPrj(ubigint refFmncMProject, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrj(ubigint refFmncMProject, const bool append, ListFmncJMProjectState& rst);
};
// IP pgTbl --- END

#endif

