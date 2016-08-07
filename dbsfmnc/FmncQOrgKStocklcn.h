/**
  * \file FmncQOrgKStocklcn.h
  * Dbs and XML wrapper for table TblFmncQOrgKStocklcn (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGKSTOCKLCN_H
#define FMNCQORGKSTOCKLCN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgKStocklcn: record of TblFmncQOrgKStocklcn
  */
class FmncQOrgKStocklcn {

public:
	FmncQOrgKStocklcn(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint klsNum;
	bool Fixed;
	string yesnoFixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQOrgKStocklcn: recordset of TblFmncQOrgKStocklcn
  */
class ListFmncQOrgKStocklcn {

public:
	ListFmncQOrgKStocklcn();
	ListFmncQOrgKStocklcn(const ListFmncQOrgKStocklcn& src);
	~ListFmncQOrgKStocklcn();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgKStocklcn* rec);

	ListFmncQOrgKStocklcn& operator=(const ListFmncQOrgKStocklcn& src);

public:
	vector<FmncQOrgKStocklcn*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgKStocklcn: C++ wrapper for table TblFmncQOrgKStocklcn
  */
class TblFmncQOrgKStocklcn {

public:
	TblFmncQOrgKStocklcn();
	virtual ~TblFmncQOrgKStocklcn();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgKStocklcn** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgKStocklcn& rst);

	virtual void insertRec(FmncQOrgKStocklcn* rec);
	ubigint insertNewRec(FmncQOrgKStocklcn** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQOrgKStocklcn& rst, FmncQOrgKStocklcn** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncQOrgKStocklcn& rst);
	virtual void updateRec(FmncQOrgKStocklcn* rec);
	virtual void updateRst(ListFmncQOrgKStocklcn& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgKStocklcn** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgKStocklcn& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgKStocklcn: C++ wrapper for table TblFmncQOrgKStocklcn (MySQL database)
  */
class MyTblFmncQOrgKStocklcn : public TblFmncQOrgKStocklcn, public MyTable {

public:
	MyTblFmncQOrgKStocklcn();
	~MyTblFmncQOrgKStocklcn();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgKStocklcn** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgKStocklcn& rst);

	void insertRec(FmncQOrgKStocklcn* rec);
	void insertRst(ListFmncQOrgKStocklcn& rst);
	void updateRec(FmncQOrgKStocklcn* rec);
	void updateRst(ListFmncQOrgKStocklcn& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgKStocklcn** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgKStocklcn& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgKStocklcn: C++ wrapper for table TblFmncQOrgKStocklcn (PgSQL database)
  */
class PgTblFmncQOrgKStocklcn : public TblFmncQOrgKStocklcn, public PgTable {

public:
	PgTblFmncQOrgKStocklcn();
	~PgTblFmncQOrgKStocklcn();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgKStocklcn** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgKStocklcn& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgKStocklcn** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgKStocklcn& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgKStocklcn** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgKStocklcn& rst);

	void insertRec(FmncQOrgKStocklcn* rec);
	void insertRst(ListFmncQOrgKStocklcn& rst);
	void updateRec(FmncQOrgKStocklcn* rec);
	void updateRst(ListFmncQOrgKStocklcn& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgKStocklcn** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgKStocklcn& rst);
};
// IP pgTbl --- END

#endif

