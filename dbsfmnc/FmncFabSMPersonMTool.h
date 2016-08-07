/**
  * \file FmncFabSMPersonMTool.h
  * database access for table TblFmncFabSMPersonMTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCFABSMPERSONMTOOL_H
#define FMNCFABSMPERSONMTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncFabSMPersonMTool: record of TblFmncFabSMPersonMTool
  */
class FmncFabSMPersonMTool {

public:
	FmncFabSMPersonMTool(const ubigint ref = 0, const ubigint refFmncMPerson = 0, const ubigint refM = 0, const uint numM = 0);

public:
	ubigint ref;
	ubigint refFmncMPerson;
	ubigint refM;
	uint numM;

public:
	bool operator==(const FmncFabSMPersonMTool& comp);
	bool operator!=(const FmncFabSMPersonMTool& comp);
};

/**
  * ListFmncFabSMPersonMTool: recordset of TblFmncFabSMPersonMTool
  */
class ListFmncFabSMPersonMTool {

public:
	ListFmncFabSMPersonMTool();
	ListFmncFabSMPersonMTool(const ListFmncFabSMPersonMTool& src);
	~ListFmncFabSMPersonMTool();

	void clear();
	unsigned int size() const;
	void append(FmncFabSMPersonMTool* rec);

	FmncFabSMPersonMTool* operator[](const uint ix);
	ListFmncFabSMPersonMTool& operator=(const ListFmncFabSMPersonMTool& src);
	bool operator==(const ListFmncFabSMPersonMTool& comp);
	bool operator!=(const ListFmncFabSMPersonMTool& comp);

public:
	vector<FmncFabSMPersonMTool*> nodes;
};

/**
  * TblFmncFabSMPersonMTool: C++ wrapper for table TblFmncFabSMPersonMTool
  */
class TblFmncFabSMPersonMTool {

public:
	TblFmncFabSMPersonMTool();
	virtual ~TblFmncFabSMPersonMTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncFabSMPersonMTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncFabSMPersonMTool& rst);

	virtual void insertRec(FmncFabSMPersonMTool* rec);
	ubigint insertNewRec(FmncFabSMPersonMTool** rec = NULL, const ubigint refFmncMPerson = 0, const ubigint refM = 0, const uint numM = 0);
	ubigint appendNewRecToRst(ListFmncFabSMPersonMTool& rst, FmncFabSMPersonMTool** rec = NULL, const ubigint refFmncMPerson = 0, const ubigint refM = 0, const uint numM = 0);
	virtual void insertRst(ListFmncFabSMPersonMTool& rst, bool transact = false);
	virtual void updateRec(FmncFabSMPersonMTool* rec);
	virtual void updateRst(ListFmncFabSMPersonMTool& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncFabSMPersonMTool** rec);
	virtual ubigint loadRefsByM(ubigint refM, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByM(ubigint refM, const bool append, ListFmncFabSMPersonMTool& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncFabSMPersonMTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncFabSMPersonMTool: C++ wrapper for table TblFmncFabSMPersonMTool (MySQL database)
  */
class MyTblFmncFabSMPersonMTool : public TblFmncFabSMPersonMTool, public MyTable {

public:
	MyTblFmncFabSMPersonMTool();
	~MyTblFmncFabSMPersonMTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncFabSMPersonMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncFabSMPersonMTool& rst);

	void insertRec(FmncFabSMPersonMTool* rec);
	void insertRst(ListFmncFabSMPersonMTool& rst, bool transact = false);
	void updateRec(FmncFabSMPersonMTool* rec);
	void updateRst(ListFmncFabSMPersonMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncFabSMPersonMTool** rec);
	ubigint loadRefsByM(ubigint refM, const bool append, vector<ubigint>& refs);
	ubigint loadRstByM(ubigint refM, const bool append, ListFmncFabSMPersonMTool& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncFabSMPersonMTool: C++ wrapper for table TblFmncFabSMPersonMTool (PgSQL database)
  */
class PgTblFmncFabSMPersonMTool : public TblFmncFabSMPersonMTool, public PgTable {

public:
	PgTblFmncFabSMPersonMTool();
	~PgTblFmncFabSMPersonMTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncFabSMPersonMTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncFabSMPersonMTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncFabSMPersonMTool** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncFabSMPersonMTool& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncFabSMPersonMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncFabSMPersonMTool& rst);

	void insertRec(FmncFabSMPersonMTool* rec);
	void insertRst(ListFmncFabSMPersonMTool& rst, bool transact = false);
	void updateRec(FmncFabSMPersonMTool* rec);
	void updateRst(ListFmncFabSMPersonMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncFabSMPersonMTool** rec);
	ubigint loadRefsByM(ubigint refM, const bool append, vector<ubigint>& refs);
	ubigint loadRstByM(ubigint refM, const bool append, ListFmncFabSMPersonMTool& rst);
};
// IP pgTbl --- END

#endif

