/**
  * \file FmncRMArticleMOrg.h
  * database access for table TblFmncRMArticleMOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMARTICLEMORG_H
#define FMNCRMARTICLEMORG_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMArticleMOrg: record of TblFmncRMArticleMOrg
  */
class FmncRMArticleMOrg {

public:
	FmncRMArticleMOrg(const ubigint ref = 0, const ubigint refFmncMArticle = 0, const ubigint refFmncMOrg = 0, const string Itemno = "");

public:
	ubigint ref;
	ubigint refFmncMArticle;
	ubigint refFmncMOrg;
	string Itemno;

public:
	bool operator==(const FmncRMArticleMOrg& comp);
	bool operator!=(const FmncRMArticleMOrg& comp);
};

/**
  * ListFmncRMArticleMOrg: recordset of TblFmncRMArticleMOrg
  */
class ListFmncRMArticleMOrg {

public:
	ListFmncRMArticleMOrg();
	ListFmncRMArticleMOrg(const ListFmncRMArticleMOrg& src);
	~ListFmncRMArticleMOrg();

	void clear();
	unsigned int size() const;
	void append(FmncRMArticleMOrg* rec);

	FmncRMArticleMOrg* operator[](const uint ix);
	ListFmncRMArticleMOrg& operator=(const ListFmncRMArticleMOrg& src);
	bool operator==(const ListFmncRMArticleMOrg& comp);
	bool operator!=(const ListFmncRMArticleMOrg& comp);

public:
	vector<FmncRMArticleMOrg*> nodes;
};

/**
  * TblFmncRMArticleMOrg: C++ wrapper for table TblFmncRMArticleMOrg
  */
class TblFmncRMArticleMOrg {

public:
	TblFmncRMArticleMOrg();
	virtual ~TblFmncRMArticleMOrg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMArticleMOrg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMArticleMOrg& rst);

	virtual void insertRec(FmncRMArticleMOrg* rec);
	ubigint insertNewRec(FmncRMArticleMOrg** rec = NULL, const ubigint refFmncMArticle = 0, const ubigint refFmncMOrg = 0, const string Itemno = "");
	ubigint appendNewRecToRst(ListFmncRMArticleMOrg& rst, FmncRMArticleMOrg** rec = NULL, const ubigint refFmncMArticle = 0, const ubigint refFmncMOrg = 0, const string Itemno = "");
	virtual void insertRst(ListFmncRMArticleMOrg& rst, bool transact = false);
	virtual void updateRec(FmncRMArticleMOrg* rec);
	virtual void updateRst(ListFmncRMArticleMOrg& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMArticleMOrg** rec);
	virtual ubigint loadRefsByArt(ubigint refFmncMArticle, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMArticleMOrg& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMArticleMOrg: C++ wrapper for table TblFmncRMArticleMOrg (MySQL database)
  */
class MyTblFmncRMArticleMOrg : public TblFmncRMArticleMOrg, public MyTable {

public:
	MyTblFmncRMArticleMOrg();
	~MyTblFmncRMArticleMOrg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMArticleMOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMArticleMOrg& rst);

	void insertRec(FmncRMArticleMOrg* rec);
	void insertRst(ListFmncRMArticleMOrg& rst, bool transact = false);
	void updateRec(FmncRMArticleMOrg* rec);
	void updateRst(ListFmncRMArticleMOrg& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMArticleMOrg** rec);
	ubigint loadRefsByArt(ubigint refFmncMArticle, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMArticleMOrg: C++ wrapper for table TblFmncRMArticleMOrg (PgSQL database)
  */
class PgTblFmncRMArticleMOrg : public TblFmncRMArticleMOrg, public PgTable {

public:
	PgTblFmncRMArticleMOrg();
	~PgTblFmncRMArticleMOrg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMArticleMOrg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMArticleMOrg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMArticleMOrg** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMArticleMOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMArticleMOrg& rst);

	void insertRec(FmncRMArticleMOrg* rec);
	void insertRst(ListFmncRMArticleMOrg& rst, bool transact = false);
	void updateRec(FmncRMArticleMOrg* rec);
	void updateRst(ListFmncRMArticleMOrg& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMArticleMOrg** rec);
	ubigint loadRefsByArt(ubigint refFmncMArticle, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

