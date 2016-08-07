/**
  * \file FmncSvcRMOrgMTool.h
  * database access for table TblFmncSvcRMOrgMTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCSVCRMORGMTOOL_H
#define FMNCSVCRMORGMTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncSvcRMOrgMTool: record of TblFmncSvcRMOrgMTool
  */
class FmncSvcRMOrgMTool {

public:
	FmncSvcRMOrgMTool(const ubigint ref = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMTool = 0);

public:
	ubigint ref;
	ubigint refFmncMOrg;
	ubigint refFmncMTool;

public:
	bool operator==(const FmncSvcRMOrgMTool& comp);
	bool operator!=(const FmncSvcRMOrgMTool& comp);
};

/**
  * ListFmncSvcRMOrgMTool: recordset of TblFmncSvcRMOrgMTool
  */
class ListFmncSvcRMOrgMTool {

public:
	ListFmncSvcRMOrgMTool();
	ListFmncSvcRMOrgMTool(const ListFmncSvcRMOrgMTool& src);
	~ListFmncSvcRMOrgMTool();

	void clear();
	unsigned int size() const;
	void append(FmncSvcRMOrgMTool* rec);

	FmncSvcRMOrgMTool* operator[](const uint ix);
	ListFmncSvcRMOrgMTool& operator=(const ListFmncSvcRMOrgMTool& src);
	bool operator==(const ListFmncSvcRMOrgMTool& comp);
	bool operator!=(const ListFmncSvcRMOrgMTool& comp);

public:
	vector<FmncSvcRMOrgMTool*> nodes;
};

/**
  * TblFmncSvcRMOrgMTool: C++ wrapper for table TblFmncSvcRMOrgMTool
  */
class TblFmncSvcRMOrgMTool {

public:
	TblFmncSvcRMOrgMTool();
	virtual ~TblFmncSvcRMOrgMTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncSvcRMOrgMTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncSvcRMOrgMTool& rst);

	virtual void insertRec(FmncSvcRMOrgMTool* rec);
	ubigint insertNewRec(FmncSvcRMOrgMTool** rec = NULL, const ubigint refFmncMOrg = 0, const ubigint refFmncMTool = 0);
	ubigint appendNewRecToRst(ListFmncSvcRMOrgMTool& rst, FmncSvcRMOrgMTool** rec = NULL, const ubigint refFmncMOrg = 0, const ubigint refFmncMTool = 0);
	virtual void insertRst(ListFmncSvcRMOrgMTool& rst, bool transact = false);
	virtual void updateRec(FmncSvcRMOrgMTool* rec);
	virtual void updateRst(ListFmncSvcRMOrgMTool& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncSvcRMOrgMTool** rec);
	virtual ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncSvcRMOrgMTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncSvcRMOrgMTool: C++ wrapper for table TblFmncSvcRMOrgMTool (MySQL database)
  */
class MyTblFmncSvcRMOrgMTool : public TblFmncSvcRMOrgMTool, public MyTable {

public:
	MyTblFmncSvcRMOrgMTool();
	~MyTblFmncSvcRMOrgMTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncSvcRMOrgMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncSvcRMOrgMTool& rst);

	void insertRec(FmncSvcRMOrgMTool* rec);
	void insertRst(ListFmncSvcRMOrgMTool& rst, bool transact = false);
	void updateRec(FmncSvcRMOrgMTool* rec);
	void updateRst(ListFmncSvcRMOrgMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncSvcRMOrgMTool** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncSvcRMOrgMTool: C++ wrapper for table TblFmncSvcRMOrgMTool (PgSQL database)
  */
class PgTblFmncSvcRMOrgMTool : public TblFmncSvcRMOrgMTool, public PgTable {

public:
	PgTblFmncSvcRMOrgMTool();
	~PgTblFmncSvcRMOrgMTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncSvcRMOrgMTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncSvcRMOrgMTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncSvcRMOrgMTool** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncSvcRMOrgMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncSvcRMOrgMTool& rst);

	void insertRec(FmncSvcRMOrgMTool* rec);
	void insertRst(ListFmncSvcRMOrgMTool& rst, bool transact = false);
	void updateRec(FmncSvcRMOrgMTool* rec);
	void updateRst(ListFmncSvcRMOrgMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncSvcRMOrgMTool** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

