/**
  * \file FmncQTolList.h
  * Dbs and XML wrapper for table TblFmncQTolList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLLIST_H
#define FMNCQTOLLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolList: record of TblFmncQTolList
  */
class FmncQTolList {

public:
	FmncQTolList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint fabRefFmncMFab = 0, const string stubFabRefFmncMFab = "", const ubigint mnfRefFmncMOrg = 0, const string stubMnfRefFmncMOrg = "", const double Unitprice = 0.0, const string Training = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	ubigint fabRefFmncMFab;
	string stubFabRefFmncMFab;
	ubigint mnfRefFmncMOrg;
	string stubMnfRefFmncMOrg;
	double Unitprice;
	string Training;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolList: recordset of TblFmncQTolList
  */
class ListFmncQTolList {

public:
	ListFmncQTolList();
	ListFmncQTolList(const ListFmncQTolList& src);
	~ListFmncQTolList();

	void clear();
	unsigned int size() const;
	void append(FmncQTolList* rec);

	ListFmncQTolList& operator=(const ListFmncQTolList& src);

public:
	vector<FmncQTolList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolList: C++ wrapper for table TblFmncQTolList
  */
class TblFmncQTolList {

public:
	TblFmncQTolList();
	virtual ~TblFmncQTolList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolList& rst);

	virtual void insertRec(FmncQTolList* rec);
	ubigint insertNewRec(FmncQTolList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint fabRefFmncMFab = 0, const string stubFabRefFmncMFab = "", const ubigint mnfRefFmncMOrg = 0, const string stubMnfRefFmncMOrg = "", const double Unitprice = 0.0, const string Training = "");
	ubigint appendNewRecToRst(ListFmncQTolList& rst, FmncQTolList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint fabRefFmncMFab = 0, const string stubFabRefFmncMFab = "", const ubigint mnfRefFmncMOrg = 0, const string stubMnfRefFmncMOrg = "", const double Unitprice = 0.0, const string Training = "");
	virtual void insertRst(ListFmncQTolList& rst);
	virtual void updateRec(FmncQTolList* rec);
	virtual void updateRst(ListFmncQTolList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolList: C++ wrapper for table TblFmncQTolList (MySQL database)
  */
class MyTblFmncQTolList : public TblFmncQTolList, public MyTable {

public:
	MyTblFmncQTolList();
	~MyTblFmncQTolList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolList& rst);

	void insertRec(FmncQTolList* rec);
	void insertRst(ListFmncQTolList& rst);
	void updateRec(FmncQTolList* rec);
	void updateRst(ListFmncQTolList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolList: C++ wrapper for table TblFmncQTolList (PgSQL database)
  */
class PgTblFmncQTolList : public TblFmncQTolList, public PgTable {

public:
	PgTblFmncQTolList();
	~PgTblFmncQTolList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolList& rst);

	void insertRec(FmncQTolList* rec);
	void insertRst(ListFmncQTolList& rst);
	void updateRec(FmncQTolList* rec);
	void updateRst(ListFmncQTolList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolList& rst);
};
// IP pgTbl --- END

#endif

