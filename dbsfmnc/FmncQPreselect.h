/**
  * \file FmncQPreselect.h
  * Dbs and XML wrapper for table TblFmncQPreselect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQPRESELECT_H
#define FMNCQPRESELECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQPreselect: record of TblFmncQPreselect
  */
class FmncQPreselect {

public:
	FmncQPreselect(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQPreselect: recordset of TblFmncQPreselect
  */
class ListFmncQPreselect {

public:
	ListFmncQPreselect();
	ListFmncQPreselect(const ListFmncQPreselect& src);
	~ListFmncQPreselect();

	void clear();
	unsigned int size() const;
	void append(FmncQPreselect* rec);

	ListFmncQPreselect& operator=(const ListFmncQPreselect& src);

public:
	vector<FmncQPreselect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQPreselect: C++ wrapper for table TblFmncQPreselect
  */
class TblFmncQPreselect {

public:
	TblFmncQPreselect();
	virtual ~TblFmncQPreselect();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQPreselect** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPreselect& rst);

	virtual void insertRec(FmncQPreselect* rec);
	ubigint insertNewRec(FmncQPreselect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQPreselect& rst, FmncQPreselect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);
	virtual void insertRst(ListFmncQPreselect& rst);
	virtual void updateRec(FmncQPreselect* rec);
	virtual void updateRst(ListFmncQPreselect& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQPreselect** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPreselect& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQPreselect: C++ wrapper for table TblFmncQPreselect (MySQL database)
  */
class MyTblFmncQPreselect : public TblFmncQPreselect, public MyTable {

public:
	MyTblFmncQPreselect();
	~MyTblFmncQPreselect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPreselect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPreselect& rst);

	void insertRec(FmncQPreselect* rec);
	void insertRst(ListFmncQPreselect& rst);
	void updateRec(FmncQPreselect* rec);
	void updateRst(ListFmncQPreselect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPreselect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPreselect& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQPreselect: C++ wrapper for table TblFmncQPreselect (PgSQL database)
  */
class PgTblFmncQPreselect : public TblFmncQPreselect, public PgTable {

public:
	PgTblFmncQPreselect();
	~PgTblFmncQPreselect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQPreselect** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQPreselect& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQPreselect** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQPreselect& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQPreselect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQPreselect& rst);

	void insertRec(FmncQPreselect* rec);
	void insertRst(ListFmncQPreselect& rst);
	void updateRec(FmncQPreselect* rec);
	void updateRst(ListFmncQPreselect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQPreselect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQPreselect& rst);
};
// IP pgTbl --- END

#endif

