/**
  * \file FmncQFilMNStep.h
  * Dbs and XML wrapper for table TblFmncQFilMNStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFILMNSTEP_H
#define FMNCQFILMNSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFilMNStep: record of TblFmncQFilMNStep
  */
class FmncQFilMNStep {

public:
	FmncQFilMNStep(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	string stubsTrefFmncMSample;
	ubigint ref;
	uint ixVDir;
	string srefIxVDir;
	string titIxVDir;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQFilMNStep: recordset of TblFmncQFilMNStep
  */
class ListFmncQFilMNStep {

public:
	ListFmncQFilMNStep();
	ListFmncQFilMNStep(const ListFmncQFilMNStep& src);
	~ListFmncQFilMNStep();

	void clear();
	unsigned int size() const;
	void append(FmncQFilMNStep* rec);

	ListFmncQFilMNStep& operator=(const ListFmncQFilMNStep& src);

public:
	vector<FmncQFilMNStep*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFilMNStep: C++ wrapper for table TblFmncQFilMNStep
  */
class TblFmncQFilMNStep {

public:
	TblFmncQFilMNStep();
	virtual ~TblFmncQFilMNStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFilMNStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilMNStep& rst);

	virtual void insertRec(FmncQFilMNStep* rec);
	ubigint insertNewRec(FmncQFilMNStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");
	ubigint appendNewRecToRst(ListFmncQFilMNStep& rst, FmncQFilMNStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");
	virtual void insertRst(ListFmncQFilMNStep& rst);
	virtual void updateRec(FmncQFilMNStep* rec);
	virtual void updateRst(ListFmncQFilMNStep& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFilMNStep** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilMNStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFilMNStep: C++ wrapper for table TblFmncQFilMNStep (MySQL database)
  */
class MyTblFmncQFilMNStep : public TblFmncQFilMNStep, public MyTable {

public:
	MyTblFmncQFilMNStep();
	~MyTblFmncQFilMNStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFilMNStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilMNStep& rst);

	void insertRec(FmncQFilMNStep* rec);
	void insertRst(ListFmncQFilMNStep& rst);
	void updateRec(FmncQFilMNStep* rec);
	void updateRst(ListFmncQFilMNStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFilMNStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilMNStep& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFilMNStep: C++ wrapper for table TblFmncQFilMNStep (PgSQL database)
  */
class PgTblFmncQFilMNStep : public TblFmncQFilMNStep, public PgTable {

public:
	PgTblFmncQFilMNStep();
	~PgTblFmncQFilMNStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFilMNStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFilMNStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFilMNStep** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFilMNStep& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFilMNStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilMNStep& rst);

	void insertRec(FmncQFilMNStep* rec);
	void insertRst(ListFmncQFilMNStep& rst);
	void updateRec(FmncQFilMNStep* rec);
	void updateRst(ListFmncQFilMNStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFilMNStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilMNStep& rst);
};
// IP pgTbl --- END

#endif

