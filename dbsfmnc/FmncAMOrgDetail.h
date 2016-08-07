/**
  * \file FmncAMOrgDetail.h
  * database access for table TblFmncAMOrgDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMORGDETAIL_H
#define FMNCAMORGDETAIL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMOrgDetail: record of TblFmncAMOrgDetail
  */
class FmncAMOrgDetail {

public:
	FmncAMOrgDetail(const ubigint ref = 0, const ubigint refFmncMOrg = 0, const string x1SrefKType = "", const string Val = "");

public:
	ubigint ref;
	ubigint refFmncMOrg;
	string x1SrefKType;
	string Val;

public:
	bool operator==(const FmncAMOrgDetail& comp);
	bool operator!=(const FmncAMOrgDetail& comp);
};

/**
  * ListFmncAMOrgDetail: recordset of TblFmncAMOrgDetail
  */
class ListFmncAMOrgDetail {

public:
	ListFmncAMOrgDetail();
	ListFmncAMOrgDetail(const ListFmncAMOrgDetail& src);
	~ListFmncAMOrgDetail();

	void clear();
	unsigned int size() const;
	void append(FmncAMOrgDetail* rec);

	FmncAMOrgDetail* operator[](const uint ix);
	ListFmncAMOrgDetail& operator=(const ListFmncAMOrgDetail& src);
	bool operator==(const ListFmncAMOrgDetail& comp);
	bool operator!=(const ListFmncAMOrgDetail& comp);

public:
	vector<FmncAMOrgDetail*> nodes;
};

/**
  * TblFmncAMOrgDetail: C++ wrapper for table TblFmncAMOrgDetail
  */
class TblFmncAMOrgDetail {

public:
	TblFmncAMOrgDetail();
	virtual ~TblFmncAMOrgDetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMOrgDetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMOrgDetail& rst);

	virtual void insertRec(FmncAMOrgDetail* rec);
	ubigint insertNewRec(FmncAMOrgDetail** rec = NULL, const ubigint refFmncMOrg = 0, const string x1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListFmncAMOrgDetail& rst, FmncAMOrgDetail** rec = NULL, const ubigint refFmncMOrg = 0, const string x1SrefKType = "", const string Val = "");
	virtual void insertRst(ListFmncAMOrgDetail& rst, bool transact = false);
	virtual void updateRec(FmncAMOrgDetail* rec);
	virtual void updateRst(ListFmncAMOrgDetail& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMOrgDetail** rec);
	virtual bool loadRecByOrgTyp(ubigint refFmncMOrg, string x1SrefKType, FmncAMOrgDetail** rec);
	virtual ubigint loadRefsByOrg(ubigint refFmncMOrg, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMOrgDetail& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMOrgDetail: C++ wrapper for table TblFmncAMOrgDetail (MySQL database)
  */
class MyTblFmncAMOrgDetail : public TblFmncAMOrgDetail, public MyTable {

public:
	MyTblFmncAMOrgDetail();
	~MyTblFmncAMOrgDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMOrgDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMOrgDetail& rst);

	void insertRec(FmncAMOrgDetail* rec);
	void insertRst(ListFmncAMOrgDetail& rst, bool transact = false);
	void updateRec(FmncAMOrgDetail* rec);
	void updateRst(ListFmncAMOrgDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMOrgDetail** rec);
	bool loadRecByOrgTyp(ubigint refFmncMOrg, string x1SrefKType, FmncAMOrgDetail** rec);
	ubigint loadRefsByOrg(ubigint refFmncMOrg, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMOrgDetail: C++ wrapper for table TblFmncAMOrgDetail (PgSQL database)
  */
class PgTblFmncAMOrgDetail : public TblFmncAMOrgDetail, public PgTable {

public:
	PgTblFmncAMOrgDetail();
	~PgTblFmncAMOrgDetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMOrgDetail** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMOrgDetail& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMOrgDetail** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMOrgDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMOrgDetail& rst);

	void insertRec(FmncAMOrgDetail* rec);
	void insertRst(ListFmncAMOrgDetail& rst, bool transact = false);
	void updateRec(FmncAMOrgDetail* rec);
	void updateRst(ListFmncAMOrgDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMOrgDetail** rec);
	bool loadRecByOrgTyp(ubigint refFmncMOrg, string x1SrefKType, FmncAMOrgDetail** rec);
	ubigint loadRefsByOrg(ubigint refFmncMOrg, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

