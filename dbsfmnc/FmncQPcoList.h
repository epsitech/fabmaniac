/**
  * \file FmncQPcoList.h
  * Dbs and XML wrapper for table TblFmncQPcoList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPCOLIST_H
#define FMNCQPCOLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPcoList: record of TblFmncQPcoList
  */
class FmncQPcoList {

public:
	FmncQPcoList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint Date = 0, const string ftmDate = "", const ubigint pcoRefFmncMOrg = 0, const string stubPcoRefFmncMOrg = "", const ubigint splRefFmncMOrg = 0, const string stubSplRefFmncMOrg = "", const ubigint refFmncMFile = 0, const string stubRefFmncMFile = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const double Amount = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	uint Date;
	string ftmDate;
	ubigint pcoRefFmncMOrg;
	string stubPcoRefFmncMOrg;
	ubigint splRefFmncMOrg;
	string stubSplRefFmncMOrg;
	ubigint refFmncMFile;
	string stubRefFmncMFile;
	uint ixVState;
	string srefIxVState;
	string titIxVState;
	double Amount;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPcoList: recordset of TblFmncQPcoList
  */
class ListFmncQPcoList {

public:
	ListFmncQPcoList();
	ListFmncQPcoList(const ListFmncQPcoList& src);
	~ListFmncQPcoList();

	void clear();
	unsigned int size() const;
	void append(FmncQPcoList* rec);

	ListFmncQPcoList& operator=(const ListFmncQPcoList& src);

public:
	vector<FmncQPcoList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPcoList: C++ wrapper for table TblFmncQPcoList
  */
class TblFmncQPcoList {

public:
	TblFmncQPcoList();
	virtual ~TblFmncQPcoList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPcoList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPcoList& rst);

	virtual void insertRec(FmncQPcoList* rec);
	ubigint insertNewRec(FmncQPcoList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint Date = 0, const string ftmDate = "", const ubigint pcoRefFmncMOrg = 0, const string stubPcoRefFmncMOrg = "", const ubigint splRefFmncMOrg = 0, const string stubSplRefFmncMOrg = "", const ubigint refFmncMFile = 0, const string stubRefFmncMFile = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const double Amount = 0.0);
	ubigint appendNewRecToRst(ListFmncQPcoList& rst, FmncQPcoList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint Date = 0, const string ftmDate = "", const ubigint pcoRefFmncMOrg = 0, const string stubPcoRefFmncMOrg = "", const ubigint splRefFmncMOrg = 0, const string stubSplRefFmncMOrg = "", const ubigint refFmncMFile = 0, const string stubRefFmncMFile = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const double Amount = 0.0);
	virtual void insertRst(ListFmncQPcoList& rst);
	virtual void updateRec(FmncQPcoList* rec);
	virtual void updateRst(ListFmncQPcoList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPcoList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPcoList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPcoList: C++ wrapper for table TblFmncQPcoList (MySQL database)
  */
class MyTblFmncQPcoList : public TblFmncQPcoList, public MyTable {

public:
	MyTblFmncQPcoList();
	~MyTblFmncQPcoList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPcoList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPcoList& rst);

	void insertRec(FmncQPcoList* rec);
	void insertRst(ListFmncQPcoList& rst);
	void updateRec(FmncQPcoList* rec);
	void updateRst(ListFmncQPcoList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPcoList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPcoList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPcoList: C++ wrapper for table TblFmncQPcoList (PgSQL database)
  */
class PgTblFmncQPcoList : public TblFmncQPcoList, public PgTable {

public:
	PgTblFmncQPcoList();
	~PgTblFmncQPcoList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPcoList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPcoList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPcoList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPcoList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPcoList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPcoList& rst);

	void insertRec(FmncQPcoList* rec);
	void insertRst(ListFmncQPcoList& rst);
	void updateRec(FmncQPcoList* rec);
	void updateRst(ListFmncQPcoList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPcoList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPcoList& rst);
};
// IP pgTbl --- END

#endif

