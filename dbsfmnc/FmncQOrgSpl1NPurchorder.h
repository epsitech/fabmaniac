/**
  * \file FmncQOrgSpl1NPurchorder.h
  * Dbs and XML wrapper for table TblFmncQOrgSpl1NPurchorder (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGSPL1NPURCHORDER_H
#define FMNCQORGSPL1NPURCHORDER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgSpl1NPurchorder: record of TblFmncQOrgSpl1NPurchorder
  */
class FmncQOrgSpl1NPurchorder {

public:
	FmncQOrgSpl1NPurchorder(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQOrgSpl1NPurchorder: recordset of TblFmncQOrgSpl1NPurchorder
  */
class ListFmncQOrgSpl1NPurchorder {

public:
	ListFmncQOrgSpl1NPurchorder();
	ListFmncQOrgSpl1NPurchorder(const ListFmncQOrgSpl1NPurchorder& src);
	~ListFmncQOrgSpl1NPurchorder();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgSpl1NPurchorder* rec);

	ListFmncQOrgSpl1NPurchorder& operator=(const ListFmncQOrgSpl1NPurchorder& src);

public:
	vector<FmncQOrgSpl1NPurchorder*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgSpl1NPurchorder: C++ wrapper for table TblFmncQOrgSpl1NPurchorder
  */
class TblFmncQOrgSpl1NPurchorder {

public:
	TblFmncQOrgSpl1NPurchorder();
	virtual ~TblFmncQOrgSpl1NPurchorder();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgSpl1NPurchorder** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSpl1NPurchorder& rst);

	virtual void insertRec(FmncQOrgSpl1NPurchorder* rec);
	ubigint insertNewRec(FmncQOrgSpl1NPurchorder** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQOrgSpl1NPurchorder& rst, FmncQOrgSpl1NPurchorder** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQOrgSpl1NPurchorder& rst);
	virtual void updateRec(FmncQOrgSpl1NPurchorder* rec);
	virtual void updateRst(ListFmncQOrgSpl1NPurchorder& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgSpl1NPurchorder** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSpl1NPurchorder& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgSpl1NPurchorder: C++ wrapper for table TblFmncQOrgSpl1NPurchorder (MySQL database)
  */
class MyTblFmncQOrgSpl1NPurchorder : public TblFmncQOrgSpl1NPurchorder, public MyTable {

public:
	MyTblFmncQOrgSpl1NPurchorder();
	~MyTblFmncQOrgSpl1NPurchorder();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgSpl1NPurchorder** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSpl1NPurchorder& rst);

	void insertRec(FmncQOrgSpl1NPurchorder* rec);
	void insertRst(ListFmncQOrgSpl1NPurchorder& rst);
	void updateRec(FmncQOrgSpl1NPurchorder* rec);
	void updateRst(ListFmncQOrgSpl1NPurchorder& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgSpl1NPurchorder** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSpl1NPurchorder& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgSpl1NPurchorder: C++ wrapper for table TblFmncQOrgSpl1NPurchorder (PgSQL database)
  */
class PgTblFmncQOrgSpl1NPurchorder : public TblFmncQOrgSpl1NPurchorder, public PgTable {

public:
	PgTblFmncQOrgSpl1NPurchorder();
	~PgTblFmncQOrgSpl1NPurchorder();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgSpl1NPurchorder** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgSpl1NPurchorder& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgSpl1NPurchorder** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgSpl1NPurchorder& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgSpl1NPurchorder** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSpl1NPurchorder& rst);

	void insertRec(FmncQOrgSpl1NPurchorder* rec);
	void insertRst(ListFmncQOrgSpl1NPurchorder& rst);
	void updateRec(FmncQOrgSpl1NPurchorder* rec);
	void updateRst(ListFmncQOrgSpl1NPurchorder& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgSpl1NPurchorder** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSpl1NPurchorder& rst);
};
// IP pgTbl --- END

#endif

