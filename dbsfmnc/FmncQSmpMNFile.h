/**
  * \file FmncQSmpMNFile.h
  * Dbs and XML wrapper for table TblFmncQSmpMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSMPMNFILE_H
#define FMNCQSMPMNFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSmpMNFile: record of TblFmncQSmpMNFile
  */
class FmncQSmpMNFile {

public:
	FmncQSmpMNFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListFmncQSmpMNFile: recordset of TblFmncQSmpMNFile
  */
class ListFmncQSmpMNFile {

public:
	ListFmncQSmpMNFile();
	ListFmncQSmpMNFile(const ListFmncQSmpMNFile& src);
	~ListFmncQSmpMNFile();

	void clear();
	unsigned int size() const;
	void append(FmncQSmpMNFile* rec);

	ListFmncQSmpMNFile& operator=(const ListFmncQSmpMNFile& src);

public:
	vector<FmncQSmpMNFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSmpMNFile: C++ wrapper for table TblFmncQSmpMNFile
  */
class TblFmncQSmpMNFile {

public:
	TblFmncQSmpMNFile();
	virtual ~TblFmncQSmpMNFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSmpMNFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNFile& rst);

	virtual void insertRec(FmncQSmpMNFile* rec);
	ubigint insertNewRec(FmncQSmpMNFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListFmncQSmpMNFile& rst, FmncQSmpMNFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListFmncQSmpMNFile& rst);
	virtual void updateRec(FmncQSmpMNFile* rec);
	virtual void updateRst(ListFmncQSmpMNFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSmpMNFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSmpMNFile: C++ wrapper for table TblFmncQSmpMNFile (MySQL database)
  */
class MyTblFmncQSmpMNFile : public TblFmncQSmpMNFile, public MyTable {

public:
	MyTblFmncQSmpMNFile();
	~MyTblFmncQSmpMNFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpMNFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNFile& rst);

	void insertRec(FmncQSmpMNFile* rec);
	void insertRst(ListFmncQSmpMNFile& rst);
	void updateRec(FmncQSmpMNFile* rec);
	void updateRst(ListFmncQSmpMNFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpMNFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSmpMNFile: C++ wrapper for table TblFmncQSmpMNFile (PgSQL database)
  */
class PgTblFmncQSmpMNFile : public TblFmncQSmpMNFile, public PgTable {

public:
	PgTblFmncQSmpMNFile();
	~PgTblFmncQSmpMNFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSmpMNFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSmpMNFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSmpMNFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSmpMNFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSmpMNFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSmpMNFile& rst);

	void insertRec(FmncQSmpMNFile* rec);
	void insertRst(ListFmncQSmpMNFile& rst);
	void updateRec(FmncQSmpMNFile* rec);
	void updateRst(ListFmncQSmpMNFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSmpMNFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSmpMNFile& rst);
};
// IP pgTbl --- END

#endif

