/**
  * \file FmncQTolMNFabuser.h
  * Dbs and XML wrapper for table TblFmncQTolMNFabuser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLMNFABUSER_H
#define FMNCQTOLMNFABUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolMNFabuser: record of TblFmncQTolMNFabuser
  */
class FmncQTolMNFabuser {

public:
	FmncQTolMNFabuser(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint trnRefFmncMPerson = 0, const string stubTrnRefFmncMPerson = "", const string srefKLvl = "", const string titSrefKLvl = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	ubigint trnRefFmncMPerson;
	string stubTrnRefFmncMPerson;
	string srefKLvl;
	string titSrefKLvl;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolMNFabuser: recordset of TblFmncQTolMNFabuser
  */
class ListFmncQTolMNFabuser {

public:
	ListFmncQTolMNFabuser();
	ListFmncQTolMNFabuser(const ListFmncQTolMNFabuser& src);
	~ListFmncQTolMNFabuser();

	void clear();
	unsigned int size() const;
	void append(FmncQTolMNFabuser* rec);

	ListFmncQTolMNFabuser& operator=(const ListFmncQTolMNFabuser& src);

public:
	vector<FmncQTolMNFabuser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolMNFabuser: C++ wrapper for table TblFmncQTolMNFabuser
  */
class TblFmncQTolMNFabuser {

public:
	TblFmncQTolMNFabuser();
	virtual ~TblFmncQTolMNFabuser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolMNFabuser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolMNFabuser& rst);

	virtual void insertRec(FmncQTolMNFabuser* rec);
	ubigint insertNewRec(FmncQTolMNFabuser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint trnRefFmncMPerson = 0, const string stubTrnRefFmncMPerson = "", const string srefKLvl = "", const string titSrefKLvl = "");
	ubigint appendNewRecToRst(ListFmncQTolMNFabuser& rst, FmncQTolMNFabuser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint trnRefFmncMPerson = 0, const string stubTrnRefFmncMPerson = "", const string srefKLvl = "", const string titSrefKLvl = "");
	virtual void insertRst(ListFmncQTolMNFabuser& rst);
	virtual void updateRec(FmncQTolMNFabuser* rec);
	virtual void updateRst(ListFmncQTolMNFabuser& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolMNFabuser** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolMNFabuser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolMNFabuser: C++ wrapper for table TblFmncQTolMNFabuser (MySQL database)
  */
class MyTblFmncQTolMNFabuser : public TblFmncQTolMNFabuser, public MyTable {

public:
	MyTblFmncQTolMNFabuser();
	~MyTblFmncQTolMNFabuser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolMNFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolMNFabuser& rst);

	void insertRec(FmncQTolMNFabuser* rec);
	void insertRst(ListFmncQTolMNFabuser& rst);
	void updateRec(FmncQTolMNFabuser* rec);
	void updateRst(ListFmncQTolMNFabuser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolMNFabuser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolMNFabuser& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolMNFabuser: C++ wrapper for table TblFmncQTolMNFabuser (PgSQL database)
  */
class PgTblFmncQTolMNFabuser : public TblFmncQTolMNFabuser, public PgTable {

public:
	PgTblFmncQTolMNFabuser();
	~PgTblFmncQTolMNFabuser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolMNFabuser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolMNFabuser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolMNFabuser** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolMNFabuser& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolMNFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolMNFabuser& rst);

	void insertRec(FmncQTolMNFabuser* rec);
	void insertRst(ListFmncQTolMNFabuser& rst);
	void updateRec(FmncQTolMNFabuser* rec);
	void updateRst(ListFmncQTolMNFabuser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolMNFabuser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolMNFabuser& rst);
};
// IP pgTbl --- END

#endif

