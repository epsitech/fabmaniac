/**
  * \file FmncMStockitem.h
  * database access for table TblFmncMStockitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMSTOCKITEM_H
#define FMNCMSTOCKITEM_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMStockitem: record of TblFmncMStockitem
  */
class FmncMStockitem {

public:
	FmncMStockitem(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMArticle = 0, const ubigint refJQuantity = 0, const string Quantity = "", const string osrefFmncKStocklcn = "", const uint Expdate = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncMOrg;
	ubigint refFmncMArticle;
	ubigint refJQuantity;
	string Quantity;
	string osrefFmncKStocklcn;
	uint Expdate;
	string Comment;

public:
	bool operator==(const FmncMStockitem& comp);
	bool operator!=(const FmncMStockitem& comp);
};

/**
  * ListFmncMStockitem: recordset of TblFmncMStockitem
  */
class ListFmncMStockitem {

public:
	ListFmncMStockitem();
	ListFmncMStockitem(const ListFmncMStockitem& src);
	~ListFmncMStockitem();

	void clear();
	unsigned int size() const;
	void append(FmncMStockitem* rec);

	FmncMStockitem* operator[](const uint ix);
	ListFmncMStockitem& operator=(const ListFmncMStockitem& src);
	bool operator==(const ListFmncMStockitem& comp);
	bool operator!=(const ListFmncMStockitem& comp);

public:
	vector<FmncMStockitem*> nodes;
};

/**
  * TblFmncMStockitem: C++ wrapper for table TblFmncMStockitem
  */
class TblFmncMStockitem {

public:
	TblFmncMStockitem();
	virtual ~TblFmncMStockitem();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMStockitem** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMStockitem& rst);

	virtual void insertRec(FmncMStockitem* rec);
	ubigint insertNewRec(FmncMStockitem** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMArticle = 0, const ubigint refJQuantity = 0, const string Quantity = "", const string osrefFmncKStocklcn = "", const uint Expdate = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMStockitem& rst, FmncMStockitem** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMArticle = 0, const ubigint refJQuantity = 0, const string Quantity = "", const string osrefFmncKStocklcn = "", const uint Expdate = 0, const string Comment = "");
	virtual void insertRst(ListFmncMStockitem& rst, bool transact = false);
	virtual void updateRec(FmncMStockitem* rec);
	virtual void updateRst(ListFmncMStockitem& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMStockitem** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMStockitem& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMStockitem: C++ wrapper for table TblFmncMStockitem (MySQL database)
  */
class MyTblFmncMStockitem : public TblFmncMStockitem, public MyTable {

public:
	MyTblFmncMStockitem();
	~MyTblFmncMStockitem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMStockitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMStockitem& rst);

	void insertRec(FmncMStockitem* rec);
	void insertRst(ListFmncMStockitem& rst, bool transact = false);
	void updateRec(FmncMStockitem* rec);
	void updateRst(ListFmncMStockitem& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMStockitem** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMStockitem: C++ wrapper for table TblFmncMStockitem (PgSQL database)
  */
class PgTblFmncMStockitem : public TblFmncMStockitem, public PgTable {

public:
	PgTblFmncMStockitem();
	~PgTblFmncMStockitem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMStockitem** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMStockitem& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMStockitem** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMStockitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMStockitem& rst);

	void insertRec(FmncMStockitem* rec);
	void insertRst(ListFmncMStockitem& rst, bool transact = false);
	void updateRec(FmncMStockitem* rec);
	void updateRst(ListFmncMStockitem& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMStockitem** rec);
};
// IP pgTbl --- END

#endif

