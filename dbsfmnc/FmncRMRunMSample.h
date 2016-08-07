/**
  * \file FmncRMRunMSample.h
  * database access for table TblFmncRMRunMSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMRUNMSAMPLE_H
#define FMNCRMRUNMSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMRunMSample: record of TblFmncRMRunMSample
  */
class FmncRMRunMSample {

public:
	FmncRMRunMSample(const ubigint ref = 0, const ubigint refFmncMRun = 0, const ubigint refFmncMSample = 0);

public:
	ubigint ref;
	ubigint refFmncMRun;
	ubigint refFmncMSample;

public:
	bool operator==(const FmncRMRunMSample& comp);
	bool operator!=(const FmncRMRunMSample& comp);
};

/**
  * ListFmncRMRunMSample: recordset of TblFmncRMRunMSample
  */
class ListFmncRMRunMSample {

public:
	ListFmncRMRunMSample();
	ListFmncRMRunMSample(const ListFmncRMRunMSample& src);
	~ListFmncRMRunMSample();

	void clear();
	unsigned int size() const;
	void append(FmncRMRunMSample* rec);

	FmncRMRunMSample* operator[](const uint ix);
	ListFmncRMRunMSample& operator=(const ListFmncRMRunMSample& src);
	bool operator==(const ListFmncRMRunMSample& comp);
	bool operator!=(const ListFmncRMRunMSample& comp);

public:
	vector<FmncRMRunMSample*> nodes;
};

/**
  * TblFmncRMRunMSample: C++ wrapper for table TblFmncRMRunMSample
  */
class TblFmncRMRunMSample {

public:
	TblFmncRMRunMSample();
	virtual ~TblFmncRMRunMSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMRunMSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMRunMSample& rst);

	virtual void insertRec(FmncRMRunMSample* rec);
	ubigint insertNewRec(FmncRMRunMSample** rec = NULL, const ubigint refFmncMRun = 0, const ubigint refFmncMSample = 0);
	ubigint appendNewRecToRst(ListFmncRMRunMSample& rst, FmncRMRunMSample** rec = NULL, const ubigint refFmncMRun = 0, const ubigint refFmncMSample = 0);
	virtual void insertRst(ListFmncRMRunMSample& rst, bool transact = false);
	virtual void updateRec(FmncRMRunMSample* rec);
	virtual void updateRst(ListFmncRMRunMSample& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMRunMSample** rec);
	virtual ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMRunMSample& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMRunMSample: C++ wrapper for table TblFmncRMRunMSample (MySQL database)
  */
class MyTblFmncRMRunMSample : public TblFmncRMRunMSample, public MyTable {

public:
	MyTblFmncRMRunMSample();
	~MyTblFmncRMRunMSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMRunMSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMRunMSample& rst);

	void insertRec(FmncRMRunMSample* rec);
	void insertRst(ListFmncRMRunMSample& rst, bool transact = false);
	void updateRec(FmncRMRunMSample* rec);
	void updateRst(ListFmncRMRunMSample& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMRunMSample** rec);
	ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMRunMSample: C++ wrapper for table TblFmncRMRunMSample (PgSQL database)
  */
class PgTblFmncRMRunMSample : public TblFmncRMRunMSample, public PgTable {

public:
	PgTblFmncRMRunMSample();
	~PgTblFmncRMRunMSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMRunMSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMRunMSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMRunMSample** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMRunMSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMRunMSample& rst);

	void insertRec(FmncRMRunMSample* rec);
	void insertRst(ListFmncRMRunMSample& rst, bool transact = false);
	void updateRec(FmncRMRunMSample* rec);
	void updateRst(ListFmncRMRunMSample& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMRunMSample** rec);
	ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

