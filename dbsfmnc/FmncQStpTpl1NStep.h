/**
  * \file FmncQStpTpl1NStep.h
  * Dbs and XML wrapper for table TblFmncQStpTpl1NStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPTPL1NSTEP_H
#define FMNCQSTPTPL1NSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpTpl1NStep: record of TblFmncQStpTpl1NStep
  */
class FmncQStpTpl1NStep {

public:
	FmncQStpTpl1NStep(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQStpTpl1NStep: recordset of TblFmncQStpTpl1NStep
  */
class ListFmncQStpTpl1NStep {

public:
	ListFmncQStpTpl1NStep();
	ListFmncQStpTpl1NStep(const ListFmncQStpTpl1NStep& src);
	~ListFmncQStpTpl1NStep();

	void clear();
	unsigned int size() const;
	void append(FmncQStpTpl1NStep* rec);

	ListFmncQStpTpl1NStep& operator=(const ListFmncQStpTpl1NStep& src);

public:
	vector<FmncQStpTpl1NStep*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQStpTpl1NStep: C++ wrapper for table TblFmncQStpTpl1NStep
  */
class TblFmncQStpTpl1NStep {

public:
	TblFmncQStpTpl1NStep();
	virtual ~TblFmncQStpTpl1NStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQStpTpl1NStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpTpl1NStep& rst);

	virtual void insertRec(FmncQStpTpl1NStep* rec);
	ubigint insertNewRec(FmncQStpTpl1NStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQStpTpl1NStep& rst, FmncQStpTpl1NStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQStpTpl1NStep& rst);
	virtual void updateRec(FmncQStpTpl1NStep* rec);
	virtual void updateRst(ListFmncQStpTpl1NStep& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQStpTpl1NStep** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpTpl1NStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQStpTpl1NStep: C++ wrapper for table TblFmncQStpTpl1NStep (MySQL database)
  */
class MyTblFmncQStpTpl1NStep : public TblFmncQStpTpl1NStep, public MyTable {

public:
	MyTblFmncQStpTpl1NStep();
	~MyTblFmncQStpTpl1NStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpTpl1NStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpTpl1NStep& rst);

	void insertRec(FmncQStpTpl1NStep* rec);
	void insertRst(ListFmncQStpTpl1NStep& rst);
	void updateRec(FmncQStpTpl1NStep* rec);
	void updateRst(ListFmncQStpTpl1NStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpTpl1NStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpTpl1NStep& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQStpTpl1NStep: C++ wrapper for table TblFmncQStpTpl1NStep (PgSQL database)
  */
class PgTblFmncQStpTpl1NStep : public TblFmncQStpTpl1NStep, public PgTable {

public:
	PgTblFmncQStpTpl1NStep();
	~PgTblFmncQStpTpl1NStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQStpTpl1NStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQStpTpl1NStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQStpTpl1NStep** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQStpTpl1NStep& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpTpl1NStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpTpl1NStep& rst);

	void insertRec(FmncQStpTpl1NStep* rec);
	void insertRst(ListFmncQStpTpl1NStep& rst);
	void updateRec(FmncQStpTpl1NStep* rec);
	void updateRst(ListFmncQStpTpl1NStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpTpl1NStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpTpl1NStep& rst);
};
// IP pgTbl --- END

#endif

