/**
  * \file FmncQOrg1NStockitem.h
  * Dbs and XML wrapper for table TblFmncQOrg1NStockitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORG1NSTOCKITEM_H
#define FMNCQORG1NSTOCKITEM_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrg1NStockitem: record of TblFmncQOrg1NStockitem
  */
class FmncQOrg1NStockitem {

public:
	FmncQOrg1NStockitem(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQOrg1NStockitem: recordset of TblFmncQOrg1NStockitem
  */
class ListFmncQOrg1NStockitem {

public:
	ListFmncQOrg1NStockitem();
	ListFmncQOrg1NStockitem(const ListFmncQOrg1NStockitem& src);
	~ListFmncQOrg1NStockitem();

	void clear();
	unsigned int size() const;
	void append(FmncQOrg1NStockitem* rec);

	ListFmncQOrg1NStockitem& operator=(const ListFmncQOrg1NStockitem& src);

public:
	vector<FmncQOrg1NStockitem*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrg1NStockitem: C++ wrapper for table TblFmncQOrg1NStockitem
  */
class TblFmncQOrg1NStockitem {

public:
	TblFmncQOrg1NStockitem();
	virtual ~TblFmncQOrg1NStockitem();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrg1NStockitem** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrg1NStockitem& rst);

	virtual void insertRec(FmncQOrg1NStockitem* rec);
	ubigint insertNewRec(FmncQOrg1NStockitem** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQOrg1NStockitem& rst, FmncQOrg1NStockitem** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQOrg1NStockitem& rst);
	virtual void updateRec(FmncQOrg1NStockitem* rec);
	virtual void updateRst(ListFmncQOrg1NStockitem& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrg1NStockitem** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrg1NStockitem& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrg1NStockitem: C++ wrapper for table TblFmncQOrg1NStockitem (MySQL database)
  */
class MyTblFmncQOrg1NStockitem : public TblFmncQOrg1NStockitem, public MyTable {

public:
	MyTblFmncQOrg1NStockitem();
	~MyTblFmncQOrg1NStockitem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrg1NStockitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrg1NStockitem& rst);

	void insertRec(FmncQOrg1NStockitem* rec);
	void insertRst(ListFmncQOrg1NStockitem& rst);
	void updateRec(FmncQOrg1NStockitem* rec);
	void updateRst(ListFmncQOrg1NStockitem& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrg1NStockitem** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrg1NStockitem& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrg1NStockitem: C++ wrapper for table TblFmncQOrg1NStockitem (PgSQL database)
  */
class PgTblFmncQOrg1NStockitem : public TblFmncQOrg1NStockitem, public PgTable {

public:
	PgTblFmncQOrg1NStockitem();
	~PgTblFmncQOrg1NStockitem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrg1NStockitem** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrg1NStockitem& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrg1NStockitem** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrg1NStockitem& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrg1NStockitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrg1NStockitem& rst);

	void insertRec(FmncQOrg1NStockitem* rec);
	void insertRst(ListFmncQOrg1NStockitem& rst);
	void updateRec(FmncQOrg1NStockitem* rec);
	void updateRst(ListFmncQOrg1NStockitem& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrg1NStockitem** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrg1NStockitem& rst);
};
// IP pgTbl --- END

#endif

