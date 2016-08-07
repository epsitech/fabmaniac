/**
  * \file FmncMFab.h
  * database access for table TblFmncMFab (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMFAB_H
#define FMNCMFAB_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMFab: record of TblFmncMFab
  */
class FmncMFab {

public:
	FmncMFab(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0);

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncMOrg;

public:
	bool operator==(const FmncMFab& comp);
	bool operator!=(const FmncMFab& comp);
};

/**
  * ListFmncMFab: recordset of TblFmncMFab
  */
class ListFmncMFab {

public:
	ListFmncMFab();
	ListFmncMFab(const ListFmncMFab& src);
	~ListFmncMFab();

	void clear();
	unsigned int size() const;
	void append(FmncMFab* rec);

	FmncMFab* operator[](const uint ix);
	ListFmncMFab& operator=(const ListFmncMFab& src);
	bool operator==(const ListFmncMFab& comp);
	bool operator!=(const ListFmncMFab& comp);

public:
	vector<FmncMFab*> nodes;
};

/**
  * TblFmncMFab: C++ wrapper for table TblFmncMFab
  */
class TblFmncMFab {

public:
	TblFmncMFab();
	virtual ~TblFmncMFab();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMFab** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFab& rst);

	virtual void insertRec(FmncMFab* rec);
	ubigint insertNewRec(FmncMFab** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0);
	ubigint appendNewRecToRst(ListFmncMFab& rst, FmncMFab** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0);
	virtual void insertRst(ListFmncMFab& rst, bool transact = false);
	virtual void updateRec(FmncMFab* rec);
	virtual void updateRst(ListFmncMFab& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMFab** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMFab& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMFab: C++ wrapper for table TblFmncMFab (MySQL database)
  */
class MyTblFmncMFab : public TblFmncMFab, public MyTable {

public:
	MyTblFmncMFab();
	~MyTblFmncMFab();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMFab** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFab& rst);

	void insertRec(FmncMFab* rec);
	void insertRst(ListFmncMFab& rst, bool transact = false);
	void updateRec(FmncMFab* rec);
	void updateRst(ListFmncMFab& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMFab** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMFab: C++ wrapper for table TblFmncMFab (PgSQL database)
  */
class PgTblFmncMFab : public TblFmncMFab, public PgTable {

public:
	PgTblFmncMFab();
	~PgTblFmncMFab();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMFab** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMFab& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMFab** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMFab** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFab& rst);

	void insertRec(FmncMFab* rec);
	void insertRst(ListFmncMFab& rst, bool transact = false);
	void updateRec(FmncMFab* rec);
	void updateRst(ListFmncMFab& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMFab** rec);
};
// IP pgTbl --- END

#endif

