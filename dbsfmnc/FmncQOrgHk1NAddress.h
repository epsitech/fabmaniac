/**
  * \file FmncQOrgHk1NAddress.h
  * Dbs and XML wrapper for table TblFmncQOrgHk1NAddress (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGHK1NADDRESS_H
#define FMNCQORGHK1NADDRESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgHk1NAddress: record of TblFmncQOrgHk1NAddress
  */
class FmncQOrgHk1NAddress {

public:
	FmncQOrgHk1NAddress(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQOrgHk1NAddress: recordset of TblFmncQOrgHk1NAddress
  */
class ListFmncQOrgHk1NAddress {

public:
	ListFmncQOrgHk1NAddress();
	ListFmncQOrgHk1NAddress(const ListFmncQOrgHk1NAddress& src);
	~ListFmncQOrgHk1NAddress();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgHk1NAddress* rec);

	ListFmncQOrgHk1NAddress& operator=(const ListFmncQOrgHk1NAddress& src);

public:
	vector<FmncQOrgHk1NAddress*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgHk1NAddress: C++ wrapper for table TblFmncQOrgHk1NAddress
  */
class TblFmncQOrgHk1NAddress {

public:
	TblFmncQOrgHk1NAddress();
	virtual ~TblFmncQOrgHk1NAddress();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgHk1NAddress** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgHk1NAddress& rst);

	virtual void insertRec(FmncQOrgHk1NAddress* rec);
	ubigint insertNewRec(FmncQOrgHk1NAddress** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQOrgHk1NAddress& rst, FmncQOrgHk1NAddress** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQOrgHk1NAddress& rst);
	virtual void updateRec(FmncQOrgHk1NAddress* rec);
	virtual void updateRst(ListFmncQOrgHk1NAddress& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgHk1NAddress** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgHk1NAddress& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgHk1NAddress: C++ wrapper for table TblFmncQOrgHk1NAddress (MySQL database)
  */
class MyTblFmncQOrgHk1NAddress : public TblFmncQOrgHk1NAddress, public MyTable {

public:
	MyTblFmncQOrgHk1NAddress();
	~MyTblFmncQOrgHk1NAddress();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgHk1NAddress** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgHk1NAddress& rst);

	void insertRec(FmncQOrgHk1NAddress* rec);
	void insertRst(ListFmncQOrgHk1NAddress& rst);
	void updateRec(FmncQOrgHk1NAddress* rec);
	void updateRst(ListFmncQOrgHk1NAddress& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgHk1NAddress** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgHk1NAddress& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgHk1NAddress: C++ wrapper for table TblFmncQOrgHk1NAddress (PgSQL database)
  */
class PgTblFmncQOrgHk1NAddress : public TblFmncQOrgHk1NAddress, public PgTable {

public:
	PgTblFmncQOrgHk1NAddress();
	~PgTblFmncQOrgHk1NAddress();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgHk1NAddress** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgHk1NAddress& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgHk1NAddress** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgHk1NAddress& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgHk1NAddress** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgHk1NAddress& rst);

	void insertRec(FmncQOrgHk1NAddress* rec);
	void insertRst(ListFmncQOrgHk1NAddress& rst);
	void updateRec(FmncQOrgHk1NAddress* rec);
	void updateRst(ListFmncQOrgHk1NAddress& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgHk1NAddress** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgHk1NAddress& rst);
};
// IP pgTbl --- END

#endif

