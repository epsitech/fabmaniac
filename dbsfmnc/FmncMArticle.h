/**
  * \file FmncMArticle.h
  * database access for table TblFmncMArticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMARTICLE_H
#define FMNCMARTICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMArticle: record of TblFmncMArticle
  */
class FmncMArticle {

public:
	FmncMArticle(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMTool = 0, const string sref = "", const string Title = "", const string srefKType = "", const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncMOrg;
	ubigint refFmncMTool;
	string sref;
	string Title;
	string srefKType;
	string Comment;

public:
	bool operator==(const FmncMArticle& comp);
	bool operator!=(const FmncMArticle& comp);
};

/**
  * ListFmncMArticle: recordset of TblFmncMArticle
  */
class ListFmncMArticle {

public:
	ListFmncMArticle();
	ListFmncMArticle(const ListFmncMArticle& src);
	~ListFmncMArticle();

	void clear();
	unsigned int size() const;
	void append(FmncMArticle* rec);

	FmncMArticle* operator[](const uint ix);
	ListFmncMArticle& operator=(const ListFmncMArticle& src);
	bool operator==(const ListFmncMArticle& comp);
	bool operator!=(const ListFmncMArticle& comp);

public:
	vector<FmncMArticle*> nodes;
};

/**
  * TblFmncMArticle: C++ wrapper for table TblFmncMArticle
  */
class TblFmncMArticle {

public:
	TblFmncMArticle();
	virtual ~TblFmncMArticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMArticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMArticle& rst);

	virtual void insertRec(FmncMArticle* rec);
	ubigint insertNewRec(FmncMArticle** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMTool = 0, const string sref = "", const string Title = "", const string srefKType = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMArticle& rst, FmncMArticle** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMTool = 0, const string sref = "", const string Title = "", const string srefKType = "", const string Comment = "");
	virtual void insertRst(ListFmncMArticle& rst, bool transact = false);
	virtual void updateRec(FmncMArticle* rec);
	virtual void updateRst(ListFmncMArticle& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMArticle** rec);
	virtual ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMArticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMArticle: C++ wrapper for table TblFmncMArticle (MySQL database)
  */
class MyTblFmncMArticle : public TblFmncMArticle, public MyTable {

public:
	MyTblFmncMArticle();
	~MyTblFmncMArticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMArticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMArticle& rst);

	void insertRec(FmncMArticle* rec);
	void insertRst(ListFmncMArticle& rst, bool transact = false);
	void updateRec(FmncMArticle* rec);
	void updateRst(ListFmncMArticle& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMArticle** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMArticle: C++ wrapper for table TblFmncMArticle (PgSQL database)
  */
class PgTblFmncMArticle : public TblFmncMArticle, public PgTable {

public:
	PgTblFmncMArticle();
	~PgTblFmncMArticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMArticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMArticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMArticle** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMArticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMArticle& rst);

	void insertRec(FmncMArticle* rec);
	void insertRst(ListFmncMArticle& rst, bool transact = false);
	void updateRec(FmncMArticle* rec);
	void updateRst(ListFmncMArticle& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMArticle** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

