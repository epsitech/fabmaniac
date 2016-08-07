/**
  * \file FmncRMToolMTooltype.h
  * database access for table TblFmncRMToolMTooltype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMTOOLMTOOLTYPE_H
#define FMNCRMTOOLMTOOLTYPE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMToolMTooltype: record of TblFmncRMToolMTooltype
  */
class FmncRMToolMTooltype {

public:
	FmncRMToolMTooltype(const ubigint ref = 0, const ubigint refFmncMTool = 0, const ubigint refFmncMTooltype = 0, const string srefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "");

public:
	ubigint ref;
	ubigint refFmncMTool;
	ubigint refFmncMTooltype;
	string srefsFmncKToolchar;
	string defSrefsFmncKSteppar;
	string optSrefsFmncKSteppar;

public:
	bool operator==(const FmncRMToolMTooltype& comp);
	bool operator!=(const FmncRMToolMTooltype& comp);
};

/**
  * ListFmncRMToolMTooltype: recordset of TblFmncRMToolMTooltype
  */
class ListFmncRMToolMTooltype {

public:
	ListFmncRMToolMTooltype();
	ListFmncRMToolMTooltype(const ListFmncRMToolMTooltype& src);
	~ListFmncRMToolMTooltype();

	void clear();
	unsigned int size() const;
	void append(FmncRMToolMTooltype* rec);

	FmncRMToolMTooltype* operator[](const uint ix);
	ListFmncRMToolMTooltype& operator=(const ListFmncRMToolMTooltype& src);
	bool operator==(const ListFmncRMToolMTooltype& comp);
	bool operator!=(const ListFmncRMToolMTooltype& comp);

public:
	vector<FmncRMToolMTooltype*> nodes;
};

/**
  * TblFmncRMToolMTooltype: C++ wrapper for table TblFmncRMToolMTooltype
  */
class TblFmncRMToolMTooltype {

public:
	TblFmncRMToolMTooltype();
	virtual ~TblFmncRMToolMTooltype();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMToolMTooltype** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMToolMTooltype& rst);

	virtual void insertRec(FmncRMToolMTooltype* rec);
	ubigint insertNewRec(FmncRMToolMTooltype** rec = NULL, const ubigint refFmncMTool = 0, const ubigint refFmncMTooltype = 0, const string srefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "");
	ubigint appendNewRecToRst(ListFmncRMToolMTooltype& rst, FmncRMToolMTooltype** rec = NULL, const ubigint refFmncMTool = 0, const ubigint refFmncMTooltype = 0, const string srefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "");
	virtual void insertRst(ListFmncRMToolMTooltype& rst, bool transact = false);
	virtual void updateRec(FmncRMToolMTooltype* rec);
	virtual void updateRst(ListFmncRMToolMTooltype& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMToolMTooltype** rec);
	virtual ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMToolMTooltype& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMToolMTooltype: C++ wrapper for table TblFmncRMToolMTooltype (MySQL database)
  */
class MyTblFmncRMToolMTooltype : public TblFmncRMToolMTooltype, public MyTable {

public:
	MyTblFmncRMToolMTooltype();
	~MyTblFmncRMToolMTooltype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMToolMTooltype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMToolMTooltype& rst);

	void insertRec(FmncRMToolMTooltype* rec);
	void insertRst(ListFmncRMToolMTooltype& rst, bool transact = false);
	void updateRec(FmncRMToolMTooltype* rec);
	void updateRst(ListFmncRMToolMTooltype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMToolMTooltype** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMToolMTooltype: C++ wrapper for table TblFmncRMToolMTooltype (PgSQL database)
  */
class PgTblFmncRMToolMTooltype : public TblFmncRMToolMTooltype, public PgTable {

public:
	PgTblFmncRMToolMTooltype();
	~PgTblFmncRMToolMTooltype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMToolMTooltype** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMToolMTooltype& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMToolMTooltype** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMToolMTooltype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMToolMTooltype& rst);

	void insertRec(FmncRMToolMTooltype* rec);
	void insertRst(ListFmncRMToolMTooltype& rst, bool transact = false);
	void updateRec(FmncRMToolMTooltype* rec);
	void updateRst(ListFmncRMToolMTooltype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMToolMTooltype** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

