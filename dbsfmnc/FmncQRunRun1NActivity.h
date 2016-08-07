/**
  * \file FmncQRunRun1NActivity.h
  * Dbs and XML wrapper for table TblFmncQRunRun1NActivity (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNRUN1NACTIVITY_H
#define FMNCQRUNRUN1NACTIVITY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunRun1NActivity: record of TblFmncQRunRun1NActivity
  */
class FmncQRunRun1NActivity {

public:
	FmncQRunRun1NActivity(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint runNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint runNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQRunRun1NActivity: recordset of TblFmncQRunRun1NActivity
  */
class ListFmncQRunRun1NActivity {

public:
	ListFmncQRunRun1NActivity();
	ListFmncQRunRun1NActivity(const ListFmncQRunRun1NActivity& src);
	~ListFmncQRunRun1NActivity();

	void clear();
	unsigned int size() const;
	void append(FmncQRunRun1NActivity* rec);

	ListFmncQRunRun1NActivity& operator=(const ListFmncQRunRun1NActivity& src);

public:
	vector<FmncQRunRun1NActivity*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQRunRun1NActivity: C++ wrapper for table TblFmncQRunRun1NActivity
  */
class TblFmncQRunRun1NActivity {

public:
	TblFmncQRunRun1NActivity();
	virtual ~TblFmncQRunRun1NActivity();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQRunRun1NActivity** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunRun1NActivity& rst);

	virtual void insertRec(FmncQRunRun1NActivity* rec);
	ubigint insertNewRec(FmncQRunRun1NActivity** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint runNum = 0);
	ubigint appendNewRecToRst(ListFmncQRunRun1NActivity& rst, FmncQRunRun1NActivity** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint runNum = 0);
	virtual void insertRst(ListFmncQRunRun1NActivity& rst);
	virtual void updateRec(FmncQRunRun1NActivity* rec);
	virtual void updateRst(ListFmncQRunRun1NActivity& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQRunRun1NActivity** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunRun1NActivity& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQRunRun1NActivity: C++ wrapper for table TblFmncQRunRun1NActivity (MySQL database)
  */
class MyTblFmncQRunRun1NActivity : public TblFmncQRunRun1NActivity, public MyTable {

public:
	MyTblFmncQRunRun1NActivity();
	~MyTblFmncQRunRun1NActivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunRun1NActivity** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunRun1NActivity& rst);

	void insertRec(FmncQRunRun1NActivity* rec);
	void insertRst(ListFmncQRunRun1NActivity& rst);
	void updateRec(FmncQRunRun1NActivity* rec);
	void updateRst(ListFmncQRunRun1NActivity& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunRun1NActivity** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunRun1NActivity& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQRunRun1NActivity: C++ wrapper for table TblFmncQRunRun1NActivity (PgSQL database)
  */
class PgTblFmncQRunRun1NActivity : public TblFmncQRunRun1NActivity, public PgTable {

public:
	PgTblFmncQRunRun1NActivity();
	~PgTblFmncQRunRun1NActivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQRunRun1NActivity** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQRunRun1NActivity& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQRunRun1NActivity** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQRunRun1NActivity& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunRun1NActivity** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunRun1NActivity& rst);

	void insertRec(FmncQRunRun1NActivity* rec);
	void insertRst(ListFmncQRunRun1NActivity& rst);
	void updateRec(FmncQRunRun1NActivity* rec);
	void updateRst(ListFmncQRunRun1NActivity& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunRun1NActivity** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunRun1NActivity& rst);
};
// IP pgTbl --- END

#endif

