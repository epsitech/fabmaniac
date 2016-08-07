/**
  * \file FmncMSample.h
  * database access for table TblFmncMSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMSAMPLE_H
#define FMNCMSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMSample: record of TblFmncMSample
  */
class FmncMSample {

public:
	FmncMSample(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint supRefFmncMSample = 0, const usmallint supLvl = 0, const ubigint refFmncMArticle = 0, const string sref = "", const string Material = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint supRefFmncMSample;
	usmallint supLvl;
	ubigint refFmncMArticle;
	string sref;
	string Material;
	ubigint refJState;
	uint ixVState;
	string Comment;

public:
	bool operator==(const FmncMSample& comp);
	bool operator!=(const FmncMSample& comp);
};

/**
  * ListFmncMSample: recordset of TblFmncMSample
  */
class ListFmncMSample {

public:
	ListFmncMSample();
	ListFmncMSample(const ListFmncMSample& src);
	~ListFmncMSample();

	void clear();
	unsigned int size() const;
	void append(FmncMSample* rec);

	FmncMSample* operator[](const uint ix);
	ListFmncMSample& operator=(const ListFmncMSample& src);
	bool operator==(const ListFmncMSample& comp);
	bool operator!=(const ListFmncMSample& comp);

public:
	vector<FmncMSample*> nodes;
};

/**
  * TblFmncMSample: C++ wrapper for table TblFmncMSample
  */
class TblFmncMSample {

public:
	TblFmncMSample();
	virtual ~TblFmncMSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMSample& rst);

	virtual void insertRec(FmncMSample* rec);
	ubigint insertNewRec(FmncMSample** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint supRefFmncMSample = 0, const usmallint supLvl = 0, const ubigint refFmncMArticle = 0, const string sref = "", const string Material = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMSample& rst, FmncMSample** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint supRefFmncMSample = 0, const usmallint supLvl = 0, const ubigint refFmncMArticle = 0, const string sref = "", const string Material = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");
	virtual void insertRst(ListFmncMSample& rst, bool transact = false);
	virtual void updateRec(FmncMSample* rec);
	virtual void updateRst(ListFmncMSample& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMSample** rec);
	virtual bool confirmByRef(ubigint ref);
	virtual bool loadRefBySupSrf(ubigint supRefFmncMSample, string sref, ubigint& ref);
	virtual ubigint loadRefsBySup(ubigint supRefFmncMSample, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstBySup(ubigint supRefFmncMSample, const bool append, ListFmncMSample& rst);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	virtual bool loadSupByRef(ubigint ref, ubigint& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMSample& rst);
// IP loadHrefsup --- BEGIN
	ubigint loadHrefsup(ubigint ref, vector<ubigint>& refs);
// IP loadHrefsup --- END
// IP loadHrefsdown --- BEGIN
	ubigint loadHrefsdown(ubigint ref, const bool append, vector<ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrefsdown --- END
// IP loadHrstup --- BEGIN
	ubigint loadHrstup(ubigint ref, ListFmncMSample& rst);
// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
	ubigint loadHrstdown(ubigint ref, const bool append, ListFmncMSample& rst, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrstdown --- END
};

// IP myTbl --- BEGIN
/**
  * MyFmncMSample: C++ wrapper for table TblFmncMSample (MySQL database)
  */
class MyTblFmncMSample : public TblFmncMSample, public MyTable {

public:
	MyTblFmncMSample();
	~MyTblFmncMSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMSample& rst);

	void insertRec(FmncMSample* rec);
	void insertRst(ListFmncMSample& rst, bool transact = false);
	void updateRec(FmncMSample* rec);
	void updateRst(ListFmncMSample& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMSample** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint supRefFmncMSample, string sref, ubigint& ref);
	ubigint loadRefsBySup(ubigint supRefFmncMSample, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefFmncMSample, const bool append, ListFmncMSample& rst);
	bool loadSrfByRef(ubigint ref, string& val);
	bool loadSupByRef(ubigint ref, ubigint& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMSample: C++ wrapper for table TblFmncMSample (PgSQL database)
  */
class PgTblFmncMSample : public TblFmncMSample, public PgTable {

public:
	PgTblFmncMSample();
	~PgTblFmncMSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMSample** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncMSample& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncMSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMSample& rst);

	void insertRec(FmncMSample* rec);
	void insertRst(ListFmncMSample& rst, bool transact = false);
	void updateRec(FmncMSample* rec);
	void updateRst(ListFmncMSample& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMSample** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint supRefFmncMSample, string sref, ubigint& ref);
	ubigint loadRefsBySup(ubigint supRefFmncMSample, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefFmncMSample, const bool append, ListFmncMSample& rst);
	bool loadSrfByRef(ubigint ref, string& val);
	bool loadSupByRef(ubigint ref, ubigint& val);
};
// IP pgTbl --- END

#endif

