/**
  * \file FmncAMSamplePar.cpp
  * database access for table TblFmncAMSamplePar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMSamplePar.h"

/******************************************************************************
 class FmncAMSamplePar
 ******************************************************************************/

FmncAMSamplePar::FmncAMSamplePar(
			const ubigint ref
			, const ubigint refFmncMSample
			, const string x1SrefKKey
			, const string osrefKVal
		) {

	this->ref = ref;
	this->refFmncMSample = refFmncMSample;
	this->x1SrefKKey = x1SrefKKey;
	this->osrefKVal = osrefKVal;
};

bool FmncAMSamplePar::operator==(
			const FmncAMSamplePar& comp
		) {
	return false;
};

bool FmncAMSamplePar::operator!=(
			const FmncAMSamplePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMSamplePar
 ******************************************************************************/

ListFmncAMSamplePar::ListFmncAMSamplePar() {
};

ListFmncAMSamplePar::ListFmncAMSamplePar(
			const ListFmncAMSamplePar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMSamplePar(*(src.nodes[i]));
};

ListFmncAMSamplePar::~ListFmncAMSamplePar() {
	clear();
};

void ListFmncAMSamplePar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMSamplePar::size() const {
	return(nodes.size());
};

void ListFmncAMSamplePar::append(
			FmncAMSamplePar* rec
		) {
	nodes.push_back(rec);
};

FmncAMSamplePar* ListFmncAMSamplePar::operator[](
			const uint ix
		) {
	FmncAMSamplePar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMSamplePar& ListFmncAMSamplePar::operator=(
			const ListFmncAMSamplePar& src
		) {
	FmncAMSamplePar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMSamplePar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMSamplePar::operator==(
			const ListFmncAMSamplePar& comp
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

bool ListFmncAMSamplePar::operator!=(
			const ListFmncAMSamplePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMSamplePar
 ******************************************************************************/

TblFmncAMSamplePar::TblFmncAMSamplePar() {
};

TblFmncAMSamplePar::~TblFmncAMSamplePar() {
};

bool TblFmncAMSamplePar::loadRecBySQL(
			const string& sqlstr
			, FmncAMSamplePar** rec
		) {
	return false;
};

ubigint TblFmncAMSamplePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMSamplePar& rst
		) {
	return 0;
};

void TblFmncAMSamplePar::insertRec(
			FmncAMSamplePar* rec
		) {
};

ubigint TblFmncAMSamplePar::insertNewRec(
			FmncAMSamplePar** rec
			, const ubigint refFmncMSample
			, const string x1SrefKKey
			, const string osrefKVal
		) {
	ubigint retval = 0;
	FmncAMSamplePar* _rec = NULL;

	_rec = new FmncAMSamplePar(0, refFmncMSample, x1SrefKKey, osrefKVal);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMSamplePar::appendNewRecToRst(
			ListFmncAMSamplePar& rst
			, FmncAMSamplePar** rec
			, const ubigint refFmncMSample
			, const string x1SrefKKey
			, const string osrefKVal
		) {
	ubigint retval = 0;
	FmncAMSamplePar* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMSample, x1SrefKKey, osrefKVal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMSamplePar::insertRst(
			ListFmncAMSamplePar& rst
			, bool transact
		) {
};

void TblFmncAMSamplePar::updateRec(
			FmncAMSamplePar* rec
		) {
};

void TblFmncAMSamplePar::updateRst(
			ListFmncAMSamplePar& rst
			, bool transact
		) {
};

void TblFmncAMSamplePar::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMSamplePar::loadRecByRef(
			ubigint ref
			, FmncAMSamplePar** rec
		) {
	return false;
};

ubigint TblFmncAMSamplePar::loadRefsBySmp(
			ubigint refFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncAMSamplePar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMSamplePar& rst
		) {
	ubigint numload = 0;
	FmncAMSamplePar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMSamplePar
 ******************************************************************************/

MyTblFmncAMSamplePar::MyTblFmncAMSamplePar() : TblFmncAMSamplePar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMSamplePar::~MyTblFmncAMSamplePar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMSamplePar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMSamplePar (refFmncMSample, x1SrefKKey, osrefKVal) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMSamplePar SET refFmncMSample = ?, x1SrefKKey = ?, osrefKVal = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMSamplePar WHERE ref = ?", false);
};

bool MyTblFmncAMSamplePar::loadRecBySQL(
			const string& sqlstr
			, FmncAMSamplePar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMSamplePar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMSamplePar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMSamplePar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMSample = atoll((char*) dbrow[1]); else _rec->refFmncMSample = 0;
		if (dbrow[2]) _rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKKey = "";
		if (dbrow[3]) _rec->osrefKVal.assign(dbrow[3], dblengths[3]); else _rec->osrefKVal = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMSamplePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMSamplePar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMSamplePar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMSamplePar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMSamplePar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMSample = atoll((char*) dbrow[1]); else rec->refFmncMSample = 0;
			if (dbrow[2]) rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else rec->x1SrefKKey = "";
			if (dbrow[3]) rec->osrefKVal.assign(dbrow[3], dblengths[3]); else rec->osrefKVal = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMSamplePar::insertRec(
			FmncAMSamplePar* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->osrefKVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMSample,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->osrefKVal.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMSamplePar / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMSamplePar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMSamplePar::insertRst(
			ListFmncAMSamplePar& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMSamplePar::updateRec(
			FmncAMSamplePar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->osrefKVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMSample,&(l[0]),&(n[0]),&(e[0])), 
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->osrefKVal.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMSamplePar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMSamplePar / stmtUpdateRec)\n");
};

void MyTblFmncAMSamplePar::updateRst(
			ListFmncAMSamplePar& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMSamplePar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMSamplePar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMSamplePar / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMSamplePar::loadRecByRef(
			ubigint ref
			, FmncAMSamplePar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMSamplePar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncAMSamplePar::loadRefsBySmp(
			ubigint refFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncAMSamplePar WHERE refFmncMSample = " + to_string(refFmncMSample) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMSamplePar
 ******************************************************************************/

PgTblFmncAMSamplePar::PgTblFmncAMSamplePar() : TblFmncAMSamplePar(), PgTable() {
};

PgTblFmncAMSamplePar::~PgTblFmncAMSamplePar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMSamplePar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMSamplePar_insertRec", "INSERT INTO TblFmncAMSamplePar (refFmncMSample, x1SrefKKey, osrefKVal) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMSamplePar_updateRec", "UPDATE TblFmncAMSamplePar SET refFmncMSample = $1, x1SrefKKey = $2, osrefKVal = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMSamplePar_removeRecByRef", "DELETE FROM TblFmncAMSamplePar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMSamplePar_loadRecByRef", "SELECT ref, refFmncMSample, x1SrefKKey, osrefKVal FROM TblFmncAMSamplePar WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAMSamplePar_loadRefsBySmp", "SELECT ref FROM TblFmncAMSamplePar WHERE refFmncMSample = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAMSamplePar::loadRec(
			PGresult* res
			, FmncAMSamplePar** rec
		) {
	char* ptr;

	FmncAMSamplePar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMSamplePar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmsample"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "osrefkval")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMSample = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->osrefKVal.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMSamplePar::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMSamplePar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMSamplePar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmsample"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "osrefkval")
		};

		while (numread < numrow) {
			rec = new FmncAMSamplePar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMSample = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->osrefKVal.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMSamplePar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMSamplePar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMSamplePar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMSamplePar::loadRecBySQL(
			const string& sqlstr
			, FmncAMSamplePar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMSamplePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMSamplePar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMSamplePar::insertRec(
			FmncAMSamplePar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		rec->x1SrefKKey.c_str(),
		rec->osrefKVal.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMSamplePar_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMSamplePar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMSamplePar::insertRst(
			ListFmncAMSamplePar& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMSamplePar::updateRec(
			FmncAMSamplePar* rec
		) {
	PGresult* res;

	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		rec->x1SrefKKey.c_str(),
		rec->osrefKVal.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMSamplePar_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMSamplePar_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMSamplePar::updateRst(
			ListFmncAMSamplePar& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMSamplePar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMSamplePar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMSamplePar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMSamplePar::loadRecByRef(
			ubigint ref
			, FmncAMSamplePar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMSamplePar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncAMSamplePar::loadRefsBySmp(
			ubigint refFmncMSample
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMSample = htonl64(refFmncMSample);

	const char* vals[] = {
		(char*) &_refFmncMSample
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncAMSamplePar_loadRefsBySmp", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

