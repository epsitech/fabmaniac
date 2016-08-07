/**
  * \file FmncJMRunState.cpp
  * database access for table TblFmncJMRunState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMRunState.h"

/******************************************************************************
 class FmncJMRunState
 ******************************************************************************/

FmncJMRunState::FmncJMRunState(
			const ubigint ref
			, const ubigint refFmncMRun
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refFmncMRun = refFmncMRun;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool FmncJMRunState::operator==(
			const FmncJMRunState& comp
		) {
	return false;
};

bool FmncJMRunState::operator!=(
			const FmncJMRunState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMRunState
 ******************************************************************************/

ListFmncJMRunState::ListFmncJMRunState() {
};

ListFmncJMRunState::ListFmncJMRunState(
			const ListFmncJMRunState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMRunState(*(src.nodes[i]));
};

ListFmncJMRunState::~ListFmncJMRunState() {
	clear();
};

void ListFmncJMRunState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMRunState::size() const {
	return(nodes.size());
};

void ListFmncJMRunState::append(
			FmncJMRunState* rec
		) {
	nodes.push_back(rec);
};

FmncJMRunState* ListFmncJMRunState::operator[](
			const uint ix
		) {
	FmncJMRunState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMRunState& ListFmncJMRunState::operator=(
			const ListFmncJMRunState& src
		) {
	FmncJMRunState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMRunState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMRunState::operator==(
			const ListFmncJMRunState& comp
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

bool ListFmncJMRunState::operator!=(
			const ListFmncJMRunState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMRunState
 ******************************************************************************/

TblFmncJMRunState::TblFmncJMRunState() {
};

TblFmncJMRunState::~TblFmncJMRunState() {
};

bool TblFmncJMRunState::loadRecBySQL(
			const string& sqlstr
			, FmncJMRunState** rec
		) {
	return false;
};

ubigint TblFmncJMRunState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMRunState& rst
		) {
	return 0;
};

void TblFmncJMRunState::insertRec(
			FmncJMRunState* rec
		) {
};

ubigint TblFmncJMRunState::insertNewRec(
			FmncJMRunState** rec
			, const ubigint refFmncMRun
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMRunState* _rec = NULL;

	_rec = new FmncJMRunState(0, refFmncMRun, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMRunState::appendNewRecToRst(
			ListFmncJMRunState& rst
			, FmncJMRunState** rec
			, const ubigint refFmncMRun
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMRunState* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMRun, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMRunState::insertRst(
			ListFmncJMRunState& rst
			, bool transact
		) {
};

void TblFmncJMRunState::updateRec(
			FmncJMRunState* rec
		) {
};

void TblFmncJMRunState::updateRst(
			ListFmncJMRunState& rst
			, bool transact
		) {
};

void TblFmncJMRunState::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMRunState::loadRecByRef(
			ubigint ref
			, FmncJMRunState** rec
		) {
	return false;
};

bool TblFmncJMRunState::loadRecByRunSta(
			ubigint refFmncMRun
			, uint x1Start
			, FmncJMRunState** rec
		) {
	return false;
};

ubigint TblFmncJMRunState::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncJMRunState::loadRstByRun(
			ubigint refFmncMRun
			, const bool append
			, ListFmncJMRunState& rst
		) {
	return 0;
};

ubigint TblFmncJMRunState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMRunState& rst
		) {
	ubigint numload = 0;
	FmncJMRunState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMRunState
 ******************************************************************************/

MyTblFmncJMRunState::MyTblFmncJMRunState() : TblFmncJMRunState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMRunState::~MyTblFmncJMRunState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMRunState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMRunState (refFmncMRun, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMRunState SET refFmncMRun = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMRunState WHERE ref = ?", false);
};

bool MyTblFmncJMRunState::loadRecBySQL(
			const string& sqlstr
			, FmncJMRunState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMRunState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMRunState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMRunState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMRun = atoll((char*) dbrow[1]); else _rec->refFmncMRun = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMRunState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMRunState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMRunState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMRunState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMRunState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMRun = atoll((char*) dbrow[1]); else rec->refFmncMRun = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMRunState::insertRec(
			FmncJMRunState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMRun,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMRunState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMRunState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMRunState::insertRst(
			ListFmncJMRunState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMRunState::updateRec(
			FmncJMRunState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMRun,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMRunState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMRunState / stmtUpdateRec)\n");
};

void MyTblFmncJMRunState::updateRst(
			ListFmncJMRunState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMRunState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMRunState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMRunState / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMRunState::loadRecByRef(
			ubigint ref
			, FmncJMRunState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMRunState WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMRunState::loadRecByRunSta(
			ubigint refFmncMRun
			, uint x1Start
			, FmncJMRunState** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMRun, x1Start, ixVState FROM TblFmncJMRunState WHERE refFmncMRun = " + to_string(refFmncMRun) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMRunState::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncJMRunState WHERE refFmncMRun = " + to_string(refFmncMRun) + "", append, refs);
};

ubigint MyTblFmncJMRunState::loadRstByRun(
			ubigint refFmncMRun
			, const bool append
			, ListFmncJMRunState& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMRun, x1Start, ixVState FROM TblFmncJMRunState WHERE refFmncMRun = " + to_string(refFmncMRun) + " ORDER BY x1Start ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMRunState
 ******************************************************************************/

PgTblFmncJMRunState::PgTblFmncJMRunState() : TblFmncJMRunState(), PgTable() {
};

PgTblFmncJMRunState::~PgTblFmncJMRunState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMRunState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMRunState_insertRec", "INSERT INTO TblFmncJMRunState (refFmncMRun, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMRunState_updateRec", "UPDATE TblFmncJMRunState SET refFmncMRun = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMRunState_removeRecByRef", "DELETE FROM TblFmncJMRunState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMRunState_loadRecByRef", "SELECT ref, refFmncMRun, x1Start, ixVState FROM TblFmncJMRunState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMRunState_loadRecByRunSta", "SELECT ref, refFmncMRun, x1Start, ixVState FROM TblFmncJMRunState WHERE refFmncMRun = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMRunState_loadRefsByRun", "SELECT ref FROM TblFmncJMRunState WHERE refFmncMRun = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMRunState_loadRstByRun", "SELECT ref, refFmncMRun, x1Start, ixVState FROM TblFmncJMRunState WHERE refFmncMRun = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMRunState::loadRec(
			PGresult* res
			, FmncJMRunState** rec
		) {
	char* ptr;

	FmncJMRunState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMRunState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmrun"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMRun = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMRunState::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMRunState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMRunState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmrun"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncJMRunState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMRun = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMRunState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMRunState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMRunState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMRunState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMRunState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMRunState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMRunState::loadRecBySQL(
			const string& sqlstr
			, FmncJMRunState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMRunState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMRunState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMRunState::insertRec(
			FmncJMRunState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMRun = htonl64(rec->refFmncMRun);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refFmncMRun,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncJMRunState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMRunState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMRunState::insertRst(
			ListFmncJMRunState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMRunState::updateRec(
			FmncJMRunState* rec
		) {
	PGresult* res;

	ubigint _refFmncMRun = htonl64(rec->refFmncMRun);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMRun,
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

	res = PQexecPrepared(dbs, "TblFmncJMRunState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMRunState_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMRunState::updateRst(
			ListFmncJMRunState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMRunState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMRunState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMRunState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMRunState::loadRecByRef(
			ubigint ref
			, FmncJMRunState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMRunState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMRunState::loadRecByRunSta(
			ubigint refFmncMRun
			, uint x1Start
			, FmncJMRunState** rec
		) {
	ubigint _refFmncMRun = htonl64(refFmncMRun);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refFmncMRun,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMRunState_loadRecByRunSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMRunState::loadRefsByRun(
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

	return loadRefsByStmt("TblFmncJMRunState_loadRefsByRun", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncJMRunState::loadRstByRun(
			ubigint refFmncMRun
			, const bool append
			, ListFmncJMRunState& rst
		) {
	ubigint _refFmncMRun = htonl64(refFmncMRun);

	const char* vals[] = {
		(char*) &_refFmncMRun
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMRunState_loadRstByRun", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

