/**
  * \file FmncRMUserMUsergroup.cpp
  * database access for table TblFmncRMUserMUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMUserMUsergroup.h"

/******************************************************************************
 class FmncRMUserMUsergroup
 ******************************************************************************/

FmncRMUserMUsergroup::FmncRMUserMUsergroup(
			const ubigint ref
			, const ubigint refFmncMUser
			, const ubigint refFmncMUsergroup
			, const uint ixFmncVUserlevel
		) {

	this->ref = ref;
	this->refFmncMUser = refFmncMUser;
	this->refFmncMUsergroup = refFmncMUsergroup;
	this->ixFmncVUserlevel = ixFmncVUserlevel;
};

bool FmncRMUserMUsergroup::operator==(
			const FmncRMUserMUsergroup& comp
		) {
	return false;
};

bool FmncRMUserMUsergroup::operator!=(
			const FmncRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMUserMUsergroup
 ******************************************************************************/

ListFmncRMUserMUsergroup::ListFmncRMUserMUsergroup() {
};

ListFmncRMUserMUsergroup::ListFmncRMUserMUsergroup(
			const ListFmncRMUserMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMUserMUsergroup(*(src.nodes[i]));
};

ListFmncRMUserMUsergroup::~ListFmncRMUserMUsergroup() {
	clear();
};

void ListFmncRMUserMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMUserMUsergroup::size() const {
	return(nodes.size());
};

void ListFmncRMUserMUsergroup::append(
			FmncRMUserMUsergroup* rec
		) {
	nodes.push_back(rec);
};

FmncRMUserMUsergroup* ListFmncRMUserMUsergroup::operator[](
			const uint ix
		) {
	FmncRMUserMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMUserMUsergroup& ListFmncRMUserMUsergroup::operator=(
			const ListFmncRMUserMUsergroup& src
		) {
	FmncRMUserMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMUserMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMUserMUsergroup::operator==(
			const ListFmncRMUserMUsergroup& comp
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

bool ListFmncRMUserMUsergroup::operator!=(
			const ListFmncRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMUserMUsergroup
 ******************************************************************************/

TblFmncRMUserMUsergroup::TblFmncRMUserMUsergroup() {
};

TblFmncRMUserMUsergroup::~TblFmncRMUserMUsergroup() {
};

bool TblFmncRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblFmncRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	return 0;
};

void TblFmncRMUserMUsergroup::insertRec(
			FmncRMUserMUsergroup* rec
		) {
};

ubigint TblFmncRMUserMUsergroup::insertNewRec(
			FmncRMUserMUsergroup** rec
			, const ubigint refFmncMUser
			, const ubigint refFmncMUsergroup
			, const uint ixFmncVUserlevel
		) {
	ubigint retval = 0;
	FmncRMUserMUsergroup* _rec = NULL;

	_rec = new FmncRMUserMUsergroup(0, refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMUserMUsergroup::appendNewRecToRst(
			ListFmncRMUserMUsergroup& rst
			, FmncRMUserMUsergroup** rec
			, const ubigint refFmncMUser
			, const ubigint refFmncMUsergroup
			, const uint ixFmncVUserlevel
		) {
	ubigint retval = 0;
	FmncRMUserMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMUserMUsergroup::insertRst(
			ListFmncRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblFmncRMUserMUsergroup::updateRec(
			FmncRMUserMUsergroup* rec
		) {
};

void TblFmncRMUserMUsergroup::updateRst(
			ListFmncRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblFmncRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, FmncRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblFmncRMUserMUsergroup::loadRstByUsg(
			ubigint refFmncMUsergroup
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblFmncRMUserMUsergroup::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblFmncRMUserMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	ubigint numload = 0;
	FmncRMUserMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMUserMUsergroup
 ******************************************************************************/

MyTblFmncRMUserMUsergroup::MyTblFmncRMUserMUsergroup() : TblFmncRMUserMUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMUserMUsergroup::~MyTblFmncRMUserMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMUserMUsergroup (refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMUserMUsergroup SET refFmncMUser = ?, refFmncMUsergroup = ?, ixFmncVUserlevel = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMUserMUsergroup WHERE ref = ?", false);
};

bool MyTblFmncRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncRMUserMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMUserMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMUserMUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMUserMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMUser = atoll((char*) dbrow[1]); else _rec->refFmncMUser = 0;
		if (dbrow[2]) _rec->refFmncMUsergroup = atoll((char*) dbrow[2]); else _rec->refFmncMUsergroup = 0;
		if (dbrow[3]) _rec->ixFmncVUserlevel = atol((char*) dbrow[3]); else _rec->ixFmncVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMUserMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMUserMUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMUserMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMUser = atoll((char*) dbrow[1]); else rec->refFmncMUser = 0;
			if (dbrow[2]) rec->refFmncMUsergroup = atoll((char*) dbrow[2]); else rec->refFmncMUsergroup = 0;
			if (dbrow[3]) rec->ixFmncVUserlevel = atol((char*) dbrow[3]); else rec->ixFmncVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMUserMUsergroup::insertRec(
			FmncRMUserMUsergroup* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixFmncVUserlevel,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMUserMUsergroup / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMUserMUsergroup / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMUserMUsergroup::insertRst(
			ListFmncRMUserMUsergroup& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMUserMUsergroup::updateRec(
			FmncRMUserMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMUsergroup,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixFmncVUserlevel,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMUserMUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMUserMUsergroup / stmtUpdateRec)\n");
};

void MyTblFmncRMUserMUsergroup::updateRst(
			ListFmncRMUserMUsergroup& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMUserMUsergroup / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMUserMUsergroup / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, FmncRMUserMUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMUserMUsergroup WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMUserMUsergroup::loadRstByUsg(
			ubigint refFmncMUsergroup
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel FROM TblFmncRMUserMUsergroup WHERE refFmncMUsergroup = " + to_string(refFmncMUsergroup) + "", append, rst);
};

ubigint MyTblFmncRMUserMUsergroup::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel FROM TblFmncRMUserMUsergroup WHERE refFmncMUser = " + to_string(refFmncMUser) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMUserMUsergroup
 ******************************************************************************/

PgTblFmncRMUserMUsergroup::PgTblFmncRMUserMUsergroup() : TblFmncRMUserMUsergroup(), PgTable() {
};

PgTblFmncRMUserMUsergroup::~PgTblFmncRMUserMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMUserMUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMUserMUsergroup_insertRec", "INSERT INTO TblFmncRMUserMUsergroup (refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMUserMUsergroup_updateRec", "UPDATE TblFmncRMUserMUsergroup SET refFmncMUser = $1, refFmncMUsergroup = $2, ixFmncVUserlevel = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMUserMUsergroup_removeRecByRef", "DELETE FROM TblFmncRMUserMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMUserMUsergroup_loadRecByRef", "SELECT ref, refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel FROM TblFmncRMUserMUsergroup WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMUserMUsergroup_loadRstByUsg", "SELECT ref, refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel FROM TblFmncRMUserMUsergroup WHERE refFmncMUsergroup = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMUserMUsergroup_loadRstByUsr", "SELECT ref, refFmncMUser, refFmncMUsergroup, ixFmncVUserlevel FROM TblFmncRMUserMUsergroup WHERE refFmncMUser = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMUserMUsergroup::loadRec(
			PGresult* res
			, FmncRMUserMUsergroup** rec
		) {
	char* ptr;

	FmncRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMUserMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "ixfmncvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixFmncVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMUserMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMUserMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "ixfmncvuserlevel")
		};

		while (numread < numrow) {
			rec = new FmncRMUserMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixFmncVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMUserMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUserMUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncRMUserMUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUserMUsergroup / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMUserMUsergroup::insertRec(
			FmncRMUserMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	uint _ixFmncVUserlevel = htonl(rec->ixFmncVUserlevel);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_refFmncMUsergroup,
		(char*) &_ixFmncVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMUserMUsergroup_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUserMUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMUserMUsergroup::insertRst(
			ListFmncRMUserMUsergroup& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMUserMUsergroup::updateRec(
			FmncRMUserMUsergroup* rec
		) {
	PGresult* res;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	uint _ixFmncVUserlevel = htonl(rec->ixFmncVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_refFmncMUsergroup,
		(char*) &_ixFmncVUserlevel,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncRMUserMUsergroup_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUserMUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMUserMUsergroup::updateRst(
			ListFmncRMUserMUsergroup& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMUserMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMUserMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMUserMUsergroup_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, FmncRMUserMUsergroup** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMUserMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMUserMUsergroup::loadRstByUsg(
			ubigint refFmncMUsergroup
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	ubigint _refFmncMUsergroup = htonl64(refFmncMUsergroup);

	const char* vals[] = {
		(char*) &_refFmncMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncRMUserMUsergroup_loadRstByUsg", 1, vals, l, f, append, rst);
};

ubigint PgTblFmncRMUserMUsergroup::loadRstByUsr(
			ubigint refFmncMUser
			, const bool append
			, ListFmncRMUserMUsergroup& rst
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);

	const char* vals[] = {
		(char*) &_refFmncMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncRMUserMUsergroup_loadRstByUsr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

