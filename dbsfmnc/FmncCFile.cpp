/**
  * \file FmncCFile.cpp
  * Dbs and XML wrapper for table TblFmncCFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncCFile.h"

/******************************************************************************
 class TblFmncCFile
 ******************************************************************************/

TblFmncCFile::TblFmncCFile() {
};

TblFmncCFile::~TblFmncCFile() {
};

ubigint TblFmncCFile::getNewRef() {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncCFile
 ******************************************************************************/

MyTblFmncCFile::MyTblFmncCFile() : TblFmncCFile(), MyTable() {
	stmtGetNewRef = NULL;
};

MyTblFmncCFile::~MyTblFmncCFile() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblFmncCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblFmncCFile () VALUES ()", false);
};

ubigint MyTblFmncCFile::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncCFile / stmtGetNewRef)\n");
	if (mysql_stmt_execute(stmtGetNewRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncCFile / stmtGetNewRef)\n");
	return mysql_stmt_insert_id(stmtGetNewRef);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncCFile
 ******************************************************************************/

PgTblFmncCFile::PgTblFmncCFile() : TblFmncCFile(), PgTable() {
};

PgTblFmncCFile::~PgTblFmncCFile() {
};

void PgTblFmncCFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncCFile_getNewRef", "SELECT nextval('TblFmncCFile')", 0, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

ubigint PgTblFmncCFile::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblFmncCFile_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncCFile_getNewRef)\n");

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
// IP pgTbl --- END

