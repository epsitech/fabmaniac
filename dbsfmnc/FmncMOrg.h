/**
  * \file FmncMOrg.h
  * database access for table TblFmncMOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMORG_H
#define FMNCMORG_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMOrg: record of TblFmncMOrg
  */
class FmncMOrg {

public:
	FmncMOrg(const ubigint ref = 0, const uint ixWDerivate = 0, const ubigint refFmncMAddress = 0, const ubigint supRefFmncMOrg = 0, const usmallint supLvl = 0, const string sref = "", const ubigint refJTitle = 0, const string Title = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "");

public:
	ubigint ref;
	uint ixWDerivate;
	ubigint refFmncMAddress;
	ubigint supRefFmncMOrg;
	usmallint supLvl;
	string sref;
	ubigint refJTitle;
	string Title;
	ubigint telRefADetail;
	string Tel;
	ubigint emlRefADetail;
	string Eml;

public:
	bool operator==(const FmncMOrg& comp);
	bool operator!=(const FmncMOrg& comp);
};

/**
  * ListFmncMOrg: recordset of TblFmncMOrg
  */
class ListFmncMOrg {

public:
	ListFmncMOrg();
	ListFmncMOrg(const ListFmncMOrg& src);
	~ListFmncMOrg();

	void clear();
	unsigned int size() const;
	void append(FmncMOrg* rec);

	FmncMOrg* operator[](const uint ix);
	ListFmncMOrg& operator=(const ListFmncMOrg& src);
	bool operator==(const ListFmncMOrg& comp);
	bool operator!=(const ListFmncMOrg& comp);

public:
	vector<FmncMOrg*> nodes;
};

/**
  * TblFmncMOrg: C++ wrapper for table TblFmncMOrg
  */
class TblFmncMOrg {

public:
	TblFmncMOrg();
	virtual ~TblFmncMOrg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMOrg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMOrg& rst);

	virtual void insertRec(FmncMOrg* rec);
	ubigint insertNewRec(FmncMOrg** rec = NULL, const uint ixWDerivate = 0, const ubigint refFmncMAddress = 0, const ubigint supRefFmncMOrg = 0, const usmallint supLvl = 0, const string sref = "", const ubigint refJTitle = 0, const string Title = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "");
	ubigint appendNewRecToRst(ListFmncMOrg& rst, FmncMOrg** rec = NULL, const uint ixWDerivate = 0, const ubigint refFmncMAddress = 0, const ubigint supRefFmncMOrg = 0, const usmallint supLvl = 0, const string sref = "", const ubigint refJTitle = 0, const string Title = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "");
	virtual void insertRst(ListFmncMOrg& rst, bool transact = false);
	virtual void updateRec(FmncMOrg* rec);
	virtual void updateRst(ListFmncMOrg& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMOrg** rec);
	virtual bool confirmByRef(ubigint ref);
	virtual bool loadRefBySupSrf(ubigint supRefFmncMOrg, string sref, ubigint& ref);
	virtual ubigint loadRefsBySup(ubigint supRefFmncMOrg, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstBySup(ubigint supRefFmncMOrg, const bool append, ListFmncMOrg& rst);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	virtual bool loadSupByRef(ubigint ref, ubigint& val);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMOrg& rst);
// IP loadHrefsup --- BEGIN
	ubigint loadHrefsup(ubigint ref, vector<ubigint>& refs);
// IP loadHrefsup --- END
// IP loadHrefsdown --- BEGIN
	ubigint loadHrefsdown(ubigint ref, const bool append, vector<ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrefsdown --- END
// IP loadHrstup --- BEGIN
	ubigint loadHrstup(ubigint ref, ListFmncMOrg& rst);
// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
	ubigint loadHrstdown(ubigint ref, const bool append, ListFmncMOrg& rst, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrstdown --- END
};

// IP myTbl --- BEGIN
/**
  * MyFmncMOrg: C++ wrapper for table TblFmncMOrg (MySQL database)
  */
class MyTblFmncMOrg : public TblFmncMOrg, public MyTable {

public:
	MyTblFmncMOrg();
	~MyTblFmncMOrg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMOrg& rst);

	void insertRec(FmncMOrg* rec);
	void insertRst(ListFmncMOrg& rst, bool transact = false);
	void updateRec(FmncMOrg* rec);
	void updateRst(ListFmncMOrg& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMOrg** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint supRefFmncMOrg, string sref, ubigint& ref);
	ubigint loadRefsBySup(ubigint supRefFmncMOrg, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefFmncMOrg, const bool append, ListFmncMOrg& rst);
	bool loadSrfByRef(ubigint ref, string& val);
	bool loadSupByRef(ubigint ref, ubigint& val);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMOrg: C++ wrapper for table TblFmncMOrg (PgSQL database)
  */
class PgTblFmncMOrg : public TblFmncMOrg, public PgTable {

public:
	PgTblFmncMOrg();
	~PgTblFmncMOrg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMOrg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMOrg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMOrg** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncMOrg& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncMOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMOrg& rst);

	void insertRec(FmncMOrg* rec);
	void insertRst(ListFmncMOrg& rst, bool transact = false);
	void updateRec(FmncMOrg* rec);
	void updateRst(ListFmncMOrg& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMOrg** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint supRefFmncMOrg, string sref, ubigint& ref);
	ubigint loadRefsBySup(ubigint supRefFmncMOrg, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefFmncMOrg, const bool append, ListFmncMOrg& rst);
	bool loadSrfByRef(ubigint ref, string& val);
	bool loadSupByRef(ubigint ref, ubigint& val);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

