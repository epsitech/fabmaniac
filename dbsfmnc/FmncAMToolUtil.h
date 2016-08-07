/**
  * \file FmncAMToolUtil.h
  * database access for table TblFmncAMToolUtil (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMTOOLUTIL_H
#define FMNCAMTOOLUTIL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMToolUtil: record of TblFmncAMToolUtil
  */
class FmncAMToolUtil {

public:
	FmncAMToolUtil(const ubigint ref = 0, const ubigint refFmncMTool = 0, const ubigint x1RefFmncMFabproject = 0, const ubigint x2RefFmncMFabuser = 0, const uint startd = 0, const uint startt = 0, const uint stopt = 0, const double Unitprice = 0.0, const string Comment = "");

public:
	ubigint ref;
	ubigint refFmncMTool;
	ubigint x1RefFmncMFabproject;
	ubigint x2RefFmncMFabuser;
	uint startd;
	uint startt;
	uint stopt;
	double Unitprice;
	string Comment;

public:
	bool operator==(const FmncAMToolUtil& comp);
	bool operator!=(const FmncAMToolUtil& comp);
};

/**
  * ListFmncAMToolUtil: recordset of TblFmncAMToolUtil
  */
class ListFmncAMToolUtil {

public:
	ListFmncAMToolUtil();
	ListFmncAMToolUtil(const ListFmncAMToolUtil& src);
	~ListFmncAMToolUtil();

	void clear();
	unsigned int size() const;
	void append(FmncAMToolUtil* rec);

	FmncAMToolUtil* operator[](const uint ix);
	ListFmncAMToolUtil& operator=(const ListFmncAMToolUtil& src);
	bool operator==(const ListFmncAMToolUtil& comp);
	bool operator!=(const ListFmncAMToolUtil& comp);

public:
	vector<FmncAMToolUtil*> nodes;
};

/**
  * TblFmncAMToolUtil: C++ wrapper for table TblFmncAMToolUtil
  */
class TblFmncAMToolUtil {

public:
	TblFmncAMToolUtil();
	virtual ~TblFmncAMToolUtil();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMToolUtil** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolUtil& rst);

	virtual void insertRec(FmncAMToolUtil* rec);
	ubigint insertNewRec(FmncAMToolUtil** rec = NULL, const ubigint refFmncMTool = 0, const ubigint x1RefFmncMFabproject = 0, const ubigint x2RefFmncMFabuser = 0, const uint startd = 0, const uint startt = 0, const uint stopt = 0, const double Unitprice = 0.0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncAMToolUtil& rst, FmncAMToolUtil** rec = NULL, const ubigint refFmncMTool = 0, const ubigint x1RefFmncMFabproject = 0, const ubigint x2RefFmncMFabuser = 0, const uint startd = 0, const uint startt = 0, const uint stopt = 0, const double Unitprice = 0.0, const string Comment = "");
	virtual void insertRst(ListFmncAMToolUtil& rst, bool transact = false);
	virtual void updateRec(FmncAMToolUtil* rec);
	virtual void updateRst(ListFmncAMToolUtil& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMToolUtil** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMToolUtil& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMToolUtil: C++ wrapper for table TblFmncAMToolUtil (MySQL database)
  */
class MyTblFmncAMToolUtil : public TblFmncAMToolUtil, public MyTable {

public:
	MyTblFmncAMToolUtil();
	~MyTblFmncAMToolUtil();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMToolUtil** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolUtil& rst);

	void insertRec(FmncAMToolUtil* rec);
	void insertRst(ListFmncAMToolUtil& rst, bool transact = false);
	void updateRec(FmncAMToolUtil* rec);
	void updateRst(ListFmncAMToolUtil& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMToolUtil** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMToolUtil: C++ wrapper for table TblFmncAMToolUtil (PgSQL database)
  */
class PgTblFmncAMToolUtil : public TblFmncAMToolUtil, public PgTable {

public:
	PgTblFmncAMToolUtil();
	~PgTblFmncAMToolUtil();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMToolUtil** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMToolUtil& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMToolUtil** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMToolUtil** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolUtil& rst);

	void insertRec(FmncAMToolUtil* rec);
	void insertRst(ListFmncAMToolUtil& rst, bool transact = false);
	void updateRec(FmncAMToolUtil* rec);
	void updateRst(ListFmncAMToolUtil& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMToolUtil** rec);
};
// IP pgTbl --- END

#endif

