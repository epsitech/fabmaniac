/**
  * \file FmncRMFabuserMTool.cpp
  * database access for table TblFmncRMFabuserMTool (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMFabuserMTool.h"

/******************************************************************************
 class FmncRMFabuserMTool
 ******************************************************************************/

FmncRMFabuserMTool::FmncRMFabuserMTool(
			const ubigint ref
			, const ubigint refFmncMFabuser
			, const ubigint refFmncMTool
			, const ubigint trnRefFmncMPerson
			, const string srefKLvl
		) {

	this->ref = ref;
	this->refFmncMFabuser = refFmncMFabuser;
	this->refFmncMTool = refFmncMTool;
	this->trnRefFmncMPerson = trnRefFmncMPerson;
	this->srefKLvl = srefKLvl;
};

bool FmncRMFabuserMTool::operator==(
			const FmncRMFabuserMTool& comp
		) {
	return false;
};

bool FmncRMFabuserMTool::operator!=(
			const FmncRMFabuserMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMFabuserMTool
 ******************************************************************************/

ListFmncRMFabuserMTool::ListFmncRMFabuserMTool() {
};

ListFmncRMFabuserMTool::ListFmncRMFabuserMTool(
			const ListFmncRMFabuserMTool& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMFabuserMTool(*(src.nodes[i]));
};

ListFmncRMFabuserMTool::~ListFmncRMFabuserMTool() {
	clear();
};

void ListFmncRMFabuserMTool::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMFabuserMTool::size() const {
	return(nodes.size());
};

void ListFmncRMFabuserMTool::append(
			FmncRMFabuserMTool* rec
		) {
	nodes.push_back(rec);
};

FmncRMFabuserMTool* ListFmncRMFabuserMTool::operator[](
			const uint ix
		) {
	FmncRMFabuserMTool* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMFabuserMTool& ListFmncRMFabuserMTool::operator=(
			const ListFmncRMFabuserMTool& src
		) {
	FmncRMFabuserMTool* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMFabuserMTool(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMFabuserMTool::operator==(
			const ListFmncRMFabuserMTool& comp
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

bool ListFmncRMFabuserMTool::operator!=(
			const ListFmncRMFabuserMTool& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMFabuserMTool
 ******************************************************************************/

TblFmncRMFabuserMTool::TblFmncRMFabuserMTool() {
};

TblFmncRMFabuserMTool::~TblFmncRMFabuserMTool() {
};

bool TblFmncRMFabuserMTool::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabuserMTool** rec
		) {
	return false;
};

ubigint TblFmncRMFabuserMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabuserMTool& rst
		) {
	return 0;
};

void TblFmncRMFabuserMTool::insertRec(
			FmncRMFabuserMTool* rec
		) {
};

ubigint TblFmncRMFabuserMTool::insertNewRec(
			FmncRMFabuserMTool** rec
			, const ubigint refFmncMFabuser
			, const ubigint refFmncMTool
			, const ubigint trnRefFmncMPerson
			, const string srefKLvl
		) {
	ubigint retval = 0;
	FmncRMFabuserMTool* _rec = NULL;

	_rec = new FmncRMFabuserMTool(0, refFmncMFabuser, refFmncMTool, trnRefFmncMPerson, srefKLvl);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMFabuserMTool::appendNewRecToRst(
			ListFmncRMFabuserMTool& rst
			, FmncRMFabuserMTool** rec
			, const ubigint refFmncMFabuser
			, const ubigint refFmncMTool
			, const ubigint trnRefFmncMPerson
			, const string srefKLvl
		) {
	ubigint retval = 0;
	FmncRMFabuserMTool* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMFabuser, refFmncMTool, trnRefFmncMPerson, srefKLvl);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMFabuserMTool::insertRst(
			ListFmncRMFabuserMTool& rst
			, bool transact
		) {
};

void TblFmncRMFabuserMTool::updateRec(
			FmncRMFabuserMTool* rec
		) {
};

void TblFmncRMFabuserMTool::updateRst(
			ListFmncRMFabuserMTool& rst
			, bool transact
		) {
};

void TblFmncRMFabuserMTool::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMFabuserMTool::loadRecByRef(
			ubigint ref
			, FmncRMFabuserMTool** rec
		) {
	return false;
};

ubigint TblFmncRMFabuserMTool::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMFabuserMTool& rst
		) {
	ubigint numload = 0;
	FmncRMFabuserMTool* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMFabuserMTool
 ******************************************************************************/

MyTblFmncRMFabuserMTool::MyTblFmncRMFabuserMTool() : TblFmncRMFabuserMTool(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMFabuserMTool::~MyTblFmncRMFabuserMTool() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMFabuserMTool::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMFabuserMTool (refFmncMFabuser, refFmncMTool, trnRefFmncMPerson, srefKLvl) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMFabuserMTool SET refFmncMFabuser = ?, refFmncMTool = ?, trnRefFmncMPerson = ?, srefKLvl = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMFabuserMTool WHERE ref = ?", false);
};

bool MyTblFmncRMFabuserMTool::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabuserMTool** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMFabuserMTool* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFabuserMTool / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMFabuserMTool();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMFabuser = atoll((char*) dbrow[1]); else _rec->refFmncMFabuser = 0;
		if (dbrow[2]) _rec->refFmncMTool = atoll((char*) dbrow[2]); else _rec->refFmncMTool = 0;
		if (dbrow[3]) _rec->trnRefFmncMPerson = atoll((char*) dbrow[3]); else _rec->trnRefFmncMPerson = 0;
		if (dbrow[4]) _rec->srefKLvl.assign(dbrow[4], dblengths[4]); else _rec->srefKLvl = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMFabuserMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabuserMTool& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMFabuserMTool* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMFabuserMTool / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMFabuserMTool();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMFabuser = atoll((char*) dbrow[1]); else rec->refFmncMFabuser = 0;
			if (dbrow[2]) rec->refFmncMTool = atoll((char*) dbrow[2]); else rec->refFmncMTool = 0;
			if (dbrow[3]) rec->trnRefFmncMPerson = atoll((char*) dbrow[3]); else rec->trnRefFmncMPerson = 0;
			if (dbrow[4]) rec->srefKLvl.assign(dbrow[4], dblengths[4]); else rec->srefKLvl = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMFabuserMTool::insertRec(
			FmncRMFabuserMTool* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->srefKLvl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFabuser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMTool,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->trnRefFmncMPerson,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefKLvl.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabuserMTool / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabuserMTool / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMFabuserMTool::insertRst(
			ListFmncRMFabuserMTool& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMFabuserMTool::updateRec(
			FmncRMFabuserMTool* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->srefKLvl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMFabuser,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMTool,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->trnRefFmncMPerson,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->srefKLvl.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabuserMTool / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabuserMTool / stmtUpdateRec)\n");
};

void MyTblFmncRMFabuserMTool::updateRst(
			ListFmncRMFabuserMTool& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMFabuserMTool::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMFabuserMTool / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMFabuserMTool / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMFabuserMTool::loadRecByRef(
			ubigint ref
			, FmncRMFabuserMTool** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMFabuserMTool WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMFabuserMTool
 ******************************************************************************/

PgTblFmncRMFabuserMTool::PgTblFmncRMFabuserMTool() : TblFmncRMFabuserMTool(), PgTable() {
};

PgTblFmncRMFabuserMTool::~PgTblFmncRMFabuserMTool() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMFabuserMTool::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMFabuserMTool_insertRec", "INSERT INTO TblFmncRMFabuserMTool (refFmncMFabuser, refFmncMTool, trnRefFmncMPerson, srefKLvl) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFabuserMTool_updateRec", "UPDATE TblFmncRMFabuserMTool SET refFmncMFabuser = $1, refFmncMTool = $2, trnRefFmncMPerson = $3, srefKLvl = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMFabuserMTool_removeRecByRef", "DELETE FROM TblFmncRMFabuserMTool WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMFabuserMTool_loadRecByRef", "SELECT ref, refFmncMFabuser, refFmncMTool, trnRefFmncMPerson, srefKLvl FROM TblFmncRMFabuserMTool WHERE ref = $1", 1, NULL);
};

bool PgTblFmncRMFabuserMTool::loadRec(
			PGresult* res
			, FmncRMFabuserMTool** rec
		) {
	char* ptr;

	FmncRMFabuserMTool* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMFabuserMTool();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfabuser"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "trnreffmncmperson"),
			PQfnumber(res, "srefklvl")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMFabuser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->trnRefFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefKLvl.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMFabuserMTool::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMFabuserMTool& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMFabuserMTool* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmfabuser"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "trnreffmncmperson"),
			PQfnumber(res, "srefklvl")
		};

		while (numread < numrow) {
			rec = new FmncRMFabuserMTool();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMFabuser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->trnRefFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefKLvl.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMFabuserMTool::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMFabuserMTool** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabuserMTool / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMFabuserMTool::loadRecBySQL(
			const string& sqlstr
			, FmncRMFabuserMTool** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMFabuserMTool::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMFabuserMTool& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMFabuserMTool::insertRec(
			FmncRMFabuserMTool* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMFabuser = htonl64(rec->refFmncMFabuser);
	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _trnRefFmncMPerson = htonl64(rec->trnRefFmncMPerson);

	const char* vals[] = {
		(char*) &_refFmncMFabuser,
		(char*) &_refFmncMTool,
		(char*) &_trnRefFmncMPerson,
		rec->srefKLvl.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncRMFabuserMTool_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabuserMTool_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMFabuserMTool::insertRst(
			ListFmncRMFabuserMTool& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMFabuserMTool::updateRec(
			FmncRMFabuserMTool* rec
		) {
	PGresult* res;

	ubigint _refFmncMFabuser = htonl64(rec->refFmncMFabuser);
	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _trnRefFmncMPerson = htonl64(rec->trnRefFmncMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMFabuser,
		(char*) &_refFmncMTool,
		(char*) &_trnRefFmncMPerson,
		rec->srefKLvl.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncRMFabuserMTool_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabuserMTool_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMFabuserMTool::updateRst(
			ListFmncRMFabuserMTool& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMFabuserMTool::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMFabuserMTool_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMFabuserMTool_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMFabuserMTool::loadRecByRef(
			ubigint ref
			, FmncRMFabuserMTool** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMFabuserMTool_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

