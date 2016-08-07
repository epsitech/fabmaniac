/**
  * \file FmncQArt1NSample.h
  * Dbs and XML wrapper for table TblFmncQArt1NSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQART1NSAMPLE_H
#define FMNCQART1NSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArt1NSample: record of TblFmncQArt1NSample
  */
class FmncQArt1NSample {

public:
	FmncQArt1NSample(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQArt1NSample: recordset of TblFmncQArt1NSample
  */
class ListFmncQArt1NSample {

public:
	ListFmncQArt1NSample();
	ListFmncQArt1NSample(const ListFmncQArt1NSample& src);
	~ListFmncQArt1NSample();

	void clear();
	unsigned int size() const;
	void append(FmncQArt1NSample* rec);

	ListFmncQArt1NSample& operator=(const ListFmncQArt1NSample& src);

public:
	vector<FmncQArt1NSample*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQArt1NSample: C++ wrapper for table TblFmncQArt1NSample
  */
class TblFmncQArt1NSample {

public:
	TblFmncQArt1NSample();
	virtual ~TblFmncQArt1NSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQArt1NSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArt1NSample& rst);

	virtual void insertRec(FmncQArt1NSample* rec);
	ubigint insertNewRec(FmncQArt1NSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQArt1NSample& rst, FmncQArt1NSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQArt1NSample& rst);
	virtual void updateRec(FmncQArt1NSample* rec);
	virtual void updateRst(ListFmncQArt1NSample& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQArt1NSample** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArt1NSample& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQArt1NSample: C++ wrapper for table TblFmncQArt1NSample (MySQL database)
  */
class MyTblFmncQArt1NSample : public TblFmncQArt1NSample, public MyTable {

public:
	MyTblFmncQArt1NSample();
	~MyTblFmncQArt1NSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArt1NSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArt1NSample& rst);

	void insertRec(FmncQArt1NSample* rec);
	void insertRst(ListFmncQArt1NSample& rst);
	void updateRec(FmncQArt1NSample* rec);
	void updateRst(ListFmncQArt1NSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArt1NSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArt1NSample& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQArt1NSample: C++ wrapper for table TblFmncQArt1NSample (PgSQL database)
  */
class PgTblFmncQArt1NSample : public TblFmncQArt1NSample, public PgTable {

public:
	PgTblFmncQArt1NSample();
	~PgTblFmncQArt1NSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQArt1NSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQArt1NSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQArt1NSample** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQArt1NSample& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArt1NSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArt1NSample& rst);

	void insertRec(FmncQArt1NSample* rec);
	void insertRst(ListFmncQArt1NSample& rst);
	void updateRec(FmncQArt1NSample* rec);
	void updateRst(ListFmncQArt1NSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArt1NSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArt1NSample& rst);
};
// IP pgTbl --- END

#endif

