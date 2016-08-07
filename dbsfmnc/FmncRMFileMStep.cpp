/**
  * \file FmncRMFileMStep.cpp
  * database access for table TblFmncRMFileMStep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMFileMStep.h"

/******************************************************************************
 class FmncRMFileMStep
 ******************************************************************************/

FmncRMFileMStep::FmncRMFileMStep(
			const ubigint ref
			, const ubigint refFmncMFile
			, const ubigint refFmncMStep
			, const uint ixVDir
		) {

	this->ref = ref;
	this->refFmncMFile = refFmncMFile;
	this->refFmncMStep = refFmncMStep;
	this->ixVDir = ixVDir;
};

bool FmncRMFileMStep::operator==(
			const FmncRMFileMStep& comp
		) {
	return false;
};

bool FmncRMFileMStep::operator!=(
			const FmncRMFileMStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMFileMStep
 ******************************************************************************/

ListFmncRMFileMStep::ListFmncRMFileMStep() {
};

ListFmncRMFileMStep::ListFmncRMFileMStep(
			const ListFmncRMFileMStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMFileMStep(*(src.nodes[i]));
};

ListFmncRMFileMStep::~ListFmncRMFileMStep() {
	clear();
};

void ListFmncRMFileMStep::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMFileMStep::size() const {
	return(nodes.size());
};

void ListFmncRMFileMStep::append(
			FmncRMFileMStep* rec
		) {
	nodes.push_back(rec);
};

FmncRMFileMStep* ListFmncRMFileMStep::operator[](
			const uint ix
		) {
	FmncRMFileMStep* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMFileMStep& ListFmncRMFileMStep::operator=(
			const ListFmncRMFileMStep& src
		) {
	FmncRMFileMStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMFileMStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMFileMStep::operator==(
			const ListFmncRMFileMStep& comp
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

bool ListFmncRMFileMStep::operator!=(
			const ListFmncRMFileMStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMFileMStep
 ******************************************************************************/

TblFmncRMFileMStep::TblFmncRMFileMStep() {
};

TblFmncRMFileMStep::~TblFmncRMFileMStep() {
};

bool TblFmncRMFileMStep::loadRecBySQL(
			const string& sqlstr
			, FmncRMFileMStep** rec
		) {
	return false;
};

ubigint TblFmncRMFileMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFileMStep& rst
		) {
	return 0;
};

void TblFmncRMFileMStep::insertRec(
			FmncRMFileMStep* rec
		) {
};

ubigint TblFmncRMFileMStep::insertNewRec(
			FmncRMFileMStep** rec
			, const ubigint refFmncMFile
			, const ubigint refFmncMStep
			, const uint ixVDir
		) {
	ubigint retval = 0;
	FmncRMFileMStep* _rec = NULL;

	_rec = new FmncRMFileMStep(0, refFmncMFile, refFmncMStep, ixVDir);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMFileMStep::appendNewRecToRst(
			ListFmncRMFileMStep& rst
			, FmncRMFileMStep** rec
			, const ubigint refFmncMFile
			, const ubigint refFmncMStep
			, const uint ixVDir
		) {
	ubigint retval = 0;
	FmncRMFileMStep* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMFile, refFmncMStep, ixVDir);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMFileMStep::insertRst(
			ListFmncRMFileMStep& rst
			, bool transact
		) {
};

void TblFmncRMFileMStep::updateRec(
			FmncRMFileMStep* rec
		) {
};

void TblFmncRMFileMStep::updateRst(
			ListFmncRMFileMStep& rst
			, bool transact
		) {
};

void TblFmncRMFileMStep::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMFileMStep::loadRecByRef(
			ubigint ref
			, FmncRMFileMStep** rec
		) {
	return false;
};

ubigint TblFmncRMFileMStep::loadRefsBySte(
			ubigint refFmncMStep
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncRMFileMStep::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMFileMStep& rst
		) {
	ubigint numload = 0;
	FmncRMFileMStep* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMFileMStep
 ******************************************************************************/

MyTblFmncRMFileMStep::MyTblFmncRMFileMStep() : TblFmncRMFileMStep(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMFileMStep::~MyTblFmncRMFileMStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMFileMStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMFileMStep (refFmncMFile, refFmncMStep, ixVDir) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMFileMStep SET refFmncMFile = ?, refFmncMStep = ?, ixVDir = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMFileMStep WHERE ref = ?", false);
};

bool MyTblFmncRMFileMStep::loadRecBySQL(
			const string& sqlstr
			, FmncRMFileMStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMFileMStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFileMStep / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMFileMStep();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMFile = atoll((char*) dbrow[1]); else _rec->refFmncMFile = 0;
		if (dbrow[2]) _rec->refFmncMStep = atoll((char*) dbrow[2]); else _rec->refFmncMStep = 0;
		if (dbrow[3]) _rec->ixVDir = atol((char*) dbrow[3]); else _rec->ixVDir = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMFileMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFileMStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMFileMStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFileMStep / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMFileMStep();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMFile = atoll((char*) dbrow[1]); else rec->refFmncMFile = 0;
			if (dbrow[2]) rec->refFmncMStep = atoll((char*) dbrow[2]); else rec->refFmncMStep = 0;
			if (dbrow[3]) rec->ixVDir = atol((char*) dbrow[3]); else rec->ixVDir = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMFileMStep::insertRec(
			FmncRMFileMStep* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFile,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMStep,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVDir,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFileMStep / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFileMStep / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMFileMStep::insertRst(
			ListFmncRMFileMStep& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMFileMStep::updateRec(
			FmncRMFileMStep* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFile,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMStep,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVDir,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFileMStep / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFileMStep / stmtUpdateRec)\n");
};

void MyTblFmncRMFileMStep::updateRst(
			ListFmncRMFileMStep& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMFileMStep::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFileMStep / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFileMStep / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMFileMStep::loadRecByRef(
			ubigint ref
			, FmncRMFileMStep** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMFileMStep WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMFileMStep::loadRefsBySte(
			ubigint refFmncMStep
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncRMFileMStep WHERE refFmncMStep = " + to_string(refFmncMStep) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMFileMStep
 ******************************************************************************/

PgTblFmncRMFileMStep::PgTblFmncRMFileMStep() : TblFmncRMFileMStep(), PgTable() {
};

PgTblFmncRMFileMStep::~PgTblFmncRMFileMStep() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMFileMStep::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMFileMStep_insertRec", "INSERT INTO TblFmncRMFileMStep (refFmncMFile, refFmncMStep, ixVDir) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFileMStep_updateRec", "UPDATE TblFmncRMFileMStep SET refFmncMFile = $1, refFmncMStep = $2, ixVDir = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFileMStep_removeRecByRef", "DELETE FROM TblFmncRMFileMStep WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMFileMStep_loadRecByRef", "SELECT ref, refFmncMFile, refFmncMStep, ixVDir FROM TblFmncRMFileMStep WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMFileMStep_loadRefsBySte", "SELECT ref FROM TblFmncRMFileMStep WHERE refFmncMStep = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMFileMStep::loadRec(
			PGresult* res
			, FmncRMFileMStep** rec
		) {
	char* ptr;

	FmncRMFileMStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMFileMStep();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "reffmncmstep"),
			PQfnumber(res, "ixvdir")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMStep = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVDir = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMFileMStep::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMFileMStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMFileMStep* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfile"),
			PQfnumber(res, "reffmncmstep"),
			PQfnumber(res, "ixvdir")
		};

		while (numread < numrow) {
			rec = new FmncRMFileMStep();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMStep = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVDir = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMFileMStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMFileMStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFileMStep / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMFileMStep::loadRecBySQL(
			const string& sqlstr
			, FmncRMFileMStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMFileMStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFileMStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMFileMStep::insertRec(
			FmncRMFileMStep* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	ubigint _refFmncMStep = htonl64(rec->refFmncMStep);
	uint _ixVDir = htonl(rec->ixVDir);

	const char* vals[] = {
		(char*) &_refFmncMFile,
		(char*) &_refFmncMStep,
		(char*) &_ixVDir
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFileMStep_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFileMStep_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMFileMStep::insertRst(
			ListFmncRMFileMStep& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMFileMStep::updateRec(
			FmncRMFileMStep* rec
		) {
	PGresult* res;

	ubigint _refFmncMFile = htonl64(rec->refFmncMFile);
	ubigint _refFmncMStep = htonl64(rec->refFmncMStep);
	uint _ixVDir = htonl(rec->ixVDir);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMFile,
		(char*) &_refFmncMStep,
		(char*) &_ixVDir,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFileMStep_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFileMStep_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMFileMStep::updateRst(
			ListFmncRMFileMStep& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMFileMStep::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMFileMStep_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFileMStep_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMFileMStep::loadRecByRef(
			ubigint ref
			, FmncRMFileMStep** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMFileMStep_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMFileMStep::loadRefsBySte(
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

	return loadRefsByStmt("TblFmncRMFileMStep_loadRefsBySte", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

