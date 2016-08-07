/**
  * \file FmncMFabproject.cpp
  * database access for table TblFmncMFabproject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMFabproject.h"

/******************************************************************************
 class FmncMFabproject
 ******************************************************************************/

FmncMFabproject::FmncMFabproject(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFab
			, const ubigint bioRefFmncMOrg
			, const string sref
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const ubigint bipRefFmncMPerson
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refFmncMFab = refFmncMFab;
	this->bioRefFmncMOrg = bioRefFmncMOrg;
	this->sref = sref;
	this->Title = Title;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->bipRefFmncMPerson = bipRefFmncMPerson;
	this->Comment = Comment;
};

bool FmncMFabproject::operator==(
			const FmncMFabproject& comp
		) {
	return false;
};

bool FmncMFabproject::operator!=(
			const FmncMFabproject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMFabproject
 ******************************************************************************/

ListFmncMFabproject::ListFmncMFabproject() {
};

ListFmncMFabproject::ListFmncMFabproject(
			const ListFmncMFabproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMFabproject(*(src.nodes[i]));
};

ListFmncMFabproject::~ListFmncMFabproject() {
	clear();
};

void ListFmncMFabproject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMFabproject::size() const {
	return(nodes.size());
};

void ListFmncMFabproject::append(
			FmncMFabproject* rec
		) {
	nodes.push_back(rec);
};

FmncMFabproject* ListFmncMFabproject::operator[](
			const uint ix
		) {
	FmncMFabproject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMFabproject& ListFmncMFabproject::operator=(
			const ListFmncMFabproject& src
		) {
	FmncMFabproject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMFabproject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMFabproject::operator==(
			const ListFmncMFabproject& comp
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

bool ListFmncMFabproject::operator!=(
			const ListFmncMFabproject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMFabproject
 ******************************************************************************/

TblFmncMFabproject::TblFmncMFabproject() {
};

TblFmncMFabproject::~TblFmncMFabproject() {
};

bool TblFmncMFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncMFabproject** rec
		) {
	return false;
};

ubigint TblFmncMFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFabproject& rst
		) {
	return 0;
};

void TblFmncMFabproject::insertRec(
			FmncMFabproject* rec
		) {
};

ubigint TblFmncMFabproject::insertNewRec(
			FmncMFabproject** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFab
			, const ubigint bioRefFmncMOrg
			, const string sref
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const ubigint bipRefFmncMPerson
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMFabproject* _rec = NULL;

	_rec = new FmncMFabproject(0, grp, own, refFmncMFab, bioRefFmncMOrg, sref, Title, refJState, ixVState, bipRefFmncMPerson, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMFabproject::appendNewRecToRst(
			ListFmncMFabproject& rst
			, FmncMFabproject** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMFab
			, const ubigint bioRefFmncMOrg
			, const string sref
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const ubigint bipRefFmncMPerson
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMFabproject* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refFmncMFab, bioRefFmncMOrg, sref, Title, refJState, ixVState, bipRefFmncMPerson, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMFabproject::insertRst(
			ListFmncMFabproject& rst
			, bool transact
		) {
};

void TblFmncMFabproject::updateRec(
			FmncMFabproject* rec
		) {
};

void TblFmncMFabproject::updateRst(
			ListFmncMFabproject& rst
			, bool transact
		) {
};

void TblFmncMFabproject::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMFabproject::loadRecByRef(
			ubigint ref
			, FmncMFabproject** rec
		) {
	return false;
};

bool TblFmncMFabproject::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMFabproject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMFabproject& rst
		) {
	ubigint numload = 0;
	FmncMFabproject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMFabproject
 ******************************************************************************/

MyTblFmncMFabproject::MyTblFmncMFabproject() : TblFmncMFabproject(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMFabproject::~MyTblFmncMFabproject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMFabproject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMFabproject (grp, own, refFmncMFab, bioRefFmncMOrg, sref, Title, refJState, ixVState, bipRefFmncMPerson, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMFabproject SET grp = ?, own = ?, refFmncMFab = ?, bioRefFmncMOrg = ?, sref = ?, Title = ?, refJState = ?, ixVState = ?, bipRefFmncMPerson = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMFabproject WHERE ref = ?", false);
};

bool MyTblFmncMFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncMFabproject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMFabproject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMFabproject / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMFabproject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refFmncMFab = atoll((char*) dbrow[3]); else _rec->refFmncMFab = 0;
		if (dbrow[4]) _rec->bioRefFmncMOrg = atoll((char*) dbrow[4]); else _rec->bioRefFmncMOrg = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->bipRefFmncMPerson = atoll((char*) dbrow[9]); else _rec->bipRefFmncMPerson = 0;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFabproject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMFabproject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMFabproject / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMFabproject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refFmncMFab = atoll((char*) dbrow[3]); else rec->refFmncMFab = 0;
			if (dbrow[4]) rec->bioRefFmncMOrg = atoll((char*) dbrow[4]); else rec->bioRefFmncMOrg = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->bipRefFmncMPerson = atoll((char*) dbrow[9]); else rec->bipRefFmncMPerson = 0;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMFabproject::insertRec(
			FmncMFabproject* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[5] = rec->Title.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMFab,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->bioRefFmncMOrg,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->bipRefFmncMPerson,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFabproject / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFabproject / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMFabproject::insertRst(
			ListFmncMFabproject& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMFabproject::updateRec(
			FmncMFabproject* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->sref.length();
	l[5] = rec->Title.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMFab,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->bioRefFmncMOrg,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->bipRefFmncMPerson,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFabproject / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFabproject / stmtUpdateRec)\n");
};

void MyTblFmncMFabproject::updateRst(
			ListFmncMFabproject& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMFabproject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMFabproject / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMFabproject / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMFabproject::loadRecByRef(
			ubigint ref
			, FmncMFabproject** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMFabproject WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncMFabproject::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblFmncMFabproject WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMFabproject
 ******************************************************************************/

PgTblFmncMFabproject::PgTblFmncMFabproject() : TblFmncMFabproject(), PgTable() {
};

PgTblFmncMFabproject::~PgTblFmncMFabproject() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMFabproject::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMFabproject_insertRec", "INSERT INTO TblFmncMFabproject (grp, own, refFmncMFab, bioRefFmncMOrg, sref, Title, refJState, ixVState, bipRefFmncMPerson, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMFabproject_updateRec", "UPDATE TblFmncMFabproject SET grp = $1, own = $2, refFmncMFab = $3, bioRefFmncMOrg = $4, sref = $5, Title = $6, refJState = $7, ixVState = $8, bipRefFmncMPerson = $9, Comment = $10 WHERE ref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMFabproject_removeRecByRef", "DELETE FROM TblFmncMFabproject WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMFabproject_loadRecByRef", "SELECT ref, grp, own, refFmncMFab, bioRefFmncMOrg, sref, Title, refJState, ixVState, bipRefFmncMPerson, Comment FROM TblFmncMFabproject WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMFabproject_loadSrfByRef", "SELECT sref FROM TblFmncMFabproject WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMFabproject::loadRec(
			PGresult* res
			, FmncMFabproject** rec
		) {
	char* ptr;

	FmncMFabproject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMFabproject();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "bioreffmncmorg"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "bipreffmncmperson"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMFab = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->bioRefFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->bipRefFmncMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMFabproject::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMFabproject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMFabproject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmfab"),
			PQfnumber(res, "bioreffmncmorg"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "bipreffmncmperson"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMFabproject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMFab = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->bioRefFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->bipRefFmncMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMFabproject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMFabproject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFabproject / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMFabproject::loadRecBySQL(
			const string& sqlstr
			, FmncMFabproject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMFabproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMFabproject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMFabproject::insertRec(
			FmncMFabproject* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _bioRefFmncMOrg = htonl64(rec->bioRefFmncMOrg);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _bipRefFmncMPerson = htonl64(rec->bipRefFmncMPerson);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMFab,
		(char*) &_bioRefFmncMOrg,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_bipRefFmncMPerson,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMFabproject_insertRec", 10, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFabproject_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMFabproject::insertRst(
			ListFmncMFabproject& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMFabproject::updateRec(
			FmncMFabproject* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMFab = htonl64(rec->refFmncMFab);
	ubigint _bioRefFmncMOrg = htonl64(rec->bioRefFmncMOrg);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _bipRefFmncMPerson = htonl64(rec->bipRefFmncMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMFab,
		(char*) &_bioRefFmncMOrg,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_bipRefFmncMPerson,
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
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMFabproject_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFabproject_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMFabproject::updateRst(
			ListFmncMFabproject& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMFabproject::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMFabproject_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMFabproject_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMFabproject::loadRecByRef(
			ubigint ref
			, FmncMFabproject** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMFabproject_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncMFabproject::loadSrfByRef(
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

	return loadStringByStmt("TblFmncMFabproject_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

