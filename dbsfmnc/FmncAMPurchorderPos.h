/**
  * \file FmncAMPurchorderPos.h
  * database access for table TblFmncAMPurchorderPos (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMPURCHORDERPOS_H
#define FMNCAMPURCHORDERPOS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMPurchorderPos: record of TblFmncAMPurchorderPos
  */
class FmncAMPurchorderPos {

public:
	FmncAMPurchorderPos(const ubigint ref = 0, const ubigint pcoRefFmncMPurchorder = 0, const uint pcoNum = 0, const double Quantity = 0.0, const string Itemno = "", const ubigint refFmncMArticle = 0, const double Unitprice = 0.0, const double Price = 0.0);

public:
	ubigint ref;
	ubigint pcoRefFmncMPurchorder;
	uint pcoNum;
	double Quantity;
	string Itemno;
	ubigint refFmncMArticle;
	double Unitprice;
	double Price;

public:
	bool operator==(const FmncAMPurchorderPos& comp);
	bool operator!=(const FmncAMPurchorderPos& comp);
};

/**
  * ListFmncAMPurchorderPos: recordset of TblFmncAMPurchorderPos
  */
class ListFmncAMPurchorderPos {

public:
	ListFmncAMPurchorderPos();
	ListFmncAMPurchorderPos(const ListFmncAMPurchorderPos& src);
	~ListFmncAMPurchorderPos();

	void clear();
	unsigned int size() const;
	void append(FmncAMPurchorderPos* rec);

	FmncAMPurchorderPos* operator[](const uint ix);
	ListFmncAMPurchorderPos& operator=(const ListFmncAMPurchorderPos& src);
	bool operator==(const ListFmncAMPurchorderPos& comp);
	bool operator!=(const ListFmncAMPurchorderPos& comp);

public:
	vector<FmncAMPurchorderPos*> nodes;
};

/**
  * TblFmncAMPurchorderPos: C++ wrapper for table TblFmncAMPurchorderPos
  */
class TblFmncAMPurchorderPos {

public:
	TblFmncAMPurchorderPos();
	virtual ~TblFmncAMPurchorderPos();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMPurchorderPos** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMPurchorderPos& rst);

	virtual void insertRec(FmncAMPurchorderPos* rec);
	ubigint insertNewRec(FmncAMPurchorderPos** rec = NULL, const ubigint pcoRefFmncMPurchorder = 0, const uint pcoNum = 0, const double Quantity = 0.0, const string Itemno = "", const ubigint refFmncMArticle = 0, const double Unitprice = 0.0, const double Price = 0.0);
	ubigint appendNewRecToRst(ListFmncAMPurchorderPos& rst, FmncAMPurchorderPos** rec = NULL, const ubigint pcoRefFmncMPurchorder = 0, const uint pcoNum = 0, const double Quantity = 0.0, const string Itemno = "", const ubigint refFmncMArticle = 0, const double Unitprice = 0.0, const double Price = 0.0);
	virtual void insertRst(ListFmncAMPurchorderPos& rst, bool transact = false);
	virtual void updateRec(FmncAMPurchorderPos* rec);
	virtual void updateRst(ListFmncAMPurchorderPos& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMPurchorderPos** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMPurchorderPos& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMPurchorderPos: C++ wrapper for table TblFmncAMPurchorderPos (MySQL database)
  */
class MyTblFmncAMPurchorderPos : public TblFmncAMPurchorderPos, public MyTable {

public:
	MyTblFmncAMPurchorderPos();
	~MyTblFmncAMPurchorderPos();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMPurchorderPos** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMPurchorderPos& rst);

	void insertRec(FmncAMPurchorderPos* rec);
	void insertRst(ListFmncAMPurchorderPos& rst, bool transact = false);
	void updateRec(FmncAMPurchorderPos* rec);
	void updateRst(ListFmncAMPurchorderPos& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMPurchorderPos** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMPurchorderPos: C++ wrapper for table TblFmncAMPurchorderPos (PgSQL database)
  */
class PgTblFmncAMPurchorderPos : public TblFmncAMPurchorderPos, public PgTable {

public:
	PgTblFmncAMPurchorderPos();
	~PgTblFmncAMPurchorderPos();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMPurchorderPos** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMPurchorderPos& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMPurchorderPos** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMPurchorderPos** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMPurchorderPos& rst);

	void insertRec(FmncAMPurchorderPos* rec);
	void insertRst(ListFmncAMPurchorderPos& rst, bool transact = false);
	void updateRec(FmncAMPurchorderPos* rec);
	void updateRst(ListFmncAMPurchorderPos& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMPurchorderPos** rec);
};
// IP pgTbl --- END

#endif

