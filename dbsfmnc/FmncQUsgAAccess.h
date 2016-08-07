/**
  * \file FmncQUsgAAccess.h
  * Dbs and XML wrapper for table TblFmncQUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSGAACCESS_H
#define FMNCQUSGAACCESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsgAAccess: record of TblFmncQUsgAAccess
  */
class FmncQUsgAAccess {

public:
	FmncQUsgAAccess(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxFmncVCard = 0, const string srefX1IxFmncVCard = "", const string titX1IxFmncVCard = "", const uint ixFmncWUiaccess = 0, const string srefsIxFmncWUiaccess = "", const string titsIxFmncWUiaccess = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint x1IxFmncVCard;
	string srefX1IxFmncVCard;
	string titX1IxFmncVCard;
	uint ixFmncWUiaccess;
	string srefsIxFmncWUiaccess;
	string titsIxFmncWUiaccess;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQUsgAAccess: recordset of TblFmncQUsgAAccess
  */
class ListFmncQUsgAAccess {

public:
	ListFmncQUsgAAccess();
	ListFmncQUsgAAccess(const ListFmncQUsgAAccess& src);
	~ListFmncQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(FmncQUsgAAccess* rec);

	ListFmncQUsgAAccess& operator=(const ListFmncQUsgAAccess& src);

public:
	vector<FmncQUsgAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQUsgAAccess: C++ wrapper for table TblFmncQUsgAAccess
  */
class TblFmncQUsgAAccess {

public:
	TblFmncQUsgAAccess();
	virtual ~TblFmncQUsgAAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQUsgAAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgAAccess& rst);

	virtual void insertRec(FmncQUsgAAccess* rec);
	ubigint insertNewRec(FmncQUsgAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxFmncVCard = 0, const string srefX1IxFmncVCard = "", const string titX1IxFmncVCard = "", const uint ixFmncWUiaccess = 0, const string srefsIxFmncWUiaccess = "", const string titsIxFmncWUiaccess = "");
	ubigint appendNewRecToRst(ListFmncQUsgAAccess& rst, FmncQUsgAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxFmncVCard = 0, const string srefX1IxFmncVCard = "", const string titX1IxFmncVCard = "", const uint ixFmncWUiaccess = 0, const string srefsIxFmncWUiaccess = "", const string titsIxFmncWUiaccess = "");
	virtual void insertRst(ListFmncQUsgAAccess& rst);
	virtual void updateRec(FmncQUsgAAccess* rec);
	virtual void updateRst(ListFmncQUsgAAccess& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQUsgAAccess** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgAAccess& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQUsgAAccess: C++ wrapper for table TblFmncQUsgAAccess (MySQL database)
  */
class MyTblFmncQUsgAAccess : public TblFmncQUsgAAccess, public MyTable {

public:
	MyTblFmncQUsgAAccess();
	~MyTblFmncQUsgAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsgAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgAAccess& rst);

	void insertRec(FmncQUsgAAccess* rec);
	void insertRst(ListFmncQUsgAAccess& rst);
	void updateRec(FmncQUsgAAccess* rec);
	void updateRst(ListFmncQUsgAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsgAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgAAccess& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQUsgAAccess: C++ wrapper for table TblFmncQUsgAAccess (PgSQL database)
  */
class PgTblFmncQUsgAAccess : public TblFmncQUsgAAccess, public PgTable {

public:
	PgTblFmncQUsgAAccess();
	~PgTblFmncQUsgAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQUsgAAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQUsgAAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQUsgAAccess** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQUsgAAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsgAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsgAAccess& rst);

	void insertRec(FmncQUsgAAccess* rec);
	void insertRst(ListFmncQUsgAAccess& rst);
	void updateRec(FmncQUsgAAccess* rec);
	void updateRst(ListFmncQUsgAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsgAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsgAAccess& rst);
};
// IP pgTbl --- END

#endif

