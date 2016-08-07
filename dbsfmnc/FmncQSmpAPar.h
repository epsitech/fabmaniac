/**
  * \file FmncQSmpAPar.h
  * Dbs and XML wrapper for table TblFmncQSmpAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPAPAR_H
#define FMNCQSMPAPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpAPar: record of TblFmncQSmpAPar
  */
class FmncQSmpAPar {

public:
	FmncQSmpAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKKey = "", const string titX1SrefKKey = "", const string osrefKVal = "", const string titOsrefKVal = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x1SrefKKey;
	string titX1SrefKKey;
	string osrefKVal;
	string titOsrefKVal;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQSmpAPar: recordset of TblFmncQSmpAPar
  */
class ListFmncQSmpAPar {

public:
	ListFmncQSmpAPar();
	ListFmncQSmpAPar(const ListFmncQSmpAPar& src);
	~ListFmncQSmpAPar();

	void clear();
	unsigned int size() const;
	void append(FmncQSmpAPar* rec);

	ListFmncQSmpAPar& operator=(const ListFmncQSmpAPar& src);

public:
	vector<FmncQSmpAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSmpAPar: C++ wrapper for table TblFmncQSmpAPar
  */
class TblFmncQSmpAPar {

public:
	TblFmncQSmpAPar();
	virtual ~TblFmncQSmpAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSmpAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpAPar& rst);

	virtual void insertRec(FmncQSmpAPar* rec);
	ubigint insertNewRec(FmncQSmpAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKKey = "", const string titX1SrefKKey = "", const string osrefKVal = "", const string titOsrefKVal = "");
	ubigint appendNewRecToRst(ListFmncQSmpAPar& rst, FmncQSmpAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKKey = "", const string titX1SrefKKey = "", const string osrefKVal = "", const string titOsrefKVal = "");
	virtual void insertRst(ListFmncQSmpAPar& rst);
	virtual void updateRec(FmncQSmpAPar* rec);
	virtual void updateRst(ListFmncQSmpAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSmpAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpAPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSmpAPar: C++ wrapper for table TblFmncQSmpAPar (MySQL database)
  */
class MyTblFmncQSmpAPar : public TblFmncQSmpAPar, public MyTable {

public:
	MyTblFmncQSmpAPar();
	~MyTblFmncQSmpAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpAPar& rst);

	void insertRec(FmncQSmpAPar* rec);
	void insertRst(ListFmncQSmpAPar& rst);
	void updateRec(FmncQSmpAPar* rec);
	void updateRst(ListFmncQSmpAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpAPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSmpAPar: C++ wrapper for table TblFmncQSmpAPar (PgSQL database)
  */
class PgTblFmncQSmpAPar : public TblFmncQSmpAPar, public PgTable {

public:
	PgTblFmncQSmpAPar();
	~PgTblFmncQSmpAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSmpAPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSmpAPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSmpAPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSmpAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpAPar& rst);

	void insertRec(FmncQSmpAPar* rec);
	void insertRst(ListFmncQSmpAPar& rst);
	void updateRec(FmncQSmpAPar* rec);
	void updateRst(ListFmncQSmpAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpAPar& rst);
};
// IP pgTbl --- END

#endif

