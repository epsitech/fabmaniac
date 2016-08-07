/**
  * \file FmncJMOrgTitle.h
  * database access for table TblFmncJMOrgTitle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMORGTITLE_H
#define FMNCJMORGTITLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMOrgTitle: record of TblFmncJMOrgTitle
  */
class FmncJMOrgTitle {

public:
	FmncJMOrgTitle(const ubigint ref = 0, const ubigint refFmncMOrg = 0, const uint x1Startd = 0, const string Title = "");

public:
	ubigint ref;
	ubigint refFmncMOrg;
	uint x1Startd;
	string Title;

public:
	bool operator==(const FmncJMOrgTitle& comp);
	bool operator!=(const FmncJMOrgTitle& comp);
};

/**
  * ListFmncJMOrgTitle: recordset of TblFmncJMOrgTitle
  */
class ListFmncJMOrgTitle {

public:
	ListFmncJMOrgTitle();
	ListFmncJMOrgTitle(const ListFmncJMOrgTitle& src);
	~ListFmncJMOrgTitle();

	void clear();
	unsigned int size() const;
	void append(FmncJMOrgTitle* rec);

	FmncJMOrgTitle* operator[](const uint ix);
	ListFmncJMOrgTitle& operator=(const ListFmncJMOrgTitle& src);
	bool operator==(const ListFmncJMOrgTitle& comp);
	bool operator!=(const ListFmncJMOrgTitle& comp);

public:
	vector<FmncJMOrgTitle*> nodes;
};

/**
  * TblFmncJMOrgTitle: C++ wrapper for table TblFmncJMOrgTitle
  */
class TblFmncJMOrgTitle {

public:
	TblFmncJMOrgTitle();
	virtual ~TblFmncJMOrgTitle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMOrgTitle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMOrgTitle& rst);

	virtual void insertRec(FmncJMOrgTitle* rec);
	ubigint insertNewRec(FmncJMOrgTitle** rec = NULL, const ubigint refFmncMOrg = 0, const uint x1Startd = 0, const string Title = "");
	ubigint appendNewRecToRst(ListFmncJMOrgTitle& rst, FmncJMOrgTitle** rec = NULL, const ubigint refFmncMOrg = 0, const uint x1Startd = 0, const string Title = "");
	virtual void insertRst(ListFmncJMOrgTitle& rst, bool transact = false);
	virtual void updateRec(FmncJMOrgTitle* rec);
	virtual void updateRst(ListFmncJMOrgTitle& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMOrgTitle** rec);
	virtual ubigint loadRefsByOrg(ubigint refFmncMOrg, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByOrg(ubigint refFmncMOrg, const bool append, ListFmncJMOrgTitle& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMOrgTitle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMOrgTitle: C++ wrapper for table TblFmncJMOrgTitle (MySQL database)
  */
class MyTblFmncJMOrgTitle : public TblFmncJMOrgTitle, public MyTable {

public:
	MyTblFmncJMOrgTitle();
	~MyTblFmncJMOrgTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMOrgTitle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMOrgTitle& rst);

	void insertRec(FmncJMOrgTitle* rec);
	void insertRst(ListFmncJMOrgTitle& rst, bool transact = false);
	void updateRec(FmncJMOrgTitle* rec);
	void updateRst(ListFmncJMOrgTitle& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMOrgTitle** rec);
	ubigint loadRefsByOrg(ubigint refFmncMOrg, const bool append, vector<ubigint>& refs);
	ubigint loadRstByOrg(ubigint refFmncMOrg, const bool append, ListFmncJMOrgTitle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMOrgTitle: C++ wrapper for table TblFmncJMOrgTitle (PgSQL database)
  */
class PgTblFmncJMOrgTitle : public TblFmncJMOrgTitle, public PgTable {

public:
	PgTblFmncJMOrgTitle();
	~PgTblFmncJMOrgTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMOrgTitle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMOrgTitle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMOrgTitle** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMOrgTitle& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMOrgTitle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMOrgTitle& rst);

	void insertRec(FmncJMOrgTitle* rec);
	void insertRst(ListFmncJMOrgTitle& rst, bool transact = false);
	void updateRec(FmncJMOrgTitle* rec);
	void updateRst(ListFmncJMOrgTitle& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMOrgTitle** rec);
	ubigint loadRefsByOrg(ubigint refFmncMOrg, const bool append, vector<ubigint>& refs);
	ubigint loadRstByOrg(ubigint refFmncMOrg, const bool append, ListFmncJMOrgTitle& rst);
};
// IP pgTbl --- END

#endif

