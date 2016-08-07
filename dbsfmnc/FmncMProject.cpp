/**
  * \file FmncMProject.cpp
  * database access for table TblFmncMProject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMProject.h"

/******************************************************************************
 class FmncMProject
 ******************************************************************************/

FmncMProject::FmncMProject(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->Title = Title;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->Comment = Comment;
};

bool FmncMProject::operator==(
			const FmncMProject& comp
		) {
	return false;
};

bool FmncMProject::operator!=(
			const FmncMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMProject
 ******************************************************************************/

ListFmncMProject::ListFmncMProject() {
};

ListFmncMProject::ListFmncMProject(
			const ListFmncMProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMProject(*(src.nodes[i]));
};

ListFmncMProject::~ListFmncMProject() {
	clear();
};

void ListFmncMProject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMProject::size() const {
	return(nodes.size());
};

void ListFmncMProject::append(
			FmncMProject* rec
		) {
	nodes.push_back(rec);
};

FmncMProject* ListFmncMProject::operator[](
			const uint ix
		) {
	FmncMProject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMProject& ListFmncMProject::operator=(
			const ListFmncMProject& src
		) {
	FmncMProject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMProject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMProject::operator==(
			const ListFmncMProject& comp
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

bool ListFmncMProject::operator!=(
			const ListFmncMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMProject
 ******************************************************************************/

TblFmncMProject::TblFmncMProject() {
};

TblFmncMProject::~TblFmncMProject() {
};

bool TblFmncMProject::loadRecBySQL(
			const string& sqlstr
			, FmncMProject** rec
		) {
	return false;
};

ubigint TblFmncMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMProject& rst
		) {
	return 0;
};

void TblFmncMProject::insertRec(
			FmncMProject* rec
		) {
};

ubigint TblFmncMProject::insertNewRec(
			FmncMProject** rec
			, const ubigint grp
			, const ubigint own
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMProject* _rec = NULL;

	_rec = new FmncMProject(0, grp, own, Title, refJState, ixVState, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMProject::appendNewRecToRst(
			ListFmncMProject& rst
			, FmncMProject** rec
			, const ubigint grp
			, const ubigint own
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMProject* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, Title, refJState, ixVState, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMProject::insertRst(
			ListFmncMProject& rst
			, bool transact
		) {
};

void TblFmncMProject::updateRec(
			FmncMProject* rec
		) {
};

void TblFmncMProject::updateRst(
			ListFmncMProject& rst
			, bool transact
		) {
};

void TblFmncMProject::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMProject::loadRecByRef(
			ubigint ref
			, FmncMProject** rec
		) {
	return false;
};

bool TblFmncMProject::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMProject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMProject& rst
		) {
	ubigint numload = 0;
	FmncMProject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMProject
 ******************************************************************************/

MyTblFmncMProject::MyTblFmncMProject() : TblFmncMProject(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMProject::~MyTblFmncMProject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMProject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMProject (grp, own, Title, refJState, ixVState, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMProject SET grp = ?, own = ?, Title = ?, refJState = ?, ixVState = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMProject WHERE ref = ?", false);
};

bool MyTblFmncMProject::loadRecBySQL(
			const string& sqlstr
			, FmncMProject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMProject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMProject / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMProject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->refJState = atoll((char*) dbrow[4]); else _rec->refJState = 0;
		if (dbrow[5]) _rec->ixVState = atol((char*) dbrow[5]); else _rec->ixVState = 0;
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMProject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMProject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMProject / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMProject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->refJState = atoll((char*) dbrow[4]); else rec->refJState = 0;
			if (dbrow[5]) rec->ixVState = atol((char*) dbrow[5]); else rec->ixVState = 0;
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMProject::insertRec(
			FmncMProject* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->Title.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJState,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVState,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMProject / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMProject / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMProject::insertRst(
			ListFmncMProject& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMProject::updateRec(
			FmncMProject* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->Title.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refJState,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVState,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMProject / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMProject / stmtUpdateRec)\n");
};

void MyTblFmncMProject::updateRst(
			ListFmncMProject& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMProject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMProject / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMProject / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMProject::loadRecByRef(
			ubigint ref
			, FmncMProject** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMProject WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncMProject::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblFmncMProject WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMProject
 ******************************************************************************/

PgTblFmncMProject::PgTblFmncMProject() : TblFmncMProject(), PgTable() {
};

PgTblFmncMProject::~PgTblFmncMProject() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMProject::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMProject_insertRec", "INSERT INTO TblFmncMProject (grp, own, Title, refJState, ixVState, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMProject_updateRec", "UPDATE TblFmncMProject SET grp = $1, own = $2, Title = $3, refJState = $4, ixVState = $5, Comment = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMProject_removeRecByRef", "DELETE FROM TblFmncMProject WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMProject_loadRecByRef", "SELECT ref, grp, own, Title, refJState, ixVState, Comment FROM TblFmncMProject WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMProject_loadTitByRef", "SELECT Title FROM TblFmncMProject WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMProject::loadRec(
			PGresult* res
			, FmncMProject** rec
		) {
	char* ptr;

	FmncMProject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMProject();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMProject::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMProject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMProject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMProject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMProject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMProject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMProject / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMProject::loadRecBySQL(
			const string& sqlstr
			, FmncMProject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMProject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMProject::insertRec(
			FmncMProject* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMProject_insertRec", 6, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMProject_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMProject::insertRst(
			ListFmncMProject& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMProject::updateRec(
			FmncMProject* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMProject_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMProject_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMProject::updateRst(
			ListFmncMProject& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMProject::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMProject_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMProject_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMProject::loadRecByRef(
			ubigint ref
			, FmncMProject** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMProject_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncMProject::loadTitByRef(
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

	return loadStringByStmt("TblFmncMProject_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

