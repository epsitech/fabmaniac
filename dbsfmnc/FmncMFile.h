/**
  * \file FmncMFile.h
  * database access for table TblFmncMFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCMFILE_H
#define FMNCMFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * FmncMFile: record of TblFmncMFile
  */
class FmncMFile {

public:
	FmncMFile(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refFmncCFile;
	uint refIxVTbl;
	ubigint refUref;
	string osrefKContent;
	uint Archived;
	string Filename;
	string Archivename;
	string srefKMimetype;
	usmallint Size;
	string Comment;

public:
	bool operator==(const FmncMFile& comp);
	bool operator!=(const FmncMFile& comp);
};

/**
  * ListFmncMFile: recordset of TblFmncMFile
  */
class ListFmncMFile {

public:
	ListFmncMFile();
	ListFmncMFile(const ListFmncMFile& src);
	~ListFmncMFile();

	void clear();
	unsigned int size() const;
	void append(FmncMFile* rec);

	FmncMFile* operator[](const uint ix);
	ListFmncMFile& operator=(const ListFmncMFile& src);
	bool operator==(const ListFmncMFile& comp);
	bool operator!=(const ListFmncMFile& comp);

public:
	vector<FmncMFile*> nodes;
};

/**
  * TblFmncMFile: C++ wrapper for table TblFmncMFile
  */
class TblFmncMFile {

public:
	TblFmncMFile();
	virtual ~TblFmncMFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, FmncMFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFile& rst);

	virtual void insertRec(FmncMFile* rec);
	ubigint insertNewRec(FmncMFile** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListFmncMFile& rst, FmncMFile** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refFmncCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");
	virtual void insertRst(ListFmncMFile& rst, bool transact = false);
	virtual void updateRec(FmncMFile* rec);
	virtual void updateRst(ListFmncMFile& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, FmncMFile** rec);
	virtual bool loadFnmByRef(ubigint ref, string& val);
	virtual ubigint loadRefsByClu(ubigint refFmncCFile, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRefsByRetReu(uint refIxVTbl, ubigint refUref, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByClu(ubigint refFmncCFile, const bool append, ListFmncMFile& rst);
	virtual ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListFmncMFile& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListFmncMFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyFmncMFile: C++ wrapper for table TblFmncMFile (MySQL database)
  */
class MyTblFmncMFile : public TblFmncMFile, public MyTable {

public:
	MyTblFmncMFile();
	~MyTblFmncMFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, FmncMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFile& rst);

	void insertRec(FmncMFile* rec);
	void insertRst(ListFmncMFile& rst, bool transact = false);
	void updateRec(FmncMFile* rec);
	void updateRst(ListFmncMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMFile** rec);
	bool loadFnmByRef(ubigint ref, string& val);
	ubigint loadRefsByClu(ubigint refFmncCFile, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByRetReu(uint refIxVTbl, ubigint refUref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByClu(ubigint refFmncCFile, const bool append, ListFmncMFile& rst);
	ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListFmncMFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgFmncMFile: C++ wrapper for table TblFmncMFile (PgSQL database)
  */
class PgTblFmncMFile : public TblFmncMFile, public PgTable {

public:
	PgTblFmncMFile();
	~PgTblFmncMFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, FmncMFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListFmncMFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, FmncMFile** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListFmncMFile& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, FmncMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListFmncMFile& rst);

	void insertRec(FmncMFile* rec);
	void insertRst(ListFmncMFile& rst, bool transact = false);
	void updateRec(FmncMFile* rec);
	void updateRst(ListFmncMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, FmncMFile** rec);
	bool loadFnmByRef(ubigint ref, string& val);
	ubigint loadRefsByClu(ubigint refFmncCFile, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByRetReu(uint refIxVTbl, ubigint refUref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByClu(ubigint refFmncCFile, const bool append, ListFmncMFile& rst);
	ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListFmncMFile& rst);
};
// IP pgTbl --- END

#endif

