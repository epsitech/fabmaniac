/**
  * \file FmncQPcoAPos.h
  * Dbs and XML wrapper for table TblFmncQPcoAPos (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPCOAPOS_H
#define FMNCQPCOAPOS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPcoAPos: record of TblFmncQPcoAPos
  */
class FmncQPcoAPos {

public:
	FmncQPcoAPos(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint pcoNum = 0, const double Quantity = 0.0, const string Itemno = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const double Unitprice = 0.0, const double Price = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint pcoNum;
	double Quantity;
	string Itemno;
	ubigint refFmncMArticle;
	string stubRefFmncMArticle;
	double Unitprice;
	double Price;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPcoAPos: recordset of TblFmncQPcoAPos
  */
class ListFmncQPcoAPos {

public:
	ListFmncQPcoAPos();
	ListFmncQPcoAPos(const ListFmncQPcoAPos& src);
	~ListFmncQPcoAPos();

	void clear();
	unsigned int size() const;
	void append(FmncQPcoAPos* rec);

	ListFmncQPcoAPos& operator=(const ListFmncQPcoAPos& src);

public:
	vector<FmncQPcoAPos*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPcoAPos: C++ wrapper for table TblFmncQPcoAPos
  */
class TblFmncQPcoAPos {

public:
	TblFmncQPcoAPos();
	virtual ~TblFmncQPcoAPos();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPcoAPos** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPcoAPos& rst);

	virtual void insertRec(FmncQPcoAPos* rec);
	ubigint insertNewRec(FmncQPcoAPos** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint pcoNum = 0, const double Quantity = 0.0, const string Itemno = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const double Unitprice = 0.0, const double Price = 0.0);
	ubigint appendNewRecToRst(ListFmncQPcoAPos& rst, FmncQPcoAPos** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint pcoNum = 0, const double Quantity = 0.0, const string Itemno = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const double Unitprice = 0.0, const double Price = 0.0);
	virtual void insertRst(ListFmncQPcoAPos& rst);
	virtual void updateRec(FmncQPcoAPos* rec);
	virtual void updateRst(ListFmncQPcoAPos& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPcoAPos** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPcoAPos& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPcoAPos: C++ wrapper for table TblFmncQPcoAPos (MySQL database)
  */
class MyTblFmncQPcoAPos : public TblFmncQPcoAPos, public MyTable {

public:
	MyTblFmncQPcoAPos();
	~MyTblFmncQPcoAPos();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPcoAPos** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPcoAPos& rst);

	void insertRec(FmncQPcoAPos* rec);
	void insertRst(ListFmncQPcoAPos& rst);
	void updateRec(FmncQPcoAPos* rec);
	void updateRst(ListFmncQPcoAPos& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPcoAPos** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPcoAPos& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPcoAPos: C++ wrapper for table TblFmncQPcoAPos (PgSQL database)
  */
class PgTblFmncQPcoAPos : public TblFmncQPcoAPos, public PgTable {

public:
	PgTblFmncQPcoAPos();
	~PgTblFmncQPcoAPos();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPcoAPos** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPcoAPos& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPcoAPos** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPcoAPos& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPcoAPos** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPcoAPos& rst);

	void insertRec(FmncQPcoAPos* rec);
	void insertRst(ListFmncQPcoAPos& rst);
	void updateRec(FmncQPcoAPos* rec);
	void updateRst(ListFmncQPcoAPos& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPcoAPos** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPcoAPos& rst);
};
// IP pgTbl --- END

#endif

