/**
  * \file FmncQTolAAvl.h
  * Dbs and XML wrapper for table TblFmncQTolAAvl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLAAVL_H
#define FMNCQTOLAAVL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolAAvl: record of TblFmncQTolAAvl
  */
class FmncQTolAAvl {

public:
	FmncQTolAAvl(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x2IxVWkday = 0, const string srefX2IxVWkday = "", const uint x3Startt = 0, const string ftmX3Startt = "", const uint x3Stopt = 0, const string ftmX3Stopt = "", const string srefKAvltype = "", const string titSrefKAvltype = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint x1Startd;
	string ftmX1Startd;
	uint x2IxVWkday;
	string srefX2IxVWkday;
	uint x3Startt;
	string ftmX3Startt;
	uint x3Stopt;
	string ftmX3Stopt;
	string srefKAvltype;
	string titSrefKAvltype;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolAAvl: recordset of TblFmncQTolAAvl
  */
class ListFmncQTolAAvl {

public:
	ListFmncQTolAAvl();
	ListFmncQTolAAvl(const ListFmncQTolAAvl& src);
	~ListFmncQTolAAvl();

	void clear();
	unsigned int size() const;
	void append(FmncQTolAAvl* rec);

	ListFmncQTolAAvl& operator=(const ListFmncQTolAAvl& src);

public:
	vector<FmncQTolAAvl*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolAAvl: C++ wrapper for table TblFmncQTolAAvl
  */
class TblFmncQTolAAvl {

public:
	TblFmncQTolAAvl();
	virtual ~TblFmncQTolAAvl();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolAAvl** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAAvl& rst);

	virtual void insertRec(FmncQTolAAvl* rec);
	ubigint insertNewRec(FmncQTolAAvl** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x2IxVWkday = 0, const string srefX2IxVWkday = "", const uint x3Startt = 0, const string ftmX3Startt = "", const uint x3Stopt = 0, const string ftmX3Stopt = "", const string srefKAvltype = "", const string titSrefKAvltype = "");
	ubigint appendNewRecToRst(ListFmncQTolAAvl& rst, FmncQTolAAvl** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x2IxVWkday = 0, const string srefX2IxVWkday = "", const uint x3Startt = 0, const string ftmX3Startt = "", const uint x3Stopt = 0, const string ftmX3Stopt = "", const string srefKAvltype = "", const string titSrefKAvltype = "");
	virtual void insertRst(ListFmncQTolAAvl& rst);
	virtual void updateRec(FmncQTolAAvl* rec);
	virtual void updateRst(ListFmncQTolAAvl& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolAAvl** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAAvl& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolAAvl: C++ wrapper for table TblFmncQTolAAvl (MySQL database)
  */
class MyTblFmncQTolAAvl : public TblFmncQTolAAvl, public MyTable {

public:
	MyTblFmncQTolAAvl();
	~MyTblFmncQTolAAvl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolAAvl** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAAvl& rst);

	void insertRec(FmncQTolAAvl* rec);
	void insertRst(ListFmncQTolAAvl& rst);
	void updateRec(FmncQTolAAvl* rec);
	void updateRst(ListFmncQTolAAvl& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolAAvl** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAAvl& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolAAvl: C++ wrapper for table TblFmncQTolAAvl (PgSQL database)
  */
class PgTblFmncQTolAAvl : public TblFmncQTolAAvl, public PgTable {

public:
	PgTblFmncQTolAAvl();
	~PgTblFmncQTolAAvl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolAAvl** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolAAvl& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolAAvl** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolAAvl& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolAAvl** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAAvl& rst);

	void insertRec(FmncQTolAAvl* rec);
	void insertRst(ListFmncQTolAAvl& rst);
	void updateRec(FmncQTolAAvl* rec);
	void updateRst(ListFmncQTolAAvl& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolAAvl** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAAvl& rst);
};
// IP pgTbl --- END

#endif

