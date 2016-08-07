/**
  * \file FmncJMPurchorderState.cpp
  * database access for table TblFmncJMPurchorderState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMPurchorderState.h"

/******************************************************************************
 class FmncJMPurchorderState
 ******************************************************************************/

FmncJMPurchorderState::FmncJMPurchorderState(
			const ubigint ref
			, const ubigint refFmncMPurchorder
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refFmncMPurchorder = refFmncMPurchorder;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool FmncJMPurchorderState::operator==(
			const FmncJMPurchorderState& comp
		) {
	return false;
};

bool FmncJMPurchorderState::operator!=(
			const FmncJMPurchorderState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMPurchorderState
 ******************************************************************************/

ListFmncJMPurchorderState::ListFmncJMPurchorderState() {
};

ListFmncJMPurchorderState::ListFmncJMPurchorderState(
			const ListFmncJMPurchorderState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMPurchorderState(*(src.nodes[i]));
};

ListFmncJMPurchorderState::~ListFmncJMPurchorderState() {
	clear();
};

void ListFmncJMPurchorderState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMPurchorderState::size() const {
	return(nodes.size());
};

void ListFmncJMPurchorderState::append(
			FmncJMPurchorderState* rec
		) {
	nodes.push_back(rec);
};

FmncJMPurchorderState* ListFmncJMPurchorderState::operator[](
			const uint ix
		) {
	FmncJMPurchorderState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMPurchorderState& ListFmncJMPurchorderState::operator=(
			const ListFmncJMPurchorderState& src
		) {
	FmncJMPurchorderState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMPurchorderState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMPurchorderState::operator==(
			const ListFmncJMPurchorderState& comp
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

bool ListFmncJMPurchorderState::operator!=(
			const ListFmncJMPurchorderState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMPurchorderState
 ******************************************************************************/

TblFmncJMPurchorderState::TblFmncJMPurchorderState() {
};

TblFmncJMPurchorderState::~TblFmncJMPurchorderState() {
};

bool TblFmncJMPurchorderState::loadRecBySQL(
			const string& sqlstr
			, FmncJMPurchorderState** rec
		) {
	return false;
};

ubigint TblFmncJMPurchorderState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	return 0;
};

void TblFmncJMPurchorderState::insertRec(
			FmncJMPurchorderState* rec
		) {
};

ubigint TblFmncJMPurchorderState::insertNewRec(
			FmncJMPurchorderState** rec
			, const ubigint refFmncMPurchorder
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMPurchorderState* _rec = NULL;

	_rec = new FmncJMPurchorderState(0, refFmncMPurchorder, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMPurchorderState::appendNewRecToRst(
			ListFmncJMPurchorderState& rst
			, FmncJMPurchorderState** rec
			, const ubigint refFmncMPurchorder
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMPurchorderState* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMPurchorder, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMPurchorderState::insertRst(
			ListFmncJMPurchorderState& rst
			, bool transact
		) {
};

void TblFmncJMPurchorderState::updateRec(
			FmncJMPurchorderState* rec
		) {
};

void TblFmncJMPurchorderState::updateRst(
			ListFmncJMPurchorderState& rst
			, bool transact
		) {
};

void TblFmncJMPurchorderState::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMPurchorderState::loadRecByRef(
			ubigint ref
			, FmncJMPurchorderState** rec
		) {
	return false;
};

bool TblFmncJMPurchorderState::loadRecByPcoSta(
			ubigint refFmncMPurchorder
			, uint x1Start
			, FmncJMPurchorderState** rec
		) {
	return false;
};

ubigint TblFmncJMPurchorderState::loadRstByPco(
			ubigint refFmncMPurchorder
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	return 0;
};

ubigint TblFmncJMPurchorderState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	ubigint numload = 0;
	FmncJMPurchorderState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMPurchorderState
 ******************************************************************************/

MyTblFmncJMPurchorderState::MyTblFmncJMPurchorderState() : TblFmncJMPurchorderState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMPurchorderState::~MyTblFmncJMPurchorderState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMPurchorderState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMPurchorderState (refFmncMPurchorder, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMPurchorderState SET refFmncMPurchorder = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMPurchorderState WHERE ref = ?", false);
};

bool MyTblFmncJMPurchorderState::loadRecBySQL(
			const string& sqlstr
			, FmncJMPurchorderState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMPurchorderState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMPurchorderState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMPurchorderState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMPurchorder = atoll((char*) dbrow[1]); else _rec->refFmncMPurchorder = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMPurchorderState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMPurchorderState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMPurchorderState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMPurchorderState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMPurchorder = atoll((char*) dbrow[1]); else rec->refFmncMPurchorder = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMPurchorderState::insertRec(
			FmncJMPurchorderState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPurchorder,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMPurchorderState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMPurchorderState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMPurchorderState::insertRst(
			ListFmncJMPurchorderState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMPurchorderState::updateRec(
			FmncJMPurchorderState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPurchorder,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMPurchorderState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMPurchorderState / stmtUpdateRec)\n");
};

void MyTblFmncJMPurchorderState::updateRst(
			ListFmncJMPurchorderState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMPurchorderState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMPurchorderState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMPurchorderState / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMPurchorderState::loadRecByRef(
			ubigint ref
			, FmncJMPurchorderState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMPurchorderState WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMPurchorderState::loadRecByPcoSta(
			ubigint refFmncMPurchorder
			, uint x1Start
			, FmncJMPurchorderState** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMPurchorder, x1Start, ixVState FROM TblFmncJMPurchorderState WHERE refFmncMPurchorder = " + to_string(refFmncMPurchorder) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMPurchorderState::loadRstByPco(
			ubigint refFmncMPurchorder
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMPurchorder, x1Start, ixVState FROM TblFmncJMPurchorderState WHERE refFmncMPurchorder = " + to_string(refFmncMPurchorder) + " ORDER BY x1Start ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMPurchorderState
 ******************************************************************************/

PgTblFmncJMPurchorderState::PgTblFmncJMPurchorderState() : TblFmncJMPurchorderState(), PgTable() {
};

PgTblFmncJMPurchorderState::~PgTblFmncJMPurchorderState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMPurchorderState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMPurchorderState_insertRec", "INSERT INTO TblFmncJMPurchorderState (refFmncMPurchorder, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMPurchorderState_updateRec", "UPDATE TblFmncJMPurchorderState SET refFmncMPurchorder = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMPurchorderState_removeRecByRef", "DELETE FROM TblFmncJMPurchorderState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMPurchorderState_loadRecByRef", "SELECT ref, refFmncMPurchorder, x1Start, ixVState FROM TblFmncJMPurchorderState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMPurchorderState_loadRecByPcoSta", "SELECT ref, refFmncMPurchorder, x1Start, ixVState FROM TblFmncJMPurchorderState WHERE refFmncMPurchorder = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMPurchorderState_loadRstByPco", "SELECT ref, refFmncMPurchorder, x1Start, ixVState FROM TblFmncJMPurchorderState WHERE refFmncMPurchorder = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMPurchorderState::loadRec(
			PGresult* res
			, FmncJMPurchorderState** rec
		) {
	char* ptr;

	FmncJMPurchorderState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMPurchorderState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmpurchorder"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMPurchorder = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMPurchorderState::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMPurchorderState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmpurchorder"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncJMPurchorderState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMPurchorder = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMPurchorderState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMPurchorderState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPurchorderState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMPurchorderState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPurchorderState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMPurchorderState::loadRecBySQL(
			const string& sqlstr
			, FmncJMPurchorderState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMPurchorderState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMPurchorderState::insertRec(
			FmncJMPurchorderState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMPurchorder = htonl64(rec->refFmncMPurchorder);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refFmncMPurchorder,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncJMPurchorderState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPurchorderState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMPurchorderState::insertRst(
			ListFmncJMPurchorderState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMPurchorderState::updateRec(
			FmncJMPurchorderState* rec
		) {
	PGresult* res;

	ubigint _refFmncMPurchorder = htonl64(rec->refFmncMPurchorder);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMPurchorder,
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

	res = PQexecPrepared(dbs, "TblFmncJMPurchorderState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPurchorderState_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMPurchorderState::updateRst(
			ListFmncJMPurchorderState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMPurchorderState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMPurchorderState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPurchorderState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMPurchorderState::loadRecByRef(
			ubigint ref
			, FmncJMPurchorderState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMPurchorderState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMPurchorderState::loadRecByPcoSta(
			ubigint refFmncMPurchorder
			, uint x1Start
			, FmncJMPurchorderState** rec
		) {
	ubigint _refFmncMPurchorder = htonl64(refFmncMPurchorder);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refFmncMPurchorder,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMPurchorderState_loadRecByPcoSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMPurchorderState::loadRstByPco(
			ubigint refFmncMPurchorder
			, const bool append
			, ListFmncJMPurchorderState& rst
		) {
	ubigint _refFmncMPurchorder = htonl64(refFmncMPurchorder);

	const char* vals[] = {
		(char*) &_refFmncMPurchorder
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMPurchorderState_loadRstByPco", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

