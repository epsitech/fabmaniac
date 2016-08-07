/**
  * \file FmncMPerson.h
  * database access for table TblFmncMPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMPERSON_H
#define FMNCMPERSON_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMPerson: record of TblFmncMPerson
  */
class FmncMPerson {

public:
	FmncMPerson(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const ubigint refROrg = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMAddress = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "", const string Salutation = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint ixWDerivate;
	ubigint refROrg;
	ubigint refFmncMOrg;
	ubigint refFmncMAddress;
	uint ixVSex;
	string Title;
	string Firstname;
	ubigint refJLastname;
	string Lastname;
	ubigint telRefADetail;
	string Tel;
	ubigint emlRefADetail;
	string Eml;
	string Salutation;

public:
	bool operator==(const FmncMPerson& comp);
	bool operator!=(const FmncMPerson& comp);
};

/**
  * ListFmncMPerson: recordset of TblFmncMPerson
  */
class ListFmncMPerson {

public:
	ListFmncMPerson();
	ListFmncMPerson(const ListFmncMPerson& src);
	~ListFmncMPerson();

	void clear();
	unsigned int size() const;
	void append(FmncMPerson* rec);

	FmncMPerson* operator[](const uint ix);
	ListFmncMPerson& operator=(const ListFmncMPerson& src);
	bool operator==(const ListFmncMPerson& comp);
	bool operator!=(const ListFmncMPerson& comp);

public:
	vector<FmncMPerson*> nodes;
};

/**
  * TblFmncMPerson: C++ wrapper for table TblFmncMPerson
  */
class TblFmncMPerson {

public:
	TblFmncMPerson();
	virtual ~TblFmncMPerson();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMPerson** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMPerson& rst);

	virtual void insertRec(FmncMPerson* rec);
	ubigint insertNewRec(FmncMPerson** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const ubigint refROrg = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMAddress = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "", const string Salutation = "");
	ubigint appendNewRecToRst(ListFmncMPerson& rst, FmncMPerson** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const ubigint refROrg = 0, const ubigint refFmncMOrg = 0, const ubigint refFmncMAddress = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "", const string Salutation = "");
	virtual void insertRst(ListFmncMPerson& rst, bool transact = false);
	virtual void updateRec(FmncMPerson* rec);
	virtual void updateRst(ListFmncMPerson& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMPerson** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMPerson& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMPerson: C++ wrapper for table TblFmncMPerson (MySQL database)
  */
class MyTblFmncMPerson : public TblFmncMPerson, public MyTable {

public:
	MyTblFmncMPerson();
	~MyTblFmncMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMPerson& rst);

	void insertRec(FmncMPerson* rec);
	void insertRst(ListFmncMPerson& rst, bool transact = false);
	void updateRec(FmncMPerson* rec);
	void updateRst(ListFmncMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMPerson** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMPerson: C++ wrapper for table TblFmncMPerson (PgSQL database)
  */
class PgTblFmncMPerson : public TblFmncMPerson, public PgTable {

public:
	PgTblFmncMPerson();
	~PgTblFmncMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMPerson** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMPerson& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMPerson** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMPerson& rst);

	void insertRec(FmncMPerson* rec);
	void insertRst(ListFmncMPerson& rst, bool transact = false);
	void updateRec(FmncMPerson* rec);
	void updateRst(ListFmncMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMPerson** rec);
};
// IP pgTbl --- END

#endif

