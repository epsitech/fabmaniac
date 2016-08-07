/**
  * \file FmncQSepList.h
  * Dbs and XML wrapper for table TblFmncQSepList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPLIST_H
#define FMNCQSEPLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepList: record of TblFmncQSepList
  */
class FmncQSepList {

public:
	FmncQSepList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMActivity = 0, const string stubRefFmncMActivity = "", const uint rlvIxVTbl = 0, const string srefRlvIxVTbl = "", const string titRlvIxVTbl = "", const ubigint rlvUref = 0, const string stubRlvUref = "", const ubigint tplRefFmncMStep = 0, const string stubTplRefFmncMStep = "", const uint start = 0, const string ftmStart = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	ubigint refFmncMActivity;
	string stubRefFmncMActivity;
	uint rlvIxVTbl;
	string srefRlvIxVTbl;
	string titRlvIxVTbl;
	ubigint rlvUref;
	string stubRlvUref;
	ubigint tplRefFmncMStep;
	string stubTplRefFmncMStep;
	uint start;
	string ftmStart;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQSepList: recordset of TblFmncQSepList
  */
class ListFmncQSepList {

public:
	ListFmncQSepList();
	ListFmncQSepList(const ListFmncQSepList& src);
	~ListFmncQSepList();

	void clear();
	unsigned int size() const;
	void append(FmncQSepList* rec);

	ListFmncQSepList& operator=(const ListFmncQSepList& src);

public:
	vector<FmncQSepList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSepList: C++ wrapper for table TblFmncQSepList
  */
class TblFmncQSepList {

public:
	TblFmncQSepList();
	virtual ~TblFmncQSepList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSepList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepList& rst);

	virtual void insertRec(FmncQSepList* rec);
	ubigint insertNewRec(FmncQSepList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMActivity = 0, const string stubRefFmncMActivity = "", const uint rlvIxVTbl = 0, const string srefRlvIxVTbl = "", const string titRlvIxVTbl = "", const ubigint rlvUref = 0, const string stubRlvUref = "", const ubigint tplRefFmncMStep = 0, const string stubTplRefFmncMStep = "", const uint start = 0, const string ftmStart = "");
	ubigint appendNewRecToRst(ListFmncQSepList& rst, FmncQSepList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMActivity = 0, const string stubRefFmncMActivity = "", const uint rlvIxVTbl = 0, const string srefRlvIxVTbl = "", const string titRlvIxVTbl = "", const ubigint rlvUref = 0, const string stubRlvUref = "", const ubigint tplRefFmncMStep = 0, const string stubTplRefFmncMStep = "", const uint start = 0, const string ftmStart = "");
	virtual void insertRst(ListFmncQSepList& rst);
	virtual void updateRec(FmncQSepList* rec);
	virtual void updateRst(ListFmncQSepList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSepList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSepList: C++ wrapper for table TblFmncQSepList (MySQL database)
  */
class MyTblFmncQSepList : public TblFmncQSepList, public MyTable {

public:
	MyTblFmncQSepList();
	~MyTblFmncQSepList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepList& rst);

	void insertRec(FmncQSepList* rec);
	void insertRst(ListFmncQSepList& rst);
	void updateRec(FmncQSepList* rec);
	void updateRst(ListFmncQSepList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSepList: C++ wrapper for table TblFmncQSepList (PgSQL database)
  */
class PgTblFmncQSepList : public TblFmncQSepList, public PgTable {

public:
	PgTblFmncQSepList();
	~PgTblFmncQSepList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSepList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSepList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSepList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSepList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepList& rst);

	void insertRec(FmncQSepList* rec);
	void insertRst(ListFmncQSepList& rst);
	void updateRec(FmncQSepList* rec);
	void updateRst(ListFmncQSepList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepList& rst);
};
// IP pgTbl --- END

#endif

