/**
  * \file FmncJMSampleState.cpp
  * database access for table TblFmncJMSampleState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMSampleState.h"

/******************************************************************************
 class FmncJMSampleState
 ******************************************************************************/

FmncJMSampleState::FmncJMSampleState(
			const ubigint ref
			, const ubigint refFmncMSample
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refFmncMSample = refFmncMSample;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool FmncJMSampleState::operator==(
			const FmncJMSampleState& comp
		) {
	return false;
};

bool FmncJMSampleState::operator!=(
			const FmncJMSampleState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMSampleState
 ******************************************************************************/

ListFmncJMSampleState::ListFmncJMSampleState() {
};

ListFmncJMSampleState::ListFmncJMSampleState(
			const ListFmncJMSampleState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMSampleState(*(src.nodes[i]));
};

ListFmncJMSampleState::~ListFmncJMSampleState() {
	clear();
};

void ListFmncJMSampleState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMSampleState::size() const {
	return(nodes.size());
};

void ListFmncJMSampleState::append(
			FmncJMSampleState* rec
		) {
	nodes.push_back(rec);
};

FmncJMSampleState* ListFmncJMSampleState::operator[](
			const uint ix
		) {
	FmncJMSampleState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMSampleState& ListFmncJMSampleState::operator=(
			const ListFmncJMSampleState& src
		) {
	FmncJMSampleState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMSampleState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMSampleState::operator==(
			const ListFmncJMSampleState& comp
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

bool ListFmncJMSampleState::operator!=(
			const ListFmncJMSampleState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMSampleState
 ******************************************************************************/

TblFmncJMSampleState::TblFmncJMSampleState() {
};

TblFmncJMSampleState::~TblFmncJMSampleState() {
};

bool TblFmncJMSampleState::loadRecBySQL(
			const string& sqlstr
			, FmncJMSampleState** rec
		) {
	return false;
};

ubigint TblFmncJMSampleState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	return 0;
};

void TblFmncJMSampleState::insertRec(
			FmncJMSampleState* rec
		) {
};

ubigint TblFmncJMSampleState::insertNewRec(
			FmncJMSampleState** rec
			, const ubigint refFmncMSample
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMSampleState* _rec = NULL;

	_rec = new FmncJMSampleState(0, refFmncMSample, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMSampleState::appendNewRecToRst(
			ListFmncJMSampleState& rst
			, FmncJMSampleState** rec
			, const ubigint refFmncMSample
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMSampleState* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMSample, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMSampleState::insertRst(
			ListFmncJMSampleState& rst
			, bool transact
		) {
};

void TblFmncJMSampleState::updateRec(
			FmncJMSampleState* rec
		) {
};

void TblFmncJMSampleState::updateRst(
			ListFmncJMSampleState& rst
			, bool transact
		) {
};

void TblFmncJMSampleState::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMSampleState::loadRecByRef(
			ubigint ref
			, FmncJMSampleState** rec
		) {
	return false;
};

bool TblFmncJMSampleState::loadRecBySmpSta(
			ubigint refFmncMSample
			, uint x1Start
			, FmncJMSampleState** rec
		) {
	return false;
};

ubigint TblFmncJMSampleState::loadRefsBySmp(
			ubigint refFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncJMSampleState::loadRstBySmp(
			ubigint refFmncMSample
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	return 0;
};

ubigint TblFmncJMSampleState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	ubigint numload = 0;
	FmncJMSampleState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMSampleState
 ******************************************************************************/

MyTblFmncJMSampleState::MyTblFmncJMSampleState() : TblFmncJMSampleState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMSampleState::~MyTblFmncJMSampleState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMSampleState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMSampleState (refFmncMSample, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMSampleState SET refFmncMSample = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMSampleState WHERE ref = ?", false);
};

bool MyTblFmncJMSampleState::loadRecBySQL(
			const string& sqlstr
			, FmncJMSampleState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMSampleState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMSampleState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMSampleState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMSample = atoll((char*) dbrow[1]); else _rec->refFmncMSample = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMSampleState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMSampleState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMSampleState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMSampleState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMSample = atoll((char*) dbrow[1]); else rec->refFmncMSample = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMSampleState::insertRec(
			FmncJMSampleState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMSample,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMSampleState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMSampleState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMSampleState::insertRst(
			ListFmncJMSampleState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMSampleState::updateRec(
			FmncJMSampleState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMSample,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMSampleState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMSampleState / stmtUpdateRec)\n");
};

void MyTblFmncJMSampleState::updateRst(
			ListFmncJMSampleState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMSampleState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMSampleState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMSampleState / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMSampleState::loadRecByRef(
			ubigint ref
			, FmncJMSampleState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMSampleState WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMSampleState::loadRecBySmpSta(
			ubigint refFmncMSample
			, uint x1Start
			, FmncJMSampleState** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMSample, x1Start, ixVState FROM TblFmncJMSampleState WHERE refFmncMSample = " + to_string(refFmncMSample) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMSampleState::loadRefsBySmp(
			ubigint refFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncJMSampleState WHERE refFmncMSample = " + to_string(refFmncMSample) + "", append, refs);
};

ubigint MyTblFmncJMSampleState::loadRstBySmp(
			ubigint refFmncMSample
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMSample, x1Start, ixVState FROM TblFmncJMSampleState WHERE refFmncMSample = " + to_string(refFmncMSample) + " ORDER BY x1Start ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMSampleState
 ******************************************************************************/

PgTblFmncJMSampleState::PgTblFmncJMSampleState() : TblFmncJMSampleState(), PgTable() {
};

PgTblFmncJMSampleState::~PgTblFmncJMSampleState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMSampleState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMSampleState_insertRec", "INSERT INTO TblFmncJMSampleState (refFmncMSample, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMSampleState_updateRec", "UPDATE TblFmncJMSampleState SET refFmncMSample = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMSampleState_removeRecByRef", "DELETE FROM TblFmncJMSampleState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMSampleState_loadRecByRef", "SELECT ref, refFmncMSample, x1Start, ixVState FROM TblFmncJMSampleState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMSampleState_loadRecBySmpSta", "SELECT ref, refFmncMSample, x1Start, ixVState FROM TblFmncJMSampleState WHERE refFmncMSample = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMSampleState_loadRefsBySmp", "SELECT ref FROM TblFmncJMSampleState WHERE refFmncMSample = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMSampleState_loadRstBySmp", "SELECT ref, refFmncMSample, x1Start, ixVState FROM TblFmncJMSampleState WHERE refFmncMSample = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMSampleState::loadRec(
			PGresult* res
			, FmncJMSampleState** rec
		) {
	char* ptr;

	FmncJMSampleState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMSampleState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmsample"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMSample = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMSampleState::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMSampleState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmsample"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncJMSampleState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMSample = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMSampleState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMSampleState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMSampleState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMSampleState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMSampleState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMSampleState::loadRecBySQL(
			const string& sqlstr
			, FmncJMSampleState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMSampleState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMSampleState::insertRec(
			FmncJMSampleState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncJMSampleState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMSampleState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMSampleState::insertRst(
			ListFmncJMSampleState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMSampleState::updateRec(
			FmncJMSampleState* rec
		) {
	PGresult* res;

	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		(char*) &_x1Start,
		(char*) &_ixVState,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncJMSampleState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMSampleState_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMSampleState::updateRst(
			ListFmncJMSampleState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMSampleState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMSampleState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMSampleState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMSampleState::loadRecByRef(
			ubigint ref
			, FmncJMSampleState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMSampleState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMSampleState::loadRecBySmpSta(
			ubigint refFmncMSample
			, uint x1Start
			, FmncJMSampleState** rec
		) {
	ubigint _refFmncMSample = htonl64(refFmncMSample);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMSampleState_loadRecBySmpSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMSampleState::loadRefsBySmp(
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

	return loadRefsByStmt("TblFmncJMSampleState_loadRefsBySmp", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncJMSampleState::loadRstBySmp(
			ubigint refFmncMSample
			, const bool append
			, ListFmncJMSampleState& rst
		) {
	ubigint _refFmncMSample = htonl64(refFmncMSample);

	const char* vals[] = {
		(char*) &_refFmncMSample
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMSampleState_loadRstBySmp", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

