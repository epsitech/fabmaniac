/**
  * \file FmncAVKeylistKey.h
  * database access for table TblFmncAVKeylistKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAVKEYLISTKEY_H
#define FMNCAVKEYLISTKEY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAVKeylistKey: record of TblFmncAVKeylistKey
  */
class FmncAVKeylistKey {

public:
	FmncAVKeylistKey(const ubigint ref = 0, const uint klsIxFmncVKeylist = 0, const uint klsNum = 0, const uint x1IxFmncVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	uint klsIxFmncVKeylist;
	uint klsNum;
	uint x1IxFmncVMaintable;
	ubigint x1Uref;
	bool Fixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	bool operator==(const FmncAVKeylistKey& comp);
	bool operator!=(const FmncAVKeylistKey& comp);
};

/**
  * ListFmncAVKeylistKey: recordset of TblFmncAVKeylistKey
  */
class ListFmncAVKeylistKey {

public:
	ListFmncAVKeylistKey();
	ListFmncAVKeylistKey(const ListFmncAVKeylistKey& src);
	~ListFmncAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(FmncAVKeylistKey* rec);

	FmncAVKeylistKey* operator[](const uint ix);
	ListFmncAVKeylistKey& operator=(const ListFmncAVKeylistKey& src);
	bool operator==(const ListFmncAVKeylistKey& comp);
	bool operator!=(const ListFmncAVKeylistKey& comp);

public:
	vector<FmncAVKeylistKey*> nodes;
};

/**
  * TblFmncAVKeylistKey: C++ wrapper for table TblFmncAVKeylistKey
  */
class TblFmncAVKeylistKey {

public:
	TblFmncAVKeylistKey();
	virtual ~TblFmncAVKeylistKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAVKeylistKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVKeylistKey& rst);

	virtual void insertRec(FmncAVKeylistKey* rec);
	ubigint insertNewRec(FmncAVKeylistKey** rec = NULL, const uint klsIxFmncVKeylist = 0, const uint klsNum = 0, const uint x1IxFmncVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncAVKeylistKey& rst, FmncAVKeylistKey** rec = NULL, const uint klsIxFmncVKeylist = 0, const uint klsNum = 0, const uint x1IxFmncVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(FmncAVKeylistKey* rec);
	virtual void updateRst(ListFmncAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(uint klsIxFmncVKeylist, uint x1IxFmncVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	virtual bool loadRefByKlsSrf(uint klsIxFmncVKeylist, string sref, ubigint& ref);
	virtual ubigint loadRefsByMtbUrf(uint x1IxFmncVMaintable, ubigint x1Uref, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByKls(uint klsIxFmncVKeylist, const bool append, ListFmncAVKeylistKey& rst);
	virtual ubigint loadRstByKlsMtbUrf(uint klsIxFmncVKeylist, uint x1IxFmncVMaintable, ubigint x1Uref, const bool append, ListFmncAVKeylistKey& rst);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAVKeylistKey& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAVKeylistKey: C++ wrapper for table TblFmncAVKeylistKey (MySQL database)
  */
class MyTblFmncAVKeylistKey : public TblFmncAVKeylistKey, public MyTable {

public:
	MyTblFmncAVKeylistKey();
	~MyTblFmncAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVKeylistKey& rst);

	void insertRec(FmncAVKeylistKey* rec);
	void insertRst(ListFmncAVKeylistKey& rst, bool transact = false);
	void updateRec(FmncAVKeylistKey* rec);
	void updateRst(ListFmncAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(uint klsIxFmncVKeylist, uint x1IxFmncVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	bool loadRefByKlsSrf(uint klsIxFmncVKeylist, string sref, ubigint& ref);
	ubigint loadRefsByMtbUrf(uint x1IxFmncVMaintable, ubigint x1Uref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKls(uint klsIxFmncVKeylist, const bool append, ListFmncAVKeylistKey& rst);
	ubigint loadRstByKlsMtbUrf(uint klsIxFmncVKeylist, uint x1IxFmncVMaintable, ubigint x1Uref, const bool append, ListFmncAVKeylistKey& rst);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAVKeylistKey: C++ wrapper for table TblFmncAVKeylistKey (PgSQL database)
  */
class PgTblFmncAVKeylistKey : public TblFmncAVKeylistKey, public PgTable {

public:
	PgTblFmncAVKeylistKey();
	~PgTblFmncAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAVKeylistKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAVKeylistKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAVKeylistKey** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncAVKeylistKey& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVKeylistKey& rst);

	void insertRec(FmncAVKeylistKey* rec);
	void insertRst(ListFmncAVKeylistKey& rst, bool transact = false);
	void updateRec(FmncAVKeylistKey* rec);
	void updateRst(ListFmncAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(uint klsIxFmncVKeylist, uint x1IxFmncVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	bool loadRefByKlsSrf(uint klsIxFmncVKeylist, string sref, ubigint& ref);
	ubigint loadRefsByMtbUrf(uint x1IxFmncVMaintable, ubigint x1Uref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKls(uint klsIxFmncVKeylist, const bool append, ListFmncAVKeylistKey& rst);
	ubigint loadRstByKlsMtbUrf(uint klsIxFmncVKeylist, uint x1IxFmncVMaintable, ubigint x1Uref, const bool append, ListFmncAVKeylistKey& rst);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

