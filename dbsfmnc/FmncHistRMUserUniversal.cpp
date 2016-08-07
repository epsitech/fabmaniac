/**
  * \file FmncHistRMUserUniversal.cpp
  * database access for table TblFmncHistRMUserUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncHistRMUserUniversal.h"

/******************************************************************************
 class FmncHistRMUserUniversal
 ******************************************************************************/

FmncHistRMUserUniversal::FmncHistRMUserUniversal(
			const ubigint ref
			, const ubigint refFmncMUser
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVCard
			, const uint ixFmncVPreset
			, const uint preIxFmncVMaintable
			, const ubigint preUref
			, const uint start
		) {

	this->ref = ref;
	this->refFmncMUser = refFmncMUser;
	this->unvIxFmncVMaintable = unvIxFmncVMaintable;
	this->unvUref = unvUref;
	this->ixFmncVCard = ixFmncVCard;
	this->ixFmncVPreset = ixFmncVPreset;
	this->preIxFmncVMaintable = preIxFmncVMaintable;
	this->preUref = preUref;
	this->start = start;
};

bool FmncHistRMUserUniversal::operator==(
			const FmncHistRMUserUniversal& comp
		) {
	return false;
};

bool FmncHistRMUserUniversal::operator!=(
			const FmncHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncHistRMUserUniversal
 ******************************************************************************/

ListFmncHistRMUserUniversal::ListFmncHistRMUserUniversal() {
};

ListFmncHistRMUserUniversal::ListFmncHistRMUserUniversal(
			const ListFmncHistRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncHistRMUserUniversal(*(src.nodes[i]));
};

ListFmncHistRMUserUniversal::~ListFmncHistRMUserUniversal() {
	clear();
};

void ListFmncHistRMUserUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncHistRMUserUniversal::size() const {
	return(nodes.size());
};

void ListFmncHistRMUserUniversal::append(
			FmncHistRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

FmncHistRMUserUniversal* ListFmncHistRMUserUniversal::operator[](
			const uint ix
		) {
	FmncHistRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncHistRMUserUniversal& ListFmncHistRMUserUniversal::operator=(
			const ListFmncHistRMUserUniversal& src
		) {
	FmncHistRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncHistRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncHistRMUserUniversal::operator==(
			const ListFmncHistRMUserUniversal& comp
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

bool ListFmncHistRMUserUniversal::operator!=(
			const ListFmncHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncHistRMUserUniversal
 ******************************************************************************/

TblFmncHistRMUserUniversal::TblFmncHistRMUserUniversal() {
};

TblFmncHistRMUserUniversal::~TblFmncHistRMUserUniversal() {
};

bool TblFmncHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblFmncHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	return 0;
};

void TblFmncHistRMUserUniversal::insertRec(
			FmncHistRMUserUniversal* rec
		) {
};

ubigint TblFmncHistRMUserUniversal::insertNewRec(
			FmncHistRMUserUniversal** rec
			, const ubigint refFmncMUser
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVCard
			, const uint ixFmncVPreset
			, const uint preIxFmncVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	FmncHistRMUserUniversal* _rec = NULL;

	_rec = new FmncHistRMUserUniversal(0, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVCard, ixFmncVPreset, preIxFmncVMaintable, preUref, start);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncHistRMUserUniversal::appendNewRecToRst(
			ListFmncHistRMUserUniversal& rst
			, FmncHistRMUserUniversal** rec
			, const ubigint refFmncMUser
			, const uint unvIxFmncVMaintable
			, const ubigint unvUref
			, const uint ixFmncVCard
			, const uint ixFmncVPreset
			, const uint preIxFmncVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	FmncHistRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVCard, ixFmncVPreset, preIxFmncVMaintable, preUref, start);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncHistRMUserUniversal::insertRst(
			ListFmncHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblFmncHistRMUserUniversal::updateRec(
			FmncHistRMUserUniversal* rec
		) {
};

void TblFmncHistRMUserUniversal::updateRst(
			ListFmncHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblFmncHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, FmncHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblFmncHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refFmncMUser
			, uint ixFmncVCard
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	return 0;
};

bool TblFmncHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& val
		) {
	return false;
};

ubigint TblFmncHistRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	ubigint numload = 0;
	FmncHistRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncHistRMUserUniversal
 ******************************************************************************/

MyTblFmncHistRMUserUniversal::MyTblFmncHistRMUserUniversal() : TblFmncHistRMUserUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncHistRMUserUniversal::~MyTblFmncHistRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncHistRMUserUniversal (refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVCard, ixFmncVPreset, preIxFmncVMaintable, preUref, start) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncHistRMUserUniversal SET refFmncMUser = ?, unvIxFmncVMaintable = ?, unvUref = ?, ixFmncVCard = ?, ixFmncVPreset = ?, preIxFmncVMaintable = ?, preUref = ?, start = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncHistRMUserUniversal WHERE ref = ?", false);
};

bool MyTblFmncHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncHistRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncHistRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncHistRMUserUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncHistRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMUser = atoll((char*) dbrow[1]); else _rec->refFmncMUser = 0;
		if (dbrow[2]) _rec->unvIxFmncVMaintable = atol((char*) dbrow[2]); else _rec->unvIxFmncVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixFmncVCard = atol((char*) dbrow[4]); else _rec->ixFmncVCard = 0;
		if (dbrow[5]) _rec->ixFmncVPreset = atol((char*) dbrow[5]); else _rec->ixFmncVPreset = 0;
		if (dbrow[6]) _rec->preIxFmncVMaintable = atol((char*) dbrow[6]); else _rec->preIxFmncVMaintable = 0;
		if (dbrow[7]) _rec->preUref = atoll((char*) dbrow[7]); else _rec->preUref = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncHistRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncHistRMUserUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncHistRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMUser = atoll((char*) dbrow[1]); else rec->refFmncMUser = 0;
			if (dbrow[2]) rec->unvIxFmncVMaintable = atol((char*) dbrow[2]); else rec->unvIxFmncVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixFmncVCard = atol((char*) dbrow[4]); else rec->ixFmncVCard = 0;
			if (dbrow[5]) rec->ixFmncVPreset = atol((char*) dbrow[5]); else rec->ixFmncVPreset = 0;
			if (dbrow[6]) rec->preIxFmncVMaintable = atol((char*) dbrow[6]); else rec->preIxFmncVMaintable = 0;
			if (dbrow[7]) rec->preUref = atoll((char*) dbrow[7]); else rec->preUref = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncHistRMUserUniversal::insertRec(
			FmncHistRMUserUniversal* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxFmncVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixFmncVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixFmncVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxFmncVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncHistRMUserUniversal / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncHistRMUserUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncHistRMUserUniversal::insertRst(
			ListFmncHistRMUserUniversal& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncHistRMUserUniversal::updateRec(
			FmncHistRMUserUniversal* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->unvIxFmncVMaintable,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixFmncVCard,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixFmncVPreset,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->preIxFmncVMaintable,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncHistRMUserUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncHistRMUserUniversal / stmtUpdateRec)\n");
};

void MyTblFmncHistRMUserUniversal::updateRst(
			ListFmncHistRMUserUniversal& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncHistRMUserUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncHistRMUserUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblFmncHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, FmncHistRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncHistRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refFmncMUser
			, uint ixFmncVCard
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVCard, ixFmncVPreset, preIxFmncVMaintable, preUref, start FROM TblFmncHistRMUserUniversal WHERE refFmncMUser = " + to_string(refFmncMUser) + " AND ixFmncVCard = " + to_string(ixFmncVCard) + " ORDER BY start DESC", append, rst);
};

bool MyTblFmncHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT unvUref FROM TblFmncHistRMUserUniversal WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncHistRMUserUniversal
 ******************************************************************************/

PgTblFmncHistRMUserUniversal::PgTblFmncHistRMUserUniversal() : TblFmncHistRMUserUniversal(), PgTable() {
};

PgTblFmncHistRMUserUniversal::~PgTblFmncHistRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncHistRMUserUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncHistRMUserUniversal_insertRec", "INSERT INTO TblFmncHistRMUserUniversal (refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVCard, ixFmncVPreset, preIxFmncVMaintable, preUref, start) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncHistRMUserUniversal_updateRec", "UPDATE TblFmncHistRMUserUniversal SET refFmncMUser = $1, unvIxFmncVMaintable = $2, unvUref = $3, ixFmncVCard = $4, ixFmncVPreset = $5, preIxFmncVMaintable = $6, preUref = $7, start = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncHistRMUserUniversal_removeRecByRef", "DELETE FROM TblFmncHistRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncHistRMUserUniversal_loadRecByRef", "SELECT ref, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVCard, ixFmncVPreset, preIxFmncVMaintable, preUref, start FROM TblFmncHistRMUserUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncHistRMUserUniversal_loadRstByUsrCrd", "SELECT ref, refFmncMUser, unvIxFmncVMaintable, unvUref, ixFmncVCard, ixFmncVPreset, preIxFmncVMaintable, preUref, start FROM TblFmncHistRMUserUniversal WHERE refFmncMUser = $1 AND ixFmncVCard = $2 ORDER BY start DESC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncHistRMUserUniversal_loadUnuByRef", "SELECT unvUref FROM TblFmncHistRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncHistRMUserUniversal::loadRec(
			PGresult* res
			, FmncHistRMUserUniversal** rec
		) {
	char* ptr;

	FmncHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncHistRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "unvixfmncvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixfmncvcard"),
			PQfnumber(res, "ixfmncvpreset"),
			PQfnumber(res, "preixfmncvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxFmncVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixFmncVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixFmncVPreset = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->preIxFmncVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->preUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->start = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncHistRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncHistRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "unvixfmncvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixfmncvcard"),
			PQfnumber(res, "ixfmncvpreset"),
			PQfnumber(res, "preixfmncvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		while (numread < numrow) {
			rec = new FmncHistRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxFmncVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixFmncVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixFmncVPreset = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->preIxFmncVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->preUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->start = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncHistRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncHistRMUserUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncHistRMUserUniversal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncHistRMUserUniversal / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, FmncHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncHistRMUserUniversal::insertRec(
			FmncHistRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _unvIxFmncVMaintable = htonl(rec->unvIxFmncVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixFmncVCard = htonl(rec->ixFmncVCard);
	uint _ixFmncVPreset = htonl(rec->ixFmncVPreset);
	uint _preIxFmncVMaintable = htonl(rec->preIxFmncVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_unvIxFmncVMaintable,
		(char*) &_unvUref,
		(char*) &_ixFmncVCard,
		(char*) &_ixFmncVPreset,
		(char*) &_preIxFmncVMaintable,
		(char*) &_preUref,
		(char*) &_start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncHistRMUserUniversal_insertRec", 8, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncHistRMUserUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncHistRMUserUniversal::insertRst(
			ListFmncHistRMUserUniversal& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncHistRMUserUniversal::updateRec(
			FmncHistRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _unvIxFmncVMaintable = htonl(rec->unvIxFmncVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixFmncVCard = htonl(rec->ixFmncVCard);
	uint _ixFmncVPreset = htonl(rec->ixFmncVPreset);
	uint _preIxFmncVMaintable = htonl(rec->preIxFmncVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_unvIxFmncVMaintable,
		(char*) &_unvUref,
		(char*) &_ixFmncVCard,
		(char*) &_ixFmncVPreset,
		(char*) &_preIxFmncVMaintable,
		(char*) &_preUref,
		(char*) &_start,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncHistRMUserUniversal_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncHistRMUserUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblFmncHistRMUserUniversal::updateRst(
			ListFmncHistRMUserUniversal& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncHistRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncHistRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncHistRMUserUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, FmncHistRMUserUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncHistRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refFmncMUser
			, uint ixFmncVCard
			, const bool append
			, ListFmncHistRMUserUniversal& rst
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);
	uint _ixFmncVCard = htonl(ixFmncVCard);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_ixFmncVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblFmncHistRMUserUniversal_loadRstByUsrCrd", 2, vals, l, f, append, rst);
};

bool PgTblFmncHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadUbigintByStmt("TblFmncHistRMUserUniversal_loadUnuByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

