/**
  * \file FmncMTooltype.h
  * database access for table TblFmncMTooltype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMTOOLTYPE_H
#define FMNCMTOOLTYPE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMTooltype: record of TblFmncMTooltype
  */
class FmncMTooltype {

public:
	FmncMTooltype(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint supRefFmncMTooltype = 0, const usmallint supLvl = 0, const string sref = "", const string Title = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint supRefFmncMTooltype;
	usmallint supLvl;
	string sref;
	string Title;

public:
	bool operator==(const FmncMTooltype& comp);
	bool operator!=(const FmncMTooltype& comp);
};

/**
  * ListFmncMTooltype: recordset of TblFmncMTooltype
  */
class ListFmncMTooltype {

public:
	ListFmncMTooltype();
	ListFmncMTooltype(const ListFmncMTooltype& src);
	~ListFmncMTooltype();

	void clear();
	unsigned int size() const;
	void append(FmncMTooltype* rec);

	FmncMTooltype* operator[](const uint ix);
	ListFmncMTooltype& operator=(const ListFmncMTooltype& src);
	bool operator==(const ListFmncMTooltype& comp);
	bool operator!=(const ListFmncMTooltype& comp);

public:
	vector<FmncMTooltype*> nodes;
};

/**
  * TblFmncMTooltype: C++ wrapper for table TblFmncMTooltype
  */
class TblFmncMTooltype {

public:
	TblFmncMTooltype();
	virtual ~TblFmncMTooltype();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMTooltype** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMTooltype& rst);

	virtual void insertRec(FmncMTooltype* rec);
	ubigint insertNewRec(FmncMTooltype** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint supRefFmncMTooltype = 0, const usmallint supLvl = 0, const string sref = "", const string Title = "");
	ubigint appendNewRecToRst(ListFmncMTooltype& rst, FmncMTooltype** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint supRefFmncMTooltype = 0, const usmallint supLvl = 0, const string sref = "", const string Title = "");
	virtual void insertRst(ListFmncMTooltype& rst, bool transact = false);
	virtual void updateRec(FmncMTooltype* rec);
	virtual void updateRst(ListFmncMTooltype& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMTooltype** rec);
	virtual bool confirmByRef(ubigint ref);
	virtual bool loadRefBySupSrf(ubigint supRefFmncMTooltype, string sref, ubigint& ref);
	virtual ubigint loadRefsBySup(ubigint supRefFmncMTooltype, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstBySup(ubigint supRefFmncMTooltype, const bool append, ListFmncMTooltype& rst);
	virtual bool loadSupByRef(ubigint ref, ubigint& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMTooltype& rst);
// IP loadHrefsup --- BEGIN
	ubigint loadHrefsup(ubigint ref, vector<ubigint>& refs);
// IP loadHrefsup --- END
// IP loadHrefsdown --- BEGIN
	ubigint loadHrefsdown(ubigint ref, const bool append, vector<ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrefsdown --- END
// IP loadHrstup --- BEGIN
	ubigint loadHrstup(ubigint ref, ListFmncMTooltype& rst);
// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
	ubigint loadHrstdown(ubigint ref, const bool append, ListFmncMTooltype& rst, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrstdown --- END
};

// IP myTbl --- BEGIN
/**
  * MyFmncMTooltype: C++ wrapper for table TblFmncMTooltype (MySQL database)
  */
class MyTblFmncMTooltype : public TblFmncMTooltype, public MyTable {

public:
	MyTblFmncMTooltype();
	~MyTblFmncMTooltype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMTooltype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMTooltype& rst);

	void insertRec(FmncMTooltype* rec);
	void insertRst(ListFmncMTooltype& rst, bool transact = false);
	void updateRec(FmncMTooltype* rec);
	void updateRst(ListFmncMTooltype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMTooltype** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint supRefFmncMTooltype, string sref, ubigint& ref);
	ubigint loadRefsBySup(ubigint supRefFmncMTooltype, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefFmncMTooltype, const bool append, ListFmncMTooltype& rst);
	bool loadSupByRef(ubigint ref, ubigint& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMTooltype: C++ wrapper for table TblFmncMTooltype (PgSQL database)
  */
class PgTblFmncMTooltype : public TblFmncMTooltype, public PgTable {

public:
	PgTblFmncMTooltype();
	~PgTblFmncMTooltype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMTooltype** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMTooltype& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMTooltype** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncMTooltype& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncMTooltype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMTooltype& rst);

	void insertRec(FmncMTooltype* rec);
	void insertRst(ListFmncMTooltype& rst, bool transact = false);
	void updateRec(FmncMTooltype* rec);
	void updateRst(ListFmncMTooltype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMTooltype** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint supRefFmncMTooltype, string sref, ubigint& ref);
	ubigint loadRefsBySup(ubigint supRefFmncMTooltype, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefFmncMTooltype, const bool append, ListFmncMTooltype& rst);
	bool loadSupByRef(ubigint ref, ubigint& val);
};
// IP pgTbl --- END

#endif

