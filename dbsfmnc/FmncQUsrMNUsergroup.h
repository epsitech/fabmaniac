/**
  * \file FmncQUsrMNUsergroup.h
  * Dbs and XML wrapper for table TblFmncQUsrMNUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSRMNUSERGROUP_H
#define FMNCQUSRMNUSERGROUP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsrMNUsergroup: record of TblFmncQUsrMNUsergroup
  */
class FmncQUsrMNUsergroup {

public:
	FmncQUsrMNUsergroup(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");

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
  * ListFmncQUsrMNUsergroup: recordset of TblFmncQUsrMNUsergroup
  */
class ListFmncQUsrMNUsergroup {

public:
	ListFmncQUsrMNUsergroup();
	ListFmncQUsrMNUsergroup(const ListFmncQUsrMNUsergroup& src);
	~ListFmncQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(FmncQUsrMNUsergroup* rec);

	ListFmncQUsrMNUsergroup& operator=(const ListFmncQUsrMNUsergroup& src);

public:
	vector<FmncQUsrMNUsergroup*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQUsrMNUsergroup: C++ wrapper for table TblFmncQUsrMNUsergroup
  */
class TblFmncQUsrMNUsergroup {

public:
	TblFmncQUsrMNUsergroup();
	virtual ~TblFmncQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQUsrMNUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrMNUsergroup& rst);

	virtual void insertRec(FmncQUsrMNUsergroup* rec);
	ubigint insertNewRec(FmncQUsrMNUsergroup** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");
	ubigint appendNewRecToRst(ListFmncQUsrMNUsergroup& rst, FmncQUsrMNUsergroup** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixFmncVUserlevel = 0, const string srefIxFmncVUserlevel = "", const string titIxFmncVUserlevel = "");
	virtual void insertRst(ListFmncQUsrMNUsergroup& rst);
	virtual void updateRec(FmncQUsrMNUsergroup* rec);
	virtual void updateRst(ListFmncQUsrMNUsergroup& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQUsrMNUsergroup** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrMNUsergroup& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQUsrMNUsergroup: C++ wrapper for table TblFmncQUsrMNUsergroup (MySQL database)
  */
class MyTblFmncQUsrMNUsergroup : public TblFmncQUsrMNUsergroup, public MyTable {

public:
	MyTblFmncQUsrMNUsergroup();
	~MyTblFmncQUsrMNUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsrMNUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrMNUsergroup& rst);

	void insertRec(FmncQUsrMNUsergroup* rec);
	void insertRst(ListFmncQUsrMNUsergroup& rst);
	void updateRec(FmncQUsrMNUsergroup* rec);
	void updateRst(ListFmncQUsrMNUsergroup& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsrMNUsergroup** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrMNUsergroup& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQUsrMNUsergroup: C++ wrapper for table TblFmncQUsrMNUsergroup (PgSQL database)
  */
class PgTblFmncQUsrMNUsergroup : public TblFmncQUsrMNUsergroup, public PgTable {

public:
	PgTblFmncQUsrMNUsergroup();
	~PgTblFmncQUsrMNUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQUsrMNUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQUsrMNUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQUsrMNUsergroup** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsrMNUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrMNUsergroup& rst);

	void insertRec(FmncQUsrMNUsergroup* rec);
	void insertRst(ListFmncQUsrMNUsergroup& rst);
	void updateRec(FmncQUsrMNUsergroup* rec);
	void updateRst(ListFmncQUsrMNUsergroup& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsrMNUsergroup** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrMNUsergroup& rst);
};
// IP pgTbl --- END

#endif

