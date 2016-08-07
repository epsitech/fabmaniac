/**
  * \file FmncQTolSvcMNOrg.h
  * Dbs and XML wrapper for table TblFmncQTolSvcMNOrg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLSVCMNORG_H
#define FMNCQTOLSVCMNORG_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolSvcMNOrg: record of TblFmncQTolSvcMNOrg
  */
class FmncQTolSvcMNOrg {

public:
	FmncQTolSvcMNOrg(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMPerson = "", const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	string stubsTrefFmncMPerson;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolSvcMNOrg: recordset of TblFmncQTolSvcMNOrg
  */
class ListFmncQTolSvcMNOrg {

public:
	ListFmncQTolSvcMNOrg();
	ListFmncQTolSvcMNOrg(const ListFmncQTolSvcMNOrg& src);
	~ListFmncQTolSvcMNOrg();

	void clear();
	unsigned int size() const;
	void append(FmncQTolSvcMNOrg* rec);

	ListFmncQTolSvcMNOrg& operator=(const ListFmncQTolSvcMNOrg& src);

public:
	vector<FmncQTolSvcMNOrg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolSvcMNOrg: C++ wrapper for table TblFmncQTolSvcMNOrg
  */
class TblFmncQTolSvcMNOrg {

public:
	TblFmncQTolSvcMNOrg();
	virtual ~TblFmncQTolSvcMNOrg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolSvcMNOrg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolSvcMNOrg& rst);

	virtual void insertRec(FmncQTolSvcMNOrg* rec);
	ubigint insertNewRec(FmncQTolSvcMNOrg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMPerson = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQTolSvcMNOrg& rst, FmncQTolSvcMNOrg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMPerson = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQTolSvcMNOrg& rst);
	virtual void updateRec(FmncQTolSvcMNOrg* rec);
	virtual void updateRst(ListFmncQTolSvcMNOrg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolSvcMNOrg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolSvcMNOrg& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolSvcMNOrg: C++ wrapper for table TblFmncQTolSvcMNOrg (MySQL database)
  */
class MyTblFmncQTolSvcMNOrg : public TblFmncQTolSvcMNOrg, public MyTable {

public:
	MyTblFmncQTolSvcMNOrg();
	~MyTblFmncQTolSvcMNOrg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolSvcMNOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolSvcMNOrg& rst);

	void insertRec(FmncQTolSvcMNOrg* rec);
	void insertRst(ListFmncQTolSvcMNOrg& rst);
	void updateRec(FmncQTolSvcMNOrg* rec);
	void updateRst(ListFmncQTolSvcMNOrg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolSvcMNOrg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolSvcMNOrg& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolSvcMNOrg: C++ wrapper for table TblFmncQTolSvcMNOrg (PgSQL database)
  */
class PgTblFmncQTolSvcMNOrg : public TblFmncQTolSvcMNOrg, public PgTable {

public:
	PgTblFmncQTolSvcMNOrg();
	~PgTblFmncQTolSvcMNOrg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolSvcMNOrg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolSvcMNOrg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolSvcMNOrg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolSvcMNOrg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolSvcMNOrg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolSvcMNOrg& rst);

	void insertRec(FmncQTolSvcMNOrg* rec);
	void insertRst(ListFmncQTolSvcMNOrg& rst);
	void updateRec(FmncQTolSvcMNOrg* rec);
	void updateRst(ListFmncQTolSvcMNOrg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolSvcMNOrg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolSvcMNOrg& rst);
};
// IP pgTbl --- END

#endif

