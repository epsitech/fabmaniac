/**
  * \file FmncMnfSMPersonMTool.h
  * database access for table TblFmncMnfSMPersonMTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMNFSMPERSONMTOOL_H
#define FMNCMNFSMPERSONMTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMnfSMPersonMTool: record of TblFmncMnfSMPersonMTool
  */
class FmncMnfSMPersonMTool {

public:
	FmncMnfSMPersonMTool(const ubigint ref = 0, const ubigint refFmncMPerson = 0, const ubigint refM = 0);

public:
	ubigint ref;
	ubigint refFmncMPerson;
	ubigint refM;

public:
	bool operator==(const FmncMnfSMPersonMTool& comp);
	bool operator!=(const FmncMnfSMPersonMTool& comp);
};

/**
  * ListFmncMnfSMPersonMTool: recordset of TblFmncMnfSMPersonMTool
  */
class ListFmncMnfSMPersonMTool {

public:
	ListFmncMnfSMPersonMTool();
	ListFmncMnfSMPersonMTool(const ListFmncMnfSMPersonMTool& src);
	~ListFmncMnfSMPersonMTool();

	void clear();
	unsigned int size() const;
	void append(FmncMnfSMPersonMTool* rec);

	FmncMnfSMPersonMTool* operator[](const uint ix);
	ListFmncMnfSMPersonMTool& operator=(const ListFmncMnfSMPersonMTool& src);
	bool operator==(const ListFmncMnfSMPersonMTool& comp);
	bool operator!=(const ListFmncMnfSMPersonMTool& comp);

public:
	vector<FmncMnfSMPersonMTool*> nodes;
};

/**
  * TblFmncMnfSMPersonMTool: C++ wrapper for table TblFmncMnfSMPersonMTool
  */
class TblFmncMnfSMPersonMTool {

public:
	TblFmncMnfSMPersonMTool();
	virtual ~TblFmncMnfSMPersonMTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMnfSMPersonMTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMnfSMPersonMTool& rst);

	virtual void insertRec(FmncMnfSMPersonMTool* rec);
	ubigint insertNewRec(FmncMnfSMPersonMTool** rec = NULL, const ubigint refFmncMPerson = 0, const ubigint refM = 0);
	ubigint appendNewRecToRst(ListFmncMnfSMPersonMTool& rst, FmncMnfSMPersonMTool** rec = NULL, const ubigint refFmncMPerson = 0, const ubigint refM = 0);
	virtual void insertRst(ListFmncMnfSMPersonMTool& rst, bool transact = false);
	virtual void updateRec(FmncMnfSMPersonMTool* rec);
	virtual void updateRst(ListFmncMnfSMPersonMTool& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMnfSMPersonMTool** rec);
	virtual ubigint loadRefsByM(ubigint refM, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByM(ubigint refM, const bool append, ListFmncMnfSMPersonMTool& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMnfSMPersonMTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMnfSMPersonMTool: C++ wrapper for table TblFmncMnfSMPersonMTool (MySQL database)
  */
class MyTblFmncMnfSMPersonMTool : public TblFmncMnfSMPersonMTool, public MyTable {

public:
	MyTblFmncMnfSMPersonMTool();
	~MyTblFmncMnfSMPersonMTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMnfSMPersonMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMnfSMPersonMTool& rst);

	void insertRec(FmncMnfSMPersonMTool* rec);
	void insertRst(ListFmncMnfSMPersonMTool& rst, bool transact = false);
	void updateRec(FmncMnfSMPersonMTool* rec);
	void updateRst(ListFmncMnfSMPersonMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMnfSMPersonMTool** rec);
	ubigint loadRefsByM(ubigint refM, const bool append, vector<ubigint>& refs);
	ubigint loadRstByM(ubigint refM, const bool append, ListFmncMnfSMPersonMTool& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMnfSMPersonMTool: C++ wrapper for table TblFmncMnfSMPersonMTool (PgSQL database)
  */
class PgTblFmncMnfSMPersonMTool : public TblFmncMnfSMPersonMTool, public PgTable {

public:
	PgTblFmncMnfSMPersonMTool();
	~PgTblFmncMnfSMPersonMTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMnfSMPersonMTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMnfSMPersonMTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMnfSMPersonMTool** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncMnfSMPersonMTool& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncMnfSMPersonMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMnfSMPersonMTool& rst);

	void insertRec(FmncMnfSMPersonMTool* rec);
	void insertRst(ListFmncMnfSMPersonMTool& rst, bool transact = false);
	void updateRec(FmncMnfSMPersonMTool* rec);
	void updateRst(ListFmncMnfSMPersonMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMnfSMPersonMTool** rec);
	ubigint loadRefsByM(ubigint refM, const bool append, vector<ubigint>& refs);
	ubigint loadRstByM(ubigint refM, const bool append, ListFmncMnfSMPersonMTool& rst);
};
// IP pgTbl --- END

#endif

