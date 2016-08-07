/**
  * \file FmncAMSamplePar.h
  * database access for table TblFmncAMSamplePar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMSAMPLEPAR_H
#define FMNCAMSAMPLEPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMSamplePar: record of TblFmncAMSamplePar
  */
class FmncAMSamplePar {

public:
	FmncAMSamplePar(const ubigint ref = 0, const ubigint refFmncMSample = 0, const string x1SrefKKey = "", const string osrefKVal = "");

public:
	ubigint ref;
	ubigint refFmncMSample;
	string x1SrefKKey;
	string osrefKVal;

public:
	bool operator==(const FmncAMSamplePar& comp);
	bool operator!=(const FmncAMSamplePar& comp);
};

/**
  * ListFmncAMSamplePar: recordset of TblFmncAMSamplePar
  */
class ListFmncAMSamplePar {

public:
	ListFmncAMSamplePar();
	ListFmncAMSamplePar(const ListFmncAMSamplePar& src);
	~ListFmncAMSamplePar();

	void clear();
	unsigned int size() const;
	void append(FmncAMSamplePar* rec);

	FmncAMSamplePar* operator[](const uint ix);
	ListFmncAMSamplePar& operator=(const ListFmncAMSamplePar& src);
	bool operator==(const ListFmncAMSamplePar& comp);
	bool operator!=(const ListFmncAMSamplePar& comp);

public:
	vector<FmncAMSamplePar*> nodes;
};

/**
  * TblFmncAMSamplePar: C++ wrapper for table TblFmncAMSamplePar
  */
class TblFmncAMSamplePar {

public:
	TblFmncAMSamplePar();
	virtual ~TblFmncAMSamplePar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMSamplePar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMSamplePar& rst);

	virtual void insertRec(FmncAMSamplePar* rec);
	ubigint insertNewRec(FmncAMSamplePar** rec = NULL, const ubigint refFmncMSample = 0, const string x1SrefKKey = "", const string osrefKVal = "");
	ubigint appendNewRecToRst(ListFmncAMSamplePar& rst, FmncAMSamplePar** rec = NULL, const ubigint refFmncMSample = 0, const string x1SrefKKey = "", const string osrefKVal = "");
	virtual void insertRst(ListFmncAMSamplePar& rst, bool transact = false);
	virtual void updateRec(FmncAMSamplePar* rec);
	virtual void updateRst(ListFmncAMSamplePar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMSamplePar** rec);
	virtual ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMSamplePar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMSamplePar: C++ wrapper for table TblFmncAMSamplePar (MySQL database)
  */
class MyTblFmncAMSamplePar : public TblFmncAMSamplePar, public MyTable {

public:
	MyTblFmncAMSamplePar();
	~MyTblFmncAMSamplePar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMSamplePar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMSamplePar& rst);

	void insertRec(FmncAMSamplePar* rec);
	void insertRst(ListFmncAMSamplePar& rst, bool transact = false);
	void updateRec(FmncAMSamplePar* rec);
	void updateRst(ListFmncAMSamplePar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMSamplePar** rec);
	ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMSamplePar: C++ wrapper for table TblFmncAMSamplePar (PgSQL database)
  */
class PgTblFmncAMSamplePar : public TblFmncAMSamplePar, public PgTable {

public:
	PgTblFmncAMSamplePar();
	~PgTblFmncAMSamplePar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMSamplePar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMSamplePar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMSamplePar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMSamplePar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMSamplePar& rst);

	void insertRec(FmncAMSamplePar* rec);
	void insertRst(ListFmncAMSamplePar& rst, bool transact = false);
	void updateRec(FmncAMSamplePar* rec);
	void updateRst(ListFmncAMSamplePar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMSamplePar** rec);
	ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

