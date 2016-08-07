/**
  * \file FmncQUsgList.h
  * Dbs and XML wrapper for table TblFmncQUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSGLIST_H
#define FMNCQUSGLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsgList: record of TblFmncQUsgList
  */
class FmncQUsgList {

public:
	FmncQUsgList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQUsgList: recordset of TblFmncQUsgList
  */
class ListFmncQUsgList {

public:
	ListFmncQUsgList();
	ListFmncQUsgList(const ListFmncQUsgList& src);
	~ListFmncQUsgList();

	void clear();
	unsigned int size() const;
	void append(FmncQUsgList* rec);

	ListFmncQUsgList& operator=(const ListFmncQUsgList& src);

public:
	vector<FmncQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQUsgList: C++ wrapper for table TblFmncQUsgList
  */
class TblFmncQUsgList {

public:
	TblFmncQUsgList();
	virtual ~TblFmncQUsgList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQUsgList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgList& rst);

	virtual void insertRec(FmncQUsgList* rec);
	ubigint insertNewRec(FmncQUsgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");
	ubigint appendNewRecToRst(ListFmncQUsgList& rst, FmncQUsgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");
	virtual void insertRst(ListFmncQUsgList& rst);
	virtual void updateRec(FmncQUsgList* rec);
	virtual void updateRst(ListFmncQUsgList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQUsgList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQUsgList: C++ wrapper for table TblFmncQUsgList (MySQL database)
  */
class MyTblFmncQUsgList : public TblFmncQUsgList, public MyTable {

public:
	MyTblFmncQUsgList();
	~MyTblFmncQUsgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgList& rst);

	void insertRec(FmncQUsgList* rec);
	void insertRst(ListFmncQUsgList& rst);
	void updateRec(FmncQUsgList* rec);
	void updateRst(ListFmncQUsgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQUsgList: C++ wrapper for table TblFmncQUsgList (PgSQL database)
  */
class PgTblFmncQUsgList : public TblFmncQUsgList, public PgTable {

public:
	PgTblFmncQUsgList();
	~PgTblFmncQUsgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQUsgList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQUsgList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQUsgList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQUsgList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgList& rst);

	void insertRec(FmncQUsgList* rec);
	void insertRst(ListFmncQUsgList& rst);
	void updateRec(FmncQUsgList* rec);
	void updateRst(ListFmncQUsgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgList& rst);
};
// IP pgTbl --- END

#endif

