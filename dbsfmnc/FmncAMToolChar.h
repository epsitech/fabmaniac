/**
  * \file FmncAMToolChar.h
  * database access for table TblFmncAMToolChar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAMTOOLCHAR_H
#define FMNCAMTOOLCHAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAMToolChar: record of TblFmncAMToolChar
  */
class FmncAMToolChar {

public:
	FmncAMToolChar(const ubigint ref = 0, const ubigint refFmncMTool = 0, const string x1OsrefFmncKToolchar = "", const string Val = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refFmncMTool;
	string x1OsrefFmncKToolchar;
	string Val;
	string Comment;

public:
	bool operator==(const FmncAMToolChar& comp);
	bool operator!=(const FmncAMToolChar& comp);
};

/**
  * ListFmncAMToolChar: recordset of TblFmncAMToolChar
  */
class ListFmncAMToolChar {

public:
	ListFmncAMToolChar();
	ListFmncAMToolChar(const ListFmncAMToolChar& src);
	~ListFmncAMToolChar();

	void clear();
	unsigned int size() const;
	void append(FmncAMToolChar* rec);

	FmncAMToolChar* operator[](const uint ix);
	ListFmncAMToolChar& operator=(const ListFmncAMToolChar& src);
	bool operator==(const ListFmncAMToolChar& comp);
	bool operator!=(const ListFmncAMToolChar& comp);

public:
	vector<FmncAMToolChar*> nodes;
};

/**
  * TblFmncAMToolChar: C++ wrapper for table TblFmncAMToolChar
  */
class TblFmncAMToolChar {

public:
	TblFmncAMToolChar();
	virtual ~TblFmncAMToolChar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAMToolChar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolChar& rst);

	virtual void insertRec(FmncAMToolChar* rec);
	ubigint insertNewRec(FmncAMToolChar** rec = NULL, const ubigint refFmncMTool = 0, const string x1OsrefFmncKToolchar = "", const string Val = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncAMToolChar& rst, FmncAMToolChar** rec = NULL, const ubigint refFmncMTool = 0, const string x1OsrefFmncKToolchar = "", const string Val = "", const string Comment = "");
	virtual void insertRst(ListFmncAMToolChar& rst, bool transact = false);
	virtual void updateRec(FmncAMToolChar* rec);
	virtual void updateRst(ListFmncAMToolChar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAMToolChar** rec);
	virtual ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAMToolChar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAMToolChar: C++ wrapper for table TblFmncAMToolChar (MySQL database)
  */
class MyTblFmncAMToolChar : public TblFmncAMToolChar, public MyTable {

public:
	MyTblFmncAMToolChar();
	~MyTblFmncAMToolChar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMToolChar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolChar& rst);

	void insertRec(FmncAMToolChar* rec);
	void insertRst(ListFmncAMToolChar& rst, bool transact = false);
	void updateRec(FmncAMToolChar* rec);
	void updateRst(ListFmncAMToolChar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMToolChar** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAMToolChar: C++ wrapper for table TblFmncAMToolChar (PgSQL database)
  */
class PgTblFmncAMToolChar : public TblFmncAMToolChar, public PgTable {

public:
	PgTblFmncAMToolChar();
	~PgTblFmncAMToolChar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAMToolChar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAMToolChar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAMToolChar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncAMToolChar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAMToolChar& rst);

	void insertRec(FmncAMToolChar* rec);
	void insertRst(ListFmncAMToolChar& rst, bool transact = false);
	void updateRec(FmncAMToolChar* rec);
	void updateRst(ListFmncAMToolChar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAMToolChar** rec);
	ubigint loadRefsByTol(ubigint refFmncMTool, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

