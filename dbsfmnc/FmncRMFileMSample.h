/**
  * \file FmncRMFileMSample.h
  * database access for table TblFmncRMFileMSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCRMFILEMSAMPLE_H
#define FMNCRMFILEMSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncRMFileMSample: record of TblFmncRMFileMSample
  */
class FmncRMFileMSample {

public:
	FmncRMFileMSample(const ubigint ref = 0, const ubigint refFmncMFile = 0, const ubigint refFmncMSample = 0);

public:
	ubigint ref;
	ubigint refFmncMFile;
	ubigint refFmncMSample;

public:
	bool operator==(const FmncRMFileMSample& comp);
	bool operator!=(const FmncRMFileMSample& comp);
};

/**
  * ListFmncRMFileMSample: recordset of TblFmncRMFileMSample
  */
class ListFmncRMFileMSample {

public:
	ListFmncRMFileMSample();
	ListFmncRMFileMSample(const ListFmncRMFileMSample& src);
	~ListFmncRMFileMSample();

	void clear();
	unsigned int size() const;
	void append(FmncRMFileMSample* rec);

	FmncRMFileMSample* operator[](const uint ix);
	ListFmncRMFileMSample& operator=(const ListFmncRMFileMSample& src);
	bool operator==(const ListFmncRMFileMSample& comp);
	bool operator!=(const ListFmncRMFileMSample& comp);

public:
	vector<FmncRMFileMSample*> nodes;
};

/**
  * TblFmncRMFileMSample: C++ wrapper for table TblFmncRMFileMSample
  */
class TblFmncRMFileMSample {

public:
	TblFmncRMFileMSample();
	virtual ~TblFmncRMFileMSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncRMFileMSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFileMSample& rst);

	virtual void insertRec(FmncRMFileMSample* rec);
	ubigint insertNewRec(FmncRMFileMSample** rec = NULL, const ubigint refFmncMFile = 0, const ubigint refFmncMSample = 0);
	ubigint appendNewRecToRst(ListFmncRMFileMSample& rst, FmncRMFileMSample** rec = NULL, const ubigint refFmncMFile = 0, const ubigint refFmncMSample = 0);
	virtual void insertRst(ListFmncRMFileMSample& rst, bool transact = false);
	virtual void updateRec(FmncRMFileMSample* rec);
	virtual void updateRst(ListFmncRMFileMSample& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncRMFileMSample** rec);
	virtual ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncRMFileMSample& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncRMFileMSample: C++ wrapper for table TblFmncRMFileMSample (MySQL database)
  */
class MyTblFmncRMFileMSample : public TblFmncRMFileMSample, public MyTable {

public:
	MyTblFmncRMFileMSample();
	~MyTblFmncRMFileMSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFileMSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFileMSample& rst);

	void insertRec(FmncRMFileMSample* rec);
	void insertRst(ListFmncRMFileMSample& rst, bool transact = false);
	void updateRec(FmncRMFileMSample* rec);
	void updateRst(ListFmncRMFileMSample& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFileMSample** rec);
	ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncRMFileMSample: C++ wrapper for table TblFmncRMFileMSample (PgSQL database)
  */
class PgTblFmncRMFileMSample : public TblFmncRMFileMSample, public PgTable {

public:
	PgTblFmncRMFileMSample();
	~PgTblFmncRMFileMSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncRMFileMSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncRMFileMSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncRMFileMSample** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncRMFileMSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncRMFileMSample& rst);

	void insertRec(FmncRMFileMSample* rec);
	void insertRst(ListFmncRMFileMSample& rst, bool transact = false);
	void updateRec(FmncRMFileMSample* rec);
	void updateRst(ListFmncRMFileMSample& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncRMFileMSample** rec);
	ubigint loadRefsBySmp(ubigint refFmncMSample, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

