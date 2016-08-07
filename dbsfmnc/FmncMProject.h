/**
  * \file FmncMProject.h
  * database access for table TblFmncMProject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMPROJECT_H
#define FMNCMPROJECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMProject: record of TblFmncMProject
  */
class FmncMProject {

public:
	FmncMProject(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	string Title;
	ubigint refJState;
	uint ixVState;
	string Comment;

public:
	bool operator==(const FmncMProject& comp);
	bool operator!=(const FmncMProject& comp);
};

/**
  * ListFmncMProject: recordset of TblFmncMProject
  */
class ListFmncMProject {

public:
	ListFmncMProject();
	ListFmncMProject(const ListFmncMProject& src);
	~ListFmncMProject();

	void clear();
	unsigned int size() const;
	void append(FmncMProject* rec);

	FmncMProject* operator[](const uint ix);
	ListFmncMProject& operator=(const ListFmncMProject& src);
	bool operator==(const ListFmncMProject& comp);
	bool operator!=(const ListFmncMProject& comp);

public:
	vector<FmncMProject*> nodes;
};

/**
  * TblFmncMProject: C++ wrapper for table TblFmncMProject
  */
class TblFmncMProject {

public:
	TblFmncMProject();
	virtual ~TblFmncMProject();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMProject** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMProject& rst);

	virtual void insertRec(FmncMProject* rec);
	ubigint insertNewRec(FmncMProject** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMProject& rst, FmncMProject** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");
	virtual void insertRst(ListFmncMProject& rst, bool transact = false);
	virtual void updateRec(FmncMProject* rec);
	virtual void updateRst(ListFmncMProject& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMProject** rec);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMProject& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMProject: C++ wrapper for table TblFmncMProject (MySQL database)
  */
class MyTblFmncMProject : public TblFmncMProject, public MyTable {

public:
	MyTblFmncMProject();
	~MyTblFmncMProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMProject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMProject& rst);

	void insertRec(FmncMProject* rec);
	void insertRst(ListFmncMProject& rst, bool transact = false);
	void updateRec(FmncMProject* rec);
	void updateRst(ListFmncMProject& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMProject** rec);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMProject: C++ wrapper for table TblFmncMProject (PgSQL database)
  */
class PgTblFmncMProject : public TblFmncMProject, public PgTable {

public:
	PgTblFmncMProject();
	~PgTblFmncMProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMProject** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMProject& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMProject** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMProject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMProject& rst);

	void insertRec(FmncMProject* rec);
	void insertRst(ListFmncMProject& rst, bool transact = false);
	void updateRec(FmncMProject* rec);
	void updateRst(ListFmncMProject& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMProject** rec);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

