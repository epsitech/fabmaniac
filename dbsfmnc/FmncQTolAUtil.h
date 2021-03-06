/**
  * \file FmncQTolAUtil.h
  * Dbs and XML wrapper for table TblFmncQTolAUtil (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLAUTIL_H
#define FMNCQTOLAUTIL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolAUtil: record of TblFmncQTolAUtil
  */
class FmncQTolAUtil {

public:
	FmncQTolAUtil(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefFmncMFabproject = 0, const string stubX1RefFmncMFabproject = "", const ubigint x2RefFmncMFabuser = 0, const string stubX2RefFmncMFabuser = "", const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "", const uint stopt = 0, const string ftmStopt = "", const double Unitprice = 0.0, const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint x1RefFmncMFabproject;
	string stubX1RefFmncMFabproject;
	ubigint x2RefFmncMFabuser;
	string stubX2RefFmncMFabuser;
	uint startd;
	string ftmStartd;
	uint startt;
	string ftmStartt;
	uint stopt;
	string ftmStopt;
	double Unitprice;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolAUtil: recordset of TblFmncQTolAUtil
  */
class ListFmncQTolAUtil {

public:
	ListFmncQTolAUtil();
	ListFmncQTolAUtil(const ListFmncQTolAUtil& src);
	~ListFmncQTolAUtil();

	void clear();
	unsigned int size() const;
	void append(FmncQTolAUtil* rec);

	ListFmncQTolAUtil& operator=(const ListFmncQTolAUtil& src);

public:
	vector<FmncQTolAUtil*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolAUtil: C++ wrapper for table TblFmncQTolAUtil
  */
class TblFmncQTolAUtil {

public:
	TblFmncQTolAUtil();
	virtual ~TblFmncQTolAUtil();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolAUtil** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAUtil& rst);

	virtual void insertRec(FmncQTolAUtil* rec);
	ubigint insertNewRec(FmncQTolAUtil** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefFmncMFabproject = 0, const string stubX1RefFmncMFabproject = "", const ubigint x2RefFmncMFabuser = 0, const string stubX2RefFmncMFabuser = "", const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "", const uint stopt = 0, const string ftmStopt = "", const double Unitprice = 0.0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQTolAUtil& rst, FmncQTolAUtil** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefFmncMFabproject = 0, const string stubX1RefFmncMFabproject = "", const ubigint x2RefFmncMFabuser = 0, const string stubX2RefFmncMFabuser = "", const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "", const uint stopt = 0, const string ftmStopt = "", const double Unitprice = 0.0, const string Comment = "");
	virtual void insertRst(ListFmncQTolAUtil& rst);
	virtual void updateRec(FmncQTolAUtil* rec);
	virtual void updateRst(ListFmncQTolAUtil& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolAUtil** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAUtil& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolAUtil: C++ wrapper for table TblFmncQTolAUtil (MySQL database)
  */
class MyTblFmncQTolAUtil : public TblFmncQTolAUtil, public MyTable {

public:
	MyTblFmncQTolAUtil();
	~MyTblFmncQTolAUtil();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolAUtil** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAUtil& rst);

	void insertRec(FmncQTolAUtil* rec);
	void insertRst(ListFmncQTolAUtil& rst);
	void updateRec(FmncQTolAUtil* rec);
	void updateRst(ListFmncQTolAUtil& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolAUtil** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAUtil& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolAUtil: C++ wrapper for table TblFmncQTolAUtil (PgSQL database)
  */
class PgTblFmncQTolAUtil : public TblFmncQTolAUtil, public PgTable {

public:
	PgTblFmncQTolAUtil();
	~PgTblFmncQTolAUtil();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolAUtil** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolAUtil& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolAUtil** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolAUtil& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolAUtil** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAUtil& rst);

	void insertRec(FmncQTolAUtil* rec);
	void insertRst(ListFmncQTolAUtil& rst);
	void updateRec(FmncQTolAUtil* rec);
	void updateRst(ListFmncQTolAUtil& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolAUtil** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAUtil& rst);
};
// IP pgTbl --- END

#endif

