/**
  * \file FmncQAdrList.h
  * Dbs and XML wrapper for table TblFmncQAdrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQADRLIST_H
#define FMNCQADRLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQAdrList: record of TblFmncQAdrList
  */
class FmncQAdrList {

public:
	FmncQAdrList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Address1 = "", const string City = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const string srefKAdrtype = "", const string titSrefKAdrtype = "", const string Zipcode = "", const string srefKCountry = "", const string titSrefKCountry = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Address1;
	string City;
	uint hkIxVTbl;
	string srefHkIxVTbl;
	string titHkIxVTbl;
	ubigint hkUref;
	string stubHkUref;
	string srefKAdrtype;
	string titSrefKAdrtype;
	string Zipcode;
	string srefKCountry;
	string titSrefKCountry;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQAdrList: recordset of TblFmncQAdrList
  */
class ListFmncQAdrList {

public:
	ListFmncQAdrList();
	ListFmncQAdrList(const ListFmncQAdrList& src);
	~ListFmncQAdrList();

	void clear();
	unsigned int size() const;
	void append(FmncQAdrList* rec);

	ListFmncQAdrList& operator=(const ListFmncQAdrList& src);

public:
	vector<FmncQAdrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQAdrList: C++ wrapper for table TblFmncQAdrList
  */
class TblFmncQAdrList {

public:
	TblFmncQAdrList();
	virtual ~TblFmncQAdrList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQAdrList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQAdrList& rst);

	virtual void insertRec(FmncQAdrList* rec);
	ubigint insertNewRec(FmncQAdrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Address1 = "", const string City = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const string srefKAdrtype = "", const string titSrefKAdrtype = "", const string Zipcode = "", const string srefKCountry = "", const string titSrefKCountry = "");
	ubigint appendNewRecToRst(ListFmncQAdrList& rst, FmncQAdrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Address1 = "", const string City = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const string srefKAdrtype = "", const string titSrefKAdrtype = "", const string Zipcode = "", const string srefKCountry = "", const string titSrefKCountry = "");
	virtual void insertRst(ListFmncQAdrList& rst);
	virtual void updateRec(FmncQAdrList* rec);
	virtual void updateRst(ListFmncQAdrList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQAdrList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQAdrList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQAdrList: C++ wrapper for table TblFmncQAdrList (MySQL database)
  */
class MyTblFmncQAdrList : public TblFmncQAdrList, public MyTable {

public:
	MyTblFmncQAdrList();
	~MyTblFmncQAdrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQAdrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQAdrList& rst);

	void insertRec(FmncQAdrList* rec);
	void insertRst(ListFmncQAdrList& rst);
	void updateRec(FmncQAdrList* rec);
	void updateRst(ListFmncQAdrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQAdrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQAdrList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQAdrList: C++ wrapper for table TblFmncQAdrList (PgSQL database)
  */
class PgTblFmncQAdrList : public TblFmncQAdrList, public PgTable {

public:
	PgTblFmncQAdrList();
	~PgTblFmncQAdrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQAdrList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQAdrList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQAdrList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQAdrList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQAdrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQAdrList& rst);

	void insertRec(FmncQAdrList* rec);
	void insertRst(ListFmncQAdrList& rst);
	void updateRec(FmncQAdrList* rec);
	void updateRst(ListFmncQAdrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQAdrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQAdrList& rst);
};
// IP pgTbl --- END

#endif

