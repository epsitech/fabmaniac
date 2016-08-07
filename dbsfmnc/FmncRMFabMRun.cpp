/**
  * \file FmncRMFabMRun.cpp
  * database access for table TblFmncRMFabMRun (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMFabMRun.h"

/******************************************************************************
 class FmncRMFabMRun
 ******************************************************************************/

FmncRMFabMRun::FmncRMFabMRun(
			const ubigint ref
			, const ubigint refFmncMFab
			, const ubigint refFmncMRun
		) {

	this->ref = ref;
	this->refFmncMFab = refFmncMFab;
	this->refFmncMRun = refFmncMRun;
};

bool FmncRMFabMRun::operator==(
			const FmncRMFabMRun& comp
		) {
	return false;
};

bool FmncRMFabMRun::operator!=(
			const FmncRMFabMRun& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMFabMRun
 ******************************************************************************/

ListFmncRMFabMRun::ListFmncRMFabMRun() {
};

ListFmncRMFabMRun::ListFmncRMFabMRun(
			const ListFmncRMFabMRun& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMFabMRun(*(src.nodes[i]));
};

ListFmncRMFabMRun::~ListFmncRMFabMRun() {
	clear();
};

void ListFmncRMFabMRun::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMFabMRun::size() const {
	return(nodes.size());
};

void ListFmncRMFabMRun::append(
			FmncRMFabMRun* rec
		) {
	nodes.push_back(rec);
};

FmncRMFabMRun* ListFmncRMFabMRun::operator[](
			const uint ix
		) {
	FmncRMFabMRun* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMFabMRun& ListFmncRMFabMRun::operator=(
			const ListFmncRMFabMRun& src
		) {
	FmncRMFabMRun* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMFabMRun(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMFabMRun::operator==(
			const ListFmncRMFabMRun& comp
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

bool ListFmncRMFabMRun::operator!=(
			const ListFmncRMFabMRun& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMFabMRun
 ******************************************************************************/

TblFmncRMFabMRun::TblFmncRMFabMRun() {
};

TblFmncRMFabMRun::~TblFmncRMFabMRun() {
};

bool TblFmncRMFabMRun::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabMRun** rec
		) {
	return false;
};

ubigint TblFmncRMFabMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabMRun& rst
		) {
	return 0;
};

void TblFmncRMFabMRun::insertRec(
			FmncRMFabMRun* rec
		) {
};

ubigint TblFmncRMFabMRun::insertNewRec(
			FmncRMFabMRun** rec
			, const ubigint refFmncMFab
			, const ubigint refFmncMRun
		) {
	ubigint retval = 0;
	FmncRMFabMRun* _rec = NULL;

	_rec = new FmncRMFabMRun(0, refFmncMFab, refFmncMRun);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMFabMRun::appendNewRecToRst(
			ListFmncRMFabMRun& rst
			, FmncRMFabMRun** rec
			, const ubigint refFmncMFab
			, const ubigint refFmncMRun
		) {
	ubigint retval = 0;
	FmncRMFabMRun* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMFab, refFmncMRun);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMFabMRun::insertRst(
			ListFmncRMFabMRun& rst
			, bool transact
		) {
};

void TblFmncRMFabMRun::updateRec(
			FmncRMFabMRun* rec
		) {
};

void TblFmncRMFabMRun::updateRst(
			ListFmncRMFabMRun& rst
			, bool transact
		) {
};

void TblFmncRMFabMRun::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMFabMRun::loadRecByRef(
			ubigint ref
			, FmncRMFabMRun** rec
		) {
	return false;
};

ubigint TblFmncRMFabMRun::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncRMFabMRun::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMFabMRun& rst
		) {
	ubigint numload = 0;
	FmncRMFabMRun* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMFabMRun
 ******************************************************************************/

MyTblFmncRMFabMRun::MyTblFmncRMFabMRun() : TblFmncRMFabMRun(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMFabMRun::~MyTblFmncRMFabMRun() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMFabMRun::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMFabMRun (refFmncMFab, refFmncMRun) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMFabMRun SET refFmncMFab = ?, refFmncMRun = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMFabMRun WHERE ref = ?", false);
};

bool MyTblFmncRMFabMRun::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabMRun** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMFabMRun* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFabMRun / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMFabMRun();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMFab = atoll((char*) dbrow[1]); else _rec->refFmncMFab = 0;
		if (dbrow[2]) _rec->refFmncMRun = atoll((char*) dbrow[2]); else _rec->refFmncMRun = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMFabMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabMRun& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMFabMRun* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFabMRun / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMFabMRun();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMFab = atoll((char*) dbrow[1]); else rec->refFmncMFab = 0;
			if (dbrow[2]) rec->refFmncMRun = atoll((char*) dbrow[2]); else rec->refFmncMRun = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMFabMRun::insertRec(
			FmncRMFabMRun* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFab,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMRun,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabMRun / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabMRun / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMFabMRun::insertRst(
			ListFmncRMFabMRun& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMFabMRun::updateRec(
			FmncRMFabMRun* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFab,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMRun,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabMRun / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabMRun / stmtUpdateRec)\n");
};

void MyTblFmncRMFabMRun::updateRst(
			ListFmncRMFabMRun& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMFabMRun::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabMRun / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabMRun / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMFabMRun::loadRecByRef(
			ubigint ref
			, FmncRMFabMRun** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMFabMRun WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMFabMRun::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncRMFabMRun WHERE refFmncMRun = " + to_string(refFmncMRun) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMFabMRun
 ******************************************************************************/

PgTblFmncRMFabMRun::PgTblFmncRMFabMRun() : TblFmncRMFabMRun(), PgTable() {
};

PgTblFmncRMFabMRun::~PgTblFmncRMFabMRun() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMFabMRun::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMFabMRun_insertRec", "INSERT INTO TblFmncRMFabMRun (refFmncMFab, refFmncMRun) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFabMRun_updateRec", "UPDATE TblFmncRMFabMRun SET refFmncMFab = $1, refFmncMRun = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFabMRun_removeRecByRef", "DELETE FROM TblFmncRMFabMRun WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMFabMRun_loadRecByRef", "SELECT ref, refFmncMFab, refFmncMRun FROM TblFmncRMFabMRun WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMFabMRun_loadRefsByRun", "SELECT ref FROM TblFmncRMFabMRun WHERE refFmncMRun = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMFabMRun::loadRec(
			PGresult* res
			, FmncRMFabMRun** rec
		) {
	char* ptr;

	FmncRMFabMRun* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMFabMRun();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "reffmncmrun")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMFab = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMRun = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMFabMRun::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMFabMRun& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMFabMRun* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "reffmncmrun")
		};

		while (numread < numrow) {
			rec = new FmncRMFabMRun();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMFab = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMRun = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMFabMRun::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMFabMRun** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabMRun / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMFabMRun::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabMRun** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMFabMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabMRun& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMFabMRun::insertRec(
			FmncRMFabMRun* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _refFmncMRun = htonl64(rec->refFmncMRun);

	const char* vals[] = {
		(char*) &_refFmncMFab,
		(char*) &_refFmncMRun
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFabMRun_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabMRun_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMFabMRun::insertRst(
			ListFmncRMFabMRun& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMFabMRun::updateRec(
			FmncRMFabMRun* rec
		) {
	PGresult* res;

	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _refFmncMRun = htonl64(rec->refFmncMRun);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMFab,
		(char*) &_refFmncMRun,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFabMRun_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabMRun_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMFabMRun::updateRst(
			ListFmncRMFabMRun& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMFabMRun::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMFabMRun_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabMRun_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMFabMRun::loadRecByRef(
			ubigint ref
			, FmncRMFabMRun** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMFabMRun_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMFabMRun::loadRefsByRun(
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

	return loadRefsByStmt("TblFmncRMFabMRun_loadRefsByRun", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

