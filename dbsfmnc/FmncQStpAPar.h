/**
  * \file FmncQStpAPar.h
  * Dbs and XML wrapper for table TblFmncQStpAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPAPAR_H
#define FMNCQSTPAPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpAPar: record of TblFmncQStpAPar
  */
class FmncQStpAPar {

public:
	FmncQStpAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKSteppar = "", const string titX1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const string srefX2IxVTbl = "", const string titX2IxVTbl = "", const ubigint x2Uref = 0, const string stubX2Uref = "", const string Val = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x1OsrefFmncKSteppar;
	string titX1OsrefFmncKSteppar;
	uint x2IxVTbl;
	string srefX2IxVTbl;
	string titX2IxVTbl;
	ubigint x2Uref;
	string stubX2Uref;
	string Val;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQStpAPar: recordset of TblFmncQStpAPar
  */
class ListFmncQStpAPar {

public:
	ListFmncQStpAPar();
	ListFmncQStpAPar(const ListFmncQStpAPar& src);
	~ListFmncQStpAPar();

	void clear();
	unsigned int size() const;
	void append(FmncQStpAPar* rec);

	ListFmncQStpAPar& operator=(const ListFmncQStpAPar& src);

public:
	vector<FmncQStpAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQStpAPar: C++ wrapper for table TblFmncQStpAPar
  */
class TblFmncQStpAPar {

public:
	TblFmncQStpAPar();
	virtual ~TblFmncQStpAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQStpAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpAPar& rst);

	virtual void insertRec(FmncQStpAPar* rec);
	ubigint insertNewRec(FmncQStpAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKSteppar = "", const string titX1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const string srefX2IxVTbl = "", const string titX2IxVTbl = "", const ubigint x2Uref = 0, const string stubX2Uref = "", const string Val = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQStpAPar& rst, FmncQStpAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKSteppar = "", const string titX1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const string srefX2IxVTbl = "", const string titX2IxVTbl = "", const ubigint x2Uref = 0, const string stubX2Uref = "", const string Val = "", const string Comment = "");
	virtual void insertRst(ListFmncQStpAPar& rst);
	virtual void updateRec(FmncQStpAPar* rec);
	virtual void updateRst(ListFmncQStpAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQStpAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpAPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQStpAPar: C++ wrapper for table TblFmncQStpAPar (MySQL database)
  */
class MyTblFmncQStpAPar : public TblFmncQStpAPar, public MyTable {

public:
	MyTblFmncQStpAPar();
	~MyTblFmncQStpAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpAPar& rst);

	void insertRec(FmncQStpAPar* rec);
	void insertRst(ListFmncQStpAPar& rst);
	void updateRec(FmncQStpAPar* rec);
	void updateRst(ListFmncQStpAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpAPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQStpAPar: C++ wrapper for table TblFmncQStpAPar (PgSQL database)
  */
class PgTblFmncQStpAPar : public TblFmncQStpAPar, public PgTable {

public:
	PgTblFmncQStpAPar();
	~PgTblFmncQStpAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQStpAPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQStpAPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQStpAPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQStpAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpAPar& rst);

	void insertRec(FmncQStpAPar* rec);
	void insertRst(ListFmncQStpAPar& rst);
	void updateRec(FmncQStpAPar* rec);
	void updateRst(ListFmncQStpAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpAPar& rst);
};
// IP pgTbl --- END

#endif

