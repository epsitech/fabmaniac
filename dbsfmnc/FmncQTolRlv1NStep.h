/**
  * \file FmncQTolRlv1NStep.h
  * Dbs and XML wrapper for table TblFmncQTolRlv1NStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLRLV1NSTEP_H
#define FMNCQTOLRLV1NSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolRlv1NStep: record of TblFmncQTolRlv1NStep
  */
class FmncQTolRlv1NStep {

public:
	FmncQTolRlv1NStep(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQTolRlv1NStep: recordset of TblFmncQTolRlv1NStep
  */
class ListFmncQTolRlv1NStep {

public:
	ListFmncQTolRlv1NStep();
	ListFmncQTolRlv1NStep(const ListFmncQTolRlv1NStep& src);
	~ListFmncQTolRlv1NStep();

	void clear();
	unsigned int size() const;
	void append(FmncQTolRlv1NStep* rec);

	ListFmncQTolRlv1NStep& operator=(const ListFmncQTolRlv1NStep& src);

public:
	vector<FmncQTolRlv1NStep*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolRlv1NStep: C++ wrapper for table TblFmncQTolRlv1NStep
  */
class TblFmncQTolRlv1NStep {

public:
	TblFmncQTolRlv1NStep();
	virtual ~TblFmncQTolRlv1NStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolRlv1NStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolRlv1NStep& rst);

	virtual void insertRec(FmncQTolRlv1NStep* rec);
	ubigint insertNewRec(FmncQTolRlv1NStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQTolRlv1NStep& rst, FmncQTolRlv1NStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQTolRlv1NStep& rst);
	virtual void updateRec(FmncQTolRlv1NStep* rec);
	virtual void updateRst(ListFmncQTolRlv1NStep& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolRlv1NStep** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolRlv1NStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolRlv1NStep: C++ wrapper for table TblFmncQTolRlv1NStep (MySQL database)
  */
class MyTblFmncQTolRlv1NStep : public TblFmncQTolRlv1NStep, public MyTable {

public:
	MyTblFmncQTolRlv1NStep();
	~MyTblFmncQTolRlv1NStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolRlv1NStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolRlv1NStep& rst);

	void insertRec(FmncQTolRlv1NStep* rec);
	void insertRst(ListFmncQTolRlv1NStep& rst);
	void updateRec(FmncQTolRlv1NStep* rec);
	void updateRst(ListFmncQTolRlv1NStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolRlv1NStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolRlv1NStep& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolRlv1NStep: C++ wrapper for table TblFmncQTolRlv1NStep (PgSQL database)
  */
class PgTblFmncQTolRlv1NStep : public TblFmncQTolRlv1NStep, public PgTable {

public:
	PgTblFmncQTolRlv1NStep();
	~PgTblFmncQTolRlv1NStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolRlv1NStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolRlv1NStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolRlv1NStep** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolRlv1NStep& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolRlv1NStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolRlv1NStep& rst);

	void insertRec(FmncQTolRlv1NStep* rec);
	void insertRst(ListFmncQTolRlv1NStep& rst);
	void updateRec(FmncQTolRlv1NStep* rec);
	void updateRst(ListFmncQTolRlv1NStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolRlv1NStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolRlv1NStep& rst);
};
// IP pgTbl --- END

#endif

