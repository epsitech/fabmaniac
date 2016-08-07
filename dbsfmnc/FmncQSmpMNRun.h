/**
  * \file FmncQSmpMNRun.h
  * Dbs and XML wrapper for table TblFmncQSmpMNRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPMNRUN_H
#define FMNCQSMPMNRUN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpMNRun: record of TblFmncQSmpMNRun
  */
class FmncQSmpMNRun {

public:
	FmncQSmpMNRun(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQSmpMNRun: recordset of TblFmncQSmpMNRun
  */
class ListFmncQSmpMNRun {

public:
	ListFmncQSmpMNRun();
	ListFmncQSmpMNRun(const ListFmncQSmpMNRun& src);
	~ListFmncQSmpMNRun();

	void clear();
	unsigned int size() const;
	void append(FmncQSmpMNRun* rec);

	ListFmncQSmpMNRun& operator=(const ListFmncQSmpMNRun& src);

public:
	vector<FmncQSmpMNRun*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSmpMNRun: C++ wrapper for table TblFmncQSmpMNRun
  */
class TblFmncQSmpMNRun {

public:
	TblFmncQSmpMNRun();
	virtual ~TblFmncQSmpMNRun();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSmpMNRun** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNRun& rst);

	virtual void insertRec(FmncQSmpMNRun* rec);
	ubigint insertNewRec(FmncQSmpMNRun** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQSmpMNRun& rst, FmncQSmpMNRun** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQSmpMNRun& rst);
	virtual void updateRec(FmncQSmpMNRun* rec);
	virtual void updateRst(ListFmncQSmpMNRun& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSmpMNRun** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNRun& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSmpMNRun: C++ wrapper for table TblFmncQSmpMNRun (MySQL database)
  */
class MyTblFmncQSmpMNRun : public TblFmncQSmpMNRun, public MyTable {

public:
	MyTblFmncQSmpMNRun();
	~MyTblFmncQSmpMNRun();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpMNRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNRun& rst);

	void insertRec(FmncQSmpMNRun* rec);
	void insertRst(ListFmncQSmpMNRun& rst);
	void updateRec(FmncQSmpMNRun* rec);
	void updateRst(ListFmncQSmpMNRun& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpMNRun** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNRun& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSmpMNRun: C++ wrapper for table TblFmncQSmpMNRun (PgSQL database)
  */
class PgTblFmncQSmpMNRun : public TblFmncQSmpMNRun, public PgTable {

public:
	PgTblFmncQSmpMNRun();
	~PgTblFmncQSmpMNRun();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSmpMNRun** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSmpMNRun& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSmpMNRun** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSmpMNRun& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpMNRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNRun& rst);

	void insertRec(FmncQSmpMNRun* rec);
	void insertRst(ListFmncQSmpMNRun& rst);
	void updateRec(FmncQSmpMNRun* rec);
	void updateRst(ListFmncQSmpMNRun& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpMNRun** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNRun& rst);
};
// IP pgTbl --- END

#endif

