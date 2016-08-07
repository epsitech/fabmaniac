/**
  * \file FmncQSepRef1NFile.h
  * Dbs and XML wrapper for table TblFmncQSepRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPREF1NFILE_H
#define FMNCQSEPREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepRef1NFile: record of TblFmncQSepRef1NFile
  */
class FmncQSepRef1NFile {

public:
	FmncQSepRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQSepRef1NFile: recordset of TblFmncQSepRef1NFile
  */
class ListFmncQSepRef1NFile {

public:
	ListFmncQSepRef1NFile();
	ListFmncQSepRef1NFile(const ListFmncQSepRef1NFile& src);
	~ListFmncQSepRef1NFile();

	void clear();
	unsigned int size() const;
	void append(FmncQSepRef1NFile* rec);

	ListFmncQSepRef1NFile& operator=(const ListFmncQSepRef1NFile& src);

public:
	vector<FmncQSepRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSepRef1NFile: C++ wrapper for table TblFmncQSepRef1NFile
  */
class TblFmncQSepRef1NFile {

public:
	TblFmncQSepRef1NFile();
	virtual ~TblFmncQSepRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSepRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepRef1NFile& rst);

	virtual void insertRec(FmncQSepRef1NFile* rec);
	ubigint insertNewRec(FmncQSepRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQSepRef1NFile& rst, FmncQSepRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQSepRef1NFile& rst);
	virtual void updateRec(FmncQSepRef1NFile* rec);
	virtual void updateRst(ListFmncQSepRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSepRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSepRef1NFile: C++ wrapper for table TblFmncQSepRef1NFile (MySQL database)
  */
class MyTblFmncQSepRef1NFile : public TblFmncQSepRef1NFile, public MyTable {

public:
	MyTblFmncQSepRef1NFile();
	~MyTblFmncQSepRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepRef1NFile& rst);

	void insertRec(FmncQSepRef1NFile* rec);
	void insertRst(ListFmncQSepRef1NFile& rst);
	void updateRec(FmncQSepRef1NFile* rec);
	void updateRst(ListFmncQSepRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSepRef1NFile: C++ wrapper for table TblFmncQSepRef1NFile (PgSQL database)
  */
class PgTblFmncQSepRef1NFile : public TblFmncQSepRef1NFile, public PgTable {

public:
	PgTblFmncQSepRef1NFile();
	~PgTblFmncQSepRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSepRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSepRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSepRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSepRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepRef1NFile& rst);

	void insertRec(FmncQSepRef1NFile* rec);
	void insertRst(ListFmncQSepRef1NFile& rst);
	void updateRec(FmncQSepRef1NFile* rec);
	void updateRst(ListFmncQSepRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepRef1NFile& rst);
};
// IP pgTbl --- END

#endif

