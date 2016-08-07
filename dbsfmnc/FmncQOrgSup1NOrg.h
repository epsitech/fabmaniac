/**
  * \file FmncQOrgSup1NOrg.h
  * Dbs and XML wrapper for table TblFmncQOrgSup1NOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGSUP1NORG_H
#define FMNCQORGSUP1NORG_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgSup1NOrg: record of TblFmncQOrgSup1NOrg
  */
class FmncQOrgSup1NOrg {

public:
	FmncQOrgSup1NOrg(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQOrgSup1NOrg: recordset of TblFmncQOrgSup1NOrg
  */
class ListFmncQOrgSup1NOrg {

public:
	ListFmncQOrgSup1NOrg();
	ListFmncQOrgSup1NOrg(const ListFmncQOrgSup1NOrg& src);
	~ListFmncQOrgSup1NOrg();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgSup1NOrg* rec);

	ListFmncQOrgSup1NOrg& operator=(const ListFmncQOrgSup1NOrg& src);

public:
	vector<FmncQOrgSup1NOrg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgSup1NOrg: C++ wrapper for table TblFmncQOrgSup1NOrg
  */
class TblFmncQOrgSup1NOrg {

public:
	TblFmncQOrgSup1NOrg();
	virtual ~TblFmncQOrgSup1NOrg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgSup1NOrg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSup1NOrg& rst);

	virtual void insertRec(FmncQOrgSup1NOrg* rec);
	ubigint insertNewRec(FmncQOrgSup1NOrg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQOrgSup1NOrg& rst, FmncQOrgSup1NOrg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQOrgSup1NOrg& rst);
	virtual void updateRec(FmncQOrgSup1NOrg* rec);
	virtual void updateRst(ListFmncQOrgSup1NOrg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgSup1NOrg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSup1NOrg& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgSup1NOrg: C++ wrapper for table TblFmncQOrgSup1NOrg (MySQL database)
  */
class MyTblFmncQOrgSup1NOrg : public TblFmncQOrgSup1NOrg, public MyTable {

public:
	MyTblFmncQOrgSup1NOrg();
	~MyTblFmncQOrgSup1NOrg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgSup1NOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSup1NOrg& rst);

	void insertRec(FmncQOrgSup1NOrg* rec);
	void insertRst(ListFmncQOrgSup1NOrg& rst);
	void updateRec(FmncQOrgSup1NOrg* rec);
	void updateRst(ListFmncQOrgSup1NOrg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgSup1NOrg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSup1NOrg& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgSup1NOrg: C++ wrapper for table TblFmncQOrgSup1NOrg (PgSQL database)
  */
class PgTblFmncQOrgSup1NOrg : public TblFmncQOrgSup1NOrg, public PgTable {

public:
	PgTblFmncQOrgSup1NOrg();
	~PgTblFmncQOrgSup1NOrg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgSup1NOrg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgSup1NOrg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgSup1NOrg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgSup1NOrg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgSup1NOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSup1NOrg& rst);

	void insertRec(FmncQOrgSup1NOrg* rec);
	void insertRst(ListFmncQOrgSup1NOrg& rst);
	void updateRec(FmncQOrgSup1NOrg* rec);
	void updateRst(ListFmncQOrgSup1NOrg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgSup1NOrg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSup1NOrg& rst);
};
// IP pgTbl --- END

#endif

