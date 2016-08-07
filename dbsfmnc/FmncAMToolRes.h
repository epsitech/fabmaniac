/**
  * \file FmncAMToolRes.h
  * database access for table TblFmncAMToolRes (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMTOOLRES_H
#define FMNCAMTOOLRES_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMToolRes: record of TblFmncAMToolRes
  */
class FmncAMToolRes {

public:
	FmncAMToolRes(const ubigint ref = 0, const ubigint refFmncMTool = 0, const ubigint x1RefFmncMFabuser = 0, const uint startd = 0, const uint startt = 0, const uint stopt = 0, const string srefKRestype = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refFmncMTool;
	ubigint x1RefFmncMFabuser;
	uint startd;
	uint startt;
	uint stopt;
	string srefKRestype;
	string Comment;

public:
	bool operator==(const FmncAMToolRes& comp);
	bool operator!=(const FmncAMToolRes& comp);
};

/**
  * ListFmncAMToolRes: recordset of TblFmncAMToolRes
  */
class ListFmncAMToolRes {

public:
	ListFmncAMToolRes();
	ListFmncAMToolRes(const ListFmncAMToolRes& src);
	~ListFmncAMToolRes();

	void clear();
	unsigned int size() const;
	void append(FmncAMToolRes* rec);

	FmncAMToolRes* operator[](const uint ix);
	ListFmncAMToolRes& operator=(const ListFmncAMToolRes& src);
	bool operator==(const ListFmncAMToolRes& comp);
	bool operator!=(const ListFmncAMToolRes& comp);

public:
	vector<FmncAMToolRes*> nodes;
};

/**
  * TblFmncAMToolRes: C++ wrapper for table TblFmncAMToolRes
  */
class TblFmncAMToolRes {

public:
	TblFmncAMToolRes();
	virtual ~TblFmncAMToolRes();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMToolRes** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolRes& rst);

	virtual void insertRec(FmncAMToolRes* rec);
	ubigint insertNewRec(FmncAMToolRes** rec = NULL, const ubigint refFmncMTool = 0, const ubigint x1RefFmncMFabuser = 0, const uint startd = 0, const uint startt = 0, const uint stopt = 0, const string srefKRestype = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncAMToolRes& rst, FmncAMToolRes** rec = NULL, const ubigint refFmncMTool = 0, const ubigint x1RefFmncMFabuser = 0, const uint startd = 0, const uint startt = 0, const uint stopt = 0, const string srefKRestype = "", const string Comment = "");
	virtual void insertRst(ListFmncAMToolRes& rst, bool transact = false);
	virtual void updateRec(FmncAMToolRes* rec);
	virtual void updateRst(ListFmncAMToolRes& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMToolRes** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMToolRes& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMToolRes: C++ wrapper for table TblFmncAMToolRes (MySQL database)
  */
class MyTblFmncAMToolRes : public TblFmncAMToolRes, public MyTable {

public:
	MyTblFmncAMToolRes();
	~MyTblFmncAMToolRes();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMToolRes** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolRes& rst);

	void insertRec(FmncAMToolRes* rec);
	void insertRst(ListFmncAMToolRes& rst, bool transact = false);
	void updateRec(FmncAMToolRes* rec);
	void updateRst(ListFmncAMToolRes& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMToolRes** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMToolRes: C++ wrapper for table TblFmncAMToolRes (PgSQL database)
  */
class PgTblFmncAMToolRes : public TblFmncAMToolRes, public PgTable {

public:
	PgTblFmncAMToolRes();
	~PgTblFmncAMToolRes();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMToolRes** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMToolRes& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMToolRes** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMToolRes** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolRes& rst);

	void insertRec(FmncAMToolRes* rec);
	void insertRst(ListFmncAMToolRes& rst, bool transact = false);
	void updateRec(FmncAMToolRes* rec);
	void updateRst(ListFmncAMToolRes& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMToolRes** rec);
};
// IP pgTbl --- END

#endif

