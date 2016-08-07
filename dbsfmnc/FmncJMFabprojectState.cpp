/**
  * \file FmncJMFabprojectState.cpp
  * database access for table TblFmncJMFabprojectState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMFabprojectState.h"

/******************************************************************************
 class FmncJMFabprojectState
 ******************************************************************************/

FmncJMFabprojectState::FmncJMFabprojectState(
			const ubigint ref
			, const ubigint refFmncMFabproject
			, const uint x1Startd
			, const uint ixVState
		) {

	this->ref = ref;
	this->refFmncMFabproject = refFmncMFabproject;
	this->x1Startd = x1Startd;
	this->ixVState = ixVState;
};

bool FmncJMFabprojectState::operator==(
			const FmncJMFabprojectState& comp
		) {
	return false;
};

bool FmncJMFabprojectState::operator!=(
			const FmncJMFabprojectState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMFabprojectState
 ******************************************************************************/

ListFmncJMFabprojectState::ListFmncJMFabprojectState() {
};

ListFmncJMFabprojectState::ListFmncJMFabprojectState(
			const ListFmncJMFabprojectState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMFabprojectState(*(src.nodes[i]));
};

ListFmncJMFabprojectState::~ListFmncJMFabprojectState() {
	clear();
};

void ListFmncJMFabprojectState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMFabprojectState::size() const {
	return(nodes.size());
};

void ListFmncJMFabprojectState::append(
			FmncJMFabprojectState* rec
		) {
	nodes.push_back(rec);
};

FmncJMFabprojectState* ListFmncJMFabprojectState::operator[](
			const uint ix
		) {
	FmncJMFabprojectState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMFabprojectState& ListFmncJMFabprojectState::operator=(
			const ListFmncJMFabprojectState& src
		) {
	FmncJMFabprojectState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMFabprojectState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMFabprojectState::operator==(
			const ListFmncJMFabprojectState& comp
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

bool ListFmncJMFabprojectState::operator!=(
			const ListFmncJMFabprojectState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMFabprojectState
 ******************************************************************************/

TblFmncJMFabprojectState::TblFmncJMFabprojectState() {
};

TblFmncJMFabprojectState::~TblFmncJMFabprojectState() {
};

bool TblFmncJMFabprojectState::loadRecBySQL(
			const string& sqlstr
			, FmncJMFabprojectState** rec
		) {
	return false;
};

ubigint TblFmncJMFabprojectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	return 0;
};

void TblFmncJMFabprojectState::insertRec(
			FmncJMFabprojectState* rec
		) {
};

ubigint TblFmncJMFabprojectState::insertNewRec(
			FmncJMFabprojectState** rec
			, const ubigint refFmncMFabproject
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMFabprojectState* _rec = NULL;

	_rec = new FmncJMFabprojectState(0, refFmncMFabproject, x1Startd, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMFabprojectState::appendNewRecToRst(
			ListFmncJMFabprojectState& rst
			, FmncJMFabprojectState** rec
			, const ubigint refFmncMFabproject
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMFabprojectState* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMFabproject, x1Startd, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMFabprojectState::insertRst(
			ListFmncJMFabprojectState& rst
			, bool transact
		) {
};

void TblFmncJMFabprojectState::updateRec(
			FmncJMFabprojectState* rec
		) {
};

void TblFmncJMFabprojectState::updateRst(
			ListFmncJMFabprojectState& rst
			, bool transact
		) {
};

void TblFmncJMFabprojectState::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMFabprojectState::loadRecByRef(
			ubigint ref
			, FmncJMFabprojectState** rec
		) {
	return false;
};

bool TblFmncJMFabprojectState::loadRecByFpjSta(
			ubigint refFmncMFabproject
			, uint x1Startd
			, FmncJMFabprojectState** rec
		) {
	return false;
};

ubigint TblFmncJMFabprojectState::loadRstByFpj(
			ubigint refFmncMFabproject
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	return 0;
};

ubigint TblFmncJMFabprojectState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	ubigint numload = 0;
	FmncJMFabprojectState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMFabprojectState
 ******************************************************************************/

MyTblFmncJMFabprojectState::MyTblFmncJMFabprojectState() : TblFmncJMFabprojectState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMFabprojectState::~MyTblFmncJMFabprojectState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMFabprojectState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMFabprojectState (refFmncMFabproject, x1Startd, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMFabprojectState SET refFmncMFabproject = ?, x1Startd = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMFabprojectState WHERE ref = ?", false);
};

bool MyTblFmncJMFabprojectState::loadRecBySQL(
			const string& sqlstr
			, FmncJMFabprojectState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMFabprojectState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMFabprojectState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMFabprojectState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMFabproject = atoll((char*) dbrow[1]); else _rec->refFmncMFabproject = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMFabprojectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMFabprojectState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMFabprojectState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMFabprojectState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMFabproject = atoll((char*) dbrow[1]); else rec->refFmncMFabproject = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMFabprojectState::insertRec(
			FmncJMFabprojectState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFabproject,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMFabprojectState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMFabprojectState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMFabprojectState::insertRst(
			ListFmncJMFabprojectState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMFabprojectState::updateRec(
			FmncJMFabprojectState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFabproject,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMFabprojectState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMFabprojectState / stmtUpdateRec)\n");
};

void MyTblFmncJMFabprojectState::updateRst(
			ListFmncJMFabprojectState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMFabprojectState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMFabprojectState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMFabprojectState / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMFabprojectState::loadRecByRef(
			ubigint ref
			, FmncJMFabprojectState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMFabprojectState WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMFabprojectState::loadRecByFpjSta(
			ubigint refFmncMFabproject
			, uint x1Startd
			, FmncJMFabprojectState** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMFabproject, x1Startd, ixVState FROM TblFmncJMFabprojectState WHERE refFmncMFabproject = " + to_string(refFmncMFabproject) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMFabprojectState::loadRstByFpj(
			ubigint refFmncMFabproject
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMFabproject, x1Startd, ixVState FROM TblFmncJMFabprojectState WHERE refFmncMFabproject = " + to_string(refFmncMFabproject) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMFabprojectState
 ******************************************************************************/

PgTblFmncJMFabprojectState::PgTblFmncJMFabprojectState() : TblFmncJMFabprojectState(), PgTable() {
};

PgTblFmncJMFabprojectState::~PgTblFmncJMFabprojectState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMFabprojectState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMFabprojectState_insertRec", "INSERT INTO TblFmncJMFabprojectState (refFmncMFabproject, x1Startd, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMFabprojectState_updateRec", "UPDATE TblFmncJMFabprojectState SET refFmncMFabproject = $1, x1Startd = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMFabprojectState_removeRecByRef", "DELETE FROM TblFmncJMFabprojectState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMFabprojectState_loadRecByRef", "SELECT ref, refFmncMFabproject, x1Startd, ixVState FROM TblFmncJMFabprojectState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMFabprojectState_loadRecByFpjSta", "SELECT ref, refFmncMFabproject, x1Startd, ixVState FROM TblFmncJMFabprojectState WHERE refFmncMFabproject = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMFabprojectState_loadRstByFpj", "SELECT ref, refFmncMFabproject, x1Startd, ixVState FROM TblFmncJMFabprojectState WHERE refFmncMFabproject = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMFabprojectState::loadRec(
			PGresult* res
			, FmncJMFabprojectState** rec
		) {
	char* ptr;

	FmncJMFabprojectState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMFabprojectState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMFabprojectState::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMFabprojectState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncJMFabprojectState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMFabprojectState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMFabprojectState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMFabprojectState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMFabprojectState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMFabprojectState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMFabprojectState::loadRecBySQL(
			const string& sqlstr
			, FmncJMFabprojectState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMFabprojectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMFabprojectState::insertRec(
			FmncJMFabprojectState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refFmncMFabproject,
		(char*) &_x1Startd,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncJMFabprojectState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMFabprojectState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMFabprojectState::insertRst(
			ListFmncJMFabprojectState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMFabprojectState::updateRec(
			FmncJMFabprojectState* rec
		) {
	PGresult* res;

	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMFabproject,
		(char*) &_x1Startd,
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

	res = PQexecPrepared(dbs, "TblFmncJMFabprojectState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMFabprojectState_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMFabprojectState::updateRst(
			ListFmncJMFabprojectState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMFabprojectState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMFabprojectState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMFabprojectState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMFabprojectState::loadRecByRef(
			ubigint ref
			, FmncJMFabprojectState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMFabprojectState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMFabprojectState::loadRecByFpjSta(
			ubigint refFmncMFabproject
			, uint x1Startd
			, FmncJMFabprojectState** rec
		) {
	ubigint _refFmncMFabproject = htonl64(refFmncMFabproject);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMFabproject,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMFabprojectState_loadRecByFpjSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMFabprojectState::loadRstByFpj(
			ubigint refFmncMFabproject
			, const bool append
			, ListFmncJMFabprojectState& rst
		) {
	ubigint _refFmncMFabproject = htonl64(refFmncMFabproject);

	const char* vals[] = {
		(char*) &_refFmncMFabproject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMFabprojectState_loadRstByFpj", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

