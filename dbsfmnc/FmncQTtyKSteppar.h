/**
  * \file FmncQTtyKSteppar.h
  * Dbs and XML wrapper for table TblFmncQTtyKSteppar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYKSTEPPAR_H
#define FMNCQTTYKSTEPPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyKSteppar: record of TblFmncQTtyKSteppar
  */
class FmncQTtyKSteppar {

public:
	FmncQTtyKSteppar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

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
  * ListFmncQTtyKSteppar: recordset of TblFmncQTtyKSteppar
  */
class ListFmncQTtyKSteppar {

public:
	ListFmncQTtyKSteppar();
	ListFmncQTtyKSteppar(const ListFmncQTtyKSteppar& src);
	~ListFmncQTtyKSteppar();

	void clear();
	unsigned int size() const;
	void append(FmncQTtyKSteppar* rec);

	ListFmncQTtyKSteppar& operator=(const ListFmncQTtyKSteppar& src);

public:
	vector<FmncQTtyKSteppar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTtyKSteppar: C++ wrapper for table TblFmncQTtyKSteppar
  */
class TblFmncQTtyKSteppar {

public:
	TblFmncQTtyKSteppar();
	virtual ~TblFmncQTtyKSteppar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTtyKSteppar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyKSteppar& rst);

	virtual void insertRec(FmncQTtyKSteppar* rec);
	ubigint insertNewRec(FmncQTtyKSteppar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQTtyKSteppar& rst, FmncQTtyKSteppar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncQTtyKSteppar& rst);
	virtual void updateRec(FmncQTtyKSteppar* rec);
	virtual void updateRst(ListFmncQTtyKSteppar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTtyKSteppar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyKSteppar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTtyKSteppar: C++ wrapper for table TblFmncQTtyKSteppar (MySQL database)
  */
class MyTblFmncQTtyKSteppar : public TblFmncQTtyKSteppar, public MyTable {

public:
	MyTblFmncQTtyKSteppar();
	~MyTblFmncQTtyKSteppar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyKSteppar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyKSteppar& rst);

	void insertRec(FmncQTtyKSteppar* rec);
	void insertRst(ListFmncQTtyKSteppar& rst);
	void updateRec(FmncQTtyKSteppar* rec);
	void updateRst(ListFmncQTtyKSteppar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyKSteppar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyKSteppar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTtyKSteppar: C++ wrapper for table TblFmncQTtyKSteppar (PgSQL database)
  */
class PgTblFmncQTtyKSteppar : public TblFmncQTtyKSteppar, public PgTable {

public:
	PgTblFmncQTtyKSteppar();
	~PgTblFmncQTtyKSteppar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTtyKSteppar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTtyKSteppar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTtyKSteppar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTtyKSteppar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyKSteppar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyKSteppar& rst);

	void insertRec(FmncQTtyKSteppar* rec);
	void insertRst(ListFmncQTtyKSteppar& rst);
	void updateRec(FmncQTtyKSteppar* rec);
	void updateRst(ListFmncQTtyKSteppar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyKSteppar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyKSteppar& rst);
};
// IP pgTbl --- END

#endif

