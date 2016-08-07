/**
  * \file FmncMTool.h
  * database access for table TblFmncMTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMTOOL_H
#define FMNCMTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMTool: record of TblFmncMTool
  */
class FmncMTool {

public:
	FmncMTool(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint fabRefFmncMFab = 0, const ubigint mnfRefFmncMOrg = 0, const string Title = "", const ubigint refJUnitprice = 0, const double Unitprice = 0.0, const string Training = "", const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint fabRefFmncMFab;
	ubigint mnfRefFmncMOrg;
	string Title;
	ubigint refJUnitprice;
	double Unitprice;
	string Training;
	string Comment;

public:
	bool operator==(const FmncMTool& comp);
	bool operator!=(const FmncMTool& comp);
};

/**
  * ListFmncMTool: recordset of TblFmncMTool
  */
class ListFmncMTool {

public:
	ListFmncMTool();
	ListFmncMTool(const ListFmncMTool& src);
	~ListFmncMTool();

	void clear();
	unsigned int size() const;
	void append(FmncMTool* rec);

	FmncMTool* operator[](const uint ix);
	ListFmncMTool& operator=(const ListFmncMTool& src);
	bool operator==(const ListFmncMTool& comp);
	bool operator!=(const ListFmncMTool& comp);

public:
	vector<FmncMTool*> nodes;
};

/**
  * TblFmncMTool: C++ wrapper for table TblFmncMTool
  */
class TblFmncMTool {

public:
	TblFmncMTool();
	virtual ~TblFmncMTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMTool& rst);

	virtual void insertRec(FmncMTool* rec);
	ubigint insertNewRec(FmncMTool** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint fabRefFmncMFab = 0, const ubigint mnfRefFmncMOrg = 0, const string Title = "", const ubigint refJUnitprice = 0, const double Unitprice = 0.0, const string Training = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMTool& rst, FmncMTool** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint fabRefFmncMFab = 0, const ubigint mnfRefFmncMOrg = 0, const string Title = "", const ubigint refJUnitprice = 0, const double Unitprice = 0.0, const string Training = "", const string Comment = "");
	virtual void insertRst(ListFmncMTool& rst, bool transact = false);
	virtual void updateRec(FmncMTool* rec);
	virtual void updateRst(ListFmncMTool& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMTool** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMTool: C++ wrapper for table TblFmncMTool (MySQL database)
  */
class MyTblFmncMTool : public TblFmncMTool, public MyTable {

public:
	MyTblFmncMTool();
	~MyTblFmncMTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMTool& rst);

	void insertRec(FmncMTool* rec);
	void insertRst(ListFmncMTool& rst, bool transact = false);
	void updateRec(FmncMTool* rec);
	void updateRst(ListFmncMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMTool** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMTool: C++ wrapper for table TblFmncMTool (PgSQL database)
  */
class PgTblFmncMTool : public TblFmncMTool, public PgTable {

public:
	PgTblFmncMTool();
	~PgTblFmncMTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMTool** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMTool& rst);

	void insertRec(FmncMTool* rec);
	void insertRst(ListFmncMTool& rst, bool transact = false);
	void updateRec(FmncMTool* rec);
	void updateRst(ListFmncMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMTool** rec);
};
// IP pgTbl --- END

#endif

