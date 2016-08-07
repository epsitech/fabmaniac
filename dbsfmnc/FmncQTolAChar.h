/**
  * \file FmncQTolAChar.h
  * Dbs and XML wrapper for table TblFmncQTolAChar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLACHAR_H
#define FMNCQTOLACHAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolAChar: record of TblFmncQTolAChar
  */
class FmncQTolAChar {

public:
	FmncQTolAChar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKToolchar = "", const string titX1OsrefFmncKToolchar = "", const string Val = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x1OsrefFmncKToolchar;
	string titX1OsrefFmncKToolchar;
	string Val;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolAChar: recordset of TblFmncQTolAChar
  */
class ListFmncQTolAChar {

public:
	ListFmncQTolAChar();
	ListFmncQTolAChar(const ListFmncQTolAChar& src);
	~ListFmncQTolAChar();

	void clear();
	unsigned int size() const;
	void append(FmncQTolAChar* rec);

	ListFmncQTolAChar& operator=(const ListFmncQTolAChar& src);

public:
	vector<FmncQTolAChar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolAChar: C++ wrapper for table TblFmncQTolAChar
  */
class TblFmncQTolAChar {

public:
	TblFmncQTolAChar();
	virtual ~TblFmncQTolAChar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolAChar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAChar& rst);

	virtual void insertRec(FmncQTolAChar* rec);
	ubigint insertNewRec(FmncQTolAChar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKToolchar = "", const string titX1OsrefFmncKToolchar = "", const string Val = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQTolAChar& rst, FmncQTolAChar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1OsrefFmncKToolchar = "", const string titX1OsrefFmncKToolchar = "", const string Val = "", const string Comment = "");
	virtual void insertRst(ListFmncQTolAChar& rst);
	virtual void updateRec(FmncQTolAChar* rec);
	virtual void updateRst(ListFmncQTolAChar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolAChar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAChar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolAChar: C++ wrapper for table TblFmncQTolAChar (MySQL database)
  */
class MyTblFmncQTolAChar : public TblFmncQTolAChar, public MyTable {

public:
	MyTblFmncQTolAChar();
	~MyTblFmncQTolAChar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolAChar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAChar& rst);

	void insertRec(FmncQTolAChar* rec);
	void insertRst(ListFmncQTolAChar& rst);
	void updateRec(FmncQTolAChar* rec);
	void updateRst(ListFmncQTolAChar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolAChar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAChar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolAChar: C++ wrapper for table TblFmncQTolAChar (PgSQL database)
  */
class PgTblFmncQTolAChar : public TblFmncQTolAChar, public PgTable {

public:
	PgTblFmncQTolAChar();
	~PgTblFmncQTolAChar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolAChar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolAChar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolAChar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolAChar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolAChar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolAChar& rst);

	void insertRec(FmncQTolAChar* rec);
	void insertRst(ListFmncQTolAChar& rst);
	void updateRec(FmncQTolAChar* rec);
	void updateRst(ListFmncQTolAChar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolAChar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolAChar& rst);
};
// IP pgTbl --- END

#endif

