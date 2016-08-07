/**
  * \file FmncQFusMNTool.h
  * Dbs and XML wrapper for table TblFmncQFusMNTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFUSMNTOOL_H
#define FMNCQFUSMNTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFusMNTool: record of TblFmncQFusMNTool
  */
class FmncQFusMNTool {

public:
	FmncQFusMNTool(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint trnRefFmncMPerson = 0, const string stubTrnRefFmncMPerson = "", const string srefKLvl = "", const string titSrefKLvl = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	ubigint trnRefFmncMPerson;
	string stubTrnRefFmncMPerson;
	string srefKLvl;
	string titSrefKLvl;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQFusMNTool: recordset of TblFmncQFusMNTool
  */
class ListFmncQFusMNTool {

public:
	ListFmncQFusMNTool();
	ListFmncQFusMNTool(const ListFmncQFusMNTool& src);
	~ListFmncQFusMNTool();

	void clear();
	unsigned int size() const;
	void append(FmncQFusMNTool* rec);

	ListFmncQFusMNTool& operator=(const ListFmncQFusMNTool& src);

public:
	vector<FmncQFusMNTool*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFusMNTool: C++ wrapper for table TblFmncQFusMNTool
  */
class TblFmncQFusMNTool {

public:
	TblFmncQFusMNTool();
	virtual ~TblFmncQFusMNTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFusMNTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusMNTool& rst);

	virtual void insertRec(FmncQFusMNTool* rec);
	ubigint insertNewRec(FmncQFusMNTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint trnRefFmncMPerson = 0, const string stubTrnRefFmncMPerson = "", const string srefKLvl = "", const string titSrefKLvl = "");
	ubigint appendNewRecToRst(ListFmncQFusMNTool& rst, FmncQFusMNTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint trnRefFmncMPerson = 0, const string stubTrnRefFmncMPerson = "", const string srefKLvl = "", const string titSrefKLvl = "");
	virtual void insertRst(ListFmncQFusMNTool& rst);
	virtual void updateRec(FmncQFusMNTool* rec);
	virtual void updateRst(ListFmncQFusMNTool& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFusMNTool** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusMNTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFusMNTool: C++ wrapper for table TblFmncQFusMNTool (MySQL database)
  */
class MyTblFmncQFusMNTool : public TblFmncQFusMNTool, public MyTable {

public:
	MyTblFmncQFusMNTool();
	~MyTblFmncQFusMNTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFusMNTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusMNTool& rst);

	void insertRec(FmncQFusMNTool* rec);
	void insertRst(ListFmncQFusMNTool& rst);
	void updateRec(FmncQFusMNTool* rec);
	void updateRst(ListFmncQFusMNTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFusMNTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusMNTool& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFusMNTool: C++ wrapper for table TblFmncQFusMNTool (PgSQL database)
  */
class PgTblFmncQFusMNTool : public TblFmncQFusMNTool, public PgTable {

public:
	PgTblFmncQFusMNTool();
	~PgTblFmncQFusMNTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFusMNTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFusMNTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFusMNTool** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFusMNTool& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFusMNTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusMNTool& rst);

	void insertRec(FmncQFusMNTool* rec);
	void insertRst(ListFmncQFusMNTool& rst);
	void updateRec(FmncQFusMNTool* rec);
	void updateRst(ListFmncQFusMNTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFusMNTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusMNTool& rst);
};
// IP pgTbl --- END

#endif

