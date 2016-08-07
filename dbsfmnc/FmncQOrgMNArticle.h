/**
  * \file FmncQOrgMNArticle.h
  * Dbs and XML wrapper for table TblFmncQOrgMNArticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGMNARTICLE_H
#define FMNCQORGMNARTICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgMNArticle: record of TblFmncQOrgMNArticle
  */
class FmncQOrgMNArticle {

public:
	FmncQOrgMNArticle(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string Itemno = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	string Itemno;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQOrgMNArticle: recordset of TblFmncQOrgMNArticle
  */
class ListFmncQOrgMNArticle {

public:
	ListFmncQOrgMNArticle();
	ListFmncQOrgMNArticle(const ListFmncQOrgMNArticle& src);
	~ListFmncQOrgMNArticle();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgMNArticle* rec);

	ListFmncQOrgMNArticle& operator=(const ListFmncQOrgMNArticle& src);

public:
	vector<FmncQOrgMNArticle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgMNArticle: C++ wrapper for table TblFmncQOrgMNArticle
  */
class TblFmncQOrgMNArticle {

public:
	TblFmncQOrgMNArticle();
	virtual ~TblFmncQOrgMNArticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgMNArticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMNArticle& rst);

	virtual void insertRec(FmncQOrgMNArticle* rec);
	ubigint insertNewRec(FmncQOrgMNArticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string Itemno = "");
	ubigint appendNewRecToRst(ListFmncQOrgMNArticle& rst, FmncQOrgMNArticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string Itemno = "");
	virtual void insertRst(ListFmncQOrgMNArticle& rst);
	virtual void updateRec(FmncQOrgMNArticle* rec);
	virtual void updateRst(ListFmncQOrgMNArticle& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgMNArticle** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMNArticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgMNArticle: C++ wrapper for table TblFmncQOrgMNArticle (MySQL database)
  */
class MyTblFmncQOrgMNArticle : public TblFmncQOrgMNArticle, public MyTable {

public:
	MyTblFmncQOrgMNArticle();
	~MyTblFmncQOrgMNArticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgMNArticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMNArticle& rst);

	void insertRec(FmncQOrgMNArticle* rec);
	void insertRst(ListFmncQOrgMNArticle& rst);
	void updateRec(FmncQOrgMNArticle* rec);
	void updateRst(ListFmncQOrgMNArticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgMNArticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMNArticle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgMNArticle: C++ wrapper for table TblFmncQOrgMNArticle (PgSQL database)
  */
class PgTblFmncQOrgMNArticle : public TblFmncQOrgMNArticle, public PgTable {

public:
	PgTblFmncQOrgMNArticle();
	~PgTblFmncQOrgMNArticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgMNArticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgMNArticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgMNArticle** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgMNArticle& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgMNArticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMNArticle& rst);

	void insertRec(FmncQOrgMNArticle* rec);
	void insertRst(ListFmncQOrgMNArticle& rst);
	void updateRec(FmncQOrgMNArticle* rec);
	void updateRst(ListFmncQOrgMNArticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgMNArticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMNArticle& rst);
};
// IP pgTbl --- END

#endif

