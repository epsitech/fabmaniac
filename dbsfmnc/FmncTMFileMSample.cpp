/**
  * \file FmncTMFileMSample.cpp
  * database access for table TblFmncTMFileMSample (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncTMFileMSample.h"

/******************************************************************************
 class FmncTMFileMSample
 ******************************************************************************/

FmncTMFileMSample::FmncTMFileMSample(
			const ubigint ref
			, const ubigint refFmncMSample
			, const ubigint refR
		) {

	this->ref = ref;
	this->refFmncMSample = refFmncMSample;
	this->refR = refR;
};

bool FmncTMFileMSample::operator==(
			const FmncTMFileMSample& comp
		) {
	return false;
};

bool FmncTMFileMSample::operator!=(
			const FmncTMFileMSample& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncTMFileMSample
 ******************************************************************************/

ListFmncTMFileMSample::ListFmncTMFileMSample() {
};

ListFmncTMFileMSample::ListFmncTMFileMSample(
			const ListFmncTMFileMSample& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncTMFileMSample(*(src.nodes[i]));
};

ListFmncTMFileMSample::~ListFmncTMFileMSample() {
	clear();
};

void ListFmncTMFileMSample::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncTMFileMSample::size() const {
	return(nodes.size());
};

void ListFmncTMFileMSample::append(
			FmncTMFileMSample* rec
		) {
	nodes.push_back(rec);
};

FmncTMFileMSample* ListFmncTMFileMSample::operator[](
			const uint ix
		) {
	FmncTMFileMSample* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncTMFileMSample& ListFmncTMFileMSample::operator=(
			const ListFmncTMFileMSample& src
		) {
	FmncTMFileMSample* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncTMFileMSample(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncTMFileMSample::operator==(
			const ListFmncTMFileMSample& comp
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

bool ListFmncTMFileMSample::operator!=(
			const ListFmncTMFileMSample& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncTMFileMSample
 ******************************************************************************/

TblFmncTMFileMSample::TblFmncTMFileMSample() {
};

TblFmncTMFileMSample::~TblFmncTMFileMSample() {
};

bool TblFmncTMFileMSample::loadRecBySQL(
			const string& sqlstr
			, FmncTMFileMSample** rec
		) {
	return false;
};

ubigint TblFmncTMFileMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	return 0;
};

void TblFmncTMFileMSample::insertRec(
			FmncTMFileMSample* rec
		) {
};

ubigint TblFmncTMFileMSample::insertNewRec(
			FmncTMFileMSample** rec
			, const ubigint refFmncMSample
			, const ubigint refR
		) {
	ubigint retval = 0;
	FmncTMFileMSample* _rec = NULL;

	_rec = new FmncTMFileMSample(0, refFmncMSample, refR);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncTMFileMSample::appendNewRecToRst(
			ListFmncTMFileMSample& rst
			, FmncTMFileMSample** rec
			, const ubigint refFmncMSample
			, const ubigint refR
		) {
	ubigint retval = 0;
	FmncTMFileMSample* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMSample, refR);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncTMFileMSample::insertRst(
			ListFmncTMFileMSample& rst
			, bool transact
		) {
};

void TblFmncTMFileMSample::updateRec(
			FmncTMFileMSample* rec
		) {
};

void TblFmncTMFileMSample::updateRst(
			ListFmncTMFileMSample& rst
			, bool transact
		) {
};

void TblFmncTMFileMSample::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncTMFileMSample::loadRecByRef(
			ubigint ref
			, FmncTMFileMSample** rec
		) {
	return false;
};

ubigint TblFmncTMFileMSample::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncTMFileMSample::loadRstByR(
			ubigint refR
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	return 0;
};

ubigint TblFmncTMFileMSample::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	ubigint numload = 0;
	FmncTMFileMSample* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncTMFileMSample
 ******************************************************************************/

MyTblFmncTMFileMSample::MyTblFmncTMFileMSample() : TblFmncTMFileMSample(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncTMFileMSample::~MyTblFmncTMFileMSample() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncTMFileMSample::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncTMFileMSample (refFmncMSample, refR) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncTMFileMSample SET refFmncMSample = ?, refR = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncTMFileMSample WHERE ref = ?", false);
};

bool MyTblFmncTMFileMSample::loadRecBySQL(
			const string& sqlstr
			, FmncTMFileMSample** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncTMFileMSample* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncTMFileMSample / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncTMFileMSample();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMSample = atoll((char*) dbrow[1]); else _rec->refFmncMSample = 0;
		if (dbrow[2]) _rec->refR = atoll((char*) dbrow[2]); else _rec->refR = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncTMFileMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncTMFileMSample* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncTMFileMSample / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncTMFileMSample();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMSample = atoll((char*) dbrow[1]); else rec->refFmncMSample = 0;
			if (dbrow[2]) rec->refR = atoll((char*) dbrow[2]); else rec->refR = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncTMFileMSample::insertRec(
			FmncTMFileMSample* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMSample,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refR,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncTMFileMSample / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncTMFileMSample / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncTMFileMSample::insertRst(
			ListFmncTMFileMSample& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncTMFileMSample::updateRec(
			FmncTMFileMSample* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMSample,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refR,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncTMFileMSample / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncTMFileMSample / stmtUpdateRec)\n");
};

void MyTblFmncTMFileMSample::updateRst(
			ListFmncTMFileMSample& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncTMFileMSample::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncTMFileMSample / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncTMFileMSample / stmtRemoveRecByRef)\n");
};

bool MyTblFmncTMFileMSample::loadRecByRef(
			ubigint ref
			, FmncTMFileMSample** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncTMFileMSample WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncTMFileMSample::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncTMFileMSample WHERE refR = " + to_string(refR) + "", append, refs);
};

ubigint MyTblFmncTMFileMSample::loadRstByR(
			ubigint refR
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMSample, refR FROM TblFmncTMFileMSample WHERE refR = " + to_string(refR) + " ORDER BY refFmncMSample ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncTMFileMSample
 ******************************************************************************/

PgTblFmncTMFileMSample::PgTblFmncTMFileMSample() : TblFmncTMFileMSample(), PgTable() {
};

PgTblFmncTMFileMSample::~PgTblFmncTMFileMSample() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncTMFileMSample::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncTMFileMSample_insertRec", "INSERT INTO TblFmncTMFileMSample (refFmncMSample, refR) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncTMFileMSample_updateRec", "UPDATE TblFmncTMFileMSample SET refFmncMSample = $1, refR = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncTMFileMSample_removeRecByRef", "DELETE FROM TblFmncTMFileMSample WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncTMFileMSample_loadRecByRef", "SELECT ref, refFmncMSample, refR FROM TblFmncTMFileMSample WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncTMFileMSample_loadRefsByR", "SELECT ref FROM TblFmncTMFileMSample WHERE refR = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncTMFileMSample_loadRstByR", "SELECT ref, refFmncMSample, refR FROM TblFmncTMFileMSample WHERE refR = $1 ORDER BY refFmncMSample ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncTMFileMSample::loadRec(
			PGresult* res
			, FmncTMFileMSample** rec
		) {
	char* ptr;

	FmncTMFileMSample* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncTMFileMSample();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmsample"),
			PQfnumber(res, "refr")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMSample = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refR = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncTMFileMSample::loadRst(
			PGresult* res
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncTMFileMSample* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmsample"),
			PQfnumber(res, "refr")
		};

		while (numread < numrow) {
			rec = new FmncTMFileMSample();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMSample = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refR = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncTMFileMSample::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncTMFileMSample** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncTMFileMSample / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncTMFileMSample::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncTMFileMSample / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncTMFileMSample::loadRecBySQL(
			const string& sqlstr
			, FmncTMFileMSample** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncTMFileMSample::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncTMFileMSample::insertRec(
			FmncTMFileMSample* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	ubigint _refR = htonl64(rec->refR);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncTMFileMSample_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncTMFileMSample_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncTMFileMSample::insertRst(
			ListFmncTMFileMSample& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncTMFileMSample::updateRec(
			FmncTMFileMSample* rec
		) {
	PGresult* res;

	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	ubigint _refR = htonl64(rec->refR);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		(char*) &_refR,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncTMFileMSample_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncTMFileMSample_updateRec)\n");

	PQclear(res);
};

void PgTblFmncTMFileMSample::updateRst(
			ListFmncTMFileMSample& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncTMFileMSample::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncTMFileMSample_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncTMFileMSample_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncTMFileMSample::loadRecByRef(
			ubigint ref
			, FmncTMFileMSample** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncTMFileMSample_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncTMFileMSample::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refR = htonl64(refR);

	const char* vals[] = {
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncTMFileMSample_loadRefsByR", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncTMFileMSample::loadRstByR(
			ubigint refR
			, const bool append
			, ListFmncTMFileMSample& rst
		) {
	ubigint _refR = htonl64(refR);

	const char* vals[] = {
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncTMFileMSample_loadRstByR", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

