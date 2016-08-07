/**
  * \file FmncMUser.h
  * database access for table TblFmncMUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMUSER_H
#define FMNCMUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMUser: record of TblFmncMUser
  */
class FmncMUser {

public:
	FmncMUser(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refFmncMUsergroup = 0, const ubigint refFmncMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixFmncVLocale = 0, const uint ixFmncVUserlevel = 0, const string Password = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refRUsergroup;
	ubigint refFmncMUsergroup;
	ubigint refFmncMPerson;
	string sref;
	ubigint refJState;
	uint ixVState;
	uint ixFmncVLocale;
	uint ixFmncVUserlevel;
	string Password;

public:
	bool operator==(const FmncMUser& comp);
	bool operator!=(const FmncMUser& comp);
};

/**
  * ListFmncMUser: recordset of TblFmncMUser
  */
class ListFmncMUser {

public:
	ListFmncMUser();
	ListFmncMUser(const ListFmncMUser& src);
	~ListFmncMUser();

	void clear();
	unsigned int size() const;
	void append(FmncMUser* rec);

	FmncMUser* operator[](const uint ix);
	ListFmncMUser& operator=(const ListFmncMUser& src);
	bool operator==(const ListFmncMUser& comp);
	bool operator!=(const ListFmncMUser& comp);

public:
	vector<FmncMUser*> nodes;
};

/**
  * TblFmncMUser: C++ wrapper for table TblFmncMUser
  */
class TblFmncMUser {

public:
	TblFmncMUser();
	virtual ~TblFmncMUser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMUser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMUser& rst);

	virtual void insertRec(FmncMUser* rec);
	ubigint insertNewRec(FmncMUser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refFmncMUsergroup = 0, const ubigint refFmncMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixFmncVLocale = 0, const uint ixFmncVUserlevel = 0, const string Password = "");
	ubigint appendNewRecToRst(ListFmncMUser& rst, FmncMUser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refFmncMUsergroup = 0, const ubigint refFmncMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixFmncVLocale = 0, const uint ixFmncVUserlevel = 0, const string Password = "");
	virtual void insertRst(ListFmncMUser& rst, bool transact = false);
	virtual void updateRec(FmncMUser* rec);
	virtual void updateRst(ListFmncMUser& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMUser** rec);
	virtual bool loadRecByPrs(ubigint refFmncMPerson, FmncMUser** rec);
	virtual bool loadRecBySrf(string sref, FmncMUser** rec);
	virtual bool loadRefByPrs(ubigint refFmncMPerson, ubigint& ref);
	virtual bool loadRefBySrf(string sref, ubigint& ref);
	virtual bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMUser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMUser: C++ wrapper for table TblFmncMUser (MySQL database)
  */
class MyTblFmncMUser : public TblFmncMUser, public MyTable {

public:
	MyTblFmncMUser();
	~MyTblFmncMUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMUser& rst);

	void insertRec(FmncMUser* rec);
	void insertRst(ListFmncMUser& rst, bool transact = false);
	void updateRec(FmncMUser* rec);
	void updateRst(ListFmncMUser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMUser** rec);
	bool loadRecByPrs(ubigint refFmncMPerson, FmncMUser** rec);
	bool loadRecBySrf(string sref, FmncMUser** rec);
	bool loadRefByPrs(ubigint refFmncMPerson, ubigint& ref);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMUser: C++ wrapper for table TblFmncMUser (PgSQL database)
  */
class PgTblFmncMUser : public TblFmncMUser, public PgTable {

public:
	PgTblFmncMUser();
	~PgTblFmncMUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMUser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMUser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMUser** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMUser& rst);

	void insertRec(FmncMUser* rec);
	void insertRst(ListFmncMUser& rst, bool transact = false);
	void updateRec(FmncMUser* rec);
	void updateRst(ListFmncMUser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMUser** rec);
	bool loadRecByPrs(ubigint refFmncMPerson, FmncMUser** rec);
	bool loadRecBySrf(string sref, FmncMUser** rec);
	bool loadRefByPrs(ubigint refFmncMPerson, ubigint& ref);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

