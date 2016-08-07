/**
  * \file FmncQFusList.h
  * Dbs and XML wrapper for table TblFmncQFusList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFUSLIST_H
#define FMNCQFUSLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFusList: record of TblFmncQFusList
  */
class FmncQFusList {

public:
	FmncQFusList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMPerson = 0, const string stubRefFmncMPerson = "", const string sref = "", const ubigint refFmncMFab = 0, const string stubRefFmncMFab = "", const ubigint refFmncMFabproject = 0, const string stubRefFmncMFabproject = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint refFmncMPerson;
	string stubRefFmncMPerson;
	string sref;
	ubigint refFmncMFab;
	string stubRefFmncMFab;
	ubigint refFmncMFabproject;
	string stubRefFmncMFabproject;
	uint ixVState;
	string srefIxVState;
	string titIxVState;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQFusList: recordset of TblFmncQFusList
  */
class ListFmncQFusList {

public:
	ListFmncQFusList();
	ListFmncQFusList(const ListFmncQFusList& src);
	~ListFmncQFusList();

	void clear();
	unsigned int size() const;
	void append(FmncQFusList* rec);

	ListFmncQFusList& operator=(const ListFmncQFusList& src);

public:
	vector<FmncQFusList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFusList: C++ wrapper for table TblFmncQFusList
  */
class TblFmncQFusList {

public:
	TblFmncQFusList();
	virtual ~TblFmncQFusList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFusList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusList& rst);

	virtual void insertRec(FmncQFusList* rec);
	ubigint insertNewRec(FmncQFusList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMPerson = 0, const string stubRefFmncMPerson = "", const string sref = "", const ubigint refFmncMFab = 0, const string stubRefFmncMFab = "", const ubigint refFmncMFabproject = 0, const string stubRefFmncMFabproject = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	ubigint appendNewRecToRst(ListFmncQFusList& rst, FmncQFusList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMPerson = 0, const string stubRefFmncMPerson = "", const string sref = "", const ubigint refFmncMFab = 0, const string stubRefFmncMFab = "", const ubigint refFmncMFabproject = 0, const string stubRefFmncMFabproject = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	virtual void insertRst(ListFmncQFusList& rst);
	virtual void updateRec(FmncQFusList* rec);
	virtual void updateRst(ListFmncQFusList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFusList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFusList: C++ wrapper for table TblFmncQFusList (MySQL database)
  */
class MyTblFmncQFusList : public TblFmncQFusList, public MyTable {

public:
	MyTblFmncQFusList();
	~MyTblFmncQFusList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFusList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusList& rst);

	void insertRec(FmncQFusList* rec);
	void insertRst(ListFmncQFusList& rst);
	void updateRec(FmncQFusList* rec);
	void updateRst(ListFmncQFusList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFusList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFusList: C++ wrapper for table TblFmncQFusList (PgSQL database)
  */
class PgTblFmncQFusList : public TblFmncQFusList, public PgTable {

public:
	PgTblFmncQFusList();
	~PgTblFmncQFusList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFusList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFusList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFusList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFusList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFusList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusList& rst);

	void insertRec(FmncQFusList* rec);
	void insertRst(ListFmncQFusList& rst);
	void updateRec(FmncQFusList* rec);
	void updateRst(ListFmncQFusList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFusList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusList& rst);
};
// IP pgTbl --- END

#endif

