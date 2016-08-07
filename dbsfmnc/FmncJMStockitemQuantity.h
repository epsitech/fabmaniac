/**
  * \file FmncJMStockitemQuantity.h
  * database access for table TblFmncJMStockitemQuantity (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMSTOCKITEMQUANTITY_H
#define FMNCJMSTOCKITEMQUANTITY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMStockitemQuantity: record of TblFmncJMStockitemQuantity
  */
class FmncJMStockitemQuantity {

public:
	FmncJMStockitemQuantity(const ubigint ref = 0, const ubigint refFmncMStockitem = 0, const uint x1Startd = 0, const string Quantity = "");

public:
	ubigint ref;
	ubigint refFmncMStockitem;
	uint x1Startd;
	string Quantity;

public:
	bool operator==(const FmncJMStockitemQuantity& comp);
	bool operator!=(const FmncJMStockitemQuantity& comp);
};

/**
  * ListFmncJMStockitemQuantity: recordset of TblFmncJMStockitemQuantity
  */
class ListFmncJMStockitemQuantity {

public:
	ListFmncJMStockitemQuantity();
	ListFmncJMStockitemQuantity(const ListFmncJMStockitemQuantity& src);
	~ListFmncJMStockitemQuantity();

	void clear();
	unsigned int size() const;
	void append(FmncJMStockitemQuantity* rec);

	FmncJMStockitemQuantity* operator[](const uint ix);
	ListFmncJMStockitemQuantity& operator=(const ListFmncJMStockitemQuantity& src);
	bool operator==(const ListFmncJMStockitemQuantity& comp);
	bool operator!=(const ListFmncJMStockitemQuantity& comp);

public:
	vector<FmncJMStockitemQuantity*> nodes;
};

/**
  * TblFmncJMStockitemQuantity: C++ wrapper for table TblFmncJMStockitemQuantity
  */
class TblFmncJMStockitemQuantity {

public:
	TblFmncJMStockitemQuantity();
	virtual ~TblFmncJMStockitemQuantity();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMStockitemQuantity** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMStockitemQuantity& rst);

	virtual void insertRec(FmncJMStockitemQuantity* rec);
	ubigint insertNewRec(FmncJMStockitemQuantity** rec = NULL, const ubigint refFmncMStockitem = 0, const uint x1Startd = 0, const string Quantity = "");
	ubigint appendNewRecToRst(ListFmncJMStockitemQuantity& rst, FmncJMStockitemQuantity** rec = NULL, const ubigint refFmncMStockitem = 0, const uint x1Startd = 0, const string Quantity = "");
	virtual void insertRst(ListFmncJMStockitemQuantity& rst, bool transact = false);
	virtual void updateRec(FmncJMStockitemQuantity* rec);
	virtual void updateRst(ListFmncJMStockitemQuantity& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMStockitemQuantity** rec);
	virtual bool loadRecBySkiSta(ubigint refFmncMStockitem, uint x1Startd, FmncJMStockitemQuantity** rec);
	virtual ubigint loadRstBySki(ubigint refFmncMStockitem, const bool append, ListFmncJMStockitemQuantity& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMStockitemQuantity& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMStockitemQuantity: C++ wrapper for table TblFmncJMStockitemQuantity (MySQL database)
  */
class MyTblFmncJMStockitemQuantity : public TblFmncJMStockitemQuantity, public MyTable {

public:
	MyTblFmncJMStockitemQuantity();
	~MyTblFmncJMStockitemQuantity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMStockitemQuantity** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMStockitemQuantity& rst);

	void insertRec(FmncJMStockitemQuantity* rec);
	void insertRst(ListFmncJMStockitemQuantity& rst, bool transact = false);
	void updateRec(FmncJMStockitemQuantity* rec);
	void updateRst(ListFmncJMStockitemQuantity& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMStockitemQuantity** rec);
	bool loadRecBySkiSta(ubigint refFmncMStockitem, uint x1Startd, FmncJMStockitemQuantity** rec);
	ubigint loadRstBySki(ubigint refFmncMStockitem, const bool append, ListFmncJMStockitemQuantity& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMStockitemQuantity: C++ wrapper for table TblFmncJMStockitemQuantity (PgSQL database)
  */
class PgTblFmncJMStockitemQuantity : public TblFmncJMStockitemQuantity, public PgTable {

public:
	PgTblFmncJMStockitemQuantity();
	~PgTblFmncJMStockitemQuantity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMStockitemQuantity** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMStockitemQuantity& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMStockitemQuantity** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMStockitemQuantity& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMStockitemQuantity** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMStockitemQuantity& rst);

	void insertRec(FmncJMStockitemQuantity* rec);
	void insertRst(ListFmncJMStockitemQuantity& rst, bool transact = false);
	void updateRec(FmncJMStockitemQuantity* rec);
	void updateRst(ListFmncJMStockitemQuantity& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMStockitemQuantity** rec);
	bool loadRecBySkiSta(ubigint refFmncMStockitem, uint x1Startd, FmncJMStockitemQuantity** rec);
	ubigint loadRstBySki(ubigint refFmncMStockitem, const bool append, ListFmncJMStockitemQuantity& rst);
};
// IP pgTbl --- END

#endif

