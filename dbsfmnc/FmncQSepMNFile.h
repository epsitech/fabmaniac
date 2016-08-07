/**
  * \file FmncQSepMNFile.h
  * Dbs and XML wrapper for table TblFmncQSepMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSEPMNFILE_H
#define FMNCQSEPMNFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQSepMNFile: record of TblFmncQSepMNFile
  */
class FmncQSepMNFile {

public:
	FmncQSepMNFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	string stubsTrefFmncMSample;
	ubigint ref;
	uint ixVDir;
	string srefIxVDir;
	string titIxVDir;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListFmncQSepMNFile: recordset of TblFmncQSepMNFile
  */
class ListFmncQSepMNFile {

public:
	ListFmncQSepMNFile();
	ListFmncQSepMNFile(const ListFmncQSepMNFile& src);
	~ListFmncQSepMNFile();

	void clear();
	unsigned int size() const;
	void append(FmncQSepMNFile* rec);

	ListFmncQSepMNFile& operator=(const ListFmncQSepMNFile& src);

public:
	vector<FmncQSepMNFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQSepMNFile: C++ wrapper for table TblFmncQSepMNFile
  */
class TblFmncQSepMNFile {

public:
	TblFmncQSepMNFile();
	virtual ~TblFmncQSepMNFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQSepMNFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepMNFile& rst);

	virtual void insertRec(FmncQSepMNFile* rec);
	ubigint insertNewRec(FmncQSepMNFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");
	ubigint appendNewRecToRst(ListFmncQSepMNFile& rst, FmncQSepMNFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");
	virtual void insertRst(ListFmncQSepMNFile& rst);
	virtual void updateRec(FmncQSepMNFile* rec);
	virtual void updateRst(ListFmncQSepMNFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQSepMNFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepMNFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQSepMNFile: C++ wrapper for table TblFmncQSepMNFile (MySQL database)
  */
class MyTblFmncQSepMNFile : public TblFmncQSepMNFile, public MyTable {

public:
	MyTblFmncQSepMNFile();
	~MyTblFmncQSepMNFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepMNFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepMNFile& rst);

	void insertRec(FmncQSepMNFile* rec);
	void insertRst(ListFmncQSepMNFile& rst);
	void updateRec(FmncQSepMNFile* rec);
	void updateRst(ListFmncQSepMNFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepMNFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepMNFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQSepMNFile: C++ wrapper for table TblFmncQSepMNFile (PgSQL database)
  */
class PgTblFmncQSepMNFile : public TblFmncQSepMNFile, public PgTable {

public:
	PgTblFmncQSepMNFile();
	~PgTblFmncQSepMNFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQSepMNFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQSepMNFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQSepMNFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQSepMNFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQSepMNFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQSepMNFile& rst);

	void insertRec(FmncQSepMNFile* rec);
	void insertRst(ListFmncQSepMNFile& rst);
	void updateRec(FmncQSepMNFile* rec);
	void updateRst(ListFmncQSepMNFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQSepMNFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQSepMNFile& rst);
};
// IP pgTbl --- END

#endif

