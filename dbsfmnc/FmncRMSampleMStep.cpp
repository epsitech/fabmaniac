/**
  * \file FmncRMSampleMStep.cpp
  * database access for table TblFmncRMSampleMStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMSampleMStep.h"

/******************************************************************************
 class FmncRMSampleMStep
 ******************************************************************************/

FmncRMSampleMStep::FmncRMSampleMStep(
			const ubigint ref
			, const ubigint refFmncMSample
			, const ubigint refFmncMStep
		) {

	this->ref = ref;
	this->refFmncMSample = refFmncMSample;
	this->refFmncMStep = refFmncMStep;
};

bool FmncRMSampleMStep::operator==(
			const FmncRMSampleMStep& comp
		) {
	return false;
};

bool FmncRMSampleMStep::operator!=(
			const FmncRMSampleMStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMSampleMStep
 ******************************************************************************/

ListFmncRMSampleMStep::ListFmncRMSampleMStep() {
};

ListFmncRMSampleMStep::ListFmncRMSampleMStep(
			const ListFmncRMSampleMStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMSampleMStep(*(src.nodes[i]));
};

ListFmncRMSampleMStep::~ListFmncRMSampleMStep() {
	clear();
};

void ListFmncRMSampleMStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMSampleMStep::size() const {
	return(nodes.size());
};

void ListFmncRMSampleMStep::append(
			FmncRMSampleMStep* rec
		) {
	nodes.push_back(rec);
};

FmncRMSampleMStep* ListFmncRMSampleMStep::operator[](
			const uint ix
		) {
	FmncRMSampleMStep* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMSampleMStep& ListFmncRMSampleMStep::operator=(
			const ListFmncRMSampleMStep& src
		) {
	FmncRMSampleMStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMSampleMStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMSampleMStep::operator==(
			const ListFmncRMSampleMStep& comp
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

bool ListFmncRMSampleMStep::operator!=(
			const ListFmncRMSampleMStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMSampleMStep
 ******************************************************************************/

TblFmncRMSampleMStep::TblFmncRMSampleMStep() {
};

TblFmncRMSampleMStep::~TblFmncRMSampleMStep() {
};

bool TblFmncRMSampleMStep::loadRecBySQL(
			const string& sqlstr
			, FmncRMSampleMStep** rec
		) {
	return false;
};

ubigint TblFmncRMSampleMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMSampleMStep& rst
		) {
	return 0;
};

void TblFmncRMSampleMStep::insertRec(
			FmncRMSampleMStep* rec
		) {
};

ubigint TblFmncRMSampleMStep::insertNewRec(
			FmncRMSampleMStep** rec
			, const ubigint refFmncMSample
			, const ubigint refFmncMStep
		) {
	ubigint retval = 0;
	FmncRMSampleMStep* _rec = NULL;

	_rec = new FmncRMSampleMStep(0, refFmncMSample, refFmncMStep);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMSampleMStep::appendNewRecToRst(
			ListFmncRMSampleMStep& rst
			, FmncRMSampleMStep** rec
			, const ubigint refFmncMSample
			, const ubigint refFmncMStep
		) {
	ubigint retval = 0;
	FmncRMSampleMStep* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMSample, refFmncMStep);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMSampleMStep::insertRst(
			ListFmncRMSampleMStep& rst
			, bool transact
		) {
};

void TblFmncRMSampleMStep::updateRec(
			FmncRMSampleMStep* rec
		) {
};

void TblFmncRMSampleMStep::updateRst(
			ListFmncRMSampleMStep& rst
			, bool transact
		) {
};

void TblFmncRMSampleMStep::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMSampleMStep::loadRecByRef(
			ubigint ref
			, FmncRMSampleMStep** rec
		) {
	return false;
};

ubigint TblFmncRMSampleMStep::loadRefsBySte(
			ubigint refFmncMStep
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncRMSampleMStep::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMSampleMStep& rst
		) {
	ubigint numload = 0;
	FmncRMSampleMStep* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMSampleMStep
 ******************************************************************************/

MyTblFmncRMSampleMStep::MyTblFmncRMSampleMStep() : TblFmncRMSampleMStep(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMSampleMStep::~MyTblFmncRMSampleMStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMSampleMStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMSampleMStep (refFmncMSample, refFmncMStep) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMSampleMStep SET refFmncMSample = ?, refFmncMStep = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMSampleMStep WHERE ref = ?", false);
};

bool MyTblFmncRMSampleMStep::loadRecBySQL(
			const string& sqlstr
			, FmncRMSampleMStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMSampleMStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMSampleMStep / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMSampleMStep();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMSample = atoll((char*) dbrow[1]); else _rec->refFmncMSample = 0;
		if (dbrow[2]) _rec->refFmncMStep = atoll((char*) dbrow[2]); else _rec->refFmncMStep = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMSampleMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMSampleMStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMSampleMStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMSampleMStep / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMSampleMStep();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMSample = atoll((char*) dbrow[1]); else rec->refFmncMSample = 0;
			if (dbrow[2]) rec->refFmncMStep = atoll((char*) dbrow[2]); else rec->refFmncMStep = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMSampleMStep::insertRec(
			FmncRMSampleMStep* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMSample,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMStep,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMSampleMStep / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMSampleMStep / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMSampleMStep::insertRst(
			ListFmncRMSampleMStep& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMSampleMStep::updateRec(
			FmncRMSampleMStep* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMSample,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMStep,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMSampleMStep / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMSampleMStep / stmtUpdateRec)\n");
};

void MyTblFmncRMSampleMStep::updateRst(
			ListFmncRMSampleMStep& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMSampleMStep::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMSampleMStep / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMSampleMStep / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMSampleMStep::loadRecByRef(
			ubigint ref
			, FmncRMSampleMStep** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMSampleMStep WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMSampleMStep::loadRefsBySte(
			ubigint refFmncMStep
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncRMSampleMStep WHERE refFmncMStep = " + to_string(refFmncMStep) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMSampleMStep
 ******************************************************************************/

PgTblFmncRMSampleMStep::PgTblFmncRMSampleMStep() : TblFmncRMSampleMStep(), PgTable() {
};

PgTblFmncRMSampleMStep::~PgTblFmncRMSampleMStep() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMSampleMStep::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMSampleMStep_insertRec", "INSERT INTO TblFmncRMSampleMStep (refFmncMSample, refFmncMStep) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMSampleMStep_updateRec", "UPDATE TblFmncRMSampleMStep SET refFmncMSample = $1, refFmncMStep = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMSampleMStep_removeRecByRef", "DELETE FROM TblFmncRMSampleMStep WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMSampleMStep_loadRecByRef", "SELECT ref, refFmncMSample, refFmncMStep FROM TblFmncRMSampleMStep WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMSampleMStep_loadRefsBySte", "SELECT ref FROM TblFmncRMSampleMStep WHERE refFmncMStep = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMSampleMStep::loadRec(
			PGresult* res
			, FmncRMSampleMStep** rec
		) {
	char* ptr;

	FmncRMSampleMStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMSampleMStep();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmsample"),
			PQfnumber(res, "reffmncmstep")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMSample = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMStep = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMSampleMStep::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMSampleMStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMSampleMStep* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmsample"),
			PQfnumber(res, "reffmncmstep")
		};

		while (numread < numrow) {
			rec = new FmncRMSampleMStep();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMSample = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMStep = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMSampleMStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMSampleMStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMSampleMStep / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMSampleMStep::loadRecBySQL(
			const string& sqlstr
			, FmncRMSampleMStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMSampleMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMSampleMStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMSampleMStep::insertRec(
			FmncRMSampleMStep* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	ubigint _refFmncMStep = htonl64(rec->refFmncMStep);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		(char*) &_refFmncMStep
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMSampleMStep_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMSampleMStep_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMSampleMStep::insertRst(
			ListFmncRMSampleMStep& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMSampleMStep::updateRec(
			FmncRMSampleMStep* rec
		) {
	PGresult* res;

	ubigint _refFmncMSample = htonl64(rec->refFmncMSample);
	ubigint _refFmncMStep = htonl64(rec->refFmncMStep);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMSample,
		(char*) &_refFmncMStep,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMSampleMStep_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMSampleMStep_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMSampleMStep::updateRst(
			ListFmncRMSampleMStep& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMSampleMStep::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMSampleMStep_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMSampleMStep_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMSampleMStep::loadRecByRef(
			ubigint ref
			, FmncRMSampleMStep** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMSampleMStep_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMSampleMStep::loadRefsBySte(
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

	return loadRefsByStmt("TblFmncRMSampleMStep_loadRefsBySte", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

