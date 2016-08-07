/**
  * \file FmncMPurchorder.h
  * database access for table TblFmncMPurchorder (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMPURCHORDER_H
#define FMNCMPURCHORDER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMPurchorder: record of TblFmncMPurchorder
  */
class FmncMPurchorder {

public:
	FmncMPurchorder(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint pcoRefFmncMOrg = 0, const ubigint splRefFmncMOrg = 0, const ubigint refFmncMFile = 0, const string sref = "", const uint Date = 0, const ubigint refJState = 0, const uint ixVState = 0, const double Amount = 0.0, const ubigint pcpRefFmncMPerson = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint pcoRefFmncMOrg;
	ubigint splRefFmncMOrg;
	ubigint refFmncMFile;
	string sref;
	uint Date;
	ubigint refJState;
	uint ixVState;
	double Amount;
	ubigint pcpRefFmncMPerson;
	string Comment;

public:
	bool operator==(const FmncMPurchorder& comp);
	bool operator!=(const FmncMPurchorder& comp);
};

/**
  * ListFmncMPurchorder: recordset of TblFmncMPurchorder
  */
class ListFmncMPurchorder {

public:
	ListFmncMPurchorder();
	ListFmncMPurchorder(const ListFmncMPurchorder& src);
	~ListFmncMPurchorder();

	void clear();
	unsigned int size() const;
	void append(FmncMPurchorder* rec);

	FmncMPurchorder* operator[](const uint ix);
	ListFmncMPurchorder& operator=(const ListFmncMPurchorder& src);
	bool operator==(const ListFmncMPurchorder& comp);
	bool operator!=(const ListFmncMPurchorder& comp);

public:
	vector<FmncMPurchorder*> nodes;
};

/**
  * TblFmncMPurchorder: C++ wrapper for table TblFmncMPurchorder
  */
class TblFmncMPurchorder {

public:
	TblFmncMPurchorder();
	virtual ~TblFmncMPurchorder();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMPurchorder** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMPurchorder& rst);

	virtual void insertRec(FmncMPurchorder* rec);
	ubigint insertNewRec(FmncMPurchorder** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint pcoRefFmncMOrg = 0, const ubigint splRefFmncMOrg = 0, const ubigint refFmncMFile = 0, const string sref = "", const uint Date = 0, const ubigint refJState = 0, const uint ixVState = 0, const double Amount = 0.0, const ubigint pcpRefFmncMPerson = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMPurchorder& rst, FmncMPurchorder** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint pcoRefFmncMOrg = 0, const ubigint splRefFmncMOrg = 0, const ubigint refFmncMFile = 0, const string sref = "", const uint Date = 0, const ubigint refJState = 0, const uint ixVState = 0, const double Amount = 0.0, const ubigint pcpRefFmncMPerson = 0, const string Comment = "");
	virtual void insertRst(ListFmncMPurchorder& rst, bool transact = false);
	virtual void updateRec(FmncMPurchorder* rec);
	virtual void updateRst(ListFmncMPurchorder& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMPurchorder** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMPurchorder& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMPurchorder: C++ wrapper for table TblFmncMPurchorder (MySQL database)
  */
class MyTblFmncMPurchorder : public TblFmncMPurchorder, public MyTable {

public:
	MyTblFmncMPurchorder();
	~MyTblFmncMPurchorder();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMPurchorder** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMPurchorder& rst);

	void insertRec(FmncMPurchorder* rec);
	void insertRst(ListFmncMPurchorder& rst, bool transact = false);
	void updateRec(FmncMPurchorder* rec);
	void updateRst(ListFmncMPurchorder& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMPurchorder** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMPurchorder: C++ wrapper for table TblFmncMPurchorder (PgSQL database)
  */
class PgTblFmncMPurchorder : public TblFmncMPurchorder, public PgTable {

public:
	PgTblFmncMPurchorder();
	~PgTblFmncMPurchorder();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMPurchorder** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMPurchorder& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMPurchorder** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMPurchorder** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMPurchorder& rst);

	void insertRec(FmncMPurchorder* rec);
	void insertRst(ListFmncMPurchorder& rst, bool transact = false);
	void updateRec(FmncMPurchorder* rec);
	void updateRst(ListFmncMPurchorder& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMPurchorder** rec);
};
// IP pgTbl --- END

#endif

