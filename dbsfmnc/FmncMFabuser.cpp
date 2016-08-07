/**
  * \file FmncMFabuser.cpp
  * database access for table TblFmncMFabuser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMFabuser.h"

/******************************************************************************
 class FmncMFabuser
 ******************************************************************************/

FmncMFabuser::FmncMFabuser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFab
			, const ubigint refFmncMPerson
			, const ubigint refRFabproject
			, const ubigint refFmncMFabproject
			, const string sref
			, const ubigint refJState
			, const uint ixVState
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refFmncMFab = refFmncMFab;
	this->refFmncMPerson = refFmncMPerson;
	this->refRFabproject = refRFabproject;
	this->refFmncMFabproject = refFmncMFabproject;
	this->sref = sref;
	this->refJState = refJState;
	this->ixVState = ixVState;
};

bool FmncMFabuser::operator==(
			const FmncMFabuser& comp
		) {
	return false;
};

bool FmncMFabuser::operator!=(
			const FmncMFabuser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMFabuser
 ******************************************************************************/

ListFmncMFabuser::ListFmncMFabuser() {
};

ListFmncMFabuser::ListFmncMFabuser(
			const ListFmncMFabuser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMFabuser(*(src.nodes[i]));
};

ListFmncMFabuser::~ListFmncMFabuser() {
	clear();
};

void ListFmncMFabuser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMFabuser::size() const {
	return(nodes.size());
};

void ListFmncMFabuser::append(
			FmncMFabuser* rec
		) {
	nodes.push_back(rec);
};

FmncMFabuser* ListFmncMFabuser::operator[](
			const uint ix
		) {
	FmncMFabuser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMFabuser& ListFmncMFabuser::operator=(
			const ListFmncMFabuser& src
		) {
	FmncMFabuser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMFabuser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMFabuser::operator==(
			const ListFmncMFabuser& comp
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

bool ListFmncMFabuser::operator!=(
			const ListFmncMFabuser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMFabuser
 ******************************************************************************/

TblFmncMFabuser::TblFmncMFabuser() {
};

TblFmncMFabuser::~TblFmncMFabuser() {
};

bool TblFmncMFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncMFabuser** rec
		) {
	return false;
};

ubigint TblFmncMFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFabuser& rst
		) {
	return 0;
};

void TblFmncMFabuser::insertRec(
			FmncMFabuser* rec
		) {
};

ubigint TblFmncMFabuser::insertNewRec(
			FmncMFabuser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFab
			, const ubigint refFmncMPerson
			, const ubigint refRFabproject
			, const ubigint refFmncMFabproject
			, const string sref
			, const ubigint refJState
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncMFabuser* _rec = NULL;

	_rec = new FmncMFabuser(0, grp, own, refFmncMFab, refFmncMPerson, refRFabproject, refFmncMFabproject, sref, refJState, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMFabuser::appendNewRecToRst(
			ListFmncMFabuser& rst
			, FmncMFabuser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFab
			, const ubigint refFmncMPerson
			, const ubigint refRFabproject
			, const ubigint refFmncMFabproject
			, const string sref
			, const ubigint refJState
			, const uint ixVState
		) {
	ubigint retval = 0;
	FmncMFabuser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refFmncMFab, refFmncMPerson, refRFabproject, refFmncMFabproject, sref, refJState, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMFabuser::insertRst(
			ListFmncMFabuser& rst
			, bool transact
		) {
};

void TblFmncMFabuser::updateRec(
			FmncMFabuser* rec
		) {
};

void TblFmncMFabuser::updateRst(
			ListFmncMFabuser& rst
			, bool transact
		) {
};

void TblFmncMFabuser::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMFabuser::loadRecByRef(
			ubigint ref
			, FmncMFabuser** rec
		) {
	return false;
};

ubigint TblFmncMFabuser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMFabuser& rst
		) {
	ubigint numload = 0;
	FmncMFabuser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMFabuser
 ******************************************************************************/

MyTblFmncMFabuser::MyTblFmncMFabuser() : TblFmncMFabuser(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMFabuser::~MyTblFmncMFabuser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMFabuser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMFabuser (grp, own, refFmncMFab, refFmncMPerson, refRFabproject, refFmncMFabproject, sref, refJState, ixVState) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMFabuser SET grp = ?, own = ?, refFmncMFab = ?, refFmncMPerson = ?, refRFabproject = ?, refFmncMFabproject = ?, sref = ?, refJState = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMFabuser WHERE ref = ?", false);
};

bool MyTblFmncMFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncMFabuser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMFabuser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMFabuser / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMFabuser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refFmncMFab = atoll((char*) dbrow[3]); else _rec->refFmncMFab = 0;
		if (dbrow[4]) _rec->refFmncMPerson = atoll((char*) dbrow[4]); else _rec->refFmncMPerson = 0;
		if (dbrow[5]) _rec->refRFabproject = atoll((char*) dbrow[5]); else _rec->refRFabproject = 0;
		if (dbrow[6]) _rec->refFmncMFabproject = atoll((char*) dbrow[6]); else _rec->refFmncMFabproject = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->refJState = atoll((char*) dbrow[8]); else _rec->refJState = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFabuser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMFabuser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMFabuser / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMFabuser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refFmncMFab = atoll((char*) dbrow[3]); else rec->refFmncMFab = 0;
			if (dbrow[4]) rec->refFmncMPerson = atoll((char*) dbrow[4]); else rec->refFmncMPerson = 0;
			if (dbrow[5]) rec->refRFabproject = atoll((char*) dbrow[5]); else rec->refRFabproject = 0;
			if (dbrow[6]) rec->refFmncMFabproject = atoll((char*) dbrow[6]); else rec->refFmncMFabproject = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->refJState = atoll((char*) dbrow[8]); else rec->refJState = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMFabuser::insertRec(
			FmncMFabuser* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMFab,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refRFabproject,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refFmncMFabproject,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refJState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFabuser / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFabuser / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMFabuser::insertRst(
			ListFmncMFabuser& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMFabuser::updateRec(
			FmncMFabuser* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMFab,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMPerson,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refRFabproject,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refFmncMFabproject,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->refJState,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFabuser / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFabuser / stmtUpdateRec)\n");
};

void MyTblFmncMFabuser::updateRst(
			ListFmncMFabuser& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMFabuser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFabuser / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFabuser / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMFabuser::loadRecByRef(
			ubigint ref
			, FmncMFabuser** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMFabuser WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMFabuser
 ******************************************************************************/

PgTblFmncMFabuser::PgTblFmncMFabuser() : TblFmncMFabuser(), PgTable() {
};

PgTblFmncMFabuser::~PgTblFmncMFabuser() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMFabuser::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMFabuser_insertRec", "INSERT INTO TblFmncMFabuser (grp, own, refFmncMFab, refFmncMPerson, refRFabproject, refFmncMFabproject, sref, refJState, ixVState) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMFabuser_updateRec", "UPDATE TblFmncMFabuser SET grp = $1, own = $2, refFmncMFab = $3, refFmncMPerson = $4, refRFabproject = $5, refFmncMFabproject = $6, sref = $7, refJState = $8, ixVState = $9 WHERE ref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMFabuser_removeRecByRef", "DELETE FROM TblFmncMFabuser WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMFabuser_loadRecByRef", "SELECT ref, grp, own, refFmncMFab, refFmncMPerson, refRFabproject, refFmncMFabproject, sref, refJState, ixVState FROM TblFmncMFabuser WHERE ref = $1", 1, NULL);
};

bool PgTblFmncMFabuser::loadRec(
			PGresult* res
			, FmncMFabuser** rec
		) {
	char* ptr;

	FmncMFabuser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMFabuser();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "refrfabproject"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMFab = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refRFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refFmncMFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMFabuser::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMFabuser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMFabuser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "refrfabproject"),
			PQfnumber(res, "reffmncmfabproject"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new FmncMFabuser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMFab = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refRFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refFmncMFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMFabuser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMFabuser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFabuser / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMFabuser::loadRecBySQL(
			const string& sqlstr
			, FmncMFabuser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMFabuser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFabuser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMFabuser::insertRec(
			FmncMFabuser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refRFabproject = htonl64(rec->refRFabproject);
	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMFab,
		(char*) &_refFmncMPerson,
		(char*) &_refRFabproject,
		(char*) &_refFmncMFabproject,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncMFabuser_insertRec", 9, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFabuser_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMFabuser::insertRst(
			ListFmncMFabuser& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMFabuser::updateRec(
			FmncMFabuser* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _refRFabproject = htonl64(rec->refRFabproject);
	ubigint _refFmncMFabproject = htonl64(rec->refFmncMFabproject);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMFab,
		(char*) &_refFmncMPerson,
		(char*) &_refRFabproject,
		(char*) &_refFmncMFabproject,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncMFabuser_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFabuser_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMFabuser::updateRst(
			ListFmncMFabuser& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMFabuser::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMFabuser_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFabuser_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMFabuser::loadRecByRef(
			ubigint ref
			, FmncMFabuser** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMFabuser_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

