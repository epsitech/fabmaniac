/**
  * \file FmncQUsrAAccess.h
  * Dbs and XML wrapper for table TblFmncQUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQUSRAACCESS_H
#define FMNCQUSRAACCESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQUsrAAccess: record of TblFmncQUsrAAccess
  */
class FmncQUsrAAccess {

public:
	FmncQUsrAAccess(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxFmncVCard = 0, const string srefX1IxFmncVCard = "", const string titX1IxFmncVCard = "", const uint ixFmncWUiaccess = 0, const string srefsIxFmncWUiaccess = "", const string titsIxFmncWUiaccess = "");

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
  * ListFmncQUsrAAccess: recordset of TblFmncQUsrAAccess
  */
class ListFmncQUsrAAccess {

public:
	ListFmncQUsrAAccess();
	ListFmncQUsrAAccess(const ListFmncQUsrAAccess& src);
	~ListFmncQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(FmncQUsrAAccess* rec);

	ListFmncQUsrAAccess& operator=(const ListFmncQUsrAAccess& src);

public:
	vector<FmncQUsrAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQUsrAAccess: C++ wrapper for table TblFmncQUsrAAccess
  */
class TblFmncQUsrAAccess {

public:
	TblFmncQUsrAAccess();
	virtual ~TblFmncQUsrAAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQUsrAAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrAAccess& rst);

	virtual void insertRec(FmncQUsrAAccess* rec);
	ubigint insertNewRec(FmncQUsrAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxFmncVCard = 0, const string srefX1IxFmncVCard = "", const string titX1IxFmncVCard = "", const uint ixFmncWUiaccess = 0, const string srefsIxFmncWUiaccess = "", const string titsIxFmncWUiaccess = "");
	ubigint appendNewRecToRst(ListFmncQUsrAAccess& rst, FmncQUsrAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxFmncVCard = 0, const string srefX1IxFmncVCard = "", const string titX1IxFmncVCard = "", const uint ixFmncWUiaccess = 0, const string srefsIxFmncWUiaccess = "", const string titsIxFmncWUiaccess = "");
	virtual void insertRst(ListFmncQUsrAAccess& rst);
	virtual void updateRec(FmncQUsrAAccess* rec);
	virtual void updateRst(ListFmncQUsrAAccess& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQUsrAAccess** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrAAccess& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQUsrAAccess: C++ wrapper for table TblFmncQUsrAAccess (MySQL database)
  */
class MyTblFmncQUsrAAccess : public TblFmncQUsrAAccess, public MyTable {

public:
	MyTblFmncQUsrAAccess();
	~MyTblFmncQUsrAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsrAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrAAccess& rst);

	void insertRec(FmncQUsrAAccess* rec);
	void insertRst(ListFmncQUsrAAccess& rst);
	void updateRec(FmncQUsrAAccess* rec);
	void updateRst(ListFmncQUsrAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsrAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrAAccess& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQUsrAAccess: C++ wrapper for table TblFmncQUsrAAccess (PgSQL database)
  */
class PgTblFmncQUsrAAccess : public TblFmncQUsrAAccess, public PgTable {

public:
	PgTblFmncQUsrAAccess();
	~PgTblFmncQUsrAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQUsrAAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQUsrAAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQUsrAAccess** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQUsrAAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQUsrAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQUsrAAccess& rst);

	void insertRec(FmncQUsrAAccess* rec);
	void insertRst(ListFmncQUsrAAccess& rst);
	void updateRec(FmncQUsrAAccess* rec);
	void updateRst(ListFmncQUsrAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQUsrAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQUsrAAccess& rst);
};
// IP pgTbl --- END

#endif

