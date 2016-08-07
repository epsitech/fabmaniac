/**
  * \file FmncQOrgSvcMNTool.h
  * Dbs and XML wrapper for table TblFmncQOrgSvcMNTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGSVCMNTOOL_H
#define FMNCQORGSVCMNTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgSvcMNTool: record of TblFmncQOrgSvcMNTool
  */
class FmncQOrgSvcMNTool {

public:
	FmncQOrgSvcMNTool(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMPerson = "", const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	string stubsTrefFmncMPerson;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQOrgSvcMNTool: recordset of TblFmncQOrgSvcMNTool
  */
class ListFmncQOrgSvcMNTool {

public:
	ListFmncQOrgSvcMNTool();
	ListFmncQOrgSvcMNTool(const ListFmncQOrgSvcMNTool& src);
	~ListFmncQOrgSvcMNTool();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgSvcMNTool* rec);

	ListFmncQOrgSvcMNTool& operator=(const ListFmncQOrgSvcMNTool& src);

public:
	vector<FmncQOrgSvcMNTool*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgSvcMNTool: C++ wrapper for table TblFmncQOrgSvcMNTool
  */
class TblFmncQOrgSvcMNTool {

public:
	TblFmncQOrgSvcMNTool();
	virtual ~TblFmncQOrgSvcMNTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgSvcMNTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSvcMNTool& rst);

	virtual void insertRec(FmncQOrgSvcMNTool* rec);
	ubigint insertNewRec(FmncQOrgSvcMNTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMPerson = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQOrgSvcMNTool& rst, FmncQOrgSvcMNTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMPerson = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQOrgSvcMNTool& rst);
	virtual void updateRec(FmncQOrgSvcMNTool* rec);
	virtual void updateRst(ListFmncQOrgSvcMNTool& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgSvcMNTool** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSvcMNTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgSvcMNTool: C++ wrapper for table TblFmncQOrgSvcMNTool (MySQL database)
  */
class MyTblFmncQOrgSvcMNTool : public TblFmncQOrgSvcMNTool, public MyTable {

public:
	MyTblFmncQOrgSvcMNTool();
	~MyTblFmncQOrgSvcMNTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgSvcMNTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSvcMNTool& rst);

	void insertRec(FmncQOrgSvcMNTool* rec);
	void insertRst(ListFmncQOrgSvcMNTool& rst);
	void updateRec(FmncQOrgSvcMNTool* rec);
	void updateRst(ListFmncQOrgSvcMNTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgSvcMNTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSvcMNTool& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgSvcMNTool: C++ wrapper for table TblFmncQOrgSvcMNTool (PgSQL database)
  */
class PgTblFmncQOrgSvcMNTool : public TblFmncQOrgSvcMNTool, public PgTable {

public:
	PgTblFmncQOrgSvcMNTool();
	~PgTblFmncQOrgSvcMNTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgSvcMNTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgSvcMNTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgSvcMNTool** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgSvcMNTool& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgSvcMNTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgSvcMNTool& rst);

	void insertRec(FmncQOrgSvcMNTool* rec);
	void insertRst(ListFmncQOrgSvcMNTool& rst);
	void updateRec(FmncQOrgSvcMNTool* rec);
	void updateRst(ListFmncQOrgSvcMNTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgSvcMNTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgSvcMNTool& rst);
};
// IP pgTbl --- END

#endif

