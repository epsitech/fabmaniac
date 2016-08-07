/**
  * \file FmncAMOrgDetail.cpp
  * database access for table TblFmncAMOrgDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMOrgDetail.h"

/******************************************************************************
 class FmncAMOrgDetail
 ******************************************************************************/

FmncAMOrgDetail::FmncAMOrgDetail(
			const ubigint ref
			, const ubigint refFmncMOrg
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refFmncMOrg = refFmncMOrg;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool FmncAMOrgDetail::operator==(
			const FmncAMOrgDetail& comp
		) {
	return false;
};

bool FmncAMOrgDetail::operator!=(
			const FmncAMOrgDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMOrgDetail
 ******************************************************************************/

ListFmncAMOrgDetail::ListFmncAMOrgDetail() {
};

ListFmncAMOrgDetail::ListFmncAMOrgDetail(
			const ListFmncAMOrgDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMOrgDetail(*(src.nodes[i]));
};

ListFmncAMOrgDetail::~ListFmncAMOrgDetail() {
	clear();
};

void ListFmncAMOrgDetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMOrgDetail::size() const {
	return(nodes.size());
};

void ListFmncAMOrgDetail::append(
			FmncAMOrgDetail* rec
		) {
	nodes.push_back(rec);
};

FmncAMOrgDetail* ListFmncAMOrgDetail::operator[](
			const uint ix
		) {
	FmncAMOrgDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMOrgDetail& ListFmncAMOrgDetail::operator=(
			const ListFmncAMOrgDetail& src
		) {
	FmncAMOrgDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMOrgDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMOrgDetail::operator==(
			const ListFmncAMOrgDetail& comp
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

bool ListFmncAMOrgDetail::operator!=(
			const ListFmncAMOrgDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMOrgDetail
 ******************************************************************************/

TblFmncAMOrgDetail::TblFmncAMOrgDetail() {
};

TblFmncAMOrgDetail::~TblFmncAMOrgDetail() {
};

bool TblFmncAMOrgDetail::loadRecBySQL(
			const string& sqlstr
			, FmncAMOrgDetail** rec
		) {
	return false;
};

ubigint TblFmncAMOrgDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMOrgDetail& rst
		) {
	return 0;
};

void TblFmncAMOrgDetail::insertRec(
			FmncAMOrgDetail* rec
		) {
};

ubigint TblFmncAMOrgDetail::insertNewRec(
			FmncAMOrgDetail** rec
			, const ubigint refFmncMOrg
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	FmncAMOrgDetail* _rec = NULL;

	_rec = new FmncAMOrgDetail(0, refFmncMOrg, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMOrgDetail::appendNewRecToRst(
			ListFmncAMOrgDetail& rst
			, FmncAMOrgDetail** rec
			, const ubigint refFmncMOrg
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	FmncAMOrgDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMOrg, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMOrgDetail::insertRst(
			ListFmncAMOrgDetail& rst
			, bool transact
		) {
};

void TblFmncAMOrgDetail::updateRec(
			FmncAMOrgDetail* rec
		) {
};

void TblFmncAMOrgDetail::updateRst(
			ListFmncAMOrgDetail& rst
			, bool transact
		) {
};

void TblFmncAMOrgDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMOrgDetail::loadRecByRef(
			ubigint ref
			, FmncAMOrgDetail** rec
		) {
	return false;
};

bool TblFmncAMOrgDetail::loadRecByOrgTyp(
			ubigint refFmncMOrg
			, string x1SrefKType
			, FmncAMOrgDetail** rec
		) {
	return false;
};

ubigint TblFmncAMOrgDetail::loadRefsByOrg(
			ubigint refFmncMOrg
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncAMOrgDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMOrgDetail& rst
		) {
	ubigint numload = 0;
	FmncAMOrgDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMOrgDetail
 ******************************************************************************/

MyTblFmncAMOrgDetail::MyTblFmncAMOrgDetail() : TblFmncAMOrgDetail(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMOrgDetail::~MyTblFmncAMOrgDetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMOrgDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMOrgDetail (refFmncMOrg, x1SrefKType, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMOrgDetail SET refFmncMOrg = ?, x1SrefKType = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMOrgDetail WHERE ref = ?", false);
};

bool MyTblFmncAMOrgDetail::loadRecBySQL(
			const string& sqlstr
			, FmncAMOrgDetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMOrgDetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMOrgDetail / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMOrgDetail();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMOrg = atoll((char*) dbrow[1]); else _rec->refFmncMOrg = 0;
		if (dbrow[2]) _rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKType = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMOrgDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMOrgDetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMOrgDetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMOrgDetail / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMOrgDetail();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMOrg = atoll((char*) dbrow[1]); else rec->refFmncMOrg = 0;
			if (dbrow[2]) rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else rec->x1SrefKType = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMOrgDetail::insertRec(
			FmncAMOrgDetail* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMOrg,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMOrgDetail / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMOrgDetail / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMOrgDetail::insertRst(
			ListFmncAMOrgDetail& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMOrgDetail::updateRec(
			FmncAMOrgDetail* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMOrg,&(l[0]),&(n[0]),&(e[0])), 
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMOrgDetail / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMOrgDetail / stmtUpdateRec)\n");
};

void MyTblFmncAMOrgDetail::updateRst(
			ListFmncAMOrgDetail& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMOrgDetail::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMOrgDetail / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMOrgDetail / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMOrgDetail::loadRecByRef(
			ubigint ref
			, FmncAMOrgDetail** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMOrgDetail WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncAMOrgDetail::loadRecByOrgTyp(
			ubigint refFmncMOrg
			, string x1SrefKType
			, FmncAMOrgDetail** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMOrg, x1SrefKType, Val FROM TblFmncAMOrgDetail WHERE refFmncMOrg = " + to_string(refFmncMOrg) + " AND x1SrefKType = '" + x1SrefKType + "'", rec);
};

ubigint MyTblFmncAMOrgDetail::loadRefsByOrg(
			ubigint refFmncMOrg
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncAMOrgDetail WHERE refFmncMOrg = " + to_string(refFmncMOrg) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMOrgDetail
 ******************************************************************************/

PgTblFmncAMOrgDetail::PgTblFmncAMOrgDetail() : TblFmncAMOrgDetail(), PgTable() {
};

PgTblFmncAMOrgDetail::~PgTblFmncAMOrgDetail() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMOrgDetail::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMOrgDetail_insertRec", "INSERT INTO TblFmncAMOrgDetail (refFmncMOrg, x1SrefKType, Val) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMOrgDetail_updateRec", "UPDATE TblFmncAMOrgDetail SET refFmncMOrg = $1, x1SrefKType = $2, Val = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMOrgDetail_removeRecByRef", "DELETE FROM TblFmncAMOrgDetail WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMOrgDetail_loadRecByRef", "SELECT ref, refFmncMOrg, x1SrefKType, Val FROM TblFmncAMOrgDetail WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAMOrgDetail_loadRecByOrgTyp", "SELECT ref, refFmncMOrg, x1SrefKType, Val FROM TblFmncAMOrgDetail WHERE refFmncMOrg = $1 AND x1SrefKType = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMOrgDetail_loadRefsByOrg", "SELECT ref FROM TblFmncAMOrgDetail WHERE refFmncMOrg = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAMOrgDetail::loadRec(
			PGresult* res
			, FmncAMOrgDetail** rec
		) {
	char* ptr;

	FmncAMOrgDetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMOrgDetail();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMOrgDetail::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMOrgDetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMOrgDetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new FmncAMOrgDetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMOrgDetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMOrgDetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMOrgDetail / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMOrgDetail::loadRecBySQL(
			const string& sqlstr
			, FmncAMOrgDetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMOrgDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMOrgDetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMOrgDetail::insertRec(
			FmncAMOrgDetail* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);

	const char* vals[] = {
		(char*) &_refFmncMOrg,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMOrgDetail_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMOrgDetail_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMOrgDetail::insertRst(
			ListFmncAMOrgDetail& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMOrgDetail::updateRec(
			FmncAMOrgDetail* rec
		) {
	PGresult* res;

	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMOrg,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMOrgDetail_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMOrgDetail_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMOrgDetail::updateRst(
			ListFmncAMOrgDetail& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMOrgDetail::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMOrgDetail_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMOrgDetail_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMOrgDetail::loadRecByRef(
			ubigint ref
			, FmncAMOrgDetail** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMOrgDetail_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncAMOrgDetail::loadRecByOrgTyp(
			ubigint refFmncMOrg
			, string x1SrefKType
			, FmncAMOrgDetail** rec
		) {
	ubigint _refFmncMOrg = htonl64(refFmncMOrg);

	const char* vals[] = {
		(char*) &_refFmncMOrg,
		x1SrefKType.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRecByStmt("TblFmncAMOrgDetail_loadRecByOrgTyp", 2, vals, l, f, rec);
};

ubigint PgTblFmncAMOrgDetail::loadRefsByOrg(
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

	return loadRefsByStmt("TblFmncAMOrgDetail_loadRefsByOrg", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

