/**
  * \file FmncQRunMNSample.h
  * Dbs and XML wrapper for table TblFmncQRunMNSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNMNSAMPLE_H
#define FMNCQRUNMNSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunMNSample: record of TblFmncQRunMNSample
  */
class FmncQRunMNSample {

public:
	FmncQRunMNSample(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQRunMNSample: recordset of TblFmncQRunMNSample
  */
class ListFmncQRunMNSample {

public:
	ListFmncQRunMNSample();
	ListFmncQRunMNSample(const ListFmncQRunMNSample& src);
	~ListFmncQRunMNSample();

	void clear();
	unsigned int size() const;
	void append(FmncQRunMNSample* rec);

	ListFmncQRunMNSample& operator=(const ListFmncQRunMNSample& src);

public:
	vector<FmncQRunMNSample*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQRunMNSample: C++ wrapper for table TblFmncQRunMNSample
  */
class TblFmncQRunMNSample {

public:
	TblFmncQRunMNSample();
	virtual ~TblFmncQRunMNSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQRunMNSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNSample& rst);

	virtual void insertRec(FmncQRunMNSample* rec);
	ubigint insertNewRec(FmncQRunMNSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQRunMNSample& rst, FmncQRunMNSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQRunMNSample& rst);
	virtual void updateRec(FmncQRunMNSample* rec);
	virtual void updateRst(ListFmncQRunMNSample& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQRunMNSample** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNSample& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQRunMNSample: C++ wrapper for table TblFmncQRunMNSample (MySQL database)
  */
class MyTblFmncQRunMNSample : public TblFmncQRunMNSample, public MyTable {

public:
	MyTblFmncQRunMNSample();
	~MyTblFmncQRunMNSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunMNSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNSample& rst);

	void insertRec(FmncQRunMNSample* rec);
	void insertRst(ListFmncQRunMNSample& rst);
	void updateRec(FmncQRunMNSample* rec);
	void updateRst(ListFmncQRunMNSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunMNSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNSample& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQRunMNSample: C++ wrapper for table TblFmncQRunMNSample (PgSQL database)
  */
class PgTblFmncQRunMNSample : public TblFmncQRunMNSample, public PgTable {

public:
	PgTblFmncQRunMNSample();
	~PgTblFmncQRunMNSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQRunMNSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQRunMNSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQRunMNSample** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQRunMNSample& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunMNSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNSample& rst);

	void insertRec(FmncQRunMNSample* rec);
	void insertRst(ListFmncQRunMNSample& rst);
	void updateRec(FmncQRunMNSample* rec);
	void updateRst(ListFmncQRunMNSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunMNSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNSample& rst);
};
// IP pgTbl --- END

#endif

