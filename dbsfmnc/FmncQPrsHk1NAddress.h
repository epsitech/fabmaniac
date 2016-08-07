/**
  * \file FmncQPrsHk1NAddress.h
  * Dbs and XML wrapper for table TblFmncQPrsHk1NAddress (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSHK1NADDRESS_H
#define FMNCQPRSHK1NADDRESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsHk1NAddress: record of TblFmncQPrsHk1NAddress
  */
class FmncQPrsHk1NAddress {

public:
	FmncQPrsHk1NAddress(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQPrsHk1NAddress: recordset of TblFmncQPrsHk1NAddress
  */
class ListFmncQPrsHk1NAddress {

public:
	ListFmncQPrsHk1NAddress();
	ListFmncQPrsHk1NAddress(const ListFmncQPrsHk1NAddress& src);
	~ListFmncQPrsHk1NAddress();

	void clear();
	unsigned int size() const;
	void append(FmncQPrsHk1NAddress* rec);

	ListFmncQPrsHk1NAddress& operator=(const ListFmncQPrsHk1NAddress& src);

public:
	vector<FmncQPrsHk1NAddress*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPrsHk1NAddress: C++ wrapper for table TblFmncQPrsHk1NAddress
  */
class TblFmncQPrsHk1NAddress {

public:
	TblFmncQPrsHk1NAddress();
	virtual ~TblFmncQPrsHk1NAddress();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPrsHk1NAddress** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsHk1NAddress& rst);

	virtual void insertRec(FmncQPrsHk1NAddress* rec);
	ubigint insertNewRec(FmncQPrsHk1NAddress** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQPrsHk1NAddress& rst, FmncQPrsHk1NAddress** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQPrsHk1NAddress& rst);
	virtual void updateRec(FmncQPrsHk1NAddress* rec);
	virtual void updateRst(ListFmncQPrsHk1NAddress& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPrsHk1NAddress** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsHk1NAddress& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPrsHk1NAddress: C++ wrapper for table TblFmncQPrsHk1NAddress (MySQL database)
  */
class MyTblFmncQPrsHk1NAddress : public TblFmncQPrsHk1NAddress, public MyTable {

public:
	MyTblFmncQPrsHk1NAddress();
	~MyTblFmncQPrsHk1NAddress();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsHk1NAddress** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsHk1NAddress& rst);

	void insertRec(FmncQPrsHk1NAddress* rec);
	void insertRst(ListFmncQPrsHk1NAddress& rst);
	void updateRec(FmncQPrsHk1NAddress* rec);
	void updateRst(ListFmncQPrsHk1NAddress& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsHk1NAddress** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsHk1NAddress& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPrsHk1NAddress: C++ wrapper for table TblFmncQPrsHk1NAddress (PgSQL database)
  */
class PgTblFmncQPrsHk1NAddress : public TblFmncQPrsHk1NAddress, public PgTable {

public:
	PgTblFmncQPrsHk1NAddress();
	~PgTblFmncQPrsHk1NAddress();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPrsHk1NAddress** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPrsHk1NAddress& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPrsHk1NAddress** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPrsHk1NAddress& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsHk1NAddress** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsHk1NAddress& rst);

	void insertRec(FmncQPrsHk1NAddress* rec);
	void insertRst(ListFmncQPrsHk1NAddress& rst);
	void updateRec(FmncQPrsHk1NAddress* rec);
	void updateRst(ListFmncQPrsHk1NAddress& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsHk1NAddress** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsHk1NAddress& rst);
};
// IP pgTbl --- END

#endif

