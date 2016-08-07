/**
  * \file FmncRMUsergroupUniversal.h
  * database access for table TblFmncRMUsergroupUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMUSERGROUPUNIVERSAL_H
#define FMNCRMUSERGROUPUNIVERSAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMUsergroupUniversal: record of TblFmncRMUsergroupUniversal
  */
class FmncRMUsergroupUniversal {

public:
	FmncRMUsergroupUniversal(const ubigint ref = 0, const ubigint refFmncMUsergroup = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVAccess = 0);

public:
	ubigint ref;
	ubigint refFmncMUsergroup;
	uint unvIxFmncVMaintable;
	ubigint unvUref;
	uint ixFmncVAccess;

public:
	bool operator==(const FmncRMUsergroupUniversal& comp);
	bool operator!=(const FmncRMUsergroupUniversal& comp);
};

/**
  * ListFmncRMUsergroupUniversal: recordset of TblFmncRMUsergroupUniversal
  */
class ListFmncRMUsergroupUniversal {

public:
	ListFmncRMUsergroupUniversal();
	ListFmncRMUsergroupUniversal(const ListFmncRMUsergroupUniversal& src);
	~ListFmncRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(FmncRMUsergroupUniversal* rec);

	FmncRMUsergroupUniversal* operator[](const uint ix);
	ListFmncRMUsergroupUniversal& operator=(const ListFmncRMUsergroupUniversal& src);
	bool operator==(const ListFmncRMUsergroupUniversal& comp);
	bool operator!=(const ListFmncRMUsergroupUniversal& comp);

public:
	vector<FmncRMUsergroupUniversal*> nodes;
};

/**
  * TblFmncRMUsergroupUniversal: C++ wrapper for table TblFmncRMUsergroupUniversal
  */
class TblFmncRMUsergroupUniversal {

public:
	TblFmncRMUsergroupUniversal();
	virtual ~TblFmncRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMUsergroupUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMUsergroupUniversal& rst);

	virtual void insertRec(FmncRMUsergroupUniversal* rec);
	ubigint insertNewRec(FmncRMUsergroupUniversal** rec = NULL, const ubigint refFmncMUsergroup = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVAccess = 0);
	ubigint appendNewRecToRst(ListFmncRMUsergroupUniversal& rst, FmncRMUsergroupUniversal** rec = NULL, const ubigint refFmncMUsergroup = 0, const uint unvIxFmncVMaintable = 0, const ubigint unvUref = 0, const uint ixFmncVAccess = 0);
	virtual void insertRst(ListFmncRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(FmncRMUsergroupUniversal* rec);
	virtual void updateRst(ListFmncRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(ubigint refFmncMUsergroup, uint unvIxFmncVMaintable, ubigint unvUref, FmncRMUsergroupUniversal** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMUsergroupUniversal& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMUsergroupUniversal: C++ wrapper for table TblFmncRMUsergroupUniversal (MySQL database)
  */
class MyTblFmncRMUsergroupUniversal : public TblFmncRMUsergroupUniversal, public MyTable {

public:
	MyTblFmncRMUsergroupUniversal();
	~MyTblFmncRMUsergroupUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMUsergroupUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMUsergroupUniversal& rst);

	void insertRec(FmncRMUsergroupUniversal* rec);
	void insertRst(ListFmncRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(FmncRMUsergroupUniversal* rec);
	void updateRst(ListFmncRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(ubigint refFmncMUsergroup, uint unvIxFmncVMaintable, ubigint unvUref, FmncRMUsergroupUniversal** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMUsergroupUniversal: C++ wrapper for table TblFmncRMUsergroupUniversal (PgSQL database)
  */
class PgTblFmncRMUsergroupUniversal : public TblFmncRMUsergroupUniversal, public PgTable {

public:
	PgTblFmncRMUsergroupUniversal();
	~PgTblFmncRMUsergroupUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMUsergroupUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMUsergroupUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMUsergroupUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMUsergroupUniversal& rst);

	void insertRec(FmncRMUsergroupUniversal* rec);
	void insertRst(ListFmncRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(FmncRMUsergroupUniversal* rec);
	void updateRst(ListFmncRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(ubigint refFmncMUsergroup, uint unvIxFmncVMaintable, ubigint unvUref, FmncRMUsergroupUniversal** rec);
};
// IP pgTbl --- END

#endif

