/**
  * \file FmncQRunRef1NFile.h
  * Dbs and XML wrapper for table TblFmncQRunRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQRUNREF1NFILE_H
#define FMNCQRUNREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQRunRef1NFile: record of TblFmncQRunRef1NFile
  */
class FmncQRunRef1NFile {

public:
	FmncQRunRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQRunRef1NFile: recordset of TblFmncQRunRef1NFile
  */
class ListFmncQRunRef1NFile {

public:
	ListFmncQRunRef1NFile();
	ListFmncQRunRef1NFile(const ListFmncQRunRef1NFile& src);
	~ListFmncQRunRef1NFile();

	void clear();
	unsigned int size() const;
	void append(FmncQRunRef1NFile* rec);

	ListFmncQRunRef1NFile& operator=(const ListFmncQRunRef1NFile& src);

public:
	vector<FmncQRunRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQRunRef1NFile: C++ wrapper for table TblFmncQRunRef1NFile
  */
class TblFmncQRunRef1NFile {

public:
	TblFmncQRunRef1NFile();
	virtual ~TblFmncQRunRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQRunRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunRef1NFile& rst);

	virtual void insertRec(FmncQRunRef1NFile* rec);
	ubigint insertNewRec(FmncQRunRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQRunRef1NFile& rst, FmncQRunRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQRunRef1NFile& rst);
	virtual void updateRec(FmncQRunRef1NFile* rec);
	virtual void updateRst(ListFmncQRunRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQRunRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQRunRef1NFile: C++ wrapper for table TblFmncQRunRef1NFile (MySQL database)
  */
class MyTblFmncQRunRef1NFile : public TblFmncQRunRef1NFile, public MyTable {

public:
	MyTblFmncQRunRef1NFile();
	~MyTblFmncQRunRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunRef1NFile& rst);

	void insertRec(FmncQRunRef1NFile* rec);
	void insertRst(ListFmncQRunRef1NFile& rst);
	void updateRec(FmncQRunRef1NFile* rec);
	void updateRst(ListFmncQRunRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQRunRef1NFile: C++ wrapper for table TblFmncQRunRef1NFile (PgSQL database)
  */
class PgTblFmncQRunRef1NFile : public TblFmncQRunRef1NFile, public PgTable {

public:
	PgTblFmncQRunRef1NFile();
	~PgTblFmncQRunRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQRunRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQRunRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQRunRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQRunRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQRunRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQRunRef1NFile& rst);

	void insertRec(FmncQRunRef1NFile* rec);
	void insertRst(ListFmncQRunRef1NFile& rst);
	void updateRec(FmncQRunRef1NFile* rec);
	void updateRst(ListFmncQRunRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQRunRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQRunRef1NFile& rst);
};
// IP pgTbl --- END

#endif

