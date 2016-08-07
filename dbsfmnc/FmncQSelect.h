/**
  * \file FmncQSelect.h
  * Dbs and XML wrapper for table TblFmncQSelect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSELECT_H
#define FMNCQSELECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSelect: record of TblFmncQSelect
  */
class FmncQSelect {

public:
	FmncQSelect(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	uint ix;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQSelect: recordset of TblFmncQSelect
  */
class ListFmncQSelect {

public:
	ListFmncQSelect();
	ListFmncQSelect(const ListFmncQSelect& src);
	~ListFmncQSelect();

	void clear();
	unsigned int size() const;
	void append(FmncQSelect* rec);

	ListFmncQSelect& operator=(const ListFmncQSelect& src);

public:
	vector<FmncQSelect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSelect: C++ wrapper for table TblFmncQSelect
  */
class TblFmncQSelect {

public:
	TblFmncQSelect();
	virtual ~TblFmncQSelect();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSelect** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSelect& rst);

	virtual void insertRec(FmncQSelect* rec);
	ubigint insertNewRec(FmncQSelect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQSelect& rst, FmncQSelect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);
	virtual void insertRst(ListFmncQSelect& rst);
	virtual void updateRec(FmncQSelect* rec);
	virtual void updateRst(ListFmncQSelect& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSelect** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSelect& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSelect: C++ wrapper for table TblFmncQSelect (MySQL database)
  */
class MyTblFmncQSelect : public TblFmncQSelect, public MyTable {

public:
	MyTblFmncQSelect();
	~MyTblFmncQSelect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSelect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSelect& rst);

	void insertRec(FmncQSelect* rec);
	void insertRst(ListFmncQSelect& rst);
	void updateRec(FmncQSelect* rec);
	void updateRst(ListFmncQSelect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSelect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSelect& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSelect: C++ wrapper for table TblFmncQSelect (PgSQL database)
  */
class PgTblFmncQSelect : public TblFmncQSelect, public PgTable {

public:
	PgTblFmncQSelect();
	~PgTblFmncQSelect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSelect** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSelect& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSelect** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSelect& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSelect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSelect& rst);

	void insertRec(FmncQSelect* rec);
	void insertRst(ListFmncQSelect& rst);
	void updateRec(FmncQSelect* rec);
	void updateRst(ListFmncQSelect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSelect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSelect& rst);
};
// IP pgTbl --- END

#endif

