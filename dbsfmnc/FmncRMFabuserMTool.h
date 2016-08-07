/**
  * \file FmncRMFabuserMTool.h
  * database access for table TblFmncRMFabuserMTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMFABUSERMTOOL_H
#define FMNCRMFABUSERMTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMFabuserMTool: record of TblFmncRMFabuserMTool
  */
class FmncRMFabuserMTool {

public:
	FmncRMFabuserMTool(const ubigint ref = 0, const ubigint refFmncMFabuser = 0, const ubigint refFmncMTool = 0, const ubigint trnRefFmncMPerson = 0, const string srefKLvl = "");

public:
	ubigint ref;
	ubigint refFmncMFabuser;
	ubigint refFmncMTool;
	ubigint trnRefFmncMPerson;
	string srefKLvl;

public:
	bool operator==(const FmncRMFabuserMTool& comp);
	bool operator!=(const FmncRMFabuserMTool& comp);
};

/**
  * ListFmncRMFabuserMTool: recordset of TblFmncRMFabuserMTool
  */
class ListFmncRMFabuserMTool {

public:
	ListFmncRMFabuserMTool();
	ListFmncRMFabuserMTool(const ListFmncRMFabuserMTool& src);
	~ListFmncRMFabuserMTool();

	void clear();
	unsigned int size() const;
	void append(FmncRMFabuserMTool* rec);

	FmncRMFabuserMTool* operator[](const uint ix);
	ListFmncRMFabuserMTool& operator=(const ListFmncRMFabuserMTool& src);
	bool operator==(const ListFmncRMFabuserMTool& comp);
	bool operator!=(const ListFmncRMFabuserMTool& comp);

public:
	vector<FmncRMFabuserMTool*> nodes;
};

/**
  * TblFmncRMFabuserMTool: C++ wrapper for table TblFmncRMFabuserMTool
  */
class TblFmncRMFabuserMTool {

public:
	TblFmncRMFabuserMTool();
	virtual ~TblFmncRMFabuserMTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMFabuserMTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabuserMTool& rst);

	virtual void insertRec(FmncRMFabuserMTool* rec);
	ubigint insertNewRec(FmncRMFabuserMTool** rec = NULL, const ubigint refFmncMFabuser = 0, const ubigint refFmncMTool = 0, const ubigint trnRefFmncMPerson = 0, const string srefKLvl = "");
	ubigint appendNewRecToRst(ListFmncRMFabuserMTool& rst, FmncRMFabuserMTool** rec = NULL, const ubigint refFmncMFabuser = 0, const ubigint refFmncMTool = 0, const ubigint trnRefFmncMPerson = 0, const string srefKLvl = "");
	virtual void insertRst(ListFmncRMFabuserMTool& rst, bool transact = false);
	virtual void updateRec(FmncRMFabuserMTool* rec);
	virtual void updateRst(ListFmncRMFabuserMTool& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMFabuserMTool** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMFabuserMTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMFabuserMTool: C++ wrapper for table TblFmncRMFabuserMTool (MySQL database)
  */
class MyTblFmncRMFabuserMTool : public TblFmncRMFabuserMTool, public MyTable {

public:
	MyTblFmncRMFabuserMTool();
	~MyTblFmncRMFabuserMTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFabuserMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabuserMTool& rst);

	void insertRec(FmncRMFabuserMTool* rec);
	void insertRst(ListFmncRMFabuserMTool& rst, bool transact = false);
	void updateRec(FmncRMFabuserMTool* rec);
	void updateRst(ListFmncRMFabuserMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFabuserMTool** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMFabuserMTool: C++ wrapper for table TblFmncRMFabuserMTool (PgSQL database)
  */
class PgTblFmncRMFabuserMTool : public TblFmncRMFabuserMTool, public PgTable {

public:
	PgTblFmncRMFabuserMTool();
	~PgTblFmncRMFabuserMTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMFabuserMTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMFabuserMTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMFabuserMTool** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFabuserMTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFabuserMTool& rst);

	void insertRec(FmncRMFabuserMTool* rec);
	void insertRst(ListFmncRMFabuserMTool& rst, bool transact = false);
	void updateRec(FmncRMFabuserMTool* rec);
	void updateRst(ListFmncRMFabuserMTool& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFabuserMTool** rec);
};
// IP pgTbl --- END

#endif

