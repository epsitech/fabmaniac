/**
  * \file FmncQTtyKToolchar.h
  * Dbs and XML wrapper for table TblFmncQTtyKToolchar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYKTOOLCHAR_H
#define FMNCQTTYKTOOLCHAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyKToolchar: record of TblFmncQTtyKToolchar
  */
class FmncQTtyKToolchar {

public:
	FmncQTtyKToolchar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

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
  * ListFmncQTtyKToolchar: recordset of TblFmncQTtyKToolchar
  */
class ListFmncQTtyKToolchar {

public:
	ListFmncQTtyKToolchar();
	ListFmncQTtyKToolchar(const ListFmncQTtyKToolchar& src);
	~ListFmncQTtyKToolchar();

	void clear();
	unsigned int size() const;
	void append(FmncQTtyKToolchar* rec);

	ListFmncQTtyKToolchar& operator=(const ListFmncQTtyKToolchar& src);

public:
	vector<FmncQTtyKToolchar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTtyKToolchar: C++ wrapper for table TblFmncQTtyKToolchar
  */
class TblFmncQTtyKToolchar {

public:
	TblFmncQTtyKToolchar();
	virtual ~TblFmncQTtyKToolchar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTtyKToolchar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyKToolchar& rst);

	virtual void insertRec(FmncQTtyKToolchar* rec);
	ubigint insertNewRec(FmncQTtyKToolchar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListFmncQTtyKToolchar& rst, FmncQTtyKToolchar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListFmncQTtyKToolchar& rst);
	virtual void updateRec(FmncQTtyKToolchar* rec);
	virtual void updateRst(ListFmncQTtyKToolchar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTtyKToolchar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyKToolchar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTtyKToolchar: C++ wrapper for table TblFmncQTtyKToolchar (MySQL database)
  */
class MyTblFmncQTtyKToolchar : public TblFmncQTtyKToolchar, public MyTable {

public:
	MyTblFmncQTtyKToolchar();
	~MyTblFmncQTtyKToolchar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyKToolchar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyKToolchar& rst);

	void insertRec(FmncQTtyKToolchar* rec);
	void insertRst(ListFmncQTtyKToolchar& rst);
	void updateRec(FmncQTtyKToolchar* rec);
	void updateRst(ListFmncQTtyKToolchar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyKToolchar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyKToolchar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTtyKToolchar: C++ wrapper for table TblFmncQTtyKToolchar (PgSQL database)
  */
class PgTblFmncQTtyKToolchar : public TblFmncQTtyKToolchar, public PgTable {

public:
	PgTblFmncQTtyKToolchar();
	~PgTblFmncQTtyKToolchar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTtyKToolchar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTtyKToolchar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTtyKToolchar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTtyKToolchar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyKToolchar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyKToolchar& rst);

	void insertRec(FmncQTtyKToolchar* rec);
	void insertRst(ListFmncQTtyKToolchar& rst);
	void updateRec(FmncQTtyKToolchar* rec);
	void updateRst(ListFmncQTtyKToolchar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyKToolchar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyKToolchar& rst);
};
// IP pgTbl --- END

#endif

