/**
  * \file FmncRMSampleMStep.h
  * database access for table TblFmncRMSampleMStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMSAMPLEMSTEP_H
#define FMNCRMSAMPLEMSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMSampleMStep: record of TblFmncRMSampleMStep
  */
class FmncRMSampleMStep {

public:
	FmncRMSampleMStep(const ubigint ref = 0, const ubigint refFmncMSample = 0, const ubigint refFmncMStep = 0);

public:
	ubigint ref;
	ubigint refFmncMSample;
	ubigint refFmncMStep;

public:
	bool operator==(const FmncRMSampleMStep& comp);
	bool operator!=(const FmncRMSampleMStep& comp);
};

/**
  * ListFmncRMSampleMStep: recordset of TblFmncRMSampleMStep
  */
class ListFmncRMSampleMStep {

public:
	ListFmncRMSampleMStep();
	ListFmncRMSampleMStep(const ListFmncRMSampleMStep& src);
	~ListFmncRMSampleMStep();

	void clear();
	unsigned int size() const;
	void append(FmncRMSampleMStep* rec);

	FmncRMSampleMStep* operator[](const uint ix);
	ListFmncRMSampleMStep& operator=(const ListFmncRMSampleMStep& src);
	bool operator==(const ListFmncRMSampleMStep& comp);
	bool operator!=(const ListFmncRMSampleMStep& comp);

public:
	vector<FmncRMSampleMStep*> nodes;
};

/**
  * TblFmncRMSampleMStep: C++ wrapper for table TblFmncRMSampleMStep
  */
class TblFmncRMSampleMStep {

public:
	TblFmncRMSampleMStep();
	virtual ~TblFmncRMSampleMStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMSampleMStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMSampleMStep& rst);

	virtual void insertRec(FmncRMSampleMStep* rec);
	ubigint insertNewRec(FmncRMSampleMStep** rec = NULL, const ubigint refFmncMSample = 0, const ubigint refFmncMStep = 0);
	ubigint appendNewRecToRst(ListFmncRMSampleMStep& rst, FmncRMSampleMStep** rec = NULL, const ubigint refFmncMSample = 0, const ubigint refFmncMStep = 0);
	virtual void insertRst(ListFmncRMSampleMStep& rst, bool transact = false);
	virtual void updateRec(FmncRMSampleMStep* rec);
	virtual void updateRst(ListFmncRMSampleMStep& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMSampleMStep** rec);
	virtual ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMSampleMStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMSampleMStep: C++ wrapper for table TblFmncRMSampleMStep (MySQL database)
  */
class MyTblFmncRMSampleMStep : public TblFmncRMSampleMStep, public MyTable {

public:
	MyTblFmncRMSampleMStep();
	~MyTblFmncRMSampleMStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMSampleMStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMSampleMStep& rst);

	void insertRec(FmncRMSampleMStep* rec);
	void insertRst(ListFmncRMSampleMStep& rst, bool transact = false);
	void updateRec(FmncRMSampleMStep* rec);
	void updateRst(ListFmncRMSampleMStep& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMSampleMStep** rec);
	ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMSampleMStep: C++ wrapper for table TblFmncRMSampleMStep (PgSQL database)
  */
class PgTblFmncRMSampleMStep : public TblFmncRMSampleMStep, public PgTable {

public:
	PgTblFmncRMSampleMStep();
	~PgTblFmncRMSampleMStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMSampleMStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMSampleMStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMSampleMStep** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMSampleMStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMSampleMStep& rst);

	void insertRec(FmncRMSampleMStep* rec);
	void insertRst(ListFmncRMSampleMStep& rst, bool transact = false);
	void updateRec(FmncRMSampleMStep* rec);
	void updateRst(ListFmncRMSampleMStep& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMSampleMStep** rec);
	ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

