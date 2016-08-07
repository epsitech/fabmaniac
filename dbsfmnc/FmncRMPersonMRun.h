/**
  * \file FmncRMPersonMRun.h
  * database access for table TblFmncRMPersonMRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMPERSONMRUN_H
#define FMNCRMPERSONMRUN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMPersonMRun: record of TblFmncRMPersonMRun
  */
class FmncRMPersonMRun {

public:
	FmncRMPersonMRun(const ubigint ref = 0, const ubigint refFmncMPerson = 0, const ubigint refFmncMRun = 0);

public:
	ubigint ref;
	ubigint refFmncMPerson;
	ubigint refFmncMRun;

public:
	bool operator==(const FmncRMPersonMRun& comp);
	bool operator!=(const FmncRMPersonMRun& comp);
};

/**
  * ListFmncRMPersonMRun: recordset of TblFmncRMPersonMRun
  */
class ListFmncRMPersonMRun {

public:
	ListFmncRMPersonMRun();
	ListFmncRMPersonMRun(const ListFmncRMPersonMRun& src);
	~ListFmncRMPersonMRun();

	void clear();
	unsigned int size() const;
	void append(FmncRMPersonMRun* rec);

	FmncRMPersonMRun* operator[](const uint ix);
	ListFmncRMPersonMRun& operator=(const ListFmncRMPersonMRun& src);
	bool operator==(const ListFmncRMPersonMRun& comp);
	bool operator!=(const ListFmncRMPersonMRun& comp);

public:
	vector<FmncRMPersonMRun*> nodes;
};

/**
  * TblFmncRMPersonMRun: C++ wrapper for table TblFmncRMPersonMRun
  */
class TblFmncRMPersonMRun {

public:
	TblFmncRMPersonMRun();
	virtual ~TblFmncRMPersonMRun();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMPersonMRun** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMPersonMRun& rst);

	virtual void insertRec(FmncRMPersonMRun* rec);
	ubigint insertNewRec(FmncRMPersonMRun** rec = NULL, const ubigint refFmncMPerson = 0, const ubigint refFmncMRun = 0);
	ubigint appendNewRecToRst(ListFmncRMPersonMRun& rst, FmncRMPersonMRun** rec = NULL, const ubigint refFmncMPerson = 0, const ubigint refFmncMRun = 0);
	virtual void insertRst(ListFmncRMPersonMRun& rst, bool transact = false);
	virtual void updateRec(FmncRMPersonMRun* rec);
	virtual void updateRst(ListFmncRMPersonMRun& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMPersonMRun** rec);
	virtual ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMPersonMRun& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMPersonMRun: C++ wrapper for table TblFmncRMPersonMRun (MySQL database)
  */
class MyTblFmncRMPersonMRun : public TblFmncRMPersonMRun, public MyTable {

public:
	MyTblFmncRMPersonMRun();
	~MyTblFmncRMPersonMRun();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMPersonMRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMPersonMRun& rst);

	void insertRec(FmncRMPersonMRun* rec);
	void insertRst(ListFmncRMPersonMRun& rst, bool transact = false);
	void updateRec(FmncRMPersonMRun* rec);
	void updateRst(ListFmncRMPersonMRun& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMPersonMRun** rec);
	ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMPersonMRun: C++ wrapper for table TblFmncRMPersonMRun (PgSQL database)
  */
class PgTblFmncRMPersonMRun : public TblFmncRMPersonMRun, public PgTable {

public:
	PgTblFmncRMPersonMRun();
	~PgTblFmncRMPersonMRun();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMPersonMRun** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMPersonMRun& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMPersonMRun** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMPersonMRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMPersonMRun& rst);

	void insertRec(FmncRMPersonMRun* rec);
	void insertRst(ListFmncRMPersonMRun& rst, bool transact = false);
	void updateRec(FmncRMPersonMRun* rec);
	void updateRst(ListFmncRMPersonMRun& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMPersonMRun** rec);
	ubigint loadRefsByRun(ubigint refFmncMRun, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

