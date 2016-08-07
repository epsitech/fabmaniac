/**
  * \file FmncQOrgMNPerson.h
  * Dbs and XML wrapper for table TblFmncQOrgMNPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQORGMNPERSON_H
#define FMNCQORGMNPERSON_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQOrgMNPerson: record of TblFmncQOrgMNPerson
  */
class FmncQOrgMNPerson {

public:
	FmncQOrgMNPerson(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x1Stopd = 0, const string ftmX1Stopd = "", const string srefKFunction = "", const string titSrefKFunction = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint x1Startd;
	string ftmX1Startd;
	uint x1Stopd;
	string ftmX1Stopd;
	string srefKFunction;
	string titSrefKFunction;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQOrgMNPerson: recordset of TblFmncQOrgMNPerson
  */
class ListFmncQOrgMNPerson {

public:
	ListFmncQOrgMNPerson();
	ListFmncQOrgMNPerson(const ListFmncQOrgMNPerson& src);
	~ListFmncQOrgMNPerson();

	void clear();
	unsigned int size() const;
	void append(FmncQOrgMNPerson* rec);

	ListFmncQOrgMNPerson& operator=(const ListFmncQOrgMNPerson& src);

public:
	vector<FmncQOrgMNPerson*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQOrgMNPerson: C++ wrapper for table TblFmncQOrgMNPerson
  */
class TblFmncQOrgMNPerson {

public:
	TblFmncQOrgMNPerson();
	virtual ~TblFmncQOrgMNPerson();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQOrgMNPerson** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMNPerson& rst);

	virtual void insertRec(FmncQOrgMNPerson* rec);
	ubigint insertNewRec(FmncQOrgMNPerson** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x1Stopd = 0, const string ftmX1Stopd = "", const string srefKFunction = "", const string titSrefKFunction = "");
	ubigint appendNewRecToRst(ListFmncQOrgMNPerson& rst, FmncQOrgMNPerson** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Startd = 0, const string ftmX1Startd = "", const uint x1Stopd = 0, const string ftmX1Stopd = "", const string srefKFunction = "", const string titSrefKFunction = "");
	virtual void insertRst(ListFmncQOrgMNPerson& rst);
	virtual void updateRec(FmncQOrgMNPerson* rec);
	virtual void updateRst(ListFmncQOrgMNPerson& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQOrgMNPerson** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMNPerson& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQOrgMNPerson: C++ wrapper for table TblFmncQOrgMNPerson (MySQL database)
  */
class MyTblFmncQOrgMNPerson : public TblFmncQOrgMNPerson, public MyTable {

public:
	MyTblFmncQOrgMNPerson();
	~MyTblFmncQOrgMNPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgMNPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMNPerson& rst);

	void insertRec(FmncQOrgMNPerson* rec);
	void insertRst(ListFmncQOrgMNPerson& rst);
	void updateRec(FmncQOrgMNPerson* rec);
	void updateRst(ListFmncQOrgMNPerson& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgMNPerson** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMNPerson& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQOrgMNPerson: C++ wrapper for table TblFmncQOrgMNPerson (PgSQL database)
  */
class PgTblFmncQOrgMNPerson : public TblFmncQOrgMNPerson, public PgTable {

public:
	PgTblFmncQOrgMNPerson();
	~PgTblFmncQOrgMNPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQOrgMNPerson** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQOrgMNPerson& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQOrgMNPerson** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQOrgMNPerson& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQOrgMNPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQOrgMNPerson& rst);

	void insertRec(FmncQOrgMNPerson* rec);
	void insertRst(ListFmncQOrgMNPerson& rst);
	void updateRec(FmncQOrgMNPerson* rec);
	void updateRst(ListFmncQOrgMNPerson& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQOrgMNPerson** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQOrgMNPerson& rst);
};
// IP pgTbl --- END

#endif

