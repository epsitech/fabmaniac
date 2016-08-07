/**
  * \file FmncAMToolRes.cpp
  * database access for table TblFmncAMToolRes (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMToolRes.h"

/******************************************************************************
 class FmncAMToolRes
 ******************************************************************************/

FmncAMToolRes::FmncAMToolRes(
			const ubigint ref
			, const ubigint refFmncMTool
			, const ubigint x1RefFmncMFabuser
			, const uint startd
			, const uint startt
			, const uint stopt
			, const string srefKRestype
			, const string Comment
		) {

	this->ref = ref;
	this->refFmncMTool = refFmncMTool;
	this->x1RefFmncMFabuser = x1RefFmncMFabuser;
	this->startd = startd;
	this->startt = startt;
	this->stopt = stopt;
	this->srefKRestype = srefKRestype;
	this->Comment = Comment;
};

bool FmncAMToolRes::operator==(
			const FmncAMToolRes& comp
		) {
	return false;
};

bool FmncAMToolRes::operator!=(
			const FmncAMToolRes& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMToolRes
 ******************************************************************************/

ListFmncAMToolRes::ListFmncAMToolRes() {
};

ListFmncAMToolRes::ListFmncAMToolRes(
			const ListFmncAMToolRes& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMToolRes(*(src.nodes[i]));
};

ListFmncAMToolRes::~ListFmncAMToolRes() {
	clear();
};

void ListFmncAMToolRes::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMToolRes::size() const {
	return(nodes.size());
};

void ListFmncAMToolRes::append(
			FmncAMToolRes* rec
		) {
	nodes.push_back(rec);
};

FmncAMToolRes* ListFmncAMToolRes::operator[](
			const uint ix
		) {
	FmncAMToolRes* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMToolRes& ListFmncAMToolRes::operator=(
			const ListFmncAMToolRes& src
		) {
	FmncAMToolRes* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMToolRes(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMToolRes::operator==(
			const ListFmncAMToolRes& comp
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

bool ListFmncAMToolRes::operator!=(
			const ListFmncAMToolRes& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMToolRes
 ******************************************************************************/

TblFmncAMToolRes::TblFmncAMToolRes() {
};

TblFmncAMToolRes::~TblFmncAMToolRes() {
};

bool TblFmncAMToolRes::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolRes** rec
		) {
	return false;
};

ubigint TblFmncAMToolRes::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolRes& rst
		) {
	return 0;
};

void TblFmncAMToolRes::insertRec(
			FmncAMToolRes* rec
		) {
};

ubigint TblFmncAMToolRes::insertNewRec(
			FmncAMToolRes** rec
			, const ubigint refFmncMTool
			, const ubigint x1RefFmncMFabuser
			, const uint startd
			, const uint startt
			, const uint stopt
			, const string srefKRestype
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAMToolRes* _rec = NULL;

	_rec = new FmncAMToolRes(0, refFmncMTool, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMToolRes::appendNewRecToRst(
			ListFmncAMToolRes& rst
			, FmncAMToolRes** rec
			, const ubigint refFmncMTool
			, const ubigint x1RefFmncMFabuser
			, const uint startd
			, const uint startt
			, const uint stopt
			, const string srefKRestype
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAMToolRes* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMTool, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMToolRes::insertRst(
			ListFmncAMToolRes& rst
			, bool transact
		) {
};

void TblFmncAMToolRes::updateRec(
			FmncAMToolRes* rec
		) {
};

void TblFmncAMToolRes::updateRst(
			ListFmncAMToolRes& rst
			, bool transact
		) {
};

void TblFmncAMToolRes::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMToolRes::loadRecByRef(
			ubigint ref
			, FmncAMToolRes** rec
		) {
	return false;
};

ubigint TblFmncAMToolRes::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMToolRes& rst
		) {
	ubigint numload = 0;
	FmncAMToolRes* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMToolRes
 ******************************************************************************/

MyTblFmncAMToolRes::MyTblFmncAMToolRes() : TblFmncAMToolRes(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMToolRes::~MyTblFmncAMToolRes() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMToolRes::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMToolRes (refFmncMTool, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMToolRes SET refFmncMTool = ?, x1RefFmncMFabuser = ?, startd = ?, startt = ?, stopt = ?, srefKRestype = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMToolRes WHERE ref = ?", false);
};

bool MyTblFmncAMToolRes::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolRes** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMToolRes* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMToolRes / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMToolRes();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMTool = atoll((char*) dbrow[1]); else _rec->refFmncMTool = 0;
		if (dbrow[2]) _rec->x1RefFmncMFabuser = atoll((char*) dbrow[2]); else _rec->x1RefFmncMFabuser = 0;
		if (dbrow[3]) _rec->startd = atol((char*) dbrow[3]); else _rec->startd = 0;
		if (dbrow[4]) _rec->startt = atol((char*) dbrow[4]); else _rec->startt = 0;
		if (dbrow[5]) _rec->stopt = atol((char*) dbrow[5]); else _rec->stopt = 0;
		if (dbrow[6]) _rec->srefKRestype.assign(dbrow[6], dblengths[6]); else _rec->srefKRestype = "";
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMToolRes::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolRes& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMToolRes* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMToolRes / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMToolRes();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMTool = atoll((char*) dbrow[1]); else rec->refFmncMTool = 0;
			if (dbrow[2]) rec->x1RefFmncMFabuser = atoll((char*) dbrow[2]); else rec->x1RefFmncMFabuser = 0;
			if (dbrow[3]) rec->startd = atol((char*) dbrow[3]); else rec->startd = 0;
			if (dbrow[4]) rec->startt = atol((char*) dbrow[4]); else rec->startt = 0;
			if (dbrow[5]) rec->stopt = atol((char*) dbrow[5]); else rec->stopt = 0;
			if (dbrow[6]) rec->srefKRestype.assign(dbrow[6], dblengths[6]); else rec->srefKRestype = "";
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMToolRes::insertRec(
			FmncAMToolRes* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->srefKRestype.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefFmncMFabuser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->startd,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->startt,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->stopt,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefKRestype.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolRes / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolRes / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMToolRes::insertRst(
			ListFmncAMToolRes& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMToolRes::updateRec(
			FmncAMToolRes* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[5] = rec->srefKRestype.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefFmncMFabuser,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->startd,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->startt,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->stopt,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->srefKRestype.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolRes / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolRes / stmtUpdateRec)\n");
};

void MyTblFmncAMToolRes::updateRst(
			ListFmncAMToolRes& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMToolRes::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolRes / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolRes / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMToolRes::loadRecByRef(
			ubigint ref
			, FmncAMToolRes** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMToolRes WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMToolRes
 ******************************************************************************/

PgTblFmncAMToolRes::PgTblFmncAMToolRes() : TblFmncAMToolRes(), PgTable() {
};

PgTblFmncAMToolRes::~PgTblFmncAMToolRes() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMToolRes::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMToolRes_insertRec", "INSERT INTO TblFmncAMToolRes (refFmncMTool, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMToolRes_updateRec", "UPDATE TblFmncAMToolRes SET refFmncMTool = $1, x1RefFmncMFabuser = $2, startd = $3, startt = $4, stopt = $5, srefKRestype = $6, Comment = $7 WHERE ref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMToolRes_removeRecByRef", "DELETE FROM TblFmncAMToolRes WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMToolRes_loadRecByRef", "SELECT ref, refFmncMTool, x1RefFmncMFabuser, startd, startt, stopt, srefKRestype, Comment FROM TblFmncAMToolRes WHERE ref = $1", 1, NULL);
};

bool PgTblFmncAMToolRes::loadRec(
			PGresult* res
			, FmncAMToolRes** rec
		) {
	char* ptr;

	FmncAMToolRes* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMToolRes();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1reffmncmfabuser"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt"),
			PQfnumber(res, "stopt"),
			PQfnumber(res, "srefkrestype"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefFmncMFabuser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->startt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->stopt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefKRestype.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMToolRes::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMToolRes& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMToolRes* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1reffmncmfabuser"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt"),
			PQfnumber(res, "stopt"),
			PQfnumber(res, "srefkrestype"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncAMToolRes();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefFmncMFabuser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->startt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->stopt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefKRestype.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMToolRes::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMToolRes** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolRes / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMToolRes::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolRes** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMToolRes::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolRes& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMToolRes::insertRec(
			FmncAMToolRes* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _x1RefFmncMFabuser = htonl64(rec->x1RefFmncMFabuser);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	uint _stopt = htonl(rec->stopt);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1RefFmncMFabuser,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_stopt,
		rec->srefKRestype.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMToolRes_insertRec", 7, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolRes_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMToolRes::insertRst(
			ListFmncAMToolRes& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMToolRes::updateRec(
			FmncAMToolRes* rec
		) {
	PGresult* res;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _x1RefFmncMFabuser = htonl64(rec->x1RefFmncMFabuser);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	uint _stopt = htonl(rec->stopt);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1RefFmncMFabuser,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_stopt,
		rec->srefKRestype.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMToolRes_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolRes_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMToolRes::updateRst(
			ListFmncAMToolRes& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMToolRes::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMToolRes_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolRes_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMToolRes::loadRecByRef(
			ubigint ref
			, FmncAMToolRes** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMToolRes_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

