/**
  * \file FmncQTolRef1NFile.h
  * Dbs and XML wrapper for table TblFmncQTolRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQTOLREF1NFILE_H
#define FMNCQTOLREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQTolRef1NFile: record of TblFmncQTolRef1NFile
  */
class FmncQTolRef1NFile {

public:
	FmncQTolRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQTolRef1NFile: recordset of TblFmncQTolRef1NFile
  */
class ListFmncQTolRef1NFile {

public:
	ListFmncQTolRef1NFile();
	ListFmncQTolRef1NFile(const ListFmncQTolRef1NFile& src);
	~ListFmncQTolRef1NFile();

	void clear();
	unsigned int size() const;
	void append(FmncQTolRef1NFile* rec);

	ListFmncQTolRef1NFile& operator=(const ListFmncQTolRef1NFile& src);

public:
	vector<FmncQTolRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQTolRef1NFile: C++ wrapper for table TblFmncQTolRef1NFile
  */
class TblFmncQTolRef1NFile {

public:
	TblFmncQTolRef1NFile();
	virtual ~TblFmncQTolRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQTolRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolRef1NFile& rst);

	virtual void insertRec(FmncQTolRef1NFile* rec);
	ubigint insertNewRec(FmncQTolRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQTolRef1NFile& rst, FmncQTolRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQTolRef1NFile& rst);
	virtual void updateRec(FmncQTolRef1NFile* rec);
	virtual void updateRst(ListFmncQTolRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQTolRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQTolRef1NFile: C++ wrapper for table TblFmncQTolRef1NFile (MySQL database)
  */
class MyTblFmncQTolRef1NFile : public TblFmncQTolRef1NFile, public MyTable {

public:
	MyTblFmncQTolRef1NFile();
	~MyTblFmncQTolRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolRef1NFile& rst);

	void insertRec(FmncQTolRef1NFile* rec);
	void insertRst(ListFmncQTolRef1NFile& rst);
	void updateRec(FmncQTolRef1NFile* rec);
	void updateRst(ListFmncQTolRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQTolRef1NFile: C++ wrapper for table TblFmncQTolRef1NFile (PgSQL database)
  */
class PgTblFmncQTolRef1NFile : public TblFmncQTolRef1NFile, public PgTable {

public:
	PgTblFmncQTolRef1NFile();
	~PgTblFmncQTolRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQTolRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQTolRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQTolRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQTolRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQTolRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQTolRef1NFile& rst);

	void insertRec(FmncQTolRef1NFile* rec);
	void insertRst(ListFmncQTolRef1NFile& rst);
	void updateRec(FmncQTolRef1NFile* rec);
	void updateRst(ListFmncQTolRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQTolRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQTolRef1NFile& rst);
};
// IP pgTbl --- END

#endif

