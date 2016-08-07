/**
  * \file FmncMActivity.cpp
  * database access for table TblFmncMActivity (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMActivity.h"

/******************************************************************************
 class FmncMActivity
 ******************************************************************************/

FmncMActivity::FmncMActivity(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint runRefFmncMRun
			, const uint runNum
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->runRefFmncMRun = runRefFmncMRun;
	this->runNum = runNum;
	this->Title = Title;
	this->Comment = Comment;
};

bool FmncMActivity::operator==(
			const FmncMActivity& comp
		) {
	return false;
};

bool FmncMActivity::operator!=(
			const FmncMActivity& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMActivity
 ******************************************************************************/

ListFmncMActivity::ListFmncMActivity() {
};

ListFmncMActivity::ListFmncMActivity(
			const ListFmncMActivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMActivity(*(src.nodes[i]));
};

ListFmncMActivity::~ListFmncMActivity() {
	clear();
};

void ListFmncMActivity::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMActivity::size() const {
	return(nodes.size());
};

void ListFmncMActivity::append(
			FmncMActivity* rec
		) {
	nodes.push_back(rec);
};

FmncMActivity* ListFmncMActivity::operator[](
			const uint ix
		) {
	FmncMActivity* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMActivity& ListFmncMActivity::operator=(
			const ListFmncMActivity& src
		) {
	FmncMActivity* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMActivity(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMActivity::operator==(
			const ListFmncMActivity& comp
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

bool ListFmncMActivity::operator!=(
			const ListFmncMActivity& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMActivity
 ******************************************************************************/

TblFmncMActivity::TblFmncMActivity() {
};

TblFmncMActivity::~TblFmncMActivity() {
};

bool TblFmncMActivity::loadRecBySQL(
			const string& sqlstr
			, FmncMActivity** rec
		) {
	return false;
};

ubigint TblFmncMActivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMActivity& rst
		) {
	return 0;
};

void TblFmncMActivity::insertRec(
			FmncMActivity* rec
		) {
};

ubigint TblFmncMActivity::insertNewRec(
			FmncMActivity** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint runRefFmncMRun
			, const uint runNum
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMActivity* _rec = NULL;

	_rec = new FmncMActivity(0, grp, own, runRefFmncMRun, runNum, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMActivity::appendNewRecToRst(
			ListFmncMActivity& rst
			, FmncMActivity** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint runRefFmncMRun
			, const uint runNum
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMActivity* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, runRefFmncMRun, runNum, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMActivity::insertRst(
			ListFmncMActivity& rst
			, bool transact
		) {
};

void TblFmncMActivity::updateRec(
			FmncMActivity* rec
		) {
};

void TblFmncMActivity::updateRst(
			ListFmncMActivity& rst
			, bool transact
		) {
};

void TblFmncMActivity::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMActivity::loadRecByRef(
			ubigint ref
			, FmncMActivity** rec
		) {
	return false;
};

ubigint TblFmncMActivity::loadRefsByRun(
			ubigint runRefFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblFmncMActivity::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMActivity::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMActivity& rst
		) {
	ubigint numload = 0;
	FmncMActivity* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMActivity
 ******************************************************************************/

MyTblFmncMActivity::MyTblFmncMActivity() : TblFmncMActivity(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMActivity::~MyTblFmncMActivity() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMActivity::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMActivity (grp, own, runRefFmncMRun, runNum, Title, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMActivity SET grp = ?, own = ?, runRefFmncMRun = ?, runNum = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMActivity WHERE ref = ?", false);
};

bool MyTblFmncMActivity::loadRecBySQL(
			const string& sqlstr
			, FmncMActivity** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMActivity* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMActivity / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMActivity();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->runRefFmncMRun = atoll((char*) dbrow[3]); else _rec->runRefFmncMRun = 0;
		if (dbrow[4]) _rec->runNum = atol((char*) dbrow[4]); else _rec->runNum = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMActivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMActivity& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMActivity* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMActivity / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMActivity();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->runRefFmncMRun = atoll((char*) dbrow[3]); else rec->runRefFmncMRun = 0;
			if (dbrow[4]) rec->runNum = atol((char*) dbrow[4]); else rec->runNum = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMActivity::insertRec(
			FmncMActivity* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->Title.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->runRefFmncMRun,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->runNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMActivity / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMActivity / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMActivity::insertRst(
			ListFmncMActivity& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMActivity::updateRec(
			FmncMActivity* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->Title.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->runRefFmncMRun,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->runNum,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMActivity / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMActivity / stmtUpdateRec)\n");
};

void MyTblFmncMActivity::updateRst(
			ListFmncMActivity& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMActivity::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMActivity / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMActivity / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMActivity::loadRecByRef(
			ubigint ref
			, FmncMActivity** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMActivity WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncMActivity::loadRefsByRun(
			ubigint runRefFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMActivity WHERE runRefFmncMRun = " + to_string(runRefFmncMRun) + "", append, refs);
};

bool MyTblFmncMActivity::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblFmncMActivity WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMActivity
 ******************************************************************************/

PgTblFmncMActivity::PgTblFmncMActivity() : TblFmncMActivity(), PgTable() {
};

PgTblFmncMActivity::~PgTblFmncMActivity() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMActivity::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMActivity_insertRec", "INSERT INTO TblFmncMActivity (grp, own, runRefFmncMRun, runNum, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMActivity_updateRec", "UPDATE TblFmncMActivity SET grp = $1, own = $2, runRefFmncMRun = $3, runNum = $4, Title = $5, Comment = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMActivity_removeRecByRef", "DELETE FROM TblFmncMActivity WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMActivity_loadRecByRef", "SELECT ref, grp, own, runRefFmncMRun, runNum, Title, Comment FROM TblFmncMActivity WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMActivity_loadRefsByRun", "SELECT ref FROM TblFmncMActivity WHERE runRefFmncMRun = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMActivity_loadTitByRef", "SELECT Title FROM TblFmncMActivity WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMActivity::loadRec(
			PGresult* res
			, FmncMActivity** rec
		) {
	char* ptr;

	FmncMActivity* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMActivity();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "runreffmncmrun"),
			PQfnumber(res, "runnum"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->runRefFmncMRun = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->runNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMActivity::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMActivity& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMActivity* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "runreffmncmrun"),
			PQfnumber(res, "runnum"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMActivity();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->runRefFmncMRun = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->runNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMActivity::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMActivity** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMActivity / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMActivity::loadRecBySQL(
			const string& sqlstr
			, FmncMActivity** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMActivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMActivity& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMActivity::insertRec(
			FmncMActivity* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _runRefFmncMRun = htonl64(rec->runRefFmncMRun);
	uint _runNum = htonl(rec->runNum);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_runRefFmncMRun,
		(char*) &_runNum,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncMActivity_insertRec", 6, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMActivity_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMActivity::insertRst(
			ListFmncMActivity& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMActivity::updateRec(
			FmncMActivity* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _runRefFmncMRun = htonl64(rec->runRefFmncMRun);
	uint _runNum = htonl(rec->runNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_runRefFmncMRun,
		(char*) &_runNum,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMActivity_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMActivity_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMActivity::updateRst(
			ListFmncMActivity& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMActivity::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMActivity_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMActivity_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMActivity::loadRecByRef(
			ubigint ref
			, FmncMActivity** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMActivity_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncMActivity::loadRefsByRun(
			ubigint runRefFmncMRun
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _runRefFmncMRun = htonl64(runRefFmncMRun);

	const char* vals[] = {
		(char*) &_runRefFmncMRun
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncMActivity_loadRefsByRun", 1, vals, l, f, append, refs);
};

bool PgTblFmncMActivity::loadTitByRef(
			ubigint ref
			, string& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblFmncMActivity_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

