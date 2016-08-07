/**
  * \file FmncQSepMNSample.h
  * Dbs and XML wrapper for table TblFmncQSepMNSample (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPMNSAMPLE_H
#define FMNCQSEPMNSAMPLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepMNSample: record of TblFmncQSepMNSample
  */
class FmncQSepMNSample {

public:
	FmncQSepMNSample(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQSepMNSample: recordset of TblFmncQSepMNSample
  */
class ListFmncQSepMNSample {

public:
	ListFmncQSepMNSample();
	ListFmncQSepMNSample(const ListFmncQSepMNSample& src);
	~ListFmncQSepMNSample();

	void clear();
	unsigned int size() const;
	void append(FmncQSepMNSample* rec);

	ListFmncQSepMNSample& operator=(const ListFmncQSepMNSample& src);

public:
	vector<FmncQSepMNSample*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSepMNSample: C++ wrapper for table TblFmncQSepMNSample
  */
class TblFmncQSepMNSample {

public:
	TblFmncQSepMNSample();
	virtual ~TblFmncQSepMNSample();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSepMNSample** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepMNSample& rst);

	virtual void insertRec(FmncQSepMNSample* rec);
	ubigint insertNewRec(FmncQSepMNSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQSepMNSample& rst, FmncQSepMNSample** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQSepMNSample& rst);
	virtual void updateRec(FmncQSepMNSample* rec);
	virtual void updateRst(ListFmncQSepMNSample& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSepMNSample** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepMNSample& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSepMNSample: C++ wrapper for table TblFmncQSepMNSample (MySQL database)
  */
class MyTblFmncQSepMNSample : public TblFmncQSepMNSample, public MyTable {

public:
	MyTblFmncQSepMNSample();
	~MyTblFmncQSepMNSample();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepMNSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepMNSample& rst);

	void insertRec(FmncQSepMNSample* rec);
	void insertRst(ListFmncQSepMNSample& rst);
	void updateRec(FmncQSepMNSample* rec);
	void updateRst(ListFmncQSepMNSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepMNSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepMNSample& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSepMNSample: C++ wrapper for table TblFmncQSepMNSample (PgSQL database)
  */
class PgTblFmncQSepMNSample : public TblFmncQSepMNSample, public PgTable {

public:
	PgTblFmncQSepMNSample();
	~PgTblFmncQSepMNSample();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSepMNSample** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSepMNSample& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSepMNSample** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSepMNSample& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepMNSample** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepMNSample& rst);

	void insertRec(FmncQSepMNSample* rec);
	void insertRst(ListFmncQSepMNSample& rst);
	void updateRec(FmncQSepMNSample* rec);
	void updateRst(ListFmncQSepMNSample& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepMNSample** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepMNSample& rst);
};
// IP pgTbl --- END

#endif

