/**
  * \file FmncQFpj1NBill.h
  * Dbs and XML wrapper for table TblFmncQFpj1NBill (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFPJ1NBILL_H
#define FMNCQFPJ1NBILL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFpj1NBill: record of TblFmncQFpj1NBill
  */
class FmncQFpj1NBill {

public:
	FmncQFpj1NBill(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQFpj1NBill: recordset of TblFmncQFpj1NBill
  */
class ListFmncQFpj1NBill {

public:
	ListFmncQFpj1NBill();
	ListFmncQFpj1NBill(const ListFmncQFpj1NBill& src);
	~ListFmncQFpj1NBill();

	void clear();
	unsigned int size() const;
	void append(FmncQFpj1NBill* rec);

	ListFmncQFpj1NBill& operator=(const ListFmncQFpj1NBill& src);

public:
	vector<FmncQFpj1NBill*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFpj1NBill: C++ wrapper for table TblFmncQFpj1NBill
  */
class TblFmncQFpj1NBill {

public:
	TblFmncQFpj1NBill();
	virtual ~TblFmncQFpj1NBill();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFpj1NBill** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpj1NBill& rst);

	virtual void insertRec(FmncQFpj1NBill* rec);
	ubigint insertNewRec(FmncQFpj1NBill** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQFpj1NBill& rst, FmncQFpj1NBill** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQFpj1NBill& rst);
	virtual void updateRec(FmncQFpj1NBill* rec);
	virtual void updateRst(ListFmncQFpj1NBill& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFpj1NBill** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpj1NBill& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFpj1NBill: C++ wrapper for table TblFmncQFpj1NBill (MySQL database)
  */
class MyTblFmncQFpj1NBill : public TblFmncQFpj1NBill, public MyTable {

public:
	MyTblFmncQFpj1NBill();
	~MyTblFmncQFpj1NBill();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFpj1NBill** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpj1NBill& rst);

	void insertRec(FmncQFpj1NBill* rec);
	void insertRst(ListFmncQFpj1NBill& rst);
	void updateRec(FmncQFpj1NBill* rec);
	void updateRst(ListFmncQFpj1NBill& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFpj1NBill** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpj1NBill& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFpj1NBill: C++ wrapper for table TblFmncQFpj1NBill (PgSQL database)
  */
class PgTblFmncQFpj1NBill : public TblFmncQFpj1NBill, public PgTable {

public:
	PgTblFmncQFpj1NBill();
	~PgTblFmncQFpj1NBill();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFpj1NBill** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFpj1NBill& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFpj1NBill** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFpj1NBill& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFpj1NBill** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpj1NBill& rst);

	void insertRec(FmncQFpj1NBill* rec);
	void insertRst(ListFmncQFpj1NBill& rst);
	void updateRec(FmncQFpj1NBill* rec);
	void updateRst(ListFmncQFpj1NBill& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFpj1NBill** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpj1NBill& rst);
};
// IP pgTbl --- END

#endif

