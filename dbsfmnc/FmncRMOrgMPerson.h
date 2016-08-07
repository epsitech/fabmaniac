/**
  * \file FmncRMOrgMPerson.h
  * database access for table TblFmncRMOrgMPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMORGMPERSON_H
#define FMNCRMORGMPERSON_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMOrgMPerson: record of TblFmncRMOrgMPerson
  */
class FmncRMOrgMPerson {

public:
	FmncRMOrgMPerson(const ubigint ref = 0, const uint x1Startd = 0, const uint x1Stopd = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMPerson = 0, const string srefKFunction = "");

public:
	ubigint ref;
	uint x1Startd;
	uint x1Stopd;
	ubigint refFmncMOrg;
	ubigint refFmncMPerson;
	string srefKFunction;

public:
	bool operator==(const FmncRMOrgMPerson& comp);
	bool operator!=(const FmncRMOrgMPerson& comp);
};

/**
  * ListFmncRMOrgMPerson: recordset of TblFmncRMOrgMPerson
  */
class ListFmncRMOrgMPerson {

public:
	ListFmncRMOrgMPerson();
	ListFmncRMOrgMPerson(const ListFmncRMOrgMPerson& src);
	~ListFmncRMOrgMPerson();

	void clear();
	unsigned int size() const;
	void append(FmncRMOrgMPerson* rec);

	FmncRMOrgMPerson* operator[](const uint ix);
	ListFmncRMOrgMPerson& operator=(const ListFmncRMOrgMPerson& src);
	bool operator==(const ListFmncRMOrgMPerson& comp);
	bool operator!=(const ListFmncRMOrgMPerson& comp);

public:
	vector<FmncRMOrgMPerson*> nodes;
};

/**
  * TblFmncRMOrgMPerson: C++ wrapper for table TblFmncRMOrgMPerson
  */
class TblFmncRMOrgMPerson {

public:
	TblFmncRMOrgMPerson();
	virtual ~TblFmncRMOrgMPerson();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMOrgMPerson** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMOrgMPerson& rst);

	virtual void insertRec(FmncRMOrgMPerson* rec);
	ubigint insertNewRec(FmncRMOrgMPerson** rec = NULL, const uint x1Startd = 0, const uint x1Stopd = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMPerson = 0, const string srefKFunction = "");
	ubigint appendNewRecToRst(ListFmncRMOrgMPerson& rst, FmncRMOrgMPerson** rec = NULL, const uint x1Startd = 0, const uint x1Stopd = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMPerson = 0, const string srefKFunction = "");
	virtual void insertRst(ListFmncRMOrgMPerson& rst, bool transact = false);
	virtual void updateRec(FmncRMOrgMPerson* rec);
	virtual void updateRst(ListFmncRMOrgMPerson& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMOrgMPerson** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMOrgMPerson& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMOrgMPerson: C++ wrapper for table TblFmncRMOrgMPerson (MySQL database)
  */
class MyTblFmncRMOrgMPerson : public TblFmncRMOrgMPerson, public MyTable {

public:
	MyTblFmncRMOrgMPerson();
	~MyTblFmncRMOrgMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMOrgMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMOrgMPerson& rst);

	void insertRec(FmncRMOrgMPerson* rec);
	void insertRst(ListFmncRMOrgMPerson& rst, bool transact = false);
	void updateRec(FmncRMOrgMPerson* rec);
	void updateRst(ListFmncRMOrgMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMOrgMPerson** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMOrgMPerson: C++ wrapper for table TblFmncRMOrgMPerson (PgSQL database)
  */
class PgTblFmncRMOrgMPerson : public TblFmncRMOrgMPerson, public PgTable {

public:
	PgTblFmncRMOrgMPerson();
	~PgTblFmncRMOrgMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMOrgMPerson** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMOrgMPerson& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMOrgMPerson** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMOrgMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMOrgMPerson& rst);

	void insertRec(FmncRMOrgMPerson* rec);
	void insertRst(ListFmncRMOrgMPerson& rst, bool transact = false);
	void updateRec(FmncRMOrgMPerson* rec);
	void updateRst(ListFmncRMOrgMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMOrgMPerson** rec);
};
// IP pgTbl --- END

#endif

