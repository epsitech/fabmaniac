/**
  * \file FmncQFabFab1NTool.h
  * Dbs and XML wrapper for table TblFmncQFabFab1NTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFABFAB1NTOOL_H
#define FMNCQFABFAB1NTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFabFab1NTool: record of TblFmncQFabFab1NTool
  */
class FmncQFabFab1NTool {

public:
	FmncQFabFab1NTool(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const string stubsSrefFmncMPerson = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	string stubsSrefFmncMPerson;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQFabFab1NTool: recordset of TblFmncQFabFab1NTool
  */
class ListFmncQFabFab1NTool {

public:
	ListFmncQFabFab1NTool();
	ListFmncQFabFab1NTool(const ListFmncQFabFab1NTool& src);
	~ListFmncQFabFab1NTool();

	void clear();
	unsigned int size() const;
	void append(FmncQFabFab1NTool* rec);

	ListFmncQFabFab1NTool& operator=(const ListFmncQFabFab1NTool& src);

public:
	vector<FmncQFabFab1NTool*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFabFab1NTool: C++ wrapper for table TblFmncQFabFab1NTool
  */
class TblFmncQFabFab1NTool {

public:
	TblFmncQFabFab1NTool();
	virtual ~TblFmncQFabFab1NTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFabFab1NTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabFab1NTool& rst);

	virtual void insertRec(FmncQFabFab1NTool* rec);
	ubigint insertNewRec(FmncQFabFab1NTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const string stubsSrefFmncMPerson = "");
	ubigint appendNewRecToRst(ListFmncQFabFab1NTool& rst, FmncQFabFab1NTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const string stubsSrefFmncMPerson = "");
	virtual void insertRst(ListFmncQFabFab1NTool& rst);
	virtual void updateRec(FmncQFabFab1NTool* rec);
	virtual void updateRst(ListFmncQFabFab1NTool& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFabFab1NTool** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabFab1NTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFabFab1NTool: C++ wrapper for table TblFmncQFabFab1NTool (MySQL database)
  */
class MyTblFmncQFabFab1NTool : public TblFmncQFabFab1NTool, public MyTable {

public:
	MyTblFmncQFabFab1NTool();
	~MyTblFmncQFabFab1NTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFabFab1NTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabFab1NTool& rst);

	void insertRec(FmncQFabFab1NTool* rec);
	void insertRst(ListFmncQFabFab1NTool& rst);
	void updateRec(FmncQFabFab1NTool* rec);
	void updateRst(ListFmncQFabFab1NTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFabFab1NTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabFab1NTool& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFabFab1NTool: C++ wrapper for table TblFmncQFabFab1NTool (PgSQL database)
  */
class PgTblFmncQFabFab1NTool : public TblFmncQFabFab1NTool, public PgTable {

public:
	PgTblFmncQFabFab1NTool();
	~PgTblFmncQFabFab1NTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFabFab1NTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFabFab1NTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFabFab1NTool** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFabFab1NTool& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFabFab1NTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabFab1NTool& rst);

	void insertRec(FmncQFabFab1NTool* rec);
	void insertRst(ListFmncQFabFab1NTool& rst);
	void updateRec(FmncQFabFab1NTool* rec);
	void updateRst(ListFmncQFabFab1NTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFabFab1NTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabFab1NTool& rst);
};
// IP pgTbl --- END

#endif

