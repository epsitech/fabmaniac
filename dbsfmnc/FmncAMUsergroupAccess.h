/**
  * \file FmncAMUsergroupAccess.h
  * database access for table TblFmncAMUsergroupAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMUSERGROUPACCESS_H
#define FMNCAMUSERGROUPACCESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMUsergroupAccess: record of TblFmncAMUsergroupAccess
  */
class FmncAMUsergroupAccess {

public:
	FmncAMUsergroupAccess(const ubigint ref = 0, const ubigint refFmncMUsergroup = 0, const uint x1IxFmncVCard = 0, const uint ixFmncWUiaccess = 0);

public:
	ubigint ref;
	ubigint refFmncMUsergroup;
	uint x1IxFmncVCard;
	uint ixFmncWUiaccess;

public:
	bool operator==(const FmncAMUsergroupAccess& comp);
	bool operator!=(const FmncAMUsergroupAccess& comp);
};

/**
  * ListFmncAMUsergroupAccess: recordset of TblFmncAMUsergroupAccess
  */
class ListFmncAMUsergroupAccess {

public:
	ListFmncAMUsergroupAccess();
	ListFmncAMUsergroupAccess(const ListFmncAMUsergroupAccess& src);
	~ListFmncAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(FmncAMUsergroupAccess* rec);

	FmncAMUsergroupAccess* operator[](const uint ix);
	ListFmncAMUsergroupAccess& operator=(const ListFmncAMUsergroupAccess& src);
	bool operator==(const ListFmncAMUsergroupAccess& comp);
	bool operator!=(const ListFmncAMUsergroupAccess& comp);

public:
	vector<FmncAMUsergroupAccess*> nodes;
};

/**
  * TblFmncAMUsergroupAccess: C++ wrapper for table TblFmncAMUsergroupAccess
  */
class TblFmncAMUsergroupAccess {

public:
	TblFmncAMUsergroupAccess();
	virtual ~TblFmncAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMUsergroupAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMUsergroupAccess& rst);

	virtual void insertRec(FmncAMUsergroupAccess* rec);
	ubigint insertNewRec(FmncAMUsergroupAccess** rec = NULL, const ubigint refFmncMUsergroup = 0, const uint x1IxFmncVCard = 0, const uint ixFmncWUiaccess = 0);
	ubigint appendNewRecToRst(ListFmncAMUsergroupAccess& rst, FmncAMUsergroupAccess** rec = NULL, const ubigint refFmncMUsergroup = 0, const uint x1IxFmncVCard = 0, const uint ixFmncWUiaccess = 0);
	virtual void insertRst(ListFmncAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(FmncAMUsergroupAccess* rec);
	virtual void updateRst(ListFmncAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMUsergroupAccess** rec);
	virtual bool loadRecByUsgCrd(ubigint refFmncMUsergroup, uint x1IxFmncVCard, FmncAMUsergroupAccess** rec);
	virtual ubigint loadRefsByUsg(ubigint refFmncMUsergroup, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMUsergroupAccess& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMUsergroupAccess: C++ wrapper for table TblFmncAMUsergroupAccess (MySQL database)
  */
class MyTblFmncAMUsergroupAccess : public TblFmncAMUsergroupAccess, public MyTable {

public:
	MyTblFmncAMUsergroupAccess();
	~MyTblFmncAMUsergroupAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMUsergroupAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMUsergroupAccess& rst);

	void insertRec(FmncAMUsergroupAccess* rec);
	void insertRst(ListFmncAMUsergroupAccess& rst, bool transact = false);
	void updateRec(FmncAMUsergroupAccess* rec);
	void updateRst(ListFmncAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMUsergroupAccess** rec);
	bool loadRecByUsgCrd(ubigint refFmncMUsergroup, uint x1IxFmncVCard, FmncAMUsergroupAccess** rec);
	ubigint loadRefsByUsg(ubigint refFmncMUsergroup, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMUsergroupAccess: C++ wrapper for table TblFmncAMUsergroupAccess (PgSQL database)
  */
class PgTblFmncAMUsergroupAccess : public TblFmncAMUsergroupAccess, public PgTable {

public:
	PgTblFmncAMUsergroupAccess();
	~PgTblFmncAMUsergroupAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMUsergroupAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMUsergroupAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMUsergroupAccess** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMUsergroupAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMUsergroupAccess& rst);

	void insertRec(FmncAMUsergroupAccess* rec);
	void insertRst(ListFmncAMUsergroupAccess& rst, bool transact = false);
	void updateRec(FmncAMUsergroupAccess* rec);
	void updateRst(ListFmncAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMUsergroupAccess** rec);
	bool loadRecByUsgCrd(ubigint refFmncMUsergroup, uint x1IxFmncVCard, FmncAMUsergroupAccess** rec);
	ubigint loadRefsByUsg(ubigint refFmncMUsergroup, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

