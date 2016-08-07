/**
  * \file FmncQFusMNFabproject.h
  * Dbs and XML wrapper for table TblFmncQFusMNFabproject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFUSMNFABPROJECT_H
#define FMNCQFUSMNFABPROJECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFusMNFabproject: record of TblFmncQFusMNFabproject
  */
class FmncQFusMNFabproject {

public:
	FmncQFusMNFabproject(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQFusMNFabproject: recordset of TblFmncQFusMNFabproject
  */
class ListFmncQFusMNFabproject {

public:
	ListFmncQFusMNFabproject();
	ListFmncQFusMNFabproject(const ListFmncQFusMNFabproject& src);
	~ListFmncQFusMNFabproject();

	void clear();
	unsigned int size() const;
	void append(FmncQFusMNFabproject* rec);

	ListFmncQFusMNFabproject& operator=(const ListFmncQFusMNFabproject& src);

public:
	vector<FmncQFusMNFabproject*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFusMNFabproject: C++ wrapper for table TblFmncQFusMNFabproject
  */
class TblFmncQFusMNFabproject {

public:
	TblFmncQFusMNFabproject();
	virtual ~TblFmncQFusMNFabproject();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFusMNFabproject** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusMNFabproject& rst);

	virtual void insertRec(FmncQFusMNFabproject* rec);
	ubigint insertNewRec(FmncQFusMNFabproject** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQFusMNFabproject& rst, FmncQFusMNFabproject** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQFusMNFabproject& rst);
	virtual void updateRec(FmncQFusMNFabproject* rec);
	virtual void updateRst(ListFmncQFusMNFabproject& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFusMNFabproject** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusMNFabproject& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFusMNFabproject: C++ wrapper for table TblFmncQFusMNFabproject (MySQL database)
  */
class MyTblFmncQFusMNFabproject : public TblFmncQFusMNFabproject, public MyTable {

public:
	MyTblFmncQFusMNFabproject();
	~MyTblFmncQFusMNFabproject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFusMNFabproject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusMNFabproject& rst);

	void insertRec(FmncQFusMNFabproject* rec);
	void insertRst(ListFmncQFusMNFabproject& rst);
	void updateRec(FmncQFusMNFabproject* rec);
	void updateRst(ListFmncQFusMNFabproject& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFusMNFabproject** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusMNFabproject& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFusMNFabproject: C++ wrapper for table TblFmncQFusMNFabproject (PgSQL database)
  */
class PgTblFmncQFusMNFabproject : public TblFmncQFusMNFabproject, public PgTable {

public:
	PgTblFmncQFusMNFabproject();
	~PgTblFmncQFusMNFabproject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFusMNFabproject** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFusMNFabproject& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFusMNFabproject** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFusMNFabproject& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFusMNFabproject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFusMNFabproject& rst);

	void insertRec(FmncQFusMNFabproject* rec);
	void insertRst(ListFmncQFusMNFabproject& rst);
	void updateRec(FmncQFusMNFabproject* rec);
	void updateRst(ListFmncQFusMNFabproject& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFusMNFabproject** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFusMNFabproject& rst);
};
// IP pgTbl --- END

#endif

