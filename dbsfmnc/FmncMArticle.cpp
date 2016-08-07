/**
  * \file FmncMArticle.cpp
  * database access for table TblFmncMArticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMArticle.h"

/******************************************************************************
 class FmncMArticle
 ******************************************************************************/

FmncMArticle::FmncMArticle(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
			, const ubigint refFmncMTool
			, const string sref
			, const string Title
			, const string srefKType
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refFmncMOrg = refFmncMOrg;
	this->refFmncMTool = refFmncMTool;
	this->sref = sref;
	this->Title = Title;
	this->srefKType = srefKType;
	this->Comment = Comment;
};

bool FmncMArticle::operator==(
			const FmncMArticle& comp
		) {
	return false;
};

bool FmncMArticle::operator!=(
			const FmncMArticle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMArticle
 ******************************************************************************/

ListFmncMArticle::ListFmncMArticle() {
};

ListFmncMArticle::ListFmncMArticle(
			const ListFmncMArticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMArticle(*(src.nodes[i]));
};

ListFmncMArticle::~ListFmncMArticle() {
	clear();
};

void ListFmncMArticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMArticle::size() const {
	return(nodes.size());
};

void ListFmncMArticle::append(
			FmncMArticle* rec
		) {
	nodes.push_back(rec);
};

FmncMArticle* ListFmncMArticle::operator[](
			const uint ix
		) {
	FmncMArticle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMArticle& ListFmncMArticle::operator=(
			const ListFmncMArticle& src
		) {
	FmncMArticle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMArticle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMArticle::operator==(
			const ListFmncMArticle& comp
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

bool ListFmncMArticle::operator!=(
			const ListFmncMArticle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMArticle
 ******************************************************************************/

TblFmncMArticle::TblFmncMArticle() {
};

TblFmncMArticle::~TblFmncMArticle() {
};

bool TblFmncMArticle::loadRecBySQL(
			const string& sqlstr
			, FmncMArticle** rec
		) {
	return false;
};

ubigint TblFmncMArticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMArticle& rst
		) {
	return 0;
};

void TblFmncMArticle::insertRec(
			FmncMArticle* rec
		) {
};

ubigint TblFmncMArticle::insertNewRec(
			FmncMArticle** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
			, const ubigint refFmncMTool
			, const string sref
			, const string Title
			, const string srefKType
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMArticle* _rec = NULL;

	_rec = new FmncMArticle(0, grp, own, refFmncMOrg, refFmncMTool, sref, Title, srefKType, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMArticle::appendNewRecToRst(
			ListFmncMArticle& rst
			, FmncMArticle** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
			, const ubigint refFmncMTool
			, const string sref
			, const string Title
			, const string srefKType
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMArticle* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refFmncMOrg, refFmncMTool, sref, Title, srefKType, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMArticle::insertRst(
			ListFmncMArticle& rst
			, bool transact
		) {
};

void TblFmncMArticle::updateRec(
			FmncMArticle* rec
		) {
};

void TblFmncMArticle::updateRst(
			ListFmncMArticle& rst
			, bool transact
		) {
};

void TblFmncMArticle::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMArticle::loadRecByRef(
			ubigint ref
			, FmncMArticle** rec
		) {
	return false;
};

ubigint TblFmncMArticle::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblFmncMArticle::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMArticle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMArticle& rst
		) {
	ubigint numload = 0;
	FmncMArticle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMArticle
 ******************************************************************************/

MyTblFmncMArticle::MyTblFmncMArticle() : TblFmncMArticle(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMArticle::~MyTblFmncMArticle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMArticle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMArticle (grp, own, refFmncMOrg, refFmncMTool, sref, Title, srefKType, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMArticle SET grp = ?, own = ?, refFmncMOrg = ?, refFmncMTool = ?, sref = ?, Title = ?, srefKType = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMArticle WHERE ref = ?", false);
};

bool MyTblFmncMArticle::loadRecBySQL(
			const string& sqlstr
			, FmncMArticle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMArticle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMArticle / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMArticle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refFmncMOrg = atoll((char*) dbrow[3]); else _rec->refFmncMOrg = 0;
		if (dbrow[4]) _rec->refFmncMTool = atoll((char*) dbrow[4]); else _rec->refFmncMTool = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->srefKType.assign(dbrow[7], dblengths[7]); else _rec->srefKType = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMArticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMArticle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMArticle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMArticle / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMArticle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refFmncMOrg = atoll((char*) dbrow[3]); else rec->refFmncMOrg = 0;
			if (dbrow[4]) rec->refFmncMTool = atoll((char*) dbrow[4]); else rec->refFmncMTool = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->srefKType.assign(dbrow[7], dblengths[7]); else rec->srefKType = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMArticle::insertRec(
			FmncMArticle* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();
	l[5] = rec->Title.length();
	l[6] = rec->srefKType.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMOrg,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMTool,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefKType.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMArticle / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMArticle / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMArticle::insertRst(
			ListFmncMArticle& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMArticle::updateRec(
			FmncMArticle* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[5] = rec->Title.length();
	l[6] = rec->srefKType.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMOrg,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMTool,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->srefKType.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMArticle / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMArticle / stmtUpdateRec)\n");
};

void MyTblFmncMArticle::updateRst(
			ListFmncMArticle& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMArticle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMArticle / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMArticle / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMArticle::loadRecByRef(
			ubigint ref
			, FmncMArticle** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMArticle WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncMArticle::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncMArticle WHERE refFmncMTool = " + to_string(refFmncMTool) + "", append, refs);
};

bool MyTblFmncMArticle::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblFmncMArticle WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMArticle
 ******************************************************************************/

PgTblFmncMArticle::PgTblFmncMArticle() : TblFmncMArticle(), PgTable() {
};

PgTblFmncMArticle::~PgTblFmncMArticle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMArticle::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMArticle_insertRec", "INSERT INTO TblFmncMArticle (grp, own, refFmncMOrg, refFmncMTool, sref, Title, srefKType, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMArticle_updateRec", "UPDATE TblFmncMArticle SET grp = $1, own = $2, refFmncMOrg = $3, refFmncMTool = $4, sref = $5, Title = $6, srefKType = $7, Comment = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMArticle_removeRecByRef", "DELETE FROM TblFmncMArticle WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMArticle_loadRecByRef", "SELECT ref, grp, own, refFmncMOrg, refFmncMTool, sref, Title, srefKType, Comment FROM TblFmncMArticle WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMArticle_loadRefsByTol", "SELECT ref FROM TblFmncMArticle WHERE refFmncMTool = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMArticle_loadTitByRef", "SELECT Title FROM TblFmncMArticle WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMArticle::loadRec(
			PGresult* res
			, FmncMArticle** rec
		) {
	char* ptr;

	FmncMArticle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMArticle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "srefktype"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->srefKType.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMArticle::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMArticle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMArticle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "srefktype"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMArticle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->srefKType.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMArticle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMArticle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMArticle / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMArticle::loadRecBySQL(
			const string& sqlstr
			, FmncMArticle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMArticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMArticle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMArticle::insertRec(
			FmncMArticle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMTool,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->srefKType.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncMArticle_insertRec", 8, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMArticle_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMArticle::insertRst(
			ListFmncMArticle& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMArticle::updateRec(
			FmncMArticle* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMTool,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->srefKType.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMArticle_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMArticle_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMArticle::updateRst(
			ListFmncMArticle& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMArticle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMArticle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMArticle_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMArticle::loadRecByRef(
			ubigint ref
			, FmncMArticle** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMArticle_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncMArticle::loadRefsByTol(
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

	return loadRefsByStmt("TblFmncMArticle_loadRefsByTol", 1, vals, l, f, append, refs);
};

bool PgTblFmncMArticle::loadTitByRef(
			ubigint ref
			, string& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblFmncMArticle_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

