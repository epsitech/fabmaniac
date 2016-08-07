/**
  * \file FmncQFabMNRun.h
  * Dbs and XML wrapper for table TblFmncQFabMNRun (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFABMNRUN_H
#define FMNCQFABMNRUN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFabMNRun: record of TblFmncQFabMNRun
  */
class FmncQFabMNRun {

public:
	FmncQFabMNRun(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQFabMNRun: recordset of TblFmncQFabMNRun
  */
class ListFmncQFabMNRun {

public:
	ListFmncQFabMNRun();
	ListFmncQFabMNRun(const ListFmncQFabMNRun& src);
	~ListFmncQFabMNRun();

	void clear();
	unsigned int size() const;
	void append(FmncQFabMNRun* rec);

	ListFmncQFabMNRun& operator=(const ListFmncQFabMNRun& src);

public:
	vector<FmncQFabMNRun*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFabMNRun: C++ wrapper for table TblFmncQFabMNRun
  */
class TblFmncQFabMNRun {

public:
	TblFmncQFabMNRun();
	virtual ~TblFmncQFabMNRun();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFabMNRun** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabMNRun& rst);

	virtual void insertRec(FmncQFabMNRun* rec);
	ubigint insertNewRec(FmncQFabMNRun** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQFabMNRun& rst, FmncQFabMNRun** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQFabMNRun& rst);
	virtual void updateRec(FmncQFabMNRun* rec);
	virtual void updateRst(ListFmncQFabMNRun& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFabMNRun** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabMNRun& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFabMNRun: C++ wrapper for table TblFmncQFabMNRun (MySQL database)
  */
class MyTblFmncQFabMNRun : public TblFmncQFabMNRun, public MyTable {

public:
	MyTblFmncQFabMNRun();
	~MyTblFmncQFabMNRun();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFabMNRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabMNRun& rst);

	void insertRec(FmncQFabMNRun* rec);
	void insertRst(ListFmncQFabMNRun& rst);
	void updateRec(FmncQFabMNRun* rec);
	void updateRst(ListFmncQFabMNRun& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFabMNRun** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabMNRun& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFabMNRun: C++ wrapper for table TblFmncQFabMNRun (PgSQL database)
  */
class PgTblFmncQFabMNRun : public TblFmncQFabMNRun, public PgTable {

public:
	PgTblFmncQFabMNRun();
	~PgTblFmncQFabMNRun();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFabMNRun** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFabMNRun& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFabMNRun** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFabMNRun& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFabMNRun** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFabMNRun& rst);

	void insertRec(FmncQFabMNRun* rec);
	void insertRst(ListFmncQFabMNRun& rst);
	void updateRec(FmncQFabMNRun* rec);
	void updateRst(ListFmncQFabMNRun& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFabMNRun** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFabMNRun& rst);
};
// IP pgTbl --- END

#endif

