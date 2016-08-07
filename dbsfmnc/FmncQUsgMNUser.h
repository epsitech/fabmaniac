/**
  * \file FmncQUsgMNUser.h
  * Dbs and XML wrapper for table TblFmncQUsgMNUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSGMNUSER_H
#define FMNCQUSGMNUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsgMNUser: record of TblFmncQUsgMNUser
  */
class FmncQUsgMNUser {

public:
	FmncQUsgMNUser(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint ixFmncVUserlevel;
	string srefIxFmncVUserlevel;
	string titIxFmncVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQUsgMNUser: recordset of TblFmncQUsgMNUser
  */
class ListFmncQUsgMNUser {

public:
	ListFmncQUsgMNUser();
	ListFmncQUsgMNUser(const ListFmncQUsgMNUser& src);
	~ListFmncQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(FmncQUsgMNUser* rec);

	ListFmncQUsgMNUser& operator=(const ListFmncQUsgMNUser& src);

public:
	vector<FmncQUsgMNUser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQUsgMNUser: C++ wrapper for table TblFmncQUsgMNUser
  */
class TblFmncQUsgMNUser {

public:
	TblFmncQUsgMNUser();
	virtual ~TblFmncQUsgMNUser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQUsgMNUser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgMNUser& rst);

	virtual void insertRec(FmncQUsgMNUser* rec);
	ubigint insertNewRec(FmncQUsgMNUser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");
	ubigint appendNewRecToRst(ListFmncQUsgMNUser& rst, FmncQUsgMNUser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");
	virtual void insertRst(ListFmncQUsgMNUser& rst);
	virtual void updateRec(FmncQUsgMNUser* rec);
	virtual void updateRst(ListFmncQUsgMNUser& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQUsgMNUser** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgMNUser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQUsgMNUser: C++ wrapper for table TblFmncQUsgMNUser (MySQL database)
  */
class MyTblFmncQUsgMNUser : public TblFmncQUsgMNUser, public MyTable {

public:
	MyTblFmncQUsgMNUser();
	~MyTblFmncQUsgMNUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsgMNUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgMNUser& rst);

	void insertRec(FmncQUsgMNUser* rec);
	void insertRst(ListFmncQUsgMNUser& rst);
	void updateRec(FmncQUsgMNUser* rec);
	void updateRst(ListFmncQUsgMNUser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsgMNUser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgMNUser& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQUsgMNUser: C++ wrapper for table TblFmncQUsgMNUser (PgSQL database)
  */
class PgTblFmncQUsgMNUser : public TblFmncQUsgMNUser, public PgTable {

public:
	PgTblFmncQUsgMNUser();
	~PgTblFmncQUsgMNUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQUsgMNUser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQUsgMNUser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQUsgMNUser** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQUsgMNUser& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsgMNUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgMNUser& rst);

	void insertRec(FmncQUsgMNUser* rec);
	void insertRst(ListFmncQUsgMNUser& rst);
	void updateRec(FmncQUsgMNUser* rec);
	void updateRst(ListFmncQUsgMNUser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsgMNUser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgMNUser& rst);
};
// IP pgTbl --- END

#endif

