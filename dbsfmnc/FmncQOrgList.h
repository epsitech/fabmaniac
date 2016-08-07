/**
  * \file FmncQOrgList.h
  * Dbs and XML wrapper for table TblFmncQOrgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGLIST_H
#define FMNCQORGLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgList: record of TblFmncQOrgList
  */
class FmncQOrgList {

public:
	FmncQOrgList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const uint ixWDerivate = 0, const string srefsIxWDerivate = "", const string titsIxWDerivate = "", const ubigint refFmncMAddress = 0, const string stubRefFmncMAddress = "", const ubigint supRefFmncMOrg = 0, const string stubSupRefFmncMOrg = "", const string Tel = "", const string Eml = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string Title;
	uint ixWDerivate;
	string srefsIxWDerivate;
	string titsIxWDerivate;
	ubigint refFmncMAddress;
	string stubRefFmncMAddress;
	ubigint supRefFmncMOrg;
	string stubSupRefFmncMOrg;
	string Tel;
	string Eml;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQOrgList: recordset of TblFmncQOrgList
  */
class ListFmncQOrgList {

public:
	ListFmncQOrgList();
	ListFmncQOrgList(const ListFmncQOrgList& src);
	~ListFmncQOrgList();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgList* rec);

	ListFmncQOrgList& operator=(const ListFmncQOrgList& src);

public:
	vector<FmncQOrgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgList: C++ wrapper for table TblFmncQOrgList
  */
class TblFmncQOrgList {

public:
	TblFmncQOrgList();
	virtual ~TblFmncQOrgList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgList& rst);

	virtual void insertRec(FmncQOrgList* rec);
	ubigint insertNewRec(FmncQOrgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const uint ixWDerivate = 0, const string srefsIxWDerivate = "", const string titsIxWDerivate = "", const ubigint refFmncMAddress = 0, const string stubRefFmncMAddress = "", const ubigint supRefFmncMOrg = 0, const string stubSupRefFmncMOrg = "", const string Tel = "", const string Eml = "");
	ubigint appendNewRecToRst(ListFmncQOrgList& rst, FmncQOrgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const uint ixWDerivate = 0, const string srefsIxWDerivate = "", const string titsIxWDerivate = "", const ubigint refFmncMAddress = 0, const string stubRefFmncMAddress = "", const ubigint supRefFmncMOrg = 0, const string stubSupRefFmncMOrg = "", const string Tel = "", const string Eml = "");
	virtual void insertRst(ListFmncQOrgList& rst);
	virtual void updateRec(FmncQOrgList* rec);
	virtual void updateRst(ListFmncQOrgList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgList: C++ wrapper for table TblFmncQOrgList (MySQL database)
  */
class MyTblFmncQOrgList : public TblFmncQOrgList, public MyTable {

public:
	MyTblFmncQOrgList();
	~MyTblFmncQOrgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgList& rst);

	void insertRec(FmncQOrgList* rec);
	void insertRst(ListFmncQOrgList& rst);
	void updateRec(FmncQOrgList* rec);
	void updateRst(ListFmncQOrgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgList: C++ wrapper for table TblFmncQOrgList (PgSQL database)
  */
class PgTblFmncQOrgList : public TblFmncQOrgList, public PgTable {

public:
	PgTblFmncQOrgList();
	~PgTblFmncQOrgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgList& rst);

	void insertRec(FmncQOrgList* rec);
	void insertRst(ListFmncQOrgList& rst);
	void updateRec(FmncQOrgList* rec);
	void updateRst(ListFmncQOrgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgList& rst);
};
// IP pgTbl --- END

#endif

