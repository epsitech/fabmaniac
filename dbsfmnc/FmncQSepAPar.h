/**
  * \file FmncQSepAPar.h
  * Dbs and XML wrapper for table TblFmncQSepAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPAPAR_H
#define FMNCQSEPAPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepAPar: record of TblFmncQSepAPar
  */
class FmncQSepAPar {

public:
	FmncQSepAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKSteppar = "", const string titX1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const string srefX2IxVTbl = "", const string titX2IxVTbl = "", const ubigint x2Uref = 0, const string stubX2Uref = "", const string Val = "", const string Comment = "");

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
  * ListFmncQSepAPar: recordset of TblFmncQSepAPar
  */
class ListFmncQSepAPar {

public:
	ListFmncQSepAPar();
	ListFmncQSepAPar(const ListFmncQSepAPar& src);
	~ListFmncQSepAPar();

	void clear();
	unsigned int size() const;
	void append(FmncQSepAPar* rec);

	ListFmncQSepAPar& operator=(const ListFmncQSepAPar& src);

public:
	vector<FmncQSepAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSepAPar: C++ wrapper for table TblFmncQSepAPar
  */
class TblFmncQSepAPar {

public:
	TblFmncQSepAPar();
	virtual ~TblFmncQSepAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSepAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepAPar& rst);

	virtual void insertRec(FmncQSepAPar* rec);
	ubigint insertNewRec(FmncQSepAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKSteppar = "", const string titX1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const string srefX2IxVTbl = "", const string titX2IxVTbl = "", const ubigint x2Uref = 0, const string stubX2Uref = "", const string Val = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQSepAPar& rst, FmncQSepAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKSteppar = "", const string titX1OsrefFmncKSteppar = "", const uint x2IxVTbl = 0, const string srefX2IxVTbl = "", const string titX2IxVTbl = "", const ubigint x2Uref = 0, const string stubX2Uref = "", const string Val = "", const string Comment = "");
	virtual void insertRst(ListFmncQSepAPar& rst);
	virtual void updateRec(FmncQSepAPar* rec);
	virtual void updateRst(ListFmncQSepAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSepAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepAPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSepAPar: C++ wrapper for table TblFmncQSepAPar (MySQL database)
  */
class MyTblFmncQSepAPar : public TblFmncQSepAPar, public MyTable {

public:
	MyTblFmncQSepAPar();
	~MyTblFmncQSepAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepAPar& rst);

	void insertRec(FmncQSepAPar* rec);
	void insertRst(ListFmncQSepAPar& rst);
	void updateRec(FmncQSepAPar* rec);
	void updateRst(ListFmncQSepAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepAPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSepAPar: C++ wrapper for table TblFmncQSepAPar (PgSQL database)
  */
class PgTblFmncQSepAPar : public TblFmncQSepAPar, public PgTable {

public:
	PgTblFmncQSepAPar();
	~PgTblFmncQSepAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSepAPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSepAPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSepAPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSepAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepAPar& rst);

	void insertRec(FmncQSepAPar* rec);
	void insertRst(ListFmncQSepAPar& rst);
	void updateRec(FmncQSepAPar* rec);
	void updateRst(ListFmncQSepAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepAPar& rst);
};
// IP pgTbl --- END

#endif

