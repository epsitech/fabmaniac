/**
  * \file FmncJMOrgTitle.cpp
  * database access for table TblFmncJMOrgTitle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJMOrgTitle.h"

/******************************************************************************
 class FmncJMOrgTitle
 ******************************************************************************/

FmncJMOrgTitle::FmncJMOrgTitle(
			const ubigint ref
			, const ubigint refFmncMOrg
			, const uint x1Startd
			, const string Title
		) {

	this->ref = ref;
	this->refFmncMOrg = refFmncMOrg;
	this->x1Startd = x1Startd;
	this->Title = Title;
};

bool FmncJMOrgTitle::operator==(
			const FmncJMOrgTitle& comp
		) {
	return false;
};

bool FmncJMOrgTitle::operator!=(
			const FmncJMOrgTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJMOrgTitle
 ******************************************************************************/

ListFmncJMOrgTitle::ListFmncJMOrgTitle() {
};

ListFmncJMOrgTitle::ListFmncJMOrgTitle(
			const ListFmncJMOrgTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJMOrgTitle(*(src.nodes[i]));
};

ListFmncJMOrgTitle::~ListFmncJMOrgTitle() {
	clear();
};

void ListFmncJMOrgTitle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJMOrgTitle::size() const {
	return(nodes.size());
};

void ListFmncJMOrgTitle::append(
			FmncJMOrgTitle* rec
		) {
	nodes.push_back(rec);
};

FmncJMOrgTitle* ListFmncJMOrgTitle::operator[](
			const uint ix
		) {
	FmncJMOrgTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJMOrgTitle& ListFmncJMOrgTitle::operator=(
			const ListFmncJMOrgTitle& src
		) {
	FmncJMOrgTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJMOrgTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJMOrgTitle::operator==(
			const ListFmncJMOrgTitle& comp
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

bool ListFmncJMOrgTitle::operator!=(
			const ListFmncJMOrgTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJMOrgTitle
 ******************************************************************************/

TblFmncJMOrgTitle::TblFmncJMOrgTitle() {
};

TblFmncJMOrgTitle::~TblFmncJMOrgTitle() {
};

bool TblFmncJMOrgTitle::loadRecBySQL(
			const string& sqlstr
			, FmncJMOrgTitle** rec
		) {
	return false;
};

ubigint TblFmncJMOrgTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	return 0;
};

void TblFmncJMOrgTitle::insertRec(
			FmncJMOrgTitle* rec
		) {
};

ubigint TblFmncJMOrgTitle::insertNewRec(
			FmncJMOrgTitle** rec
			, const ubigint refFmncMOrg
			, const uint x1Startd
			, const string Title
		) {
	ubigint retval = 0;
	FmncJMOrgTitle* _rec = NULL;

	_rec = new FmncJMOrgTitle(0, refFmncMOrg, x1Startd, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJMOrgTitle::appendNewRecToRst(
			ListFmncJMOrgTitle& rst
			, FmncJMOrgTitle** rec
			, const ubigint refFmncMOrg
			, const uint x1Startd
			, const string Title
		) {
	ubigint retval = 0;
	FmncJMOrgTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMOrg, x1Startd, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJMOrgTitle::insertRst(
			ListFmncJMOrgTitle& rst
			, bool transact
		) {
};

void TblFmncJMOrgTitle::updateRec(
			FmncJMOrgTitle* rec
		) {
};

void TblFmncJMOrgTitle::updateRst(
			ListFmncJMOrgTitle& rst
			, bool transact
		) {
};

void TblFmncJMOrgTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJMOrgTitle::loadRecByRef(
			ubigint ref
			, FmncJMOrgTitle** rec
		) {
	return false;
};

ubigint TblFmncJMOrgTitle::loadRefsByOrg(
			ubigint refFmncMOrg
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncJMOrgTitle::loadRstByOrg(
			ubigint refFmncMOrg
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	return 0;
};

ubigint TblFmncJMOrgTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	ubigint numload = 0;
	FmncJMOrgTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJMOrgTitle
 ******************************************************************************/

MyTblFmncJMOrgTitle::MyTblFmncJMOrgTitle() : TblFmncJMOrgTitle(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJMOrgTitle::~MyTblFmncJMOrgTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJMOrgTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJMOrgTitle (refFmncMOrg, x1Startd, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJMOrgTitle SET refFmncMOrg = ?, x1Startd = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJMOrgTitle WHERE ref = ?", false);
};

bool MyTblFmncJMOrgTitle::loadRecBySQL(
			const string& sqlstr
			, FmncJMOrgTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJMOrgTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMOrgTitle / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJMOrgTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMOrg = atoll((char*) dbrow[1]); else _rec->refFmncMOrg = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJMOrgTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJMOrgTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJMOrgTitle / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJMOrgTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMOrg = atoll((char*) dbrow[1]); else rec->refFmncMOrg = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJMOrgTitle::insertRec(
			FmncJMOrgTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMOrg,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMOrgTitle / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMOrgTitle / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJMOrgTitle::insertRst(
			ListFmncJMOrgTitle& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJMOrgTitle::updateRec(
			FmncJMOrgTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMOrg,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMOrgTitle / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMOrgTitle / stmtUpdateRec)\n");
};

void MyTblFmncJMOrgTitle::updateRst(
			ListFmncJMOrgTitle& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJMOrgTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJMOrgTitle / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJMOrgTitle / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJMOrgTitle::loadRecByRef(
			ubigint ref
			, FmncJMOrgTitle** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJMOrgTitle WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncJMOrgTitle::loadRefsByOrg(
			ubigint refFmncMOrg
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncJMOrgTitle WHERE refFmncMOrg = " + to_string(refFmncMOrg) + "", append, refs);
};

ubigint MyTblFmncJMOrgTitle::loadRstByOrg(
			ubigint refFmncMOrg
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncMOrg, x1Startd, Title FROM TblFmncJMOrgTitle WHERE refFmncMOrg = " + to_string(refFmncMOrg) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJMOrgTitle
 ******************************************************************************/

PgTblFmncJMOrgTitle::PgTblFmncJMOrgTitle() : TblFmncJMOrgTitle(), PgTable() {
};

PgTblFmncJMOrgTitle::~PgTblFmncJMOrgTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJMOrgTitle::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJMOrgTitle_insertRec", "INSERT INTO TblFmncJMOrgTitle (refFmncMOrg, x1Startd, Title) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMOrgTitle_updateRec", "UPDATE TblFmncJMOrgTitle SET refFmncMOrg = $1, x1Startd = $2, Title = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMOrgTitle_removeRecByRef", "DELETE FROM TblFmncJMOrgTitle WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJMOrgTitle_loadRecByRef", "SELECT ref, refFmncMOrg, x1Startd, Title FROM TblFmncJMOrgTitle WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJMOrgTitle_loadRefsByOrg", "SELECT ref FROM TblFmncJMOrgTitle WHERE refFmncMOrg = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJMOrgTitle_loadRstByOrg", "SELECT ref, refFmncMOrg, x1Startd, Title FROM TblFmncJMOrgTitle WHERE refFmncMOrg = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJMOrgTitle::loadRec(
			PGresult* res
			, FmncJMOrgTitle** rec
		) {
	char* ptr;

	FmncJMOrgTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJMOrgTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJMOrgTitle::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJMOrgTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new FmncJMOrgTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJMOrgTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJMOrgTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMOrgTitle / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJMOrgTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMOrgTitle / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJMOrgTitle::loadRecBySQL(
			const string& sqlstr
			, FmncJMOrgTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJMOrgTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJMOrgTitle::insertRec(
			FmncJMOrgTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	uint _x1Startd = htonl(rec->x1Startd);

	const char* vals[] = {
		(char*) &_refFmncMOrg,
		(char*) &_x1Startd,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncJMOrgTitle_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMOrgTitle_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJMOrgTitle::insertRst(
			ListFmncJMOrgTitle& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJMOrgTitle::updateRec(
			FmncJMOrgTitle* rec
		) {
	PGresult* res;

	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	uint _x1Startd = htonl(rec->x1Startd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMOrg,
		(char*) &_x1Startd,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncJMOrgTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMOrgTitle_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJMOrgTitle::updateRst(
			ListFmncJMOrgTitle& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJMOrgTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJMOrgTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJMOrgTitle_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJMOrgTitle::loadRecByRef(
			ubigint ref
			, FmncJMOrgTitle** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJMOrgTitle_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncJMOrgTitle::loadRefsByOrg(
			ubigint refFmncMOrg
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMOrg = htonl64(refFmncMOrg);

	const char* vals[] = {
		(char*) &_refFmncMOrg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncJMOrgTitle_loadRefsByOrg", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncJMOrgTitle::loadRstByOrg(
			ubigint refFmncMOrg
			, const bool append
			, ListFmncJMOrgTitle& rst
		) {
	ubigint _refFmncMOrg = htonl64(refFmncMOrg);

	const char* vals[] = {
		(char*) &_refFmncMOrg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJMOrgTitle_loadRstByOrg", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

