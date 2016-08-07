/**
  * \file FmncQFab1NFabproject.h
  * Dbs and XML wrapper for table TblFmncQFab1NFabproject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFAB1NFABPROJECT_H
#define FMNCQFAB1NFABPROJECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFab1NFabproject: record of TblFmncQFab1NFabproject
  */
class FmncQFab1NFabproject {

public:
	FmncQFab1NFabproject(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQFab1NFabproject: recordset of TblFmncQFab1NFabproject
  */
class ListFmncQFab1NFabproject {

public:
	ListFmncQFab1NFabproject();
	ListFmncQFab1NFabproject(const ListFmncQFab1NFabproject& src);
	~ListFmncQFab1NFabproject();

	void clear();
	unsigned int size() const;
	void append(FmncQFab1NFabproject* rec);

	ListFmncQFab1NFabproject& operator=(const ListFmncQFab1NFabproject& src);

public:
	vector<FmncQFab1NFabproject*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFab1NFabproject: C++ wrapper for table TblFmncQFab1NFabproject
  */
class TblFmncQFab1NFabproject {

public:
	TblFmncQFab1NFabproject();
	virtual ~TblFmncQFab1NFabproject();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFab1NFabproject** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFab1NFabproject& rst);

	virtual void insertRec(FmncQFab1NFabproject* rec);
	ubigint insertNewRec(FmncQFab1NFabproject** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQFab1NFabproject& rst, FmncQFab1NFabproject** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQFab1NFabproject& rst);
	virtual void updateRec(FmncQFab1NFabproject* rec);
	virtual void updateRst(ListFmncQFab1NFabproject& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFab1NFabproject** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFab1NFabproject& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFab1NFabproject: C++ wrapper for table TblFmncQFab1NFabproject (MySQL database)
  */
class MyTblFmncQFab1NFabproject : public TblFmncQFab1NFabproject, public MyTable {

public:
	MyTblFmncQFab1NFabproject();
	~MyTblFmncQFab1NFabproject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFab1NFabproject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFab1NFabproject& rst);

	void insertRec(FmncQFab1NFabproject* rec);
	void insertRst(ListFmncQFab1NFabproject& rst);
	void updateRec(FmncQFab1NFabproject* rec);
	void updateRst(ListFmncQFab1NFabproject& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFab1NFabproject** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFab1NFabproject& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFab1NFabproject: C++ wrapper for table TblFmncQFab1NFabproject (PgSQL database)
  */
class PgTblFmncQFab1NFabproject : public TblFmncQFab1NFabproject, public PgTable {

public:
	PgTblFmncQFab1NFabproject();
	~PgTblFmncQFab1NFabproject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFab1NFabproject** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFab1NFabproject& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFab1NFabproject** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFab1NFabproject& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFab1NFabproject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFab1NFabproject& rst);

	void insertRec(FmncQFab1NFabproject* rec);
	void insertRst(ListFmncQFab1NFabproject& rst);
	void updateRec(FmncQFab1NFabproject* rec);
	void updateRst(ListFmncQFab1NFabproject& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFab1NFabproject** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFab1NFabproject& rst);
};
// IP pgTbl --- END

#endif

