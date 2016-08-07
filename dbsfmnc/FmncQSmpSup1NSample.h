/**
  * \file FmncQSmpSup1NSample.h
  * Dbs and XML wrapper for table TblFmncQSmpSup1NSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPSUP1NSAMPLE_H
#define FMNCQSMPSUP1NSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpSup1NSample: record of TblFmncQSmpSup1NSample
  */
class FmncQSmpSup1NSample {

public:
	FmncQSmpSup1NSample(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQSmpSup1NSample: recordset of TblFmncQSmpSup1NSample
  */
class ListFmncQSmpSup1NSample {

public:
	ListFmncQSmpSup1NSample();
	ListFmncQSmpSup1NSample(const ListFmncQSmpSup1NSample& src);
	~ListFmncQSmpSup1NSample();

	void clear();
	unsigned int size() const;
	void append(FmncQSmpSup1NSample* rec);

	ListFmncQSmpSup1NSample& operator=(const ListFmncQSmpSup1NSample& src);

public:
	vector<FmncQSmpSup1NSample*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSmpSup1NSample: C++ wrapper for table TblFmncQSmpSup1NSample
  */
class TblFmncQSmpSup1NSample {

public:
	TblFmncQSmpSup1NSample();
	virtual ~TblFmncQSmpSup1NSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSmpSup1NSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpSup1NSample& rst);

	virtual void insertRec(FmncQSmpSup1NSample* rec);
	ubigint insertNewRec(FmncQSmpSup1NSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQSmpSup1NSample& rst, FmncQSmpSup1NSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQSmpSup1NSample& rst);
	virtual void updateRec(FmncQSmpSup1NSample* rec);
	virtual void updateRst(ListFmncQSmpSup1NSample& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSmpSup1NSample** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpSup1NSample& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSmpSup1NSample: C++ wrapper for table TblFmncQSmpSup1NSample (MySQL database)
  */
class MyTblFmncQSmpSup1NSample : public TblFmncQSmpSup1NSample, public MyTable {

public:
	MyTblFmncQSmpSup1NSample();
	~MyTblFmncQSmpSup1NSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpSup1NSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpSup1NSample& rst);

	void insertRec(FmncQSmpSup1NSample* rec);
	void insertRst(ListFmncQSmpSup1NSample& rst);
	void updateRec(FmncQSmpSup1NSample* rec);
	void updateRst(ListFmncQSmpSup1NSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpSup1NSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpSup1NSample& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSmpSup1NSample: C++ wrapper for table TblFmncQSmpSup1NSample (PgSQL database)
  */
class PgTblFmncQSmpSup1NSample : public TblFmncQSmpSup1NSample, public PgTable {

public:
	PgTblFmncQSmpSup1NSample();
	~PgTblFmncQSmpSup1NSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSmpSup1NSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSmpSup1NSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSmpSup1NSample** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSmpSup1NSample& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpSup1NSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpSup1NSample& rst);

	void insertRec(FmncQSmpSup1NSample* rec);
	void insertRst(ListFmncQSmpSup1NSample& rst);
	void updateRec(FmncQSmpSup1NSample* rec);
	void updateRst(ListFmncQSmpSup1NSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpSup1NSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpSup1NSample& rst);
};
// IP pgTbl --- END

#endif

