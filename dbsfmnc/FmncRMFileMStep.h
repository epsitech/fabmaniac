/**
  * \file FmncRMFileMStep.h
  * database access for table TblFmncRMFileMStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMFILEMSTEP_H
#define FMNCRMFILEMSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMFileMStep: record of TblFmncRMFileMStep
  */
class FmncRMFileMStep {

public:
	FmncRMFileMStep(const ubigint ref = 0, const ubigint refFmncMFile = 0, const ubigint refFmncMStep = 0, const uint ixVDir = 0);

public:
	ubigint ref;
	ubigint refFmncMFile;
	ubigint refFmncMStep;
	uint ixVDir;

public:
	bool operator==(const FmncRMFileMStep& comp);
	bool operator!=(const FmncRMFileMStep& comp);
};

/**
  * ListFmncRMFileMStep: recordset of TblFmncRMFileMStep
  */
class ListFmncRMFileMStep {

public:
	ListFmncRMFileMStep();
	ListFmncRMFileMStep(const ListFmncRMFileMStep& src);
	~ListFmncRMFileMStep();

	void clear();
	unsigned int size() const;
	void append(FmncRMFileMStep* rec);

	FmncRMFileMStep* operator[](const uint ix);
	ListFmncRMFileMStep& operator=(const ListFmncRMFileMStep& src);
	bool operator==(const ListFmncRMFileMStep& comp);
	bool operator!=(const ListFmncRMFileMStep& comp);

public:
	vector<FmncRMFileMStep*> nodes;
};

/**
  * TblFmncRMFileMStep: C++ wrapper for table TblFmncRMFileMStep
  */
class TblFmncRMFileMStep {

public:
	TblFmncRMFileMStep();
	virtual ~TblFmncRMFileMStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMFileMStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFileMStep& rst);

	virtual void insertRec(FmncRMFileMStep* rec);
	ubigint insertNewRec(FmncRMFileMStep** rec = NULL, const ubigint refFmncMFile = 0, const ubigint refFmncMStep = 0, const uint ixVDir = 0);
	ubigint appendNewRecToRst(ListFmncRMFileMStep& rst, FmncRMFileMStep** rec = NULL, const ubigint refFmncMFile = 0, const ubigint refFmncMStep = 0, const uint ixVDir = 0);
	virtual void insertRst(ListFmncRMFileMStep& rst, bool transact = false);
	virtual void updateRec(FmncRMFileMStep* rec);
	virtual void updateRst(ListFmncRMFileMStep& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMFileMStep** rec);
	virtual ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMFileMStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMFileMStep: C++ wrapper for table TblFmncRMFileMStep (MySQL database)
  */
class MyTblFmncRMFileMStep : public TblFmncRMFileMStep, public MyTable {

public:
	MyTblFmncRMFileMStep();
	~MyTblFmncRMFileMStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFileMStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFileMStep& rst);

	void insertRec(FmncRMFileMStep* rec);
	void insertRst(ListFmncRMFileMStep& rst, bool transact = false);
	void updateRec(FmncRMFileMStep* rec);
	void updateRst(ListFmncRMFileMStep& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFileMStep** rec);
	ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMFileMStep: C++ wrapper for table TblFmncRMFileMStep (PgSQL database)
  */
class PgTblFmncRMFileMStep : public TblFmncRMFileMStep, public PgTable {

public:
	PgTblFmncRMFileMStep();
	~PgTblFmncRMFileMStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMFileMStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMFileMStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMFileMStep** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFileMStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFileMStep& rst);

	void insertRec(FmncRMFileMStep* rec);
	void insertRst(ListFmncRMFileMStep& rst, bool transact = false);
	void updateRec(FmncRMFileMStep* rec);
	void updateRst(ListFmncRMFileMStep& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFileMStep** rec);
	ubigint loadRefsBySte(ubigint refFmncMStep, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

