/**
  * \file FmncQPrsMNOrg.h
  * Dbs and XML wrapper for table TblFmncQPrsMNOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSMNORG_H
#define FMNCQPRSMNORG_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsMNOrg: record of TblFmncQPrsMNOrg
  */
class FmncQPrsMNOrg {

public:
	FmncQPrsMNOrg(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x1Stopd = 0, const string ftmX1Stopd = "", const string srefKFunction = "", const string titSrefKFunction = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint x1Startd;
	string ftmX1Startd;
	uint x1Stopd;
	string ftmX1Stopd;
	string srefKFunction;
	string titSrefKFunction;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPrsMNOrg: recordset of TblFmncQPrsMNOrg
  */
class ListFmncQPrsMNOrg {

public:
	ListFmncQPrsMNOrg();
	ListFmncQPrsMNOrg(const ListFmncQPrsMNOrg& src);
	~ListFmncQPrsMNOrg();

	void clear();
	unsigned int size() const;
	void append(FmncQPrsMNOrg* rec);

	ListFmncQPrsMNOrg& operator=(const ListFmncQPrsMNOrg& src);

public:
	vector<FmncQPrsMNOrg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPrsMNOrg: C++ wrapper for table TblFmncQPrsMNOrg
  */
class TblFmncQPrsMNOrg {

public:
	TblFmncQPrsMNOrg();
	virtual ~TblFmncQPrsMNOrg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPrsMNOrg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsMNOrg& rst);

	virtual void insertRec(FmncQPrsMNOrg* rec);
	ubigint insertNewRec(FmncQPrsMNOrg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x1Stopd = 0, const string ftmX1Stopd = "", const string srefKFunction = "", const string titSrefKFunction = "");
	ubigint appendNewRecToRst(ListFmncQPrsMNOrg& rst, FmncQPrsMNOrg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x1Stopd = 0, const string ftmX1Stopd = "", const string srefKFunction = "", const string titSrefKFunction = "");
	virtual void insertRst(ListFmncQPrsMNOrg& rst);
	virtual void updateRec(FmncQPrsMNOrg* rec);
	virtual void updateRst(ListFmncQPrsMNOrg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPrsMNOrg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsMNOrg& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPrsMNOrg: C++ wrapper for table TblFmncQPrsMNOrg (MySQL database)
  */
class MyTblFmncQPrsMNOrg : public TblFmncQPrsMNOrg, public MyTable {

public:
	MyTblFmncQPrsMNOrg();
	~MyTblFmncQPrsMNOrg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsMNOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsMNOrg& rst);

	void insertRec(FmncQPrsMNOrg* rec);
	void insertRst(ListFmncQPrsMNOrg& rst);
	void updateRec(FmncQPrsMNOrg* rec);
	void updateRst(ListFmncQPrsMNOrg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsMNOrg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsMNOrg& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPrsMNOrg: C++ wrapper for table TblFmncQPrsMNOrg (PgSQL database)
  */
class PgTblFmncQPrsMNOrg : public TblFmncQPrsMNOrg, public PgTable {

public:
	PgTblFmncQPrsMNOrg();
	~PgTblFmncQPrsMNOrg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPrsMNOrg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPrsMNOrg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPrsMNOrg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPrsMNOrg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsMNOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsMNOrg& rst);

	void insertRec(FmncQPrsMNOrg* rec);
	void insertRst(ListFmncQPrsMNOrg& rst);
	void updateRec(FmncQPrsMNOrg* rec);
	void updateRst(ListFmncQPrsMNOrg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsMNOrg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsMNOrg& rst);
};
// IP pgTbl --- END

#endif

