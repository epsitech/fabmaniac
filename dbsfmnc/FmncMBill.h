/**
  * \file FmncMBill.h
  * database access for table TblFmncMBill (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMBILL_H
#define FMNCMBILL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMBill: record of TblFmncMBill
  */
class FmncMBill {

public:
	FmncMBill(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFabproject = 0, const ubigint refFmncMFile = 0, const string sref = "", const uint Date = 0, const ubigint refJState = 0, const uint ixVState = 0, const uint Prdstart = 0, const uint Prdstop = 0, const double Amount = 0.0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncMFabproject;
	ubigint refFmncMFile;
	string sref;
	uint Date;
	ubigint refJState;
	uint ixVState;
	uint Prdstart;
	uint Prdstop;
	double Amount;
	string Comment;

public:
	bool operator==(const FmncMBill& comp);
	bool operator!=(const FmncMBill& comp);
};

/**
  * ListFmncMBill: recordset of TblFmncMBill
  */
class ListFmncMBill {

public:
	ListFmncMBill();
	ListFmncMBill(const ListFmncMBill& src);
	~ListFmncMBill();

	void clear();
	unsigned int size() const;
	void append(FmncMBill* rec);

	FmncMBill* operator[](const uint ix);
	ListFmncMBill& operator=(const ListFmncMBill& src);
	bool operator==(const ListFmncMBill& comp);
	bool operator!=(const ListFmncMBill& comp);

public:
	vector<FmncMBill*> nodes;
};

/**
  * TblFmncMBill: C++ wrapper for table TblFmncMBill
  */
class TblFmncMBill {

public:
	TblFmncMBill();
	virtual ~TblFmncMBill();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMBill** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMBill& rst);

	virtual void insertRec(FmncMBill* rec);
	ubigint insertNewRec(FmncMBill** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFabproject = 0, const ubigint refFmncMFile = 0, const string sref = "", const uint Date = 0, const ubigint refJState = 0, const uint ixVState = 0, const uint Prdstart = 0, const uint Prdstop = 0, const double Amount = 0.0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMBill& rst, FmncMBill** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFabproject = 0, const ubigint refFmncMFile = 0, const string sref = "", const uint Date = 0, const ubigint refJState = 0, const uint ixVState = 0, const uint Prdstart = 0, const uint Prdstop = 0, const double Amount = 0.0, const string Comment = "");
	virtual void insertRst(ListFmncMBill& rst, bool transact = false);
	virtual void updateRec(FmncMBill* rec);
	virtual void updateRst(ListFmncMBill& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMBill** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMBill& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMBill: C++ wrapper for table TblFmncMBill (MySQL database)
  */
class MyTblFmncMBill : public TblFmncMBill, public MyTable {

public:
	MyTblFmncMBill();
	~MyTblFmncMBill();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMBill** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMBill& rst);

	void insertRec(FmncMBill* rec);
	void insertRst(ListFmncMBill& rst, bool transact = false);
	void updateRec(FmncMBill* rec);
	void updateRst(ListFmncMBill& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMBill** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMBill: C++ wrapper for table TblFmncMBill (PgSQL database)
  */
class PgTblFmncMBill : public TblFmncMBill, public PgTable {

public:
	PgTblFmncMBill();
	~PgTblFmncMBill();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMBill** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMBill& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMBill** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMBill** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMBill& rst);

	void insertRec(FmncMBill* rec);
	void insertRst(ListFmncMBill& rst, bool transact = false);
	void updateRec(FmncMBill* rec);
	void updateRst(ListFmncMBill& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMBill** rec);
};
// IP pgTbl --- END

#endif

