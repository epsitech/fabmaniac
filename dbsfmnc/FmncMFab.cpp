/**
  * \file FmncMFab.cpp
  * database access for table TblFmncMFab (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMFab.h"

/******************************************************************************
 class FmncMFab
 ******************************************************************************/

FmncMFab::FmncMFab(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refFmncMOrg = refFmncMOrg;
};

bool FmncMFab::operator==(
			const FmncMFab& comp
		) {
	return false;
};

bool FmncMFab::operator!=(
			const FmncMFab& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMFab
 ******************************************************************************/

ListFmncMFab::ListFmncMFab() {
};

ListFmncMFab::ListFmncMFab(
			const ListFmncMFab& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMFab(*(src.nodes[i]));
};

ListFmncMFab::~ListFmncMFab() {
	clear();
};

void ListFmncMFab::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMFab::size() const {
	return(nodes.size());
};

void ListFmncMFab::append(
			FmncMFab* rec
		) {
	nodes.push_back(rec);
};

FmncMFab* ListFmncMFab::operator[](
			const uint ix
		) {
	FmncMFab* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMFab& ListFmncMFab::operator=(
			const ListFmncMFab& src
		) {
	FmncMFab* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMFab(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMFab::operator==(
			const ListFmncMFab& comp
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

bool ListFmncMFab::operator!=(
			const ListFmncMFab& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMFab
 ******************************************************************************/

TblFmncMFab::TblFmncMFab() {
};

TblFmncMFab::~TblFmncMFab() {
};

bool TblFmncMFab::loadRecBySQL(
			const string& sqlstr
			, FmncMFab** rec
		) {
	return false;
};

ubigint TblFmncMFab::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFab& rst
		) {
	return 0;
};

void TblFmncMFab::insertRec(
			FmncMFab* rec
		) {
};

ubigint TblFmncMFab::insertNewRec(
			FmncMFab** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
		) {
	ubigint retval = 0;
	FmncMFab* _rec = NULL;

	_rec = new FmncMFab(0, grp, own, refFmncMOrg);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMFab::appendNewRecToRst(
			ListFmncMFab& rst
			, FmncMFab** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
		) {
	ubigint retval = 0;
	FmncMFab* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refFmncMOrg);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMFab::insertRst(
			ListFmncMFab& rst
			, bool transact
		) {
};

void TblFmncMFab::updateRec(
			FmncMFab* rec
		) {
};

void TblFmncMFab::updateRst(
			ListFmncMFab& rst
			, bool transact
		) {
};

void TblFmncMFab::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMFab::loadRecByRef(
			ubigint ref
			, FmncMFab** rec
		) {
	return false;
};

ubigint TblFmncMFab::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMFab& rst
		) {
	ubigint numload = 0;
	FmncMFab* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMFab
 ******************************************************************************/

MyTblFmncMFab::MyTblFmncMFab() : TblFmncMFab(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMFab::~MyTblFmncMFab() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMFab::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMFab (grp, own, refFmncMOrg) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMFab SET grp = ?, own = ?, refFmncMOrg = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMFab WHERE ref = ?", false);
};

bool MyTblFmncMFab::loadRecBySQL(
			const string& sqlstr
			, FmncMFab** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMFab* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMFab / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMFab();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refFmncMOrg = atoll((char*) dbrow[3]); else _rec->refFmncMOrg = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMFab::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFab& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMFab* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMFab / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMFab();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refFmncMOrg = atoll((char*) dbrow[3]); else rec->refFmncMOrg = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMFab::insertRec(
			FmncMFab* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMOrg,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFab / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFab / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMFab::insertRst(
			ListFmncMFab& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMFab::updateRec(
			FmncMFab* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMOrg,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFab / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFab / stmtUpdateRec)\n");
};

void MyTblFmncMFab::updateRst(
			ListFmncMFab& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMFab::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFab / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFab / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMFab::loadRecByRef(
			ubigint ref
			, FmncMFab** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMFab WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMFab
 ******************************************************************************/

PgTblFmncMFab::PgTblFmncMFab() : TblFmncMFab(), PgTable() {
};

PgTblFmncMFab::~PgTblFmncMFab() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMFab::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMFab_insertRec", "INSERT INTO TblFmncMFab (grp, own, refFmncMOrg) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMFab_updateRec", "UPDATE TblFmncMFab SET grp = $1, own = $2, refFmncMOrg = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMFab_removeRecByRef", "DELETE FROM TblFmncMFab WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMFab_loadRecByRef", "SELECT ref, grp, own, refFmncMOrg FROM TblFmncMFab WHERE ref = $1", 1, NULL);
};

bool PgTblFmncMFab::loadRec(
			PGresult* res
			, FmncMFab** rec
		) {
	char* ptr;

	FmncMFab* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMFab();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmorg")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMOrg = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMFab::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMFab& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMFab* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmorg")
		};

		while (numread < numrow) {
			rec = new FmncMFab();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMOrg = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMFab::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMFab** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFab / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMFab::loadRecBySQL(
			const string& sqlstr
			, FmncMFab** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMFab::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFab& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMFab::insertRec(
			FmncMFab* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMOrg
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncMFab_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFab_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMFab::insertRst(
			ListFmncMFab& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMFab::updateRec(
			FmncMFab* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMOrg,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncMFab_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFab_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMFab::updateRst(
			ListFmncMFab& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMFab::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMFab_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFab_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMFab::loadRecByRef(
			ubigint ref
			, FmncMFab** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMFab_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

