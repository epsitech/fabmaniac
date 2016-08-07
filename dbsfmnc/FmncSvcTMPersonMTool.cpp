/**
  * \file FmncSvcTMPersonMTool.cpp
  * database access for table TblFmncSvcTMPersonMTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncSvcTMPersonMTool.h"

/******************************************************************************
 class FmncSvcTMPersonMTool
 ******************************************************************************/

FmncSvcTMPersonMTool::FmncSvcTMPersonMTool(
			const ubigint ref
			, const ubigint refFmncMPerson
			, const ubigint refR
		) {

	this->ref = ref;
	this->refFmncMPerson = refFmncMPerson;
	this->refR = refR;
};

bool FmncSvcTMPersonMTool::operator==(
			const FmncSvcTMPersonMTool& comp
		) {
	return false;
};

bool FmncSvcTMPersonMTool::operator!=(
			const FmncSvcTMPersonMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncSvcTMPersonMTool
 ******************************************************************************/

ListFmncSvcTMPersonMTool::ListFmncSvcTMPersonMTool() {
};

ListFmncSvcTMPersonMTool::ListFmncSvcTMPersonMTool(
			const ListFmncSvcTMPersonMTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncSvcTMPersonMTool(*(src.nodes[i]));
};

ListFmncSvcTMPersonMTool::~ListFmncSvcTMPersonMTool() {
	clear();
};

void ListFmncSvcTMPersonMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncSvcTMPersonMTool::size() const {
	return(nodes.size());
};

void ListFmncSvcTMPersonMTool::append(
			FmncSvcTMPersonMTool* rec
		) {
	nodes.push_back(rec);
};

FmncSvcTMPersonMTool* ListFmncSvcTMPersonMTool::operator[](
			const uint ix
		) {
	FmncSvcTMPersonMTool* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncSvcTMPersonMTool& ListFmncSvcTMPersonMTool::operator=(
			const ListFmncSvcTMPersonMTool& src
		) {
	FmncSvcTMPersonMTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncSvcTMPersonMTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncSvcTMPersonMTool::operator==(
			const ListFmncSvcTMPersonMTool& comp
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

bool ListFmncSvcTMPersonMTool::operator!=(
			const ListFmncSvcTMPersonMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncSvcTMPersonMTool
 ******************************************************************************/

TblFmncSvcTMPersonMTool::TblFmncSvcTMPersonMTool() {
};

TblFmncSvcTMPersonMTool::~TblFmncSvcTMPersonMTool() {
};

bool TblFmncSvcTMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncSvcTMPersonMTool** rec
		) {
	return false;
};

ubigint TblFmncSvcTMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	return 0;
};

void TblFmncSvcTMPersonMTool::insertRec(
			FmncSvcTMPersonMTool* rec
		) {
};

ubigint TblFmncSvcTMPersonMTool::insertNewRec(
			FmncSvcTMPersonMTool** rec
			, const ubigint refFmncMPerson
			, const ubigint refR
		) {
	ubigint retval = 0;
	FmncSvcTMPersonMTool* _rec = NULL;

	_rec = new FmncSvcTMPersonMTool(0, refFmncMPerson, refR);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncSvcTMPersonMTool::appendNewRecToRst(
			ListFmncSvcTMPersonMTool& rst
			, FmncSvcTMPersonMTool** rec
			, const ubigint refFmncMPerson
			, const ubigint refR
		) {
	ubigint retval = 0;
	FmncSvcTMPersonMTool* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMPerson, refR);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncSvcTMPersonMTool::insertRst(
			ListFmncSvcTMPersonMTool& rst
			, bool transact
		) {
};

void TblFmncSvcTMPersonMTool::updateRec(
			FmncSvcTMPersonMTool* rec
		) {
};

void TblFmncSvcTMPersonMTool::updateRst(
			ListFmncSvcTMPersonMTool& rst
			, bool transact
		) {
};

void TblFmncSvcTMPersonMTool::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncSvcTMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncSvcTMPersonMTool** rec
		) {
	return false;
};

ubigint TblFmncSvcTMPersonMTool::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncSvcTMPersonMTool::loadRstByR(
			ubigint refR
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	return 0;
};

ubigint TblFmncSvcTMPersonMTool::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	ubigint numload = 0;
	FmncSvcTMPersonMTool* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncSvcTMPersonMTool
 ******************************************************************************/

MyTblFmncSvcTMPersonMTool::MyTblFmncSvcTMPersonMTool() : TblFmncSvcTMPersonMTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncSvcTMPersonMTool::~MyTblFmncSvcTMPersonMTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncSvcTMPersonMTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncSvcTMPersonMTool (refFmncMPerson, refR) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncSvcTMPersonMTool SET refFmncMPerson = ?, refR = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncSvcTMPersonMTool WHERE ref = ?", false);
};

bool MyTblFmncSvcTMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncSvcTMPersonMTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncSvcTMPersonMTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncSvcTMPersonMTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncSvcTMPersonMTool();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMPerson = atoll((char*) dbrow[1]); else _rec->refFmncMPerson = 0;
		if (dbrow[2]) _rec->refR = atoll((char*) dbrow[2]); else _rec->refR = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncSvcTMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncSvcTMPersonMTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncSvcTMPersonMTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncSvcTMPersonMTool();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMPerson = atoll((char*) dbrow[1]); else rec->refFmncMPerson = 0;
			if (dbrow[2]) rec->refR = atoll((char*) dbrow[2]); else rec->refR = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncSvcTMPersonMTool::insertRec(
			FmncSvcTMPersonMTool* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refR,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncSvcTMPersonMTool / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncSvcTMPersonMTool / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncSvcTMPersonMTool::insertRst(
			ListFmncSvcTMPersonMTool& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncSvcTMPersonMTool::updateRec(
			FmncSvcTMPersonMTool* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refR,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncSvcTMPersonMTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncSvcTMPersonMTool / stmtUpdateRec)\n");
};

void MyTblFmncSvcTMPersonMTool::updateRst(
			ListFmncSvcTMPersonMTool& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncSvcTMPersonMTool::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncSvcTMPersonMTool / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncSvcTMPersonMTool / stmtRemoveRecByRef)\n");
};

bool MyTblFmncSvcTMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncSvcTMPersonMTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncSvcTMPersonMTool WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncSvcTMPersonMTool::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncSvcTMPersonMTool WHERE refR = " + to_string(refR) + "", append, refs);
};

ubigint MyTblFmncSvcTMPersonMTool::loadRstByR(
			ubigint refR
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMPerson, refR FROM TblFmncSvcTMPersonMTool WHERE refR = " + to_string(refR) + " ORDER BY refFmncMPerson ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncSvcTMPersonMTool
 ******************************************************************************/

PgTblFmncSvcTMPersonMTool::PgTblFmncSvcTMPersonMTool() : TblFmncSvcTMPersonMTool(), PgTable() {
};

PgTblFmncSvcTMPersonMTool::~PgTblFmncSvcTMPersonMTool() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncSvcTMPersonMTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncSvcTMPersonMTool_insertRec", "INSERT INTO TblFmncSvcTMPersonMTool (refFmncMPerson, refR) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncSvcTMPersonMTool_updateRec", "UPDATE TblFmncSvcTMPersonMTool SET refFmncMPerson = $1, refR = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncSvcTMPersonMTool_removeRecByRef", "DELETE FROM TblFmncSvcTMPersonMTool WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncSvcTMPersonMTool_loadRecByRef", "SELECT ref, refFmncMPerson, refR FROM TblFmncSvcTMPersonMTool WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncSvcTMPersonMTool_loadRefsByR", "SELECT ref FROM TblFmncSvcTMPersonMTool WHERE refR = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncSvcTMPersonMTool_loadRstByR", "SELECT ref, refFmncMPerson, refR FROM TblFmncSvcTMPersonMTool WHERE refR = $1 ORDER BY refFmncMPerson ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncSvcTMPersonMTool::loadRec(
			PGresult* res
			, FmncSvcTMPersonMTool** rec
		) {
	char* ptr;

	FmncSvcTMPersonMTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncSvcTMPersonMTool();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "refr")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refR = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncSvcTMPersonMTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncSvcTMPersonMTool* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "refr")
		};

		while (numread < numrow) {
			rec = new FmncSvcTMPersonMTool();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refR = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncSvcTMPersonMTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncSvcTMPersonMTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcTMPersonMTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncSvcTMPersonMTool::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcTMPersonMTool / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncSvcTMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncSvcTMPersonMTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncSvcTMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncSvcTMPersonMTool::insertRec(
			FmncSvcTMPersonMTool* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refR = htonl64(rec->refR);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncSvcTMPersonMTool_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcTMPersonMTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncSvcTMPersonMTool::insertRst(
			ListFmncSvcTMPersonMTool& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncSvcTMPersonMTool::updateRec(
			FmncSvcTMPersonMTool* rec
		) {
	PGresult* res;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refR = htonl64(rec->refR);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_refR,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncSvcTMPersonMTool_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcTMPersonMTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncSvcTMPersonMTool::updateRst(
			ListFmncSvcTMPersonMTool& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncSvcTMPersonMTool::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncSvcTMPersonMTool_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncSvcTMPersonMTool_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncSvcTMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncSvcTMPersonMTool** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncSvcTMPersonMTool_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncSvcTMPersonMTool::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refR = htonl64(refR);

	const char* vals[] = {
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncSvcTMPersonMTool_loadRefsByR", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncSvcTMPersonMTool::loadRstByR(
			ubigint refR
			, const bool append
			, ListFmncSvcTMPersonMTool& rst
		) {
	ubigint _refR = htonl64(refR);

	const char* vals[] = {
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncSvcTMPersonMTool_loadRstByR", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

