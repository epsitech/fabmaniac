/**
  * \file FmncAMUsergroupAccess.cpp
  * database access for table TblFmncAMUsergroupAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMUsergroupAccess.h"

/******************************************************************************
 class FmncAMUsergroupAccess
 ******************************************************************************/

FmncAMUsergroupAccess::FmncAMUsergroupAccess(
			const ubigint ref
			, const ubigint refFmncMUsergroup
			, const uint x1IxFmncVCard
			, const uint ixFmncWUiaccess
		) {

	this->ref = ref;
	this->refFmncMUsergroup = refFmncMUsergroup;
	this->x1IxFmncVCard = x1IxFmncVCard;
	this->ixFmncWUiaccess = ixFmncWUiaccess;
};

bool FmncAMUsergroupAccess::operator==(
			const FmncAMUsergroupAccess& comp
		) {
	return false;
};

bool FmncAMUsergroupAccess::operator!=(
			const FmncAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMUsergroupAccess
 ******************************************************************************/

ListFmncAMUsergroupAccess::ListFmncAMUsergroupAccess() {
};

ListFmncAMUsergroupAccess::ListFmncAMUsergroupAccess(
			const ListFmncAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMUsergroupAccess(*(src.nodes[i]));
};

ListFmncAMUsergroupAccess::~ListFmncAMUsergroupAccess() {
	clear();
};

void ListFmncAMUsergroupAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListFmncAMUsergroupAccess::append(
			FmncAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

FmncAMUsergroupAccess* ListFmncAMUsergroupAccess::operator[](
			const uint ix
		) {
	FmncAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMUsergroupAccess& ListFmncAMUsergroupAccess::operator=(
			const ListFmncAMUsergroupAccess& src
		) {
	FmncAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMUsergroupAccess::operator==(
			const ListFmncAMUsergroupAccess& comp
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

bool ListFmncAMUsergroupAccess::operator!=(
			const ListFmncAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMUsergroupAccess
 ******************************************************************************/

TblFmncAMUsergroupAccess::TblFmncAMUsergroupAccess() {
};

TblFmncAMUsergroupAccess::~TblFmncAMUsergroupAccess() {
};

bool TblFmncAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, FmncAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblFmncAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMUsergroupAccess& rst
		) {
	return 0;
};

void TblFmncAMUsergroupAccess::insertRec(
			FmncAMUsergroupAccess* rec
		) {
};

ubigint TblFmncAMUsergroupAccess::insertNewRec(
			FmncAMUsergroupAccess** rec
			, const ubigint refFmncMUsergroup
			, const uint x1IxFmncVCard
			, const uint ixFmncWUiaccess
		) {
	ubigint retval = 0;
	FmncAMUsergroupAccess* _rec = NULL;

	_rec = new FmncAMUsergroupAccess(0, refFmncMUsergroup, x1IxFmncVCard, ixFmncWUiaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMUsergroupAccess::appendNewRecToRst(
			ListFmncAMUsergroupAccess& rst
			, FmncAMUsergroupAccess** rec
			, const ubigint refFmncMUsergroup
			, const uint x1IxFmncVCard
			, const uint ixFmncWUiaccess
		) {
	ubigint retval = 0;
	FmncAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMUsergroup, x1IxFmncVCard, ixFmncWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMUsergroupAccess::insertRst(
			ListFmncAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblFmncAMUsergroupAccess::updateRec(
			FmncAMUsergroupAccess* rec
		) {
};

void TblFmncAMUsergroupAccess::updateRst(
			ListFmncAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblFmncAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, FmncAMUsergroupAccess** rec
		) {
	return false;
};

bool TblFmncAMUsergroupAccess::loadRecByUsgCrd(
			ubigint refFmncMUsergroup
			, uint x1IxFmncVCard
			, FmncAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblFmncAMUsergroupAccess::loadRefsByUsg(
			ubigint refFmncMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	FmncAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMUsergroupAccess
 ******************************************************************************/

MyTblFmncAMUsergroupAccess::MyTblFmncAMUsergroupAccess() : TblFmncAMUsergroupAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMUsergroupAccess::~MyTblFmncAMUsergroupAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMUsergroupAccess (refFmncMUsergroup, x1IxFmncVCard, ixFmncWUiaccess) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMUsergroupAccess SET refFmncMUsergroup = ?, x1IxFmncVCard = ?, ixFmncWUiaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMUsergroupAccess WHERE ref = ?", false);
};

bool MyTblFmncAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, FmncAMUsergroupAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMUsergroupAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMUsergroupAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMUsergroupAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMUsergroup = atoll((char*) dbrow[1]); else _rec->refFmncMUsergroup = 0;
		if (dbrow[2]) _rec->x1IxFmncVCard = atol((char*) dbrow[2]); else _rec->x1IxFmncVCard = 0;
		if (dbrow[3]) _rec->ixFmncWUiaccess = atol((char*) dbrow[3]); else _rec->ixFmncWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMUsergroupAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMUsergroupAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMUsergroupAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMUsergroupAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMUsergroup = atoll((char*) dbrow[1]); else rec->refFmncMUsergroup = 0;
			if (dbrow[2]) rec->x1IxFmncVCard = atol((char*) dbrow[2]); else rec->x1IxFmncVCard = 0;
			if (dbrow[3]) rec->ixFmncWUiaccess = atol((char*) dbrow[3]); else rec->ixFmncWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMUsergroupAccess::insertRec(
			FmncAMUsergroupAccess* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxFmncVCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixFmncWUiaccess,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMUsergroupAccess / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMUsergroupAccess / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMUsergroupAccess::insertRst(
			ListFmncAMUsergroupAccess& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMUsergroupAccess::updateRec(
			FmncAMUsergroupAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUsergroup,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1IxFmncVCard,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixFmncWUiaccess,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMUsergroupAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMUsergroupAccess / stmtUpdateRec)\n");
};

void MyTblFmncAMUsergroupAccess::updateRst(
			ListFmncAMUsergroupAccess& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMUsergroupAccess / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMUsergroupAccess / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, FmncAMUsergroupAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMUsergroupAccess WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncAMUsergroupAccess::loadRecByUsgCrd(
			ubigint refFmncMUsergroup
			, uint x1IxFmncVCard
			, FmncAMUsergroupAccess** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMUsergroup, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncAMUsergroupAccess WHERE refFmncMUsergroup = " + to_string(refFmncMUsergroup) + " AND x1IxFmncVCard = " + to_string(x1IxFmncVCard) + "", rec);
};

ubigint MyTblFmncAMUsergroupAccess::loadRefsByUsg(
			ubigint refFmncMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncAMUsergroupAccess WHERE refFmncMUsergroup = " + to_string(refFmncMUsergroup) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMUsergroupAccess
 ******************************************************************************/

PgTblFmncAMUsergroupAccess::PgTblFmncAMUsergroupAccess() : TblFmncAMUsergroupAccess(), PgTable() {
};

PgTblFmncAMUsergroupAccess::~PgTblFmncAMUsergroupAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMUsergroupAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMUsergroupAccess_insertRec", "INSERT INTO TblFmncAMUsergroupAccess (refFmncMUsergroup, x1IxFmncVCard, ixFmncWUiaccess) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMUsergroupAccess_updateRec", "UPDATE TblFmncAMUsergroupAccess SET refFmncMUsergroup = $1, x1IxFmncVCard = $2, ixFmncWUiaccess = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMUsergroupAccess_removeRecByRef", "DELETE FROM TblFmncAMUsergroupAccess WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMUsergroupAccess_loadRecByRef", "SELECT ref, refFmncMUsergroup, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncAMUsergroupAccess WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAMUsergroupAccess_loadRecByUsgCrd", "SELECT ref, refFmncMUsergroup, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncAMUsergroupAccess WHERE refFmncMUsergroup = $1 AND x1IxFmncVCard = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMUsergroupAccess_loadRefsByUsg", "SELECT ref FROM TblFmncAMUsergroupAccess WHERE refFmncMUsergroup = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAMUsergroupAccess::loadRec(
			PGresult* res
			, FmncAMUsergroupAccess** rec
		) {
	char* ptr;

	FmncAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMUsergroupAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "x1ixfmncvcard"),
			PQfnumber(res, "ixfmncwuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxFmncVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixFmncWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMUsergroupAccess::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMUsergroupAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMUsergroupAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmusergroup"),
			PQfnumber(res, "x1ixfmncvcard"),
			PQfnumber(res, "ixfmncwuiaccess")
		};

		while (numread < numrow) {
			rec = new FmncAMUsergroupAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxFmncVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixFmncWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMUsergroupAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMUsergroupAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, FmncAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMUsergroupAccess::insertRec(
			FmncAMUsergroupAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	uint _x1IxFmncVCard = htonl(rec->x1IxFmncVCard);
	uint _ixFmncWUiaccess = htonl(rec->ixFmncWUiaccess);

	const char* vals[] = {
		(char*) &_refFmncMUsergroup,
		(char*) &_x1IxFmncVCard,
		(char*) &_ixFmncWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncAMUsergroupAccess_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMUsergroupAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMUsergroupAccess::insertRst(
			ListFmncAMUsergroupAccess& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMUsergroupAccess::updateRec(
			FmncAMUsergroupAccess* rec
		) {
	PGresult* res;

	ubigint _refFmncMUsergroup = htonl64(rec->refFmncMUsergroup);
	uint _x1IxFmncVCard = htonl(rec->x1IxFmncVCard);
	uint _ixFmncWUiaccess = htonl(rec->ixFmncWUiaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMUsergroup,
		(char*) &_x1IxFmncVCard,
		(char*) &_ixFmncWUiaccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncAMUsergroupAccess_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMUsergroupAccess_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMUsergroupAccess::updateRst(
			ListFmncAMUsergroupAccess& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMUsergroupAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMUsergroupAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMUsergroupAccess_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, FmncAMUsergroupAccess** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMUsergroupAccess_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncAMUsergroupAccess::loadRecByUsgCrd(
			ubigint refFmncMUsergroup
			, uint x1IxFmncVCard
			, FmncAMUsergroupAccess** rec
		) {
	ubigint _refFmncMUsergroup = htonl64(refFmncMUsergroup);
	uint _x1IxFmncVCard = htonl(x1IxFmncVCard);

	const char* vals[] = {
		(char*) &_refFmncMUsergroup,
		(char*) &_x1IxFmncVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncAMUsergroupAccess_loadRecByUsgCrd", 2, vals, l, f, rec);
};

ubigint PgTblFmncAMUsergroupAccess::loadRefsByUsg(
			ubigint refFmncMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refFmncMUsergroup = htonl64(refFmncMUsergroup);

	const char* vals[] = {
		(char*) &_refFmncMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblFmncAMUsergroupAccess_loadRefsByUsg", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

