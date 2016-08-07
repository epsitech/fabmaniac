/**
  * \file FmncAccRMUserUniversal.h
  * database access for table TblFmncAccRMUserUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCACCRMUSERUNIVERSAL_H
#define FMNCACCRMUSERUNIVERSAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAccRMUserUniversal: record of TblFmncAccRMUserUniversal
  */
class FmncAccRMUserUniversal {

public:
	FmncAccRMUserUniversal(const ubigint ref = 0, const ubigint refFmncMUser = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVAccess = 0);

public:
	ubigint ref;
	ubigint refFmncMUser;
	uint unvIxFmncVMaintable;
	ubigint unvUref;
	uint ixFmncVAccess;

public:
	bool operator==(const FmncAccRMUserUniversal& comp);
	bool operator!=(const FmncAccRMUserUniversal& comp);
};

/**
  * ListFmncAccRMUserUniversal: recordset of TblFmncAccRMUserUniversal
  */
class ListFmncAccRMUserUniversal {

public:
	ListFmncAccRMUserUniversal();
	ListFmncAccRMUserUniversal(const ListFmncAccRMUserUniversal& src);
	~ListFmncAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(FmncAccRMUserUniversal* rec);

	FmncAccRMUserUniversal* operator[](const uint ix);
	ListFmncAccRMUserUniversal& operator=(const ListFmncAccRMUserUniversal& src);
	bool operator==(const ListFmncAccRMUserUniversal& comp);
	bool operator!=(const ListFmncAccRMUserUniversal& comp);

public:
	vector<FmncAccRMUserUniversal*> nodes;
};

/**
  * TblFmncAccRMUserUniversal: C++ wrapper for table TblFmncAccRMUserUniversal
  */
class TblFmncAccRMUserUniversal {

public:
	TblFmncAccRMUserUniversal();
	virtual ~TblFmncAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAccRMUserUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAccRMUserUniversal& rst);

	virtual void insertRec(FmncAccRMUserUniversal* rec);
	ubigint insertNewRec(FmncAccRMUserUniversal** rec = NULL, const ubigint refFmncMUser = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVAccess = 0);
	ubigint appendNewRecToRst(ListFmncAccRMUserUniversal& rst, FmncAccRMUserUniversal** rec = NULL, const ubigint refFmncMUser = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVAccess = 0);
	virtual void insertRst(ListFmncAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(FmncAccRMUserUniversal* rec);
	virtual void updateRst(ListFmncAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(ubigint refFmncMUser, uint unvIxFmncVMaintable, ubigint unvUref, FmncAccRMUserUniversal** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAccRMUserUniversal& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAccRMUserUniversal: C++ wrapper for table TblFmncAccRMUserUniversal (MySQL database)
  */
class MyTblFmncAccRMUserUniversal : public TblFmncAccRMUserUniversal, public MyTable {

public:
	MyTblFmncAccRMUserUniversal();
	~MyTblFmncAccRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAccRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAccRMUserUniversal& rst);

	void insertRec(FmncAccRMUserUniversal* rec);
	void insertRst(ListFmncAccRMUserUniversal& rst, bool transact = false);
	void updateRec(FmncAccRMUserUniversal* rec);
	void updateRst(ListFmncAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(ubigint refFmncMUser, uint unvIxFmncVMaintable, ubigint unvUref, FmncAccRMUserUniversal** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAccRMUserUniversal: C++ wrapper for table TblFmncAccRMUserUniversal (PgSQL database)
  */
class PgTblFmncAccRMUserUniversal : public TblFmncAccRMUserUniversal, public PgTable {

public:
	PgTblFmncAccRMUserUniversal();
	~PgTblFmncAccRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAccRMUserUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAccRMUserUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAccRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAccRMUserUniversal& rst);

	void insertRec(FmncAccRMUserUniversal* rec);
	void insertRst(ListFmncAccRMUserUniversal& rst, bool transact = false);
	void updateRec(FmncAccRMUserUniversal* rec);
	void updateRst(ListFmncAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(ubigint refFmncMUser, uint unvIxFmncVMaintable, ubigint unvUref, FmncAccRMUserUniversal** rec);
};
// IP pgTbl --- END

#endif

