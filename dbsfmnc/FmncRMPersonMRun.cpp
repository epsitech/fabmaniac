/**
  * \file FmncRMPersonMRun.cpp
  * database access for table TblFmncRMPersonMRun (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMPersonMRun.h"

/******************************************************************************
 class FmncRMPersonMRun
 ******************************************************************************/

FmncRMPersonMRun::FmncRMPersonMRun(
			const ubigint ref
			, const ubigint refFmncMPerson
			, const ubigint refFmncMRun
		) {

	this->ref = ref;
	this->refFmncMPerson = refFmncMPerson;
	this->refFmncMRun = refFmncMRun;
};

bool FmncRMPersonMRun::operator==(
			const FmncRMPersonMRun& comp
		) {
	return false;
};

bool FmncRMPersonMRun::operator!=(
			const FmncRMPersonMRun& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMPersonMRun
 ******************************************************************************/

ListFmncRMPersonMRun::ListFmncRMPersonMRun() {
};

ListFmncRMPersonMRun::ListFmncRMPersonMRun(
			const ListFmncRMPersonMRun& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMPersonMRun(*(src.nodes[i]));
};

ListFmncRMPersonMRun::~ListFmncRMPersonMRun() {
	clear();
};

void ListFmncRMPersonMRun::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMPersonMRun::size() const {
	return(nodes.size());
};

void ListFmncRMPersonMRun::append(
			FmncRMPersonMRun* rec
		) {
	nodes.push_back(rec);
};

FmncRMPersonMRun* ListFmncRMPersonMRun::operator[](
			const uint ix
		) {
	FmncRMPersonMRun* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMPersonMRun& ListFmncRMPersonMRun::operator=(
			const ListFmncRMPersonMRun& src
		) {
	FmncRMPersonMRun* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMPersonMRun(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMPersonMRun::operator==(
			const ListFmncRMPersonMRun& comp
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

bool ListFmncRMPersonMRun::operator!=(
			const ListFmncRMPersonMRun& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMPersonMRun
 ******************************************************************************/

TblFmncRMPersonMRun::TblFmncRMPersonMRun() {
};

TblFmncRMPersonMRun::~TblFmncRMPersonMRun() {
};

bool TblFmncRMPersonMRun::loadRecBySQL(
			const string& sqlstr
			, FmncRMPersonMRun** rec
		) {
	return false;
};

ubigint TblFmncRMPersonMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMPersonMRun& rst
		) {
	return 0;
};

void TblFmncRMPersonMRun::insertRec(
			FmncRMPersonMRun* rec
		) {
};

ubigint TblFmncRMPersonMRun::insertNewRec(
			FmncRMPersonMRun** rec
			, const ubigint refFmncMPerson
			, const ubigint refFmncMRun
		) {
	ubigint retval = 0;
	FmncRMPersonMRun* _rec = NULL;

	_rec = new FmncRMPersonMRun(0, refFmncMPerson, refFmncMRun);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMPersonMRun::appendNewRecToRst(
			ListFmncRMPersonMRun& rst
			, FmncRMPersonMRun** rec
			, const ubigint refFmncMPerson
			, const ubigint refFmncMRun
		) {
	ubigint retval = 0;
	FmncRMPersonMRun* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMPerson, refFmncMRun);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMPersonMRun::insertRst(
			ListFmncRMPersonMRun& rst
			, bool transact
		) {
};

void TblFmncRMPersonMRun::updateRec(
			FmncRMPersonMRun* rec
		) {
};

void TblFmncRMPersonMRun::updateRst(
			ListFmncRMPersonMRun& rst
			, bool transact
		) {
};

void TblFmncRMPersonMRun::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMPersonMRun::loadRecByRef(
			ubigint ref
			, FmncRMPersonMRun** rec
		) {
	return false;
};

ubigint TblFmncRMPersonMRun::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncRMPersonMRun::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMPersonMRun& rst
		) {
	ubigint numload = 0;
	FmncRMPersonMRun* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMPersonMRun
 ******************************************************************************/

MyTblFmncRMPersonMRun::MyTblFmncRMPersonMRun() : TblFmncRMPersonMRun(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMPersonMRun::~MyTblFmncRMPersonMRun() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMPersonMRun::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMPersonMRun (refFmncMPerson, refFmncMRun) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMPersonMRun SET refFmncMPerson = ?, refFmncMRun = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMPersonMRun WHERE ref = ?", false);
};

bool MyTblFmncRMPersonMRun::loadRecBySQL(
			const string& sqlstr
			, FmncRMPersonMRun** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMPersonMRun* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMPersonMRun / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMPersonMRun();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMPerson = atoll((char*) dbrow[1]); else _rec->refFmncMPerson = 0;
		if (dbrow[2]) _rec->refFmncMRun = atoll((char*) dbrow[2]); else _rec->refFmncMRun = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMPersonMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMPersonMRun& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMPersonMRun* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMPersonMRun / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMPersonMRun();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMPerson = atoll((char*) dbrow[1]); else rec->refFmncMPerson = 0;
			if (dbrow[2]) rec->refFmncMRun = atoll((char*) dbrow[2]); else rec->refFmncMRun = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMPersonMRun::insertRec(
			FmncRMPersonMRun* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMRun,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMPersonMRun / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMPersonMRun / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMPersonMRun::insertRst(
			ListFmncRMPersonMRun& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMPersonMRun::updateRec(
			FmncRMPersonMRun* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMRun,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMPersonMRun / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMPersonMRun / stmtUpdateRec)\n");
};

void MyTblFmncRMPersonMRun::updateRst(
			ListFmncRMPersonMRun& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMPersonMRun::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMPersonMRun / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMPersonMRun / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMPersonMRun::loadRecByRef(
			ubigint ref
			, FmncRMPersonMRun** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMPersonMRun WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMPersonMRun::loadRefsByRun(
			ubigint refFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncRMPersonMRun WHERE refFmncMRun = " + to_string(refFmncMRun) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMPersonMRun
 ******************************************************************************/

PgTblFmncRMPersonMRun::PgTblFmncRMPersonMRun() : TblFmncRMPersonMRun(), PgTable() {
};

PgTblFmncRMPersonMRun::~PgTblFmncRMPersonMRun() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMPersonMRun::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMPersonMRun_insertRec", "INSERT INTO TblFmncRMPersonMRun (refFmncMPerson, refFmncMRun) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMPersonMRun_updateRec", "UPDATE TblFmncRMPersonMRun SET refFmncMPerson = $1, refFmncMRun = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMPersonMRun_removeRecByRef", "DELETE FROM TblFmncRMPersonMRun WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMPersonMRun_loadRecByRef", "SELECT ref, refFmncMPerson, refFmncMRun FROM TblFmncRMPersonMRun WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMPersonMRun_loadRefsByRun", "SELECT ref FROM TblFmncRMPersonMRun WHERE refFmncMRun = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMPersonMRun::loadRec(
			PGresult* res
			, FmncRMPersonMRun** rec
		) {
	char* ptr;

	FmncRMPersonMRun* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMPersonMRun();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "reffmncmrun")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMRun = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMPersonMRun::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMPersonMRun& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMPersonMRun* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "reffmncmrun")
		};

		while (numread < numrow) {
			rec = new FmncRMPersonMRun();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMRun = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMPersonMRun::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMPersonMRun** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMPersonMRun / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMPersonMRun::loadRecBySQL(
			const string& sqlstr
			, FmncRMPersonMRun** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMPersonMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMPersonMRun& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMPersonMRun::insertRec(
			FmncRMPersonMRun* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refFmncMRun = htonl64(rec->refFmncMRun);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_refFmncMRun
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMPersonMRun_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMPersonMRun_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMPersonMRun::insertRst(
			ListFmncRMPersonMRun& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMPersonMRun::updateRec(
			FmncRMPersonMRun* rec
		) {
	PGresult* res;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refFmncMRun = htonl64(rec->refFmncMRun);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_refFmncMRun,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMPersonMRun_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMPersonMRun_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMPersonMRun::updateRst(
			ListFmncRMPersonMRun& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMPersonMRun::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMPersonMRun_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMPersonMRun_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMPersonMRun::loadRecByRef(
			ubigint ref
			, FmncRMPersonMRun** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMPersonMRun_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMPersonMRun::loadRefsByRun(
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

	return loadRefsByStmt("TblFmncRMPersonMRun_loadRefsByRun", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

