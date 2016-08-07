/**
  * \file FmncJAVKeylistKey.cpp
  * database access for table TblFmncJAVKeylistKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncJAVKeylistKey.h"

/******************************************************************************
 class FmncJAVKeylistKey
 ******************************************************************************/

FmncJAVKeylistKey::FmncJAVKeylistKey(
			const ubigint ref
			, const ubigint refFmncAVKeylistKey
			, const uint x1IxFmncVLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refFmncAVKeylistKey = refFmncAVKeylistKey;
	this->x1IxFmncVLocale = x1IxFmncVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool FmncJAVKeylistKey::operator==(
			const FmncJAVKeylistKey& comp
		) {
	return false;
};

bool FmncJAVKeylistKey::operator!=(
			const FmncJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncJAVKeylistKey
 ******************************************************************************/

ListFmncJAVKeylistKey::ListFmncJAVKeylistKey() {
};

ListFmncJAVKeylistKey::ListFmncJAVKeylistKey(
			const ListFmncJAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncJAVKeylistKey(*(src.nodes[i]));
};

ListFmncJAVKeylistKey::~ListFmncJAVKeylistKey() {
	clear();
};

void ListFmncJAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncJAVKeylistKey::size() const {
	return(nodes.size());
};

void ListFmncJAVKeylistKey::append(
			FmncJAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

FmncJAVKeylistKey* ListFmncJAVKeylistKey::operator[](
			const uint ix
		) {
	FmncJAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncJAVKeylistKey& ListFmncJAVKeylistKey::operator=(
			const ListFmncJAVKeylistKey& src
		) {
	FmncJAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncJAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncJAVKeylistKey::operator==(
			const ListFmncJAVKeylistKey& comp
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

bool ListFmncJAVKeylistKey::operator!=(
			const ListFmncJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncJAVKeylistKey
 ******************************************************************************/

TblFmncJAVKeylistKey::TblFmncJAVKeylistKey() {
};

TblFmncJAVKeylistKey::~TblFmncJAVKeylistKey() {
};

bool TblFmncJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, FmncJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblFmncJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	return 0;
};

void TblFmncJAVKeylistKey::insertRec(
			FmncJAVKeylistKey* rec
		) {
};

ubigint TblFmncJAVKeylistKey::insertNewRec(
			FmncJAVKeylistKey** rec
			, const ubigint refFmncAVKeylistKey
			, const uint x1IxFmncVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	FmncJAVKeylistKey* _rec = NULL;

	_rec = new FmncJAVKeylistKey(0, refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncJAVKeylistKey::appendNewRecToRst(
			ListFmncJAVKeylistKey& rst
			, FmncJAVKeylistKey** rec
			, const ubigint refFmncAVKeylistKey
			, const uint x1IxFmncVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	FmncJAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncJAVKeylistKey::insertRst(
			ListFmncJAVKeylistKey& rst
			, bool transact
		) {
};

void TblFmncJAVKeylistKey::updateRec(
			FmncJAVKeylistKey* rec
		) {
};

void TblFmncJAVKeylistKey::updateRst(
			ListFmncJAVKeylistKey& rst
			, bool transact
		) {
};

void TblFmncJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncJAVKeylistKey::loadRecByRef(
			ubigint ref
			, FmncJAVKeylistKey** rec
		) {
	return false;
};

bool TblFmncJAVKeylistKey::loadRecByKlkLcl(
			ubigint refFmncAVKeylistKey
			, uint x1IxFmncVLocale
			, FmncJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblFmncJAVKeylistKey::loadRefsByKlk(
			ubigint refFmncAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncJAVKeylistKey::loadRstByKlk(
			ubigint refFmncAVKeylistKey
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	return 0;
};

bool TblFmncJAVKeylistKey::loadTitByKlkLcl(
			ubigint refFmncAVKeylistKey
			, uint x1IxFmncVLocale
			, string& val
		) {
	return false;
};

ubigint TblFmncJAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	ubigint numload = 0;
	FmncJAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncJAVKeylistKey
 ******************************************************************************/

MyTblFmncJAVKeylistKey::MyTblFmncJAVKeylistKey() : TblFmncJAVKeylistKey(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncJAVKeylistKey::~MyTblFmncJAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncJAVKeylistKey (refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncJAVKeylistKey SET refFmncAVKeylistKey = ?, x1IxFmncVLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncJAVKeylistKey WHERE ref = ?", false);
};

bool MyTblFmncJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, FmncJAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncJAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJAVKeylistKey / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncJAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncAVKeylistKey = atoll((char*) dbrow[1]); else _rec->refFmncAVKeylistKey = 0;
		if (dbrow[2]) _rec->x1IxFmncVLocale = atol((char*) dbrow[2]); else _rec->x1IxFmncVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncJAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncJAVKeylistKey / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncJAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncAVKeylistKey = atoll((char*) dbrow[1]); else rec->refFmncAVKeylistKey = 0;
			if (dbrow[2]) rec->x1IxFmncVLocale = atol((char*) dbrow[2]); else rec->x1IxFmncVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncJAVKeylistKey::insertRec(
			FmncJAVKeylistKey* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxFmncVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJAVKeylistKey / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJAVKeylistKey / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncJAVKeylistKey::insertRst(
			ListFmncJAVKeylistKey& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncJAVKeylistKey::updateRec(
			FmncJAVKeylistKey* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncAVKeylistKey,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1IxFmncVLocale,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJAVKeylistKey / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJAVKeylistKey / stmtUpdateRec)\n");
};

void MyTblFmncJAVKeylistKey::updateRst(
			ListFmncJAVKeylistKey& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncJAVKeylistKey / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncJAVKeylistKey / stmtRemoveRecByRef)\n");
};

bool MyTblFmncJAVKeylistKey::loadRecByRef(
			ubigint ref
			, FmncJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncJAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncJAVKeylistKey::loadRecByKlkLcl(
			ubigint refFmncAVKeylistKey
			, uint x1IxFmncVLocale
			, FmncJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment FROM TblFmncJAVKeylistKey WHERE refFmncAVKeylistKey = " + to_string(refFmncAVKeylistKey) + " AND x1IxFmncVLocale = " + to_string(x1IxFmncVLocale) + "", rec);
};

ubigint MyTblFmncJAVKeylistKey::loadRefsByKlk(
			ubigint refFmncAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncJAVKeylistKey WHERE refFmncAVKeylistKey = " + to_string(refFmncAVKeylistKey) + "", append, refs);
};

ubigint MyTblFmncJAVKeylistKey::loadRstByKlk(
			ubigint refFmncAVKeylistKey
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment FROM TblFmncJAVKeylistKey WHERE refFmncAVKeylistKey = " + to_string(refFmncAVKeylistKey) + " ORDER BY x1IxFmncVLocale ASC", append, rst);
};

bool MyTblFmncJAVKeylistKey::loadTitByKlkLcl(
			ubigint refFmncAVKeylistKey
			, uint x1IxFmncVLocale
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblFmncJAVKeylistKey WHERE refFmncAVKeylistKey = " + to_string(refFmncAVKeylistKey) + " AND x1IxFmncVLocale = " + to_string(x1IxFmncVLocale) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncJAVKeylistKey
 ******************************************************************************/

PgTblFmncJAVKeylistKey::PgTblFmncJAVKeylistKey() : TblFmncJAVKeylistKey(), PgTable() {
};

PgTblFmncJAVKeylistKey::~PgTblFmncJAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncJAVKeylistKey::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncJAVKeylistKey_insertRec", "INSERT INTO TblFmncJAVKeylistKey (refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJAVKeylistKey_updateRec", "UPDATE TblFmncJAVKeylistKey SET refFmncAVKeylistKey = $1, x1IxFmncVLocale = $2, Title = $3, Comment = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJAVKeylistKey_removeRecByRef", "DELETE FROM TblFmncJAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncJAVKeylistKey_loadRecByRef", "SELECT ref, refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment FROM TblFmncJAVKeylistKey WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncJAVKeylistKey_loadRecByKlkLcl", "SELECT ref, refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment FROM TblFmncJAVKeylistKey WHERE refFmncAVKeylistKey = $1 AND x1IxFmncVLocale = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJAVKeylistKey_loadRefsByKlk", "SELECT ref FROM TblFmncJAVKeylistKey WHERE refFmncAVKeylistKey = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJAVKeylistKey_loadRstByKlk", "SELECT ref, refFmncAVKeylistKey, x1IxFmncVLocale, Title, Comment FROM TblFmncJAVKeylistKey WHERE refFmncAVKeylistKey = $1 ORDER BY x1IxFmncVLocale ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncJAVKeylistKey_loadTitByKlkLcl", "SELECT Title FROM TblFmncJAVKeylistKey WHERE refFmncAVKeylistKey = $1 AND x1IxFmncVLocale = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncJAVKeylistKey::loadRec(
			PGresult* res
			, FmncJAVKeylistKey** rec
		) {
	char* ptr;

	FmncJAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncJAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncavkeylistkey"),
			PQfnumber(res, "x1ixfmncvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncAVKeylistKey = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxFmncVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncJAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncJAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncavkeylistkey"),
			PQfnumber(res, "x1ixfmncvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncJAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncAVKeylistKey = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxFmncVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncJAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJAVKeylistKey / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncJAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJAVKeylistKey / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, FmncJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncJAVKeylistKey::insertRec(
			FmncJAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncAVKeylistKey = htonl64(rec->refFmncAVKeylistKey);
	uint _x1IxFmncVLocale = htonl(rec->x1IxFmncVLocale);

	const char* vals[] = {
		(char*) &_refFmncAVKeylistKey,
		(char*) &_x1IxFmncVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncJAVKeylistKey_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJAVKeylistKey_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncJAVKeylistKey::insertRst(
			ListFmncJAVKeylistKey& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncJAVKeylistKey::updateRec(
			FmncJAVKeylistKey* rec
		) {
	PGresult* res;

	ubigint _refFmncAVKeylistKey = htonl64(rec->refFmncAVKeylistKey);
	uint _x1IxFmncVLocale = htonl(rec->x1IxFmncVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncAVKeylistKey,
		(char*) &_x1IxFmncVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncJAVKeylistKey_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJAVKeylistKey_updateRec)\n");

	PQclear(res);
};

void PgTblFmncJAVKeylistKey::updateRst(
			ListFmncJAVKeylistKey& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncJAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncJAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncJAVKeylistKey_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncJAVKeylistKey::loadRecByRef(
			ubigint ref
			, FmncJAVKeylistKey** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncJAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncJAVKeylistKey::loadRecByKlkLcl(
			ubigint refFmncAVKeylistKey
			, uint x1IxFmncVLocale
			, FmncJAVKeylistKey** rec
		) {
	ubigint _refFmncAVKeylistKey = htonl64(refFmncAVKeylistKey);
	uint _x1IxFmncVLocale = htonl(x1IxFmncVLocale);

	const char* vals[] = {
		(char*) &_refFmncAVKeylistKey,
		(char*) &_x1IxFmncVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncJAVKeylistKey_loadRecByKlkLcl", 2, vals, l, f, rec);
};

ubigint PgTblFmncJAVKeylistKey::loadRefsByKlk(
			ubigint refFmncAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncAVKeylistKey = htonl64(refFmncAVKeylistKey);

	const char* vals[] = {
		(char*) &_refFmncAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncJAVKeylistKey_loadRefsByKlk", 1, vals, l, f, append, refs);
};

ubigint PgTblFmncJAVKeylistKey::loadRstByKlk(
			ubigint refFmncAVKeylistKey
			, const bool append
			, ListFmncJAVKeylistKey& rst
		) {
	ubigint _refFmncAVKeylistKey = htonl64(refFmncAVKeylistKey);

	const char* vals[] = {
		(char*) &_refFmncAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncJAVKeylistKey_loadRstByKlk", 1, vals, l, f, append, rst);
};

bool PgTblFmncJAVKeylistKey::loadTitByKlkLcl(
			ubigint refFmncAVKeylistKey
			, uint x1IxFmncVLocale
			, string& val
		) {
	ubigint _refFmncAVKeylistKey = htonl64(refFmncAVKeylistKey);
	uint _x1IxFmncVLocale = htonl(x1IxFmncVLocale);

	const char* vals[] = {
		(char*) &_refFmncAVKeylistKey,
		(char*) &_x1IxFmncVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblFmncJAVKeylistKey_loadTitByKlkLcl", 2, vals, l, f, val);
};

// IP pgTbl --- END

