/**
  * \file FmncQTtyList.h
  * Dbs and XML wrapper for table TblFmncQTtyList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYLIST_H
#define FMNCQTTYLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyList: record of TblFmncQTtyList
  */
class FmncQTtyList {

public:
	FmncQTtyList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint supRefFmncMTooltype = 0, const string stubSupRefFmncMTooltype = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string Title;
	ubigint supRefFmncMTooltype;
	string stubSupRefFmncMTooltype;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTtyList: recordset of TblFmncQTtyList
  */
class ListFmncQTtyList {

public:
	ListFmncQTtyList();
	ListFmncQTtyList(const ListFmncQTtyList& src);
	~ListFmncQTtyList();

	void clear();
	unsigned int size() const;
	void append(FmncQTtyList* rec);

	ListFmncQTtyList& operator=(const ListFmncQTtyList& src);

public:
	vector<FmncQTtyList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTtyList: C++ wrapper for table TblFmncQTtyList
  */
class TblFmncQTtyList {

public:
	TblFmncQTtyList();
	virtual ~TblFmncQTtyList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTtyList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyList& rst);

	virtual void insertRec(FmncQTtyList* rec);
	ubigint insertNewRec(FmncQTtyList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint supRefFmncMTooltype = 0, const string stubSupRefFmncMTooltype = "");
	ubigint appendNewRecToRst(ListFmncQTtyList& rst, FmncQTtyList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint supRefFmncMTooltype = 0, const string stubSupRefFmncMTooltype = "");
	virtual void insertRst(ListFmncQTtyList& rst);
	virtual void updateRec(FmncQTtyList* rec);
	virtual void updateRst(ListFmncQTtyList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTtyList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTtyList: C++ wrapper for table TblFmncQTtyList (MySQL database)
  */
class MyTblFmncQTtyList : public TblFmncQTtyList, public MyTable {

public:
	MyTblFmncQTtyList();
	~MyTblFmncQTtyList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyList& rst);

	void insertRec(FmncQTtyList* rec);
	void insertRst(ListFmncQTtyList& rst);
	void updateRec(FmncQTtyList* rec);
	void updateRst(ListFmncQTtyList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTtyList: C++ wrapper for table TblFmncQTtyList (PgSQL database)
  */
class PgTblFmncQTtyList : public TblFmncQTtyList, public PgTable {

public:
	PgTblFmncQTtyList();
	~PgTblFmncQTtyList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTtyList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTtyList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTtyList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTtyList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyList& rst);

	void insertRec(FmncQTtyList* rec);
	void insertRst(ListFmncQTtyList& rst);
	void updateRec(FmncQTtyList* rec);
	void updateRst(ListFmncQTtyList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyList& rst);
};
// IP pgTbl --- END

#endif

