/**
  * \file FmncQFabList.h
  * Dbs and XML wrapper for table TblFmncQFabList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFABLIST_H
#define FMNCQFABLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFabList: record of TblFmncQFabList
  */
class FmncQFabList {

public:
	FmncQFabList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint refFmncMOrg;
	string stubRefFmncMOrg;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQFabList: recordset of TblFmncQFabList
  */
class ListFmncQFabList {

public:
	ListFmncQFabList();
	ListFmncQFabList(const ListFmncQFabList& src);
	~ListFmncQFabList();

	void clear();
	unsigned int size() const;
	void append(FmncQFabList* rec);

	ListFmncQFabList& operator=(const ListFmncQFabList& src);

public:
	vector<FmncQFabList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFabList: C++ wrapper for table TblFmncQFabList
  */
class TblFmncQFabList {

public:
	TblFmncQFabList();
	virtual ~TblFmncQFabList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFabList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabList& rst);

	virtual void insertRec(FmncQFabList* rec);
	ubigint insertNewRec(FmncQFabList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "");
	ubigint appendNewRecToRst(ListFmncQFabList& rst, FmncQFabList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "");
	virtual void insertRst(ListFmncQFabList& rst);
	virtual void updateRec(FmncQFabList* rec);
	virtual void updateRst(ListFmncQFabList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFabList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFabList: C++ wrapper for table TblFmncQFabList (MySQL database)
  */
class MyTblFmncQFabList : public TblFmncQFabList, public MyTable {

public:
	MyTblFmncQFabList();
	~MyTblFmncQFabList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFabList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabList& rst);

	void insertRec(FmncQFabList* rec);
	void insertRst(ListFmncQFabList& rst);
	void updateRec(FmncQFabList* rec);
	void updateRst(ListFmncQFabList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFabList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFabList: C++ wrapper for table TblFmncQFabList (PgSQL database)
  */
class PgTblFmncQFabList : public TblFmncQFabList, public PgTable {

public:
	PgTblFmncQFabList();
	~PgTblFmncQFabList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFabList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFabList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFabList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFabList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFabList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabList& rst);

	void insertRec(FmncQFabList* rec);
	void insertRst(ListFmncQFabList& rst);
	void updateRec(FmncQFabList* rec);
	void updateRst(ListFmncQFabList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFabList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabList& rst);
};
// IP pgTbl --- END

#endif

