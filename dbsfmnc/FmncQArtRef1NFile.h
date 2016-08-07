/**
  * \file FmncQArtRef1NFile.h
  * Dbs and XML wrapper for table TblFmncQArtRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQARTREF1NFILE_H
#define FMNCQARTREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQArtRef1NFile: record of TblFmncQArtRef1NFile
  */
class FmncQArtRef1NFile {

public:
	FmncQArtRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListFmncQArtRef1NFile: recordset of TblFmncQArtRef1NFile
  */
class ListFmncQArtRef1NFile {

public:
	ListFmncQArtRef1NFile();
	ListFmncQArtRef1NFile(const ListFmncQArtRef1NFile& src);
	~ListFmncQArtRef1NFile();

	void clear();
	unsigned int size() const;
	void append(FmncQArtRef1NFile* rec);

	ListFmncQArtRef1NFile& operator=(const ListFmncQArtRef1NFile& src);

public:
	vector<FmncQArtRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQArtRef1NFile: C++ wrapper for table TblFmncQArtRef1NFile
  */
class TblFmncQArtRef1NFile {

public:
	TblFmncQArtRef1NFile();
	virtual ~TblFmncQArtRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQArtRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtRef1NFile& rst);

	virtual void insertRec(FmncQArtRef1NFile* rec);
	ubigint insertNewRec(FmncQArtRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListFmncQArtRef1NFile& rst, FmncQArtRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListFmncQArtRef1NFile& rst);
	virtual void updateRec(FmncQArtRef1NFile* rec);
	virtual void updateRst(ListFmncQArtRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQArtRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQArtRef1NFile: C++ wrapper for table TblFmncQArtRef1NFile (MySQL database)
  */
class MyTblFmncQArtRef1NFile : public TblFmncQArtRef1NFile, public MyTable {

public:
	MyTblFmncQArtRef1NFile();
	~MyTblFmncQArtRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArtRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtRef1NFile& rst);

	void insertRec(FmncQArtRef1NFile* rec);
	void insertRst(ListFmncQArtRef1NFile& rst);
	void updateRec(FmncQArtRef1NFile* rec);
	void updateRst(ListFmncQArtRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArtRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQArtRef1NFile: C++ wrapper for table TblFmncQArtRef1NFile (PgSQL database)
  */
class PgTblFmncQArtRef1NFile : public TblFmncQArtRef1NFile, public PgTable {

public:
	PgTblFmncQArtRef1NFile();
	~PgTblFmncQArtRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQArtRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQArtRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQArtRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQArtRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQArtRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQArtRef1NFile& rst);

	void insertRec(FmncQArtRef1NFile* rec);
	void insertRst(ListFmncQArtRef1NFile& rst);
	void updateRec(FmncQArtRef1NFile* rec);
	void updateRst(ListFmncQArtRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQArtRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQArtRef1NFile& rst);
};
// IP pgTbl --- END

#endif

