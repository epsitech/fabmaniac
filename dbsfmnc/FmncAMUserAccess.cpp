/**
  * \file FmncAMUserAccess.cpp
  * database access for table TblFmncAMUserAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMUserAccess.h"

/******************************************************************************
 class FmncAMUserAccess
 ******************************************************************************/

FmncAMUserAccess::FmncAMUserAccess(
			const ubigint ref
			, const ubigint refFmncMUser
			, const uint x1IxFmncVCard
			, const uint ixFmncWUiaccess
		) {

	this->ref = ref;
	this->refFmncMUser = refFmncMUser;
	this->x1IxFmncVCard = x1IxFmncVCard;
	this->ixFmncWUiaccess = ixFmncWUiaccess;
};

bool FmncAMUserAccess::operator==(
			const FmncAMUserAccess& comp
		) {
	return false;
};

bool FmncAMUserAccess::operator!=(
			const FmncAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMUserAccess
 ******************************************************************************/

ListFmncAMUserAccess::ListFmncAMUserAccess() {
};

ListFmncAMUserAccess::ListFmncAMUserAccess(
			const ListFmncAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMUserAccess(*(src.nodes[i]));
};

ListFmncAMUserAccess::~ListFmncAMUserAccess() {
	clear();
};

void ListFmncAMUserAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMUserAccess::size() const {
	return(nodes.size());
};

void ListFmncAMUserAccess::append(
			FmncAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

FmncAMUserAccess* ListFmncAMUserAccess::operator[](
			const uint ix
		) {
	FmncAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMUserAccess& ListFmncAMUserAccess::operator=(
			const ListFmncAMUserAccess& src
		) {
	FmncAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMUserAccess::operator==(
			const ListFmncAMUserAccess& comp
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

bool ListFmncAMUserAccess::operator!=(
			const ListFmncAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMUserAccess
 ******************************************************************************/

TblFmncAMUserAccess::TblFmncAMUserAccess() {
};

TblFmncAMUserAccess::~TblFmncAMUserAccess() {
};

bool TblFmncAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, FmncAMUserAccess** rec
		) {
	return false;
};

ubigint TblFmncAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMUserAccess& rst
		) {
	return 0;
};

void TblFmncAMUserAccess::insertRec(
			FmncAMUserAccess* rec
		) {
};

ubigint TblFmncAMUserAccess::insertNewRec(
			FmncAMUserAccess** rec
			, const ubigint refFmncMUser
			, const uint x1IxFmncVCard
			, const uint ixFmncWUiaccess
		) {
	ubigint retval = 0;
	FmncAMUserAccess* _rec = NULL;

	_rec = new FmncAMUserAccess(0, refFmncMUser, x1IxFmncVCard, ixFmncWUiaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMUserAccess::appendNewRecToRst(
			ListFmncAMUserAccess& rst
			, FmncAMUserAccess** rec
			, const ubigint refFmncMUser
			, const uint x1IxFmncVCard
			, const uint ixFmncWUiaccess
		) {
	ubigint retval = 0;
	FmncAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMUser, x1IxFmncVCard, ixFmncWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMUserAccess::insertRst(
			ListFmncAMUserAccess& rst
			, bool transact
		) {
};

void TblFmncAMUserAccess::updateRec(
			FmncAMUserAccess* rec
		) {
};

void TblFmncAMUserAccess::updateRst(
			ListFmncAMUserAccess& rst
			, bool transact
		) {
};

void TblFmncAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMUserAccess::loadRecByRef(
			ubigint ref
			, FmncAMUserAccess** rec
		) {
	return false;
};

bool TblFmncAMUserAccess::loadRecByUsrCrd(
			ubigint refFmncMUser
			, uint x1IxFmncVCard
			, FmncAMUserAccess** rec
		) {
	return false;
};

ubigint TblFmncAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMUserAccess& rst
		) {
	ubigint numload = 0;
	FmncAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMUserAccess
 ******************************************************************************/

MyTblFmncAMUserAccess::MyTblFmncAMUserAccess() : TblFmncAMUserAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMUserAccess::~MyTblFmncAMUserAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMUserAccess (refFmncMUser, x1IxFmncVCard, ixFmncWUiaccess) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMUserAccess SET refFmncMUser = ?, x1IxFmncVCard = ?, ixFmncWUiaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMUserAccess WHERE ref = ?", false);
};

bool MyTblFmncAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, FmncAMUserAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMUserAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMUserAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMUserAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMUser = atoll((char*) dbrow[1]); else _rec->refFmncMUser = 0;
		if (dbrow[2]) _rec->x1IxFmncVCard = atol((char*) dbrow[2]); else _rec->x1IxFmncVCard = 0;
		if (dbrow[3]) _rec->ixFmncWUiaccess = atol((char*) dbrow[3]); else _rec->ixFmncWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMUserAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMUserAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMUserAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMUserAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMUser = atoll((char*) dbrow[1]); else rec->refFmncMUser = 0;
			if (dbrow[2]) rec->x1IxFmncVCard = atol((char*) dbrow[2]); else rec->x1IxFmncVCard = 0;
			if (dbrow[3]) rec->ixFmncWUiaccess = atol((char*) dbrow[3]); else rec->ixFmncWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMUserAccess::insertRec(
			FmncAMUserAccess* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxFmncVCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixFmncWUiaccess,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMUserAccess / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMUserAccess / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMUserAccess::insertRst(
			ListFmncAMUserAccess& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMUserAccess::updateRec(
			FmncAMUserAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1IxFmncVCard,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixFmncWUiaccess,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMUserAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMUserAccess / stmtUpdateRec)\n");
};

void MyTblFmncAMUserAccess::updateRst(
			ListFmncAMUserAccess& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMUserAccess / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMUserAccess / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMUserAccess::loadRecByRef(
			ubigint ref
			, FmncAMUserAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMUserAccess WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncAMUserAccess::loadRecByUsrCrd(
			ubigint refFmncMUser
			, uint x1IxFmncVCard
			, FmncAMUserAccess** rec
		) {
	return loadRecBySQL("SELECT ref, refFmncMUser, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncAMUserAccess WHERE refFmncMUser = " + to_string(refFmncMUser) + " AND x1IxFmncVCard = " + to_string(x1IxFmncVCard) + "", rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMUserAccess
 ******************************************************************************/

PgTblFmncAMUserAccess::PgTblFmncAMUserAccess() : TblFmncAMUserAccess(), PgTable() {
};

PgTblFmncAMUserAccess::~PgTblFmncAMUserAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMUserAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMUserAccess_insertRec", "INSERT INTO TblFmncAMUserAccess (refFmncMUser, x1IxFmncVCard, ixFmncWUiaccess) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMUserAccess_updateRec", "UPDATE TblFmncAMUserAccess SET refFmncMUser = $1, x1IxFmncVCard = $2, ixFmncWUiaccess = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMUserAccess_removeRecByRef", "DELETE FROM TblFmncAMUserAccess WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMUserAccess_loadRecByRef", "SELECT ref, refFmncMUser, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncAMUserAccess WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAMUserAccess_loadRecByUsrCrd", "SELECT ref, refFmncMUser, x1IxFmncVCard, ixFmncWUiaccess FROM TblFmncAMUserAccess WHERE refFmncMUser = $1 AND x1IxFmncVCard = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAMUserAccess::loadRec(
			PGresult* res
			, FmncAMUserAccess** rec
		) {
	char* ptr;

	FmncAMUserAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMUserAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "x1ixfmncvcard"),
			PQfnumber(res, "ixfmncwuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxFmncVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixFmncWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMUserAccess::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMUserAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMUserAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmuser"),
			PQfnumber(res, "x1ixfmncvcard"),
			PQfnumber(res, "ixfmncwuiaccess")
		};

		while (numread < numrow) {
			rec = new FmncAMUserAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxFmncVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixFmncWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMUserAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMUserAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, FmncAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMUserAccess::insertRec(
			FmncAMUserAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _x1IxFmncVCard = htonl(rec->x1IxFmncVCard);
	uint _ixFmncWUiaccess = htonl(rec->ixFmncWUiaccess);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_x1IxFmncVCard,
		(char*) &_ixFmncWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblFmncAMUserAccess_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMUserAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMUserAccess::insertRst(
			ListFmncAMUserAccess& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMUserAccess::updateRec(
			FmncAMUserAccess* rec
		) {
	PGresult* res;

	ubigint _refFmncMUser = htonl64(rec->refFmncMUser);
	uint _x1IxFmncVCard = htonl(rec->x1IxFmncVCard);
	uint _ixFmncWUiaccess = htonl(rec->ixFmncWUiaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMUser,
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

	res = PQexecPrepared(dbs, "TblFmncAMUserAccess_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMUserAccess_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMUserAccess::updateRst(
			ListFmncAMUserAccess& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMUserAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMUserAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMUserAccess_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMUserAccess::loadRecByRef(
			ubigint ref
			, FmncAMUserAccess** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMUserAccess_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncAMUserAccess::loadRecByUsrCrd(
			ubigint refFmncMUser
			, uint x1IxFmncVCard
			, FmncAMUserAccess** rec
		) {
	ubigint _refFmncMUser = htonl64(refFmncMUser);
	uint _x1IxFmncVCard = htonl(x1IxFmncVCard);

	const char* vals[] = {
		(char*) &_refFmncMUser,
		(char*) &_x1IxFmncVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblFmncAMUserAccess_loadRecByUsrCrd", 2, vals, l, f, rec);
};

// IP pgTbl --- END

