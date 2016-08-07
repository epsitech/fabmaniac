/**
  * \file FmncQSmpList.h
  * Dbs and XML wrapper for table TblFmncQSmpList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPLIST_H
#define FMNCQSMPLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpList: record of TblFmncQSmpList
  */
class FmncQSmpList {

public:
	FmncQSmpList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint supRefFmncMSample = 0, const string stubSupRefFmncMSample = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const string Material = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	ubigint supRefFmncMSample;
	string stubSupRefFmncMSample;
	ubigint refFmncMArticle;
	string stubRefFmncMArticle;
	string Material;
	uint ixVState;
	string srefIxVState;
	string titIxVState;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQSmpList: recordset of TblFmncQSmpList
  */
class ListFmncQSmpList {

public:
	ListFmncQSmpList();
	ListFmncQSmpList(const ListFmncQSmpList& src);
	~ListFmncQSmpList();

	void clear();
	unsigned int size() const;
	void append(FmncQSmpList* rec);

	ListFmncQSmpList& operator=(const ListFmncQSmpList& src);

public:
	vector<FmncQSmpList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSmpList: C++ wrapper for table TblFmncQSmpList
  */
class TblFmncQSmpList {

public:
	TblFmncQSmpList();
	virtual ~TblFmncQSmpList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSmpList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpList& rst);

	virtual void insertRec(FmncQSmpList* rec);
	ubigint insertNewRec(FmncQSmpList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint supRefFmncMSample = 0, const string stubSupRefFmncMSample = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const string Material = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	ubigint appendNewRecToRst(ListFmncQSmpList& rst, FmncQSmpList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint supRefFmncMSample = 0, const string stubSupRefFmncMSample = "", const ubigint refFmncMArticle = 0, const string stubRefFmncMArticle = "", const string Material = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	virtual void insertRst(ListFmncQSmpList& rst);
	virtual void updateRec(FmncQSmpList* rec);
	virtual void updateRst(ListFmncQSmpList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSmpList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSmpList: C++ wrapper for table TblFmncQSmpList (MySQL database)
  */
class MyTblFmncQSmpList : public TblFmncQSmpList, public MyTable {

public:
	MyTblFmncQSmpList();
	~MyTblFmncQSmpList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpList& rst);

	void insertRec(FmncQSmpList* rec);
	void insertRst(ListFmncQSmpList& rst);
	void updateRec(FmncQSmpList* rec);
	void updateRst(ListFmncQSmpList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSmpList: C++ wrapper for table TblFmncQSmpList (PgSQL database)
  */
class PgTblFmncQSmpList : public TblFmncQSmpList, public PgTable {

public:
	PgTblFmncQSmpList();
	~PgTblFmncQSmpList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSmpList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSmpList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSmpList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSmpList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpList& rst);

	void insertRec(FmncQSmpList* rec);
	void insertRst(ListFmncQSmpList& rst);
	void updateRec(FmncQSmpList* rec);
	void updateRst(ListFmncQSmpList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpList& rst);
};
// IP pgTbl --- END

#endif

