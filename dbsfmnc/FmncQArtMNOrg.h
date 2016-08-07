/**
  * \file FmncQArtMNOrg.h
  * Dbs and XML wrapper for table TblFmncQArtMNOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQARTMNORG_H
#define FMNCQARTMNORG_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArtMNOrg: record of TblFmncQArtMNOrg
  */
class FmncQArtMNOrg {

public:
	FmncQArtMNOrg(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string Itemno = "");

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
  * ListFmncQArtMNOrg: recordset of TblFmncQArtMNOrg
  */
class ListFmncQArtMNOrg {

public:
	ListFmncQArtMNOrg();
	ListFmncQArtMNOrg(const ListFmncQArtMNOrg& src);
	~ListFmncQArtMNOrg();

	void clear();
	unsigned int size() const;
	void append(FmncQArtMNOrg* rec);

	ListFmncQArtMNOrg& operator=(const ListFmncQArtMNOrg& src);

public:
	vector<FmncQArtMNOrg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQArtMNOrg: C++ wrapper for table TblFmncQArtMNOrg
  */
class TblFmncQArtMNOrg {

public:
	TblFmncQArtMNOrg();
	virtual ~TblFmncQArtMNOrg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQArtMNOrg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtMNOrg& rst);

	virtual void insertRec(FmncQArtMNOrg* rec);
	ubigint insertNewRec(FmncQArtMNOrg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string Itemno = "");
	ubigint appendNewRecToRst(ListFmncQArtMNOrg& rst, FmncQArtMNOrg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string Itemno = "");
	virtual void insertRst(ListFmncQArtMNOrg& rst);
	virtual void updateRec(FmncQArtMNOrg* rec);
	virtual void updateRst(ListFmncQArtMNOrg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQArtMNOrg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtMNOrg& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQArtMNOrg: C++ wrapper for table TblFmncQArtMNOrg (MySQL database)
  */
class MyTblFmncQArtMNOrg : public TblFmncQArtMNOrg, public MyTable {

public:
	MyTblFmncQArtMNOrg();
	~MyTblFmncQArtMNOrg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArtMNOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtMNOrg& rst);

	void insertRec(FmncQArtMNOrg* rec);
	void insertRst(ListFmncQArtMNOrg& rst);
	void updateRec(FmncQArtMNOrg* rec);
	void updateRst(ListFmncQArtMNOrg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArtMNOrg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtMNOrg& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQArtMNOrg: C++ wrapper for table TblFmncQArtMNOrg (PgSQL database)
  */
class PgTblFmncQArtMNOrg : public TblFmncQArtMNOrg, public PgTable {

public:
	PgTblFmncQArtMNOrg();
	~PgTblFmncQArtMNOrg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQArtMNOrg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQArtMNOrg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQArtMNOrg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQArtMNOrg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArtMNOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtMNOrg& rst);

	void insertRec(FmncQArtMNOrg* rec);
	void insertRst(ListFmncQArtMNOrg& rst);
	void updateRec(FmncQArtMNOrg* rec);
	void updateRst(ListFmncQArtMNOrg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArtMNOrg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtMNOrg& rst);
};
// IP pgTbl --- END

#endif

