/**
  * \file FmncSvcRMOrgMTool.cpp
  * database access for table TblFmncSvcRMOrgMTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncSvcRMOrgMTool.h"

/******************************************************************************
 class FmncSvcRMOrgMTool
 ******************************************************************************/

FmncSvcRMOrgMTool::FmncSvcRMOrgMTool(
			const ubigint ref
			, const ubigint refFmncMOrg
			, const ubigint refFmncMTool
		) {

	this->ref = ref;
	this->refFmncMOrg = refFmncMOrg;
	this->refFmncMTool = refFmncMTool;
};

bool FmncSvcRMOrgMTool::operator==(
			const FmncSvcRMOrgMTool& comp
		) {
	return false;
};

bool FmncSvcRMOrgMTool::operator!=(
			const FmncSvcRMOrgMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncSvcRMOrgMTool
 ******************************************************************************/

ListFmncSvcRMOrgMTool::ListFmncSvcRMOrgMTool() {
};

ListFmncSvcRMOrgMTool::ListFmncSvcRMOrgMTool(
			const ListFmncSvcRMOrgMTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncSvcRMOrgMTool(*(src.nodes[i]));
};

ListFmncSvcRMOrgMTool::~ListFmncSvcRMOrgMTool() {
	clear();
};

void ListFmncSvcRMOrgMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncSvcRMOrgMTool::size() const {
	return(nodes.size());
};

void ListFmncSvcRMOrgMTool::append(
			FmncSvcRMOrgMTool* rec
		) {
	nodes.push_back(rec);
};

FmncSvcRMOrgMTool* ListFmncSvcRMOrgMTool::operator[](
			const uint ix
		) {
	FmncSvcRMOrgMTool* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncSvcRMOrgMTool& ListFmncSvcRMOrgMTool::operator=(
			const ListFmncSvcRMOrgMTool& src
		) {
	FmncSvcRMOrgMTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncSvcRMOrgMTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncSvcRMOrgMTool::operator==(
			const ListFmncSvcRMOrgMTool& comp
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

bool ListFmncSvcRMOrgMTool::operator!=(
			const ListFmncSvcRMOrgMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncSvcRMOrgMTool
 ******************************************************************************/

TblFmncSvcRMOrgMTool::TblFmncSvcRMOrgMTool() {
};

TblFmncSvcRMOrgMTool::~TblFmncSvcRMOrgMTool() {
};

bool TblFmncSvcRMOrgMTool::loadRecBySQL(
			const string& sqlstr
			, FmncSvcRMOrgMTool** rec
		) {
	return false;
};

ubigint TblFmncSvcRMOrgMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncSvcRMOrgMTool& rst
		) {
	return 0;
};

void TblFmncSvcRMOrgMTool::insertRec(
			FmncSvcRMOrgMTool* rec
		) {
};

ubigint TblFmncSvcRMOrgMTool::insertNewRec(
			FmncSvcRMOrgMTool** rec
			, const ubigint refFmncMOrg
			, const ubigint refFmncMTool
		) {
	ubigint retval = 0;
	FmncSvcRMOrgMTool* _rec = NULL;

	_rec = new FmncSvcRMOrgMTool(0, refFmncMOrg, refFmncMTool);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncSvcRMOrgMTool::appendNewRecToRst(
			ListFmncSvcRMOrgMTool& rst
			, FmncSvcRMOrgMTool** rec
			, const ubigint refFmncMOrg
			, const ubigint refFmncMTool
		) {
	ubigint retval = 0;
	FmncSvcRMOrgMTool* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMOrg, refFmncMTool);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncSvcRMOrgMTool::insertRst(
			ListFmncSvcRMOrgMTool& rst
			, bool transact
		) {
};

void TblFmncSvcRMOrgMTool::updateRec(
			FmncSvcRMOrgMTool* rec
		) {
};

void TblFmncSvcRMOrgMTool::updateRst(
			ListFmncSvcRMOrgMTool& rst
			, bool transact
		) {
};

void TblFmncSvcRMOrgMTool::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncSvcRMOrgMTool::loadRecByRef(
			ubigint ref
			, FmncSvcRMOrgMTool** rec
		) {
	return false;
};

ubigint TblFmncSvcRMOrgMTool::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncSvcRMOrgMTool::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncSvcRMOrgMTool& rst
		) {
	ubigint numload = 0;
	FmncSvcRMOrgMTool* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncSvcRMOrgMTool
 ******************************************************************************/

MyTblFmncSvcRMOrgMTool::MyTblFmncSvcRMOrgMTool() : TblFmncSvcRMOrgMTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncSvcRMOrgMTool::~MyTblFmncSvcRMOrgMTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncSvcRMOrgMTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncSvcRMOrgMTool (refFmncMOrg, refFmncMTool) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncSvcRMOrgMTool SET refFmncMOrg = ?, refFmncMTool = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncSvcRMOrgMTool WHERE ref = ?", false);
};

bool MyTblFmncSvcRMOrgMTool::loadRecBySQL(
			const string& sqlstr
			, FmncSvcRMOrgMTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncSvcRMOrgMTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncSvcRMOrgMTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncSvcRMOrgMTool();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMOrg = atoll((char*) dbrow[1]); else _rec->refFmncMOrg = 0;
		if (dbrow[2]) _rec->refFmncMTool = atoll((char*) dbrow[2]); else _rec->refFmncMTool = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncSvcRMOrgMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncSvcRMOrgMTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncSvcRMOrgMTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncSvcRMOrgMTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncSvcRMOrgMTool();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMOrg = atoll((char*) dbrow[1]); else rec->refFmncMOrg = 0;
			if (dbrow[2]) rec->refFmncMTool = atoll((char*) dbrow[2]); else rec->refFmncMTool = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncSvcRMOrgMTool::insertRec(
			FmncSvcRMOrgMTool* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMOrg,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMTool,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncSvcRMOrgMTool / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncSvcRMOrgMTool / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncSvcRMOrgMTool::insertRst(
			ListFmncSvcRMOrgMTool& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncSvcRMOrgMTool::updateRec(
			FmncSvcRMOrgMTool* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMOrg,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMTool,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncSvcRMOrgMTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncSvcRMOrgMTool / stmtUpdateRec)\n");
};

void MyTblFmncSvcRMOrgMTool::updateRst(
			ListFmncSvcRMOrgMTool& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncSvcRMOrgMTool::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncSvcRMOrgMTool / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncSvcRMOrgMTool / stmtRemoveRecByRef)\n");
};

bool MyTblFmncSvcRMOrgMTool::loadRecByRef(
			ubigint ref
			, FmncSvcRMOrgMTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncSvcRMOrgMTool WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncSvcRMOrgMTool::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncSvcRMOrgMTool WHERE refFmncMTool = " + to_string(refFmncMTool) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncSvcRMOrgMTool
 ******************************************************************************/

PgTblFmncSvcRMOrgMTool::PgTblFmncSvcRMOrgMTool() : TblFmncSvcRMOrgMTool(), PgTable() {
};

PgTblFmncSvcRMOrgMTool::~PgTblFmncSvcRMOrgMTool() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncSvcRMOrgMTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncSvcRMOrgMTool_insertRec", "INSERT INTO TblFmncSvcRMOrgMTool (refFmncMOrg, refFmncMTool) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncSvcRMOrgMTool_updateRec", "UPDATE TblFmncSvcRMOrgMTool SET refFmncMOrg = $1, refFmncMTool = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncSvcRMOrgMTool_removeRecByRef", "DELETE FROM TblFmncSvcRMOrgMTool WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncSvcRMOrgMTool_loadRecByRef", "SELECT ref, refFmncMOrg, refFmncMTool FROM TblFmncSvcRMOrgMTool WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncSvcRMOrgMTool_loadRefsByTol", "SELECT ref FROM TblFmncSvcRMOrgMTool WHERE refFmncMTool = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncSvcRMOrgMTool::loadRec(
			PGresult* res
			, FmncSvcRMOrgMTool** rec
		) {
	char* ptr;

	FmncSvcRMOrgMTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncSvcRMOrgMTool();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmtool")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMTool = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncSvcRMOrgMTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncSvcRMOrgMTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncSvcRMOrgMTool* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmtool")
		};

		while (numread < numrow) {
			rec = new FmncSvcRMOrgMTool();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMTool = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncSvcRMOrgMTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncSvcRMOrgMTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcRMOrgMTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncSvcRMOrgMTool::loadRecBySQL(
			const string& sqlstr
			, FmncSvcRMOrgMTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncSvcRMOrgMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncSvcRMOrgMTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncSvcRMOrgMTool::insertRec(
			FmncSvcRMOrgMTool* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);

	const char* vals[] = {
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMTool
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncSvcRMOrgMTool_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcRMOrgMTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncSvcRMOrgMTool::insertRst(
			ListFmncSvcRMOrgMTool& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncSvcRMOrgMTool::updateRec(
			FmncSvcRMOrgMTool* rec
		) {
	PGresult* res;

	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMTool,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncSvcRMOrgMTool_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcRMOrgMTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncSvcRMOrgMTool::updateRst(
			ListFmncSvcRMOrgMTool& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncSvcRMOrgMTool::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncSvcRMOrgMTool_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcRMOrgMTool_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncSvcRMOrgMTool::loadRecByRef(
			ubigint ref
			, FmncSvcRMOrgMTool** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncSvcRMOrgMTool_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncSvcRMOrgMTool::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMTool = htonl64(refFmncMTool);

	const char* vals[] = {
		(char*) &_refFmncMTool
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncSvcRMOrgMTool_loadRefsByTol", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

