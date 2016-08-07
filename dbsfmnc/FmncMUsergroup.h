/**
  * \file FmncMUsergroup.h
  * database access for table TblFmncMUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMUSERGROUP_H
#define FMNCMUSERGROUP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMUsergroup: record of TblFmncMUsergroup
  */
class FmncMUsergroup {

public:
	FmncMUsergroup(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	string sref;
	string Comment;

public:
	bool operator==(const FmncMUsergroup& comp);
	bool operator!=(const FmncMUsergroup& comp);
};

/**
  * ListFmncMUsergroup: recordset of TblFmncMUsergroup
  */
class ListFmncMUsergroup {

public:
	ListFmncMUsergroup();
	ListFmncMUsergroup(const ListFmncMUsergroup& src);
	~ListFmncMUsergroup();

	void clear();
	unsigned int size() const;
	void append(FmncMUsergroup* rec);

	FmncMUsergroup* operator[](const uint ix);
	ListFmncMUsergroup& operator=(const ListFmncMUsergroup& src);
	bool operator==(const ListFmncMUsergroup& comp);
	bool operator!=(const ListFmncMUsergroup& comp);

public:
	vector<FmncMUsergroup*> nodes;
};

/**
  * TblFmncMUsergroup: C++ wrapper for table TblFmncMUsergroup
  */
class TblFmncMUsergroup {

public:
	TblFmncMUsergroup();
	virtual ~TblFmncMUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMUsergroup& rst);

	virtual void insertRec(FmncMUsergroup* rec);
	ubigint insertNewRec(FmncMUsergroup** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMUsergroup& rst, FmncMUsergroup** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");
	virtual void insertRst(ListFmncMUsergroup& rst, bool transact = false);
	virtual void updateRec(FmncMUsergroup* rec);
	virtual void updateRst(ListFmncMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMUsergroup** rec);
	virtual bool loadRecBySrf(string sref, FmncMUsergroup** rec);
	virtual bool loadRefBySrf(string sref, ubigint& ref);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMUsergroup& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMUsergroup: C++ wrapper for table TblFmncMUsergroup (MySQL database)
  */
class MyTblFmncMUsergroup : public TblFmncMUsergroup, public MyTable {

public:
	MyTblFmncMUsergroup();
	~MyTblFmncMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMUsergroup& rst);

	void insertRec(FmncMUsergroup* rec);
	void insertRst(ListFmncMUsergroup& rst, bool transact = false);
	void updateRec(FmncMUsergroup* rec);
	void updateRst(ListFmncMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMUsergroup** rec);
	bool loadRecBySrf(string sref, FmncMUsergroup** rec);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMUsergroup: C++ wrapper for table TblFmncMUsergroup (PgSQL database)
  */
class PgTblFmncMUsergroup : public TblFmncMUsergroup, public PgTable {

public:
	PgTblFmncMUsergroup();
	~PgTblFmncMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMUsergroup** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMUsergroup& rst);

	void insertRec(FmncMUsergroup* rec);
	void insertRst(ListFmncMUsergroup& rst, bool transact = false);
	void updateRec(FmncMUsergroup* rec);
	void updateRst(ListFmncMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMUsergroup** rec);
	bool loadRecBySrf(string sref, FmncMUsergroup** rec);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

