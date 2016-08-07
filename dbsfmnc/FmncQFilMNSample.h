/**
  * \file FmncQFilMNSample.h
  * Dbs and XML wrapper for table TblFmncQFilMNSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFILMNSAMPLE_H
#define FMNCQFILMNSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFilMNSample: record of TblFmncQFilMNSample
  */
class FmncQFilMNSample {

public:
	FmncQFilMNSample(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQFilMNSample: recordset of TblFmncQFilMNSample
  */
class ListFmncQFilMNSample {

public:
	ListFmncQFilMNSample();
	ListFmncQFilMNSample(const ListFmncQFilMNSample& src);
	~ListFmncQFilMNSample();

	void clear();
	unsigned int size() const;
	void append(FmncQFilMNSample* rec);

	ListFmncQFilMNSample& operator=(const ListFmncQFilMNSample& src);

public:
	vector<FmncQFilMNSample*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFilMNSample: C++ wrapper for table TblFmncQFilMNSample
  */
class TblFmncQFilMNSample {

public:
	TblFmncQFilMNSample();
	virtual ~TblFmncQFilMNSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFilMNSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilMNSample& rst);

	virtual void insertRec(FmncQFilMNSample* rec);
	ubigint insertNewRec(FmncQFilMNSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQFilMNSample& rst, FmncQFilMNSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQFilMNSample& rst);
	virtual void updateRec(FmncQFilMNSample* rec);
	virtual void updateRst(ListFmncQFilMNSample& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFilMNSample** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilMNSample& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFilMNSample: C++ wrapper for table TblFmncQFilMNSample (MySQL database)
  */
class MyTblFmncQFilMNSample : public TblFmncQFilMNSample, public MyTable {

public:
	MyTblFmncQFilMNSample();
	~MyTblFmncQFilMNSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFilMNSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilMNSample& rst);

	void insertRec(FmncQFilMNSample* rec);
	void insertRst(ListFmncQFilMNSample& rst);
	void updateRec(FmncQFilMNSample* rec);
	void updateRst(ListFmncQFilMNSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFilMNSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilMNSample& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFilMNSample: C++ wrapper for table TblFmncQFilMNSample (PgSQL database)
  */
class PgTblFmncQFilMNSample : public TblFmncQFilMNSample, public PgTable {

public:
	PgTblFmncQFilMNSample();
	~PgTblFmncQFilMNSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFilMNSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFilMNSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFilMNSample** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFilMNSample& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFilMNSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFilMNSample& rst);

	void insertRec(FmncQFilMNSample* rec);
	void insertRst(ListFmncQFilMNSample& rst);
	void updateRec(FmncQFilMNSample* rec);
	void updateRst(ListFmncQFilMNSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFilMNSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFilMNSample& rst);
};
// IP pgTbl --- END

#endif

