/**
  * \file FmncJMPersonLastname.h
  * database access for table TblFmncJMPersonLastname (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJMPERSONLASTNAME_H
#define FMNCJMPERSONLASTNAME_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJMPersonLastname: record of TblFmncJMPersonLastname
  */
class FmncJMPersonLastname {

public:
	FmncJMPersonLastname(const ubigint ref = 0, const ubigint refFmncMPerson = 0, const uint x1Startd = 0, const string Lastname = "");

public:
	ubigint ref;
	ubigint refFmncMPerson;
	uint x1Startd;
	string Lastname;

public:
	bool operator==(const FmncJMPersonLastname& comp);
	bool operator!=(const FmncJMPersonLastname& comp);
};

/**
  * ListFmncJMPersonLastname: recordset of TblFmncJMPersonLastname
  */
class ListFmncJMPersonLastname {

public:
	ListFmncJMPersonLastname();
	ListFmncJMPersonLastname(const ListFmncJMPersonLastname& src);
	~ListFmncJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(FmncJMPersonLastname* rec);

	FmncJMPersonLastname* operator[](const uint ix);
	ListFmncJMPersonLastname& operator=(const ListFmncJMPersonLastname& src);
	bool operator==(const ListFmncJMPersonLastname& comp);
	bool operator!=(const ListFmncJMPersonLastname& comp);

public:
	vector<FmncJMPersonLastname*> nodes;
};

/**
  * TblFmncJMPersonLastname: C++ wrapper for table TblFmncJMPersonLastname
  */
class TblFmncJMPersonLastname {

public:
	TblFmncJMPersonLastname();
	virtual ~TblFmncJMPersonLastname();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJMPersonLastname** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMPersonLastname& rst);

	virtual void insertRec(FmncJMPersonLastname* rec);
	ubigint insertNewRec(FmncJMPersonLastname** rec = NULL, const ubigint refFmncMPerson = 0, const uint x1Startd = 0, const string Lastname = "");
	ubigint appendNewRecToRst(ListFmncJMPersonLastname& rst, FmncJMPersonLastname** rec = NULL, const ubigint refFmncMPerson = 0, const uint x1Startd = 0, const string Lastname = "");
	virtual void insertRst(ListFmncJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(FmncJMPersonLastname* rec);
	virtual void updateRst(ListFmncJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJMPersonLastname** rec);
	virtual bool loadRecByPrsSta(ubigint refFmncMPerson, uint x1Startd, FmncJMPersonLastname** rec);
	virtual ubigint loadRefsByPrs(ubigint refFmncMPerson, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByPrs(ubigint refFmncMPerson, const bool append, ListFmncJMPersonLastname& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJMPersonLastname& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJMPersonLastname: C++ wrapper for table TblFmncJMPersonLastname (MySQL database)
  */
class MyTblFmncJMPersonLastname : public TblFmncJMPersonLastname, public MyTable {

public:
	MyTblFmncJMPersonLastname();
	~MyTblFmncJMPersonLastname();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMPersonLastname** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMPersonLastname& rst);

	void insertRec(FmncJMPersonLastname* rec);
	void insertRst(ListFmncJMPersonLastname& rst, bool transact = false);
	void updateRec(FmncJMPersonLastname* rec);
	void updateRst(ListFmncJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMPersonLastname** rec);
	bool loadRecByPrsSta(ubigint refFmncMPerson, uint x1Startd, FmncJMPersonLastname** rec);
	ubigint loadRefsByPrs(ubigint refFmncMPerson, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrs(ubigint refFmncMPerson, const bool append, ListFmncJMPersonLastname& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJMPersonLastname: C++ wrapper for table TblFmncJMPersonLastname (PgSQL database)
  */
class PgTblFmncJMPersonLastname : public TblFmncJMPersonLastname, public PgTable {

public:
	PgTblFmncJMPersonLastname();
	~PgTblFmncJMPersonLastname();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJMPersonLastname** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJMPersonLastname& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJMPersonLastname** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJMPersonLastname& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJMPersonLastname** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJMPersonLastname& rst);

	void insertRec(FmncJMPersonLastname* rec);
	void insertRst(ListFmncJMPersonLastname& rst, bool transact = false);
	void updateRec(FmncJMPersonLastname* rec);
	void updateRst(ListFmncJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJMPersonLastname** rec);
	bool loadRecByPrsSta(ubigint refFmncMPerson, uint x1Startd, FmncJMPersonLastname** rec);
	ubigint loadRefsByPrs(ubigint refFmncMPerson, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrs(ubigint refFmncMPerson, const bool append, ListFmncJMPersonLastname& rst);
};
// IP pgTbl --- END

#endif

