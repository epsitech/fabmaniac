/**
  * \file FmncMRun.h
  * database access for table TblFmncMRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMRUN_H
#define FMNCMRUN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMRun: record of TblFmncMRun
  */
class FmncMRun {

public:
	FmncMRun(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMProject = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncMProject;
	string Title;
	ubigint refJState;
	uint ixVState;
	string Comment;

public:
	bool operator==(const FmncMRun& comp);
	bool operator!=(const FmncMRun& comp);
};

/**
  * ListFmncMRun: recordset of TblFmncMRun
  */
class ListFmncMRun {

public:
	ListFmncMRun();
	ListFmncMRun(const ListFmncMRun& src);
	~ListFmncMRun();

	void clear();
	unsigned int size() const;
	void append(FmncMRun* rec);

	FmncMRun* operator[](const uint ix);
	ListFmncMRun& operator=(const ListFmncMRun& src);
	bool operator==(const ListFmncMRun& comp);
	bool operator!=(const ListFmncMRun& comp);

public:
	vector<FmncMRun*> nodes;
};

/**
  * TblFmncMRun: C++ wrapper for table TblFmncMRun
  */
class TblFmncMRun {

public:
	TblFmncMRun();
	virtual ~TblFmncMRun();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMRun** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMRun& rst);

	virtual void insertRec(FmncMRun* rec);
	ubigint insertNewRec(FmncMRun** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMProject = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMRun& rst, FmncMRun** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMProject = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");
	virtual void insertRst(ListFmncMRun& rst, bool transact = false);
	virtual void updateRec(FmncMRun* rec);
	virtual void updateRst(ListFmncMRun& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMRun** rec);
	virtual ubigint loadRefsByPrj(ubigint refFmncMProject, const bool append, vector<ubigint>& refs);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMRun& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMRun: C++ wrapper for table TblFmncMRun (MySQL database)
  */
class MyTblFmncMRun : public TblFmncMRun, public MyTable {

public:
	MyTblFmncMRun();
	~MyTblFmncMRun();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMRun& rst);

	void insertRec(FmncMRun* rec);
	void insertRst(ListFmncMRun& rst, bool transact = false);
	void updateRec(FmncMRun* rec);
	void updateRst(ListFmncMRun& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMRun** rec);
	ubigint loadRefsByPrj(ubigint refFmncMProject, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMRun: C++ wrapper for table TblFmncMRun (PgSQL database)
  */
class PgTblFmncMRun : public TblFmncMRun, public PgTable {

public:
	PgTblFmncMRun();
	~PgTblFmncMRun();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMRun** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMRun& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMRun** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMRun& rst);

	void insertRec(FmncMRun* rec);
	void insertRst(ListFmncMRun& rst, bool transact = false);
	void updateRec(FmncMRun* rec);
	void updateRst(ListFmncMRun& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMRun** rec);
	ubigint loadRefsByPrj(ubigint refFmncMProject, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

