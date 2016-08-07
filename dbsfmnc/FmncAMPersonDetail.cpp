/**
  * \file FmncAMPersonDetail.cpp
  * database access for table TblFmncAMPersonDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMPersonDetail.h"

/******************************************************************************
 class FmncAMPersonDetail
 ******************************************************************************/

FmncAMPersonDetail::FmncAMPersonDetail(
			const ubigint ref
			, const ubigint refFmncMPerson
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refFmncMPerson = refFmncMPerson;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool FmncAMPersonDetail::operator==(
			const FmncAMPersonDetail& comp
		) {
	return false;
};

bool FmncAMPersonDetail::operator!=(
			const FmncAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMPersonDetail
 ******************************************************************************/

ListFmncAMPersonDetail::ListFmncAMPersonDetail() {
};

ListFmncAMPersonDetail::ListFmncAMPersonDetail(
			const ListFmncAMPersonDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMPersonDetail(*(src.nodes[i]));
};

ListFmncAMPersonDetail::~ListFmncAMPersonDetail() {
	clear();
};

void ListFmncAMPersonDetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMPersonDetail::size() const {
	return(nodes.size());
};

void ListFmncAMPersonDetail::append(
			FmncAMPersonDetail* rec
		) {
	nodes.push_back(rec);
};

FmncAMPersonDetail* ListFmncAMPersonDetail::operator[](
			const uint ix
		) {
	FmncAMPersonDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMPersonDetail& ListFmncAMPersonDetail::operator=(
			const ListFmncAMPersonDetail& src
		) {
	FmncAMPersonDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMPersonDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMPersonDetail::operator==(
			const ListFmncAMPersonDetail& comp
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

bool ListFmncAMPersonDetail::operator!=(
			const ListFmncAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMPersonDetail
 ******************************************************************************/

TblFmncAMPersonDetail::TblFmncAMPersonDetail() {
};

TblFmncAMPersonDetail::~TblFmncAMPersonDetail() {
};

bool TblFmncAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, FmncAMPersonDetail** rec
		) {
	return false;
};

ubigint TblFmncAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMPersonDetail& rst
		) {
	return 0;
};

void TblFmncAMPersonDetail::insertRec(
			FmncAMPersonDetail* rec
		) {
};

ubigint TblFmncAMPersonDetail::insertNewRec(
			FmncAMPersonDetail** rec
			, const ubigint refFmncMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	FmncAMPersonDetail* _rec = NULL;

	_rec = new FmncAMPersonDetail(0, refFmncMPerson, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMPersonDetail::appendNewRecToRst(
			ListFmncAMPersonDetail& rst
			, FmncAMPersonDetail** rec
			, const ubigint refFmncMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	FmncAMPersonDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMPerson, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMPersonDetail::insertRst(
			ListFmncAMPersonDetail& rst
			, bool transact
		) {
};

void TblFmncAMPersonDetail::updateRec(
			FmncAMPersonDetail* rec
		) {
};

void TblFmncAMPersonDetail::updateRst(
			ListFmncAMPersonDetail& rst
			, bool transact
		) {
};

void TblFmncAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMPersonDetail::loadRecByRef(
			ubigint ref
			, FmncAMPersonDetail** rec
		) {
	return false;
};

bool TblFmncAMPersonDetail::loadRecByPrsTyp(
			ubigint refFmncMPerson
			, string x1SrefKType
			, FmncAMPersonDetail** rec
		) {
	return false;
};

ubigint TblFmncAMPersonDetail::loadRefsByPrs(
			ubigint refFmncMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncAMPersonDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMPersonDetail& rst
		) {
	ubigint numload = 0;
	FmncAMPersonDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMPersonDetail
 ******************************************************************************/

MyTblFmncAMPersonDetail::MyTblFmncAMPersonDetail() : TblFmncAMPersonDetail(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMPersonDetail::~MyTblFmncAMPersonDetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMPersonDetail (refFmncMPerson, x1SrefKType, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMPersonDetail SET refFmncMPerson = ?, x1SrefKType = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMPersonDetail WHERE ref = ?", false);
};

bool MyTblFmncAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, FmncAMPersonDetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMPersonDetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMPersonDetail / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMPersonDetail();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMPerson = atoll((char*) dbrow[1]); else _rec->refFmncMPerson = 0;
		if (dbrow[2]) _rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKType = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMPersonDetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMPersonDetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMPersonDetail / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMPersonDetail();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMPerson = atoll((char*) dbrow[1]); else rec->refFmncMPerson = 0;
			if (dbrow[2]) rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else rec->x1SrefKType = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMPersonDetail::insertRec(
			FmncAMPersonDetail* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMPersonDetail / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMPersonDetail / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMPersonDetail::insertRst(
			ListFmncAMPersonDetail& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMPersonDetail::updateRec(
			FmncAMPersonDetail* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMPerson,&(l[0]),&(n[0]),&(e[0])), 
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMPersonDetail / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMPersonDetail / stmtUpdateRec)\n");
};

void MyTblFmncAMPersonDetail::updateRst(
			ListFmncAMPersonDetail& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMPersonDetail / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMPersonDetail / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMPersonDetail::loadRecByRef(
			ubigint ref
			, FmncAMPersonDetail** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMPersonDetail WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncAMPersonDetail::loadRecByPrsTyp(
			ubigint refFmncMPerson
			, string x1SrefKType
			, FmncAMPersonDetail** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMPerson, x1SrefKType, Val FROM TblFmncAMPersonDetail WHERE refFmncMPerson = " + to_string(refFmncMPerson) + " AND x1SrefKType = '" + x1SrefKType + "'", rec);
};

ubigint MyTblFmncAMPersonDetail::loadRefsByPrs(
			ubigint refFmncMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncAMPersonDetail WHERE refFmncMPerson = " + to_string(refFmncMPerson) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMPersonDetail
 ******************************************************************************/

PgTblFmncAMPersonDetail::PgTblFmncAMPersonDetail() : TblFmncAMPersonDetail(), PgTable() {
};

PgTblFmncAMPersonDetail::~PgTblFmncAMPersonDetail() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMPersonDetail::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMPersonDetail_insertRec", "INSERT INTO TblFmncAMPersonDetail (refFmncMPerson, x1SrefKType, Val) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMPersonDetail_updateRec", "UPDATE TblFmncAMPersonDetail SET refFmncMPerson = $1, x1SrefKType = $2, Val = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMPersonDetail_removeRecByRef", "DELETE FROM TblFmncAMPersonDetail WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMPersonDetail_loadRecByRef", "SELECT ref, refFmncMPerson, x1SrefKType, Val FROM TblFmncAMPersonDetail WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAMPersonDetail_loadRecByPrsTyp", "SELECT ref, refFmncMPerson, x1SrefKType, Val FROM TblFmncAMPersonDetail WHERE refFmncMPerson = $1 AND x1SrefKType = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMPersonDetail_loadRefsByPrs", "SELECT ref FROM TblFmncAMPersonDetail WHERE refFmncMPerson = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAMPersonDetail::loadRec(
			PGresult* res
			, FmncAMPersonDetail** rec
		) {
	char* ptr;

	FmncAMPersonDetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMPersonDetail();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMPersonDetail::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMPersonDetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMPersonDetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new FmncAMPersonDetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMPersonDetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMPersonDetail / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, FmncAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMPersonDetail::insertRec(
			FmncAMPersonDetail* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMPersonDetail_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMPersonDetail_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMPersonDetail::insertRst(
			ListFmncAMPersonDetail& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMPersonDetail::updateRec(
			FmncAMPersonDetail* rec
		) {
	PGresult* res;

	ubigint _refFmncMPerson = htonl64(rec->refFmncMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
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

	res = PQexecPrepared(dbs, "TblFmncAMPersonDetail_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMPersonDetail_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMPersonDetail::updateRst(
			ListFmncAMPersonDetail& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMPersonDetail::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMPersonDetail_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMPersonDetail_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMPersonDetail::loadRecByRef(
			ubigint ref
			, FmncAMPersonDetail** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMPersonDetail_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncAMPersonDetail::loadRecByPrsTyp(
			ubigint refFmncMPerson
			, string x1SrefKType
			, FmncAMPersonDetail** rec
		) {
	ubigint _refFmncMPerson = htonl64(refFmncMPerson);

	const char* vals[] = {
		(char*) &_refFmncMPerson,
		x1SrefKType.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRecByStmt("TblFmncAMPersonDetail_loadRecByPrsTyp", 2, vals, l, f, rec);
};

ubigint PgTblFmncAMPersonDetail::loadRefsByPrs(
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

	return loadRefsByStmt("TblFmncAMPersonDetail_loadRefsByPrs", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

