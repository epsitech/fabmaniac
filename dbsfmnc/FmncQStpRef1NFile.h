/**
  * \file FmncQStpRef1NFile.h
  * Dbs and XML wrapper for table TblFmncQStpRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPREF1NFILE_H
#define FMNCQSTPREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpRef1NFile: record of TblFmncQStpRef1NFile
  */
class FmncQStpRef1NFile {

public:
	FmncQStpRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQStpRef1NFile: recordset of TblFmncQStpRef1NFile
  */
class ListFmncQStpRef1NFile {

public:
	ListFmncQStpRef1NFile();
	ListFmncQStpRef1NFile(const ListFmncQStpRef1NFile& src);
	~ListFmncQStpRef1NFile();

	void clear();
	unsigned int size() const;
	void append(FmncQStpRef1NFile* rec);

	ListFmncQStpRef1NFile& operator=(const ListFmncQStpRef1NFile& src);

public:
	vector<FmncQStpRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQStpRef1NFile: C++ wrapper for table TblFmncQStpRef1NFile
  */
class TblFmncQStpRef1NFile {

public:
	TblFmncQStpRef1NFile();
	virtual ~TblFmncQStpRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQStpRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpRef1NFile& rst);

	virtual void insertRec(FmncQStpRef1NFile* rec);
	ubigint insertNewRec(FmncQStpRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQStpRef1NFile& rst, FmncQStpRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQStpRef1NFile& rst);
	virtual void updateRec(FmncQStpRef1NFile* rec);
	virtual void updateRst(ListFmncQStpRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQStpRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQStpRef1NFile: C++ wrapper for table TblFmncQStpRef1NFile (MySQL database)
  */
class MyTblFmncQStpRef1NFile : public TblFmncQStpRef1NFile, public MyTable {

public:
	MyTblFmncQStpRef1NFile();
	~MyTblFmncQStpRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpRef1NFile& rst);

	void insertRec(FmncQStpRef1NFile* rec);
	void insertRst(ListFmncQStpRef1NFile& rst);
	void updateRec(FmncQStpRef1NFile* rec);
	void updateRst(ListFmncQStpRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQStpRef1NFile: C++ wrapper for table TblFmncQStpRef1NFile (PgSQL database)
  */
class PgTblFmncQStpRef1NFile : public TblFmncQStpRef1NFile, public PgTable {

public:
	PgTblFmncQStpRef1NFile();
	~PgTblFmncQStpRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQStpRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQStpRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQStpRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQStpRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpRef1NFile& rst);

	void insertRec(FmncQStpRef1NFile* rec);
	void insertRst(ListFmncQStpRef1NFile& rst);
	void updateRec(FmncQStpRef1NFile* rec);
	void updateRst(ListFmncQStpRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpRef1NFile& rst);
};
// IP pgTbl --- END

#endif

