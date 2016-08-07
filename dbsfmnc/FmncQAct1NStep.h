/**
  * \file FmncQAct1NStep.h
  * Dbs and XML wrapper for table TblFmncQAct1NStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQACT1NSTEP_H
#define FMNCQACT1NSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQAct1NStep: record of TblFmncQAct1NStep
  */
class FmncQAct1NStep {

public:
	FmncQAct1NStep(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQAct1NStep: recordset of TblFmncQAct1NStep
  */
class ListFmncQAct1NStep {

public:
	ListFmncQAct1NStep();
	ListFmncQAct1NStep(const ListFmncQAct1NStep& src);
	~ListFmncQAct1NStep();

	void clear();
	unsigned int size() const;
	void append(FmncQAct1NStep* rec);

	ListFmncQAct1NStep& operator=(const ListFmncQAct1NStep& src);

public:
	vector<FmncQAct1NStep*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQAct1NStep: C++ wrapper for table TblFmncQAct1NStep
  */
class TblFmncQAct1NStep {

public:
	TblFmncQAct1NStep();
	virtual ~TblFmncQAct1NStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQAct1NStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQAct1NStep& rst);

	virtual void insertRec(FmncQAct1NStep* rec);
	ubigint insertNewRec(FmncQAct1NStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQAct1NStep& rst, FmncQAct1NStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQAct1NStep& rst);
	virtual void updateRec(FmncQAct1NStep* rec);
	virtual void updateRst(ListFmncQAct1NStep& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQAct1NStep** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQAct1NStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQAct1NStep: C++ wrapper for table TblFmncQAct1NStep (MySQL database)
  */
class MyTblFmncQAct1NStep : public TblFmncQAct1NStep, public MyTable {

public:
	MyTblFmncQAct1NStep();
	~MyTblFmncQAct1NStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQAct1NStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQAct1NStep& rst);

	void insertRec(FmncQAct1NStep* rec);
	void insertRst(ListFmncQAct1NStep& rst);
	void updateRec(FmncQAct1NStep* rec);
	void updateRst(ListFmncQAct1NStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQAct1NStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQAct1NStep& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQAct1NStep: C++ wrapper for table TblFmncQAct1NStep (PgSQL database)
  */
class PgTblFmncQAct1NStep : public TblFmncQAct1NStep, public PgTable {

public:
	PgTblFmncQAct1NStep();
	~PgTblFmncQAct1NStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQAct1NStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQAct1NStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQAct1NStep** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQAct1NStep& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQAct1NStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQAct1NStep& rst);

	void insertRec(FmncQAct1NStep* rec);
	void insertRst(ListFmncQAct1NStep& rst);
	void updateRec(FmncQAct1NStep* rec);
	void updateRst(ListFmncQAct1NStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQAct1NStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQAct1NStep& rst);
};
// IP pgTbl --- END

#endif

