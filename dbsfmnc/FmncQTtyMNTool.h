/**
  * \file FmncQTtyMNTool.h
  * Dbs and XML wrapper for table TblFmncQTtyMNTool (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTTYMNTOOL_H
#define FMNCQTTYMNTOOL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTtyMNTool: record of TblFmncQTtyMNTool
  */
class FmncQTtyMNTool {

public:
	FmncQTtyMNTool(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefsFmncKToolchar = "", const string titsSrefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string titsDefSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "", const string titsOptSrefsFmncKSteppar = "");

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
  * ListFmncQTtyMNTool: recordset of TblFmncQTtyMNTool
  */
class ListFmncQTtyMNTool {

public:
	ListFmncQTtyMNTool();
	ListFmncQTtyMNTool(const ListFmncQTtyMNTool& src);
	~ListFmncQTtyMNTool();

	void clear();
	unsigned int size() const;
	void append(FmncQTtyMNTool* rec);

	ListFmncQTtyMNTool& operator=(const ListFmncQTtyMNTool& src);

public:
	vector<FmncQTtyMNTool*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTtyMNTool: C++ wrapper for table TblFmncQTtyMNTool
  */
class TblFmncQTtyMNTool {

public:
	TblFmncQTtyMNTool();
	virtual ~TblFmncQTtyMNTool();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTtyMNTool** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyMNTool& rst);

	virtual void insertRec(FmncQTtyMNTool* rec);
	ubigint insertNewRec(FmncQTtyMNTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefsFmncKToolchar = "", const string titsSrefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string titsDefSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "", const string titsOptSrefsFmncKSteppar = "");
	ubigint appendNewRecToRst(ListFmncQTtyMNTool& rst, FmncQTtyMNTool** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefsFmncKToolchar = "", const string titsSrefsFmncKToolchar = "", const string defSrefsFmncKSteppar = "", const string titsDefSrefsFmncKSteppar = "", const string optSrefsFmncKSteppar = "", const string titsOptSrefsFmncKSteppar = "");
	virtual void insertRst(ListFmncQTtyMNTool& rst);
	virtual void updateRec(FmncQTtyMNTool* rec);
	virtual void updateRst(ListFmncQTtyMNTool& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTtyMNTool** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyMNTool& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTtyMNTool: C++ wrapper for table TblFmncQTtyMNTool (MySQL database)
  */
class MyTblFmncQTtyMNTool : public TblFmncQTtyMNTool, public MyTable {

public:
	MyTblFmncQTtyMNTool();
	~MyTblFmncQTtyMNTool();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyMNTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyMNTool& rst);

	void insertRec(FmncQTtyMNTool* rec);
	void insertRst(ListFmncQTtyMNTool& rst);
	void updateRec(FmncQTtyMNTool* rec);
	void updateRst(ListFmncQTtyMNTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyMNTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyMNTool& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTtyMNTool: C++ wrapper for table TblFmncQTtyMNTool (PgSQL database)
  */
class PgTblFmncQTtyMNTool : public TblFmncQTtyMNTool, public PgTable {

public:
	PgTblFmncQTtyMNTool();
	~PgTblFmncQTtyMNTool();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTtyMNTool** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTtyMNTool& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTtyMNTool** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTtyMNTool& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTtyMNTool** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTtyMNTool& rst);

	void insertRec(FmncQTtyMNTool* rec);
	void insertRst(ListFmncQTtyMNTool& rst);
	void updateRec(FmncQTtyMNTool* rec);
	void updateRst(ListFmncQTtyMNTool& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTtyMNTool** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTtyMNTool& rst);
};
// IP pgTbl --- END

#endif

