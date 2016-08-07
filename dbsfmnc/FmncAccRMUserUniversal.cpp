/**
  * \file FmncAccRMUserUniversal.cpp
  * database access for table TblFmncAccRMUserUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAccRMUserUniversal.h"

/******************************************************************************
 class FmncAccRMUserUniversal
 ******************************************************************************/

FmncAccRMUserUniversal::FmncAccRMUserUniversal(
			const ubigint ref
			, const ubigint refFmncMUser
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVAccess
		) {

	this->ref = ref;
	this->refFmncMUser = refFmncMUser;
	this->unvIxFmncVMaintable = unvIxFmncVMaintable;
	this->unvUref = unvUref;
	this->ixFmncVAccess = ixFmncVAccess;
};

bool FmncAccRMUserUniversal::operator==(
			const FmncAccRMUserUniversal& comp
		) {
	return false;
};

bool FmncAccRMUserUniversal::operator!=(
			const FmncAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAccRMUserUniversal
 ******************************************************************************/

ListFmncAccRMUserUniversal::ListFmncAccRMUserUniversal() {
};

ListFmncAccRMUserUniversal::ListFmncAccRMUserUniversal(
			const ListFmncAccRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAccRMUserUniversal(*(src.nodes[i]));
};

ListFmncAccRMUserUniversal::~ListFmncAccRMUserUniversal() {
	clear();
};

void ListFmncAccRMUserUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAccRMUserUniversal::size() const {
	return(nodes.size());
};

void ListFmncAccRMUserUniversal::append(
			FmncAccRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

FmncAccRMUserUniversal* ListFmncAccRMUserUniversal::operator[](
			const uint ix
		) {
	FmncAccRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAccRMUserUniversal& ListFmncAccRMUserUniversal::operator=(
			const ListFmncAccRMUserUniversal& src
		) {
	FmncAccRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAccRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAccRMUserUniversal::operator==(
			const ListFmncAccRMUserUniversal& comp
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

bool ListFmncAccRMUserUniversal::operator!=(
			const ListFmncAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAccRMUserUniversal
 ******************************************************************************/

TblFmncAccRMUserUniversal::TblFmncAccRMUserUniversal() {
};

TblFmncAccRMUserUniversal::~TblFmncAccRMUserUniversal() {
};

bool TblFmncAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblFmncAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAccRMUserUniversal& rst
		) {
	return 0;
};

void TblFmncAccRMUserUniversal::insertRec(
			FmncAccRMUserUniversal* rec
		) {
};

ubigint TblFmncAccRMUserUniversal::insertNewRec(
			FmncAccRMUserUniversal** rec
			, const ubigint refFmncMUser
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVAccess
		) {
	ubigint retval = 0;
	FmncAccRMUserUniversal* _rec = NULL;

	_rec = new FmncAccRMUserUniversal(0, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAccRMUserUniversal::appendNewRecToRst(
			ListFmncAccRMUserUniversal& rst
			, FmncAccRMUserUniversal** rec
			, const ubigint refFmncMUser
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVAccess
		) {
	ubigint retval = 0;
	FmncAccRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAccRMUserUniversal::insertRst(
			ListFmncAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblFmncAccRMUserUniversal::updateRec(
			FmncAccRMUserUniversal* rec
		) {
};

void TblFmncAccRMUserUniversal::updateRst(
			ListFmncAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblFmncAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, FmncAccRMUserUniversal** rec
		) {
	return false;
};

bool TblFmncAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refFmncMUser
			, uint unvIxFmncVMaintable
			, ubigint unvUref
			, FmncAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblFmncAccRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAccRMUserUniversal& rst
		) {
	ubigint numload = 0;
	FmncAccRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAccRMUserUniversal
 ******************************************************************************/

MyTblFmncAccRMUserUniversal::MyTblFmncAccRMUserUniversal() : TblFmncAccRMUserUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAccRMUserUniversal::~MyTblFmncAccRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAccRMUserUniversal (refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAccRMUserUniversal SET refFmncMUser = ?, unvIxFmncVMaintable = ?, unvUref = ?, ixFmncVAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAccRMUserUniversal WHERE ref = ?", false);
};

bool MyTblFmncAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncAccRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAccRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAccRMUserUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAccRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMUser = atoll((char*) dbrow[1]); else _rec->refFmncMUser = 0;
		if (dbrow[2]) _rec->unvIxFmncVMaintable = atol((char*) dbrow[2]); else _rec->unvIxFmncVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixFmncVAccess = atol((char*) dbrow[4]); else _rec->ixFmncVAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAccRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAccRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAccRMUserUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAccRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMUser = atoll((char*) dbrow[1]); else rec->refFmncMUser = 0;
			if (dbrow[2]) rec->unvIxFmncVMaintable = atol((char*) dbrow[2]); else rec->unvIxFmncVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixFmncVAccess = atol((char*) dbrow[4]); else rec->ixFmncVAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAccRMUserUniversal::insertRec(
			FmncAccRMUserUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxFmncVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixFmncVAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAccRMUserUniversal / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAccRMUserUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAccRMUserUniversal::insertRst(
			ListFmncAccRMUserUniversal& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAccRMUserUniversal::updateRec(
			FmncAccRMUserUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->unvIxFmncVMaintable,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixFmncVAccess,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAccRMUserUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAccRMUserUniversal / stmtUpdateRec)\n");
};

void MyTblFmncAccRMUserUniversal::updateRst(
			ListFmncAccRMUserUniversal& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAccRMUserUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAccRMUserUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, FmncAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAccRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refFmncMUser
			, uint unvIxFmncVMaintable
			, ubigint unvUref
			, FmncAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVAccess FROM TblFmncAccRMUserUniversal WHERE refFmncMUser = " + to_string(refFmncMUser) + " AND unvIxFmncVMaintable = " + to_string(unvIxFmncVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAccRMUserUniversal
 ******************************************************************************/

PgTblFmncAccRMUserUniversal::PgTblFmncAccRMUserUniversal() : TblFmncAccRMUserUniversal(), PgTable() {
};

PgTblFmncAccRMUserUniversal::~PgTblFmncAccRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAccRMUserUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAccRMUserUniversal_insertRec", "INSERT INTO TblFmncAccRMUserUniversal (refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAccRMUserUniversal_updateRec", "UPDATE TblFmncAccRMUserUniversal SET refFmncMUser = $1, unvIxFmncVMaintable = $2, unvUref = $3, ixFmncVAccess = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAccRMUserUniversal_removeRecByRef", "DELETE FROM TblFmncAccRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAccRMUserUniversal_loadRecByRef", "SELECT ref, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVAccess FROM TblFmncAccRMUserUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAccRMUserUniversal_loadRecByUsrMtbUnv", "SELECT ref, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVAccess FROM TblFmncAccRMUserUniversal WHERE refFmncMUser = $1 AND unvIxFmncVMaintable = $2 AND unvUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAccRMUserUniversal::loadRec(
			PGresult* res
			, FmncAccRMUserUniversal** rec
		) {
	char* ptr;

	FmncAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAccRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "unvixfmncvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixfmncvaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxFmncVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixFmncVAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAccRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAccRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAccRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "unvixfmncvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixfmncvaccess")
		};

		while (numread < numrow) {
			rec = new FmncAccRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxFmncVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixFmncVAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAccRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAccRMUserUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAccRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAccRMUserUniversal::insertRec(
			FmncAccRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _unvIxFmncVMaintable = htonl(rec->unvIxFmncVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixFmncVAccess = htonl(rec->ixFmncVAccess);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_unvIxFmncVMaintable,
		(char*) &_unvUref,
		(char*) &_ixFmncVAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncAccRMUserUniversal_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAccRMUserUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAccRMUserUniversal::insertRst(
			ListFmncAccRMUserUniversal& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAccRMUserUniversal::updateRec(
			FmncAccRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _unvIxFmncVMaintable = htonl(rec->unvIxFmncVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixFmncVAccess = htonl(rec->ixFmncVAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_unvIxFmncVMaintable,
		(char*) &_unvUref,
		(char*) &_ixFmncVAccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncAccRMUserUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAccRMUserUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAccRMUserUniversal::updateRst(
			ListFmncAccRMUserUniversal& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAccRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAccRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAccRMUserUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, FmncAccRMUserUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAccRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refFmncMUser
			, uint unvIxFmncVMaintable
			, ubigint unvUref
			, FmncAccRMUserUniversal** rec
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);
	uint _unvIxFmncVMaintable = htonl(unvIxFmncVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_unvIxFmncVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblFmncAccRMUserUniversal_loadRecByUsrMtbUnv", 3, vals, l, f, rec);
};

// IP pgTbl --- END

