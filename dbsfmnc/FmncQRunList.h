/**
  * \file FmncQRunList.h
  * Dbs and XML wrapper for table TblFmncQRunList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNLIST_H
#define FMNCQRUNLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunList: record of TblFmncQRunList
  */
class FmncQRunList {

public:
	FmncQRunList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMProject = 0, const string stubRefFmncMProject = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	ubigint refFmncMProject;
	string stubRefFmncMProject;
	uint ixVState;
	string srefIxVState;
	string titIxVState;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQRunList: recordset of TblFmncQRunList
  */
class ListFmncQRunList {

public:
	ListFmncQRunList();
	ListFmncQRunList(const ListFmncQRunList& src);
	~ListFmncQRunList();

	void clear();
	unsigned int size() const;
	void append(FmncQRunList* rec);

	ListFmncQRunList& operator=(const ListFmncQRunList& src);

public:
	vector<FmncQRunList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQRunList: C++ wrapper for table TblFmncQRunList
  */
class TblFmncQRunList {

public:
	TblFmncQRunList();
	virtual ~TblFmncQRunList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQRunList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunList& rst);

	virtual void insertRec(FmncQRunList* rec);
	ubigint insertNewRec(FmncQRunList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMProject = 0, const string stubRefFmncMProject = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	ubigint appendNewRecToRst(ListFmncQRunList& rst, FmncQRunList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMProject = 0, const string stubRefFmncMProject = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	virtual void insertRst(ListFmncQRunList& rst);
	virtual void updateRec(FmncQRunList* rec);
	virtual void updateRst(ListFmncQRunList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQRunList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQRunList: C++ wrapper for table TblFmncQRunList (MySQL database)
  */
class MyTblFmncQRunList : public TblFmncQRunList, public MyTable {

public:
	MyTblFmncQRunList();
	~MyTblFmncQRunList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunList& rst);

	void insertRec(FmncQRunList* rec);
	void insertRst(ListFmncQRunList& rst);
	void updateRec(FmncQRunList* rec);
	void updateRst(ListFmncQRunList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQRunList: C++ wrapper for table TblFmncQRunList (PgSQL database)
  */
class PgTblFmncQRunList : public TblFmncQRunList, public PgTable {

public:
	PgTblFmncQRunList();
	~PgTblFmncQRunList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQRunList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQRunList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQRunList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQRunList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunList& rst);

	void insertRec(FmncQRunList* rec);
	void insertRst(ListFmncQRunList& rst);
	void updateRec(FmncQRunList* rec);
	void updateRst(ListFmncQRunList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunList& rst);
};
// IP pgTbl --- END

#endif

