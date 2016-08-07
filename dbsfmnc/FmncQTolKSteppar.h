/**
  * \file FmncQTolKSteppar.h
  * Dbs and XML wrapper for table TblFmncQTolKSteppar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLKSTEPPAR_H
#define FMNCQTOLKSTEPPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolKSteppar: record of TblFmncQTolKSteppar
  */
class FmncQTolKSteppar {

public:
	FmncQTolKSteppar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint klsNum;
	bool Fixed;
	string yesnoFixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolKSteppar: recordset of TblFmncQTolKSteppar
  */
class ListFmncQTolKSteppar {

public:
	ListFmncQTolKSteppar();
	ListFmncQTolKSteppar(const ListFmncQTolKSteppar& src);
	~ListFmncQTolKSteppar();

	void clear();
	unsigned int size() const;
	void append(FmncQTolKSteppar* rec);

	ListFmncQTolKSteppar& operator=(const ListFmncQTolKSteppar& src);

public:
	vector<FmncQTolKSteppar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolKSteppar: C++ wrapper for table TblFmncQTolKSteppar
  */
class TblFmncQTolKSteppar {

public:
	TblFmncQTolKSteppar();
	virtual ~TblFmncQTolKSteppar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolKSteppar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolKSteppar& rst);

	virtual void insertRec(FmncQTolKSteppar* rec);
	ubigint insertNewRec(FmncQTolKSteppar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQTolKSteppar& rst, FmncQTolKSteppar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncQTolKSteppar& rst);
	virtual void updateRec(FmncQTolKSteppar* rec);
	virtual void updateRst(ListFmncQTolKSteppar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolKSteppar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolKSteppar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolKSteppar: C++ wrapper for table TblFmncQTolKSteppar (MySQL database)
  */
class MyTblFmncQTolKSteppar : public TblFmncQTolKSteppar, public MyTable {

public:
	MyTblFmncQTolKSteppar();
	~MyTblFmncQTolKSteppar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolKSteppar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolKSteppar& rst);

	void insertRec(FmncQTolKSteppar* rec);
	void insertRst(ListFmncQTolKSteppar& rst);
	void updateRec(FmncQTolKSteppar* rec);
	void updateRst(ListFmncQTolKSteppar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolKSteppar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolKSteppar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolKSteppar: C++ wrapper for table TblFmncQTolKSteppar (PgSQL database)
  */
class PgTblFmncQTolKSteppar : public TblFmncQTolKSteppar, public PgTable {

public:
	PgTblFmncQTolKSteppar();
	~PgTblFmncQTolKSteppar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolKSteppar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolKSteppar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolKSteppar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolKSteppar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolKSteppar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolKSteppar& rst);

	void insertRec(FmncQTolKSteppar* rec);
	void insertRst(ListFmncQTolKSteppar& rst);
	void updateRec(FmncQTolKSteppar* rec);
	void updateRst(ListFmncQTolKSteppar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolKSteppar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolKSteppar& rst);
};
// IP pgTbl --- END

#endif

