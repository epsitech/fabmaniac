/**
  * \file FmncJMToolUnitprice.h
  * database access for table TblFmncJMToolUnitprice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMTOOLUNITPRICE_H
#define FMNCJMTOOLUNITPRICE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMToolUnitprice: record of TblFmncJMToolUnitprice
  */
class FmncJMToolUnitprice {

public:
	FmncJMToolUnitprice(const ubigint ref = 0, const ubigint refFmncMTool = 0, const uint x1Startd = 0, const double Unitprice = 0.0);

public:
	ubigint ref;
	ubigint refFmncMTool;
	uint x1Startd;
	double Unitprice;

public:
	bool operator==(const FmncJMToolUnitprice& comp);
	bool operator!=(const FmncJMToolUnitprice& comp);
};

/**
  * ListFmncJMToolUnitprice: recordset of TblFmncJMToolUnitprice
  */
class ListFmncJMToolUnitprice {

public:
	ListFmncJMToolUnitprice();
	ListFmncJMToolUnitprice(const ListFmncJMToolUnitprice& src);
	~ListFmncJMToolUnitprice();

	void clear();
	unsigned int size() const;
	void append(FmncJMToolUnitprice* rec);

	FmncJMToolUnitprice* operator[](const uint ix);
	ListFmncJMToolUnitprice& operator=(const ListFmncJMToolUnitprice& src);
	bool operator==(const ListFmncJMToolUnitprice& comp);
	bool operator!=(const ListFmncJMToolUnitprice& comp);

public:
	vector<FmncJMToolUnitprice*> nodes;
};

/**
  * TblFmncJMToolUnitprice: C++ wrapper for table TblFmncJMToolUnitprice
  */
class TblFmncJMToolUnitprice {

public:
	TblFmncJMToolUnitprice();
	virtual ~TblFmncJMToolUnitprice();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMToolUnitprice** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMToolUnitprice& rst);

	virtual void insertRec(FmncJMToolUnitprice* rec);
	ubigint insertNewRec(FmncJMToolUnitprice** rec = NULL, const ubigint refFmncMTool = 0, const uint x1Startd = 0, const double Unitprice = 0.0);
	ubigint appendNewRecToRst(ListFmncJMToolUnitprice& rst, FmncJMToolUnitprice** rec = NULL, const ubigint refFmncMTool = 0, const uint x1Startd = 0, const double Unitprice = 0.0);
	virtual void insertRst(ListFmncJMToolUnitprice& rst, bool transact = false);
	virtual void updateRec(FmncJMToolUnitprice* rec);
	virtual void updateRst(ListFmncJMToolUnitprice& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMToolUnitprice** rec);
	virtual bool loadRecByTolSta(ubigint refFmncMTool, uint x1Startd, FmncJMToolUnitprice** rec);
	virtual ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByTol(ubigint refFmncMTool, const bool append, ListFmncJMToolUnitprice& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMToolUnitprice& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMToolUnitprice: C++ wrapper for table TblFmncJMToolUnitprice (MySQL database)
  */
class MyTblFmncJMToolUnitprice : public TblFmncJMToolUnitprice, public MyTable {

public:
	MyTblFmncJMToolUnitprice();
	~MyTblFmncJMToolUnitprice();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMToolUnitprice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMToolUnitprice& rst);

	void insertRec(FmncJMToolUnitprice* rec);
	void insertRst(ListFmncJMToolUnitprice& rst, bool transact = false);
	void updateRec(FmncJMToolUnitprice* rec);
	void updateRst(ListFmncJMToolUnitprice& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMToolUnitprice** rec);
	bool loadRecByTolSta(ubigint refFmncMTool, uint x1Startd, FmncJMToolUnitprice** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	ubigint loadRstByTol(ubigint refFmncMTool, const bool append, ListFmncJMToolUnitprice& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMToolUnitprice: C++ wrapper for table TblFmncJMToolUnitprice (PgSQL database)
  */
class PgTblFmncJMToolUnitprice : public TblFmncJMToolUnitprice, public PgTable {

public:
	PgTblFmncJMToolUnitprice();
	~PgTblFmncJMToolUnitprice();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMToolUnitprice** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMToolUnitprice& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMToolUnitprice** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMToolUnitprice& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMToolUnitprice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMToolUnitprice& rst);

	void insertRec(FmncJMToolUnitprice* rec);
	void insertRst(ListFmncJMToolUnitprice& rst, bool transact = false);
	void updateRec(FmncJMToolUnitprice* rec);
	void updateRst(ListFmncJMToolUnitprice& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMToolUnitprice** rec);
	bool loadRecByTolSta(ubigint refFmncMTool, uint x1Startd, FmncJMToolUnitprice** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	ubigint loadRstByTol(ubigint refFmncMTool, const bool append, ListFmncJMToolUnitprice& rst);
};
// IP pgTbl --- END

#endif

