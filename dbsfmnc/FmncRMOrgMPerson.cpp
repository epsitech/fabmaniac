/**
  * \file FmncRMOrgMPerson.cpp
  * database access for table TblFmncRMOrgMPerson (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMOrgMPerson.h"

/******************************************************************************
 class FmncRMOrgMPerson
 ******************************************************************************/

FmncRMOrgMPerson::FmncRMOrgMPerson(
			const ubigint ref
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refFmncMOrg
			, const ubigint refFmncMPerson
			, const string srefKFunction
		) {

	this->ref = ref;
	this->x1Startd = x1Startd;
	this->x1Stopd = x1Stopd;
	this->refFmncMOrg = refFmncMOrg;
	this->refFmncMPerson = refFmncMPerson;
	this->srefKFunction = srefKFunction;
};

bool FmncRMOrgMPerson::operator==(
			const FmncRMOrgMPerson& comp
		) {
	return false;
};

bool FmncRMOrgMPerson::operator!=(
			const FmncRMOrgMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMOrgMPerson
 ******************************************************************************/

ListFmncRMOrgMPerson::ListFmncRMOrgMPerson() {
};

ListFmncRMOrgMPerson::ListFmncRMOrgMPerson(
			const ListFmncRMOrgMPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMOrgMPerson(*(src.nodes[i]));
};

ListFmncRMOrgMPerson::~ListFmncRMOrgMPerson() {
	clear();
};

void ListFmncRMOrgMPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMOrgMPerson::size() const {
	return(nodes.size());
};

void ListFmncRMOrgMPerson::append(
			FmncRMOrgMPerson* rec
		) {
	nodes.push_back(rec);
};

FmncRMOrgMPerson* ListFmncRMOrgMPerson::operator[](
			const uint ix
		) {
	FmncRMOrgMPerson* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMOrgMPerson& ListFmncRMOrgMPerson::operator=(
			const ListFmncRMOrgMPerson& src
		) {
	FmncRMOrgMPerson* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMOrgMPerson(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMOrgMPerson::operator==(
			const ListFmncRMOrgMPerson& comp
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

bool ListFmncRMOrgMPerson::operator!=(
			const ListFmncRMOrgMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMOrgMPerson
 ******************************************************************************/

TblFmncRMOrgMPerson::TblFmncRMOrgMPerson() {
};

TblFmncRMOrgMPerson::~TblFmncRMOrgMPerson() {
};

bool TblFmncRMOrgMPerson::loadRecBySQL(
			const string& sqlstr
			, FmncRMOrgMPerson** rec
		) {
	return false;
};

ubigint TblFmncRMOrgMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMOrgMPerson& rst
		) {
	return 0;
};

void TblFmncRMOrgMPerson::insertRec(
			FmncRMOrgMPerson* rec
		) {
};

ubigint TblFmncRMOrgMPerson::insertNewRec(
			FmncRMOrgMPerson** rec
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refFmncMOrg
			, const ubigint refFmncMPerson
			, const string srefKFunction
		) {
	ubigint retval = 0;
	FmncRMOrgMPerson* _rec = NULL;

	_rec = new FmncRMOrgMPerson(0, x1Startd, x1Stopd, refFmncMOrg, refFmncMPerson, srefKFunction);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMOrgMPerson::appendNewRecToRst(
			ListFmncRMOrgMPerson& rst
			, FmncRMOrgMPerson** rec
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refFmncMOrg
			, const ubigint refFmncMPerson
			, const string srefKFunction
		) {
	ubigint retval = 0;
	FmncRMOrgMPerson* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startd, x1Stopd, refFmncMOrg, refFmncMPerson, srefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMOrgMPerson::insertRst(
			ListFmncRMOrgMPerson& rst
			, bool transact
		) {
};

void TblFmncRMOrgMPerson::updateRec(
			FmncRMOrgMPerson* rec
		) {
};

void TblFmncRMOrgMPerson::updateRst(
			ListFmncRMOrgMPerson& rst
			, bool transact
		) {
};

void TblFmncRMOrgMPerson::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMOrgMPerson::loadRecByRef(
			ubigint ref
			, FmncRMOrgMPerson** rec
		) {
	return false;
};

ubigint TblFmncRMOrgMPerson::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMOrgMPerson& rst
		) {
	ubigint numload = 0;
	FmncRMOrgMPerson* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMOrgMPerson
 ******************************************************************************/

MyTblFmncRMOrgMPerson::MyTblFmncRMOrgMPerson() : TblFmncRMOrgMPerson(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMOrgMPerson::~MyTblFmncRMOrgMPerson() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMOrgMPerson::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMOrgMPerson (x1Startd, x1Stopd, refFmncMOrg, refFmncMPerson, srefKFunction) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMOrgMPerson SET x1Startd = ?, x1Stopd = ?, refFmncMOrg = ?, refFmncMPerson = ?, srefKFunction = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMOrgMPerson WHERE ref = ?", false);
};

bool MyTblFmncRMOrgMPerson::loadRecBySQL(
			const string& sqlstr
			, FmncRMOrgMPerson** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMOrgMPerson* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMOrgMPerson / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMOrgMPerson();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startd = atol((char*) dbrow[1]); else _rec->x1Startd = 0;
		if (dbrow[2]) _rec->x1Stopd = atol((char*) dbrow[2]); else _rec->x1Stopd = 0;
		if (dbrow[3]) _rec->refFmncMOrg = atoll((char*) dbrow[3]); else _rec->refFmncMOrg = 0;
		if (dbrow[4]) _rec->refFmncMPerson = atoll((char*) dbrow[4]); else _rec->refFmncMPerson = 0;
		if (dbrow[5]) _rec->srefKFunction.assign(dbrow[5], dblengths[5]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMOrgMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMOrgMPerson& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMOrgMPerson* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMOrgMPerson / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMOrgMPerson();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startd = atol((char*) dbrow[1]); else rec->x1Startd = 0;
			if (dbrow[2]) rec->x1Stopd = atol((char*) dbrow[2]); else rec->x1Stopd = 0;
			if (dbrow[3]) rec->refFmncMOrg = atoll((char*) dbrow[3]); else rec->refFmncMOrg = 0;
			if (dbrow[4]) rec->refFmncMPerson = atoll((char*) dbrow[4]); else rec->refFmncMPerson = 0;
			if (dbrow[5]) rec->srefKFunction.assign(dbrow[5], dblengths[5]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMOrgMPerson::insertRec(
			FmncRMOrgMPerson* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Startd,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stopd,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMOrg,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMOrgMPerson / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMOrgMPerson / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMOrgMPerson::insertRst(
			ListFmncRMOrgMPerson& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMOrgMPerson::updateRec(
			FmncRMOrgMPerson* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Startd,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Stopd,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMOrg,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMPerson,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMOrgMPerson / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMOrgMPerson / stmtUpdateRec)\n");
};

void MyTblFmncRMOrgMPerson::updateRst(
			ListFmncRMOrgMPerson& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMOrgMPerson::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMOrgMPerson / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMOrgMPerson / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMOrgMPerson::loadRecByRef(
			ubigint ref
			, FmncRMOrgMPerson** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMOrgMPerson WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMOrgMPerson
 ******************************************************************************/

PgTblFmncRMOrgMPerson::PgTblFmncRMOrgMPerson() : TblFmncRMOrgMPerson(), PgTable() {
};

PgTblFmncRMOrgMPerson::~PgTblFmncRMOrgMPerson() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMOrgMPerson::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMOrgMPerson_insertRec", "INSERT INTO TblFmncRMOrgMPerson (x1Startd, x1Stopd, refFmncMOrg, refFmncMPerson, srefKFunction) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMOrgMPerson_updateRec", "UPDATE TblFmncRMOrgMPerson SET x1Startd = $1, x1Stopd = $2, refFmncMOrg = $3, refFmncMPerson = $4, srefKFunction = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMOrgMPerson_removeRecByRef", "DELETE FROM TblFmncRMOrgMPerson WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMOrgMPerson_loadRecByRef", "SELECT ref, x1Startd, x1Stopd, refFmncMOrg, refFmncMPerson, srefKFunction FROM TblFmncRMOrgMPerson WHERE ref = $1", 1, NULL);
};

bool PgTblFmncRMOrgMPerson::loadRec(
			PGresult* res
			, FmncRMOrgMPerson** rec
		) {
	char* ptr;

	FmncRMOrgMPerson* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMOrgMPerson();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMOrgMPerson::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMOrgMPerson& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMOrgMPerson* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new FmncRMOrgMPerson();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMOrgMPerson::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMOrgMPerson** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMOrgMPerson / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMOrgMPerson::loadRecBySQL(
			const string& sqlstr
			, FmncRMOrgMPerson** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMOrgMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMOrgMPerson& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMOrgMPerson::insertRec(
			FmncRMOrgMPerson* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);

	const char* vals[] = {
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMPerson,
		rec->srefKFunction.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncRMOrgMPerson_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMOrgMPerson_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMOrgMPerson::insertRst(
			ListFmncRMOrgMPerson& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMOrgMPerson::updateRec(
			FmncRMOrgMPerson* rec
		) {
	PGresult* res;

	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMPerson,
		rec->srefKFunction.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncRMOrgMPerson_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMOrgMPerson_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMOrgMPerson::updateRst(
			ListFmncRMOrgMPerson& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMOrgMPerson::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMOrgMPerson_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMOrgMPerson_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMOrgMPerson::loadRecByRef(
			ubigint ref
			, FmncRMOrgMPerson** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMOrgMPerson_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

