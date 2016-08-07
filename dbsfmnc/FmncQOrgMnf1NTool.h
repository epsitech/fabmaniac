/**
  * \file FmncQOrgMnf1NTool.h
  * Dbs and XML wrapper for table TblFmncQOrgMnf1NTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGMNF1NTOOL_H
#define FMNCQORGMNF1NTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgMnf1NTool: record of TblFmncQOrgMnf1NTool
  */
class FmncQOrgMnf1NTool {

public:
	FmncQOrgMnf1NTool(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const string stubsSrefFmncMPerson = "");

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
  * ListFmncQOrgMnf1NTool: recordset of TblFmncQOrgMnf1NTool
  */
class ListFmncQOrgMnf1NTool {

public:
	ListFmncQOrgMnf1NTool();
	ListFmncQOrgMnf1NTool(const ListFmncQOrgMnf1NTool& src);
	~ListFmncQOrgMnf1NTool();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgMnf1NTool* rec);

	ListFmncQOrgMnf1NTool& operator=(const ListFmncQOrgMnf1NTool& src);

public:
	vector<FmncQOrgMnf1NTool*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgMnf1NTool: C++ wrapper for table TblFmncQOrgMnf1NTool
  */
class TblFmncQOrgMnf1NTool {

public:
	TblFmncQOrgMnf1NTool();
	virtual ~TblFmncQOrgMnf1NTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgMnf1NTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMnf1NTool& rst);

	virtual void insertRec(FmncQOrgMnf1NTool* rec);
	ubigint insertNewRec(FmncQOrgMnf1NTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const string stubsSrefFmncMPerson = "");
	ubigint appendNewRecToRst(ListFmncQOrgMnf1NTool& rst, FmncQOrgMnf1NTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const string stubsSrefFmncMPerson = "");
	virtual void insertRst(ListFmncQOrgMnf1NTool& rst);
	virtual void updateRec(FmncQOrgMnf1NTool* rec);
	virtual void updateRst(ListFmncQOrgMnf1NTool& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgMnf1NTool** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMnf1NTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgMnf1NTool: C++ wrapper for table TblFmncQOrgMnf1NTool (MySQL database)
  */
class MyTblFmncQOrgMnf1NTool : public TblFmncQOrgMnf1NTool, public MyTable {

public:
	MyTblFmncQOrgMnf1NTool();
	~MyTblFmncQOrgMnf1NTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgMnf1NTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMnf1NTool& rst);

	void insertRec(FmncQOrgMnf1NTool* rec);
	void insertRst(ListFmncQOrgMnf1NTool& rst);
	void updateRec(FmncQOrgMnf1NTool* rec);
	void updateRst(ListFmncQOrgMnf1NTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgMnf1NTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMnf1NTool& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgMnf1NTool: C++ wrapper for table TblFmncQOrgMnf1NTool (PgSQL database)
  */
class PgTblFmncQOrgMnf1NTool : public TblFmncQOrgMnf1NTool, public PgTable {

public:
	PgTblFmncQOrgMnf1NTool();
	~PgTblFmncQOrgMnf1NTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgMnf1NTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgMnf1NTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgMnf1NTool** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgMnf1NTool& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgMnf1NTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMnf1NTool& rst);

	void insertRec(FmncQOrgMnf1NTool* rec);
	void insertRst(ListFmncQOrgMnf1NTool& rst);
	void updateRec(FmncQOrgMnf1NTool* rec);
	void updateRst(ListFmncQOrgMnf1NTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgMnf1NTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMnf1NTool& rst);
};
// IP pgTbl --- END

#endif

