/**
  * \file FmncQUsrList.h
  * Dbs and XML wrapper for table TblFmncQUsrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSRLIST_H
#define FMNCQUSRLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsrList: record of TblFmncQUsrList
  */
class FmncQUsrList {

public:
	FmncQUsrList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMPerson = 0, const string stubRefFmncMPerson = "", const string sref = "", const ubigint refFmncMUsergroup = 0, const string stubRefFmncMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixFmncVLocale = 0, const string srefIxFmncVLocale = "", const string titIxFmncVLocale = "", const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint refFmncMPerson;
	string stubRefFmncMPerson;
	string sref;
	ubigint refFmncMUsergroup;
	string stubRefFmncMUsergroup;
	uint ixVState;
	string srefIxVState;
	string titIxVState;
	uint ixFmncVLocale;
	string srefIxFmncVLocale;
	string titIxFmncVLocale;
	uint ixFmncVUserlevel;
	string srefIxFmncVUserlevel;
	string titIxFmncVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQUsrList: recordset of TblFmncQUsrList
  */
class ListFmncQUsrList {

public:
	ListFmncQUsrList();
	ListFmncQUsrList(const ListFmncQUsrList& src);
	~ListFmncQUsrList();

	void clear();
	unsigned int size() const;
	void append(FmncQUsrList* rec);

	ListFmncQUsrList& operator=(const ListFmncQUsrList& src);

public:
	vector<FmncQUsrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQUsrList: C++ wrapper for table TblFmncQUsrList
  */
class TblFmncQUsrList {

public:
	TblFmncQUsrList();
	virtual ~TblFmncQUsrList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQUsrList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrList& rst);

	virtual void insertRec(FmncQUsrList* rec);
	ubigint insertNewRec(FmncQUsrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMPerson = 0, const string stubRefFmncMPerson = "", const string sref = "", const ubigint refFmncMUsergroup = 0, const string stubRefFmncMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixFmncVLocale = 0, const string srefIxFmncVLocale = "", const string titIxFmncVLocale = "", const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");
	ubigint appendNewRecToRst(ListFmncQUsrList& rst, FmncQUsrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refFmncMPerson = 0, const string stubRefFmncMPerson = "", const string sref = "", const ubigint refFmncMUsergroup = 0, const string stubRefFmncMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixFmncVLocale = 0, const string srefIxFmncVLocale = "", const string titIxFmncVLocale = "", const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");
	virtual void insertRst(ListFmncQUsrList& rst);
	virtual void updateRec(FmncQUsrList* rec);
	virtual void updateRst(ListFmncQUsrList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQUsrList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQUsrList: C++ wrapper for table TblFmncQUsrList (MySQL database)
  */
class MyTblFmncQUsrList : public TblFmncQUsrList, public MyTable {

public:
	MyTblFmncQUsrList();
	~MyTblFmncQUsrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrList& rst);

	void insertRec(FmncQUsrList* rec);
	void insertRst(ListFmncQUsrList& rst);
	void updateRec(FmncQUsrList* rec);
	void updateRst(ListFmncQUsrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQUsrList: C++ wrapper for table TblFmncQUsrList (PgSQL database)
  */
class PgTblFmncQUsrList : public TblFmncQUsrList, public PgTable {

public:
	PgTblFmncQUsrList();
	~PgTblFmncQUsrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQUsrList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQUsrList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQUsrList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQUsrList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrList& rst);

	void insertRec(FmncQUsrList* rec);
	void insertRst(ListFmncQUsrList& rst);
	void updateRec(FmncQUsrList* rec);
	void updateRst(ListFmncQUsrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrList& rst);
};
// IP pgTbl --- END

#endif

