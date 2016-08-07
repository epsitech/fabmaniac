/**
  * \file FmncQArtList.h
  * Dbs and XML wrapper for table TblFmncQArtList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQARTLIST_H
#define FMNCQARTLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArtList: record of TblFmncQArtList
  */
class FmncQArtList {

public:
	FmncQArtList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMTool = 0, const string stubRefFmncMTool = "", const string srefKType = "", const string titSrefKType = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string Title;
	ubigint refFmncMOrg;
	string stubRefFmncMOrg;
	ubigint refFmncMTool;
	string stubRefFmncMTool;
	string srefKType;
	string titSrefKType;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQArtList: recordset of TblFmncQArtList
  */
class ListFmncQArtList {

public:
	ListFmncQArtList();
	ListFmncQArtList(const ListFmncQArtList& src);
	~ListFmncQArtList();

	void clear();
	unsigned int size() const;
	void append(FmncQArtList* rec);

	ListFmncQArtList& operator=(const ListFmncQArtList& src);

public:
	vector<FmncQArtList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQArtList: C++ wrapper for table TblFmncQArtList
  */
class TblFmncQArtList {

public:
	TblFmncQArtList();
	virtual ~TblFmncQArtList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQArtList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtList& rst);

	virtual void insertRec(FmncQArtList* rec);
	ubigint insertNewRec(FmncQArtList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMTool = 0, const string stubRefFmncMTool = "", const string srefKType = "", const string titSrefKType = "");
	ubigint appendNewRecToRst(ListFmncQArtList& rst, FmncQArtList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMTool = 0, const string stubRefFmncMTool = "", const string srefKType = "", const string titSrefKType = "");
	virtual void insertRst(ListFmncQArtList& rst);
	virtual void updateRec(FmncQArtList* rec);
	virtual void updateRst(ListFmncQArtList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQArtList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQArtList: C++ wrapper for table TblFmncQArtList (MySQL database)
  */
class MyTblFmncQArtList : public TblFmncQArtList, public MyTable {

public:
	MyTblFmncQArtList();
	~MyTblFmncQArtList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArtList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtList& rst);

	void insertRec(FmncQArtList* rec);
	void insertRst(ListFmncQArtList& rst);
	void updateRec(FmncQArtList* rec);
	void updateRst(ListFmncQArtList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArtList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQArtList: C++ wrapper for table TblFmncQArtList (PgSQL database)
  */
class PgTblFmncQArtList : public TblFmncQArtList, public PgTable {

public:
	PgTblFmncQArtList();
	~PgTblFmncQArtList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQArtList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQArtList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQArtList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQArtList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArtList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtList& rst);

	void insertRec(FmncQArtList* rec);
	void insertRst(ListFmncQArtList& rst);
	void updateRec(FmncQArtList* rec);
	void updateRst(ListFmncQArtList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArtList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtList& rst);
};
// IP pgTbl --- END

#endif

