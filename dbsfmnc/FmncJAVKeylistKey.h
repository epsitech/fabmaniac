/**
  * \file FmncJAVKeylistKey.h
  * database access for table TblFmncJAVKeylistKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCJAVKEYLISTKEY_H
#define FMNCJAVKEYLISTKEY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncJAVKeylistKey: record of TblFmncJAVKeylistKey
  */
class FmncJAVKeylistKey {

public:
	FmncJAVKeylistKey(const ubigint ref = 0, const ubigint refFmncAVKeylistKey = 0, const uint x1IxFmncVLocale = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refFmncAVKeylistKey;
	uint x1IxFmncVLocale;
	string Title;
	string Comment;

public:
	bool operator==(const FmncJAVKeylistKey& comp);
	bool operator!=(const FmncJAVKeylistKey& comp);
};

/**
  * ListFmncJAVKeylistKey: recordset of TblFmncJAVKeylistKey
  */
class ListFmncJAVKeylistKey {

public:
	ListFmncJAVKeylistKey();
	ListFmncJAVKeylistKey(const ListFmncJAVKeylistKey& src);
	~ListFmncJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(FmncJAVKeylistKey* rec);

	FmncJAVKeylistKey* operator[](const uint ix);
	ListFmncJAVKeylistKey& operator=(const ListFmncJAVKeylistKey& src);
	bool operator==(const ListFmncJAVKeylistKey& comp);
	bool operator!=(const ListFmncJAVKeylistKey& comp);

public:
	vector<FmncJAVKeylistKey*> nodes;
};

/**
  * TblFmncJAVKeylistKey: C++ wrapper for table TblFmncJAVKeylistKey
  */
class TblFmncJAVKeylistKey {

public:
	TblFmncJAVKeylistKey();
	virtual ~TblFmncJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncJAVKeylistKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJAVKeylistKey& rst);

	virtual void insertRec(FmncJAVKeylistKey* rec);
	ubigint insertNewRec(FmncJAVKeylistKey** rec = NULL, const ubigint refFmncAVKeylistKey = 0, const uint x1IxFmncVLocale = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncJAVKeylistKey& rst, FmncJAVKeylistKey** rec = NULL, const ubigint refFmncAVKeylistKey = 0, const uint x1IxFmncVLocale = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(FmncJAVKeylistKey* rec);
	virtual void updateRst(ListFmncJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(ubigint refFmncAVKeylistKey, uint x1IxFmncVLocale, FmncJAVKeylistKey** rec);
	virtual ubigint loadRefsByKlk(ubigint refFmncAVKeylistKey, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByKlk(ubigint refFmncAVKeylistKey, const bool append, ListFmncJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(ubigint refFmncAVKeylistKey, uint x1IxFmncVLocale, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncJAVKeylistKey& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncJAVKeylistKey: C++ wrapper for table TblFmncJAVKeylistKey (MySQL database)
  */
class MyTblFmncJAVKeylistKey : public TblFmncJAVKeylistKey, public MyTable {

public:
	MyTblFmncJAVKeylistKey();
	~MyTblFmncJAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncJAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJAVKeylistKey& rst);

	void insertRec(FmncJAVKeylistKey* rec);
	void insertRst(ListFmncJAVKeylistKey& rst, bool transact = false);
	void updateRec(FmncJAVKeylistKey* rec);
	void updateRst(ListFmncJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJAVKeylistKey** rec);
	bool loadRecByKlkLcl(ubigint refFmncAVKeylistKey, uint x1IxFmncVLocale, FmncJAVKeylistKey** rec);
	ubigint loadRefsByKlk(ubigint refFmncAVKeylistKey, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKlk(ubigint refFmncAVKeylistKey, const bool append, ListFmncJAVKeylistKey& rst);
	bool loadTitByKlkLcl(ubigint refFmncAVKeylistKey, uint x1IxFmncVLocale, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncJAVKeylistKey: C++ wrapper for table TblFmncJAVKeylistKey (PgSQL database)
  */
class PgTblFmncJAVKeylistKey : public TblFmncJAVKeylistKey, public PgTable {

public:
	PgTblFmncJAVKeylistKey();
	~PgTblFmncJAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncJAVKeylistKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncJAVKeylistKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncJAVKeylistKey** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncJAVKeylistKey& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncJAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncJAVKeylistKey& rst);

	void insertRec(FmncJAVKeylistKey* rec);
	void insertRst(ListFmncJAVKeylistKey& rst, bool transact = false);
	void updateRec(FmncJAVKeylistKey* rec);
	void updateRst(ListFmncJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncJAVKeylistKey** rec);
	bool loadRecByKlkLcl(ubigint refFmncAVKeylistKey, uint x1IxFmncVLocale, FmncJAVKeylistKey** rec);
	ubigint loadRefsByKlk(ubigint refFmncAVKeylistKey, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKlk(ubigint refFmncAVKeylistKey, const bool append, ListFmncJAVKeylistKey& rst);
	bool loadTitByKlkLcl(ubigint refFmncAVKeylistKey, uint x1IxFmncVLocale, string& val);
};
// IP pgTbl --- END

#endif

