/**
  * \file FmncFabSMPersonMTool.cpp
  * database access for table TblFmncFabSMPersonMTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncFabSMPersonMTool.h"

/******************************************************************************
 class FmncFabSMPersonMTool
 ******************************************************************************/

FmncFabSMPersonMTool::FmncFabSMPersonMTool(
			const ubigint ref
			, const ubigint refFmncMPerson
			, const ubigint refM
			, const uint numM
		) {

	this->ref = ref;
	this->refFmncMPerson = refFmncMPerson;
	this->refM = refM;
	this->numM = numM;
};

bool FmncFabSMPersonMTool::operator==(
			const FmncFabSMPersonMTool& comp
		) {
	return false;
};

bool FmncFabSMPersonMTool::operator!=(
			const FmncFabSMPersonMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncFabSMPersonMTool
 ******************************************************************************/

ListFmncFabSMPersonMTool::ListFmncFabSMPersonMTool() {
};

ListFmncFabSMPersonMTool::ListFmncFabSMPersonMTool(
			const ListFmncFabSMPersonMTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncFabSMPersonMTool(*(src.nodes[i]));
};

ListFmncFabSMPersonMTool::~ListFmncFabSMPersonMTool() {
	clear();
};

void ListFmncFabSMPersonMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncFabSMPersonMTool::size() const {
	return(nodes.size());
};

void ListFmncFabSMPersonMTool::append(
			FmncFabSMPersonMTool* rec
		) {
	nodes.push_back(rec);
};

FmncFabSMPersonMTool* ListFmncFabSMPersonMTool::operator[](
			const uint ix
		) {
	FmncFabSMPersonMTool* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncFabSMPersonMTool& ListFmncFabSMPersonMTool::operator=(
			const ListFmncFabSMPersonMTool& src
		) {
	FmncFabSMPersonMTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncFabSMPersonMTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncFabSMPersonMTool::operator==(
			const ListFmncFabSMPersonMTool& comp
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

bool ListFmncFabSMPersonMTool::operator!=(
			const ListFmncFabSMPersonMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncFabSMPersonMTool
 ******************************************************************************/

TblFmncFabSMPersonMTool::TblFmncFabSMPersonMTool() {
};

TblFmncFabSMPersonMTool::~TblFmncFabSMPersonMTool() {
};

bool TblFmncFabSMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncFabSMPersonMTool** rec
		) {
	return false;
};

ubigint TblFmncFabSMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	return 0;
};

void TblFmncFabSMPersonMTool::insertRec(
			FmncFabSMPersonMTool* rec
		) {
};

ubigint TblFmncFabSMPersonMTool::insertNewRec(
			FmncFabSMPersonMTool** rec
			, const ubigint refFmncMPerson
			, const ubigint refM
			, const uint numM
		) {
	ubigint retval = 0;
	FmncFabSMPersonMTool* _rec = NULL;

	_rec = new FmncFabSMPersonMTool(0, refFmncMPerson, refM, numM);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncFabSMPersonMTool::appendNewRecToRst(
			ListFmncFabSMPersonMTool& rst
			, FmncFabSMPersonMTool** rec
			, const ubigint refFmncMPerson
			, const ubigint refM
			, const uint numM
		) {
	ubigint retval = 0;
	FmncFabSMPersonMTool* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMPerson, refM, numM);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncFabSMPersonMTool::insertRst(
			ListFmncFabSMPersonMTool& rst
			, bool transact
		) {
};

void TblFmncFabSMPersonMTool::updateRec(
			FmncFabSMPersonMTool* rec
		) {
};

void TblFmncFabSMPersonMTool::updateRst(
			ListFmncFabSMPersonMTool& rst
			, bool transact
		) {
};

void TblFmncFabSMPersonMTool::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncFabSMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncFabSMPersonMTool** rec
		) {
	return false;
};

ubigint TblFmncFabSMPersonMTool::loadRefsByM(
			ubigint refM
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncFabSMPersonMTool::loadRstByM(
			ubigint refM
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	return 0;
};

ubigint TblFmncFabSMPersonMTool::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	ubigint numload = 0;
	FmncFabSMPersonMTool* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncFabSMPersonMTool
 ******************************************************************************/

MyTblFmncFabSMPersonMTool::MyTblFmncFabSMPersonMTool() : TblFmncFabSMPersonMTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncFabSMPersonMTool::~MyTblFmncFabSMPersonMTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncFabSMPersonMTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncFabSMPersonMTool (refFmncMPerson, refM, numM) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncFabSMPersonMTool SET refFmncMPerson = ?, refM = ?, numM = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncFabSMPersonMTool WHERE ref = ?", false);
};

bool MyTblFmncFabSMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncFabSMPersonMTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncFabSMPersonMTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncFabSMPersonMTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncFabSMPersonMTool();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMPerson = atoll((char*) dbrow[1]); else _rec->refFmncMPerson = 0;
		if (dbrow[2]) _rec->refM = atoll((char*) dbrow[2]); else _rec->refM = 0;
		if (dbrow[3]) _rec->numM = atol((char*) dbrow[3]); else _rec->numM = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncFabSMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncFabSMPersonMTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncFabSMPersonMTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncFabSMPersonMTool();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMPerson = atoll((char*) dbrow[1]); else rec->refFmncMPerson = 0;
			if (dbrow[2]) rec->refM = atoll((char*) dbrow[2]); else rec->refM = 0;
			if (dbrow[3]) rec->numM = atol((char*) dbrow[3]); else rec->numM = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncFabSMPersonMTool::insertRec(
			FmncFabSMPersonMTool* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refM,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->numM,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncFabSMPersonMTool / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncFabSMPersonMTool / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncFabSMPersonMTool::insertRst(
			ListFmncFabSMPersonMTool& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncFabSMPersonMTool::updateRec(
			FmncFabSMPersonMTool* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refM,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->numM,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncFabSMPersonMTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncFabSMPersonMTool / stmtUpdateRec)\n");
};

void MyTblFmncFabSMPersonMTool::updateRst(
			ListFmncFabSMPersonMTool& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncFabSMPersonMTool::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncFabSMPersonMTool / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncFabSMPersonMTool / stmtRemoveRecByRef)\n");
};

bool MyTblFmncFabSMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncFabSMPersonMTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncFabSMPersonMTool WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncFabSMPersonMTool::loadRefsByM(
			ubigint refM
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncFabSMPersonMTool WHERE refM = " + to_string(refM) + "", append, refs);
};

ubigint MyTblFmncFabSMPersonMTool::loadRstByM(
			ubigint refM
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMPerson, refM, numM FROM TblFmncFabSMPersonMTool WHERE refM = " + to_string(refM) + " ORDER BY numM ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncFabSMPersonMTool
 ******************************************************************************/

PgTblFmncFabSMPersonMTool::PgTblFmncFabSMPersonMTool() : TblFmncFabSMPersonMTool(), PgTable() {
};

PgTblFmncFabSMPersonMTool::~PgTblFmncFabSMPersonMTool() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncFabSMPersonMTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncFabSMPersonMTool_insertRec", "INSERT INTO TblFmncFabSMPersonMTool (refFmncMPerson, refM, numM) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncFabSMPersonMTool_updateRec", "UPDATE TblFmncFabSMPersonMTool SET refFmncMPerson = $1, refM = $2, numM = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncFabSMPersonMTool_removeRecByRef", "DELETE FROM TblFmncFabSMPersonMTool WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncFabSMPersonMTool_loadRecByRef", "SELECT ref, refFmncMPerson, refM, numM FROM TblFmncFabSMPersonMTool WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncFabSMPersonMTool_loadRefsByM", "SELECT ref FROM TblFmncFabSMPersonMTool WHERE refM = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncFabSMPersonMTool_loadRstByM", "SELECT ref, refFmncMPerson, refM, numM FROM TblFmncFabSMPersonMTool WHERE refM = $1 ORDER BY numM ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncFabSMPersonMTool::loadRec(
			PGresult* res
			, FmncFabSMPersonMTool** rec
		) {
	char* ptr;

	FmncFabSMPersonMTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncFabSMPersonMTool();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "refm"),
			PQfnumber(res, "numm")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refM = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->numM = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncFabSMPersonMTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncFabSMPersonMTool* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "refm"),
			PQfnumber(res, "numm")
		};

		while (numread < numrow) {
			rec = new FmncFabSMPersonMTool();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refM = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->numM = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncFabSMPersonMTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncFabSMPersonMTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncFabSMPersonMTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncFabSMPersonMTool::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncFabSMPersonMTool / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncFabSMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncFabSMPersonMTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncFabSMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncFabSMPersonMTool::insertRec(
			FmncFabSMPersonMTool* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refM = htonl64(rec->refM);
	uint _numM = htonl(rec->numM);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_refM,
		(char*) &_numM
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncFabSMPersonMTool_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncFabSMPersonMTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncFabSMPersonMTool::insertRst(
			ListFmncFabSMPersonMTool& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncFabSMPersonMTool::updateRec(
			FmncFabSMPersonMTool* rec
		) {
	PGresult* res;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refM = htonl64(rec->refM);
	uint _numM = htonl(rec->numM);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_refM,
		(char*) &_numM,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncFabSMPersonMTool_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncFabSMPersonMTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncFabSMPersonMTool::updateRst(
			ListFmncFabSMPersonMTool& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncFabSMPersonMTool::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncFabSMPersonMTool_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncFabSMPersonMTool_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncFabSMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncFabSMPersonMTool** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncFabSMPersonMTool_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncFabSMPersonMTool::loadRefsByM(
			ubigint refM
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refM = htonl64(refM);

	const char* vals[] = {
		(char*) &_refM
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncFabSMPersonMTool_loadRefsByM", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncFabSMPersonMTool::loadRstByM(
			ubigint refM
			, const bool append
			, ListFmncFabSMPersonMTool& rst
		) {
	ubigint _refM = htonl64(refM);

	const char* vals[] = {
		(char*) &_refM
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncFabSMPersonMTool_loadRstByM", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

