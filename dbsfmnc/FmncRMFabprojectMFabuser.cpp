/**
  * \file FmncRMFabprojectMFabuser.cpp
  * database access for table TblFmncRMFabprojectMFabuser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMFabprojectMFabuser.h"

/******************************************************************************
 class FmncRMFabprojectMFabuser
 ******************************************************************************/

FmncRMFabprojectMFabuser::FmncRMFabprojectMFabuser(
			const ubigint ref
			, const ubigint refFmncMFabproject
			, const ubigint refFmncMFabuser
		) {

	this->ref = ref;
	this->refFmncMFabproject = refFmncMFabproject;
	this->refFmncMFabuser = refFmncMFabuser;
};

bool FmncRMFabprojectMFabuser::operator==(
			const FmncRMFabprojectMFabuser& comp
		) {
	return false;
};

bool FmncRMFabprojectMFabuser::operator!=(
			const FmncRMFabprojectMFabuser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMFabprojectMFabuser
 ******************************************************************************/

ListFmncRMFabprojectMFabuser::ListFmncRMFabprojectMFabuser() {
};

ListFmncRMFabprojectMFabuser::ListFmncRMFabprojectMFabuser(
			const ListFmncRMFabprojectMFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMFabprojectMFabuser(*(src.nodes[i]));
};

ListFmncRMFabprojectMFabuser::~ListFmncRMFabprojectMFabuser() {
	clear();
};

void ListFmncRMFabprojectMFabuser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMFabprojectMFabuser::size() const {
	return(nodes.size());
};

void ListFmncRMFabprojectMFabuser::append(
			FmncRMFabprojectMFabuser* rec
		) {
	nodes.push_back(rec);
};

FmncRMFabprojectMFabuser* ListFmncRMFabprojectMFabuser::operator[](
			const uint ix
		) {
	FmncRMFabprojectMFabuser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMFabprojectMFabuser& ListFmncRMFabprojectMFabuser::operator=(
			const ListFmncRMFabprojectMFabuser& src
		) {
	FmncRMFabprojectMFabuser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMFabprojectMFabuser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMFabprojectMFabuser::operator==(
			const ListFmncRMFabprojectMFabuser& comp
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

bool ListFmncRMFabprojectMFabuser::operator!=(
			const ListFmncRMFabprojectMFabuser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMFabprojectMFabuser
 ******************************************************************************/

TblFmncRMFabprojectMFabuser::TblFmncRMFabprojectMFabuser() {
};

TblFmncRMFabprojectMFabuser::~TblFmncRMFabprojectMFabuser() {
};

bool TblFmncRMFabprojectMFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabprojectMFabuser** rec
		) {
	return false;
};

ubigint TblFmncRMFabprojectMFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabprojectMFabuser& rst
		) {
	return 0;
};

void TblFmncRMFabprojectMFabuser::insertRec(
			FmncRMFabprojectMFabuser* rec
		) {
};

ubigint TblFmncRMFabprojectMFabuser::insertNewRec(
			FmncRMFabprojectMFabuser** rec
			, const ubigint refFmncMFabproject
			, const ubigint refFmncMFabuser
		) {
	ubigint retval = 0;
	FmncRMFabprojectMFabuser* _rec = NULL;

	_rec = new FmncRMFabprojectMFabuser(0, refFmncMFabproject, refFmncMFabuser);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMFabprojectMFabuser::appendNewRecToRst(
			ListFmncRMFabprojectMFabuser& rst
			, FmncRMFabprojectMFabuser** rec
			, const ubigint refFmncMFabproject
			, const ubigint refFmncMFabuser
		) {
	ubigint retval = 0;
	FmncRMFabprojectMFabuser* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMFabproject, refFmncMFabuser);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMFabprojectMFabuser::insertRst(
			ListFmncRMFabprojectMFabuser& rst
			, bool transact
		) {
};

void TblFmncRMFabprojectMFabuser::updateRec(
			FmncRMFabprojectMFabuser* rec
		) {
};

void TblFmncRMFabprojectMFabuser::updateRst(
			ListFmncRMFabprojectMFabuser& rst
			, bool transact
		) {
};

void TblFmncRMFabprojectMFabuser::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMFabprojectMFabuser::loadRecByRef(
			ubigint ref
			, FmncRMFabprojectMFabuser** rec
		) {
	return false;
};

ubigint TblFmncRMFabprojectMFabuser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMFabprojectMFabuser& rst
		) {
	ubigint numload = 0;
	FmncRMFabprojectMFabuser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMFabprojectMFabuser
 ******************************************************************************/

MyTblFmncRMFabprojectMFabuser::MyTblFmncRMFabprojectMFabuser() : TblFmncRMFabprojectMFabuser(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMFabprojectMFabuser::~MyTblFmncRMFabprojectMFabuser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMFabprojectMFabuser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMFabprojectMFabuser (refFmncMFabproject, refFmncMFabuser) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMFabprojectMFabuser SET refFmncMFabproject = ?, refFmncMFabuser = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMFabprojectMFabuser WHERE ref = ?", false);
};

bool MyTblFmncRMFabprojectMFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabprojectMFabuser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMFabprojectMFabuser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFabprojectMFabuser / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMFabprojectMFabuser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMFabproject = atoll((char*) dbrow[1]); else _rec->refFmncMFabproject = 0;
		if (dbrow[2]) _rec->refFmncMFabuser = atoll((char*) dbrow[2]); else _rec->refFmncMFabuser = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMFabprojectMFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabprojectMFabuser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMFabprojectMFabuser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFabprojectMFabuser / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMFabprojectMFabuser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMFabproject = atoll((char*) dbrow[1]); else rec->refFmncMFabproject = 0;
			if (dbrow[2]) rec->refFmncMFabuser = atoll((char*) dbrow[2]); else rec->refFmncMFabuser = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMFabprojectMFabuser::insertRec(
			FmncRMFabprojectMFabuser* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFabproject,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMFabuser,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabprojectMFabuser / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabprojectMFabuser / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMFabprojectMFabuser::insertRst(
			ListFmncRMFabprojectMFabuser& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMFabprojectMFabuser::updateRec(
			FmncRMFabprojectMFabuser* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFabproject,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMFabuser,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabprojectMFabuser / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabprojectMFabuser / stmtUpdateRec)\n");
};

void MyTblFmncRMFabprojectMFabuser::updateRst(
			ListFmncRMFabprojectMFabuser& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMFabprojectMFabuser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabprojectMFabuser / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabprojectMFabuser / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMFabprojectMFabuser::loadRecByRef(
			ubigint ref
			, FmncRMFabprojectMFabuser** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMFabprojectMFabuser WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMFabprojectMFabuser
 ******************************************************************************/

PgTblFmncRMFabprojectMFabuser::PgTblFmncRMFabprojectMFabuser() : TblFmncRMFabprojectMFabuser(), PgTable() {
};

PgTblFmncRMFabprojectMFabuser::~PgTblFmncRMFabprojectMFabuser() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMFabprojectMFabuser::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMFabprojectMFabuser_insertRec", "INSERT INTO TblFmncRMFabprojectMFabuser (refFmncMFabproject, refFmncMFabuser) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFabprojectMFabuser_updateRec", "UPDATE TblFmncRMFabprojectMFabuser SET refFmncMFabproject = $1, refFmncMFabuser = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFabprojectMFabuser_removeRecByRef", "DELETE FROM TblFmncRMFabprojectMFabuser WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMFabprojectMFabuser_loadRecByRef", "SELECT ref, refFmncMFabproject, refFmncMFabuser FROM TblFmncRMFabprojectMFabuser WHERE ref = $1", 1, NULL);
};

bool PgTblFmncRMFabprojectMFabuser::loadRec(
			PGresult* res
			, FmncRMFabprojectMFabuser** rec
		) {
	char* ptr;

	FmncRMFabprojectMFabuser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMFabprojectMFabuser();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "reffmncmfabuser")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMFabuser = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMFabprojectMFabuser::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMFabprojectMFabuser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMFabprojectMFabuser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "reffmncmfabuser")
		};

		while (numread < numrow) {
			rec = new FmncRMFabprojectMFabuser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMFabuser = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMFabprojectMFabuser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMFabprojectMFabuser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabprojectMFabuser / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMFabprojectMFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabprojectMFabuser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMFabprojectMFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabprojectMFabuser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMFabprojectMFabuser::insertRec(
			FmncRMFabprojectMFabuser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	ubigint _refFmncMFabuser = htonl64(rec->refFmncMFabuser);

	const char* vals[] = {
		(char*) &_refFmncMFabproject,
		(char*) &_refFmncMFabuser
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFabprojectMFabuser_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabprojectMFabuser_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMFabprojectMFabuser::insertRst(
			ListFmncRMFabprojectMFabuser& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMFabprojectMFabuser::updateRec(
			FmncRMFabprojectMFabuser* rec
		) {
	PGresult* res;

	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	ubigint _refFmncMFabuser = htonl64(rec->refFmncMFabuser);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMFabproject,
		(char*) &_refFmncMFabuser,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFabprojectMFabuser_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabprojectMFabuser_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMFabprojectMFabuser::updateRst(
			ListFmncRMFabprojectMFabuser& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMFabprojectMFabuser::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMFabprojectMFabuser_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabprojectMFabuser_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMFabprojectMFabuser::loadRecByRef(
			ubigint ref
			, FmncRMFabprojectMFabuser** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMFabprojectMFabuser_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

