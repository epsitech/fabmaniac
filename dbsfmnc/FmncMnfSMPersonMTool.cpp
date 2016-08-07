/**
  * \file FmncMnfSMPersonMTool.cpp
  * database access for table TblFmncMnfSMPersonMTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMnfSMPersonMTool.h"

/******************************************************************************
 class FmncMnfSMPersonMTool
 ******************************************************************************/

FmncMnfSMPersonMTool::FmncMnfSMPersonMTool(
			const ubigint ref
			, const ubigint refFmncMPerson
			, const ubigint refM
		) {

	this->ref = ref;
	this->refFmncMPerson = refFmncMPerson;
	this->refM = refM;
};

bool FmncMnfSMPersonMTool::operator==(
			const FmncMnfSMPersonMTool& comp
		) {
	return false;
};

bool FmncMnfSMPersonMTool::operator!=(
			const FmncMnfSMPersonMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMnfSMPersonMTool
 ******************************************************************************/

ListFmncMnfSMPersonMTool::ListFmncMnfSMPersonMTool() {
};

ListFmncMnfSMPersonMTool::ListFmncMnfSMPersonMTool(
			const ListFmncMnfSMPersonMTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMnfSMPersonMTool(*(src.nodes[i]));
};

ListFmncMnfSMPersonMTool::~ListFmncMnfSMPersonMTool() {
	clear();
};

void ListFmncMnfSMPersonMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMnfSMPersonMTool::size() const {
	return(nodes.size());
};

void ListFmncMnfSMPersonMTool::append(
			FmncMnfSMPersonMTool* rec
		) {
	nodes.push_back(rec);
};

FmncMnfSMPersonMTool* ListFmncMnfSMPersonMTool::operator[](
			const uint ix
		) {
	FmncMnfSMPersonMTool* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMnfSMPersonMTool& ListFmncMnfSMPersonMTool::operator=(
			const ListFmncMnfSMPersonMTool& src
		) {
	FmncMnfSMPersonMTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMnfSMPersonMTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMnfSMPersonMTool::operator==(
			const ListFmncMnfSMPersonMTool& comp
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

bool ListFmncMnfSMPersonMTool::operator!=(
			const ListFmncMnfSMPersonMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMnfSMPersonMTool
 ******************************************************************************/

TblFmncMnfSMPersonMTool::TblFmncMnfSMPersonMTool() {
};

TblFmncMnfSMPersonMTool::~TblFmncMnfSMPersonMTool() {
};

bool TblFmncMnfSMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncMnfSMPersonMTool** rec
		) {
	return false;
};

ubigint TblFmncMnfSMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	return 0;
};

void TblFmncMnfSMPersonMTool::insertRec(
			FmncMnfSMPersonMTool* rec
		) {
};

ubigint TblFmncMnfSMPersonMTool::insertNewRec(
			FmncMnfSMPersonMTool** rec
			, const ubigint refFmncMPerson
			, const ubigint refM
		) {
	ubigint retval = 0;
	FmncMnfSMPersonMTool* _rec = NULL;

	_rec = new FmncMnfSMPersonMTool(0, refFmncMPerson, refM);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMnfSMPersonMTool::appendNewRecToRst(
			ListFmncMnfSMPersonMTool& rst
			, FmncMnfSMPersonMTool** rec
			, const ubigint refFmncMPerson
			, const ubigint refM
		) {
	ubigint retval = 0;
	FmncMnfSMPersonMTool* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMPerson, refM);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMnfSMPersonMTool::insertRst(
			ListFmncMnfSMPersonMTool& rst
			, bool transact
		) {
};

void TblFmncMnfSMPersonMTool::updateRec(
			FmncMnfSMPersonMTool* rec
		) {
};

void TblFmncMnfSMPersonMTool::updateRst(
			ListFmncMnfSMPersonMTool& rst
			, bool transact
		) {
};

void TblFmncMnfSMPersonMTool::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMnfSMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncMnfSMPersonMTool** rec
		) {
	return false;
};

ubigint TblFmncMnfSMPersonMTool::loadRefsByM(
			ubigint refM
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncMnfSMPersonMTool::loadRstByM(
			ubigint refM
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	return 0;
};

ubigint TblFmncMnfSMPersonMTool::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	ubigint numload = 0;
	FmncMnfSMPersonMTool* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMnfSMPersonMTool
 ******************************************************************************/

MyTblFmncMnfSMPersonMTool::MyTblFmncMnfSMPersonMTool() : TblFmncMnfSMPersonMTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMnfSMPersonMTool::~MyTblFmncMnfSMPersonMTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMnfSMPersonMTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMnfSMPersonMTool (refFmncMPerson, refM) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMnfSMPersonMTool SET refFmncMPerson = ?, refM = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMnfSMPersonMTool WHERE ref = ?", false);
};

bool MyTblFmncMnfSMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncMnfSMPersonMTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMnfSMPersonMTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMnfSMPersonMTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMnfSMPersonMTool();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMPerson = atoll((char*) dbrow[1]); else _rec->refFmncMPerson = 0;
		if (dbrow[2]) _rec->refM = atoll((char*) dbrow[2]); else _rec->refM = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMnfSMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMnfSMPersonMTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMnfSMPersonMTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMnfSMPersonMTool();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMPerson = atoll((char*) dbrow[1]); else rec->refFmncMPerson = 0;
			if (dbrow[2]) rec->refM = atoll((char*) dbrow[2]); else rec->refM = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMnfSMPersonMTool::insertRec(
			FmncMnfSMPersonMTool* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refM,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMnfSMPersonMTool / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMnfSMPersonMTool / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMnfSMPersonMTool::insertRst(
			ListFmncMnfSMPersonMTool& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMnfSMPersonMTool::updateRec(
			FmncMnfSMPersonMTool* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refM,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMnfSMPersonMTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMnfSMPersonMTool / stmtUpdateRec)\n");
};

void MyTblFmncMnfSMPersonMTool::updateRst(
			ListFmncMnfSMPersonMTool& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMnfSMPersonMTool::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMnfSMPersonMTool / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMnfSMPersonMTool / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMnfSMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncMnfSMPersonMTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMnfSMPersonMTool WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncMnfSMPersonMTool::loadRefsByM(
			ubigint refM
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMnfSMPersonMTool WHERE refM = " + to_string(refM) + "", append, refs);
};

ubigint MyTblFmncMnfSMPersonMTool::loadRstByM(
			ubigint refM
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMPerson, refM FROM TblFmncMnfSMPersonMTool WHERE refM = " + to_string(refM) + " ORDER BY refFmncMPerson ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMnfSMPersonMTool
 ******************************************************************************/

PgTblFmncMnfSMPersonMTool::PgTblFmncMnfSMPersonMTool() : TblFmncMnfSMPersonMTool(), PgTable() {
};

PgTblFmncMnfSMPersonMTool::~PgTblFmncMnfSMPersonMTool() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMnfSMPersonMTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMnfSMPersonMTool_insertRec", "INSERT INTO TblFmncMnfSMPersonMTool (refFmncMPerson, refM) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMnfSMPersonMTool_updateRec", "UPDATE TblFmncMnfSMPersonMTool SET refFmncMPerson = $1, refM = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMnfSMPersonMTool_removeRecByRef", "DELETE FROM TblFmncMnfSMPersonMTool WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMnfSMPersonMTool_loadRecByRef", "SELECT ref, refFmncMPerson, refM FROM TblFmncMnfSMPersonMTool WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMnfSMPersonMTool_loadRefsByM", "SELECT ref FROM TblFmncMnfSMPersonMTool WHERE refM = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMnfSMPersonMTool_loadRstByM", "SELECT ref, refFmncMPerson, refM FROM TblFmncMnfSMPersonMTool WHERE refM = $1 ORDER BY refFmncMPerson ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMnfSMPersonMTool::loadRec(
			PGresult* res
			, FmncMnfSMPersonMTool** rec
		) {
	char* ptr;

	FmncMnfSMPersonMTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMnfSMPersonMTool();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "refm")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refM = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMnfSMPersonMTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMnfSMPersonMTool* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "refm")
		};

		while (numread < numrow) {
			rec = new FmncMnfSMPersonMTool();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refM = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMnfSMPersonMTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMnfSMPersonMTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMnfSMPersonMTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncMnfSMPersonMTool::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMnfSMPersonMTool / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncMnfSMPersonMTool::loadRecBySQL(
			const string& sqlstr
			, FmncMnfSMPersonMTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMnfSMPersonMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMnfSMPersonMTool::insertRec(
			FmncMnfSMPersonMTool* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refM = htonl64(rec->refM);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_refM
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncMnfSMPersonMTool_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMnfSMPersonMTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMnfSMPersonMTool::insertRst(
			ListFmncMnfSMPersonMTool& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMnfSMPersonMTool::updateRec(
			FmncMnfSMPersonMTool* rec
		) {
	PGresult* res;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refM = htonl64(rec->refM);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_refM,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncMnfSMPersonMTool_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMnfSMPersonMTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMnfSMPersonMTool::updateRst(
			ListFmncMnfSMPersonMTool& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMnfSMPersonMTool::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMnfSMPersonMTool_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMnfSMPersonMTool_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMnfSMPersonMTool::loadRecByRef(
			ubigint ref
			, FmncMnfSMPersonMTool** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMnfSMPersonMTool_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncMnfSMPersonMTool::loadRefsByM(
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

	return loadRefsByStmt("TblFmncMnfSMPersonMTool_loadRefsByM", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncMnfSMPersonMTool::loadRstByM(
			ubigint refM
			, const bool append
			, ListFmncMnfSMPersonMTool& rst
		) {
	ubigint _refM = htonl64(refM);

	const char* vals[] = {
		(char*) &_refM
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncMnfSMPersonMTool_loadRstByM", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

