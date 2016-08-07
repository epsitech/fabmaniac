/**
  * \file FmncQSmpRef1NFile.h
  * Dbs and XML wrapper for table TblFmncQSmpRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPREF1NFILE_H
#define FMNCQSMPREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpRef1NFile: record of TblFmncQSmpRef1NFile
  */
class FmncQSmpRef1NFile {

public:
	FmncQSmpRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQSmpRef1NFile: recordset of TblFmncQSmpRef1NFile
  */
class ListFmncQSmpRef1NFile {

public:
	ListFmncQSmpRef1NFile();
	ListFmncQSmpRef1NFile(const ListFmncQSmpRef1NFile& src);
	~ListFmncQSmpRef1NFile();

	void clear();
	unsigned int size() const;
	void append(FmncQSmpRef1NFile* rec);

	ListFmncQSmpRef1NFile& operator=(const ListFmncQSmpRef1NFile& src);

public:
	vector<FmncQSmpRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSmpRef1NFile: C++ wrapper for table TblFmncQSmpRef1NFile
  */
class TblFmncQSmpRef1NFile {

public:
	TblFmncQSmpRef1NFile();
	virtual ~TblFmncQSmpRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSmpRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpRef1NFile& rst);

	virtual void insertRec(FmncQSmpRef1NFile* rec);
	ubigint insertNewRec(FmncQSmpRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQSmpRef1NFile& rst, FmncQSmpRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQSmpRef1NFile& rst);
	virtual void updateRec(FmncQSmpRef1NFile* rec);
	virtual void updateRst(ListFmncQSmpRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSmpRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSmpRef1NFile: C++ wrapper for table TblFmncQSmpRef1NFile (MySQL database)
  */
class MyTblFmncQSmpRef1NFile : public TblFmncQSmpRef1NFile, public MyTable {

public:
	MyTblFmncQSmpRef1NFile();
	~MyTblFmncQSmpRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpRef1NFile& rst);

	void insertRec(FmncQSmpRef1NFile* rec);
	void insertRst(ListFmncQSmpRef1NFile& rst);
	void updateRec(FmncQSmpRef1NFile* rec);
	void updateRst(ListFmncQSmpRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSmpRef1NFile: C++ wrapper for table TblFmncQSmpRef1NFile (PgSQL database)
  */
class PgTblFmncQSmpRef1NFile : public TblFmncQSmpRef1NFile, public PgTable {

public:
	PgTblFmncQSmpRef1NFile();
	~PgTblFmncQSmpRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSmpRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSmpRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSmpRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSmpRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpRef1NFile& rst);

	void insertRec(FmncQSmpRef1NFile* rec);
	void insertRst(ListFmncQSmpRef1NFile& rst);
	void updateRec(FmncQSmpRef1NFile* rec);
	void updateRst(ListFmncQSmpRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpRef1NFile& rst);
};
// IP pgTbl --- END

#endif

