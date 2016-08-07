/**
  * \file FmncQPrj1NRun.h
  * Dbs and XML wrapper for table TblFmncQPrj1NRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRJ1NRUN_H
#define FMNCQPRJ1NRUN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrj1NRun: record of TblFmncQPrj1NRun
  */
class FmncQPrj1NRun {

public:
	FmncQPrj1NRun(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPrj1NRun: recordset of TblFmncQPrj1NRun
  */
class ListFmncQPrj1NRun {

public:
	ListFmncQPrj1NRun();
	ListFmncQPrj1NRun(const ListFmncQPrj1NRun& src);
	~ListFmncQPrj1NRun();

	void clear();
	unsigned int size() const;
	void append(FmncQPrj1NRun* rec);

	ListFmncQPrj1NRun& operator=(const ListFmncQPrj1NRun& src);

public:
	vector<FmncQPrj1NRun*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPrj1NRun: C++ wrapper for table TblFmncQPrj1NRun
  */
class TblFmncQPrj1NRun {

public:
	TblFmncQPrj1NRun();
	virtual ~TblFmncQPrj1NRun();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPrj1NRun** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrj1NRun& rst);

	virtual void insertRec(FmncQPrj1NRun* rec);
	ubigint insertNewRec(FmncQPrj1NRun** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQPrj1NRun& rst, FmncQPrj1NRun** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQPrj1NRun& rst);
	virtual void updateRec(FmncQPrj1NRun* rec);
	virtual void updateRst(ListFmncQPrj1NRun& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPrj1NRun** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrj1NRun& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPrj1NRun: C++ wrapper for table TblFmncQPrj1NRun (MySQL database)
  */
class MyTblFmncQPrj1NRun : public TblFmncQPrj1NRun, public MyTable {

public:
	MyTblFmncQPrj1NRun();
	~MyTblFmncQPrj1NRun();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrj1NRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrj1NRun& rst);

	void insertRec(FmncQPrj1NRun* rec);
	void insertRst(ListFmncQPrj1NRun& rst);
	void updateRec(FmncQPrj1NRun* rec);
	void updateRst(ListFmncQPrj1NRun& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrj1NRun** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrj1NRun& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPrj1NRun: C++ wrapper for table TblFmncQPrj1NRun (PgSQL database)
  */
class PgTblFmncQPrj1NRun : public TblFmncQPrj1NRun, public PgTable {

public:
	PgTblFmncQPrj1NRun();
	~PgTblFmncQPrj1NRun();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPrj1NRun** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPrj1NRun& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPrj1NRun** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPrj1NRun& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrj1NRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrj1NRun& rst);

	void insertRec(FmncQPrj1NRun* rec);
	void insertRst(ListFmncQPrj1NRun& rst);
	void updateRec(FmncQPrj1NRun* rec);
	void updateRst(ListFmncQPrj1NRun& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrj1NRun** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrj1NRun& rst);
};
// IP pgTbl --- END

#endif

