/**
  * \file FmncQFilList.h
  * Dbs and XML wrapper for table TblFmncQFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFILLIST_H
#define FMNCQFILLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFilList: record of TblFmncQFilList
  */
class FmncQFilList {

public:
	FmncQFilList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Filename;
	uint refIxVTbl;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	ubigint refUref;
	string stubRefUref;
	string osrefKContent;
	string titOsrefKContent;
	string srefKMimetype;
	string titSrefKMimetype;
	usmallint Size;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQFilList: recordset of TblFmncQFilList
  */
class ListFmncQFilList {

public:
	ListFmncQFilList();
	ListFmncQFilList(const ListFmncQFilList& src);
	~ListFmncQFilList();

	void clear();
	unsigned int size() const;
	void append(FmncQFilList* rec);

	ListFmncQFilList& operator=(const ListFmncQFilList& src);

public:
	vector<FmncQFilList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFilList: C++ wrapper for table TblFmncQFilList
  */
class TblFmncQFilList {

public:
	TblFmncQFilList();
	virtual ~TblFmncQFilList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFilList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilList& rst);

	virtual void insertRec(FmncQFilList* rec);
	ubigint insertNewRec(FmncQFilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);
	ubigint appendNewRecToRst(ListFmncQFilList& rst, FmncQFilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);
	virtual void insertRst(ListFmncQFilList& rst);
	virtual void updateRec(FmncQFilList* rec);
	virtual void updateRst(ListFmncQFilList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFilList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFilList: C++ wrapper for table TblFmncQFilList (MySQL database)
  */
class MyTblFmncQFilList : public TblFmncQFilList, public MyTable {

public:
	MyTblFmncQFilList();
	~MyTblFmncQFilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilList& rst);

	void insertRec(FmncQFilList* rec);
	void insertRst(ListFmncQFilList& rst);
	void updateRec(FmncQFilList* rec);
	void updateRst(ListFmncQFilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFilList: C++ wrapper for table TblFmncQFilList (PgSQL database)
  */
class PgTblFmncQFilList : public TblFmncQFilList, public PgTable {

public:
	PgTblFmncQFilList();
	~PgTblFmncQFilList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFilList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFilList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFilList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFilList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilList& rst);

	void insertRec(FmncQFilList* rec);
	void insertRst(ListFmncQFilList& rst);
	void updateRec(FmncQFilList* rec);
	void updateRst(ListFmncQFilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilList& rst);
};
// IP pgTbl --- END

#endif

