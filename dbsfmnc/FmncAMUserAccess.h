/**
  * \file FmncAMUserAccess.h
  * database access for table TblFmncAMUserAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMUSERACCESS_H
#define FMNCAMUSERACCESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMUserAccess: record of TblFmncAMUserAccess
  */
class FmncAMUserAccess {

public:
	FmncAMUserAccess(const ubigint ref = 0, const ubigint refFmncMUser = 0, const uint x1IxFmncVCard = 0, const uint ixFmncWUiaccess = 0);

public:
	ubigint ref;
	ubigint refFmncMUser;
	uint x1IxFmncVCard;
	uint ixFmncWUiaccess;

public:
	bool operator==(const FmncAMUserAccess& comp);
	bool operator!=(const FmncAMUserAccess& comp);
};

/**
  * ListFmncAMUserAccess: recordset of TblFmncAMUserAccess
  */
class ListFmncAMUserAccess {

public:
	ListFmncAMUserAccess();
	ListFmncAMUserAccess(const ListFmncAMUserAccess& src);
	~ListFmncAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(FmncAMUserAccess* rec);

	FmncAMUserAccess* operator[](const uint ix);
	ListFmncAMUserAccess& operator=(const ListFmncAMUserAccess& src);
	bool operator==(const ListFmncAMUserAccess& comp);
	bool operator!=(const ListFmncAMUserAccess& comp);

public:
	vector<FmncAMUserAccess*> nodes;
};

/**
  * TblFmncAMUserAccess: C++ wrapper for table TblFmncAMUserAccess
  */
class TblFmncAMUserAccess {

public:
	TblFmncAMUserAccess();
	virtual ~TblFmncAMUserAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMUserAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMUserAccess& rst);

	virtual void insertRec(FmncAMUserAccess* rec);
	ubigint insertNewRec(FmncAMUserAccess** rec = NULL, const ubigint refFmncMUser = 0, const uint x1IxFmncVCard = 0, const uint ixFmncWUiaccess = 0);
	ubigint appendNewRecToRst(ListFmncAMUserAccess& rst, FmncAMUserAccess** rec = NULL, const ubigint refFmncMUser = 0, const uint x1IxFmncVCard = 0, const uint ixFmncWUiaccess = 0);
	virtual void insertRst(ListFmncAMUserAccess& rst, bool transact = false);
	virtual void updateRec(FmncAMUserAccess* rec);
	virtual void updateRst(ListFmncAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMUserAccess** rec);
	virtual bool loadRecByUsrCrd(ubigint refFmncMUser, uint x1IxFmncVCard, FmncAMUserAccess** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMUserAccess& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMUserAccess: C++ wrapper for table TblFmncAMUserAccess (MySQL database)
  */
class MyTblFmncAMUserAccess : public TblFmncAMUserAccess, public MyTable {

public:
	MyTblFmncAMUserAccess();
	~MyTblFmncAMUserAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMUserAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMUserAccess& rst);

	void insertRec(FmncAMUserAccess* rec);
	void insertRst(ListFmncAMUserAccess& rst, bool transact = false);
	void updateRec(FmncAMUserAccess* rec);
	void updateRst(ListFmncAMUserAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMUserAccess** rec);
	bool loadRecByUsrCrd(ubigint refFmncMUser, uint x1IxFmncVCard, FmncAMUserAccess** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMUserAccess: C++ wrapper for table TblFmncAMUserAccess (PgSQL database)
  */
class PgTblFmncAMUserAccess : public TblFmncAMUserAccess, public PgTable {

public:
	PgTblFmncAMUserAccess();
	~PgTblFmncAMUserAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMUserAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMUserAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMUserAccess** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMUserAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMUserAccess& rst);

	void insertRec(FmncAMUserAccess* rec);
	void insertRst(ListFmncAMUserAccess& rst, bool transact = false);
	void updateRec(FmncAMUserAccess* rec);
	void updateRst(ListFmncAMUserAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMUserAccess** rec);
	bool loadRecByUsrCrd(ubigint refFmncMUser, uint x1IxFmncVCard, FmncAMUserAccess** rec);
};
// IP pgTbl --- END

#endif

