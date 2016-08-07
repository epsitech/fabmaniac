/**
  * \file FmncQOrg1NArticle.h
  * Dbs and XML wrapper for table TblFmncQOrg1NArticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORG1NARTICLE_H
#define FMNCQORG1NARTICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrg1NArticle: record of TblFmncQOrg1NArticle
  */
class FmncQOrg1NArticle {

public:
	FmncQOrg1NArticle(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQOrg1NArticle: recordset of TblFmncQOrg1NArticle
  */
class ListFmncQOrg1NArticle {

public:
	ListFmncQOrg1NArticle();
	ListFmncQOrg1NArticle(const ListFmncQOrg1NArticle& src);
	~ListFmncQOrg1NArticle();

	void clear();
	unsigned int size() const;
	void append(FmncQOrg1NArticle* rec);

	ListFmncQOrg1NArticle& operator=(const ListFmncQOrg1NArticle& src);

public:
	vector<FmncQOrg1NArticle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrg1NArticle: C++ wrapper for table TblFmncQOrg1NArticle
  */
class TblFmncQOrg1NArticle {

public:
	TblFmncQOrg1NArticle();
	virtual ~TblFmncQOrg1NArticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrg1NArticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrg1NArticle& rst);

	virtual void insertRec(FmncQOrg1NArticle* rec);
	ubigint insertNewRec(FmncQOrg1NArticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQOrg1NArticle& rst, FmncQOrg1NArticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQOrg1NArticle& rst);
	virtual void updateRec(FmncQOrg1NArticle* rec);
	virtual void updateRst(ListFmncQOrg1NArticle& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrg1NArticle** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrg1NArticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrg1NArticle: C++ wrapper for table TblFmncQOrg1NArticle (MySQL database)
  */
class MyTblFmncQOrg1NArticle : public TblFmncQOrg1NArticle, public MyTable {

public:
	MyTblFmncQOrg1NArticle();
	~MyTblFmncQOrg1NArticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrg1NArticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrg1NArticle& rst);

	void insertRec(FmncQOrg1NArticle* rec);
	void insertRst(ListFmncQOrg1NArticle& rst);
	void updateRec(FmncQOrg1NArticle* rec);
	void updateRst(ListFmncQOrg1NArticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrg1NArticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrg1NArticle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrg1NArticle: C++ wrapper for table TblFmncQOrg1NArticle (PgSQL database)
  */
class PgTblFmncQOrg1NArticle : public TblFmncQOrg1NArticle, public PgTable {

public:
	PgTblFmncQOrg1NArticle();
	~PgTblFmncQOrg1NArticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrg1NArticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrg1NArticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrg1NArticle** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrg1NArticle& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrg1NArticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrg1NArticle& rst);

	void insertRec(FmncQOrg1NArticle* rec);
	void insertRst(ListFmncQOrg1NArticle& rst);
	void updateRec(FmncQOrg1NArticle* rec);
	void updateRst(ListFmncQOrg1NArticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrg1NArticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrg1NArticle& rst);
};
// IP pgTbl --- END

#endif

