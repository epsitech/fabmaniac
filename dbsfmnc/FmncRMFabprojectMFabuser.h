/**
  * \file FmncRMFabprojectMFabuser.h
  * database access for table TblFmncRMFabprojectMFabuser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMFABPROJECTMFABUSER_H
#define FMNCRMFABPROJECTMFABUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMFabprojectMFabuser: record of TblFmncRMFabprojectMFabuser
  */
class FmncRMFabprojectMFabuser {

public:
	FmncRMFabprojectMFabuser(const ubigint ref = 0, const ubigint refFmncMFabproject = 0, const ubigint refFmncMFabuser = 0);

public:
	ubigint ref;
	ubigint refFmncMFabproject;
	ubigint refFmncMFabuser;

public:
	bool operator==(const FmncRMFabprojectMFabuser& comp);
	bool operator!=(const FmncRMFabprojectMFabuser& comp);
};

/**
  * ListFmncRMFabprojectMFabuser: recordset of TblFmncRMFabprojectMFabuser
  */
class ListFmncRMFabprojectMFabuser {

public:
	ListFmncRMFabprojectMFabuser();
	ListFmncRMFabprojectMFabuser(const ListFmncRMFabprojectMFabuser& src);
	~ListFmncRMFabprojectMFabuser();

	void clear();
	unsigned int size() const;
	void append(FmncRMFabprojectMFabuser* rec);

	FmncRMFabprojectMFabuser* operator[](const uint ix);
	ListFmncRMFabprojectMFabuser& operator=(const ListFmncRMFabprojectMFabuser& src);
	bool operator==(const ListFmncRMFabprojectMFabuser& comp);
	bool operator!=(const ListFmncRMFabprojectMFabuser& comp);

public:
	vector<FmncRMFabprojectMFabuser*> nodes;
};

/**
  * TblFmncRMFabprojectMFabuser: C++ wrapper for table TblFmncRMFabprojectMFabuser
  */
class TblFmncRMFabprojectMFabuser {

public:
	TblFmncRMFabprojectMFabuser();
	virtual ~TblFmncRMFabprojectMFabuser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMFabprojectMFabuser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabprojectMFabuser& rst);

	virtual void insertRec(FmncRMFabprojectMFabuser* rec);
	ubigint insertNewRec(FmncRMFabprojectMFabuser** rec = NULL, const ubigint refFmncMFabproject = 0, const ubigint refFmncMFabuser = 0);
	ubigint appendNewRecToRst(ListFmncRMFabprojectMFabuser& rst, FmncRMFabprojectMFabuser** rec = NULL, const ubigint refFmncMFabproject = 0, const ubigint refFmncMFabuser = 0);
	virtual void insertRst(ListFmncRMFabprojectMFabuser& rst, bool transact = false);
	virtual void updateRec(FmncRMFabprojectMFabuser* rec);
	virtual void updateRst(ListFmncRMFabprojectMFabuser& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMFabprojectMFabuser** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMFabprojectMFabuser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMFabprojectMFabuser: C++ wrapper for table TblFmncRMFabprojectMFabuser (MySQL database)
  */
class MyTblFmncRMFabprojectMFabuser : public TblFmncRMFabprojectMFabuser, public MyTable {

public:
	MyTblFmncRMFabprojectMFabuser();
	~MyTblFmncRMFabprojectMFabuser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFabprojectMFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabprojectMFabuser& rst);

	void insertRec(FmncRMFabprojectMFabuser* rec);
	void insertRst(ListFmncRMFabprojectMFabuser& rst, bool transact = false);
	void updateRec(FmncRMFabprojectMFabuser* rec);
	void updateRst(ListFmncRMFabprojectMFabuser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFabprojectMFabuser** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMFabprojectMFabuser: C++ wrapper for table TblFmncRMFabprojectMFabuser (PgSQL database)
  */
class PgTblFmncRMFabprojectMFabuser : public TblFmncRMFabprojectMFabuser, public PgTable {

public:
	PgTblFmncRMFabprojectMFabuser();
	~PgTblFmncRMFabprojectMFabuser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMFabprojectMFabuser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMFabprojectMFabuser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMFabprojectMFabuser** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFabprojectMFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabprojectMFabuser& rst);

	void insertRec(FmncRMFabprojectMFabuser* rec);
	void insertRst(ListFmncRMFabprojectMFabuser& rst, bool transact = false);
	void updateRec(FmncRMFabprojectMFabuser* rec);
	void updateRst(ListFmncRMFabprojectMFabuser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFabprojectMFabuser** rec);
};
// IP pgTbl --- END

#endif

