/**
  * \file FmncQOrgPco1NPurchorder.h
  * Dbs and XML wrapper for table TblFmncQOrgPco1NPurchorder (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGPCO1NPURCHORDER_H
#define FMNCQORGPCO1NPURCHORDER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgPco1NPurchorder: record of TblFmncQOrgPco1NPurchorder
  */
class FmncQOrgPco1NPurchorder {

public:
	FmncQOrgPco1NPurchorder(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQOrgPco1NPurchorder: recordset of TblFmncQOrgPco1NPurchorder
  */
class ListFmncQOrgPco1NPurchorder {

public:
	ListFmncQOrgPco1NPurchorder();
	ListFmncQOrgPco1NPurchorder(const ListFmncQOrgPco1NPurchorder& src);
	~ListFmncQOrgPco1NPurchorder();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgPco1NPurchorder* rec);

	ListFmncQOrgPco1NPurchorder& operator=(const ListFmncQOrgPco1NPurchorder& src);

public:
	vector<FmncQOrgPco1NPurchorder*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgPco1NPurchorder: C++ wrapper for table TblFmncQOrgPco1NPurchorder
  */
class TblFmncQOrgPco1NPurchorder {

public:
	TblFmncQOrgPco1NPurchorder();
	virtual ~TblFmncQOrgPco1NPurchorder();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgPco1NPurchorder** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgPco1NPurchorder& rst);

	virtual void insertRec(FmncQOrgPco1NPurchorder* rec);
	ubigint insertNewRec(FmncQOrgPco1NPurchorder** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQOrgPco1NPurchorder& rst, FmncQOrgPco1NPurchorder** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQOrgPco1NPurchorder& rst);
	virtual void updateRec(FmncQOrgPco1NPurchorder* rec);
	virtual void updateRst(ListFmncQOrgPco1NPurchorder& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgPco1NPurchorder** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgPco1NPurchorder& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgPco1NPurchorder: C++ wrapper for table TblFmncQOrgPco1NPurchorder (MySQL database)
  */
class MyTblFmncQOrgPco1NPurchorder : public TblFmncQOrgPco1NPurchorder, public MyTable {

public:
	MyTblFmncQOrgPco1NPurchorder();
	~MyTblFmncQOrgPco1NPurchorder();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgPco1NPurchorder** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgPco1NPurchorder& rst);

	void insertRec(FmncQOrgPco1NPurchorder* rec);
	void insertRst(ListFmncQOrgPco1NPurchorder& rst);
	void updateRec(FmncQOrgPco1NPurchorder* rec);
	void updateRst(ListFmncQOrgPco1NPurchorder& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgPco1NPurchorder** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgPco1NPurchorder& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgPco1NPurchorder: C++ wrapper for table TblFmncQOrgPco1NPurchorder (PgSQL database)
  */
class PgTblFmncQOrgPco1NPurchorder : public TblFmncQOrgPco1NPurchorder, public PgTable {

public:
	PgTblFmncQOrgPco1NPurchorder();
	~PgTblFmncQOrgPco1NPurchorder();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgPco1NPurchorder** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgPco1NPurchorder& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgPco1NPurchorder** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgPco1NPurchorder& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgPco1NPurchorder** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgPco1NPurchorder& rst);

	void insertRec(FmncQOrgPco1NPurchorder* rec);
	void insertRst(ListFmncQOrgPco1NPurchorder& rst);
	void updateRec(FmncQOrgPco1NPurchorder* rec);
	void updateRst(ListFmncQOrgPco1NPurchorder& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgPco1NPurchorder** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgPco1NPurchorder& rst);
};
// IP pgTbl --- END

#endif

