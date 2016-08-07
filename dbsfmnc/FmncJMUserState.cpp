/**
  * \file FmncJMUserState.cpp
  * database access for table TblFmncJMUserState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMUserState.h"

/******************************************************************************
 class FmncJMUserState
 ******************************************************************************/

FmncJMUserState::FmncJMUserState(
			const ubigint ref
			, const ubigint refFmncMUser
			, const uint x1Startd
			, const uint ixVState
		) {

	this->ref = ref;
	this->refFmncMUser = refFmncMUser;
	this->x1Startd = x1Startd;
	this->ixVState = ixVState;
};

bool FmncJMUserState::operator==(
			const FmncJMUserState& comp
		) {
	return false;
};

bool FmncJMUserState::operator!=(
			const FmncJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMUserState
 ******************************************************************************/

ListFmncJMUserState::ListFmncJMUserState() {
};

ListFmncJMUserState::ListFmncJMUserState(
			const ListFmncJMUserState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMUserState(*(src.nodes[i]));
};

ListFmncJMUserState::~ListFmncJMUserState() {
	clear();
};

void ListFmncJMUserState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMUserState::size() const {
	return(nodes.size());
};

void ListFmncJMUserState::append(
			FmncJMUserState* rec
		) {
	nodes.push_back(rec);
};

FmncJMUserState* ListFmncJMUserState::operator[](
			const uint ix
		) {
	FmncJMUserState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMUserState& ListFmncJMUserState::operator=(
			const ListFmncJMUserState& src
		) {
	FmncJMUserState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMUserState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMUserState::operator==(
			const ListFmncJMUserState& comp
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

bool ListFmncJMUserState::operator!=(
			const ListFmncJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMUserState
 ******************************************************************************/

TblFmncJMUserState::TblFmncJMUserState() {
};

TblFmncJMUserState::~TblFmncJMUserState() {
};

bool TblFmncJMUserState::loadRecBySQL(
			const string& sqlstr
			, FmncJMUserState** rec
		) {
	return false;
};

ubigint TblFmncJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMUserState& rst
		) {
	return 0;
};

void TblFmncJMUserState::insertRec(
			FmncJMUserState* rec
		) {
};

ubigint TblFmncJMUserState::insertNewRec(
			FmncJMUserState** rec
			, const ubigint refFmncMUser
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMUserState* _rec = NULL;

	_rec = new FmncJMUserState(0, refFmncMUser, x1Startd, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMUserState::appendNewRecToRst(
			ListFmncJMUserState& rst
			, FmncJMUserState** rec
			, const ubigint refFmncMUser
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMUserState* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMUser, x1Startd, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMUserState::insertRst(
			ListFmncJMUserState& rst
			, bool transact
		) {
};

void TblFmncJMUserState::updateRec(
			FmncJMUserState* rec
		) {
};

void TblFmncJMUserState::updateRst(
			ListFmncJMUserState& rst
			, bool transact
		) {
};

void TblFmncJMUserState::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMUserState::loadRecByRef(
			ubigint ref
			, FmncJMUserState** rec
		) {
	return false;
};

bool TblFmncJMUserState::loadRecByUsrSta(
			ubigint refFmncMUser
			, uint x1Startd
			, FmncJMUserState** rec
		) {
	return false;
};

ubigint TblFmncJMUserState::loadRefsByUsr(
			ubigint refFmncMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncJMUserState::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncJMUserState& rst
		) {
	return 0;
};

ubigint TblFmncJMUserState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMUserState& rst
		) {
	ubigint numload = 0;
	FmncJMUserState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMUserState
 ******************************************************************************/

MyTblFmncJMUserState::MyTblFmncJMUserState() : TblFmncJMUserState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMUserState::~MyTblFmncJMUserState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMUserState (refFmncMUser, x1Startd, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMUserState SET refFmncMUser = ?, x1Startd = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMUserState WHERE ref = ?", false);
};

bool MyTblFmncJMUserState::loadRecBySQL(
			const string& sqlstr
			, FmncJMUserState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMUserState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMUserState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMUserState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMUser = atoll((char*) dbrow[1]); else _rec->refFmncMUser = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMUserState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMUserState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMUserState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMUserState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMUser = atoll((char*) dbrow[1]); else rec->refFmncMUser = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMUserState::insertRec(
			FmncJMUserState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMUserState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMUserState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMUserState::insertRst(
			ListFmncJMUserState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMUserState::updateRec(
			FmncJMUserState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMUserState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMUserState / stmtUpdateRec)\n");
};

void MyTblFmncJMUserState::updateRst(
			ListFmncJMUserState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMUserState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMUserState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMUserState / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMUserState::loadRecByRef(
			ubigint ref
			, FmncJMUserState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMUserState WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMUserState::loadRecByUsrSta(
			ubigint refFmncMUser
			, uint x1Startd
			, FmncJMUserState** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMUser, x1Startd, ixVState FROM TblFmncJMUserState WHERE refFmncMUser = " + to_string(refFmncMUser) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMUserState::loadRefsByUsr(
			ubigint refFmncMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncJMUserState WHERE refFmncMUser = " + to_string(refFmncMUser) + "", append, refs);
};

ubigint MyTblFmncJMUserState::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncJMUserState& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMUser, x1Startd, ixVState FROM TblFmncJMUserState WHERE refFmncMUser = " + to_string(refFmncMUser) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMUserState
 ******************************************************************************/

PgTblFmncJMUserState::PgTblFmncJMUserState() : TblFmncJMUserState(), PgTable() {
};

PgTblFmncJMUserState::~PgTblFmncJMUserState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMUserState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMUserState_insertRec", "INSERT INTO TblFmncJMUserState (refFmncMUser, x1Startd, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMUserState_updateRec", "UPDATE TblFmncJMUserState SET refFmncMUser = $1, x1Startd = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMUserState_removeRecByRef", "DELETE FROM TblFmncJMUserState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMUserState_loadRecByRef", "SELECT ref, refFmncMUser, x1Startd, ixVState FROM TblFmncJMUserState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMUserState_loadRecByUsrSta", "SELECT ref, refFmncMUser, x1Startd, ixVState FROM TblFmncJMUserState WHERE refFmncMUser = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMUserState_loadRefsByUsr", "SELECT ref FROM TblFmncJMUserState WHERE refFmncMUser = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMUserState_loadRstByUsr", "SELECT ref, refFmncMUser, x1Startd, ixVState FROM TblFmncJMUserState WHERE refFmncMUser = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMUserState::loadRec(
			PGresult* res
			, FmncJMUserState** rec
		) {
	char* ptr;

	FmncJMUserState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMUserState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMUserState::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMUserState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMUserState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncJMUserState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMUserState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMUserState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMUserState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMUserState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMUserState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMUserState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMUserState::loadRecBySQL(
			const string& sqlstr
			, FmncJMUserState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMUserState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMUserState::insertRec(
			FmncJMUserState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_x1Startd,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncJMUserState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMUserState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMUserState::insertRst(
			ListFmncJMUserState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMUserState::updateRec(
			FmncJMUserState* rec
		) {
	PGresult* res;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMUser,
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

	res = PQexecPrepared(dbs, "TblFmncJMUserState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMUserState_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMUserState::updateRst(
			ListFmncJMUserState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMUserState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMUserState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMUserState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMUserState::loadRecByRef(
			ubigint ref
			, FmncJMUserState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMUserState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMUserState::loadRecByUsrSta(
			ubigint refFmncMUser
			, uint x1Startd
			, FmncJMUserState** rec
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMUserState_loadRecByUsrSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMUserState::loadRefsByUsr(
			ubigint refFmncMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);

	const char* vals[] = {
		(char*) &_refFmncMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncJMUserState_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncJMUserState::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncJMUserState& rst
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);

	const char* vals[] = {
		(char*) &_refFmncMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMUserState_loadRstByUsr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

