/**
  * \file FmncQRunMNPerson.h
  * Dbs and XML wrapper for table TblFmncQRunMNPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNMNPERSON_H
#define FMNCQRUNMNPERSON_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunMNPerson: record of TblFmncQRunMNPerson
  */
class FmncQRunMNPerson {

public:
	FmncQRunMNPerson(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQRunMNPerson: recordset of TblFmncQRunMNPerson
  */
class ListFmncQRunMNPerson {

public:
	ListFmncQRunMNPerson();
	ListFmncQRunMNPerson(const ListFmncQRunMNPerson& src);
	~ListFmncQRunMNPerson();

	void clear();
	unsigned int size() const;
	void append(FmncQRunMNPerson* rec);

	ListFmncQRunMNPerson& operator=(const ListFmncQRunMNPerson& src);

public:
	vector<FmncQRunMNPerson*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQRunMNPerson: C++ wrapper for table TblFmncQRunMNPerson
  */
class TblFmncQRunMNPerson {

public:
	TblFmncQRunMNPerson();
	virtual ~TblFmncQRunMNPerson();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQRunMNPerson** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNPerson& rst);

	virtual void insertRec(FmncQRunMNPerson* rec);
	ubigint insertNewRec(FmncQRunMNPerson** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQRunMNPerson& rst, FmncQRunMNPerson** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQRunMNPerson& rst);
	virtual void updateRec(FmncQRunMNPerson* rec);
	virtual void updateRst(ListFmncQRunMNPerson& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQRunMNPerson** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNPerson& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQRunMNPerson: C++ wrapper for table TblFmncQRunMNPerson (MySQL database)
  */
class MyTblFmncQRunMNPerson : public TblFmncQRunMNPerson, public MyTable {

public:
	MyTblFmncQRunMNPerson();
	~MyTblFmncQRunMNPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunMNPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNPerson& rst);

	void insertRec(FmncQRunMNPerson* rec);
	void insertRst(ListFmncQRunMNPerson& rst);
	void updateRec(FmncQRunMNPerson* rec);
	void updateRst(ListFmncQRunMNPerson& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunMNPerson** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNPerson& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQRunMNPerson: C++ wrapper for table TblFmncQRunMNPerson (PgSQL database)
  */
class PgTblFmncQRunMNPerson : public TblFmncQRunMNPerson, public PgTable {

public:
	PgTblFmncQRunMNPerson();
	~PgTblFmncQRunMNPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQRunMNPerson** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQRunMNPerson& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQRunMNPerson** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQRunMNPerson& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunMNPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunMNPerson& rst);

	void insertRec(FmncQRunMNPerson* rec);
	void insertRst(ListFmncQRunMNPerson& rst);
	void updateRec(FmncQRunMNPerson* rec);
	void updateRst(ListFmncQRunMNPerson& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunMNPerson** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunMNPerson& rst);
};
// IP pgTbl --- END

#endif

