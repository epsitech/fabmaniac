/**
  * \file FmncQBilAPos.h
  * Dbs and XML wrapper for table TblFmncQBilAPos (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQBILAPOS_H
#define FMNCQBILAPOS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQBilAPos: record of TblFmncQBilAPos
  */
class FmncQBilAPos {

public:
	FmncQBilAPos(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint bilNum = 0, const ubigint x1RefFmncMFabuser = 0, const string stubX1RefFmncMFabuser = "", const ubigint x2RefFmncMTool = 0, const string stubX2RefFmncMTool = "", const double Quantity = 0.0, const string Article = "", const double Unitprice = 0.0, const double Price = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint bilNum;
	ubigint x1RefFmncMFabuser;
	string stubX1RefFmncMFabuser;
	ubigint x2RefFmncMTool;
	string stubX2RefFmncMTool;
	double Quantity;
	string Article;
	double Unitprice;
	double Price;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQBilAPos: recordset of TblFmncQBilAPos
  */
class ListFmncQBilAPos {

public:
	ListFmncQBilAPos();
	ListFmncQBilAPos(const ListFmncQBilAPos& src);
	~ListFmncQBilAPos();

	void clear();
	unsigned int size() const;
	void append(FmncQBilAPos* rec);

	ListFmncQBilAPos& operator=(const ListFmncQBilAPos& src);

public:
	vector<FmncQBilAPos*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQBilAPos: C++ wrapper for table TblFmncQBilAPos
  */
class TblFmncQBilAPos {

public:
	TblFmncQBilAPos();
	virtual ~TblFmncQBilAPos();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQBilAPos** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQBilAPos& rst);

	virtual void insertRec(FmncQBilAPos* rec);
	ubigint insertNewRec(FmncQBilAPos** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint bilNum = 0, const ubigint x1RefFmncMFabuser = 0, const string stubX1RefFmncMFabuser = "", const ubigint x2RefFmncMTool = 0, const string stubX2RefFmncMTool = "", const double Quantity = 0.0, const string Article = "", const double Unitprice = 0.0, const double Price = 0.0);
	ubigint appendNewRecToRst(ListFmncQBilAPos& rst, FmncQBilAPos** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint bilNum = 0, const ubigint x1RefFmncMFabuser = 0, const string stubX1RefFmncMFabuser = "", const ubigint x2RefFmncMTool = 0, const string stubX2RefFmncMTool = "", const double Quantity = 0.0, const string Article = "", const double Unitprice = 0.0, const double Price = 0.0);
	virtual void insertRst(ListFmncQBilAPos& rst);
	virtual void updateRec(FmncQBilAPos* rec);
	virtual void updateRst(ListFmncQBilAPos& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQBilAPos** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQBilAPos& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQBilAPos: C++ wrapper for table TblFmncQBilAPos (MySQL database)
  */
class MyTblFmncQBilAPos : public TblFmncQBilAPos, public MyTable {

public:
	MyTblFmncQBilAPos();
	~MyTblFmncQBilAPos();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQBilAPos** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQBilAPos& rst);

	void insertRec(FmncQBilAPos* rec);
	void insertRst(ListFmncQBilAPos& rst);
	void updateRec(FmncQBilAPos* rec);
	void updateRst(ListFmncQBilAPos& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQBilAPos** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQBilAPos& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQBilAPos: C++ wrapper for table TblFmncQBilAPos (PgSQL database)
  */
class PgTblFmncQBilAPos : public TblFmncQBilAPos, public PgTable {

public:
	PgTblFmncQBilAPos();
	~PgTblFmncQBilAPos();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQBilAPos** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQBilAPos& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQBilAPos** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQBilAPos& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQBilAPos** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQBilAPos& rst);

	void insertRec(FmncQBilAPos* rec);
	void insertRst(ListFmncQBilAPos& rst);
	void updateRec(FmncQBilAPos* rec);
	void updateRst(ListFmncQBilAPos& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQBilAPos** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQBilAPos& rst);
};
// IP pgTbl --- END

#endif

