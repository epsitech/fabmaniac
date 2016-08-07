/**
  * \file FmncRMUserMUsergroup.h
  * database access for table TblFmncRMUserMUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMUSERMUSERGROUP_H
#define FMNCRMUSERMUSERGROUP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMUserMUsergroup: record of TblFmncRMUserMUsergroup
  */
class FmncRMUserMUsergroup {

public:
	FmncRMUserMUsergroup(const ubigint ref = 0, const ubigint refFmncMUser = 0, const ubigint refFmncMUsergroup = 0, const uint ixFmncVUserlevel = 0);

public:
	ubigint ref;
	ubigint refFmncMUser;
	ubigint refFmncMUsergroup;
	uint ixFmncVUserlevel;

public:
	bool operator==(const FmncRMUserMUsergroup& comp);
	bool operator!=(const FmncRMUserMUsergroup& comp);
};

/**
  * ListFmncRMUserMUsergroup: recordset of TblFmncRMUserMUsergroup
  */
class ListFmncRMUserMUsergroup {

public:
	ListFmncRMUserMUsergroup();
	ListFmncRMUserMUsergroup(const ListFmncRMUserMUsergroup& src);
	~ListFmncRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(FmncRMUserMUsergroup* rec);

	FmncRMUserMUsergroup* operator[](const uint ix);
	ListFmncRMUserMUsergroup& operator=(const ListFmncRMUserMUsergroup& src);
	bool operator==(const ListFmncRMUserMUsergroup& comp);
	bool operator!=(const ListFmncRMUserMUsergroup& comp);

public:
	vector<FmncRMUserMUsergroup*> nodes;
};

/**
  * TblFmncRMUserMUsergroup: C++ wrapper for table TblFmncRMUserMUsergroup
  */
class TblFmncRMUserMUsergroup {

public:
	TblFmncRMUserMUsergroup();
	virtual ~TblFmncRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMUserMUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMUserMUsergroup& rst);

	virtual void insertRec(FmncRMUserMUsergroup* rec);
	ubigint insertNewRec(FmncRMUserMUsergroup** rec = NULL, const ubigint refFmncMUser = 0, const ubigint refFmncMUsergroup = 0, const uint ixFmncVUserlevel = 0);
	ubigint appendNewRecToRst(ListFmncRMUserMUsergroup& rst, FmncRMUserMUsergroup** rec = NULL, const ubigint refFmncMUser = 0, const ubigint refFmncMUsergroup = 0, const uint ixFmncVUserlevel = 0);
	virtual void insertRst(ListFmncRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(FmncRMUserMUsergroup* rec);
	virtual void updateRst(ListFmncRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMUserMUsergroup** rec);
	virtual ubigint loadRstByUsg(ubigint refFmncMUsergroup, const bool append, ListFmncRMUserMUsergroup& rst);
	virtual ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncRMUserMUsergroup& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMUserMUsergroup& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMUserMUsergroup: C++ wrapper for table TblFmncRMUserMUsergroup (MySQL database)
  */
class MyTblFmncRMUserMUsergroup : public TblFmncRMUserMUsergroup, public MyTable {

public:
	MyTblFmncRMUserMUsergroup();
	~MyTblFmncRMUserMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMUserMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMUserMUsergroup& rst);

	void insertRec(FmncRMUserMUsergroup* rec);
	void insertRst(ListFmncRMUserMUsergroup& rst, bool transact = false);
	void updateRec(FmncRMUserMUsergroup* rec);
	void updateRst(ListFmncRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMUserMUsergroup** rec);
	ubigint loadRstByUsg(ubigint refFmncMUsergroup, const bool append, ListFmncRMUserMUsergroup& rst);
	ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncRMUserMUsergroup& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMUserMUsergroup: C++ wrapper for table TblFmncRMUserMUsergroup (PgSQL database)
  */
class PgTblFmncRMUserMUsergroup : public TblFmncRMUserMUsergroup, public PgTable {

public:
	PgTblFmncRMUserMUsergroup();
	~PgTblFmncRMUserMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMUserMUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMUserMUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMUserMUsergroup** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncRMUserMUsergroup& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMUserMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMUserMUsergroup& rst);

	void insertRec(FmncRMUserMUsergroup* rec);
	void insertRst(ListFmncRMUserMUsergroup& rst, bool transact = false);
	void updateRec(FmncRMUserMUsergroup* rec);
	void updateRst(ListFmncRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMUserMUsergroup** rec);
	ubigint loadRstByUsg(ubigint refFmncMUsergroup, const bool append, ListFmncRMUserMUsergroup& rst);
	ubigint loadRstByUsr(ubigint refFmncMUser, const bool append, ListFmncRMUserMUsergroup& rst);
};
// IP pgTbl --- END

#endif

