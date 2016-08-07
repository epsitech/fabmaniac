/**
  * \file FmncAMBillPos.h
  * database access for table TblFmncAMBillPos (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMBILLPOS_H
#define FMNCAMBILLPOS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMBillPos: record of TblFmncAMBillPos
  */
class FmncAMBillPos {

public:
	FmncAMBillPos(const ubigint ref = 0, const ubigint bilRefFmncMBill = 0, const uint bilNum = 0, const ubigint x1RefFmncMFabuser = 0, const ubigint x2RefFmncMTool = 0, const double Quantity = 0.0, const string Article = "", const double Unitprice = 0.0, const double Price = 0.0);

public:
	ubigint ref;
	ubigint bilRefFmncMBill;
	uint bilNum;
	ubigint x1RefFmncMFabuser;
	ubigint x2RefFmncMTool;
	double Quantity;
	string Article;
	double Unitprice;
	double Price;

public:
	bool operator==(const FmncAMBillPos& comp);
	bool operator!=(const FmncAMBillPos& comp);
};

/**
  * ListFmncAMBillPos: recordset of TblFmncAMBillPos
  */
class ListFmncAMBillPos {

public:
	ListFmncAMBillPos();
	ListFmncAMBillPos(const ListFmncAMBillPos& src);
	~ListFmncAMBillPos();

	void clear();
	unsigned int size() const;
	void append(FmncAMBillPos* rec);

	FmncAMBillPos* operator[](const uint ix);
	ListFmncAMBillPos& operator=(const ListFmncAMBillPos& src);
	bool operator==(const ListFmncAMBillPos& comp);
	bool operator!=(const ListFmncAMBillPos& comp);

public:
	vector<FmncAMBillPos*> nodes;
};

/**
  * TblFmncAMBillPos: C++ wrapper for table TblFmncAMBillPos
  */
class TblFmncAMBillPos {

public:
	TblFmncAMBillPos();
	virtual ~TblFmncAMBillPos();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMBillPos** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMBillPos& rst);

	virtual void insertRec(FmncAMBillPos* rec);
	ubigint insertNewRec(FmncAMBillPos** rec = NULL, const ubigint bilRefFmncMBill = 0, const uint bilNum = 0, const ubigint x1RefFmncMFabuser = 0, const ubigint x2RefFmncMTool = 0, const double Quantity = 0.0, const string Article = "", const double Unitprice = 0.0, const double Price = 0.0);
	ubigint appendNewRecToRst(ListFmncAMBillPos& rst, FmncAMBillPos** rec = NULL, const ubigint bilRefFmncMBill = 0, const uint bilNum = 0, const ubigint x1RefFmncMFabuser = 0, const ubigint x2RefFmncMTool = 0, const double Quantity = 0.0, const string Article = "", const double Unitprice = 0.0, const double Price = 0.0);
	virtual void insertRst(ListFmncAMBillPos& rst, bool transact = false);
	virtual void updateRec(FmncAMBillPos* rec);
	virtual void updateRst(ListFmncAMBillPos& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMBillPos** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMBillPos& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMBillPos: C++ wrapper for table TblFmncAMBillPos (MySQL database)
  */
class MyTblFmncAMBillPos : public TblFmncAMBillPos, public MyTable {

public:
	MyTblFmncAMBillPos();
	~MyTblFmncAMBillPos();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMBillPos** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMBillPos& rst);

	void insertRec(FmncAMBillPos* rec);
	void insertRst(ListFmncAMBillPos& rst, bool transact = false);
	void updateRec(FmncAMBillPos* rec);
	void updateRst(ListFmncAMBillPos& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMBillPos** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMBillPos: C++ wrapper for table TblFmncAMBillPos (PgSQL database)
  */
class PgTblFmncAMBillPos : public TblFmncAMBillPos, public PgTable {

public:
	PgTblFmncAMBillPos();
	~PgTblFmncAMBillPos();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMBillPos** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMBillPos& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMBillPos** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMBillPos** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMBillPos& rst);

	void insertRec(FmncAMBillPos* rec);
	void insertRst(ListFmncAMBillPos& rst, bool transact = false);
	void updateRec(FmncAMBillPos* rec);
	void updateRst(ListFmncAMBillPos& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMBillPos** rec);
};
// IP pgTbl --- END

#endif

