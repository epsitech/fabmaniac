/**
  * \file FmncRMArticleMOrg.cpp
  * database access for table TblFmncRMArticleMOrg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMArticleMOrg.h"

/******************************************************************************
 class FmncRMArticleMOrg
 ******************************************************************************/

FmncRMArticleMOrg::FmncRMArticleMOrg(
			const ubigint ref
			, const ubigint refFmncMArticle
			, const ubigint refFmncMOrg
			, const string Itemno
		) {

	this->ref = ref;
	this->refFmncMArticle = refFmncMArticle;
	this->refFmncMOrg = refFmncMOrg;
	this->Itemno = Itemno;
};

bool FmncRMArticleMOrg::operator==(
			const FmncRMArticleMOrg& comp
		) {
	return false;
};

bool FmncRMArticleMOrg::operator!=(
			const FmncRMArticleMOrg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMArticleMOrg
 ******************************************************************************/

ListFmncRMArticleMOrg::ListFmncRMArticleMOrg() {
};

ListFmncRMArticleMOrg::ListFmncRMArticleMOrg(
			const ListFmncRMArticleMOrg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMArticleMOrg(*(src.nodes[i]));
};

ListFmncRMArticleMOrg::~ListFmncRMArticleMOrg() {
	clear();
};

void ListFmncRMArticleMOrg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMArticleMOrg::size() const {
	return(nodes.size());
};

void ListFmncRMArticleMOrg::append(
			FmncRMArticleMOrg* rec
		) {
	nodes.push_back(rec);
};

FmncRMArticleMOrg* ListFmncRMArticleMOrg::operator[](
			const uint ix
		) {
	FmncRMArticleMOrg* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMArticleMOrg& ListFmncRMArticleMOrg::operator=(
			const ListFmncRMArticleMOrg& src
		) {
	FmncRMArticleMOrg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMArticleMOrg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMArticleMOrg::operator==(
			const ListFmncRMArticleMOrg& comp
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

bool ListFmncRMArticleMOrg::operator!=(
			const ListFmncRMArticleMOrg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMArticleMOrg
 ******************************************************************************/

TblFmncRMArticleMOrg::TblFmncRMArticleMOrg() {
};

TblFmncRMArticleMOrg::~TblFmncRMArticleMOrg() {
};

bool TblFmncRMArticleMOrg::loadRecBySQL(
			const string& sqlstr
			, FmncRMArticleMOrg** rec
		) {
	return false;
};

ubigint TblFmncRMArticleMOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMArticleMOrg& rst
		) {
	return 0;
};

void TblFmncRMArticleMOrg::insertRec(
			FmncRMArticleMOrg* rec
		) {
};

ubigint TblFmncRMArticleMOrg::insertNewRec(
			FmncRMArticleMOrg** rec
			, const ubigint refFmncMArticle
			, const ubigint refFmncMOrg
			, const string Itemno
		) {
	ubigint retval = 0;
	FmncRMArticleMOrg* _rec = NULL;

	_rec = new FmncRMArticleMOrg(0, refFmncMArticle, refFmncMOrg, Itemno);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMArticleMOrg::appendNewRecToRst(
			ListFmncRMArticleMOrg& rst
			, FmncRMArticleMOrg** rec
			, const ubigint refFmncMArticle
			, const ubigint refFmncMOrg
			, const string Itemno
		) {
	ubigint retval = 0;
	FmncRMArticleMOrg* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMArticle, refFmncMOrg, Itemno);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMArticleMOrg::insertRst(
			ListFmncRMArticleMOrg& rst
			, bool transact
		) {
};

void TblFmncRMArticleMOrg::updateRec(
			FmncRMArticleMOrg* rec
		) {
};

void TblFmncRMArticleMOrg::updateRst(
			ListFmncRMArticleMOrg& rst
			, bool transact
		) {
};

void TblFmncRMArticleMOrg::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMArticleMOrg::loadRecByRef(
			ubigint ref
			, FmncRMArticleMOrg** rec
		) {
	return false;
};

ubigint TblFmncRMArticleMOrg::loadRefsByArt(
			ubigint refFmncMArticle
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncRMArticleMOrg::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMArticleMOrg& rst
		) {
	ubigint numload = 0;
	FmncRMArticleMOrg* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMArticleMOrg
 ******************************************************************************/

MyTblFmncRMArticleMOrg::MyTblFmncRMArticleMOrg() : TblFmncRMArticleMOrg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMArticleMOrg::~MyTblFmncRMArticleMOrg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMArticleMOrg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMArticleMOrg (refFmncMArticle, refFmncMOrg, Itemno) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMArticleMOrg SET refFmncMArticle = ?, refFmncMOrg = ?, Itemno = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMArticleMOrg WHERE ref = ?", false);
};

bool MyTblFmncRMArticleMOrg::loadRecBySQL(
			const string& sqlstr
			, FmncRMArticleMOrg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMArticleMOrg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMArticleMOrg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMArticleMOrg();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMArticle = atoll((char*) dbrow[1]); else _rec->refFmncMArticle = 0;
		if (dbrow[2]) _rec->refFmncMOrg = atoll((char*) dbrow[2]); else _rec->refFmncMOrg = 0;
		if (dbrow[3]) _rec->Itemno.assign(dbrow[3], dblengths[3]); else _rec->Itemno = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMArticleMOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMArticleMOrg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMArticleMOrg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMArticleMOrg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMArticleMOrg();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMArticle = atoll((char*) dbrow[1]); else rec->refFmncMArticle = 0;
			if (dbrow[2]) rec->refFmncMOrg = atoll((char*) dbrow[2]); else rec->refFmncMOrg = 0;
			if (dbrow[3]) rec->Itemno.assign(dbrow[3], dblengths[3]); else rec->Itemno = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMArticleMOrg::insertRec(
			FmncRMArticleMOrg* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Itemno.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMArticle,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMOrg,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Itemno.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMArticleMOrg / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMArticleMOrg / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMArticleMOrg::insertRst(
			ListFmncRMArticleMOrg& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMArticleMOrg::updateRec(
			FmncRMArticleMOrg* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Itemno.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMArticle,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMOrg,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Itemno.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMArticleMOrg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMArticleMOrg / stmtUpdateRec)\n");
};

void MyTblFmncRMArticleMOrg::updateRst(
			ListFmncRMArticleMOrg& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMArticleMOrg::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMArticleMOrg / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMArticleMOrg / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMArticleMOrg::loadRecByRef(
			ubigint ref
			, FmncRMArticleMOrg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMArticleMOrg WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMArticleMOrg::loadRefsByArt(
			ubigint refFmncMArticle
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncRMArticleMOrg WHERE refFmncMArticle = " + to_string(refFmncMArticle) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMArticleMOrg
 ******************************************************************************/

PgTblFmncRMArticleMOrg::PgTblFmncRMArticleMOrg() : TblFmncRMArticleMOrg(), PgTable() {
};

PgTblFmncRMArticleMOrg::~PgTblFmncRMArticleMOrg() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMArticleMOrg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMArticleMOrg_insertRec", "INSERT INTO TblFmncRMArticleMOrg (refFmncMArticle, refFmncMOrg, Itemno) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMArticleMOrg_updateRec", "UPDATE TblFmncRMArticleMOrg SET refFmncMArticle = $1, refFmncMOrg = $2, Itemno = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMArticleMOrg_removeRecByRef", "DELETE FROM TblFmncRMArticleMOrg WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMArticleMOrg_loadRecByRef", "SELECT ref, refFmncMArticle, refFmncMOrg, Itemno FROM TblFmncRMArticleMOrg WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMArticleMOrg_loadRefsByArt", "SELECT ref FROM TblFmncRMArticleMOrg WHERE refFmncMArticle = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMArticleMOrg::loadRec(
			PGresult* res
			, FmncRMArticleMOrg** rec
		) {
	char* ptr;

	FmncRMArticleMOrg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMArticleMOrg();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "itemno")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMArticle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Itemno.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMArticleMOrg::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMArticleMOrg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMArticleMOrg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "itemno")
		};

		while (numread < numrow) {
			rec = new FmncRMArticleMOrg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMArticle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Itemno.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMArticleMOrg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMArticleMOrg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMArticleMOrg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMArticleMOrg::loadRecBySQL(
			const string& sqlstr
			, FmncRMArticleMOrg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMArticleMOrg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMArticleMOrg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMArticleMOrg::insertRec(
			FmncRMArticleMOrg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);

	const char* vals[] = {
		(char*) &_refFmncMArticle,
		(char*) &_refFmncMOrg,
		rec->Itemno.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncRMArticleMOrg_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMArticleMOrg_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMArticleMOrg::insertRst(
			ListFmncRMArticleMOrg& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMArticleMOrg::updateRec(
			FmncRMArticleMOrg* rec
		) {
	PGresult* res;

	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMArticle,
		(char*) &_refFmncMOrg,
		rec->Itemno.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncRMArticleMOrg_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMArticleMOrg_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMArticleMOrg::updateRst(
			ListFmncRMArticleMOrg& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMArticleMOrg::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMArticleMOrg_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMArticleMOrg_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMArticleMOrg::loadRecByRef(
			ubigint ref
			, FmncRMArticleMOrg** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMArticleMOrg_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMArticleMOrg::loadRefsByArt(
			ubigint refFmncMArticle
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMArticle = htonl64(refFmncMArticle);

	const char* vals[] = {
		(char*) &_refFmncMArticle
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncRMArticleMOrg_loadRefsByArt", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

