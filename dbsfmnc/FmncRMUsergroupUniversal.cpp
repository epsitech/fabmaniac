/**
  * \file FmncRMUsergroupUniversal.cpp
  * database access for table TblFmncRMUsergroupUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMUsergroupUniversal.h"

/******************************************************************************
 class FmncRMUsergroupUniversal
 ******************************************************************************/

FmncRMUsergroupUniversal::FmncRMUsergroupUniversal(
			const ubigint ref
			, const ubigint refFmncMUsergroup
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVAccess
		) {

	this->ref = ref;
	this->refFmncMUsergroup = refFmncMUsergroup;
	this->unvIxFmncVMaintable = unvIxFmncVMaintable;
	this->unvUref = unvUref;
	this->ixFmncVAccess = ixFmncVAccess;
};

bool FmncRMUsergroupUniversal::operator==(
			const FmncRMUsergroupUniversal& comp
		) {
	return false;
};

bool FmncRMUsergroupUniversal::operator!=(
			const FmncRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMUsergroupUniversal
 ******************************************************************************/

ListFmncRMUsergroupUniversal::ListFmncRMUsergroupUniversal() {
};

ListFmncRMUsergroupUniversal::ListFmncRMUsergroupUniversal(
			const ListFmncRMUsergroupUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMUsergroupUniversal(*(src.nodes[i]));
};

ListFmncRMUsergroupUniversal::~ListFmncRMUsergroupUniversal() {
	clear();
};

void ListFmncRMUsergroupUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMUsergroupUniversal::size() const {
	return(nodes.size());
};

void ListFmncRMUsergroupUniversal::append(
			FmncRMUsergroupUniversal* rec
		) {
	nodes.push_back(rec);
};

FmncRMUsergroupUniversal* ListFmncRMUsergroupUniversal::operator[](
			const uint ix
		) {
	FmncRMUsergroupUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMUsergroupUniversal& ListFmncRMUsergroupUniversal::operator=(
			const ListFmncRMUsergroupUniversal& src
		) {
	FmncRMUsergroupUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMUsergroupUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMUsergroupUniversal::operator==(
			const ListFmncRMUsergroupUniversal& comp
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

bool ListFmncRMUsergroupUniversal::operator!=(
			const ListFmncRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMUsergroupUniversal
 ******************************************************************************/

TblFmncRMUsergroupUniversal::TblFmncRMUsergroupUniversal() {
};

TblFmncRMUsergroupUniversal::~TblFmncRMUsergroupUniversal() {
};

bool TblFmncRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblFmncRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMUsergroupUniversal& rst
		) {
	return 0;
};

void TblFmncRMUsergroupUniversal::insertRec(
			FmncRMUsergroupUniversal* rec
		) {
};

ubigint TblFmncRMUsergroupUniversal::insertNewRec(
			FmncRMUsergroupUniversal** rec
			, const ubigint refFmncMUsergroup
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVAccess
		) {
	ubigint retval = 0;
	FmncRMUsergroupUniversal* _rec = NULL;

	_rec = new FmncRMUsergroupUniversal(0, refFmncMUsergroup, unvIxFmncVMaintable, unvUref, ixFmncVAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMUsergroupUniversal::appendNewRecToRst(
			ListFmncRMUsergroupUniversal& rst
			, FmncRMUsergroupUniversal** rec
			, const ubigint refFmncMUsergroup
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVAccess
		) {
	ubigint retval = 0;
	FmncRMUsergroupUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMUsergroup, unvIxFmncVMaintable, unvUref, ixFmncVAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMUsergroupUniversal::insertRst(
			ListFmncRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblFmncRMUsergroupUniversal::updateRec(
			FmncRMUsergroupUniversal* rec
		) {
};

void TblFmncRMUsergroupUniversal::updateRst(
			ListFmncRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblFmncRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, FmncRMUsergroupUniversal** rec
		) {
	return false;
};

bool TblFmncRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refFmncMUsergroup
			, uint unvIxFmncVMaintable
			, ubigint unvUref
			, FmncRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblFmncRMUsergroupUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMUsergroupUniversal& rst
		) {
	ubigint numload = 0;
	FmncRMUsergroupUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMUsergroupUniversal
 ******************************************************************************/

MyTblFmncRMUsergroupUniversal::MyTblFmncRMUsergroupUniversal() : TblFmncRMUsergroupUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMUsergroupUniversal::~MyTblFmncRMUsergroupUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMUsergroupUniversal (refFmncMUsergroup, unvIxFmncVMaintable, unvUref, ixFmncVAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMUsergroupUniversal SET refFmncMUsergroup = ?, unvIxFmncVMaintable = ?, unvUref = ?, ixFmncVAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMUsergroupUniversal WHERE ref = ?", false);
};

bool MyTblFmncRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncRMUsergroupUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMUsergroupUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMUsergroupUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMUsergroupUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMUsergroup = atoll((char*) dbrow[1]); else _rec->refFmncMUsergroup = 0;
		if (dbrow[2]) _rec->unvIxFmncVMaintable = atol((char*) dbrow[2]); else _rec->unvIxFmncVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixFmncVAccess = atol((char*) dbrow[4]); else _rec->ixFmncVAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMUsergroupUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMUsergroupUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMUsergroupUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMUsergroup = atoll((char*) dbrow[1]); else rec->refFmncMUsergroup = 0;
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

void MyTblFmncRMUsergroupUniversal::insertRec(
			FmncRMUsergroupUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxFmncVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixFmncVAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMUsergroupUniversal / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMUsergroupUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMUsergroupUniversal::insertRst(
			ListFmncRMUsergroupUniversal& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMUsergroupUniversal::updateRec(
			FmncRMUsergroupUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUsergroup,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->unvIxFmncVMaintable,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixFmncVAccess,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMUsergroupUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMUsergroupUniversal / stmtUpdateRec)\n");
};

void MyTblFmncRMUsergroupUniversal::updateRst(
			ListFmncRMUsergroupUniversal& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMUsergroupUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMUsergroupUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, FmncRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMUsergroupUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refFmncMUsergroup
			, uint unvIxFmncVMaintable
			, ubigint unvUref
			, FmncRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMUsergroup, unvIxFmncVMaintable, unvUref, ixFmncVAccess FROM TblFmncRMUsergroupUniversal WHERE refFmncMUsergroup = " + to_string(refFmncMUsergroup) + " AND unvIxFmncVMaintable = " + to_string(unvIxFmncVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMUsergroupUniversal
 ******************************************************************************/

PgTblFmncRMUsergroupUniversal::PgTblFmncRMUsergroupUniversal() : TblFmncRMUsergroupUniversal(), PgTable() {
};

PgTblFmncRMUsergroupUniversal::~PgTblFmncRMUsergroupUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMUsergroupUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMUsergroupUniversal_insertRec", "INSERT INTO TblFmncRMUsergroupUniversal (refFmncMUsergroup, unvIxFmncVMaintable, unvUref, ixFmncVAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMUsergroupUniversal_updateRec", "UPDATE TblFmncRMUsergroupUniversal SET refFmncMUsergroup = $1, unvIxFmncVMaintable = $2, unvUref = $3, ixFmncVAccess = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMUsergroupUniversal_removeRecByRef", "DELETE FROM TblFmncRMUsergroupUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMUsergroupUniversal_loadRecByRef", "SELECT ref, refFmncMUsergroup, unvIxFmncVMaintable, unvUref, ixFmncVAccess FROM TblFmncRMUsergroupUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMUsergroupUniversal_loadRecByUsgMtbUnv", "SELECT ref, refFmncMUsergroup, unvIxFmncVMaintable, unvUref, ixFmncVAccess FROM TblFmncRMUsergroupUniversal WHERE refFmncMUsergroup = $1 AND unvIxFmncVMaintable = $2 AND unvUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMUsergroupUniversal::loadRec(
			PGresult* res
			, FmncRMUsergroupUniversal** rec
		) {
	char* ptr;

	FmncRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMUsergroupUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "unvixfmncvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixfmncvaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxFmncVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixFmncVAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMUsergroupUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMUsergroupUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "unvixfmncvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixfmncvaccess")
		};

		while (numread < numrow) {
			rec = new FmncRMUsergroupUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMUsergroup = atoll(ptr);
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

bool PgTblFmncRMUsergroupUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUsergroupUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMUsergroupUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMUsergroupUniversal::insertRec(
			FmncRMUsergroupUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	uint _unvIxFmncVMaintable = htonl(rec->unvIxFmncVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixFmncVAccess = htonl(rec->ixFmncVAccess);

	const char* vals[] = {
		(char*) &_refFmncMUsergroup,
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

	res = PQexecPrepared(dbs, "TblFmncRMUsergroupUniversal_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUsergroupUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMUsergroupUniversal::insertRst(
			ListFmncRMUsergroupUniversal& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMUsergroupUniversal::updateRec(
			FmncRMUsergroupUniversal* rec
		) {
	PGresult* res;

	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	uint _unvIxFmncVMaintable = htonl(rec->unvIxFmncVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixFmncVAccess = htonl(rec->ixFmncVAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMUsergroup,
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

	res = PQexecPrepared(dbs, "TblFmncRMUsergroupUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUsergroupUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMUsergroupUniversal::updateRst(
			ListFmncRMUsergroupUniversal& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMUsergroupUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMUsergroupUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUsergroupUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, FmncRMUsergroupUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMUsergroupUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refFmncMUsergroup
			, uint unvIxFmncVMaintable
			, ubigint unvUref
			, FmncRMUsergroupUniversal** rec
		) {
	ubigint _refFmncMUsergroup = htonl64(refFmncMUsergroup);
	uint _unvIxFmncVMaintable = htonl(unvIxFmncVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refFmncMUsergroup,
		(char*) &_unvIxFmncVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblFmncRMUsergroupUniversal_loadRecByUsgMtbUnv", 3, vals, l, f, rec);
};

// IP pgTbl --- END

