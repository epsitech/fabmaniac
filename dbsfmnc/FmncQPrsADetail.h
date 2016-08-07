/**
  * \file FmncQPrsADetail.h
  * Dbs and XML wrapper for table TblFmncQPrsADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSADETAIL_H
#define FMNCQPRSADETAIL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsADetail: record of TblFmncQPrsADetail
  */
class FmncQPrsADetail {

public:
	FmncQPrsADetail(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x1SrefKType;
	string titX1SrefKType;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPrsADetail: recordset of TblFmncQPrsADetail
  */
class ListFmncQPrsADetail {

public:
	ListFmncQPrsADetail();
	ListFmncQPrsADetail(const ListFmncQPrsADetail& src);
	~ListFmncQPrsADetail();

	void clear();
	unsigned int size() const;
	void append(FmncQPrsADetail* rec);

	ListFmncQPrsADetail& operator=(const ListFmncQPrsADetail& src);

public:
	vector<FmncQPrsADetail*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPrsADetail: C++ wrapper for table TblFmncQPrsADetail
  */
class TblFmncQPrsADetail {

public:
	TblFmncQPrsADetail();
	virtual ~TblFmncQPrsADetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPrsADetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsADetail& rst);

	virtual void insertRec(FmncQPrsADetail* rec);
	ubigint insertNewRec(FmncQPrsADetail** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListFmncQPrsADetail& rst, FmncQPrsADetail** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");
	virtual void insertRst(ListFmncQPrsADetail& rst);
	virtual void updateRec(FmncQPrsADetail* rec);
	virtual void updateRst(ListFmncQPrsADetail& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPrsADetail** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsADetail& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPrsADetail: C++ wrapper for table TblFmncQPrsADetail (MySQL database)
  */
class MyTblFmncQPrsADetail : public TblFmncQPrsADetail, public MyTable {

public:
	MyTblFmncQPrsADetail();
	~MyTblFmncQPrsADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsADetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsADetail& rst);

	void insertRec(FmncQPrsADetail* rec);
	void insertRst(ListFmncQPrsADetail& rst);
	void updateRec(FmncQPrsADetail* rec);
	void updateRst(ListFmncQPrsADetail& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsADetail** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsADetail& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPrsADetail: C++ wrapper for table TblFmncQPrsADetail (PgSQL database)
  */
class PgTblFmncQPrsADetail : public TblFmncQPrsADetail, public PgTable {

public:
	PgTblFmncQPrsADetail();
	~PgTblFmncQPrsADetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPrsADetail** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPrsADetail& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPrsADetail** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPrsADetail& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsADetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsADetail& rst);

	void insertRec(FmncQPrsADetail* rec);
	void insertRst(ListFmncQPrsADetail& rst);
	void updateRec(FmncQPrsADetail* rec);
	void updateRst(ListFmncQPrsADetail& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsADetail** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsADetail& rst);
};
// IP pgTbl --- END

#endif

