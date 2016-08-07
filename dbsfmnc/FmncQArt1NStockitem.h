/**
  * \file FmncQArt1NStockitem.h
  * Dbs and XML wrapper for table TblFmncQArt1NStockitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQART1NSTOCKITEM_H
#define FMNCQART1NSTOCKITEM_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArt1NStockitem: record of TblFmncQArt1NStockitem
  */
class FmncQArt1NStockitem {

public:
	FmncQArt1NStockitem(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQArt1NStockitem: recordset of TblFmncQArt1NStockitem
  */
class ListFmncQArt1NStockitem {

public:
	ListFmncQArt1NStockitem();
	ListFmncQArt1NStockitem(const ListFmncQArt1NStockitem& src);
	~ListFmncQArt1NStockitem();

	void clear();
	unsigned int size() const;
	void append(FmncQArt1NStockitem* rec);

	ListFmncQArt1NStockitem& operator=(const ListFmncQArt1NStockitem& src);

public:
	vector<FmncQArt1NStockitem*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQArt1NStockitem: C++ wrapper for table TblFmncQArt1NStockitem
  */
class TblFmncQArt1NStockitem {

public:
	TblFmncQArt1NStockitem();
	virtual ~TblFmncQArt1NStockitem();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQArt1NStockitem** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArt1NStockitem& rst);

	virtual void insertRec(FmncQArt1NStockitem* rec);
	ubigint insertNewRec(FmncQArt1NStockitem** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQArt1NStockitem& rst, FmncQArt1NStockitem** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQArt1NStockitem& rst);
	virtual void updateRec(FmncQArt1NStockitem* rec);
	virtual void updateRst(ListFmncQArt1NStockitem& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQArt1NStockitem** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArt1NStockitem& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQArt1NStockitem: C++ wrapper for table TblFmncQArt1NStockitem (MySQL database)
  */
class MyTblFmncQArt1NStockitem : public TblFmncQArt1NStockitem, public MyTable {

public:
	MyTblFmncQArt1NStockitem();
	~MyTblFmncQArt1NStockitem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArt1NStockitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArt1NStockitem& rst);

	void insertRec(FmncQArt1NStockitem* rec);
	void insertRst(ListFmncQArt1NStockitem& rst);
	void updateRec(FmncQArt1NStockitem* rec);
	void updateRst(ListFmncQArt1NStockitem& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArt1NStockitem** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArt1NStockitem& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQArt1NStockitem: C++ wrapper for table TblFmncQArt1NStockitem (PgSQL database)
  */
class PgTblFmncQArt1NStockitem : public TblFmncQArt1NStockitem, public PgTable {

public:
	PgTblFmncQArt1NStockitem();
	~PgTblFmncQArt1NStockitem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQArt1NStockitem** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQArt1NStockitem& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQArt1NStockitem** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQArt1NStockitem& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArt1NStockitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArt1NStockitem& rst);

	void insertRec(FmncQArt1NStockitem* rec);
	void insertRst(ListFmncQArt1NStockitem& rst);
	void updateRec(FmncQArt1NStockitem* rec);
	void updateRst(ListFmncQArt1NStockitem& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArt1NStockitem** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArt1NStockitem& rst);
};
// IP pgTbl --- END

#endif

