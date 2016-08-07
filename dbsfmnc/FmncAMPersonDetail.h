/**
  * \file FmncAMPersonDetail.h
  * database access for table TblFmncAMPersonDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMPERSONDETAIL_H
#define FMNCAMPERSONDETAIL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMPersonDetail: record of TblFmncAMPersonDetail
  */
class FmncAMPersonDetail {

public:
	FmncAMPersonDetail(const ubigint ref = 0, const ubigint refFmncMPerson = 0, const string x1SrefKType = "", const string Val = "");

public:
	ubigint ref;
	ubigint refFmncMPerson;
	string x1SrefKType;
	string Val;

public:
	bool operator==(const FmncAMPersonDetail& comp);
	bool operator!=(const FmncAMPersonDetail& comp);
};

/**
  * ListFmncAMPersonDetail: recordset of TblFmncAMPersonDetail
  */
class ListFmncAMPersonDetail {

public:
	ListFmncAMPersonDetail();
	ListFmncAMPersonDetail(const ListFmncAMPersonDetail& src);
	~ListFmncAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(FmncAMPersonDetail* rec);

	FmncAMPersonDetail* operator[](const uint ix);
	ListFmncAMPersonDetail& operator=(const ListFmncAMPersonDetail& src);
	bool operator==(const ListFmncAMPersonDetail& comp);
	bool operator!=(const ListFmncAMPersonDetail& comp);

public:
	vector<FmncAMPersonDetail*> nodes;
};

/**
  * TblFmncAMPersonDetail: C++ wrapper for table TblFmncAMPersonDetail
  */
class TblFmncAMPersonDetail {

public:
	TblFmncAMPersonDetail();
	virtual ~TblFmncAMPersonDetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMPersonDetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMPersonDetail& rst);

	virtual void insertRec(FmncAMPersonDetail* rec);
	ubigint insertNewRec(FmncAMPersonDetail** rec = NULL, const ubigint refFmncMPerson = 0, const string x1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListFmncAMPersonDetail& rst, FmncAMPersonDetail** rec = NULL, const ubigint refFmncMPerson = 0, const string x1SrefKType = "", const string Val = "");
	virtual void insertRst(ListFmncAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(FmncAMPersonDetail* rec);
	virtual void updateRst(ListFmncAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMPersonDetail** rec);
	virtual bool loadRecByPrsTyp(ubigint refFmncMPerson, string x1SrefKType, FmncAMPersonDetail** rec);
	virtual ubigint loadRefsByPrs(ubigint refFmncMPerson, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMPersonDetail& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMPersonDetail: C++ wrapper for table TblFmncAMPersonDetail (MySQL database)
  */
class MyTblFmncAMPersonDetail : public TblFmncAMPersonDetail, public MyTable {

public:
	MyTblFmncAMPersonDetail();
	~MyTblFmncAMPersonDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMPersonDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMPersonDetail& rst);

	void insertRec(FmncAMPersonDetail* rec);
	void insertRst(ListFmncAMPersonDetail& rst, bool transact = false);
	void updateRec(FmncAMPersonDetail* rec);
	void updateRst(ListFmncAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMPersonDetail** rec);
	bool loadRecByPrsTyp(ubigint refFmncMPerson, string x1SrefKType, FmncAMPersonDetail** rec);
	ubigint loadRefsByPrs(ubigint refFmncMPerson, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMPersonDetail: C++ wrapper for table TblFmncAMPersonDetail (PgSQL database)
  */
class PgTblFmncAMPersonDetail : public TblFmncAMPersonDetail, public PgTable {

public:
	PgTblFmncAMPersonDetail();
	~PgTblFmncAMPersonDetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMPersonDetail** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMPersonDetail& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMPersonDetail** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMPersonDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMPersonDetail& rst);

	void insertRec(FmncAMPersonDetail* rec);
	void insertRst(ListFmncAMPersonDetail& rst, bool transact = false);
	void updateRec(FmncAMPersonDetail* rec);
	void updateRst(ListFmncAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMPersonDetail** rec);
	bool loadRecByPrsTyp(ubigint refFmncMPerson, string x1SrefKType, FmncAMPersonDetail** rec);
	ubigint loadRefsByPrs(ubigint refFmncMPerson, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

