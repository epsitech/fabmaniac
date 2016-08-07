/**
  * \file FmncMUsergroup.cpp
  * database access for table TblFmncMUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMUsergroup.h"

/******************************************************************************
 class FmncMUsergroup
 ******************************************************************************/

FmncMUsergroup::FmncMUsergroup(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->sref = sref;
	this->Comment = Comment;
};

bool FmncMUsergroup::operator==(
			const FmncMUsergroup& comp
		) {
	return false;
};

bool FmncMUsergroup::operator!=(
			const FmncMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMUsergroup
 ******************************************************************************/

ListFmncMUsergroup::ListFmncMUsergroup() {
};

ListFmncMUsergroup::ListFmncMUsergroup(
			const ListFmncMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMUsergroup(*(src.nodes[i]));
};

ListFmncMUsergroup::~ListFmncMUsergroup() {
	clear();
};

void ListFmncMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMUsergroup::size() const {
	return(nodes.size());
};

void ListFmncMUsergroup::append(
			FmncMUsergroup* rec
		) {
	nodes.push_back(rec);
};

FmncMUsergroup* ListFmncMUsergroup::operator[](
			const uint ix
		) {
	FmncMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMUsergroup& ListFmncMUsergroup::operator=(
			const ListFmncMUsergroup& src
		) {
	FmncMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMUsergroup::operator==(
			const ListFmncMUsergroup& comp
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

bool ListFmncMUsergroup::operator!=(
			const ListFmncMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMUsergroup
 ******************************************************************************/

TblFmncMUsergroup::TblFmncMUsergroup() {
};

TblFmncMUsergroup::~TblFmncMUsergroup() {
};

bool TblFmncMUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncMUsergroup** rec
		) {
	return false;
};

ubigint TblFmncMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMUsergroup& rst
		) {
	return 0;
};

void TblFmncMUsergroup::insertRec(
			FmncMUsergroup* rec
		) {
};

ubigint TblFmncMUsergroup::insertNewRec(
			FmncMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMUsergroup* _rec = NULL;

	_rec = new FmncMUsergroup(0, grp, own, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMUsergroup::appendNewRecToRst(
			ListFmncMUsergroup& rst
			, FmncMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMUsergroup::insertRst(
			ListFmncMUsergroup& rst
			, bool transact
		) {
};

void TblFmncMUsergroup::updateRec(
			FmncMUsergroup* rec
		) {
};

void TblFmncMUsergroup::updateRst(
			ListFmncMUsergroup& rst
			, bool transact
		) {
};

void TblFmncMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMUsergroup::loadRecByRef(
			ubigint ref
			, FmncMUsergroup** rec
		) {
	return false;
};

bool TblFmncMUsergroup::loadRecBySrf(
			string sref
			, FmncMUsergroup** rec
		) {
	return false;
};

bool TblFmncMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblFmncMUsergroup::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblFmncMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMUsergroup& rst
		) {
	ubigint numload = 0;
	FmncMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMUsergroup
 ******************************************************************************/

MyTblFmncMUsergroup::MyTblFmncMUsergroup() : TblFmncMUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMUsergroup::~MyTblFmncMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMUsergroup (grp, own, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMUsergroup SET grp = ?, own = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMUsergroup WHERE ref = ?", false);
};

bool MyTblFmncMUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMUsergroup::insertRec(
			FmncMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMUsergroup / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMUsergroup / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMUsergroup::insertRst(
			ListFmncMUsergroup& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMUsergroup::updateRec(
			FmncMUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMUsergroup / stmtUpdateRec)\n");
};

void MyTblFmncMUsergroup::updateRst(
			ListFmncMUsergroup& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMUsergroup / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMUsergroup / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMUsergroup::loadRecByRef(
			ubigint ref
			, FmncMUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMUsergroup WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncMUsergroup::loadRecBySrf(
			string sref
			, FmncMUsergroup** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, sref, Comment FROM TblFmncMUsergroup WHERE sref = '" + sref + "'", rec);
};

bool MyTblFmncMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncMUsergroup WHERE sref = '" + sref + "'", ref);
};

bool MyTblFmncMUsergroup::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblFmncMUsergroup WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMUsergroup
 ******************************************************************************/

PgTblFmncMUsergroup::PgTblFmncMUsergroup() : TblFmncMUsergroup(), PgTable() {
};

PgTblFmncMUsergroup::~PgTblFmncMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMUsergroup_insertRec", "INSERT INTO TblFmncMUsergroup (grp, own, sref, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUsergroup_updateRec", "UPDATE TblFmncMUsergroup SET grp = $1, own = $2, sref = $3, Comment = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUsergroup_removeRecByRef", "DELETE FROM TblFmncMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMUsergroup_loadRecByRef", "SELECT ref, grp, own, sref, Comment FROM TblFmncMUsergroup WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncMUsergroup_loadRecBySrf", "SELECT ref, grp, own, sref, Comment FROM TblFmncMUsergroup WHERE sref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUsergroup_loadRefBySrf", "SELECT ref FROM TblFmncMUsergroup WHERE sref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMUsergroup_loadSrfByRef", "SELECT sref FROM TblFmncMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncMUsergroup::loadRec(
			PGresult* res
			, FmncMUsergroup** rec
		) {
	char* ptr;

	FmncMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMUsergroup::loadRecBySQL(
			const string& sqlstr
			, FmncMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMUsergroup::insertRec(
			FmncMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncMUsergroup_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMUsergroup::insertRst(
			ListFmncMUsergroup& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMUsergroup::updateRec(
			FmncMUsergroup* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMUsergroup_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMUsergroup::updateRst(
			ListFmncMUsergroup& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMUsergroup_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMUsergroup::loadRecByRef(
			ubigint ref
			, FmncMUsergroup** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncMUsergroup::loadRecBySrf(
			string sref
			, FmncMUsergroup** rec
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRecByStmt("TblFmncMUsergroup_loadRecBySrf", 1, vals, l, f, rec);
};

bool PgTblFmncMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadUbigintByStmt("TblFmncMUsergroup_loadRefBySrf", 1, vals, l, f, ref);
};

bool PgTblFmncMUsergroup::loadSrfByRef(
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

	return loadStringByStmt("TblFmncMUsergroup_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

