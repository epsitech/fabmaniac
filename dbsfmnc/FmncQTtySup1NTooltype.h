/**
  * \file FmncQTtySup1NTooltype.h
  * Dbs and XML wrapper for table TblFmncQTtySup1NTooltype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYSUP1NTOOLTYPE_H
#define FMNCQTTYSUP1NTOOLTYPE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtySup1NTooltype: record of TblFmncQTtySup1NTooltype
  */
class FmncQTtySup1NTooltype {

public:
	FmncQTtySup1NTooltype(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQTtySup1NTooltype: recordset of TblFmncQTtySup1NTooltype
  */
class ListFmncQTtySup1NTooltype {

public:
	ListFmncQTtySup1NTooltype();
	ListFmncQTtySup1NTooltype(const ListFmncQTtySup1NTooltype& src);
	~ListFmncQTtySup1NTooltype();

	void clear();
	unsigned int size() const;
	void append(FmncQTtySup1NTooltype* rec);

	ListFmncQTtySup1NTooltype& operator=(const ListFmncQTtySup1NTooltype& src);

public:
	vector<FmncQTtySup1NTooltype*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTtySup1NTooltype: C++ wrapper for table TblFmncQTtySup1NTooltype
  */
class TblFmncQTtySup1NTooltype {

public:
	TblFmncQTtySup1NTooltype();
	virtual ~TblFmncQTtySup1NTooltype();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTtySup1NTooltype** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtySup1NTooltype& rst);

	virtual void insertRec(FmncQTtySup1NTooltype* rec);
	ubigint insertNewRec(FmncQTtySup1NTooltype** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQTtySup1NTooltype& rst, FmncQTtySup1NTooltype** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQTtySup1NTooltype& rst);
	virtual void updateRec(FmncQTtySup1NTooltype* rec);
	virtual void updateRst(ListFmncQTtySup1NTooltype& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTtySup1NTooltype** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtySup1NTooltype& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTtySup1NTooltype: C++ wrapper for table TblFmncQTtySup1NTooltype (MySQL database)
  */
class MyTblFmncQTtySup1NTooltype : public TblFmncQTtySup1NTooltype, public MyTable {

public:
	MyTblFmncQTtySup1NTooltype();
	~MyTblFmncQTtySup1NTooltype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtySup1NTooltype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtySup1NTooltype& rst);

	void insertRec(FmncQTtySup1NTooltype* rec);
	void insertRst(ListFmncQTtySup1NTooltype& rst);
	void updateRec(FmncQTtySup1NTooltype* rec);
	void updateRst(ListFmncQTtySup1NTooltype& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtySup1NTooltype** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtySup1NTooltype& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTtySup1NTooltype: C++ wrapper for table TblFmncQTtySup1NTooltype (PgSQL database)
  */
class PgTblFmncQTtySup1NTooltype : public TblFmncQTtySup1NTooltype, public PgTable {

public:
	PgTblFmncQTtySup1NTooltype();
	~PgTblFmncQTtySup1NTooltype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTtySup1NTooltype** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTtySup1NTooltype& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTtySup1NTooltype** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTtySup1NTooltype& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtySup1NTooltype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtySup1NTooltype& rst);

	void insertRec(FmncQTtySup1NTooltype* rec);
	void insertRst(ListFmncQTtySup1NTooltype& rst);
	void updateRec(FmncQTtySup1NTooltype* rec);
	void updateRst(ListFmncQTtySup1NTooltype& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtySup1NTooltype** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtySup1NTooltype& rst);
};
// IP pgTbl --- END

#endif

