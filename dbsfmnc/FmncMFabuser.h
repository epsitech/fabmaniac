/**
  * \file FmncMFabuser.h
  * database access for table TblFmncMFabuser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMFABUSER_H
#define FMNCMFABUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMFabuser: record of TblFmncMFabuser
  */
class FmncMFabuser {

public:
	FmncMFabuser(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFab = 0, const ubigint refFmncMPerson = 0, const ubigint refRFabproject = 0, const ubigint refFmncMFabproject = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncMFab;
	ubigint refFmncMPerson;
	ubigint refRFabproject;
	ubigint refFmncMFabproject;
	string sref;
	ubigint refJState;
	uint ixVState;

public:
	bool operator==(const FmncMFabuser& comp);
	bool operator!=(const FmncMFabuser& comp);
};

/**
  * ListFmncMFabuser: recordset of TblFmncMFabuser
  */
class ListFmncMFabuser {

public:
	ListFmncMFabuser();
	ListFmncMFabuser(const ListFmncMFabuser& src);
	~ListFmncMFabuser();

	void clear();
	unsigned int size() const;
	void append(FmncMFabuser* rec);

	FmncMFabuser* operator[](const uint ix);
	ListFmncMFabuser& operator=(const ListFmncMFabuser& src);
	bool operator==(const ListFmncMFabuser& comp);
	bool operator!=(const ListFmncMFabuser& comp);

public:
	vector<FmncMFabuser*> nodes;
};

/**
  * TblFmncMFabuser: C++ wrapper for table TblFmncMFabuser
  */
class TblFmncMFabuser {

public:
	TblFmncMFabuser();
	virtual ~TblFmncMFabuser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMFabuser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFabuser& rst);

	virtual void insertRec(FmncMFabuser* rec);
	ubigint insertNewRec(FmncMFabuser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFab = 0, const ubigint refFmncMPerson = 0, const ubigint refRFabproject = 0, const ubigint refFmncMFabproject = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListFmncMFabuser& rst, FmncMFabuser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncMFab = 0, const ubigint refFmncMPerson = 0, const ubigint refRFabproject = 0, const ubigint refFmncMFabproject = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0);
	virtual void insertRst(ListFmncMFabuser& rst, bool transact = false);
	virtual void updateRec(FmncMFabuser* rec);
	virtual void updateRst(ListFmncMFabuser& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMFabuser** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMFabuser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMFabuser: C++ wrapper for table TblFmncMFabuser (MySQL database)
  */
class MyTblFmncMFabuser : public TblFmncMFabuser, public MyTable {

public:
	MyTblFmncMFabuser();
	~MyTblFmncMFabuser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFabuser& rst);

	void insertRec(FmncMFabuser* rec);
	void insertRst(ListFmncMFabuser& rst, bool transact = false);
	void updateRec(FmncMFabuser* rec);
	void updateRst(ListFmncMFabuser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMFabuser** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMFabuser: C++ wrapper for table TblFmncMFabuser (PgSQL database)
  */
class PgTblFmncMFabuser : public TblFmncMFabuser, public PgTable {

public:
	PgTblFmncMFabuser();
	~PgTblFmncMFabuser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMFabuser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMFabuser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMFabuser** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFabuser& rst);

	void insertRec(FmncMFabuser* rec);
	void insertRst(ListFmncMFabuser& rst, bool transact = false);
	void updateRec(FmncMFabuser* rec);
	void updateRst(ListFmncMFabuser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMFabuser** rec);
};
// IP pgTbl --- END

#endif

