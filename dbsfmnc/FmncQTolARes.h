/**
  * \file FmncQTolARes.h
  * Dbs and XML wrapper for table TblFmncQTolARes (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLARES_H
#define FMNCQTOLARES_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolARes: record of TblFmncQTolARes
  */
class FmncQTolARes {

public:
	FmncQTolARes(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefFmncMFabuser = 0, const string stubX1RefFmncMFabuser = "", const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "", const uint stopt = 0, const string ftmStopt = "", const string srefKRestype = "", const string titSrefKRestype = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint x1RefFmncMFabuser;
	string stubX1RefFmncMFabuser;
	uint startd;
	string ftmStartd;
	uint startt;
	string ftmStartt;
	uint stopt;
	string ftmStopt;
	string srefKRestype;
	string titSrefKRestype;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolARes: recordset of TblFmncQTolARes
  */
class ListFmncQTolARes {

public:
	ListFmncQTolARes();
	ListFmncQTolARes(const ListFmncQTolARes& src);
	~ListFmncQTolARes();

	void clear();
	unsigned int size() const;
	void append(FmncQTolARes* rec);

	ListFmncQTolARes& operator=(const ListFmncQTolARes& src);

public:
	vector<FmncQTolARes*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolARes: C++ wrapper for table TblFmncQTolARes
  */
class TblFmncQTolARes {

public:
	TblFmncQTolARes();
	virtual ~TblFmncQTolARes();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolARes** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolARes& rst);

	virtual void insertRec(FmncQTolARes* rec);
	ubigint insertNewRec(FmncQTolARes** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefFmncMFabuser = 0, const string stubX1RefFmncMFabuser = "", const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "", const uint stopt = 0, const string ftmStopt = "", const string srefKRestype = "", const string titSrefKRestype = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQTolARes& rst, FmncQTolARes** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefFmncMFabuser = 0, const string stubX1RefFmncMFabuser = "", const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "", const uint stopt = 0, const string ftmStopt = "", const string srefKRestype = "", const string titSrefKRestype = "", const string Comment = "");
	virtual void insertRst(ListFmncQTolARes& rst);
	virtual void updateRec(FmncQTolARes* rec);
	virtual void updateRst(ListFmncQTolARes& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolARes** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolARes& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolARes: C++ wrapper for table TblFmncQTolARes (MySQL database)
  */
class MyTblFmncQTolARes : public TblFmncQTolARes, public MyTable {

public:
	MyTblFmncQTolARes();
	~MyTblFmncQTolARes();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolARes** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolARes& rst);

	void insertRec(FmncQTolARes* rec);
	void insertRst(ListFmncQTolARes& rst);
	void updateRec(FmncQTolARes* rec);
	void updateRst(ListFmncQTolARes& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolARes** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolARes& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolARes: C++ wrapper for table TblFmncQTolARes (PgSQL database)
  */
class PgTblFmncQTolARes : public TblFmncQTolARes, public PgTable {

public:
	PgTblFmncQTolARes();
	~PgTblFmncQTolARes();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolARes** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolARes& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolARes** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolARes& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolARes** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolARes& rst);

	void insertRec(FmncQTolARes* rec);
	void insertRst(ListFmncQTolARes& rst);
	void updateRec(FmncQTolARes* rec);
	void updateRst(ListFmncQTolARes& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolARes** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolARes& rst);
};
// IP pgTbl --- END

#endif

