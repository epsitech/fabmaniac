/**
  * \file FmncAMToolAvl.cpp
  * database access for table TblFmncAMToolAvl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMToolAvl.h"

/******************************************************************************
 class FmncAMToolAvl
 ******************************************************************************/

FmncAMToolAvl::FmncAMToolAvl(
			const ubigint ref
			, const ubigint refFmncMTool
			, const uint x1Startd
			, const uint x2IxVWkday
			, const uint x3Startt
			, const uint x3Stopt
			, const string srefKAvltype
		) {

	this->ref = ref;
	this->refFmncMTool = refFmncMTool;
	this->x1Startd = x1Startd;
	this->x2IxVWkday = x2IxVWkday;
	this->x3Startt = x3Startt;
	this->x3Stopt = x3Stopt;
	this->srefKAvltype = srefKAvltype;
};

bool FmncAMToolAvl::operator==(
			const FmncAMToolAvl& comp
		) {
	return false;
};

bool FmncAMToolAvl::operator!=(
			const FmncAMToolAvl& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMToolAvl
 ******************************************************************************/

ListFmncAMToolAvl::ListFmncAMToolAvl() {
};

ListFmncAMToolAvl::ListFmncAMToolAvl(
			const ListFmncAMToolAvl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMToolAvl(*(src.nodes[i]));
};

ListFmncAMToolAvl::~ListFmncAMToolAvl() {
	clear();
};

void ListFmncAMToolAvl::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMToolAvl::size() const {
	return(nodes.size());
};

void ListFmncAMToolAvl::append(
			FmncAMToolAvl* rec
		) {
	nodes.push_back(rec);
};

FmncAMToolAvl* ListFmncAMToolAvl::operator[](
			const uint ix
		) {
	FmncAMToolAvl* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMToolAvl& ListFmncAMToolAvl::operator=(
			const ListFmncAMToolAvl& src
		) {
	FmncAMToolAvl* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMToolAvl(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMToolAvl::operator==(
			const ListFmncAMToolAvl& comp
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

bool ListFmncAMToolAvl::operator!=(
			const ListFmncAMToolAvl& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMToolAvl
 ******************************************************************************/

TblFmncAMToolAvl::TblFmncAMToolAvl() {
};

TblFmncAMToolAvl::~TblFmncAMToolAvl() {
};

bool TblFmncAMToolAvl::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolAvl** rec
		) {
	return false;
};

ubigint TblFmncAMToolAvl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolAvl& rst
		) {
	return 0;
};

void TblFmncAMToolAvl::insertRec(
			FmncAMToolAvl* rec
		) {
};

ubigint TblFmncAMToolAvl::insertNewRec(
			FmncAMToolAvl** rec
			, const ubigint refFmncMTool
			, const uint x1Startd
			, const uint x2IxVWkday
			, const uint x3Startt
			, const uint x3Stopt
			, const string srefKAvltype
		) {
	ubigint retval = 0;
	FmncAMToolAvl* _rec = NULL;

	_rec = new FmncAMToolAvl(0, refFmncMTool, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMToolAvl::appendNewRecToRst(
			ListFmncAMToolAvl& rst
			, FmncAMToolAvl** rec
			, const ubigint refFmncMTool
			, const uint x1Startd
			, const uint x2IxVWkday
			, const uint x3Startt
			, const uint x3Stopt
			, const string srefKAvltype
		) {
	ubigint retval = 0;
	FmncAMToolAvl* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMTool, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMToolAvl::insertRst(
			ListFmncAMToolAvl& rst
			, bool transact
		) {
};

void TblFmncAMToolAvl::updateRec(
			FmncAMToolAvl* rec
		) {
};

void TblFmncAMToolAvl::updateRst(
			ListFmncAMToolAvl& rst
			, bool transact
		) {
};

void TblFmncAMToolAvl::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMToolAvl::loadRecByRef(
			ubigint ref
			, FmncAMToolAvl** rec
		) {
	return false;
};

ubigint TblFmncAMToolAvl::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncAMToolAvl::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMToolAvl& rst
		) {
	ubigint numload = 0;
	FmncAMToolAvl* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMToolAvl
 ******************************************************************************/

MyTblFmncAMToolAvl::MyTblFmncAMToolAvl() : TblFmncAMToolAvl(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMToolAvl::~MyTblFmncAMToolAvl() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMToolAvl::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMToolAvl (refFmncMTool, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMToolAvl SET refFmncMTool = ?, x1Startd = ?, x2IxVWkday = ?, x3Startt = ?, x3Stopt = ?, srefKAvltype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMToolAvl WHERE ref = ?", false);
};

bool MyTblFmncAMToolAvl::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolAvl** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMToolAvl* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMToolAvl / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMToolAvl();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMTool = atoll((char*) dbrow[1]); else _rec->refFmncMTool = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->x2IxVWkday = atol((char*) dbrow[3]); else _rec->x2IxVWkday = 0;
		if (dbrow[4]) _rec->x3Startt = atol((char*) dbrow[4]); else _rec->x3Startt = 0;
		if (dbrow[5]) _rec->x3Stopt = atol((char*) dbrow[5]); else _rec->x3Stopt = 0;
		if (dbrow[6]) _rec->srefKAvltype.assign(dbrow[6], dblengths[6]); else _rec->srefKAvltype = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMToolAvl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolAvl& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMToolAvl* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMToolAvl / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMToolAvl();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMTool = atoll((char*) dbrow[1]); else rec->refFmncMTool = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->x2IxVWkday = atol((char*) dbrow[3]); else rec->x2IxVWkday = 0;
			if (dbrow[4]) rec->x3Startt = atol((char*) dbrow[4]); else rec->x3Startt = 0;
			if (dbrow[5]) rec->x3Stopt = atol((char*) dbrow[5]); else rec->x3Stopt = 0;
			if (dbrow[6]) rec->srefKAvltype.assign(dbrow[6], dblengths[6]); else rec->srefKAvltype = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMToolAvl::insertRec(
			FmncAMToolAvl* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[5] = rec->srefKAvltype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxVWkday,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x3Startt,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x3Stopt,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefKAvltype.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolAvl / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolAvl / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMToolAvl::insertRst(
			ListFmncAMToolAvl& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMToolAvl::updateRec(
			FmncAMToolAvl* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->srefKAvltype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x2IxVWkday,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->x3Startt,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->x3Stopt,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->srefKAvltype.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolAvl / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolAvl / stmtUpdateRec)\n");
};

void MyTblFmncAMToolAvl::updateRst(
			ListFmncAMToolAvl& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMToolAvl::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolAvl / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolAvl / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMToolAvl::loadRecByRef(
			ubigint ref
			, FmncAMToolAvl** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMToolAvl WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncAMToolAvl::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncAMToolAvl WHERE refFmncMTool = " + to_string(refFmncMTool) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMToolAvl
 ******************************************************************************/

PgTblFmncAMToolAvl::PgTblFmncAMToolAvl() : TblFmncAMToolAvl(), PgTable() {
};

PgTblFmncAMToolAvl::~PgTblFmncAMToolAvl() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMToolAvl::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMToolAvl_insertRec", "INSERT INTO TblFmncAMToolAvl (refFmncMTool, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMToolAvl_updateRec", "UPDATE TblFmncAMToolAvl SET refFmncMTool = $1, x1Startd = $2, x2IxVWkday = $3, x3Startt = $4, x3Stopt = $5, srefKAvltype = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMToolAvl_removeRecByRef", "DELETE FROM TblFmncAMToolAvl WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMToolAvl_loadRecByRef", "SELECT ref, refFmncMTool, x1Startd, x2IxVWkday, x3Startt, x3Stopt, srefKAvltype FROM TblFmncAMToolAvl WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAMToolAvl_loadRefsByTol", "SELECT ref FROM TblFmncAMToolAvl WHERE refFmncMTool = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAMToolAvl::loadRec(
			PGresult* res
			, FmncAMToolAvl** rec
		) {
	char* ptr;

	FmncAMToolAvl* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMToolAvl();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x2ixvwkday"),
			PQfnumber(res, "x3startt"),
			PQfnumber(res, "x3stopt"),
			PQfnumber(res, "srefkavltype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2IxVWkday = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x3Startt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x3Stopt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefKAvltype.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMToolAvl::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMToolAvl& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMToolAvl* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x2ixvwkday"),
			PQfnumber(res, "x3startt"),
			PQfnumber(res, "x3stopt"),
			PQfnumber(res, "srefkavltype")
		};

		while (numread < numrow) {
			rec = new FmncAMToolAvl();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2IxVWkday = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x3Startt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x3Stopt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefKAvltype.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMToolAvl::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMToolAvl** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolAvl / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMToolAvl::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolAvl** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMToolAvl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolAvl& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMToolAvl::insertRec(
			FmncAMToolAvl* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x2IxVWkday = htonl(rec->x2IxVWkday);
	uint _x3Startt = htonl(rec->x3Startt);
	uint _x3Stopt = htonl(rec->x3Stopt);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1Startd,
		(char*) &_x2IxVWkday,
		(char*) &_x3Startt,
		(char*) &_x3Stopt,
		rec->srefKAvltype.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncAMToolAvl_insertRec", 6, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolAvl_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMToolAvl::insertRst(
			ListFmncAMToolAvl& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMToolAvl::updateRec(
			FmncAMToolAvl* rec
		) {
	PGresult* res;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x2IxVWkday = htonl(rec->x2IxVWkday);
	uint _x3Startt = htonl(rec->x3Startt);
	uint _x3Stopt = htonl(rec->x3Stopt);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1Startd,
		(char*) &_x2IxVWkday,
		(char*) &_x3Startt,
		(char*) &_x3Stopt,
		rec->srefKAvltype.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMToolAvl_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolAvl_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMToolAvl::updateRst(
			ListFmncAMToolAvl& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMToolAvl::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMToolAvl_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolAvl_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMToolAvl::loadRecByRef(
			ubigint ref
			, FmncAMToolAvl** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMToolAvl_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncAMToolAvl::loadRefsByTol(
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

	return loadRefsByStmt("TblFmncAMToolAvl_loadRefsByTol", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

