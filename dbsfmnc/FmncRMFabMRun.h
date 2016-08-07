/**
  * \file FmncRMFabMRun.h
  * database access for table TblFmncRMFabMRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMFABMRUN_H
#define FMNCRMFABMRUN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMFabMRun: record of TblFmncRMFabMRun
  */
class FmncRMFabMRun {

public:
	FmncRMFabMRun(const ubigint ref = 0, const ubigint refFmncMFab = 0, const ubigint refFmncMRun = 0);

public:
	ubigint ref;
	ubigint refFmncMFab;
	ubigint refFmncMRun;

public:
	bool operator==(const FmncRMFabMRun& comp);
	bool operator!=(const FmncRMFabMRun& comp);
};

/**
  * ListFmncRMFabMRun: recordset of TblFmncRMFabMRun
  */
class ListFmncRMFabMRun {

public:
	ListFmncRMFabMRun();
	ListFmncRMFabMRun(const ListFmncRMFabMRun& src);
	~ListFmncRMFabMRun();

	void clear();
	unsigned int size() const;
	void append(FmncRMFabMRun* rec);

	FmncRMFabMRun* operator[](const uint ix);
	ListFmncRMFabMRun& operator=(const ListFmncRMFabMRun& src);
	bool operator==(const ListFmncRMFabMRun& comp);
	bool operator!=(const ListFmncRMFabMRun& comp);

public:
	vector<FmncRMFabMRun*> nodes;
};

/**
  * TblFmncRMFabMRun: C++ wrapper for table TblFmncRMFabMRun
  */
class TblFmncRMFabMRun {

public:
	TblFmncRMFabMRun();
	virtual ~TblFmncRMFabMRun();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMFabMRun** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabMRun& rst);

	virtual void insertRec(FmncRMFabMRun* rec);
	ubigint insertNewRec(FmncRMFabMRun** rec = NULL, const ubigint refFmncMFab = 0, const ubigint refFmncMRun = 0);
	ubigint appendNewRecToRst(ListFmncRMFabMRun& rst, FmncRMFabMRun** rec = NULL, const ubigint refFmncMFab = 0, const ubigint refFmncMRun = 0);
	virtual void insertRst(ListFmncRMFabMRun& rst, bool transact = false);
	virtual void updateRec(FmncRMFabMRun* rec);
	virtual void updateRst(ListFmncRMFabMRun& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMFabMRun** rec);
	virtual ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMFabMRun& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMFabMRun: C++ wrapper for table TblFmncRMFabMRun (MySQL database)
  */
class MyTblFmncRMFabMRun : public TblFmncRMFabMRun, public MyTable {

public:
	MyTblFmncRMFabMRun();
	~MyTblFmncRMFabMRun();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFabMRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabMRun& rst);

	void insertRec(FmncRMFabMRun* rec);
	void insertRst(ListFmncRMFabMRun& rst, bool transact = false);
	void updateRec(FmncRMFabMRun* rec);
	void updateRst(ListFmncRMFabMRun& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFabMRun** rec);
	ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMFabMRun: C++ wrapper for table TblFmncRMFabMRun (PgSQL database)
  */
class PgTblFmncRMFabMRun : public TblFmncRMFabMRun, public PgTable {

public:
	PgTblFmncRMFabMRun();
	~PgTblFmncRMFabMRun();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMFabMRun** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMFabMRun& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMFabMRun** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFabMRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabMRun& rst);

	void insertRec(FmncRMFabMRun* rec);
	void insertRst(ListFmncRMFabMRun& rst, bool transact = false);
	void updateRec(FmncRMFabMRun* rec);
	void updateRst(ListFmncRMFabMRun& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFabMRun** rec);
	ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

