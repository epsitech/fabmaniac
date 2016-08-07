/**
  * \file FmncQFpjList.h
  * Dbs and XML wrapper for table TblFmncQFpjList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFPJLIST_H
#define FMNCQFPJLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFpjList: record of TblFmncQFpjList
  */
class FmncQFpjList {

public:
	FmncQFpjList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint refFmncMFab = 0, const string stubRefFmncMFab = "", const ubigint bioRefFmncMOrg = 0, const string stubBioRefFmncMOrg = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string Title;
	ubigint refFmncMFab;
	string stubRefFmncMFab;
	ubigint bioRefFmncMOrg;
	string stubBioRefFmncMOrg;
	uint ixVState;
	string srefIxVState;
	string titIxVState;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQFpjList: recordset of TblFmncQFpjList
  */
class ListFmncQFpjList {

public:
	ListFmncQFpjList();
	ListFmncQFpjList(const ListFmncQFpjList& src);
	~ListFmncQFpjList();

	void clear();
	unsigned int size() const;
	void append(FmncQFpjList* rec);

	ListFmncQFpjList& operator=(const ListFmncQFpjList& src);

public:
	vector<FmncQFpjList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFpjList: C++ wrapper for table TblFmncQFpjList
  */
class TblFmncQFpjList {

public:
	TblFmncQFpjList();
	virtual ~TblFmncQFpjList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFpjList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpjList& rst);

	virtual void insertRec(FmncQFpjList* rec);
	ubigint insertNewRec(FmncQFpjList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint refFmncMFab = 0, const string stubRefFmncMFab = "", const ubigint bioRefFmncMOrg = 0, const string stubBioRefFmncMOrg = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	ubigint appendNewRecToRst(ListFmncQFpjList& rst, FmncQFpjList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint refFmncMFab = 0, const string stubRefFmncMFab = "", const ubigint bioRefFmncMOrg = 0, const string stubBioRefFmncMOrg = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	virtual void insertRst(ListFmncQFpjList& rst);
	virtual void updateRec(FmncQFpjList* rec);
	virtual void updateRst(ListFmncQFpjList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFpjList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpjList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFpjList: C++ wrapper for table TblFmncQFpjList (MySQL database)
  */
class MyTblFmncQFpjList : public TblFmncQFpjList, public MyTable {

public:
	MyTblFmncQFpjList();
	~MyTblFmncQFpjList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFpjList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpjList& rst);

	void insertRec(FmncQFpjList* rec);
	void insertRst(ListFmncQFpjList& rst);
	void updateRec(FmncQFpjList* rec);
	void updateRst(ListFmncQFpjList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFpjList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpjList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFpjList: C++ wrapper for table TblFmncQFpjList (PgSQL database)
  */
class PgTblFmncQFpjList : public TblFmncQFpjList, public PgTable {

public:
	PgTblFmncQFpjList();
	~PgTblFmncQFpjList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFpjList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFpjList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFpjList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFpjList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFpjList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpjList& rst);

	void insertRec(FmncQFpjList* rec);
	void insertRst(ListFmncQFpjList& rst);
	void updateRec(FmncQFpjList* rec);
	void updateRst(ListFmncQFpjList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFpjList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpjList& rst);
};
// IP pgTbl --- END

#endif

