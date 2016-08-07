/**
  * \file FmncQBilList.h
  * Dbs and XML wrapper for table TblFmncQBilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQBILLIST_H
#define FMNCQBILLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQBilList: record of TblFmncQBilList
  */
class FmncQBilList {

public:
	FmncQBilList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint Date = 0, const string ftmDate = "", const ubigint refFmncMFabproject = 0, const string stubRefFmncMFabproject = "", const ubigint refFmncMFile = 0, const string stubRefFmncMFile = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint Prdstart = 0, const string ftmPrdstart = "", const uint Prdstop = 0, const string ftmPrdstop = "", const double Amount = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	uint Date;
	string ftmDate;
	ubigint refFmncMFabproject;
	string stubRefFmncMFabproject;
	ubigint refFmncMFile;
	string stubRefFmncMFile;
	uint ixVState;
	string srefIxVState;
	string titIxVState;
	uint Prdstart;
	string ftmPrdstart;
	uint Prdstop;
	string ftmPrdstop;
	double Amount;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQBilList: recordset of TblFmncQBilList
  */
class ListFmncQBilList {

public:
	ListFmncQBilList();
	ListFmncQBilList(const ListFmncQBilList& src);
	~ListFmncQBilList();

	void clear();
	unsigned int size() const;
	void append(FmncQBilList* rec);

	ListFmncQBilList& operator=(const ListFmncQBilList& src);

public:
	vector<FmncQBilList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQBilList: C++ wrapper for table TblFmncQBilList
  */
class TblFmncQBilList {

public:
	TblFmncQBilList();
	virtual ~TblFmncQBilList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQBilList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQBilList& rst);

	virtual void insertRec(FmncQBilList* rec);
	ubigint insertNewRec(FmncQBilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint Date = 0, const string ftmDate = "", const ubigint refFmncMFabproject = 0, const string stubRefFmncMFabproject = "", const ubigint refFmncMFile = 0, const string stubRefFmncMFile = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint Prdstart = 0, const string ftmPrdstart = "", const uint Prdstop = 0, const string ftmPrdstop = "", const double Amount = 0.0);
	ubigint appendNewRecToRst(ListFmncQBilList& rst, FmncQBilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint Date = 0, const string ftmDate = "", const ubigint refFmncMFabproject = 0, const string stubRefFmncMFabproject = "", const ubigint refFmncMFile = 0, const string stubRefFmncMFile = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint Prdstart = 0, const string ftmPrdstart = "", const uint Prdstop = 0, const string ftmPrdstop = "", const double Amount = 0.0);
	virtual void insertRst(ListFmncQBilList& rst);
	virtual void updateRec(FmncQBilList* rec);
	virtual void updateRst(ListFmncQBilList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQBilList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQBilList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQBilList: C++ wrapper for table TblFmncQBilList (MySQL database)
  */
class MyTblFmncQBilList : public TblFmncQBilList, public MyTable {

public:
	MyTblFmncQBilList();
	~MyTblFmncQBilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQBilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQBilList& rst);

	void insertRec(FmncQBilList* rec);
	void insertRst(ListFmncQBilList& rst);
	void updateRec(FmncQBilList* rec);
	void updateRst(ListFmncQBilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQBilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQBilList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQBilList: C++ wrapper for table TblFmncQBilList (PgSQL database)
  */
class PgTblFmncQBilList : public TblFmncQBilList, public PgTable {

public:
	PgTblFmncQBilList();
	~PgTblFmncQBilList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQBilList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQBilList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQBilList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQBilList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQBilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQBilList& rst);

	void insertRec(FmncQBilList* rec);
	void insertRst(ListFmncQBilList& rst);
	void updateRec(FmncQBilList* rec);
	void updateRst(ListFmncQBilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQBilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQBilList& rst);
};
// IP pgTbl --- END

#endif

