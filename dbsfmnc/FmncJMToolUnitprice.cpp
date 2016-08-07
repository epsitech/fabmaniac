/**
  * \file FmncJMToolUnitprice.cpp
  * database access for table TblFmncJMToolUnitprice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMToolUnitprice.h"

/******************************************************************************
 class FmncJMToolUnitprice
 ******************************************************************************/

FmncJMToolUnitprice::FmncJMToolUnitprice(
			const ubigint ref
			, const ubigint refFmncMTool
			, const uint x1Startd
			, const double Unitprice
		) {

	this->ref = ref;
	this->refFmncMTool = refFmncMTool;
	this->x1Startd = x1Startd;
	this->Unitprice = Unitprice;
};

bool FmncJMToolUnitprice::operator==(
			const FmncJMToolUnitprice& comp
		) {
	return false;
};

bool FmncJMToolUnitprice::operator!=(
			const FmncJMToolUnitprice& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMToolUnitprice
 ******************************************************************************/

ListFmncJMToolUnitprice::ListFmncJMToolUnitprice() {
};

ListFmncJMToolUnitprice::ListFmncJMToolUnitprice(
			const ListFmncJMToolUnitprice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMToolUnitprice(*(src.nodes[i]));
};

ListFmncJMToolUnitprice::~ListFmncJMToolUnitprice() {
	clear();
};

void ListFmncJMToolUnitprice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMToolUnitprice::size() const {
	return(nodes.size());
};

void ListFmncJMToolUnitprice::append(
			FmncJMToolUnitprice* rec
		) {
	nodes.push_back(rec);
};

FmncJMToolUnitprice* ListFmncJMToolUnitprice::operator[](
			const uint ix
		) {
	FmncJMToolUnitprice* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMToolUnitprice& ListFmncJMToolUnitprice::operator=(
			const ListFmncJMToolUnitprice& src
		) {
	FmncJMToolUnitprice* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMToolUnitprice(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMToolUnitprice::operator==(
			const ListFmncJMToolUnitprice& comp
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

bool ListFmncJMToolUnitprice::operator!=(
			const ListFmncJMToolUnitprice& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMToolUnitprice
 ******************************************************************************/

TblFmncJMToolUnitprice::TblFmncJMToolUnitprice() {
};

TblFmncJMToolUnitprice::~TblFmncJMToolUnitprice() {
};

bool TblFmncJMToolUnitprice::loadRecBySQL(
			const string& sqlstr
			, FmncJMToolUnitprice** rec
		) {
	return false;
};

ubigint TblFmncJMToolUnitprice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	return 0;
};

void TblFmncJMToolUnitprice::insertRec(
			FmncJMToolUnitprice* rec
		) {
};

ubigint TblFmncJMToolUnitprice::insertNewRec(
			FmncJMToolUnitprice** rec
			, const ubigint refFmncMTool
			, const uint x1Startd
			, const double Unitprice
		) {
	ubigint retval = 0;
	FmncJMToolUnitprice* _rec = NULL;

	_rec = new FmncJMToolUnitprice(0, refFmncMTool, x1Startd, Unitprice);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMToolUnitprice::appendNewRecToRst(
			ListFmncJMToolUnitprice& rst
			, FmncJMToolUnitprice** rec
			, const ubigint refFmncMTool
			, const uint x1Startd
			, const double Unitprice
		) {
	ubigint retval = 0;
	FmncJMToolUnitprice* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMTool, x1Startd, Unitprice);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMToolUnitprice::insertRst(
			ListFmncJMToolUnitprice& rst
			, bool transact
		) {
};

void TblFmncJMToolUnitprice::updateRec(
			FmncJMToolUnitprice* rec
		) {
};

void TblFmncJMToolUnitprice::updateRst(
			ListFmncJMToolUnitprice& rst
			, bool transact
		) {
};

void TblFmncJMToolUnitprice::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMToolUnitprice::loadRecByRef(
			ubigint ref
			, FmncJMToolUnitprice** rec
		) {
	return false;
};

bool TblFmncJMToolUnitprice::loadRecByTolSta(
			ubigint refFmncMTool
			, uint x1Startd
			, FmncJMToolUnitprice** rec
		) {
	return false;
};

ubigint TblFmncJMToolUnitprice::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncJMToolUnitprice::loadRstByTol(
			ubigint refFmncMTool
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	return 0;
};

ubigint TblFmncJMToolUnitprice::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	ubigint numload = 0;
	FmncJMToolUnitprice* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMToolUnitprice
 ******************************************************************************/

MyTblFmncJMToolUnitprice::MyTblFmncJMToolUnitprice() : TblFmncJMToolUnitprice(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMToolUnitprice::~MyTblFmncJMToolUnitprice() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMToolUnitprice::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMToolUnitprice (refFmncMTool, x1Startd, Unitprice) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMToolUnitprice SET refFmncMTool = ?, x1Startd = ?, Unitprice = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMToolUnitprice WHERE ref = ?", false);
};

bool MyTblFmncJMToolUnitprice::loadRecBySQL(
			const string& sqlstr
			, FmncJMToolUnitprice** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMToolUnitprice* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMToolUnitprice / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMToolUnitprice();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMTool = atoll((char*) dbrow[1]); else _rec->refFmncMTool = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Unitprice = atof((char*) dbrow[3]); else _rec->Unitprice = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMToolUnitprice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMToolUnitprice* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMToolUnitprice / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMToolUnitprice();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMTool = atoll((char*) dbrow[1]); else rec->refFmncMTool = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Unitprice = atof((char*) dbrow[3]); else rec->Unitprice = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMToolUnitprice::insertRec(
			FmncJMToolUnitprice* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->Unitprice,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMToolUnitprice / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMToolUnitprice / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMToolUnitprice::insertRst(
			ListFmncJMToolUnitprice& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMToolUnitprice::updateRec(
			FmncJMToolUnitprice* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindDouble(&rec->Unitprice,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMToolUnitprice / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMToolUnitprice / stmtUpdateRec)\n");
};

void MyTblFmncJMToolUnitprice::updateRst(
			ListFmncJMToolUnitprice& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMToolUnitprice::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMToolUnitprice / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMToolUnitprice / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMToolUnitprice::loadRecByRef(
			ubigint ref
			, FmncJMToolUnitprice** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMToolUnitprice WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMToolUnitprice::loadRecByTolSta(
			ubigint refFmncMTool
			, uint x1Startd
			, FmncJMToolUnitprice** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMTool, x1Startd, Unitprice FROM TblFmncJMToolUnitprice WHERE refFmncMTool = " + to_string(refFmncMTool) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMToolUnitprice::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncJMToolUnitprice WHERE refFmncMTool = " + to_string(refFmncMTool) + "", append, refs);
};

ubigint MyTblFmncJMToolUnitprice::loadRstByTol(
			ubigint refFmncMTool
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMTool, x1Startd, Unitprice FROM TblFmncJMToolUnitprice WHERE refFmncMTool = " + to_string(refFmncMTool) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMToolUnitprice
 ******************************************************************************/

PgTblFmncJMToolUnitprice::PgTblFmncJMToolUnitprice() : TblFmncJMToolUnitprice(), PgTable() {
};

PgTblFmncJMToolUnitprice::~PgTblFmncJMToolUnitprice() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMToolUnitprice::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMToolUnitprice_insertRec", "INSERT INTO TblFmncJMToolUnitprice (refFmncMTool, x1Startd, Unitprice) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMToolUnitprice_updateRec", "UPDATE TblFmncJMToolUnitprice SET refFmncMTool = $1, x1Startd = $2, Unitprice = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMToolUnitprice_removeRecByRef", "DELETE FROM TblFmncJMToolUnitprice WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMToolUnitprice_loadRecByRef", "SELECT ref, refFmncMTool, x1Startd, Unitprice FROM TblFmncJMToolUnitprice WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMToolUnitprice_loadRecByTolSta", "SELECT ref, refFmncMTool, x1Startd, Unitprice FROM TblFmncJMToolUnitprice WHERE refFmncMTool = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMToolUnitprice_loadRefsByTol", "SELECT ref FROM TblFmncJMToolUnitprice WHERE refFmncMTool = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMToolUnitprice_loadRstByTol", "SELECT ref, refFmncMTool, x1Startd, Unitprice FROM TblFmncJMToolUnitprice WHERE refFmncMTool = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMToolUnitprice::loadRec(
			PGresult* res
			, FmncJMToolUnitprice** rec
		) {
	char* ptr;

	FmncJMToolUnitprice* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMToolUnitprice();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "unitprice")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Unitprice = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMToolUnitprice::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMToolUnitprice* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "unitprice")
		};

		while (numread < numrow) {
			rec = new FmncJMToolUnitprice();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Unitprice = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMToolUnitprice::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMToolUnitprice** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMToolUnitprice / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMToolUnitprice::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMToolUnitprice / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMToolUnitprice::loadRecBySQL(
			const string& sqlstr
			, FmncJMToolUnitprice** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMToolUnitprice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMToolUnitprice::insertRec(
			FmncJMToolUnitprice* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	uint _x1Startd = htonl(rec->x1Startd);
	string _Unitprice = to_string(rec->Unitprice);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1Startd,
		_Unitprice.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncJMToolUnitprice_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMToolUnitprice_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMToolUnitprice::insertRst(
			ListFmncJMToolUnitprice& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMToolUnitprice::updateRec(
			FmncJMToolUnitprice* rec
		) {
	PGresult* res;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	uint _x1Startd = htonl(rec->x1Startd);
	string _Unitprice = to_string(rec->Unitprice);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1Startd,
		_Unitprice.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncJMToolUnitprice_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMToolUnitprice_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMToolUnitprice::updateRst(
			ListFmncJMToolUnitprice& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMToolUnitprice::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMToolUnitprice_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMToolUnitprice_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMToolUnitprice::loadRecByRef(
			ubigint ref
			, FmncJMToolUnitprice** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMToolUnitprice_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMToolUnitprice::loadRecByTolSta(
			ubigint refFmncMTool
			, uint x1Startd
			, FmncJMToolUnitprice** rec
		) {
	ubigint _refFmncMTool = htonl64(refFmncMTool);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMToolUnitprice_loadRecByTolSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMToolUnitprice::loadRefsByTol(
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

	return loadRefsByStmt("TblFmncJMToolUnitprice_loadRefsByTol", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncJMToolUnitprice::loadRstByTol(
			ubigint refFmncMTool
			, const bool append
			, ListFmncJMToolUnitprice& rst
		) {
	ubigint _refFmncMTool = htonl64(refFmncMTool);

	const char* vals[] = {
		(char*) &_refFmncMTool
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMToolUnitprice_loadRstByTol", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

