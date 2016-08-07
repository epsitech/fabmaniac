/**
  * \file FmncJMProjectState.cpp
  * database access for table TblFmncJMProjectState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMProjectState.h"

/******************************************************************************
 class FmncJMProjectState
 ******************************************************************************/

FmncJMProjectState::FmncJMProjectState(
			const ubigint ref
			, const ubigint refFmncMProject
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refFmncMProject = refFmncMProject;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool FmncJMProjectState::operator==(
			const FmncJMProjectState& comp
		) {
	return false;
};

bool FmncJMProjectState::operator!=(
			const FmncJMProjectState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMProjectState
 ******************************************************************************/

ListFmncJMProjectState::ListFmncJMProjectState() {
};

ListFmncJMProjectState::ListFmncJMProjectState(
			const ListFmncJMProjectState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMProjectState(*(src.nodes[i]));
};

ListFmncJMProjectState::~ListFmncJMProjectState() {
	clear();
};

void ListFmncJMProjectState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMProjectState::size() const {
	return(nodes.size());
};

void ListFmncJMProjectState::append(
			FmncJMProjectState* rec
		) {
	nodes.push_back(rec);
};

FmncJMProjectState* ListFmncJMProjectState::operator[](
			const uint ix
		) {
	FmncJMProjectState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMProjectState& ListFmncJMProjectState::operator=(
			const ListFmncJMProjectState& src
		) {
	FmncJMProjectState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMProjectState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMProjectState::operator==(
			const ListFmncJMProjectState& comp
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

bool ListFmncJMProjectState::operator!=(
			const ListFmncJMProjectState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMProjectState
 ******************************************************************************/

TblFmncJMProjectState::TblFmncJMProjectState() {
};

TblFmncJMProjectState::~TblFmncJMProjectState() {
};

bool TblFmncJMProjectState::loadRecBySQL(
			const string& sqlstr
			, FmncJMProjectState** rec
		) {
	return false;
};

ubigint TblFmncJMProjectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	return 0;
};

void TblFmncJMProjectState::insertRec(
			FmncJMProjectState* rec
		) {
};

ubigint TblFmncJMProjectState::insertNewRec(
			FmncJMProjectState** rec
			, const ubigint refFmncMProject
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMProjectState* _rec = NULL;

	_rec = new FmncJMProjectState(0, refFmncMProject, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMProjectState::appendNewRecToRst(
			ListFmncJMProjectState& rst
			, FmncJMProjectState** rec
			, const ubigint refFmncMProject
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncJMProjectState* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMProject, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMProjectState::insertRst(
			ListFmncJMProjectState& rst
			, bool transact
		) {
};

void TblFmncJMProjectState::updateRec(
			FmncJMProjectState* rec
		) {
};

void TblFmncJMProjectState::updateRst(
			ListFmncJMProjectState& rst
			, bool transact
		) {
};

void TblFmncJMProjectState::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMProjectState::loadRecByRef(
			ubigint ref
			, FmncJMProjectState** rec
		) {
	return false;
};

bool TblFmncJMProjectState::loadRecByPrjSta(
			ubigint refFmncMProject
			, uint x1Start
			, FmncJMProjectState** rec
		) {
	return false;
};

ubigint TblFmncJMProjectState::loadRefsByPrj(
			ubigint refFmncMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncJMProjectState::loadRstByPrj(
			ubigint refFmncMProject
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	return 0;
};

ubigint TblFmncJMProjectState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	ubigint numload = 0;
	FmncJMProjectState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMProjectState
 ******************************************************************************/

MyTblFmncJMProjectState::MyTblFmncJMProjectState() : TblFmncJMProjectState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMProjectState::~MyTblFmncJMProjectState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMProjectState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMProjectState (refFmncMProject, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMProjectState SET refFmncMProject = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMProjectState WHERE ref = ?", false);
};

bool MyTblFmncJMProjectState::loadRecBySQL(
			const string& sqlstr
			, FmncJMProjectState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMProjectState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMProjectState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMProjectState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMProject = atoll((char*) dbrow[1]); else _rec->refFmncMProject = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMProjectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMProjectState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMProjectState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMProjectState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMProject = atoll((char*) dbrow[1]); else rec->refFmncMProject = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMProjectState::insertRec(
			FmncJMProjectState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMProject,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMProjectState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMProjectState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMProjectState::insertRst(
			ListFmncJMProjectState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMProjectState::updateRec(
			FmncJMProjectState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMProject,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMProjectState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMProjectState / stmtUpdateRec)\n");
};

void MyTblFmncJMProjectState::updateRst(
			ListFmncJMProjectState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMProjectState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMProjectState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMProjectState / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMProjectState::loadRecByRef(
			ubigint ref
			, FmncJMProjectState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMProjectState WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMProjectState::loadRecByPrjSta(
			ubigint refFmncMProject
			, uint x1Start
			, FmncJMProjectState** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMProject, x1Start, ixVState FROM TblFmncJMProjectState WHERE refFmncMProject = " + to_string(refFmncMProject) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMProjectState::loadRefsByPrj(
			ubigint refFmncMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncJMProjectState WHERE refFmncMProject = " + to_string(refFmncMProject) + "", append, refs);
};

ubigint MyTblFmncJMProjectState::loadRstByPrj(
			ubigint refFmncMProject
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMProject, x1Start, ixVState FROM TblFmncJMProjectState WHERE refFmncMProject = " + to_string(refFmncMProject) + " ORDER BY x1Start ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMProjectState
 ******************************************************************************/

PgTblFmncJMProjectState::PgTblFmncJMProjectState() : TblFmncJMProjectState(), PgTable() {
};

PgTblFmncJMProjectState::~PgTblFmncJMProjectState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMProjectState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMProjectState_insertRec", "INSERT INTO TblFmncJMProjectState (refFmncMProject, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMProjectState_updateRec", "UPDATE TblFmncJMProjectState SET refFmncMProject = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMProjectState_removeRecByRef", "DELETE FROM TblFmncJMProjectState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMProjectState_loadRecByRef", "SELECT ref, refFmncMProject, x1Start, ixVState FROM TblFmncJMProjectState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMProjectState_loadRecByPrjSta", "SELECT ref, refFmncMProject, x1Start, ixVState FROM TblFmncJMProjectState WHERE refFmncMProject = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMProjectState_loadRefsByPrj", "SELECT ref FROM TblFmncJMProjectState WHERE refFmncMProject = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMProjectState_loadRstByPrj", "SELECT ref, refFmncMProject, x1Start, ixVState FROM TblFmncJMProjectState WHERE refFmncMProject = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMProjectState::loadRec(
			PGresult* res
			, FmncJMProjectState** rec
		) {
	char* ptr;

	FmncJMProjectState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMProjectState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmproject"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMProjectState::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMProjectState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmproject"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncJMProjectState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMProjectState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMProjectState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMProjectState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMProjectState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMProjectState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMProjectState::loadRecBySQL(
			const string& sqlstr
			, FmncJMProjectState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMProjectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMProjectState::insertRec(
			FmncJMProjectState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMProject = htonl64(rec->refFmncMProject);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refFmncMProject,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncJMProjectState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMProjectState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMProjectState::insertRst(
			ListFmncJMProjectState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMProjectState::updateRec(
			FmncJMProjectState* rec
		) {
	PGresult* res;

	ubigint _refFmncMProject = htonl64(rec->refFmncMProject);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMProject,
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

	res = PQexecPrepared(dbs, "TblFmncJMProjectState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMProjectState_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMProjectState::updateRst(
			ListFmncJMProjectState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMProjectState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMProjectState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMProjectState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMProjectState::loadRecByRef(
			ubigint ref
			, FmncJMProjectState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMProjectState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMProjectState::loadRecByPrjSta(
			ubigint refFmncMProject
			, uint x1Start
			, FmncJMProjectState** rec
		) {
	ubigint _refFmncMProject = htonl64(refFmncMProject);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refFmncMProject,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMProjectState_loadRecByPrjSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMProjectState::loadRefsByPrj(
			ubigint refFmncMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMProject = htonl64(refFmncMProject);

	const char* vals[] = {
		(char*) &_refFmncMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncJMProjectState_loadRefsByPrj", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncJMProjectState::loadRstByPrj(
			ubigint refFmncMProject
			, const bool append
			, ListFmncJMProjectState& rst
		) {
	ubigint _refFmncMProject = htonl64(refFmncMProject);

	const char* vals[] = {
		(char*) &_refFmncMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMProjectState_loadRstByPrj", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

