/**
  * \file FmncQTolMNTooltype.h
  * Dbs and XML wrapper for table TblFmncQTolMNTooltype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLMNTOOLTYPE_H
#define FMNCQTOLMNTOOLTYPE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolMNTooltype: record of TblFmncQTolMNTooltype
  */
class FmncQTolMNTooltype {

public:
	FmncQTolMNTooltype(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefsFmncKToolchar = "", const string titsSrefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string titsDefSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "", const string titsOptSrefsFmncKSteppar = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	string srefsFmncKToolchar;
	string titsSrefsFmncKToolchar;
	string defSrefsFmncKSteppar;
	string titsDefSrefsFmncKSteppar;
	string optSrefsFmncKSteppar;
	string titsOptSrefsFmncKSteppar;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolMNTooltype: recordset of TblFmncQTolMNTooltype
  */
class ListFmncQTolMNTooltype {

public:
	ListFmncQTolMNTooltype();
	ListFmncQTolMNTooltype(const ListFmncQTolMNTooltype& src);
	~ListFmncQTolMNTooltype();

	void clear();
	unsigned int size() const;
	void append(FmncQTolMNTooltype* rec);

	ListFmncQTolMNTooltype& operator=(const ListFmncQTolMNTooltype& src);

public:
	vector<FmncQTolMNTooltype*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolMNTooltype: C++ wrapper for table TblFmncQTolMNTooltype
  */
class TblFmncQTolMNTooltype {

public:
	TblFmncQTolMNTooltype();
	virtual ~TblFmncQTolMNTooltype();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolMNTooltype** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolMNTooltype& rst);

	virtual void insertRec(FmncQTolMNTooltype* rec);
	ubigint insertNewRec(FmncQTolMNTooltype** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefsFmncKToolchar = "", const string titsSrefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string titsDefSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "", const string titsOptSrefsFmncKSteppar = "");
	ubigint appendNewRecToRst(ListFmncQTolMNTooltype& rst, FmncQTolMNTooltype** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefsFmncKToolchar = "", const string titsSrefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string titsDefSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "", const string titsOptSrefsFmncKSteppar = "");
	virtual void insertRst(ListFmncQTolMNTooltype& rst);
	virtual void updateRec(FmncQTolMNTooltype* rec);
	virtual void updateRst(ListFmncQTolMNTooltype& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolMNTooltype** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolMNTooltype& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolMNTooltype: C++ wrapper for table TblFmncQTolMNTooltype (MySQL database)
  */
class MyTblFmncQTolMNTooltype : public TblFmncQTolMNTooltype, public MyTable {

public:
	MyTblFmncQTolMNTooltype();
	~MyTblFmncQTolMNTooltype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolMNTooltype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolMNTooltype& rst);

	void insertRec(FmncQTolMNTooltype* rec);
	void insertRst(ListFmncQTolMNTooltype& rst);
	void updateRec(FmncQTolMNTooltype* rec);
	void updateRst(ListFmncQTolMNTooltype& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolMNTooltype** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolMNTooltype& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolMNTooltype: C++ wrapper for table TblFmncQTolMNTooltype (PgSQL database)
  */
class PgTblFmncQTolMNTooltype : public TblFmncQTolMNTooltype, public PgTable {

public:
	PgTblFmncQTolMNTooltype();
	~PgTblFmncQTolMNTooltype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolMNTooltype** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolMNTooltype& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolMNTooltype** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolMNTooltype& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolMNTooltype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolMNTooltype& rst);

	void insertRec(FmncQTolMNTooltype* rec);
	void insertRst(ListFmncQTolMNTooltype& rst);
	void updateRec(FmncQTolMNTooltype* rec);
	void updateRst(ListFmncQTolMNTooltype& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolMNTooltype** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolMNTooltype& rst);
};
// IP pgTbl --- END

#endif

