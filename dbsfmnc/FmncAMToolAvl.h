/**
  * \file FmncAMToolAvl.h
  * database access for table TblFmncAMToolAvl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMTOOLAVL_H
#define FMNCAMTOOLAVL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMToolAvl: record of TblFmncAMToolAvl
  */
class FmncAMToolAvl {

public:
	FmncAMToolAvl(const ubigint ref = 0, const ubigint refFmncMTool = 0, const uint x1Startd = 0, const uint x2IxVWkday = 0, const uint x3Startt = 0, const uint x3Stopt = 0, const string srefKAvltype = "");

public:
	ubigint ref;
	ubigint refFmncMTool;
	uint x1Startd;
	uint x2IxVWkday;
	uint x3Startt;
	uint x3Stopt;
	string srefKAvltype;

public:
	bool operator==(const FmncAMToolAvl& comp);
	bool operator!=(const FmncAMToolAvl& comp);
};

/**
  * ListFmncAMToolAvl: recordset of TblFmncAMToolAvl
  */
class ListFmncAMToolAvl {

public:
	ListFmncAMToolAvl();
	ListFmncAMToolAvl(const ListFmncAMToolAvl& src);
	~ListFmncAMToolAvl();

	void clear();
	unsigned int size() const;
	void append(FmncAMToolAvl* rec);

	FmncAMToolAvl* operator[](const uint ix);
	ListFmncAMToolAvl& operator=(const ListFmncAMToolAvl& src);
	bool operator==(const ListFmncAMToolAvl& comp);
	bool operator!=(const ListFmncAMToolAvl& comp);

public:
	vector<FmncAMToolAvl*> nodes;
};

/**
  * TblFmncAMToolAvl: C++ wrapper for table TblFmncAMToolAvl
  */
class TblFmncAMToolAvl {

public:
	TblFmncAMToolAvl();
	virtual ~TblFmncAMToolAvl();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMToolAvl** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolAvl& rst);

	virtual void insertRec(FmncAMToolAvl* rec);
	ubigint insertNewRec(FmncAMToolAvl** rec = NULL, const ubigint refFmncMTool = 0, const uint x1Startd = 0, const uint x2IxVWkday = 0, const uint x3Startt = 0, const uint x3Stopt = 0, const string srefKAvltype = "");
	ubigint appendNewRecToRst(ListFmncAMToolAvl& rst, FmncAMToolAvl** rec = NULL, const ubigint refFmncMTool = 0, const uint x1Startd = 0, const uint x2IxVWkday = 0, const uint x3Startt = 0, const uint x3Stopt = 0, const string srefKAvltype = "");
	virtual void insertRst(ListFmncAMToolAvl& rst, bool transact = false);
	virtual void updateRec(FmncAMToolAvl* rec);
	virtual void updateRst(ListFmncAMToolAvl& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMToolAvl** rec);
	virtual ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMToolAvl& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMToolAvl: C++ wrapper for table TblFmncAMToolAvl (MySQL database)
  */
class MyTblFmncAMToolAvl : public TblFmncAMToolAvl, public MyTable {

public:
	MyTblFmncAMToolAvl();
	~MyTblFmncAMToolAvl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMToolAvl** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolAvl& rst);

	void insertRec(FmncAMToolAvl* rec);
	void insertRst(ListFmncAMToolAvl& rst, bool transact = false);
	void updateRec(FmncAMToolAvl* rec);
	void updateRst(ListFmncAMToolAvl& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMToolAvl** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMToolAvl: C++ wrapper for table TblFmncAMToolAvl (PgSQL database)
  */
class PgTblFmncAMToolAvl : public TblFmncAMToolAvl, public PgTable {

public:
	PgTblFmncAMToolAvl();
	~PgTblFmncAMToolAvl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMToolAvl** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMToolAvl& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMToolAvl** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMToolAvl** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolAvl& rst);

	void insertRec(FmncAMToolAvl* rec);
	void insertRst(ListFmncAMToolAvl& rst, bool transact = false);
	void updateRec(FmncAMToolAvl* rec);
	void updateRst(ListFmncAMToolAvl& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMToolAvl** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

