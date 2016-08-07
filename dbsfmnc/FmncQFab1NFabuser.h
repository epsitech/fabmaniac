/**
  * \file FmncQFab1NFabuser.h
  * Dbs and XML wrapper for table TblFmncQFab1NFabuser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFAB1NFABUSER_H
#define FMNCQFAB1NFABUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFab1NFabuser: record of TblFmncQFab1NFabuser
  */
class FmncQFab1NFabuser {

public:
	FmncQFab1NFabuser(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQFab1NFabuser: recordset of TblFmncQFab1NFabuser
  */
class ListFmncQFab1NFabuser {

public:
	ListFmncQFab1NFabuser();
	ListFmncQFab1NFabuser(const ListFmncQFab1NFabuser& src);
	~ListFmncQFab1NFabuser();

	void clear();
	unsigned int size() const;
	void append(FmncQFab1NFabuser* rec);

	ListFmncQFab1NFabuser& operator=(const ListFmncQFab1NFabuser& src);

public:
	vector<FmncQFab1NFabuser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFab1NFabuser: C++ wrapper for table TblFmncQFab1NFabuser
  */
class TblFmncQFab1NFabuser {

public:
	TblFmncQFab1NFabuser();
	virtual ~TblFmncQFab1NFabuser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFab1NFabuser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFab1NFabuser& rst);

	virtual void insertRec(FmncQFab1NFabuser* rec);
	ubigint insertNewRec(FmncQFab1NFabuser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQFab1NFabuser& rst, FmncQFab1NFabuser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQFab1NFabuser& rst);
	virtual void updateRec(FmncQFab1NFabuser* rec);
	virtual void updateRst(ListFmncQFab1NFabuser& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFab1NFabuser** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFab1NFabuser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFab1NFabuser: C++ wrapper for table TblFmncQFab1NFabuser (MySQL database)
  */
class MyTblFmncQFab1NFabuser : public TblFmncQFab1NFabuser, public MyTable {

public:
	MyTblFmncQFab1NFabuser();
	~MyTblFmncQFab1NFabuser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFab1NFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFab1NFabuser& rst);

	void insertRec(FmncQFab1NFabuser* rec);
	void insertRst(ListFmncQFab1NFabuser& rst);
	void updateRec(FmncQFab1NFabuser* rec);
	void updateRst(ListFmncQFab1NFabuser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFab1NFabuser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFab1NFabuser& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFab1NFabuser: C++ wrapper for table TblFmncQFab1NFabuser (PgSQL database)
  */
class PgTblFmncQFab1NFabuser : public TblFmncQFab1NFabuser, public PgTable {

public:
	PgTblFmncQFab1NFabuser();
	~PgTblFmncQFab1NFabuser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFab1NFabuser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFab1NFabuser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFab1NFabuser** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFab1NFabuser& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFab1NFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFab1NFabuser& rst);

	void insertRec(FmncQFab1NFabuser* rec);
	void insertRst(ListFmncQFab1NFabuser& rst);
	void updateRec(FmncQFab1NFabuser* rec);
	void updateRst(ListFmncQFab1NFabuser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFab1NFabuser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFab1NFabuser& rst);
};
// IP pgTbl --- END

#endif

