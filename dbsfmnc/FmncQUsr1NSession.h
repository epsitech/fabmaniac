/**
  * \file FmncQUsr1NSession.h
  * Dbs and XML wrapper for table TblFmncQUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSR1NSESSION_H
#define FMNCQUSR1NSESSION_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsr1NSession: record of TblFmncQUsr1NSession
  */
class FmncQUsr1NSession {

public:
	FmncQUsr1NSession(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQUsr1NSession: recordset of TblFmncQUsr1NSession
  */
class ListFmncQUsr1NSession {

public:
	ListFmncQUsr1NSession();
	ListFmncQUsr1NSession(const ListFmncQUsr1NSession& src);
	~ListFmncQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(FmncQUsr1NSession* rec);

	ListFmncQUsr1NSession& operator=(const ListFmncQUsr1NSession& src);

public:
	vector<FmncQUsr1NSession*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQUsr1NSession: C++ wrapper for table TblFmncQUsr1NSession
  */
class TblFmncQUsr1NSession {

public:
	TblFmncQUsr1NSession();
	virtual ~TblFmncQUsr1NSession();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQUsr1NSession** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsr1NSession& rst);

	virtual void insertRec(FmncQUsr1NSession* rec);
	ubigint insertNewRec(FmncQUsr1NSession** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQUsr1NSession& rst, FmncQUsr1NSession** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQUsr1NSession& rst);
	virtual void updateRec(FmncQUsr1NSession* rec);
	virtual void updateRst(ListFmncQUsr1NSession& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQUsr1NSession** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsr1NSession& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQUsr1NSession: C++ wrapper for table TblFmncQUsr1NSession (MySQL database)
  */
class MyTblFmncQUsr1NSession : public TblFmncQUsr1NSession, public MyTable {

public:
	MyTblFmncQUsr1NSession();
	~MyTblFmncQUsr1NSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsr1NSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsr1NSession& rst);

	void insertRec(FmncQUsr1NSession* rec);
	void insertRst(ListFmncQUsr1NSession& rst);
	void updateRec(FmncQUsr1NSession* rec);
	void updateRst(ListFmncQUsr1NSession& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsr1NSession** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsr1NSession& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQUsr1NSession: C++ wrapper for table TblFmncQUsr1NSession (PgSQL database)
  */
class PgTblFmncQUsr1NSession : public TblFmncQUsr1NSession, public PgTable {

public:
	PgTblFmncQUsr1NSession();
	~PgTblFmncQUsr1NSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQUsr1NSession** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQUsr1NSession& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQUsr1NSession** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQUsr1NSession& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsr1NSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsr1NSession& rst);

	void insertRec(FmncQUsr1NSession* rec);
	void insertRst(ListFmncQUsr1NSession& rst);
	void updateRec(FmncQUsr1NSession* rec);
	void updateRst(ListFmncQUsr1NSession& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsr1NSession** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsr1NSession& rst);
};
// IP pgTbl --- END

#endif

