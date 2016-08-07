/**
  * \file FmncQStpMNFile.h
  * Dbs and XML wrapper for table TblFmncQStpMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCQSTPMNFILE_H
#define FMNCQSTPMNFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * FmncQStpMNFile: record of TblFmncQStpMNFile
  */
class FmncQStpMNFile {

public:
	FmncQStpMNFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");

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
  * ListFmncQStpMNFile: recordset of TblFmncQStpMNFile
  */
class ListFmncQStpMNFile {

public:
	ListFmncQStpMNFile();
	ListFmncQStpMNFile(const ListFmncQStpMNFile& src);
	~ListFmncQStpMNFile();

	void clear();
	unsigned int size() const;
	void append(FmncQStpMNFile* rec);

	ListFmncQStpMNFile& operator=(const ListFmncQStpMNFile& src);

public:
	vector<FmncQStpMNFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblFmncQStpMNFile: C++ wrapper for table TblFmncQStpMNFile
  */
class TblFmncQStpMNFile {

public:
	TblFmncQStpMNFile();
	virtual ~TblFmncQStpMNFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncQStpMNFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpMNFile& rst);

	virtual void insertRec(FmncQStpMNFile* rec);
	ubigint insertNewRec(FmncQStpMNFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");
	ubigint appendNewRecToRst(ListFmncQStpMNFile& rst, FmncQStpMNFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const string stubsTrefFmncMSample = "", const ubigint ref = 0, const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "");
	virtual void insertRst(ListFmncQStpMNFile& rst);
	virtual void updateRec(FmncQStpMNFile* rec);
	virtual void updateRst(ListFmncQStpMNFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, FmncQStpMNFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpMNFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncQStpMNFile: C++ wrapper for table TblFmncQStpMNFile (MySQL database)
  */
class MyTblFmncQStpMNFile : public TblFmncQStpMNFile, public MyTable {

public:
	MyTblFmncQStpMNFile();
	~MyTblFmncQStpMNFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpMNFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpMNFile& rst);

	void insertRec(FmncQStpMNFile* rec);
	void insertRst(ListFmncQStpMNFile& rst);
	void updateRec(FmncQStpMNFile* rec);
	void updateRst(ListFmncQStpMNFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpMNFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpMNFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncQStpMNFile: C++ wrapper for table TblFmncQStpMNFile (PgSQL database)
  */
class PgTblFmncQStpMNFile : public TblFmncQStpMNFile, public PgTable {

public:
	PgTblFmncQStpMNFile();
	~PgTblFmncQStpMNFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncQStpMNFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncQStpMNFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncQStpMNFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncQStpMNFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, FmncQStpMNFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncQStpMNFile& rst);

	void insertRec(FmncQStpMNFile* rec);
	void insertRst(ListFmncQStpMNFile& rst);
	void updateRec(FmncQStpMNFile* rec);
	void updateRst(ListFmncQStpMNFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, FmncQStpMNFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListFmncQStpMNFile& rst);
};
// IP pgTbl --- END

#endif

