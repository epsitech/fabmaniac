/**
  * \file FmncRMRunMSample.cpp
  * database access for table TblFmncRMRunMSample (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMRunMSample.h"

/******************************************************************************
 class FmncRMRunMSample
 ******************************************************************************/

FmncRMRunMSample::FmncRMRunMSample(
			const ubigint ref
			, const ubigint refFmncMRun
			, const ubigint refFmncMSample
		) {

	this->ref = ref;
	this->refFmncMRun = refFmncMRun;
	this->refFmncMSample = refFmncMSample;
};

bool FmncRMRunMSample::operator==(
			const FmncRMRunMSample& comp
		) {
	return false;
};

bool FmncRMRunMSample::operator!=(
			const FmncRMRunMSample& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMRunMSample
 ******************************************************************************/

ListFmncRMRunMSample::ListFmncRMRunMSample() {
};

ListFmncRMRunMSample::ListFmncRMRunMSample(
			const ListFmncRMRunMSample& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMRunMSample(*(src.nodes[i]));
};

ListFmncRMRunMSample::~ListFmncRMRunMSample() {
	clear();
};

void ListFmncRMRunMSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMRunMSample::size() const {
	return(nodes.size());
};

void ListFmncRMRunMSample::append(
			FmncRMRunMSample* rec
		) {
	nodes.push_back(rec);
};

FmncRMRunMSample* ListFmncRMRunMSample::operator[](
			const uint ix
		) {
	FmncRMRunMSample* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMRunMSample& ListFmncRMRunMSample::operator=(
			const ListFmncRMRunMSample& src
		) {
	FmncRMRunMSample* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMRunMSample(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMRunMSample::operator==(
			const ListFmncRMRunMSample& comp
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

bool ListFmncRMRunMSample::operator!=(
			const ListFmncRMRunMSample& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMRunMSample
 ******************************************************************************/

TblFmncRMRunMSample::TblFmncRMRunMSample() {
};

TblFmncRMRunMSample::~TblFmncRMRunMSample() {
};

bool TblFmncRMRunMSample::loadRecBySQL(
			const string& sqlstr
			, FmncRMRunMSample** rec
		) {
	return false;
};

ubigint TblFmncRMRunMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMRunMSample& rst
		) {
	return 0;
};

void TblFmncRMRunMSample::insertRec(
			FmncRMRunMSample* rec
		) {
};

ubigint TblFmncRMRunMSample::insertNewRec(
			FmncRMRunMSample** rec
			, const ubigint refFmncMRun
			, const ubigint refFmncMSample
		) {
	ubigint retval = 0;
	FmncRMRunMSample* _rec = NULL;

	_rec = new FmncRMRunMSample(0, refFmncMRun, refFmncMSample);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMRunMSample::appendNewRecToRst(
			ListFmncRMRunMSample& rst
			, FmncRMRunMSample** rec
			, const ubigint refFmncMRun
			, const ubigint refFmncMSample
		) {
	ubigint retval = 0;
	FmncRMRunMSample* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMRun, refFmncMSample);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMRunMSample::insertRst(
			ListFmncRMRunMSample& rst
			, bool transact
		) {
};

void TblFmncRMRunMSample::updateRec(
			FmncRMRunMSample* rec
		) {
};

void TblFmncRMRunMSample::updateRst(
			ListFmncRMRunMSample& rst
			, bool transact
		) {
};

void TblFmncRMRunMSample::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMRunMSample::loadRecByRef(
			ubigint ref
			, FmncRMRunMSample** rec
		) {
	return false;
};

ubigint TblFmncRMRunMSample::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncRMRunMSample::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMRunMSample& rst
		) {
	ubigint numload = 0;
	FmncRMRunMSample* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMRunMSample
 ******************************************************************************/

MyTblFmncRMRunMSample::MyTblFmncRMRunMSample() : TblFmncRMRunMSample(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMRunMSample::~MyTblFmncRMRunMSample() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMRunMSample::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMRunMSample (refFmncMRun, refFmncMSample) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMRunMSample SET refFmncMRun = ?, refFmncMSample = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMRunMSample WHERE ref = ?", false);
};

bool MyTblFmncRMRunMSample::loadRecBySQL(
			const string& sqlstr
			, FmncRMRunMSample** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMRunMSample* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMRunMSample / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMRunMSample();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMRun = atoll((char*) dbrow[1]); else _rec->refFmncMRun = 0;
		if (dbrow[2]) _rec->refFmncMSample = atoll((char*) dbrow[2]); else _rec->refFmncMSample = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMRunMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMRunMSample& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMRunMSample* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMRunMSample / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMRunMSample();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMRun = atoll((char*) dbrow[1]); else rec->refFmncMRun = 0;
			if (dbrow[2]) rec->refFmncMSample = atoll((char*) dbrow[2]); else rec->refFmncMSample = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMRunMSample::insertRec(
			FmncRMRunMSample* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMRun,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMSample,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMRunMSample / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMRunMSample / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMRunMSample::insertRst(
			ListFmncRMRunMSample& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMRunMSample::updateRec(
			FmncRMRunMSample* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMRun,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMSample,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMRunMSample / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMRunMSample / stmtUpdateRec)\n");
};

void MyTblFmncRMRunMSample::updateRst(
			ListFmncRMRunMSample& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMRunMSample::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMRunMSample / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMRunMSample / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMRunMSample::loadRecByRef(
			ubigint ref
			, FmncRMRunMSample** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMRunMSample WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMRunMSample::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncRMRunMSample WHERE refFmncMRun = " + to_string(refFmncMRun) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMRunMSample
 ******************************************************************************/

PgTblFmncRMRunMSample::PgTblFmncRMRunMSample() : TblFmncRMRunMSample(), PgTable() {
};

PgTblFmncRMRunMSample::~PgTblFmncRMRunMSample() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMRunMSample::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMRunMSample_insertRec", "INSERT INTO TblFmncRMRunMSample (refFmncMRun, refFmncMSample) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMRunMSample_updateRec", "UPDATE TblFmncRMRunMSample SET refFmncMRun = $1, refFmncMSample = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMRunMSample_removeRecByRef", "DELETE FROM TblFmncRMRunMSample WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMRunMSample_loadRecByRef", "SELECT ref, refFmncMRun, refFmncMSample FROM TblFmncRMRunMSample WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMRunMSample_loadRefsByRun", "SELECT ref FROM TblFmncRMRunMSample WHERE refFmncMRun = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMRunMSample::loadRec(
			PGresult* res
			, FmncRMRunMSample** rec
		) {
	char* ptr;

	FmncRMRunMSample* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMRunMSample();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmrun"),
			PQfnumber(res, "reffmncmsample")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMRun = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMSample = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMRunMSample::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMRunMSample& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMRunMSample* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmrun"),
			PQfnumber(res, "reffmncmsample")
		};

		while (numread < numrow) {
			rec = new FmncRMRunMSample();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMRun = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMSample = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMRunMSample::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMRunMSample** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMRunMSample / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMRunMSample::loadRecBySQL(
			const string& sqlstr
			, FmncRMRunMSample** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMRunMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMRunMSample& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMRunMSample::insertRec(
			FmncRMRunMSample* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMRun = htonl64(rec->refFmncMRun);
	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);

	const char* vals[] = {
		(char*) &_refFmncMRun,
		(char*) &_refFmncMSample
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMRunMSample_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMRunMSample_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMRunMSample::insertRst(
			ListFmncRMRunMSample& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMRunMSample::updateRec(
			FmncRMRunMSample* rec
		) {
	PGresult* res;

	ubigint _refFmncMRun = htonl64(rec->refFmncMRun);
	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMRun,
		(char*) &_refFmncMSample,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMRunMSample_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMRunMSample_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMRunMSample::updateRst(
			ListFmncRMRunMSample& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMRunMSample::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMRunMSample_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMRunMSample_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMRunMSample::loadRecByRef(
			ubigint ref
			, FmncRMRunMSample** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMRunMSample_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMRunMSample::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMRun = htonl64(refFmncMRun);

	const char* vals[] = {
		(char*) &_refFmncMRun
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncRMRunMSample_loadRefsByRun", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

