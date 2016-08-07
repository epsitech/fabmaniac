/**
  * \file FmncAMStepPar.cpp
  * database access for table TblFmncAMStepPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMStepPar.h"

/******************************************************************************
 class FmncAMStepPar
 ******************************************************************************/

FmncAMStepPar::FmncAMStepPar(
			const ubigint ref
			, const ubigint refFmncMStep
			, const string x1OsrefFmncKSteppar
			, const uint x2IxVTbl
			, const ubigint x2Uref
			, const string Val
			, const string Comment
		) {

	this->ref = ref;
	this->refFmncMStep = refFmncMStep;
	this->x1OsrefFmncKSteppar = x1OsrefFmncKSteppar;
	this->x2IxVTbl = x2IxVTbl;
	this->x2Uref = x2Uref;
	this->Val = Val;
	this->Comment = Comment;
};

bool FmncAMStepPar::operator==(
			const FmncAMStepPar& comp
		) {
	return false;
};

bool FmncAMStepPar::operator!=(
			const FmncAMStepPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMStepPar
 ******************************************************************************/

ListFmncAMStepPar::ListFmncAMStepPar() {
};

ListFmncAMStepPar::ListFmncAMStepPar(
			const ListFmncAMStepPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMStepPar(*(src.nodes[i]));
};

ListFmncAMStepPar::~ListFmncAMStepPar() {
	clear();
};

void ListFmncAMStepPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMStepPar::size() const {
	return(nodes.size());
};

void ListFmncAMStepPar::append(
			FmncAMStepPar* rec
		) {
	nodes.push_back(rec);
};

FmncAMStepPar* ListFmncAMStepPar::operator[](
			const uint ix
		) {
	FmncAMStepPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMStepPar& ListFmncAMStepPar::operator=(
			const ListFmncAMStepPar& src
		) {
	FmncAMStepPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMStepPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMStepPar::operator==(
			const ListFmncAMStepPar& comp
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

bool ListFmncAMStepPar::operator!=(
			const ListFmncAMStepPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMStepPar
 ******************************************************************************/

TblFmncAMStepPar::TblFmncAMStepPar() {
};

TblFmncAMStepPar::~TblFmncAMStepPar() {
};

bool TblFmncAMStepPar::loadRecBySQL(
			const string& sqlstr
			, FmncAMStepPar** rec
		) {
	return false;
};

ubigint TblFmncAMStepPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMStepPar& rst
		) {
	return 0;
};

void TblFmncAMStepPar::insertRec(
			FmncAMStepPar* rec
		) {
};

ubigint TblFmncAMStepPar::insertNewRec(
			FmncAMStepPar** rec
			, const ubigint refFmncMStep
			, const string x1OsrefFmncKSteppar
			, const uint x2IxVTbl
			, const ubigint x2Uref
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAMStepPar* _rec = NULL;

	_rec = new FmncAMStepPar(0, refFmncMStep, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMStepPar::appendNewRecToRst(
			ListFmncAMStepPar& rst
			, FmncAMStepPar** rec
			, const ubigint refFmncMStep
			, const string x1OsrefFmncKSteppar
			, const uint x2IxVTbl
			, const ubigint x2Uref
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAMStepPar* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMStep, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMStepPar::insertRst(
			ListFmncAMStepPar& rst
			, bool transact
		) {
};

void TblFmncAMStepPar::updateRec(
			FmncAMStepPar* rec
		) {
};

void TblFmncAMStepPar::updateRst(
			ListFmncAMStepPar& rst
			, bool transact
		) {
};

void TblFmncAMStepPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMStepPar::loadRecByRef(
			ubigint ref
			, FmncAMStepPar** rec
		) {
	return false;
};

ubigint TblFmncAMStepPar::loadRefsBySte(
			ubigint refFmncMStep
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncAMStepPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMStepPar& rst
		) {
	ubigint numload = 0;
	FmncAMStepPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMStepPar
 ******************************************************************************/

MyTblFmncAMStepPar::MyTblFmncAMStepPar() : TblFmncAMStepPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMStepPar::~MyTblFmncAMStepPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMStepPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMStepPar (refFmncMStep, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMStepPar SET refFmncMStep = ?, x1OsrefFmncKSteppar = ?, x2IxVTbl = ?, x2Uref = ?, Val = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMStepPar WHERE ref = ?", false);
};

bool MyTblFmncAMStepPar::loadRecBySQL(
			const string& sqlstr
			, FmncAMStepPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMStepPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMStepPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMStepPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMStep = atoll((char*) dbrow[1]); else _rec->refFmncMStep = 0;
		if (dbrow[2]) _rec->x1OsrefFmncKSteppar.assign(dbrow[2], dblengths[2]); else _rec->x1OsrefFmncKSteppar = "";
		if (dbrow[3]) _rec->x2IxVTbl = atol((char*) dbrow[3]); else _rec->x2IxVTbl = 0;
		if (dbrow[4]) _rec->x2Uref = atoll((char*) dbrow[4]); else _rec->x2Uref = 0;
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMStepPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMStepPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMStepPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMStepPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMStepPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMStep = atoll((char*) dbrow[1]); else rec->refFmncMStep = 0;
			if (dbrow[2]) rec->x1OsrefFmncKSteppar.assign(dbrow[2], dblengths[2]); else rec->x1OsrefFmncKSteppar = "";
			if (dbrow[3]) rec->x2IxVTbl = atol((char*) dbrow[3]); else rec->x2IxVTbl = 0;
			if (dbrow[4]) rec->x2Uref = atoll((char*) dbrow[4]); else rec->x2Uref = 0;
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMStepPar::insertRec(
			FmncAMStepPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[1] = rec->x1OsrefFmncKSteppar.length();
	l[4] = rec->Val.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMStep,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1OsrefFmncKSteppar.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x2Uref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMStepPar / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMStepPar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMStepPar::insertRst(
			ListFmncAMStepPar& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMStepPar::updateRec(
			FmncAMStepPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[1] = rec->x1OsrefFmncKSteppar.length();
	l[4] = rec->Val.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMStep,&(l[0]),&(n[0]),&(e[0])), 
		bindCstring((char*) (rec->x1OsrefFmncKSteppar.c_str()),&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x2IxVTbl,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x2Uref,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMStepPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMStepPar / stmtUpdateRec)\n");
};

void MyTblFmncAMStepPar::updateRst(
			ListFmncAMStepPar& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMStepPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMStepPar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMStepPar / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMStepPar::loadRecByRef(
			ubigint ref
			, FmncAMStepPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMStepPar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncAMStepPar::loadRefsBySte(
			ubigint refFmncMStep
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncAMStepPar WHERE refFmncMStep = " + to_string(refFmncMStep) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMStepPar
 ******************************************************************************/

PgTblFmncAMStepPar::PgTblFmncAMStepPar() : TblFmncAMStepPar(), PgTable() {
};

PgTblFmncAMStepPar::~PgTblFmncAMStepPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMStepPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMStepPar_insertRec", "INSERT INTO TblFmncAMStepPar (refFmncMStep, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMStepPar_updateRec", "UPDATE TblFmncAMStepPar SET refFmncMStep = $1, x1OsrefFmncKSteppar = $2, x2IxVTbl = $3, x2Uref = $4, Val = $5, Comment = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMStepPar_removeRecByRef", "DELETE FROM TblFmncAMStepPar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMStepPar_loadRecByRef", "SELECT ref, refFmncMStep, x1OsrefFmncKSteppar, x2IxVTbl, x2Uref, Val, Comment FROM TblFmncAMStepPar WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAMStepPar_loadRefsBySte", "SELECT ref FROM TblFmncAMStepPar WHERE refFmncMStep = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAMStepPar::loadRec(
			PGresult* res
			, FmncAMStepPar** rec
		) {
	char* ptr;

	FmncAMStepPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMStepPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmstep"),
			PQfnumber(res, "x1osreffmncksteppar"),
			PQfnumber(res, "x2ixvtbl"),
			PQfnumber(res, "x2uref"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMStep = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1OsrefFmncKSteppar.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2IxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2Uref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMStepPar::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMStepPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMStepPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmstep"),
			PQfnumber(res, "x1osreffmncksteppar"),
			PQfnumber(res, "x2ixvtbl"),
			PQfnumber(res, "x2uref"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncAMStepPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMStep = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1OsrefFmncKSteppar.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2IxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2Uref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMStepPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMStepPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMStepPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMStepPar::loadRecBySQL(
			const string& sqlstr
			, FmncAMStepPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMStepPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMStepPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMStepPar::insertRec(
			FmncAMStepPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMStep = htonl64(rec->refFmncMStep);
	uint _x2IxVTbl = htonl(rec->x2IxVTbl);
	ubigint _x2Uref = htonl64(rec->x2Uref);

	const char* vals[] = {
		(char*) &_refFmncMStep,
		rec->x1OsrefFmncKSteppar.c_str(),
		(char*) &_x2IxVTbl,
		(char*) &_x2Uref,
		rec->Val.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMStepPar_insertRec", 6, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMStepPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMStepPar::insertRst(
			ListFmncAMStepPar& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMStepPar::updateRec(
			FmncAMStepPar* rec
		) {
	PGresult* res;

	ubigint _refFmncMStep = htonl64(rec->refFmncMStep);
	uint _x2IxVTbl = htonl(rec->x2IxVTbl);
	ubigint _x2Uref = htonl64(rec->x2Uref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMStep,
		rec->x1OsrefFmncKSteppar.c_str(),
		(char*) &_x2IxVTbl,
		(char*) &_x2Uref,
		rec->Val.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMStepPar_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMStepPar_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMStepPar::updateRst(
			ListFmncAMStepPar& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMStepPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMStepPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMStepPar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMStepPar::loadRecByRef(
			ubigint ref
			, FmncAMStepPar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMStepPar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncAMStepPar::loadRefsBySte(
			ubigint refFmncMStep
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMStep = htonl64(refFmncMStep);

	const char* vals[] = {
		(char*) &_refFmncMStep
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncAMStepPar_loadRefsBySte", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

