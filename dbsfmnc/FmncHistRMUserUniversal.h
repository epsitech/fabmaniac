/**
  * \file FmncHistRMUserUniversal.h
  * database access for table TblFmncHistRMUserUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCHISTRMUSERUNIVERSAL_H
#define FMNCHISTRMUSERUNIVERSAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncHistRMUserUniversal: record of TblFmncHistRMUserUniversal
  */
class FmncHistRMUserUniversal {

public:
	FmncHistRMUserUniversal(const ubigint ref = 0, const ubigint refFmncMUser = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVCard = 0, const uint ixFmncVPreset = 0, const uint preIxFmncVMaintable = 0, const ubigint preUref = 0, const uint start = 0);

public:
	ubigint ref;
	ubigint refFmncMUser;
	uint unvIxFmncVMaintable;
	ubigint unvUref;
	uint ixFmncVCard;
	uint ixFmncVPreset;
	uint preIxFmncVMaintable;
	ubigint preUref;
	uint start;

public:
	bool operator==(const FmncHistRMUserUniversal& comp);
	bool operator!=(const FmncHistRMUserUniversal& comp);
};

/**
  * ListFmncHistRMUserUniversal: recordset of TblFmncHistRMUserUniversal
  */
class ListFmncHistRMUserUniversal {

public:
	ListFmncHistRMUserUniversal();
	ListFmncHistRMUserUniversal(const ListFmncHistRMUserUniversal& src);
	~ListFmncHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(FmncHistRMUserUniversal* rec);

	FmncHistRMUserUniversal* operator[](const uint ix);
	ListFmncHistRMUserUniversal& operator=(const ListFmncHistRMUserUniversal& src);
	bool operator==(const ListFmncHistRMUserUniversal& comp);
	bool operator!=(const ListFmncHistRMUserUniversal& comp);

public:
	vector<FmncHistRMUserUniversal*> nodes;
};

/**
  * TblFmncHistRMUserUniversal: C++ wrapper for table TblFmncHistRMUserUniversal
  */
class TblFmncHistRMUserUniversal {

public:
	TblFmncHistRMUserUniversal();
	virtual ~TblFmncHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncHistRMUserUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncHistRMUserUniversal& rst);

	virtual void insertRec(FmncHistRMUserUniversal* rec);
	ubigint insertNewRec(FmncHistRMUserUniversal** rec = NULL, const ubigint refFmncMUser = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVCard = 0, const uint ixFmncVPreset = 0, const uint preIxFmncVMaintable = 0, const ubigint preUref = 0, const uint start = 0);
	ubigint appendNewRecToRst(ListFmncHistRMUserUniversal& rst, FmncHistRMUserUniversal** rec = NULL, const ubigint refFmncMUser = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVCard = 0, const uint ixFmncVPreset = 0, const uint preIxFmncVMaintable = 0, const ubigint preUref = 0, const uint start = 0);
	virtual void insertRst(ListFmncHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(FmncHistRMUserUniversal* rec);
	virtual void updateRst(ListFmncHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncHistRMUserUniversal** rec);
	virtual ubigint loadRstByUsrCrd(ubigint refFmncMUser, uint ixFmncVCard, const bool append, ListFmncHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(ubigint ref, ubigint& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncHistRMUserUniversal& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncHistRMUserUniversal: C++ wrapper for table TblFmncHistRMUserUniversal (MySQL database)
  */
class MyTblFmncHistRMUserUniversal : public TblFmncHistRMUserUniversal, public MyTable {

public:
	MyTblFmncHistRMUserUniversal();
	~MyTblFmncHistRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncHistRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncHistRMUserUniversal& rst);

	void insertRec(FmncHistRMUserUniversal* rec);
	void insertRst(ListFmncHistRMUserUniversal& rst, bool transact = false);
	void updateRec(FmncHistRMUserUniversal* rec);
	void updateRst(ListFmncHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncHistRMUserUniversal** rec);
	ubigint loadRstByUsrCrd(ubigint refFmncMUser, uint ixFmncVCard, const bool append, ListFmncHistRMUserUniversal& rst);
	bool loadUnuByRef(ubigint ref, ubigint& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncHistRMUserUniversal: C++ wrapper for table TblFmncHistRMUserUniversal (PgSQL database)
  */
class PgTblFmncHistRMUserUniversal : public TblFmncHistRMUserUniversal, public PgTable {

public:
	PgTblFmncHistRMUserUniversal();
	~PgTblFmncHistRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncHistRMUserUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncHistRMUserUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncHistRMUserUniversal** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncHistRMUserUniversal& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncHistRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncHistRMUserUniversal& rst);

	void insertRec(FmncHistRMUserUniversal* rec);
	void insertRst(ListFmncHistRMUserUniversal& rst, bool transact = false);
	void updateRec(FmncHistRMUserUniversal* rec);
	void updateRst(ListFmncHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncHistRMUserUniversal** rec);
	ubigint loadRstByUsrCrd(ubigint refFmncMUser, uint ixFmncVCard, const bool append, ListFmncHistRMUserUniversal& rst);
	bool loadUnuByRef(ubigint ref, ubigint& val);
};
// IP pgTbl --- END

#endif

