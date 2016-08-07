/**
  * \file FmncRMFileMSample.cpp
  * database access for table TblFmncRMFileMSample (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMFileMSample.h"

/******************************************************************************
 class FmncRMFileMSample
 ******************************************************************************/

FmncRMFileMSample::FmncRMFileMSample(
			const ubigint ref
			, const ubigint refFmncMFile
			, const ubigint refFmncMSample
		) {

	this->ref = ref;
	this->refFmncMFile = refFmncMFile;
	this->refFmncMSample = refFmncMSample;
};

bool FmncRMFileMSample::operator==(
			const FmncRMFileMSample& comp
		) {
	return false;
};

bool FmncRMFileMSample::operator!=(
			const FmncRMFileMSample& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMFileMSample
 ******************************************************************************/

ListFmncRMFileMSample::ListFmncRMFileMSample() {
};

ListFmncRMFileMSample::ListFmncRMFileMSample(
			const ListFmncRMFileMSample& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMFileMSample(*(src.nodes[i]));
};

ListFmncRMFileMSample::~ListFmncRMFileMSample() {
	clear();
};

void ListFmncRMFileMSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMFileMSample::size() const {
	return(nodes.size());
};

void ListFmncRMFileMSample::append(
			FmncRMFileMSample* rec
		) {
	nodes.push_back(rec);
};

FmncRMFileMSample* ListFmncRMFileMSample::operator[](
			const uint ix
		) {
	FmncRMFileMSample* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMFileMSample& ListFmncRMFileMSample::operator=(
			const ListFmncRMFileMSample& src
		) {
	FmncRMFileMSample* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMFileMSample(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMFileMSample::operator==(
			const ListFmncRMFileMSample& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListFmncRMFileMSample::operator!=(
			const ListFmncRMFileMSample& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMFileMSample
 ******************************************************************************/

TblFmncRMFileMSample::TblFmncRMFileMSample() {
};

TblFmncRMFileMSample::~TblFmncRMFileMSample() {
};

bool TblFmncRMFileMSample::loadRecBySQL(
			const string& sqlstr
			, FmncRMFileMSample** rec
		) {
	return false;
};

ubigint TblFmncRMFileMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFileMSample& rst
		) {
	return 0;
};

void TblFmncRMFileMSample::insertRec(
			FmncRMFileMSample* rec
		) {
};

ubigint TblFmncRMFileMSample::insertNewRec(
			FmncRMFileMSample** rec
			, const ubigint refFmncMFile
			, const ubigint refFmncMSample
		) {
	ubigint retval = 0;
	FmncRMFileMSample* _rec = NULL;

	_rec = new FmncRMFileMSample(0, refFmncMFile, refFmncMSample);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMFileMSample::appendNewRecToRst(
			ListFmncRMFileMSample& rst
			, FmncRMFileMSample** rec
			, const ubigint refFmncMFile
			, const ubigint refFmncMSample
		) {
	ubigint retval = 0;
	FmncRMFileMSample* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMFile, refFmncMSample);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMFileMSample::insertRst(
			ListFmncRMFileMSample& rst
			, bool transact
		) {
};

void TblFmncRMFileMSample::updateRec(
			FmncRMFileMSample* rec
		) {
};

void TblFmncRMFileMSample::updateRst(
			ListFmncRMFileMSample& rst
			, bool transact
		) {
};

void TblFmncRMFileMSample::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMFileMSample::loadRecByRef(
			ubigint ref
			, FmncRMFileMSample** rec
		) {
	return false;
};

ubigint TblFmncRMFileMSample::loadRefsBySmp(
			ubigint refFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncRMFileMSample::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMFileMSample& rst
		) {
	ubigint numload = 0;
	FmncRMFileMSample* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMFileMSample
 ******************************************************************************/

MyTblFmncRMFileMSample::MyTblFmncRMFileMSample() : TblFmncRMFileMSample(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMFileMSample::~MyTblFmncRMFileMSample() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMFileMSample::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMFileMSample (refFmncMFile, refFmncMSample) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMFileMSample SET refFmncMFile = ?, refFmncMSample = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMFileMSample WHERE ref = ?", false);
};

bool MyTblFmncRMFileMSample::loadRecBySQL(
			const string& sqlstr
			, FmncRMFileMSample** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMFileMSample* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFileMSample / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMFileMSample();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMFile = atoll((char*) dbrow[1]); else _rec->refFmncMFile = 0;
		if (dbrow[2]) _rec->refFmncMSample = atoll((char*) dbrow[2]); else _rec->refFmncMSample = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMFileMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFileMSample& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMFileMSample* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFileMSample / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMFileMSample();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMFile = atoll((char*) dbrow[1]); else rec->refFmncMFile = 0;
			if (dbrow[2]) rec->refFmncMSample = atoll((char*) dbrow[2]); else rec->refFmncMSample = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMFileMSample::insertRec(
			FmncRMFileMSample* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFile,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMSample,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFileMSample / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFileMSample / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMFileMSample::insertRst(
			ListFmncRMFileMSample& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMFileMSample::updateRec(
			FmncRMFileMSample* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFile,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMSample,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFileMSample / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFileMSample / stmtUpdateRec)\n");
};

void MyTblFmncRMFileMSample::updateRst(
			ListFmncRMFileMSample& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMFileMSample::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFileMSample / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFileMSample / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMFileMSample::loadRecByRef(
			ubigint ref
			, FmncRMFileMSample** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMFileMSample WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMFileMSample::loadRefsBySmp(
			ubigint refFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncRMFileMSample WHERE refFmncMSample = " + to_string(refFmncMSample) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMFileMSample
 ******************************************************************************/

PgTblFmncRMFileMSample::PgTblFmncRMFileMSample() : TblFmncRMFileMSample(), PgTable() {
};

PgTblFmncRMFileMSample::~PgTblFmncRMFileMSample() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMFileMSample::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMFileMSample_insertRec", "INSERT INTO TblFmncRMFileMSample (refFmncMFile, refFmncMSample) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFileMSample_updateRec", "UPDATE TblFmncRMFileMSample SET refFmncMFile = $1, refFmncMSample = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFileMSample_removeRecByRef", "DELETE FROM TblFmncRMFileMSample WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMFileMSample_loadRecByRef", "SELECT ref, refFmncMFile, refFmncMSample FROM TblFmncRMFileMSample WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMFileMSample_loadRefsBySmp", "SELECT ref FROM TblFmncRMFileMSample WHERE refFmncMSample = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMFileMSample::loadRec(
			PGresult* res
			, FmncRMFileMSample** rec
		) {
	char* ptr;

	FmncRMFileMSample* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMFileMSample();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "reffmncmsample")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMSample = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMFileMSample::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMFileMSample& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMFileMSample* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "reffmncmsample")
		};

		while (numread < numrow) {
			rec = new FmncRMFileMSample();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMSample = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMFileMSample::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMFileMSample** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFileMSample / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMFileMSample::loadRecBySQL(
			const string& sqlstr
			, FmncRMFileMSample** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMFileMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFileMSample& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMFileMSample::insertRec(
			FmncRMFileMSample* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);

	const char* vals[] = {
		(char*) &_refFmncMFile,
		(char*) &_refFmncMSample
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFileMSample_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFileMSample_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMFileMSample::insertRst(
			ListFmncRMFileMSample& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMFileMSample::updateRec(
			FmncRMFileMSample* rec
		) {
	PGresult* res;

	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMFile,
		(char*) &_refFmncMSample,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFileMSample_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFileMSample_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMFileMSample::updateRst(
			ListFmncRMFileMSample& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMFileMSample::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblFmncRMFileMSample_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFileMSample_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMFileMSample::loadRecByRef(
			ubigint ref
			, FmncRMFileMSample** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMFileMSample_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMFileMSample::loadRefsBySmp(
			ubigint refFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMSample = htonl64(refFmncMSample);

	const char* vals[] = {
		(char*) &_refFmncMSample
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncRMFileMSample_loadRefsBySmp", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

