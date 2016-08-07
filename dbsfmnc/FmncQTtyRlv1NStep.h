/**
  * \file FmncQTtyRlv1NStep.h
  * Dbs and XML wrapper for table TblFmncQTtyRlv1NStep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYRLV1NSTEP_H
#define FMNCQTTYRLV1NSTEP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyRlv1NStep: record of TblFmncQTtyRlv1NStep
  */
class FmncQTtyRlv1NStep {

public:
	FmncQTtyRlv1NStep(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQTtyRlv1NStep: recordset of TblFmncQTtyRlv1NStep
  */
class ListFmncQTtyRlv1NStep {

public:
	ListFmncQTtyRlv1NStep();
	ListFmncQTtyRlv1NStep(const ListFmncQTtyRlv1NStep& src);
	~ListFmncQTtyRlv1NStep();

	void clear();
	unsigned int size() const;
	void append(FmncQTtyRlv1NStep* rec);

	ListFmncQTtyRlv1NStep& operator=(const ListFmncQTtyRlv1NStep& src);

public:
	vector<FmncQTtyRlv1NStep*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTtyRlv1NStep: C++ wrapper for table TblFmncQTtyRlv1NStep
  */
class TblFmncQTtyRlv1NStep {

public:
	TblFmncQTtyRlv1NStep();
	virtual ~TblFmncQTtyRlv1NStep();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTtyRlv1NStep** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyRlv1NStep& rst);

	virtual void insertRec(FmncQTtyRlv1NStep* rec);
	ubigint insertNewRec(FmncQTtyRlv1NStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQTtyRlv1NStep& rst, FmncQTtyRlv1NStep** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQTtyRlv1NStep& rst);
	virtual void updateRec(FmncQTtyRlv1NStep* rec);
	virtual void updateRst(ListFmncQTtyRlv1NStep& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTtyRlv1NStep** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyRlv1NStep& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTtyRlv1NStep: C++ wrapper for table TblFmncQTtyRlv1NStep (MySQL database)
  */
class MyTblFmncQTtyRlv1NStep : public TblFmncQTtyRlv1NStep, public MyTable {

public:
	MyTblFmncQTtyRlv1NStep();
	~MyTblFmncQTtyRlv1NStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyRlv1NStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyRlv1NStep& rst);

	void insertRec(FmncQTtyRlv1NStep* rec);
	void insertRst(ListFmncQTtyRlv1NStep& rst);
	void updateRec(FmncQTtyRlv1NStep* rec);
	void updateRst(ListFmncQTtyRlv1NStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyRlv1NStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyRlv1NStep& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTtyRlv1NStep: C++ wrapper for table TblFmncQTtyRlv1NStep (PgSQL database)
  */
class PgTblFmncQTtyRlv1NStep : public TblFmncQTtyRlv1NStep, public PgTable {

public:
	PgTblFmncQTtyRlv1NStep();
	~PgTblFmncQTtyRlv1NStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTtyRlv1NStep** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTtyRlv1NStep& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTtyRlv1NStep** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTtyRlv1NStep& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyRlv1NStep** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyRlv1NStep& rst);

	void insertRec(FmncQTtyRlv1NStep* rec);
	void insertRst(ListFmncQTtyRlv1NStep& rst);
	void updateRec(FmncQTtyRlv1NStep* rec);
	void updateRst(ListFmncQTtyRlv1NStep& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyRlv1NStep** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyRlv1NStep& rst);
};
// IP pgTbl --- END

#endif

