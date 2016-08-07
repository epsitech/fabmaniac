/**
  * \file FmncJMBillState.cpp
  * database access for table TblFmncJMBillState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMBillState.h"

/******************************************************************************
 class FmncJMBillState
 ******************************************************************************/

FmncJMBillState::FmncJMBillState(
			const ubigint ref
			, const ubigint refFmncMBill
			, const uint x1Startd
			, const uint ixVState
		) {

	this->ref = ref;
	this->refFmncMBill = refFmncMBill;
	this->x1Startd = x1Startd;
	this->ixVState = ixVState;
};

bool FmncJMBillState::operator==(
			const FmncJMBillState& comp
		) {
	return false;
};

bool FmncJMBillState::operator!=(
			const FmncJMBillState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMBillState
 ******************************************************************************/

ListFmncJMBillState::ListFmncJMBillState() {
};

ListFmncJMBillState::ListFmncJMBillState(
			const ListFmncJMBillState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMBillState(*(src.nodes[i]));
};

ListFmncJMBillState::~ListFmncJMBillState() {
	clear();
};

void ListFmncJMBillState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMBillState::size() const {
	return(nodes.size());
};

void ListFmncJMBillState::append(
			FmncJMBillState* rec
		) {
	nodes.push_back(rec);
};

FmncJMBillState* ListFmncJMBillState::operator[](
			const uint ix
		) {
	FmncJMBillState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMBillState& ListFmncJMBillState::operator=(
			const ListFmncJMBillState& src
		) {
	FmncJMBillState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMBillState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMBillState::operator==(
			const ListFmncJMBillState& comp
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

bool ListFmncJMBillState::operator!=(
			const ListFmncJMBillState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMBillState
 ******************************************************************************/

TblFmncJMBillState::TblFmncJMBillState() {
};

TblFmncJMBillState::~TblFmncJMBillState() {
};

bool TblFmncJMBillState::loadRecBySQL(
			const string& sqlstr
			, FmncJMBillState** rec
		) {
	return false;
};

ubigint TblFmncJMBillState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMBillState& rst
		) {
	return 0;
};

void TblFmncJMBillState::insertRec(
			FmncJMBillState* rec
		) {
};

ubigint TblFmncJMBillState::insertNewRec(
			FmncJMBillState** rec
			, const ubigint refFmncMBill
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMBillState* _rec = NULL;

	_rec = new FmncJMBillState(0, refFmncMBill, x1Startd, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMBillState::appendNewRecToRst(
			ListFmncJMBillState& rst
			, FmncJMBillState** rec
			, const ubigint refFmncMBill
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMBillState* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMBill, x1Startd, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMBillState::insertRst(
			ListFmncJMBillState& rst
			, bool transact
		) {
};

void TblFmncJMBillState::updateRec(
			FmncJMBillState* rec
		) {
};

void TblFmncJMBillState::updateRst(
			ListFmncJMBillState& rst
			, bool transact
		) {
};

void TblFmncJMBillState::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMBillState::loadRecByRef(
			ubigint ref
			, FmncJMBillState** rec
		) {
	return false;
};

bool TblFmncJMBillState::loadRecByBilSta(
			ubigint refFmncMBill
			, uint x1Startd
			, FmncJMBillState** rec
		) {
	return false;
};

ubigint TblFmncJMBillState::loadRstByBil(
			ubigint refFmncMBill
			, const bool append
			, ListFmncJMBillState& rst
		) {
	return 0;
};

ubigint TblFmncJMBillState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMBillState& rst
		) {
	ubigint numload = 0;
	FmncJMBillState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMBillState
 ******************************************************************************/

MyTblFmncJMBillState::MyTblFmncJMBillState() : TblFmncJMBillState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMBillState::~MyTblFmncJMBillState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMBillState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMBillState (refFmncMBill, x1Startd, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMBillState SET refFmncMBill = ?, x1Startd = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMBillState WHERE ref = ?", false);
};

bool MyTblFmncJMBillState::loadRecBySQL(
			const string& sqlstr
			, FmncJMBillState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMBillState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMBillState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMBillState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMBill = atoll((char*) dbrow[1]); else _rec->refFmncMBill = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMBillState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMBillState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMBillState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMBillState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMBillState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMBill = atoll((char*) dbrow[1]); else rec->refFmncMBill = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMBillState::insertRec(
			FmncJMBillState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMBill,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMBillState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMBillState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMBillState::insertRst(
			ListFmncJMBillState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMBillState::updateRec(
			FmncJMBillState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMBill,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMBillState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMBillState / stmtUpdateRec)\n");
};

void MyTblFmncJMBillState::updateRst(
			ListFmncJMBillState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMBillState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMBillState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMBillState / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMBillState::loadRecByRef(
			ubigint ref
			, FmncJMBillState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMBillState WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMBillState::loadRecByBilSta(
			ubigint refFmncMBill
			, uint x1Startd
			, FmncJMBillState** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMBill, x1Startd, ixVState FROM TblFmncJMBillState WHERE refFmncMBill = " + to_string(refFmncMBill) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMBillState::loadRstByBil(
			ubigint refFmncMBill
			, const bool append
			, ListFmncJMBillState& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMBill, x1Startd, ixVState FROM TblFmncJMBillState WHERE refFmncMBill = " + to_string(refFmncMBill) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMBillState
 ******************************************************************************/

PgTblFmncJMBillState::PgTblFmncJMBillState() : TblFmncJMBillState(), PgTable() {
};

PgTblFmncJMBillState::~PgTblFmncJMBillState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMBillState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMBillState_insertRec", "INSERT INTO TblFmncJMBillState (refFmncMBill, x1Startd, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMBillState_updateRec", "UPDATE TblFmncJMBillState SET refFmncMBill = $1, x1Startd = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMBillState_removeRecByRef", "DELETE FROM TblFmncJMBillState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMBillState_loadRecByRef", "SELECT ref, refFmncMBill, x1Startd, ixVState FROM TblFmncJMBillState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMBillState_loadRecByBilSta", "SELECT ref, refFmncMBill, x1Startd, ixVState FROM TblFmncJMBillState WHERE refFmncMBill = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMBillState_loadRstByBil", "SELECT ref, refFmncMBill, x1Startd, ixVState FROM TblFmncJMBillState WHERE refFmncMBill = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMBillState::loadRec(
			PGresult* res
			, FmncJMBillState** rec
		) {
	char* ptr;

	FmncJMBillState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMBillState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmbill"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMBill = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMBillState::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMBillState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMBillState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmbill"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncJMBillState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMBill = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMBillState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMBillState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMBillState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMBillState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMBillState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMBillState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMBillState::loadRecBySQL(
			const string& sqlstr
			, FmncJMBillState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMBillState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMBillState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMBillState::insertRec(
			FmncJMBillState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMBill = htonl64(rec->refFmncMBill);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refFmncMBill,
		(char*) &_x1Startd,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncJMBillState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMBillState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMBillState::insertRst(
			ListFmncJMBillState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMBillState::updateRec(
			FmncJMBillState* rec
		) {
	PGresult* res;

	ubigint _refFmncMBill = htonl64(rec->refFmncMBill);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMBill,
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

	res = PQexecPrepared(dbs, "TblFmncJMBillState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMBillState_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMBillState::updateRst(
			ListFmncJMBillState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMBillState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMBillState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMBillState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMBillState::loadRecByRef(
			ubigint ref
			, FmncJMBillState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMBillState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMBillState::loadRecByBilSta(
			ubigint refFmncMBill
			, uint x1Startd
			, FmncJMBillState** rec
		) {
	ubigint _refFmncMBill = htonl64(refFmncMBill);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMBill,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMBillState_loadRecByBilSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMBillState::loadRstByBil(
			ubigint refFmncMBill
			, const bool append
			, ListFmncJMBillState& rst
		) {
	ubigint _refFmncMBill = htonl64(refFmncMBill);

	const char* vals[] = {
		(char*) &_refFmncMBill
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMBillState_loadRstByBil", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

