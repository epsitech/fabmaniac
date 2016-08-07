/**
  * \file FmncJMPersonLastname.cpp
  * database access for table TblFmncJMPersonLastname (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMPersonLastname.h"

/******************************************************************************
 class FmncJMPersonLastname
 ******************************************************************************/

FmncJMPersonLastname::FmncJMPersonLastname(
			const ubigint ref
			, const ubigint refFmncMPerson
			, const uint x1Startd
			, const string Lastname
		) {

	this->ref = ref;
	this->refFmncMPerson = refFmncMPerson;
	this->x1Startd = x1Startd;
	this->Lastname = Lastname;
};

bool FmncJMPersonLastname::operator==(
			const FmncJMPersonLastname& comp
		) {
	return false;
};

bool FmncJMPersonLastname::operator!=(
			const FmncJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMPersonLastname
 ******************************************************************************/

ListFmncJMPersonLastname::ListFmncJMPersonLastname() {
};

ListFmncJMPersonLastname::ListFmncJMPersonLastname(
			const ListFmncJMPersonLastname& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMPersonLastname(*(src.nodes[i]));
};

ListFmncJMPersonLastname::~ListFmncJMPersonLastname() {
	clear();
};

void ListFmncJMPersonLastname::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMPersonLastname::size() const {
	return(nodes.size());
};

void ListFmncJMPersonLastname::append(
			FmncJMPersonLastname* rec
		) {
	nodes.push_back(rec);
};

FmncJMPersonLastname* ListFmncJMPersonLastname::operator[](
			const uint ix
		) {
	FmncJMPersonLastname* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMPersonLastname& ListFmncJMPersonLastname::operator=(
			const ListFmncJMPersonLastname& src
		) {
	FmncJMPersonLastname* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMPersonLastname(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMPersonLastname::operator==(
			const ListFmncJMPersonLastname& comp
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

bool ListFmncJMPersonLastname::operator!=(
			const ListFmncJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMPersonLastname
 ******************************************************************************/

TblFmncJMPersonLastname::TblFmncJMPersonLastname() {
};

TblFmncJMPersonLastname::~TblFmncJMPersonLastname() {
};

bool TblFmncJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, FmncJMPersonLastname** rec
		) {
	return false;
};

ubigint TblFmncJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	return 0;
};

void TblFmncJMPersonLastname::insertRec(
			FmncJMPersonLastname* rec
		) {
};

ubigint TblFmncJMPersonLastname::insertNewRec(
			FmncJMPersonLastname** rec
			, const ubigint refFmncMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	FmncJMPersonLastname* _rec = NULL;

	_rec = new FmncJMPersonLastname(0, refFmncMPerson, x1Startd, Lastname);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMPersonLastname::appendNewRecToRst(
			ListFmncJMPersonLastname& rst
			, FmncJMPersonLastname** rec
			, const ubigint refFmncMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	FmncJMPersonLastname* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMPerson, x1Startd, Lastname);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMPersonLastname::insertRst(
			ListFmncJMPersonLastname& rst
			, bool transact
		) {
};

void TblFmncJMPersonLastname::updateRec(
			FmncJMPersonLastname* rec
		) {
};

void TblFmncJMPersonLastname::updateRst(
			ListFmncJMPersonLastname& rst
			, bool transact
		) {
};

void TblFmncJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMPersonLastname::loadRecByRef(
			ubigint ref
			, FmncJMPersonLastname** rec
		) {
	return false;
};

bool TblFmncJMPersonLastname::loadRecByPrsSta(
			ubigint refFmncMPerson
			, uint x1Startd
			, FmncJMPersonLastname** rec
		) {
	return false;
};

ubigint TblFmncJMPersonLastname::loadRefsByPrs(
			ubigint refFmncMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncJMPersonLastname::loadRstByPrs(
			ubigint refFmncMPerson
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblFmncJMPersonLastname::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	ubigint numload = 0;
	FmncJMPersonLastname* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMPersonLastname
 ******************************************************************************/

MyTblFmncJMPersonLastname::MyTblFmncJMPersonLastname() : TblFmncJMPersonLastname(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMPersonLastname::~MyTblFmncJMPersonLastname() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMPersonLastname (refFmncMPerson, x1Startd, Lastname) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMPersonLastname SET refFmncMPerson = ?, x1Startd = ?, Lastname = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMPersonLastname WHERE ref = ?", false);
};

bool MyTblFmncJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, FmncJMPersonLastname** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMPersonLastname* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMPersonLastname / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMPersonLastname();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMPerson = atoll((char*) dbrow[1]); else _rec->refFmncMPerson = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Lastname.assign(dbrow[3], dblengths[3]); else _rec->Lastname = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMPersonLastname* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMPersonLastname / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMPersonLastname();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMPerson = atoll((char*) dbrow[1]); else rec->refFmncMPerson = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Lastname.assign(dbrow[3], dblengths[3]); else rec->Lastname = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMPersonLastname::insertRec(
			FmncJMPersonLastname* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMPersonLastname / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMPersonLastname / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMPersonLastname::insertRst(
			ListFmncJMPersonLastname& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMPersonLastname::updateRec(
			FmncJMPersonLastname* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMPersonLastname / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMPersonLastname / stmtUpdateRec)\n");
};

void MyTblFmncJMPersonLastname::updateRst(
			ListFmncJMPersonLastname& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMPersonLastname / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMPersonLastname / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMPersonLastname::loadRecByRef(
			ubigint ref
			, FmncJMPersonLastname** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMPersonLastname WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJMPersonLastname::loadRecByPrsSta(
			ubigint refFmncMPerson
			, uint x1Startd
			, FmncJMPersonLastname** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMPerson, x1Startd, Lastname FROM TblFmncJMPersonLastname WHERE refFmncMPerson = " + to_string(refFmncMPerson) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblFmncJMPersonLastname::loadRefsByPrs(
			ubigint refFmncMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncJMPersonLastname WHERE refFmncMPerson = " + to_string(refFmncMPerson) + "", append, refs);
};

ubigint MyTblFmncJMPersonLastname::loadRstByPrs(
			ubigint refFmncMPerson
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMPerson, x1Startd, Lastname FROM TblFmncJMPersonLastname WHERE refFmncMPerson = " + to_string(refFmncMPerson) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMPersonLastname
 ******************************************************************************/

PgTblFmncJMPersonLastname::PgTblFmncJMPersonLastname() : TblFmncJMPersonLastname(), PgTable() {
};

PgTblFmncJMPersonLastname::~PgTblFmncJMPersonLastname() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMPersonLastname::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMPersonLastname_insertRec", "INSERT INTO TblFmncJMPersonLastname (refFmncMPerson, x1Startd, Lastname) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMPersonLastname_updateRec", "UPDATE TblFmncJMPersonLastname SET refFmncMPerson = $1, x1Startd = $2, Lastname = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMPersonLastname_removeRecByRef", "DELETE FROM TblFmncJMPersonLastname WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMPersonLastname_loadRecByRef", "SELECT ref, refFmncMPerson, x1Startd, Lastname FROM TblFmncJMPersonLastname WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMPersonLastname_loadRecByPrsSta", "SELECT ref, refFmncMPerson, x1Startd, Lastname FROM TblFmncJMPersonLastname WHERE refFmncMPerson = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMPersonLastname_loadRefsByPrs", "SELECT ref FROM TblFmncJMPersonLastname WHERE refFmncMPerson = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMPersonLastname_loadRstByPrs", "SELECT ref, refFmncMPerson, x1Startd, Lastname FROM TblFmncJMPersonLastname WHERE refFmncMPerson = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMPersonLastname::loadRec(
			PGresult* res
			, FmncJMPersonLastname** rec
		) {
	char* ptr;

	FmncJMPersonLastname* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMPersonLastname();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMPersonLastname::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMPersonLastname* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		while (numread < numrow) {
			rec = new FmncJMPersonLastname();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMPersonLastname::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPersonLastname / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMPersonLastname::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPersonLastname / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, FmncJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMPersonLastname::insertRec(
			FmncJMPersonLastname* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	uint _x1Startd = htonl(rec->x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncJMPersonLastname_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPersonLastname_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMPersonLastname::insertRst(
			ListFmncJMPersonLastname& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMPersonLastname::updateRec(
			FmncJMPersonLastname* rec
		) {
	PGresult* res;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	uint _x1Startd = htonl(rec->x1Startd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncJMPersonLastname_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPersonLastname_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMPersonLastname::updateRst(
			ListFmncJMPersonLastname& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMPersonLastname::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMPersonLastname_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMPersonLastname_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMPersonLastname::loadRecByRef(
			ubigint ref
			, FmncJMPersonLastname** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMPersonLastname_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJMPersonLastname::loadRecByPrsSta(
			ubigint refFmncMPerson
			, uint x1Startd
			, FmncJMPersonLastname** rec
		) {
	ubigint _refFmncMPerson = htonl64(refFmncMPerson);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJMPersonLastname_loadRecByPrsSta", 2, vals, l, f, rec);
};

ubigint PgTblFmncJMPersonLastname::loadRefsByPrs(
			ubigint refFmncMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMPerson = htonl64(refFmncMPerson);

	const char* vals[] = {
		(char*) &_refFmncMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncJMPersonLastname_loadRefsByPrs", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncJMPersonLastname::loadRstByPrs(
			ubigint refFmncMPerson
			, const bool append
			, ListFmncJMPersonLastname& rst
		) {
	ubigint _refFmncMPerson = htonl64(refFmncMPerson);

	const char* vals[] = {
		(char*) &_refFmncMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMPersonLastname_loadRstByPrs", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

