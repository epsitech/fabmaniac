/**
  * \file FmncQStpList.h
  * Dbs and XML wrapper for table TblFmncQStpList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPLIST_H
#define FMNCQSTPLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpList: record of TblFmncQStpList
  */
class FmncQStpList {

public:
	FmncQStpList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMActivity = 0, const string stubRefFmncMActivity = "", const uint rlvIxVTbl = 0, const string srefRlvIxVTbl = "", const string titRlvIxVTbl = "", const ubigint rlvUref = 0, const string stubRlvUref = "", const ubigint tplRefFmncMStep = 0, const string stubTplRefFmncMStep = "", const uint start = 0, const string ftmStart = "");

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
  * ListFmncQStpList: recordset of TblFmncQStpList
  */
class ListFmncQStpList {

public:
	ListFmncQStpList();
	ListFmncQStpList(const ListFmncQStpList& src);
	~ListFmncQStpList();

	void clear();
	unsigned int size() const;
	void append(FmncQStpList* rec);

	ListFmncQStpList& operator=(const ListFmncQStpList& src);

public:
	vector<FmncQStpList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQStpList: C++ wrapper for table TblFmncQStpList
  */
class TblFmncQStpList {

public:
	TblFmncQStpList();
	virtual ~TblFmncQStpList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQStpList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpList& rst);

	virtual void insertRec(FmncQStpList* rec);
	ubigint insertNewRec(FmncQStpList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMActivity = 0, const string stubRefFmncMActivity = "", const uint rlvIxVTbl = 0, const string srefRlvIxVTbl = "", const string titRlvIxVTbl = "", const ubigint rlvUref = 0, const string stubRlvUref = "", const ubigint tplRefFmncMStep = 0, const string stubTplRefFmncMStep = "", const uint start = 0, const string ftmStart = "");
	ubigint appendNewRecToRst(ListFmncQStpList& rst, FmncQStpList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refFmncMActivity = 0, const string stubRefFmncMActivity = "", const uint rlvIxVTbl = 0, const string srefRlvIxVTbl = "", const string titRlvIxVTbl = "", const ubigint rlvUref = 0, const string stubRlvUref = "", const ubigint tplRefFmncMStep = 0, const string stubTplRefFmncMStep = "", const uint start = 0, const string ftmStart = "");
	virtual void insertRst(ListFmncQStpList& rst);
	virtual void updateRec(FmncQStpList* rec);
	virtual void updateRst(ListFmncQStpList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQStpList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQStpList: C++ wrapper for table TblFmncQStpList (MySQL database)
  */
class MyTblFmncQStpList : public TblFmncQStpList, public MyTable {

public:
	MyTblFmncQStpList();
	~MyTblFmncQStpList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpList& rst);

	void insertRec(FmncQStpList* rec);
	void insertRst(ListFmncQStpList& rst);
	void updateRec(FmncQStpList* rec);
	void updateRst(ListFmncQStpList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQStpList: C++ wrapper for table TblFmncQStpList (PgSQL database)
  */
class PgTblFmncQStpList : public TblFmncQStpList, public PgTable {

public:
	PgTblFmncQStpList();
	~PgTblFmncQStpList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQStpList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQStpList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQStpList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQStpList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpList& rst);

	void insertRec(FmncQStpList* rec);
	void insertRst(ListFmncQStpList& rst);
	void updateRec(FmncQStpList* rec);
	void updateRst(ListFmncQStpList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpList& rst);
};
// IP pgTbl --- END

#endif

