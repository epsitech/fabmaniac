/**
  * \file FmncMStep.h
  * database access for table TblFmncMStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMSTEP_H
#define FMNCMSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMStep: record of TblFmncMStep
  */
class FmncMStep {

public:
	FmncMStep(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMActivity = 0, const uint rlvIxVTbl = 0, const ubigint rlvUref = 0, const ubigint tplRefFmncMStep = 0, const uint ixWFilecfg = 0, const string Title = "", const uint start = 0, const ubigint refFmncMPerson = 0);

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncMActivity;
	uint rlvIxVTbl;
	ubigint rlvUref;
	ubigint tplRefFmncMStep;
	uint ixWFilecfg;
	string Title;
	uint start;
	ubigint refFmncMPerson;

public:
	bool operator==(const FmncMStep& comp);
	bool operator!=(const FmncMStep& comp);
};

/**
  * ListFmncMStep: recordset of TblFmncMStep
  */
class ListFmncMStep {

public:
	ListFmncMStep();
	ListFmncMStep(const ListFmncMStep& src);
	~ListFmncMStep();

	void clear();
	unsigned int size() const;
	void append(FmncMStep* rec);

	FmncMStep* operator[](const uint ix);
	ListFmncMStep& operator=(const ListFmncMStep& src);
	bool operator==(const ListFmncMStep& comp);
	bool operator!=(const ListFmncMStep& comp);

public:
	vector<FmncMStep*> nodes;
};

/**
  * TblFmncMStep: C++ wrapper for table TblFmncMStep
  */
class TblFmncMStep {

public:
	TblFmncMStep();
	virtual ~TblFmncMStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMStep& rst);

	virtual void insertRec(FmncMStep* rec);
	ubigint insertNewRec(FmncMStep** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMActivity = 0, const uint rlvIxVTbl = 0, const ubigint rlvUref = 0, const ubigint tplRefFmncMStep = 0, const uint ixWFilecfg = 0, const string Title = "", const uint start = 0, const ubigint refFmncMPerson = 0);
	ubigint appendNewRecToRst(ListFmncMStep& rst, FmncMStep** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMActivity = 0, const uint rlvIxVTbl = 0, const ubigint rlvUref = 0, const ubigint tplRefFmncMStep = 0, const uint ixWFilecfg = 0, const string Title = "", const uint start = 0, const ubigint refFmncMPerson = 0);
	virtual void insertRst(ListFmncMStep& rst, bool transact = false);
	virtual void updateRec(FmncMStep* rec);
	virtual void updateRst(ListFmncMStep& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMStep** rec);
	virtual ubigint loadRefsByAct(ubigint refFmncMActivity, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRefsByRltRlu(uint rlvIxVTbl, ubigint rlvUref, const bool append, vector<ubigint>& refs);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMStep: C++ wrapper for table TblFmncMStep (MySQL database)
  */
class MyTblFmncMStep : public TblFmncMStep, public MyTable {

public:
	MyTblFmncMStep();
	~MyTblFmncMStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMStep& rst);

	void insertRec(FmncMStep* rec);
	void insertRst(ListFmncMStep& rst, bool transact = false);
	void updateRec(FmncMStep* rec);
	void updateRst(ListFmncMStep& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMStep** rec);
	ubigint loadRefsByAct(ubigint refFmncMActivity, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByRltRlu(uint rlvIxVTbl, ubigint rlvUref, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMStep: C++ wrapper for table TblFmncMStep (PgSQL database)
  */
class PgTblFmncMStep : public TblFmncMStep, public PgTable {

public:
	PgTblFmncMStep();
	~PgTblFmncMStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMStep** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMStep& rst);

	void insertRec(FmncMStep* rec);
	void insertRst(ListFmncMStep& rst, bool transact = false);
	void updateRec(FmncMStep* rec);
	void updateRst(ListFmncMStep& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMStep** rec);
	ubigint loadRefsByAct(ubigint refFmncMActivity, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByRltRlu(uint rlvIxVTbl, ubigint rlvUref, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

