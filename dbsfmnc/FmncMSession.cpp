/**
  * \file FmncMSession.cpp
  * database access for table TblFmncMSession (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMSession.h"

/******************************************************************************
 class FmncMSession
 ******************************************************************************/

FmncMSession::FmncMSession(
			const ubigint ref
			, const ubigint refFmncMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {

	this->ref = ref;
	this->refFmncMUser = refFmncMUser;
	this->start = start;
	this->stop = stop;
	this->Ip = Ip;
};

bool FmncMSession::operator==(
			const FmncMSession& comp
		) {
	return false;
};

bool FmncMSession::operator!=(
			const FmncMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMSession
 ******************************************************************************/

ListFmncMSession::ListFmncMSession() {
};

ListFmncMSession::ListFmncMSession(
			const ListFmncMSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMSession(*(src.nodes[i]));
};

ListFmncMSession::~ListFmncMSession() {
	clear();
};

void ListFmncMSession::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMSession::size() const {
	return(nodes.size());
};

void ListFmncMSession::append(
			FmncMSession* rec
		) {
	nodes.push_back(rec);
};

FmncMSession* ListFmncMSession::operator[](
			const uint ix
		) {
	FmncMSession* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMSession& ListFmncMSession::operator=(
			const ListFmncMSession& src
		) {
	FmncMSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMSession::operator==(
			const ListFmncMSession& comp
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

bool ListFmncMSession::operator!=(
			const ListFmncMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMSession
 ******************************************************************************/

TblFmncMSession::TblFmncMSession() {
};

TblFmncMSession::~TblFmncMSession() {
};

bool TblFmncMSession::loadRecBySQL(
			const string& sqlstr
			, FmncMSession** rec
		) {
	return false;
};

ubigint TblFmncMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMSession& rst
		) {
	return 0;
};

void TblFmncMSession::insertRec(
			FmncMSession* rec
		) {
};

ubigint TblFmncMSession::insertNewRec(
			FmncMSession** rec
			, const ubigint refFmncMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	FmncMSession* _rec = NULL;

	_rec = new FmncMSession(0, refFmncMUser, start, stop, Ip);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMSession::appendNewRecToRst(
			ListFmncMSession& rst
			, FmncMSession** rec
			, const ubigint refFmncMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	FmncMSession* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMUser, start, stop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMSession::insertRst(
			ListFmncMSession& rst
			, bool transact
		) {
};

void TblFmncMSession::updateRec(
			FmncMSession* rec
		) {
};

void TblFmncMSession::updateRst(
			ListFmncMSession& rst
			, bool transact
		) {
};

void TblFmncMSession::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMSession::loadRecByRef(
			ubigint ref
			, FmncMSession** rec
		) {
	return false;
};

ubigint TblFmncMSession::loadRefsByUsr(
			ubigint refFmncMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncMSession::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncMSession& rst
		) {
	return 0;
};

ubigint TblFmncMSession::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMSession& rst
		) {
	ubigint numload = 0;
	FmncMSession* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMSession
 ******************************************************************************/

MyTblFmncMSession::MyTblFmncMSession() : TblFmncMSession(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMSession::~MyTblFmncMSession() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMSession (refFmncMUser, start, stop, Ip) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMSession SET refFmncMUser = ?, start = ?, stop = ?, Ip = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMSession WHERE ref = ?", false);
};

bool MyTblFmncMSession::loadRecBySQL(
			const string& sqlstr
			, FmncMSession** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMSession* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMSession / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMSession();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMUser = atoll((char*) dbrow[1]); else _rec->refFmncMUser = 0;
		if (dbrow[2]) _rec->start = atol((char*) dbrow[2]); else _rec->start = 0;
		if (dbrow[3]) _rec->stop = atol((char*) dbrow[3]); else _rec->stop = 0;
		if (dbrow[4]) _rec->Ip.assign(dbrow[4], dblengths[4]); else _rec->Ip = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMSession& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMSession* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMSession / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMSession();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMUser = atoll((char*) dbrow[1]); else rec->refFmncMUser = 0;
			if (dbrow[2]) rec->start = atol((char*) dbrow[2]); else rec->start = 0;
			if (dbrow[3]) rec->stop = atol((char*) dbrow[3]); else rec->stop = 0;
			if (dbrow[4]) rec->Ip.assign(dbrow[4], dblengths[4]); else rec->Ip = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMSession::insertRec(
			FmncMSession* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMSession / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMSession / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMSession::insertRst(
			ListFmncMSession& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMSession::updateRec(
			FmncMSession* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMSession / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMSession / stmtUpdateRec)\n");
};

void MyTblFmncMSession::updateRst(
			ListFmncMSession& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMSession::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMSession / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMSession / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMSession::loadRecByRef(
			ubigint ref
			, FmncMSession** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMSession WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncMSession::loadRefsByUsr(
			ubigint refFmncMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMSession WHERE refFmncMUser = " + to_string(refFmncMUser) + " ORDER BY start ASC", append, refs);
};

ubigint MyTblFmncMSession::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncMSession& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMUser, start, stop, Ip FROM TblFmncMSession WHERE refFmncMUser = " + to_string(refFmncMUser) + " ORDER BY start ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMSession
 ******************************************************************************/

PgTblFmncMSession::PgTblFmncMSession() : TblFmncMSession(), PgTable() {
};

PgTblFmncMSession::~PgTblFmncMSession() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMSession::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMSession_insertRec", "INSERT INTO TblFmncMSession (refFmncMUser, start, stop, Ip) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSession_updateRec", "UPDATE TblFmncMSession SET refFmncMUser = $1, start = $2, stop = $3, Ip = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSession_removeRecByRef", "DELETE FROM TblFmncMSession WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMSession_loadRecByRef", "SELECT ref, refFmncMUser, start, stop, Ip FROM TblFmncMSession WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMSession_loadRefsByUsr", "SELECT ref FROM TblFmncMSession WHERE refFmncMUser = $1 ORDER BY start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMSession_loadRstByUsr", "SELECT ref, refFmncMUser, start, stop, Ip FROM TblFmncMSession WHERE refFmncMUser = $1 ORDER BY start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMSession::loadRec(
			PGresult* res
			, FmncMSession** rec
		) {
	char* ptr;

	FmncMSession* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMSession();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Ip.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMSession::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMSession& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMSession* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		while (numread < numrow) {
			rec = new FmncMSession();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Ip.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMSession::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMSession** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSession / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncMSession::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncMSession& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSession / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncMSession::loadRecBySQL(
			const string& sqlstr
			, FmncMSession** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMSession& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMSession::insertRec(
			FmncMSession* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMSession_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSession_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMSession::insertRst(
			ListFmncMSession& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMSession::updateRec(
			FmncMSession* rec
		) {
	PGresult* res;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMSession_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSession_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMSession::updateRst(
			ListFmncMSession& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMSession::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMSession_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMSession_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMSession::loadRecByRef(
			ubigint ref
			, FmncMSession** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMSession_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncMSession::loadRefsByUsr(
			ubigint refFmncMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);

	const char* vals[] = {
		(char*) &_refFmncMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncMSession_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncMSession::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncMSession& rst
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);

	const char* vals[] = {
		(char*) &_refFmncMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncMSession_loadRstByUsr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

