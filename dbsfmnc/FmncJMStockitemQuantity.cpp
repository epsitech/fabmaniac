/**
  * \file FmncJMStockitemQuantity.cpp
  * database access for table TblFmncJMStockitemQuantity (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMStockitemQuantity.h"

/******************************************************************************
 class FmncJMStockitemQuantity
 ******************************************************************************/

FmncJMStockitemQuantity::FmncJMStockitemQuantity(
			const ubigint ref
			, const ubigint refFmncMStockitem
			, const uint x1Startd
			, const string Quantity
		) {

	this->ref = ref;
	this->refFmncMStockitem = refFmncMStockitem;
	this->x1Startd = x1Startd;
	this->Quantity = Quantity;
};

bool FmncJMStockitemQuantity::operator==(
			const FmncJMStockitemQuantity& comp
		) {
	return false;
};

bool FmncJMStockitemQuantity::operator!=(
			const FmncJMStockitemQuantity& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMStockitemQuantity
 ******************************************************************************/

ListFmncJMStockitemQuantity::ListFmncJMStockitemQuantity() {
};

ListFmncJMStockitemQuantity::ListFmncJMStockitemQuantity(
			const ListFmncJMStockitemQuantity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMStockitemQuantity(*(src.nodes[i]));
};

ListFmncJMStockitemQuantity::~ListFmncJMStockitemQuantity() {
	clear();
};

void ListFmncJMStockitemQuantity::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMStockitemQuantity::size() const {
	return(nodes.size());
};

void ListFmncJMStockitemQuantity::append(
			FmncJMStockitemQuantity* rec
		) {
	nodes.push_back(rec);
};

FmncJMStockitemQuantity* ListFmncJMStockitemQuantity::operator[](
			const uint ix
		) {
	FmncJMStockitemQuantity* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMStockitemQuantity& ListFmncJMStockitemQuantity::operator=(
			const ListFmncJMStockitemQuantity& src
		) {
	FmncJMStockitemQuantity* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMStockitemQuantity(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMStockitemQuantity::operator==(
			const ListFmncJMStockitemQuantity& comp
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

bool ListFmncJMStockitemQuantity::operator!=(
			const ListFmncJMStockitemQuantity& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMStockitemQuantity
 ******************************************************************************/

TblFmncJMStockitemQuantity::TblFmncJMStockitemQuantity() {
};

TblFmncJMStockitemQuantity::~TblFmncJMStockitemQuantity() {
};

bool TblFmncJMStockitemQuantity::loadRecBySQL(
			const string& sqlstr
			, FmncJMStockitemQuantity** rec
		) {
	return false;
};

ubigint TblFmncJMStockitemQuantity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	return 0;
};

void TblFmncJMStockitemQuantity::insertRec(
			FmncJMStockitemQuantity* rec
		) {
};

ubigint TblFmncJMStockitemQuantity::insertNewRec(
			FmncJMStockitemQuantity** rec
			, const ubigint refFmncMStockitem
			, const uint x1Startd
			, const string Quantity
		) {
	ubigint retval = 0;
	FmncJMStockitemQuantity* _rec = NULL;

	_rec = new FmncJMStockitemQuantity(0, refFmncMStockitem, x1Startd, Quantity);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMStockitemQuantity::appendNewRecToRst(
			ListFmncJMStockitemQuantity& rst
			, FmncJMStockitemQuantity** rec
			, const ubigint refFmncMStockitem
			, const uint x1Startd
			, const string Quantity
		) {
	ubigint retval = 0;
	FmncJMStockitemQuantity* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMStockitem, x1Startd, Quantity);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMStockitemQuantity::insertRst(
			ListFmncJMStockitemQuantity& rst
			, bool transact
		) {
};

void TblFmncJMStockitemQuantity::updateRec(
			FmncJMStockitemQuantity* rec
		) {
};

void TblFmncJMStockitemQuantity::updateRst(
			ListFmncJMStockitemQuantity& rst
			, bool transact
		) {
};

void TblFmncJMStockitemQuantity::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMStockitemQuantity::loadRecByRef(
			ubigint ref
			, FmncJMStockitemQuantity** rec
		) {
	return false;
};

bool TblFmncJMStockitemQuantity::loadRecBySkiSta(
			ubigint refFmncMStockitem
			, uint x1Startd
			, FmncJMStockitemQuantity** rec
		) {
	return false;
};

ubigint TblFmncJMStockitemQuantity::loadRstBySki(
			ubigint refFmncMStockitem
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	return 0;
};

ubigint TblFmncJMStockitemQuantity::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	ubigint numload = 0;
	FmncJMStockitemQuantity* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMStockitemQuantity
 ******************************************************************************/

MyTblFmncJMStockitemQuantity::MyTblFmncJMStockitemQuantity() : TblFmncJMStockitemQuantity(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMStockitemQuantity::~MyTblFmncJMStockitemQuantity() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMStockitemQuantity::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMStockitemQuantity (refFmncMStockitem, x1Startd, Quantity) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMStockitemQuantity SET refFmncMStockitem = ?, x1Startd = ?, Quantity = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMStockitemQuantity WHERE ref = ?", false);
};

bool MyTblFmncJMStockitemQuantity::loadRecBySQL(
			const string& sqlstr
			, FmncJMStockitemQuantity** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMStockitemQuantity* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMStockitemQuantity / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMStockitemQuantity();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMStockitem = atoll((char*) dbrow[1]); else _rec->refFmncMStockitem = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Quantity.assign(dbrow[3], dblengths[3]); else _rec->Quantity = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMStockitemQuantity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMStockitemQuantity* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMStockitemQuantity / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMStockitemQuantity();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMStockitem = atoll((char*) dbrow[1]); else rec->refFmncMStockitem = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Quantity.assign(dbrow[3], dblengths[3]); else rec->Quantity = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMStockitemQuantity::insertRec(
			FmncJMStockitemQuantity* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Quantity.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMStockitem,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Quantity.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMStockitemQuantity / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMStockitemQuantity / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMStockitemQuantity::insertRst(
			ListFmncJMStockitemQuantity& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMStockitemQuantity::updateRec(
			FmncJMStockitemQuantity* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Quantity.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMStockitem,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Quantity.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMStockitemQuantity / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMStockitemQuantity / stmtUpdateRec)\n");
};

void MyTblFmncJMStockitemQuantity::updateRst(
			ListFmncJMStockitemQuantity& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMStockitemQuantity::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMStockitemQuantity / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMStockitemQuantity / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMStockitemQuantity::loadRecByRef(
			ubigint ref
			, FmncJMStockitemQuantity** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMStockitemQuantity WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMStockitemQuantity::loadRecBySkiSta(
			ubigint refFmncMStockitem
			, uint x1Startd
			, FmncJMStockitemQuantity** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMStockitem, x1Startd, Quantity FROM TblFmncJMStockitemQuantity WHERE refFmncMStockitem = " + to_string(refFmncMStockitem) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMStockitemQuantity::loadRstBySki(
			ubigint refFmncMStockitem
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMStockitem, x1Startd, Quantity FROM TblFmncJMStockitemQuantity WHERE refFmncMStockitem = " + to_string(refFmncMStockitem) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMStockitemQuantity
 ******************************************************************************/

PgTblFmncJMStockitemQuantity::PgTblFmncJMStockitemQuantity() : TblFmncJMStockitemQuantity(), PgTable() {
};

PgTblFmncJMStockitemQuantity::~PgTblFmncJMStockitemQuantity() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMStockitemQuantity::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMStockitemQuantity_insertRec", "INSERT INTO TblFmncJMStockitemQuantity (refFmncMStockitem, x1Startd, Quantity) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMStockitemQuantity_updateRec", "UPDATE TblFmncJMStockitemQuantity SET refFmncMStockitem = $1, x1Startd = $2, Quantity = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMStockitemQuantity_removeRecByRef", "DELETE FROM TblFmncJMStockitemQuantity WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMStockitemQuantity_loadRecByRef", "SELECT ref, refFmncMStockitem, x1Startd, Quantity FROM TblFmncJMStockitemQuantity WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMStockitemQuantity_loadRecBySkiSta", "SELECT ref, refFmncMStockitem, x1Startd, Quantity FROM TblFmncJMStockitemQuantity WHERE refFmncMStockitem = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMStockitemQuantity_loadRstBySki", "SELECT ref, refFmncMStockitem, x1Startd, Quantity FROM TblFmncJMStockitemQuantity WHERE refFmncMStockitem = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMStockitemQuantity::loadRec(
			PGresult* res
			, FmncJMStockitemQuantity** rec
		) {
	char* ptr;

	FmncJMStockitemQuantity* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMStockitemQuantity();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmstockitem"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "quantity")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMStockitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Quantity.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMStockitemQuantity::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMStockitemQuantity* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmstockitem"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "quantity")
		};

		while (numread < numrow) {
			rec = new FmncJMStockitemQuantity();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMStockitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Quantity.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMStockitemQuantity::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMStockitemQuantity** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMStockitemQuantity / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMStockitemQuantity::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMStockitemQuantity / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMStockitemQuantity::loadRecBySQL(
			const string& sqlstr
			, FmncJMStockitemQuantity** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMStockitemQuantity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMStockitemQuantity::insertRec(
			FmncJMStockitemQuantity* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMStockitem = htonl64(rec->refFmncMStockitem);
	uint _x1Startd = htonl(rec->x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMStockitem,
		(char*) &_x1Startd,
		rec->Quantity.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncJMStockitemQuantity_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMStockitemQuantity_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMStockitemQuantity::insertRst(
			ListFmncJMStockitemQuantity& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMStockitemQuantity::updateRec(
			FmncJMStockitemQuantity* rec
		) {
	PGresult* res;

	ubigint _refFmncMStockitem = htonl64(rec->refFmncMStockitem);
	uint _x1Startd = htonl(rec->x1Startd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMStockitem,
		(char*) &_x1Startd,
		rec->Quantity.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncJMStockitemQuantity_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMStockitemQuantity_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMStockitemQuantity::updateRst(
			ListFmncJMStockitemQuantity& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMStockitemQuantity::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMStockitemQuantity_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMStockitemQuantity_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMStockitemQuantity::loadRecByRef(
			ubigint ref
			, FmncJMStockitemQuantity** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMStockitemQuantity_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMStockitemQuantity::loadRecBySkiSta(
			ubigint refFmncMStockitem
			, uint x1Startd
			, FmncJMStockitemQuantity** rec
		) {
	ubigint _refFmncMStockitem = htonl64(refFmncMStockitem);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMStockitem,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMStockitemQuantity_loadRecBySkiSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMStockitemQuantity::loadRstBySki(
			ubigint refFmncMStockitem
			, const bool append
			, ListFmncJMStockitemQuantity& rst
		) {
	ubigint _refFmncMStockitem = htonl64(refFmncMStockitem);

	const char* vals[] = {
		(char*) &_refFmncMStockitem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMStockitemQuantity_loadRstBySki", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

