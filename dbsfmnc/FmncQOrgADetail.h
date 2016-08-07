/**
  * \file FmncQOrgADetail.h
  * Dbs and XML wrapper for table TblFmncQOrgADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGADETAIL_H
#define FMNCQORGADETAIL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgADetail: record of TblFmncQOrgADetail
  */
class FmncQOrgADetail {

public:
	FmncQOrgADetail(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");

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
  * ListFmncQOrgADetail: recordset of TblFmncQOrgADetail
  */
class ListFmncQOrgADetail {

public:
	ListFmncQOrgADetail();
	ListFmncQOrgADetail(const ListFmncQOrgADetail& src);
	~ListFmncQOrgADetail();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgADetail* rec);

	ListFmncQOrgADetail& operator=(const ListFmncQOrgADetail& src);

public:
	vector<FmncQOrgADetail*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgADetail: C++ wrapper for table TblFmncQOrgADetail
  */
class TblFmncQOrgADetail {

public:
	TblFmncQOrgADetail();
	virtual ~TblFmncQOrgADetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgADetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgADetail& rst);

	virtual void insertRec(FmncQOrgADetail* rec);
	ubigint insertNewRec(FmncQOrgADetail** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListFmncQOrgADetail& rst, FmncQOrgADetail** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");
	virtual void insertRst(ListFmncQOrgADetail& rst);
	virtual void updateRec(FmncQOrgADetail* rec);
	virtual void updateRst(ListFmncQOrgADetail& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgADetail** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgADetail& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgADetail: C++ wrapper for table TblFmncQOrgADetail (MySQL database)
  */
class MyTblFmncQOrgADetail : public TblFmncQOrgADetail, public MyTable {

public:
	MyTblFmncQOrgADetail();
	~MyTblFmncQOrgADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgADetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgADetail& rst);

	void insertRec(FmncQOrgADetail* rec);
	void insertRst(ListFmncQOrgADetail& rst);
	void updateRec(FmncQOrgADetail* rec);
	void updateRst(ListFmncQOrgADetail& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgADetail** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgADetail& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgADetail: C++ wrapper for table TblFmncQOrgADetail (PgSQL database)
  */
class PgTblFmncQOrgADetail : public TblFmncQOrgADetail, public PgTable {

public:
	PgTblFmncQOrgADetail();
	~PgTblFmncQOrgADetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgADetail** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgADetail& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgADetail** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgADetail& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgADetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgADetail& rst);

	void insertRec(FmncQOrgADetail* rec);
	void insertRst(ListFmncQOrgADetail& rst);
	void updateRec(FmncQOrgADetail* rec);
	void updateRst(ListFmncQOrgADetail& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgADetail** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgADetail& rst);
};
// IP pgTbl --- END

#endif

