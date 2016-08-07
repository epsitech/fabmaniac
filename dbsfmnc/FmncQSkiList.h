/**
  * \file FmncQSkiList.h
  * Dbs and XML wrapper for table TblFmncQSkiList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSKILIST_H
#define FMNCQSKILIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSkiList: record of TblFmncQSkiList
  */
class FmncQSkiList {

public:
	FmncQSkiList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const string Quantity = "", const string osrefFmncKStocklcn = "", const string titOsrefFmncKStocklcn = "", const uint Expdate = 0, const string ftmExpdate = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint refFmncMOrg;
	string stubRefFmncMOrg;
	ubigint refFmncMArticle;
	string stubRefFmncMArticle;
	string Quantity;
	string osrefFmncKStocklcn;
	string titOsrefFmncKStocklcn;
	uint Expdate;
	string ftmExpdate;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQSkiList: recordset of TblFmncQSkiList
  */
class ListFmncQSkiList {

public:
	ListFmncQSkiList();
	ListFmncQSkiList(const ListFmncQSkiList& src);
	~ListFmncQSkiList();

	void clear();
	unsigned int size() const;
	void append(FmncQSkiList* rec);

	ListFmncQSkiList& operator=(const ListFmncQSkiList& src);

public:
	vector<FmncQSkiList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSkiList: C++ wrapper for table TblFmncQSkiList
  */
class TblFmncQSkiList {

public:
	TblFmncQSkiList();
	virtual ~TblFmncQSkiList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSkiList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSkiList& rst);

	virtual void insertRec(FmncQSkiList* rec);
	ubigint insertNewRec(FmncQSkiList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const string Quantity = "", const string osrefFmncKStocklcn = "", const string titOsrefFmncKStocklcn = "", const uint Expdate = 0, const string ftmExpdate = "");
	ubigint appendNewRecToRst(ListFmncQSkiList& rst, FmncQSkiList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const string Quantity = "", const string osrefFmncKStocklcn = "", const string titOsrefFmncKStocklcn = "", const uint Expdate = 0, const string ftmExpdate = "");
	virtual void insertRst(ListFmncQSkiList& rst);
	virtual void updateRec(FmncQSkiList* rec);
	virtual void updateRst(ListFmncQSkiList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSkiList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSkiList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSkiList: C++ wrapper for table TblFmncQSkiList (MySQL database)
  */
class MyTblFmncQSkiList : public TblFmncQSkiList, public MyTable {

public:
	MyTblFmncQSkiList();
	~MyTblFmncQSkiList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSkiList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSkiList& rst);

	void insertRec(FmncQSkiList* rec);
	void insertRst(ListFmncQSkiList& rst);
	void updateRec(FmncQSkiList* rec);
	void updateRst(ListFmncQSkiList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSkiList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSkiList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSkiList: C++ wrapper for table TblFmncQSkiList (PgSQL database)
  */
class PgTblFmncQSkiList : public TblFmncQSkiList, public PgTable {

public:
	PgTblFmncQSkiList();
	~PgTblFmncQSkiList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSkiList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSkiList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSkiList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSkiList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSkiList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSkiList& rst);

	void insertRec(FmncQSkiList* rec);
	void insertRst(ListFmncQSkiList& rst);
	void updateRec(FmncQSkiList* rec);
	void updateRst(ListFmncQSkiList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSkiList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSkiList& rst);
};
// IP pgTbl --- END

#endif

