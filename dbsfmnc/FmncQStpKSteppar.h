/**
  * \file FmncQStpKSteppar.h
  * Dbs and XML wrapper for table TblFmncQStpKSteppar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPKSTEPPAR_H
#define FMNCQSTPKSTEPPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpKSteppar: record of TblFmncQStpKSteppar
  */
class FmncQStpKSteppar {

public:
	FmncQStpKSteppar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

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
  * ListFmncQStpKSteppar: recordset of TblFmncQStpKSteppar
  */
class ListFmncQStpKSteppar {

public:
	ListFmncQStpKSteppar();
	ListFmncQStpKSteppar(const ListFmncQStpKSteppar& src);
	~ListFmncQStpKSteppar();

	void clear();
	unsigned int size() const;
	void append(FmncQStpKSteppar* rec);

	ListFmncQStpKSteppar& operator=(const ListFmncQStpKSteppar& src);

public:
	vector<FmncQStpKSteppar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQStpKSteppar: C++ wrapper for table TblFmncQStpKSteppar
  */
class TblFmncQStpKSteppar {

public:
	TblFmncQStpKSteppar();
	virtual ~TblFmncQStpKSteppar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQStpKSteppar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpKSteppar& rst);

	virtual void insertRec(FmncQStpKSteppar* rec);
	ubigint insertNewRec(FmncQStpKSteppar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQStpKSteppar& rst, FmncQStpKSteppar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncQStpKSteppar& rst);
	virtual void updateRec(FmncQStpKSteppar* rec);
	virtual void updateRst(ListFmncQStpKSteppar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQStpKSteppar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpKSteppar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQStpKSteppar: C++ wrapper for table TblFmncQStpKSteppar (MySQL database)
  */
class MyTblFmncQStpKSteppar : public TblFmncQStpKSteppar, public MyTable {

public:
	MyTblFmncQStpKSteppar();
	~MyTblFmncQStpKSteppar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpKSteppar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpKSteppar& rst);

	void insertRec(FmncQStpKSteppar* rec);
	void insertRst(ListFmncQStpKSteppar& rst);
	void updateRec(FmncQStpKSteppar* rec);
	void updateRst(ListFmncQStpKSteppar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpKSteppar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpKSteppar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQStpKSteppar: C++ wrapper for table TblFmncQStpKSteppar (PgSQL database)
  */
class PgTblFmncQStpKSteppar : public TblFmncQStpKSteppar, public PgTable {

public:
	PgTblFmncQStpKSteppar();
	~PgTblFmncQStpKSteppar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQStpKSteppar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQStpKSteppar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQStpKSteppar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQStpKSteppar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpKSteppar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpKSteppar& rst);

	void insertRec(FmncQStpKSteppar* rec);
	void insertRst(ListFmncQStpKSteppar& rst);
	void updateRec(FmncQStpKSteppar* rec);
	void updateRst(ListFmncQStpKSteppar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpKSteppar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpKSteppar& rst);
};
// IP pgTbl --- END

#endif

