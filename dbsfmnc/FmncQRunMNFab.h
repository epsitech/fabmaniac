/**
  * \file FmncQRunMNFab.h
  * Dbs and XML wrapper for table TblFmncQRunMNFab (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNMNFAB_H
#define FMNCQRUNMNFAB_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunMNFab: record of TblFmncQRunMNFab
  */
class FmncQRunMNFab {

public:
	FmncQRunMNFab(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQRunMNFab: recordset of TblFmncQRunMNFab
  */
class ListFmncQRunMNFab {

public:
	ListFmncQRunMNFab();
	ListFmncQRunMNFab(const ListFmncQRunMNFab& src);
	~ListFmncQRunMNFab();

	void clear();
	unsigned int size() const;
	void append(FmncQRunMNFab* rec);

	ListFmncQRunMNFab& operator=(const ListFmncQRunMNFab& src);

public:
	vector<FmncQRunMNFab*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQRunMNFab: C++ wrapper for table TblFmncQRunMNFab
  */
class TblFmncQRunMNFab {

public:
	TblFmncQRunMNFab();
	virtual ~TblFmncQRunMNFab();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQRunMNFab** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNFab& rst);

	virtual void insertRec(FmncQRunMNFab* rec);
	ubigint insertNewRec(FmncQRunMNFab** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQRunMNFab& rst, FmncQRunMNFab** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQRunMNFab& rst);
	virtual void updateRec(FmncQRunMNFab* rec);
	virtual void updateRst(ListFmncQRunMNFab& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQRunMNFab** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNFab& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQRunMNFab: C++ wrapper for table TblFmncQRunMNFab (MySQL database)
  */
class MyTblFmncQRunMNFab : public TblFmncQRunMNFab, public MyTable {

public:
	MyTblFmncQRunMNFab();
	~MyTblFmncQRunMNFab();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunMNFab** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNFab& rst);

	void insertRec(FmncQRunMNFab* rec);
	void insertRst(ListFmncQRunMNFab& rst);
	void updateRec(FmncQRunMNFab* rec);
	void updateRst(ListFmncQRunMNFab& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunMNFab** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNFab& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQRunMNFab: C++ wrapper for table TblFmncQRunMNFab (PgSQL database)
  */
class PgTblFmncQRunMNFab : public TblFmncQRunMNFab, public PgTable {

public:
	PgTblFmncQRunMNFab();
	~PgTblFmncQRunMNFab();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQRunMNFab** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQRunMNFab& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQRunMNFab** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQRunMNFab& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunMNFab** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNFab& rst);

	void insertRec(FmncQRunMNFab* rec);
	void insertRst(ListFmncQRunMNFab& rst);
	void updateRec(FmncQRunMNFab* rec);
	void updateRst(ListFmncQRunMNFab& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunMNFab** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNFab& rst);
};
// IP pgTbl --- END

#endif

