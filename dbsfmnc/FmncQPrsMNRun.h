/**
  * \file FmncQPrsMNRun.h
  * Dbs and XML wrapper for table TblFmncQPrsMNRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRSMNRUN_H
#define FMNCQPRSMNRUN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPrsMNRun: record of TblFmncQPrsMNRun
  */
class FmncQPrsMNRun {

public:
	FmncQPrsMNRun(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPrsMNRun: recordset of TblFmncQPrsMNRun
  */
class ListFmncQPrsMNRun {

public:
	ListFmncQPrsMNRun();
	ListFmncQPrsMNRun(const ListFmncQPrsMNRun& src);
	~ListFmncQPrsMNRun();

	void clear();
	unsigned int size() const;
	void append(FmncQPrsMNRun* rec);

	ListFmncQPrsMNRun& operator=(const ListFmncQPrsMNRun& src);

public:
	vector<FmncQPrsMNRun*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPrsMNRun: C++ wrapper for table TblFmncQPrsMNRun
  */
class TblFmncQPrsMNRun {

public:
	TblFmncQPrsMNRun();
	virtual ~TblFmncQPrsMNRun();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPrsMNRun** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsMNRun& rst);

	virtual void insertRec(FmncQPrsMNRun* rec);
	ubigint insertNewRec(FmncQPrsMNRun** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQPrsMNRun& rst, FmncQPrsMNRun** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQPrsMNRun& rst);
	virtual void updateRec(FmncQPrsMNRun* rec);
	virtual void updateRst(ListFmncQPrsMNRun& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPrsMNRun** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsMNRun& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPrsMNRun: C++ wrapper for table TblFmncQPrsMNRun (MySQL database)
  */
class MyTblFmncQPrsMNRun : public TblFmncQPrsMNRun, public MyTable {

public:
	MyTblFmncQPrsMNRun();
	~MyTblFmncQPrsMNRun();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsMNRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsMNRun& rst);

	void insertRec(FmncQPrsMNRun* rec);
	void insertRst(ListFmncQPrsMNRun& rst);
	void updateRec(FmncQPrsMNRun* rec);
	void updateRst(ListFmncQPrsMNRun& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsMNRun** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsMNRun& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPrsMNRun: C++ wrapper for table TblFmncQPrsMNRun (PgSQL database)
  */
class PgTblFmncQPrsMNRun : public TblFmncQPrsMNRun, public PgTable {

public:
	PgTblFmncQPrsMNRun();
	~PgTblFmncQPrsMNRun();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPrsMNRun** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPrsMNRun& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPrsMNRun** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPrsMNRun& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPrsMNRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPrsMNRun& rst);

	void insertRec(FmncQPrsMNRun* rec);
	void insertRst(ListFmncQPrsMNRun& rst);
	void updateRec(FmncQPrsMNRun* rec);
	void updateRst(ListFmncQPrsMNRun& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPrsMNRun** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPrsMNRun& rst);
};
// IP pgTbl --- END

#endif

