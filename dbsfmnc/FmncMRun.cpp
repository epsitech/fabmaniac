/**
  * \file FmncMRun.cpp
  * database access for table TblFmncMRun (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMRun.h"

/******************************************************************************
 class FmncMRun
 ******************************************************************************/

FmncMRun::FmncMRun(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMProject
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refFmncMProject = refFmncMProject;
	this->Title = Title;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->Comment = Comment;
};

bool FmncMRun::operator==(
			const FmncMRun& comp
		) {
	return false;
};

bool FmncMRun::operator!=(
			const FmncMRun& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMRun
 ******************************************************************************/

ListFmncMRun::ListFmncMRun() {
};

ListFmncMRun::ListFmncMRun(
			const ListFmncMRun& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMRun(*(src.nodes[i]));
};

ListFmncMRun::~ListFmncMRun() {
	clear();
};

void ListFmncMRun::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMRun::size() const {
	return(nodes.size());
};

void ListFmncMRun::append(
			FmncMRun* rec
		) {
	nodes.push_back(rec);
};

FmncMRun* ListFmncMRun::operator[](
			const uint ix
		) {
	FmncMRun* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMRun& ListFmncMRun::operator=(
			const ListFmncMRun& src
		) {
	FmncMRun* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMRun(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMRun::operator==(
			const ListFmncMRun& comp
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

bool ListFmncMRun::operator!=(
			const ListFmncMRun& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMRun
 ******************************************************************************/

TblFmncMRun::TblFmncMRun() {
};

TblFmncMRun::~TblFmncMRun() {
};

bool TblFmncMRun::loadRecBySQL(
			const string& sqlstr
			, FmncMRun** rec
		) {
	return false;
};

ubigint TblFmncMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMRun& rst
		) {
	return 0;
};

void TblFmncMRun::insertRec(
			FmncMRun* rec
		) {
};

ubigint TblFmncMRun::insertNewRec(
			FmncMRun** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMProject
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMRun* _rec = NULL;

	_rec = new FmncMRun(0, grp, own, refFmncMProject, Title, refJState, ixVState, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMRun::appendNewRecToRst(
			ListFmncMRun& rst
			, FmncMRun** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMProject
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMRun* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refFmncMProject, Title, refJState, ixVState, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMRun::insertRst(
			ListFmncMRun& rst
			, bool transact
		) {
};

void TblFmncMRun::updateRec(
			FmncMRun* rec
		) {
};

void TblFmncMRun::updateRst(
			ListFmncMRun& rst
			, bool transact
		) {
};

void TblFmncMRun::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMRun::loadRecByRef(
			ubigint ref
			, FmncMRun** rec
		) {
	return false;
};

ubigint TblFmncMRun::loadRefsByPrj(
			ubigint refFmncMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblFmncMRun::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMRun::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMRun& rst
		) {
	ubigint numload = 0;
	FmncMRun* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMRun
 ******************************************************************************/

MyTblFmncMRun::MyTblFmncMRun() : TblFmncMRun(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMRun::~MyTblFmncMRun() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMRun::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMRun (grp, own, refFmncMProject, Title, refJState, ixVState, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMRun SET grp = ?, own = ?, refFmncMProject = ?, Title = ?, refJState = ?, ixVState = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMRun WHERE ref = ?", false);
};

bool MyTblFmncMRun::loadRecBySQL(
			const string& sqlstr
			, FmncMRun** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMRun* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMRun / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMRun();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refFmncMProject = atoll((char*) dbrow[3]); else _rec->refFmncMProject = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->refJState = atoll((char*) dbrow[5]); else _rec->refJState = 0;
		if (dbrow[6]) _rec->ixVState = atol((char*) dbrow[6]); else _rec->ixVState = 0;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMRun& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMRun* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMRun / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMRun();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refFmncMProject = atoll((char*) dbrow[3]); else rec->refFmncMProject = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->refJState = atoll((char*) dbrow[5]); else rec->refJState = 0;
			if (dbrow[6]) rec->ixVState = atol((char*) dbrow[6]); else rec->ixVState = 0;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMRun::insertRec(
			FmncMRun* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->Title.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMProject,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refJState,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVState,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMRun / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMRun / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMRun::insertRst(
			ListFmncMRun& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMRun::updateRec(
			FmncMRun* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->Title.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMProject,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refJState,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVState,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMRun / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMRun / stmtUpdateRec)\n");
};

void MyTblFmncMRun::updateRst(
			ListFmncMRun& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMRun::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMRun / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMRun / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMRun::loadRecByRef(
			ubigint ref
			, FmncMRun** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMRun WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncMRun::loadRefsByPrj(
			ubigint refFmncMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMRun WHERE refFmncMProject = " + to_string(refFmncMProject) + "", append, refs);
};

bool MyTblFmncMRun::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblFmncMRun WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMRun
 ******************************************************************************/

PgTblFmncMRun::PgTblFmncMRun() : TblFmncMRun(), PgTable() {
};

PgTblFmncMRun::~PgTblFmncMRun() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMRun::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMRun_insertRec", "INSERT INTO TblFmncMRun (grp, own, refFmncMProject, Title, refJState, ixVState, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMRun_updateRec", "UPDATE TblFmncMRun SET grp = $1, own = $2, refFmncMProject = $3, Title = $4, refJState = $5, ixVState = $6, Comment = $7 WHERE ref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMRun_removeRecByRef", "DELETE FROM TblFmncMRun WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMRun_loadRecByRef", "SELECT ref, grp, own, refFmncMProject, Title, refJState, ixVState, Comment FROM TblFmncMRun WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMRun_loadRefsByPrj", "SELECT ref FROM TblFmncMRun WHERE refFmncMProject = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMRun_loadTitByRef", "SELECT Title FROM TblFmncMRun WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMRun::loadRec(
			PGresult* res
			, FmncMRun** rec
		) {
	char* ptr;

	FmncMRun* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMRun();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmproject"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMRun::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMRun& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMRun* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmproject"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMRun();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMRun::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMRun** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMRun / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMRun::loadRecBySQL(
			const string& sqlstr
			, FmncMRun** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMRun::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMRun& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMRun::insertRec(
			FmncMRun* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMProject = htonl64(rec->refFmncMProject);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMProject,
		rec->Title.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMRun_insertRec", 7, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMRun_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMRun::insertRst(
			ListFmncMRun& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMRun::updateRec(
			FmncMRun* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMProject = htonl64(rec->refFmncMProject);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMProject,
		rec->Title.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMRun_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMRun_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMRun::updateRst(
			ListFmncMRun& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMRun::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMRun_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMRun_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMRun::loadRecByRef(
			ubigint ref
			, FmncMRun** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMRun_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncMRun::loadRefsByPrj(
			ubigint refFmncMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMProject = htonl64(refFmncMProject);

	const char* vals[] = {
		(char*) &_refFmncMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncMRun_loadRefsByPrj", 1, vals, l, f, append, refs);
};

bool PgTblFmncMRun::loadTitByRef(
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

	return loadStringByStmt("TblFmncMRun_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

