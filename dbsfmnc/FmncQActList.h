/**
  * \file FmncQActList.h
  * Dbs and XML wrapper for table TblFmncQActList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQACTLIST_H
#define FMNCQACTLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQActList: record of TblFmncQActList
  */
class FmncQActList {

public:
	FmncQActList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint runRefFmncMRun = 0, const string stubRunRefFmncMRun = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	ubigint runRefFmncMRun;
	string stubRunRefFmncMRun;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQActList: recordset of TblFmncQActList
  */
class ListFmncQActList {

public:
	ListFmncQActList();
	ListFmncQActList(const ListFmncQActList& src);
	~ListFmncQActList();

	void clear();
	unsigned int size() const;
	void append(FmncQActList* rec);

	ListFmncQActList& operator=(const ListFmncQActList& src);

public:
	vector<FmncQActList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQActList: C++ wrapper for table TblFmncQActList
  */
class TblFmncQActList {

public:
	TblFmncQActList();
	virtual ~TblFmncQActList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQActList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQActList& rst);

	virtual void insertRec(FmncQActList* rec);
	ubigint insertNewRec(FmncQActList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint runRefFmncMRun = 0, const string stubRunRefFmncMRun = "");
	ubigint appendNewRecToRst(ListFmncQActList& rst, FmncQActList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint runRefFmncMRun = 0, const string stubRunRefFmncMRun = "");
	virtual void insertRst(ListFmncQActList& rst);
	virtual void updateRec(FmncQActList* rec);
	virtual void updateRst(ListFmncQActList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQActList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQActList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQActList: C++ wrapper for table TblFmncQActList (MySQL database)
  */
class MyTblFmncQActList : public TblFmncQActList, public MyTable {

public:
	MyTblFmncQActList();
	~MyTblFmncQActList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQActList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQActList& rst);

	void insertRec(FmncQActList* rec);
	void insertRst(ListFmncQActList& rst);
	void updateRec(FmncQActList* rec);
	void updateRst(ListFmncQActList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQActList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQActList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQActList: C++ wrapper for table TblFmncQActList (PgSQL database)
  */
class PgTblFmncQActList : public TblFmncQActList, public PgTable {

public:
	PgTblFmncQActList();
	~PgTblFmncQActList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQActList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQActList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQActList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQActList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQActList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQActList& rst);

	void insertRec(FmncQActList* rec);
	void insertRst(ListFmncQActList& rst);
	void updateRec(FmncQActList* rec);
	void updateRst(ListFmncQActList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQActList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQActList& rst);
};
// IP pgTbl --- END

#endif

