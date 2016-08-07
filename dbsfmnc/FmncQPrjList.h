/**
  * \file FmncQPrjList.h
  * Dbs and XML wrapper for table TblFmncQPrjList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRJLIST_H
#define FMNCQPRJLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrjList: record of TblFmncQPrjList
  */
class FmncQPrjList {

public:
	FmncQPrjList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	uint ixVState;
	string srefIxVState;
	string titIxVState;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPrjList: recordset of TblFmncQPrjList
  */
class ListFmncQPrjList {

public:
	ListFmncQPrjList();
	ListFmncQPrjList(const ListFmncQPrjList& src);
	~ListFmncQPrjList();

	void clear();
	unsigned int size() const;
	void append(FmncQPrjList* rec);

	ListFmncQPrjList& operator=(const ListFmncQPrjList& src);

public:
	vector<FmncQPrjList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPrjList: C++ wrapper for table TblFmncQPrjList
  */
class TblFmncQPrjList {

public:
	TblFmncQPrjList();
	virtual ~TblFmncQPrjList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPrjList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrjList& rst);

	virtual void insertRec(FmncQPrjList* rec);
	ubigint insertNewRec(FmncQPrjList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	ubigint appendNewRecToRst(ListFmncQPrjList& rst, FmncQPrjList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	virtual void insertRst(ListFmncQPrjList& rst);
	virtual void updateRec(FmncQPrjList* rec);
	virtual void updateRst(ListFmncQPrjList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPrjList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrjList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPrjList: C++ wrapper for table TblFmncQPrjList (MySQL database)
  */
class MyTblFmncQPrjList : public TblFmncQPrjList, public MyTable {

public:
	MyTblFmncQPrjList();
	~MyTblFmncQPrjList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrjList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrjList& rst);

	void insertRec(FmncQPrjList* rec);
	void insertRst(ListFmncQPrjList& rst);
	void updateRec(FmncQPrjList* rec);
	void updateRst(ListFmncQPrjList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrjList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrjList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPrjList: C++ wrapper for table TblFmncQPrjList (PgSQL database)
  */
class PgTblFmncQPrjList : public TblFmncQPrjList, public PgTable {

public:
	PgTblFmncQPrjList();
	~PgTblFmncQPrjList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPrjList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPrjList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPrjList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPrjList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrjList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrjList& rst);

	void insertRec(FmncQPrjList* rec);
	void insertRst(ListFmncQPrjList& rst);
	void updateRec(FmncQPrjList* rec);
	void updateRst(ListFmncQPrjList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrjList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrjList& rst);
};
// IP pgTbl --- END

#endif

