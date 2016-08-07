/**
  * \file FmncQOrgBio1NFabproject.h
  * Dbs and XML wrapper for table TblFmncQOrgBio1NFabproject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGBIO1NFABPROJECT_H
#define FMNCQORGBIO1NFABPROJECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgBio1NFabproject: record of TblFmncQOrgBio1NFabproject
  */
class FmncQOrgBio1NFabproject {

public:
	FmncQOrgBio1NFabproject(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQOrgBio1NFabproject: recordset of TblFmncQOrgBio1NFabproject
  */
class ListFmncQOrgBio1NFabproject {

public:
	ListFmncQOrgBio1NFabproject();
	ListFmncQOrgBio1NFabproject(const ListFmncQOrgBio1NFabproject& src);
	~ListFmncQOrgBio1NFabproject();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgBio1NFabproject* rec);

	ListFmncQOrgBio1NFabproject& operator=(const ListFmncQOrgBio1NFabproject& src);

public:
	vector<FmncQOrgBio1NFabproject*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgBio1NFabproject: C++ wrapper for table TblFmncQOrgBio1NFabproject
  */
class TblFmncQOrgBio1NFabproject {

public:
	TblFmncQOrgBio1NFabproject();
	virtual ~TblFmncQOrgBio1NFabproject();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgBio1NFabproject** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgBio1NFabproject& rst);

	virtual void insertRec(FmncQOrgBio1NFabproject* rec);
	ubigint insertNewRec(FmncQOrgBio1NFabproject** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQOrgBio1NFabproject& rst, FmncQOrgBio1NFabproject** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQOrgBio1NFabproject& rst);
	virtual void updateRec(FmncQOrgBio1NFabproject* rec);
	virtual void updateRst(ListFmncQOrgBio1NFabproject& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgBio1NFabproject** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgBio1NFabproject& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgBio1NFabproject: C++ wrapper for table TblFmncQOrgBio1NFabproject (MySQL database)
  */
class MyTblFmncQOrgBio1NFabproject : public TblFmncQOrgBio1NFabproject, public MyTable {

public:
	MyTblFmncQOrgBio1NFabproject();
	~MyTblFmncQOrgBio1NFabproject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgBio1NFabproject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgBio1NFabproject& rst);

	void insertRec(FmncQOrgBio1NFabproject* rec);
	void insertRst(ListFmncQOrgBio1NFabproject& rst);
	void updateRec(FmncQOrgBio1NFabproject* rec);
	void updateRst(ListFmncQOrgBio1NFabproject& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgBio1NFabproject** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgBio1NFabproject& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgBio1NFabproject: C++ wrapper for table TblFmncQOrgBio1NFabproject (PgSQL database)
  */
class PgTblFmncQOrgBio1NFabproject : public TblFmncQOrgBio1NFabproject, public PgTable {

public:
	PgTblFmncQOrgBio1NFabproject();
	~PgTblFmncQOrgBio1NFabproject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgBio1NFabproject** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgBio1NFabproject& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgBio1NFabproject** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgBio1NFabproject& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgBio1NFabproject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgBio1NFabproject& rst);

	void insertRec(FmncQOrgBio1NFabproject* rec);
	void insertRst(ListFmncQOrgBio1NFabproject& rst);
	void updateRec(FmncQOrgBio1NFabproject* rec);
	void updateRst(ListFmncQOrgBio1NFabproject& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgBio1NFabproject** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgBio1NFabproject& rst);
};
// IP pgTbl --- END

#endif

