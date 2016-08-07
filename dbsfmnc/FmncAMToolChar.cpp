/**
  * \file FmncAMToolChar.cpp
  * database access for table TblFmncAMToolChar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMToolChar.h"

/******************************************************************************
 class FmncAMToolChar
 ******************************************************************************/

FmncAMToolChar::FmncAMToolChar(
			const ubigint ref
			, const ubigint refFmncMTool
			, const string x1OsrefFmncKToolchar
			, const string Val
			, const string Comment
		) {

	this->ref = ref;
	this->refFmncMTool = refFmncMTool;
	this->x1OsrefFmncKToolchar = x1OsrefFmncKToolchar;
	this->Val = Val;
	this->Comment = Comment;
};

bool FmncAMToolChar::operator==(
			const FmncAMToolChar& comp
		) {
	return false;
};

bool FmncAMToolChar::operator!=(
			const FmncAMToolChar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMToolChar
 ******************************************************************************/

ListFmncAMToolChar::ListFmncAMToolChar() {
};

ListFmncAMToolChar::ListFmncAMToolChar(
			const ListFmncAMToolChar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMToolChar(*(src.nodes[i]));
};

ListFmncAMToolChar::~ListFmncAMToolChar() {
	clear();
};

void ListFmncAMToolChar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMToolChar::size() const {
	return(nodes.size());
};

void ListFmncAMToolChar::append(
			FmncAMToolChar* rec
		) {
	nodes.push_back(rec);
};

FmncAMToolChar* ListFmncAMToolChar::operator[](
			const uint ix
		) {
	FmncAMToolChar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMToolChar& ListFmncAMToolChar::operator=(
			const ListFmncAMToolChar& src
		) {
	FmncAMToolChar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMToolChar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMToolChar::operator==(
			const ListFmncAMToolChar& comp
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

bool ListFmncAMToolChar::operator!=(
			const ListFmncAMToolChar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMToolChar
 ******************************************************************************/

TblFmncAMToolChar::TblFmncAMToolChar() {
};

TblFmncAMToolChar::~TblFmncAMToolChar() {
};

bool TblFmncAMToolChar::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolChar** rec
		) {
	return false;
};

ubigint TblFmncAMToolChar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolChar& rst
		) {
	return 0;
};

void TblFmncAMToolChar::insertRec(
			FmncAMToolChar* rec
		) {
};

ubigint TblFmncAMToolChar::insertNewRec(
			FmncAMToolChar** rec
			, const ubigint refFmncMTool
			, const string x1OsrefFmncKToolchar
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAMToolChar* _rec = NULL;

	_rec = new FmncAMToolChar(0, refFmncMTool, x1OsrefFmncKToolchar, Val, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMToolChar::appendNewRecToRst(
			ListFmncAMToolChar& rst
			, FmncAMToolChar** rec
			, const ubigint refFmncMTool
			, const string x1OsrefFmncKToolchar
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAMToolChar* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMTool, x1OsrefFmncKToolchar, Val, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMToolChar::insertRst(
			ListFmncAMToolChar& rst
			, bool transact
		) {
};

void TblFmncAMToolChar::updateRec(
			FmncAMToolChar* rec
		) {
};

void TblFmncAMToolChar::updateRst(
			ListFmncAMToolChar& rst
			, bool transact
		) {
};

void TblFmncAMToolChar::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMToolChar::loadRecByRef(
			ubigint ref
			, FmncAMToolChar** rec
		) {
	return false;
};

ubigint TblFmncAMToolChar::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncAMToolChar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMToolChar& rst
		) {
	ubigint numload = 0;
	FmncAMToolChar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMToolChar
 ******************************************************************************/

MyTblFmncAMToolChar::MyTblFmncAMToolChar() : TblFmncAMToolChar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMToolChar::~MyTblFmncAMToolChar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMToolChar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMToolChar (refFmncMTool, x1OsrefFmncKToolchar, Val, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMToolChar SET refFmncMTool = ?, x1OsrefFmncKToolchar = ?, Val = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMToolChar WHERE ref = ?", false);
};

bool MyTblFmncAMToolChar::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolChar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMToolChar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMToolChar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMToolChar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMTool = atoll((char*) dbrow[1]); else _rec->refFmncMTool = 0;
		if (dbrow[2]) _rec->x1OsrefFmncKToolchar.assign(dbrow[2], dblengths[2]); else _rec->x1OsrefFmncKToolchar = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMToolChar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolChar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMToolChar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMToolChar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMToolChar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMTool = atoll((char*) dbrow[1]); else rec->refFmncMTool = 0;
			if (dbrow[2]) rec->x1OsrefFmncKToolchar.assign(dbrow[2], dblengths[2]); else rec->x1OsrefFmncKToolchar = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMToolChar::insertRec(
			FmncAMToolChar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1OsrefFmncKToolchar.length();
	l[2] = rec->Val.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1OsrefFmncKToolchar.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolChar / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolChar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMToolChar::insertRst(
			ListFmncAMToolChar& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMToolChar::updateRec(
			FmncAMToolChar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->x1OsrefFmncKToolchar.length();
	l[2] = rec->Val.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])), 
		bindCstring((char*) (rec->x1OsrefFmncKToolchar.c_str()),&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolChar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolChar / stmtUpdateRec)\n");
};

void MyTblFmncAMToolChar::updateRst(
			ListFmncAMToolChar& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMToolChar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolChar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolChar / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMToolChar::loadRecByRef(
			ubigint ref
			, FmncAMToolChar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMToolChar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncAMToolChar::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncAMToolChar WHERE refFmncMTool = " + to_string(refFmncMTool) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMToolChar
 ******************************************************************************/

PgTblFmncAMToolChar::PgTblFmncAMToolChar() : TblFmncAMToolChar(), PgTable() {
};

PgTblFmncAMToolChar::~PgTblFmncAMToolChar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMToolChar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMToolChar_insertRec", "INSERT INTO TblFmncAMToolChar (refFmncMTool, x1OsrefFmncKToolchar, Val, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMToolChar_updateRec", "UPDATE TblFmncAMToolChar SET refFmncMTool = $1, x1OsrefFmncKToolchar = $2, Val = $3, Comment = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMToolChar_removeRecByRef", "DELETE FROM TblFmncAMToolChar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMToolChar_loadRecByRef", "SELECT ref, refFmncMTool, x1OsrefFmncKToolchar, Val, Comment FROM TblFmncAMToolChar WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAMToolChar_loadRefsByTol", "SELECT ref FROM TblFmncAMToolChar WHERE refFmncMTool = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAMToolChar::loadRec(
			PGresult* res
			, FmncAMToolChar** rec
		) {
	char* ptr;

	FmncAMToolChar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMToolChar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1osreffmncktoolchar"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1OsrefFmncKToolchar.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMToolChar::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMToolChar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMToolChar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1osreffmncktoolchar"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncAMToolChar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1OsrefFmncKToolchar.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMToolChar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMToolChar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolChar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMToolChar::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolChar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMToolChar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolChar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMToolChar::insertRec(
			FmncAMToolChar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		rec->x1OsrefFmncKToolchar.c_str(),
		rec->Val.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMToolChar_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolChar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMToolChar::insertRst(
			ListFmncAMToolChar& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMToolChar::updateRec(
			FmncAMToolChar* rec
		) {
	PGresult* res;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		rec->x1OsrefFmncKToolchar.c_str(),
		rec->Val.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMToolChar_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolChar_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMToolChar::updateRst(
			ListFmncAMToolChar& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMToolChar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMToolChar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolChar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMToolChar::loadRecByRef(
			ubigint ref
			, FmncAMToolChar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMToolChar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncAMToolChar::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMTool = htonl64(refFmncMTool);

	const char* vals[] = {
		(char*) &_refFmncMTool
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncAMToolChar_loadRefsByTol", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

