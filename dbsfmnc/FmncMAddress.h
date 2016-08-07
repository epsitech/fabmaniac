/**
  * \file FmncMAddress.h
  * database access for table TblFmncMAddress (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMADDRESS_H
#define FMNCMADDRESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMAddress: record of TblFmncMAddress
  */
class FmncMAddress {

public:
	FmncMAddress(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint x1Startd = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string srefKAdrtype = "", const string Address1 = "", const string Address2 = "", const string Zipcode = "", const string City = "", const string State = "", const string srefKCountry = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint x1Startd;
	uint hkIxVTbl;
	ubigint hkUref;
	string srefKAdrtype;
	string Address1;
	string Address2;
	string Zipcode;
	string City;
	string State;
	string srefKCountry;

public:
	bool operator==(const FmncMAddress& comp);
	bool operator!=(const FmncMAddress& comp);
};

/**
  * ListFmncMAddress: recordset of TblFmncMAddress
  */
class ListFmncMAddress {

public:
	ListFmncMAddress();
	ListFmncMAddress(const ListFmncMAddress& src);
	~ListFmncMAddress();

	void clear();
	unsigned int size() const;
	void append(FmncMAddress* rec);

	FmncMAddress* operator[](const uint ix);
	ListFmncMAddress& operator=(const ListFmncMAddress& src);
	bool operator==(const ListFmncMAddress& comp);
	bool operator!=(const ListFmncMAddress& comp);

public:
	vector<FmncMAddress*> nodes;
};

/**
  * TblFmncMAddress: C++ wrapper for table TblFmncMAddress
  */
class TblFmncMAddress {

public:
	TblFmncMAddress();
	virtual ~TblFmncMAddress();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMAddress** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMAddress& rst);

	virtual void insertRec(FmncMAddress* rec);
	ubigint insertNewRec(FmncMAddress** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint x1Startd = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string srefKAdrtype = "", const string Address1 = "", const string Address2 = "", const string Zipcode = "", const string City = "", const string State = "", const string srefKCountry = "");
	ubigint appendNewRecToRst(ListFmncMAddress& rst, FmncMAddress** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint x1Startd = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string srefKAdrtype = "", const string Address1 = "", const string Address2 = "", const string Zipcode = "", const string City = "", const string State = "", const string srefKCountry = "");
	virtual void insertRst(ListFmncMAddress& rst, bool transact = false);
	virtual void updateRec(FmncMAddress* rec);
	virtual void updateRst(ListFmncMAddress& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMAddress** rec);
	virtual ubigint loadRefsByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMAddress& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMAddress: C++ wrapper for table TblFmncMAddress (MySQL database)
  */
class MyTblFmncMAddress : public TblFmncMAddress, public MyTable {

public:
	MyTblFmncMAddress();
	~MyTblFmncMAddress();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMAddress** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMAddress& rst);

	void insertRec(FmncMAddress* rec);
	void insertRst(ListFmncMAddress& rst, bool transact = false);
	void updateRec(FmncMAddress* rec);
	void updateRst(ListFmncMAddress& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMAddress** rec);
	ubigint loadRefsByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMAddress: C++ wrapper for table TblFmncMAddress (PgSQL database)
  */
class PgTblFmncMAddress : public TblFmncMAddress, public PgTable {

public:
	PgTblFmncMAddress();
	~PgTblFmncMAddress();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMAddress** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMAddress& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMAddress** rec);

public:
	bool loadRecBySQL(const string& sqlstr, FmncMAddress** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMAddress& rst);

	void insertRec(FmncMAddress* rec);
	void insertRst(ListFmncMAddress& rst, bool transact = false);
	void updateRec(FmncMAddress* rec);
	void updateRst(ListFmncMAddress& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMAddress** rec);
	ubigint loadRefsByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

