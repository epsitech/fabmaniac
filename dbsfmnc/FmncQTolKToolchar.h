/**
  * \file FmncQTolKToolchar.h
  * Dbs and XML wrapper for table TblFmncQTolKToolchar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLKTOOLCHAR_H
#define FMNCQTOLKTOOLCHAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolKToolchar: record of TblFmncQTolKToolchar
  */
class FmncQTolKToolchar {

public:
	FmncQTolKToolchar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint klsNum;
	bool Fixed;
	string yesnoFixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolKToolchar: recordset of TblFmncQTolKToolchar
  */
class ListFmncQTolKToolchar {

public:
	ListFmncQTolKToolchar();
	ListFmncQTolKToolchar(const ListFmncQTolKToolchar& src);
	~ListFmncQTolKToolchar();

	void clear();
	unsigned int size() const;
	void append(FmncQTolKToolchar* rec);

	ListFmncQTolKToolchar& operator=(const ListFmncQTolKToolchar& src);

public:
	vector<FmncQTolKToolchar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolKToolchar: C++ wrapper for table TblFmncQTolKToolchar
  */
class TblFmncQTolKToolchar {

public:
	TblFmncQTolKToolchar();
	virtual ~TblFmncQTolKToolchar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolKToolchar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolKToolchar& rst);

	virtual void insertRec(FmncQTolKToolchar* rec);
	ubigint insertNewRec(FmncQTolKToolchar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQTolKToolchar& rst, FmncQTolKToolchar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncQTolKToolchar& rst);
	virtual void updateRec(FmncQTolKToolchar* rec);
	virtual void updateRst(ListFmncQTolKToolchar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolKToolchar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolKToolchar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolKToolchar: C++ wrapper for table TblFmncQTolKToolchar (MySQL database)
  */
class MyTblFmncQTolKToolchar : public TblFmncQTolKToolchar, public MyTable {

public:
	MyTblFmncQTolKToolchar();
	~MyTblFmncQTolKToolchar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolKToolchar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolKToolchar& rst);

	void insertRec(FmncQTolKToolchar* rec);
	void insertRst(ListFmncQTolKToolchar& rst);
	void updateRec(FmncQTolKToolchar* rec);
	void updateRst(ListFmncQTolKToolchar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolKToolchar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolKToolchar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolKToolchar: C++ wrapper for table TblFmncQTolKToolchar (PgSQL database)
  */
class PgTblFmncQTolKToolchar : public TblFmncQTolKToolchar, public PgTable {

public:
	PgTblFmncQTolKToolchar();
	~PgTblFmncQTolKToolchar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolKToolchar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolKToolchar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolKToolchar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolKToolchar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolKToolchar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolKToolchar& rst);

	void insertRec(FmncQTolKToolchar* rec);
	void insertRst(ListFmncQTolKToolchar& rst);
	void updateRec(FmncQTolKToolchar* rec);
	void updateRst(ListFmncQTolKToolchar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolKToolchar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolKToolchar& rst);
};
// IP pgTbl --- END

#endif

