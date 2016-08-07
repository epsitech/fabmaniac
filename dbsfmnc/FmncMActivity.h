/**
  * \file FmncMActivity.h
  * database access for table TblFmncMActivity (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMACTIVITY_H
#define FMNCMACTIVITY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMActivity: record of TblFmncMActivity
  */
class FmncMActivity {

public:
	FmncMActivity(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint runRefFmncMRun = 0, const uint runNum = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint runRefFmncMRun;
	uint runNum;
	string Title;
	string Comment;

public:
	bool operator==(const FmncMActivity& comp);
	bool operator!=(const FmncMActivity& comp);
};

/**
  * ListFmncMActivity: recordset of TblFmncMActivity
  */
class ListFmncMActivity {

public:
	ListFmncMActivity();
	ListFmncMActivity(const ListFmncMActivity& src);
	~ListFmncMActivity();

	void clear();
	unsigned int size() const;
	void append(FmncMActivity* rec);

	FmncMActivity* operator[](const uint ix);
	ListFmncMActivity& operator=(const ListFmncMActivity& src);
	bool operator==(const ListFmncMActivity& comp);
	bool operator!=(const ListFmncMActivity& comp);

public:
	vector<FmncMActivity*> nodes;
};

/**
  * TblFmncMActivity: C++ wrapper for table TblFmncMActivity
  */
class TblFmncMActivity {

public:
	TblFmncMActivity();
	virtual ~TblFmncMActivity();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMActivity** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMActivity& rst);

	virtual void insertRec(FmncMActivity* rec);
	ubigint insertNewRec(FmncMActivity** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint runRefFmncMRun = 0, const uint runNum = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMActivity& rst, FmncMActivity** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint runRefFmncMRun = 0, const uint runNum = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncMActivity& rst, bool transact = false);
	virtual void updateRec(FmncMActivity* rec);
	virtual void updateRst(ListFmncMActivity& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMActivity** rec);
	virtual ubigint loadRefsByRun(ubigint runRefFmncMRun, const bool append, vector<ubigint>& refs);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMActivity& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMActivity: C++ wrapper for table TblFmncMActivity (MySQL database)
  */
class MyTblFmncMActivity : public TblFmncMActivity, public MyTable {

public:
	MyTblFmncMActivity();
	~MyTblFmncMActivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMActivity** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMActivity& rst);

	void insertRec(FmncMActivity* rec);
	void insertRst(ListFmncMActivity& rst, bool transact = false);
	void updateRec(FmncMActivity* rec);
	void updateRst(ListFmncMActivity& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMActivity** rec);
	ubigint loadRefsByRun(ubigint runRefFmncMRun, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMActivity: C++ wrapper for table TblFmncMActivity (PgSQL database)
  */
class PgTblFmncMActivity : public TblFmncMActivity, public PgTable {

public:
	PgTblFmncMActivity();
	~PgTblFmncMActivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMActivity** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMActivity& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMActivity** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMActivity** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMActivity& rst);

	void insertRec(FmncMActivity* rec);
	void insertRst(ListFmncMActivity& rst, bool transact = false);
	void updateRec(FmncMActivity* rec);
	void updateRst(ListFmncMActivity& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMActivity** rec);
	ubigint loadRefsByRun(ubigint runRefFmncMRun, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

