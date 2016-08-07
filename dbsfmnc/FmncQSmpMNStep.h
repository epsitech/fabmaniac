/**
  * \file FmncQSmpMNStep.h
  * Dbs and XML wrapper for table TblFmncQSmpMNStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPMNSTEP_H
#define FMNCQSMPMNSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpMNStep: record of TblFmncQSmpMNStep
  */
class FmncQSmpMNStep {

public:
	FmncQSmpMNStep(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQSmpMNStep: recordset of TblFmncQSmpMNStep
  */
class ListFmncQSmpMNStep {

public:
	ListFmncQSmpMNStep();
	ListFmncQSmpMNStep(const ListFmncQSmpMNStep& src);
	~ListFmncQSmpMNStep();

	void clear();
	unsigned int size() const;
	void append(FmncQSmpMNStep* rec);

	ListFmncQSmpMNStep& operator=(const ListFmncQSmpMNStep& src);

public:
	vector<FmncQSmpMNStep*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSmpMNStep: C++ wrapper for table TblFmncQSmpMNStep
  */
class TblFmncQSmpMNStep {

public:
	TblFmncQSmpMNStep();
	virtual ~TblFmncQSmpMNStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSmpMNStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNStep& rst);

	virtual void insertRec(FmncQSmpMNStep* rec);
	ubigint insertNewRec(FmncQSmpMNStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQSmpMNStep& rst, FmncQSmpMNStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQSmpMNStep& rst);
	virtual void updateRec(FmncQSmpMNStep* rec);
	virtual void updateRst(ListFmncQSmpMNStep& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSmpMNStep** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSmpMNStep: C++ wrapper for table TblFmncQSmpMNStep (MySQL database)
  */
class MyTblFmncQSmpMNStep : public TblFmncQSmpMNStep, public MyTable {

public:
	MyTblFmncQSmpMNStep();
	~MyTblFmncQSmpMNStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpMNStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNStep& rst);

	void insertRec(FmncQSmpMNStep* rec);
	void insertRst(ListFmncQSmpMNStep& rst);
	void updateRec(FmncQSmpMNStep* rec);
	void updateRst(ListFmncQSmpMNStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpMNStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNStep& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSmpMNStep: C++ wrapper for table TblFmncQSmpMNStep (PgSQL database)
  */
class PgTblFmncQSmpMNStep : public TblFmncQSmpMNStep, public PgTable {

public:
	PgTblFmncQSmpMNStep();
	~PgTblFmncQSmpMNStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSmpMNStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSmpMNStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSmpMNStep** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSmpMNStep& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpMNStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNStep& rst);

	void insertRec(FmncQSmpMNStep* rec);
	void insertRst(ListFmncQSmpMNStep& rst);
	void updateRec(FmncQSmpMNStep* rec);
	void updateRst(ListFmncQSmpMNStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpMNStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNStep& rst);
};
// IP pgTbl --- END

#endif

