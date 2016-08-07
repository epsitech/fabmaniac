/**
  * \file FmncQTol1NArticle.h
  * Dbs and XML wrapper for table TblFmncQTol1NArticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOL1NARTICLE_H
#define FMNCQTOL1NARTICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTol1NArticle: record of TblFmncQTol1NArticle
  */
class FmncQTol1NArticle {

public:
	FmncQTol1NArticle(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQTol1NArticle: recordset of TblFmncQTol1NArticle
  */
class ListFmncQTol1NArticle {

public:
	ListFmncQTol1NArticle();
	ListFmncQTol1NArticle(const ListFmncQTol1NArticle& src);
	~ListFmncQTol1NArticle();

	void clear();
	unsigned int size() const;
	void append(FmncQTol1NArticle* rec);

	ListFmncQTol1NArticle& operator=(const ListFmncQTol1NArticle& src);

public:
	vector<FmncQTol1NArticle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTol1NArticle: C++ wrapper for table TblFmncQTol1NArticle
  */
class TblFmncQTol1NArticle {

public:
	TblFmncQTol1NArticle();
	virtual ~TblFmncQTol1NArticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTol1NArticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTol1NArticle& rst);

	virtual void insertRec(FmncQTol1NArticle* rec);
	ubigint insertNewRec(FmncQTol1NArticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQTol1NArticle& rst, FmncQTol1NArticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQTol1NArticle& rst);
	virtual void updateRec(FmncQTol1NArticle* rec);
	virtual void updateRst(ListFmncQTol1NArticle& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTol1NArticle** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTol1NArticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTol1NArticle: C++ wrapper for table TblFmncQTol1NArticle (MySQL database)
  */
class MyTblFmncQTol1NArticle : public TblFmncQTol1NArticle, public MyTable {

public:
	MyTblFmncQTol1NArticle();
	~MyTblFmncQTol1NArticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTol1NArticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTol1NArticle& rst);

	void insertRec(FmncQTol1NArticle* rec);
	void insertRst(ListFmncQTol1NArticle& rst);
	void updateRec(FmncQTol1NArticle* rec);
	void updateRst(ListFmncQTol1NArticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTol1NArticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTol1NArticle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTol1NArticle: C++ wrapper for table TblFmncQTol1NArticle (PgSQL database)
  */
class PgTblFmncQTol1NArticle : public TblFmncQTol1NArticle, public PgTable {

public:
	PgTblFmncQTol1NArticle();
	~PgTblFmncQTol1NArticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTol1NArticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTol1NArticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTol1NArticle** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTol1NArticle& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTol1NArticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTol1NArticle& rst);

	void insertRec(FmncQTol1NArticle* rec);
	void insertRst(ListFmncQTol1NArticle& rst);
	void updateRec(FmncQTol1NArticle* rec);
	void updateRst(ListFmncQTol1NArticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTol1NArticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTol1NArticle& rst);
};
// IP pgTbl --- END

#endif

