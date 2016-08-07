/**
  * \file FmncMFabproject.h
  * database access for table TblFmncMFabproject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMFABPROJECT_H
#define FMNCMFABPROJECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMFabproject: record of TblFmncMFabproject
  */
class FmncMFabproject {

public:
	FmncMFabproject(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFab = 0, const ubigint bioRefFmncMOrg = 0, const string sref = "", const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const ubigint bipRefFmncMPerson = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncMFab;
	ubigint bioRefFmncMOrg;
	string sref;
	string Title;
	ubigint refJState;
	uint ixVState;
	ubigint bipRefFmncMPerson;
	string Comment;

public:
	bool operator==(const FmncMFabproject& comp);
	bool operator!=(const FmncMFabproject& comp);
};

/**
  * ListFmncMFabproject: recordset of TblFmncMFabproject
  */
class ListFmncMFabproject {

public:
	ListFmncMFabproject();
	ListFmncMFabproject(const ListFmncMFabproject& src);
	~ListFmncMFabproject();

	void clear();
	unsigned int size() const;
	void append(FmncMFabproject* rec);

	FmncMFabproject* operator[](const uint ix);
	ListFmncMFabproject& operator=(const ListFmncMFabproject& src);
	bool operator==(const ListFmncMFabproject& comp);
	bool operator!=(const ListFmncMFabproject& comp);

public:
	vector<FmncMFabproject*> nodes;
};

/**
  * TblFmncMFabproject: C++ wrapper for table TblFmncMFabproject
  */
class TblFmncMFabproject {

public:
	TblFmncMFabproject();
	virtual ~TblFmncMFabproject();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMFabproject** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFabproject& rst);

	virtual void insertRec(FmncMFabproject* rec);
	ubigint insertNewRec(FmncMFabproject** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFab = 0, const ubigint bioRefFmncMOrg = 0, const string sref = "", const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const ubigint bipRefFmncMPerson = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMFabproject& rst, FmncMFabproject** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFab = 0, const ubigint bioRefFmncMOrg = 0, const string sref = "", const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const ubigint bipRefFmncMPerson = 0, const string Comment = "");
	virtual void insertRst(ListFmncMFabproject& rst, bool transact = false);
	virtual void updateRec(FmncMFabproject* rec);
	virtual void updateRst(ListFmncMFabproject& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMFabproject** rec);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMFabproject& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMFabproject: C++ wrapper for table TblFmncMFabproject (MySQL database)
  */
class MyTblFmncMFabproject : public TblFmncMFabproject, public MyTable {

public:
	MyTblFmncMFabproject();
	~MyTblFmncMFabproject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMFabproject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFabproject& rst);

	void insertRec(FmncMFabproject* rec);
	void insertRst(ListFmncMFabproject& rst, bool transact = false);
	void updateRec(FmncMFabproject* rec);
	void updateRst(ListFmncMFabproject& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMFabproject** rec);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMFabproject: C++ wrapper for table TblFmncMFabproject (PgSQL database)
  */
class PgTblFmncMFabproject : public TblFmncMFabproject, public PgTable {

public:
	PgTblFmncMFabproject();
	~PgTblFmncMFabproject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMFabproject** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMFabproject& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMFabproject** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMFabproject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFabproject& rst);

	void insertRec(FmncMFabproject* rec);
	void insertRst(ListFmncMFabproject& rst, bool transact = false);
	void updateRec(FmncMFabproject* rec);
	void updateRst(ListFmncMFabproject& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMFabproject** rec);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

