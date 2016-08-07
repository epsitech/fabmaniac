/**
  * \file FmncAMStepPar.h
  * database access for table TblFmncAMStepPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMSTEPPAR_H
#define FMNCAMSTEPPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMStepPar: record of TblFmncAMStepPar
  */
class FmncAMStepPar {

public:
	FmncAMStepPar(const ubigint ref = 0, const ubigint refFmncMStep = 0, const string x1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const ubigint x2Uref = 0, const string Val = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refFmncMStep;
	string x1OsrefFmncKSteppar;
	uint x2IxVTbl;
	ubigint x2Uref;
	string Val;
	string Comment;

public:
	bool operator==(const FmncAMStepPar& comp);
	bool operator!=(const FmncAMStepPar& comp);
};

/**
  * ListFmncAMStepPar: recordset of TblFmncAMStepPar
  */
class ListFmncAMStepPar {

public:
	ListFmncAMStepPar();
	ListFmncAMStepPar(const ListFmncAMStepPar& src);
	~ListFmncAMStepPar();

	void clear();
	unsigned int size() const;
	void append(FmncAMStepPar* rec);

	FmncAMStepPar* operator[](const uint ix);
	ListFmncAMStepPar& operator=(const ListFmncAMStepPar& src);
	bool operator==(const ListFmncAMStepPar& comp);
	bool operator!=(const ListFmncAMStepPar& comp);

public:
	vector<FmncAMStepPar*> nodes;
};

/**
  * TblFmncAMStepPar: C++ wrapper for table TblFmncAMStepPar
  */
class TblFmncAMStepPar {

public:
	TblFmncAMStepPar();
	virtual ~TblFmncAMStepPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMStepPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMStepPar& rst);

	virtual void insertRec(FmncAMStepPar* rec);
	ubigint insertNewRec(FmncAMStepPar** rec = NULL, const ubigint refFmncMStep = 0, const string x1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const ubigint x2Uref = 0, const string Val = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncAMStepPar& rst, FmncAMStepPar** rec = NULL, const ubigint refFmncMStep = 0, const string x1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const ubigint x2Uref = 0, const string Val = "", const string Comment = "");
	virtual void insertRst(ListFmncAMStepPar& rst, bool transact = false);
	virtual void updateRec(FmncAMStepPar* rec);
	virtual void updateRst(ListFmncAMStepPar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMStepPar** rec);
	virtual ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMStepPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMStepPar: C++ wrapper for table TblFmncAMStepPar (MySQL database)
  */
class MyTblFmncAMStepPar : public TblFmncAMStepPar, public MyTable {

public:
	MyTblFmncAMStepPar();
	~MyTblFmncAMStepPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMStepPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMStepPar& rst);

	void insertRec(FmncAMStepPar* rec);
	void insertRst(ListFmncAMStepPar& rst, bool transact = false);
	void updateRec(FmncAMStepPar* rec);
	void updateRst(ListFmncAMStepPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMStepPar** rec);
	ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMStepPar: C++ wrapper for table TblFmncAMStepPar (PgSQL database)
  */
class PgTblFmncAMStepPar : public TblFmncAMStepPar, public PgTable {

public:
	PgTblFmncAMStepPar();
	~PgTblFmncAMStepPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMStepPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMStepPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMStepPar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMStepPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMStepPar& rst);

	void insertRec(FmncAMStepPar* rec);
	void insertRst(ListFmncAMStepPar& rst, bool transact = false);
	void updateRec(FmncAMStepPar* rec);
	void updateRst(ListFmncAMStepPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMStepPar** rec);
	ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

