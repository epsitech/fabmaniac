/**
  * \file FmncCFile.h
  * Dbs and XML wrapper for table TblFmncCFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCCFILE_H
#define FMNCCFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * TblFmncCFile: C++ wrapper for table TblFmncCFile
  */
class TblFmncCFile {

public:
	TblFmncCFile();
	virtual ~TblFmncCFile();

public:
	virtual ubigint getNewRef();
};

// IP myTbl --- BEGIN
/**
  * MyTblFmncCFile: C++ wrapper for table TblFmncCFile (MySQL database)
  */
class MyTblFmncCFile : public TblFmncCFile, public MyTable {

public:
	MyTblFmncCFile();
	~MyTblFmncCFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	ubigint getNewRef();
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgTblFmncCFile: C++ wrapper for table TblFmncCFile (PgSQL database)
  */
class PgTblFmncCFile : public TblFmncCFile, public PgTable {

public:
	PgTblFmncCFile();
	~PgTblFmncCFile();

public:
	void initStatements();

public:
	ubigint getNewRef();
};
// IP pgTbl --- END

#endif

