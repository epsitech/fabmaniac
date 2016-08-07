/**
  * \file FmncQPrsList.h
  * Dbs and XML wrapper for table TblFmncQPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSLIST_H
#define FMNCQPRSLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsList: record of TblFmncQPrsList
  */
class FmncQPrsList {

public:
	FmncQPrsList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMAddress = 0, const string stubRefFmncMAddress = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string Tel = "", const string Eml = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	string Firstname;
	string Lastname;
	ubigint grp;
	string stubGrp;
	ubigint own;
	string stubOwn;
	ubigint refFmncMOrg;
	string stubRefFmncMOrg;
	ubigint refFmncMAddress;
	string stubRefFmncMAddress;
	uint ixVSex;
	string srefIxVSex;
	string titIxVSex;
	string Tel;
	string Eml;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPrsList: recordset of TblFmncQPrsList
  */
class ListFmncQPrsList {

public:
	ListFmncQPrsList();
	ListFmncQPrsList(const ListFmncQPrsList& src);
	~ListFmncQPrsList();

	void clear();
	unsigned int size() const;
	void append(FmncQPrsList* rec);

	ListFmncQPrsList& operator=(const ListFmncQPrsList& src);

public:
	vector<FmncQPrsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPrsList: C++ wrapper for table TblFmncQPrsList
  */
class TblFmncQPrsList {

public:
	TblFmncQPrsList();
	virtual ~TblFmncQPrsList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPrsList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsList& rst);

	virtual void insertRec(FmncQPrsList* rec);
	ubigint insertNewRec(FmncQPrsList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMAddress = 0, const string stubRefFmncMAddress = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string Tel = "", const string Eml = "");
	ubigint appendNewRecToRst(ListFmncQPrsList& rst, FmncQPrsList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const ubigint refFmncMOrg = 0, const string stubRefFmncMOrg = "", const ubigint refFmncMAddress = 0, const string stubRefFmncMAddress = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string Tel = "", const string Eml = "");
	virtual void insertRst(ListFmncQPrsList& rst);
	virtual void updateRec(FmncQPrsList* rec);
	virtual void updateRst(ListFmncQPrsList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPrsList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPrsList: C++ wrapper for table TblFmncQPrsList (MySQL database)
  */
class MyTblFmncQPrsList : public TblFmncQPrsList, public MyTable {

public:
	MyTblFmncQPrsList();
	~MyTblFmncQPrsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsList& rst);

	void insertRec(FmncQPrsList* rec);
	void insertRst(ListFmncQPrsList& rst);
	void updateRec(FmncQPrsList* rec);
	void updateRst(ListFmncQPrsList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPrsList: C++ wrapper for table TblFmncQPrsList (PgSQL database)
  */
class PgTblFmncQPrsList : public TblFmncQPrsList, public PgTable {

public:
	PgTblFmncQPrsList();
	~PgTblFmncQPrsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPrsList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPrsList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPrsList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPrsList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsList& rst);

	void insertRec(FmncQPrsList* rec);
	void insertRst(ListFmncQPrsList& rst);
	void updateRec(FmncQPrsList* rec);
	void updateRst(ListFmncQPrsList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsList& rst);
};
// IP pgTbl --- END

#endif

