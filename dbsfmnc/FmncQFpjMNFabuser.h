/**
  * \file FmncQFpjMNFabuser.h
  * Dbs and XML wrapper for table TblFmncQFpjMNFabuser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQFPJMNFABUSER_H
#define FMNCQFPJMNFABUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQFpjMNFabuser: record of TblFmncQFpjMNFabuser
  */
class FmncQFpjMNFabuser {

public:
	FmncQFpjMNFabuser(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQFpjMNFabuser: recordset of TblFmncQFpjMNFabuser
  */
class ListFmncQFpjMNFabuser {

public:
	ListFmncQFpjMNFabuser();
	ListFmncQFpjMNFabuser(const ListFmncQFpjMNFabuser& src);
	~ListFmncQFpjMNFabuser();

	void clear();
	unsigned int size() const;
	void append(FmncQFpjMNFabuser* rec);

	ListFmncQFpjMNFabuser& operator=(const ListFmncQFpjMNFabuser& src);

public:
	vector<FmncQFpjMNFabuser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQFpjMNFabuser: C++ wrapper for table TblFmncQFpjMNFabuser
  */
class TblFmncQFpjMNFabuser {

public:
	TblFmncQFpjMNFabuser();
	virtual ~TblFmncQFpjMNFabuser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQFpjMNFabuser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpjMNFabuser& rst);

	virtual void insertRec(FmncQFpjMNFabuser* rec);
	ubigint insertNewRec(FmncQFpjMNFabuser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQFpjMNFabuser& rst, FmncQFpjMNFabuser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQFpjMNFabuser& rst);
	virtual void updateRec(FmncQFpjMNFabuser* rec);
	virtual void updateRst(ListFmncQFpjMNFabuser& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQFpjMNFabuser** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpjMNFabuser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQFpjMNFabuser: C++ wrapper for table TblFmncQFpjMNFabuser (MySQL database)
  */
class MyTblFmncQFpjMNFabuser : public TblFmncQFpjMNFabuser, public MyTable {

public:
	MyTblFmncQFpjMNFabuser();
	~MyTblFmncQFpjMNFabuser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFpjMNFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpjMNFabuser& rst);

	void insertRec(FmncQFpjMNFabuser* rec);
	void insertRst(ListFmncQFpjMNFabuser& rst);
	void updateRec(FmncQFpjMNFabuser* rec);
	void updateRst(ListFmncQFpjMNFabuser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFpjMNFabuser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpjMNFabuser& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQFpjMNFabuser: C++ wrapper for table TblFmncQFpjMNFabuser (PgSQL database)
  */
class PgTblFmncQFpjMNFabuser : public TblFmncQFpjMNFabuser, public PgTable {

public:
	PgTblFmncQFpjMNFabuser();
	~PgTblFmncQFpjMNFabuser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQFpjMNFabuser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQFpjMNFabuser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQFpjMNFabuser** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQFpjMNFabuser& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQFpjMNFabuser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQFpjMNFabuser& rst);

	void insertRec(FmncQFpjMNFabuser* rec);
	void insertRst(ListFmncQFpjMNFabuser& rst);
	void updateRec(FmncQFpjMNFabuser* rec);
	void updateRst(ListFmncQFpjMNFabuser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQFpjMNFabuser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQFpjMNFabuser& rst);
};
// IP pgTbl --- END

#endif

