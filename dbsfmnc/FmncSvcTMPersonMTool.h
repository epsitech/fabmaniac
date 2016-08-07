/**
  * \file FmncSvcTMPersonMTool.h
  * database access for table TblFmncSvcTMPersonMTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCSVCTMPERSONMTOOL_H
#define FMNCSVCTMPERSONMTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncSvcTMPersonMTool: record of TblFmncSvcTMPersonMTool
  */
class FmncSvcTMPersonMTool {

public:
	FmncSvcTMPersonMTool(const ubigint ref = 0, const ubigint refFmncMPerson = 0, const ubigint refR = 0);

public:
	ubigint ref;
	ubigint refFmncMPerson;
	ubigint refR;

public:
	bool operator==(const FmncSvcTMPersonMTool& comp);
	bool operator!=(const FmncSvcTMPersonMTool& comp);
};

/**
  * ListFmncSvcTMPersonMTool: recordset of TblFmncSvcTMPersonMTool
  */
class ListFmncSvcTMPersonMTool {

public:
	ListFmncSvcTMPersonMTool();
	ListFmncSvcTMPersonMTool(const ListFmncSvcTMPersonMTool& src);
	~ListFmncSvcTMPersonMTool();

	void clear();
	unsigned int size() const;
	void append(FmncSvcTMPersonMTool* rec);

	FmncSvcTMPersonMTool* operator[](const uint ix);
	ListFmncSvcTMPersonMTool& operator=(const ListFmncSvcTMPersonMTool& src);
	bool operator==(const ListFmncSvcTMPersonMTool& comp);
	bool operator!=(const ListFmncSvcTMPersonMTool& comp);

public:
	vector<FmncSvcTMPersonMTool*> nodes;
};

/**
  * TblFmncSvcTMPersonMTool: C++ wrapper for table TblFmncSvcTMPersonMTool
  */
class TblFmncSvcTMPersonMTool {

public:
	TblFmncSvcTMPersonMTool();
	virtual ~TblFmncSvcTMPersonMTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncSvcTMPersonMTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncSvcTMPersonMTool& rst);

	virtual void insertRec(FmncSvcTMPersonMTool* rec);
	ubigint insertNewRec(FmncSvcTMPersonMTool** rec = NULL, const ubigint refFmncMPerson = 0, const ubigint refR = 0);
	ubigint appendNewRecToRst(ListFmncSvcTMPersonMTool& rst, FmncSvcTMPersonMTool** rec = NULL, const ubigint refFmncMPerson = 0, const ubigint refR = 0);
	virtual void insertRst(ListFmncSvcTMPersonMTool& rst, bool transact = false);
	virtual void updateRec(FmncSvcTMPersonMTool* rec);
	virtual void updateRst(ListFmncSvcTMPersonMTool& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncSvcTMPersonMTool** rec);
	virtual ubigint loadRefsByR(ubigint refR, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByR(ubigint refR, const bool append, ListFmncSvcTMPersonMTool& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncSvcTMPersonMTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncSvcTMPersonMTool: C++ wrapper for table TblFmncSvcTMPersonMTool (MySQL database)
  */
class MyTblFmncSvcTMPersonMTool : public TblFmncSvcTMPersonMTool, public MyTable {

public:
	MyTblFmncSvcTMPersonMTool();
	~MyTblFmncSvcTMPersonMTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncSvcTMPersonMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncSvcTMPersonMTool& rst);

	void insertRec(FmncSvcTMPersonMTool* rec);
	void insertRst(ListFmncSvcTMPersonMTool& rst, bool transact = false);
	void updateRec(FmncSvcTMPersonMTool* rec);
	void updateRst(ListFmncSvcTMPersonMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncSvcTMPersonMTool** rec);
	ubigint loadRefsByR(ubigint refR, const bool append, vector<ubigint>& refs);
	ubigint loadRstByR(ubigint refR, const bool append, ListFmncSvcTMPersonMTool& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncSvcTMPersonMTool: C++ wrapper for table TblFmncSvcTMPersonMTool (PgSQL database)
  */
class PgTblFmncSvcTMPersonMTool : public TblFmncSvcTMPersonMTool, public PgTable {

public:
	PgTblFmncSvcTMPersonMTool();
	~PgTblFmncSvcTMPersonMTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncSvcTMPersonMTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncSvcTMPersonMTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncSvcTMPersonMTool** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncSvcTMPersonMTool& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncSvcTMPersonMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncSvcTMPersonMTool& rst);

	void insertRec(FmncSvcTMPersonMTool* rec);
	void insertRst(ListFmncSvcTMPersonMTool& rst, bool transact = false);
	void updateRec(FmncSvcTMPersonMTool* rec);
	void updateRst(ListFmncSvcTMPersonMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncSvcTMPersonMTool** rec);
	ubigint loadRefsByR(ubigint refR, const bool append, vector<ubigint>& refs);
	ubigint loadRstByR(ubigint refR, const bool append, ListFmncSvcTMPersonMTool& rst);
};
// IP pgTbl --- END

#endif

