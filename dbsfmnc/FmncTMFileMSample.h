/**
  * \file FmncTMFileMSample.h
  * database access for table TblFmncTMFileMSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCTMFILEMSAMPLE_H
#define FMNCTMFILEMSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncTMFileMSample: record of TblFmncTMFileMSample
  */
class FmncTMFileMSample {

public:
	FmncTMFileMSample(const ubigint ref = 0, const ubigint refFmncMSample = 0, const ubigint refR = 0);

public:
	ubigint ref;
	ubigint refFmncMSample;
	ubigint refR;

public:
	bool operator==(const FmncTMFileMSample& comp);
	bool operator!=(const FmncTMFileMSample& comp);
};

/**
  * ListFmncTMFileMSample: recordset of TblFmncTMFileMSample
  */
class ListFmncTMFileMSample {

public:
	ListFmncTMFileMSample();
	ListFmncTMFileMSample(const ListFmncTMFileMSample& src);
	~ListFmncTMFileMSample();

	void clear();
	unsigned int size() const;
	void append(FmncTMFileMSample* rec);

	FmncTMFileMSample* operator[](const uint ix);
	ListFmncTMFileMSample& operator=(const ListFmncTMFileMSample& src);
	bool operator==(const ListFmncTMFileMSample& comp);
	bool operator!=(const ListFmncTMFileMSample& comp);

public:
	vector<FmncTMFileMSample*> nodes;
};

/**
  * TblFmncTMFileMSample: C++ wrapper for table TblFmncTMFileMSample
  */
class TblFmncTMFileMSample {

public:
	TblFmncTMFileMSample();
	virtual ~TblFmncTMFileMSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncTMFileMSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncTMFileMSample& rst);

	virtual void insertRec(FmncTMFileMSample* rec);
	ubigint insertNewRec(FmncTMFileMSample** rec = NULL, const ubigint refFmncMSample = 0, const ubigint refR = 0);
	ubigint appendNewRecToRst(ListFmncTMFileMSample& rst, FmncTMFileMSample** rec = NULL, const ubigint refFmncMSample = 0, const ubigint refR = 0);
	virtual void insertRst(ListFmncTMFileMSample& rst, bool transact = false);
	virtual void updateRec(FmncTMFileMSample* rec);
	virtual void updateRst(ListFmncTMFileMSample& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncTMFileMSample** rec);
	virtual ubigint loadRefsByR(ubigint refR, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByR(ubigint refR, const bool append, ListFmncTMFileMSample& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncTMFileMSample& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncTMFileMSample: C++ wrapper for table TblFmncTMFileMSample (MySQL database)
  */
class MyTblFmncTMFileMSample : public TblFmncTMFileMSample, public MyTable {

public:
	MyTblFmncTMFileMSample();
	~MyTblFmncTMFileMSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncTMFileMSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncTMFileMSample& rst);

	void insertRec(FmncTMFileMSample* rec);
	void insertRst(ListFmncTMFileMSample& rst, bool transact = false);
	void updateRec(FmncTMFileMSample* rec);
	void updateRst(ListFmncTMFileMSample& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncTMFileMSample** rec);
	ubigint loadRefsByR(ubigint refR, const bool append, vector<ubigint>& refs);
	ubigint loadRstByR(ubigint refR, const bool append, ListFmncTMFileMSample& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncTMFileMSample: C++ wrapper for table TblFmncTMFileMSample (PgSQL database)
  */
class PgTblFmncTMFileMSample : public TblFmncTMFileMSample, public PgTable {

public:
	PgTblFmncTMFileMSample();
	~PgTblFmncTMFileMSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncTMFileMSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncTMFileMSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncTMFileMSample** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncTMFileMSample& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncTMFileMSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncTMFileMSample& rst);

	void insertRec(FmncTMFileMSample* rec);
	void insertRst(ListFmncTMFileMSample& rst, bool transact = false);
	void updateRec(FmncTMFileMSample* rec);
	void updateRst(ListFmncTMFileMSample& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncTMFileMSample** rec);
	ubigint loadRefsByR(ubigint refR, const bool append, vector<ubigint>& refs);
	ubigint loadRstByR(ubigint refR, const bool append, ListFmncTMFileMSample& rst);
};
// IP pgTbl --- END

#endif

