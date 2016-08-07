/**
  * \file FmncAVValuelistVal.h
  * database access for table TblFmncAVValuelistVal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCAVVALUELISTVAL_H
#define FMNCAVVALUELISTVAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncAVValuelistVal: record of TblFmncAVValuelistVal
  */
class FmncAVValuelistVal {

public:
	FmncAVValuelistVal(const ubigint ref = 0, const uint vlsIxFmncVValuelist = 0, const uint vlsNum = 0, const uint x1IxFmncVLocale = 0, const string Val = "");

public:
	ubigint ref;
	uint vlsIxFmncVValuelist;
	uint vlsNum;
	uint x1IxFmncVLocale;
	string Val;

public:
	bool operator==(const FmncAVValuelistVal& comp);
	bool operator!=(const FmncAVValuelistVal& comp);
};

/**
  * ListFmncAVValuelistVal: recordset of TblFmncAVValuelistVal
  */
class ListFmncAVValuelistVal {

public:
	ListFmncAVValuelistVal();
	ListFmncAVValuelistVal(const ListFmncAVValuelistVal& src);
	~ListFmncAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(FmncAVValuelistVal* rec);

	FmncAVValuelistVal* operator[](const uint ix);
	ListFmncAVValuelistVal& operator=(const ListFmncAVValuelistVal& src);
	bool operator==(const ListFmncAVValuelistVal& comp);
	bool operator!=(const ListFmncAVValuelistVal& comp);

public:
	vector<FmncAVValuelistVal*> nodes;
};

/**
  * TblFmncAVValuelistVal: C++ wrapper for table TblFmncAVValuelistVal
  */
class TblFmncAVValuelistVal {

public:
	TblFmncAVValuelistVal();
	virtual ~TblFmncAVValuelistVal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncAVValuelistVal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVValuelistVal& rst);

	virtual void insertRec(FmncAVValuelistVal* rec);
	ubigint insertNewRec(FmncAVValuelistVal** rec = NULL, const uint vlsIxFmncVValuelist = 0, const uint vlsNum = 0, const uint x1IxFmncVLocale = 0, const string Val = "");
	ubigint appendNewRecToRst(ListFmncAVValuelistVal& rst, FmncAVValuelistVal** rec = NULL, const uint vlsIxFmncVValuelist = 0, const uint vlsNum = 0, const uint x1IxFmncVLocale = 0, const string Val = "");
	virtual void insertRst(ListFmncAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(FmncAVValuelistVal* rec);
	virtual void updateRst(ListFmncAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncAVValuelistVal** rec);
	virtual ubigint loadRstByVlsLcl(uint vlsIxFmncVValuelist, uint x1IxFmncVLocale, const bool append, ListFmncAVValuelistVal& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncAVValuelistVal& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncAVValuelistVal: C++ wrapper for table TblFmncAVValuelistVal (MySQL database)
  */
class MyTblFmncAVValuelistVal : public TblFmncAVValuelistVal, public MyTable {

public:
	MyTblFmncAVValuelistVal();
	~MyTblFmncAVValuelistVal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncAVValuelistVal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVValuelistVal& rst);

	void insertRec(FmncAVValuelistVal* rec);
	void insertRst(ListFmncAVValuelistVal& rst, bool transact = false);
	void updateRec(FmncAVValuelistVal* rec);
	void updateRst(ListFmncAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAVValuelistVal** rec);
	ubigint loadRstByVlsLcl(uint vlsIxFmncVValuelist, uint x1IxFmncVLocale, const bool append, ListFmncAVValuelistVal& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncAVValuelistVal: C++ wrapper for table TblFmncAVValuelistVal (PgSQL database)
  */
class PgTblFmncAVValuelistVal : public TblFmncAVValuelistVal, public PgTable {

public:
	PgTblFmncAVValuelistVal();
	~PgTblFmncAVValuelistVal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncAVValuelistVal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncAVValuelistVal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncAVValuelistVal** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncAVValuelistVal& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncAVValuelistVal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncAVValuelistVal& rst);

	void insertRec(FmncAVValuelistVal* rec);
	void insertRst(ListFmncAVValuelistVal& rst, bool transact = false);
	void updateRec(FmncAVValuelistVal* rec);
	void updateRst(ListFmncAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncAVValuelistVal** rec);
	ubigint loadRstByVlsLcl(uint vlsIxFmncVValuelist, uint x1IxFmncVLocale, const bool append, ListFmncAVValuelistVal& rst);
};
// IP pgTbl --- END

#endif

