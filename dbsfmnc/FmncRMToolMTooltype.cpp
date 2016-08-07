/**
  * \file FmncRMToolMTooltype.cpp
  * database access for table TblFmncRMToolMTooltype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncRMToolMTooltype.h"

/******************************************************************************
 class FmncRMToolMTooltype
 ******************************************************************************/

FmncRMToolMTooltype::FmncRMToolMTooltype(
			const ubigint ref
			, const ubigint refFmncMTool
			, const ubigint refFmncMTooltype
			, const string srefsFmncKToolchar
			, const string defSrefsFmncKSteppar
			, const string optSrefsFmncKSteppar
		) {

	this->ref = ref;
	this->refFmncMTool = refFmncMTool;
	this->refFmncMTooltype = refFmncMTooltype;
	this->srefsFmncKToolchar = srefsFmncKToolchar;
	this->defSrefsFmncKSteppar = defSrefsFmncKSteppar;
	this->optSrefsFmncKSteppar = optSrefsFmncKSteppar;
};

bool FmncRMToolMTooltype::operator==(
			const FmncRMToolMTooltype& comp
		) {
	return false;
};

bool FmncRMToolMTooltype::operator!=(
			const FmncRMToolMTooltype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncRMToolMTooltype
 ******************************************************************************/

ListFmncRMToolMTooltype::ListFmncRMToolMTooltype() {
};

ListFmncRMToolMTooltype::ListFmncRMToolMTooltype(
			const ListFmncRMToolMTooltype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncRMToolMTooltype(*(src.nodes[i]));
};

ListFmncRMToolMTooltype::~ListFmncRMToolMTooltype() {
	clear();
};

void ListFmncRMToolMTooltype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncRMToolMTooltype::size() const {
	return(nodes.size());
};

void ListFmncRMToolMTooltype::append(
			FmncRMToolMTooltype* rec
		) {
	nodes.push_back(rec);
};

FmncRMToolMTooltype* ListFmncRMToolMTooltype::operator[](
			const uint ix
		) {
	FmncRMToolMTooltype* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncRMToolMTooltype& ListFmncRMToolMTooltype::operator=(
			const ListFmncRMToolMTooltype& src
		) {
	FmncRMToolMTooltype* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncRMToolMTooltype(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncRMToolMTooltype::operator==(
			const ListFmncRMToolMTooltype& comp
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

bool ListFmncRMToolMTooltype::operator!=(
			const ListFmncRMToolMTooltype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncRMToolMTooltype
 ******************************************************************************/

TblFmncRMToolMTooltype::TblFmncRMToolMTooltype() {
};

TblFmncRMToolMTooltype::~TblFmncRMToolMTooltype() {
};

bool TblFmncRMToolMTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncRMToolMTooltype** rec
		) {
	return false;
};

ubigint TblFmncRMToolMTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMToolMTooltype& rst
		) {
	return 0;
};

void TblFmncRMToolMTooltype::insertRec(
			FmncRMToolMTooltype* rec
		) {
};

ubigint TblFmncRMToolMTooltype::insertNewRec(
			FmncRMToolMTooltype** rec
			, const ubigint refFmncMTool
			, const ubigint refFmncMTooltype
			, const string srefsFmncKToolchar
			, const string defSrefsFmncKSteppar
			, const string optSrefsFmncKSteppar
		) {
	ubigint retval = 0;
	FmncRMToolMTooltype* _rec = NULL;

	_rec = new FmncRMToolMTooltype(0, refFmncMTool, refFmncMTooltype, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncRMToolMTooltype::appendNewRecToRst(
			ListFmncRMToolMTooltype& rst
			, FmncRMToolMTooltype** rec
			, const ubigint refFmncMTool
			, const ubigint refFmncMTooltype
			, const string srefsFmncKToolchar
			, const string defSrefsFmncKSteppar
			, const string optSrefsFmncKSteppar
		) {
	ubigint retval = 0;
	FmncRMToolMTooltype* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMTool, refFmncMTooltype, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncRMToolMTooltype::insertRst(
			ListFmncRMToolMTooltype& rst
			, bool transact
		) {
};

void TblFmncRMToolMTooltype::updateRec(
			FmncRMToolMTooltype* rec
		) {
};

void TblFmncRMToolMTooltype::updateRst(
			ListFmncRMToolMTooltype& rst
			, bool transact
		) {
};

void TblFmncRMToolMTooltype::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncRMToolMTooltype::loadRecByRef(
			ubigint ref
			, FmncRMToolMTooltype** rec
		) {
	return false;
};

ubigint TblFmncRMToolMTooltype::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblFmncRMToolMTooltype::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncRMToolMTooltype& rst
		) {
	ubigint numload = 0;
	FmncRMToolMTooltype* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncRMToolMTooltype
 ******************************************************************************/

MyTblFmncRMToolMTooltype::MyTblFmncRMToolMTooltype() : TblFmncRMToolMTooltype(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncRMToolMTooltype::~MyTblFmncRMToolMTooltype() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncRMToolMTooltype::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncRMToolMTooltype (refFmncMTool, refFmncMTooltype, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncRMToolMTooltype SET refFmncMTool = ?, refFmncMTooltype = ?, srefsFmncKToolchar = ?, defSrefsFmncKSteppar = ?, optSrefsFmncKSteppar = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncRMToolMTooltype WHERE ref = ?", false);
};

bool MyTblFmncRMToolMTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncRMToolMTooltype** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncRMToolMTooltype* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMToolMTooltype / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncRMToolMTooltype();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMTool = atoll((char*) dbrow[1]); else _rec->refFmncMTool = 0;
		if (dbrow[2]) _rec->refFmncMTooltype = atoll((char*) dbrow[2]); else _rec->refFmncMTooltype = 0;
		if (dbrow[3]) _rec->srefsFmncKToolchar.assign(dbrow[3], dblengths[3]); else _rec->srefsFmncKToolchar = "";
		if (dbrow[4]) _rec->defSrefsFmncKSteppar.assign(dbrow[4], dblengths[4]); else _rec->defSrefsFmncKSteppar = "";
		if (dbrow[5]) _rec->optSrefsFmncKSteppar.assign(dbrow[5], dblengths[5]); else _rec->optSrefsFmncKSteppar = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncRMToolMTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMToolMTooltype& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncRMToolMTooltype* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncRMToolMTooltype / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncRMToolMTooltype();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMTool = atoll((char*) dbrow[1]); else rec->refFmncMTool = 0;
			if (dbrow[2]) rec->refFmncMTooltype = atoll((char*) dbrow[2]); else rec->refFmncMTooltype = 0;
			if (dbrow[3]) rec->srefsFmncKToolchar.assign(dbrow[3], dblengths[3]); else rec->srefsFmncKToolchar = "";
			if (dbrow[4]) rec->defSrefsFmncKSteppar.assign(dbrow[4], dblengths[4]); else rec->defSrefsFmncKSteppar = "";
			if (dbrow[5]) rec->optSrefsFmncKSteppar.assign(dbrow[5], dblengths[5]); else rec->optSrefsFmncKSteppar = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncRMToolMTooltype::insertRec(
			FmncRMToolMTooltype* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->srefsFmncKToolchar.length();
	l[3] = rec->defSrefsFmncKSteppar.length();
	l[4] = rec->optSrefsFmncKSteppar.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refFmncMTooltype,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefsFmncKToolchar.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->defSrefsFmncKSteppar.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->optSrefsFmncKSteppar.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMToolMTooltype / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMToolMTooltype / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncRMToolMTooltype::insertRst(
			ListFmncRMToolMTooltype& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncRMToolMTooltype::updateRec(
			FmncRMToolMTooltype* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->srefsFmncKToolchar.length();
	l[3] = rec->defSrefsFmncKSteppar.length();
	l[4] = rec->optSrefsFmncKSteppar.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refFmncMTooltype,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->srefsFmncKToolchar.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->defSrefsFmncKSteppar.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->optSrefsFmncKSteppar.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMToolMTooltype / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMToolMTooltype / stmtUpdateRec)\n");
};

void MyTblFmncRMToolMTooltype::updateRst(
			ListFmncRMToolMTooltype& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncRMToolMTooltype::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncRMToolMTooltype / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncRMToolMTooltype / stmtRemoveRecByRef)\n");
};

bool MyTblFmncRMToolMTooltype::loadRecByRef(
			ubigint ref
			, FmncRMToolMTooltype** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncRMToolMTooltype WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncRMToolMTooltype::loadRefsByTol(
			ubigint refFmncMTool
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblFmncRMToolMTooltype WHERE refFmncMTool = " + to_string(refFmncMTool) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncRMToolMTooltype
 ******************************************************************************/

PgTblFmncRMToolMTooltype::PgTblFmncRMToolMTooltype() : TblFmncRMToolMTooltype(), PgTable() {
};

PgTblFmncRMToolMTooltype::~PgTblFmncRMToolMTooltype() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncRMToolMTooltype::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncRMToolMTooltype_insertRec", "INSERT INTO TblFmncRMToolMTooltype (refFmncMTool, refFmncMTooltype, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMToolMTooltype_updateRec", "UPDATE TblFmncRMToolMTooltype SET refFmncMTool = $1, refFmncMTooltype = $2, srefsFmncKToolchar = $3, defSrefsFmncKSteppar = $4, optSrefsFmncKSteppar = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncRMToolMTooltype_removeRecByRef", "DELETE FROM TblFmncRMToolMTooltype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncRMToolMTooltype_loadRecByRef", "SELECT ref, refFmncMTool, refFmncMTooltype, srefsFmncKToolchar, defSrefsFmncKSteppar, optSrefsFmncKSteppar FROM TblFmncRMToolMTooltype WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncRMToolMTooltype_loadRefsByTol", "SELECT ref FROM TblFmncRMToolMTooltype WHERE refFmncMTool = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncRMToolMTooltype::loadRec(
			PGresult* res
			, FmncRMToolMTooltype** rec
		) {
	char* ptr;

	FmncRMToolMTooltype* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncRMToolMTooltype();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "reffmncmtooltype"),
			PQfnumber(res, "srefsfmncktoolchar"),
			PQfnumber(res, "defsrefsfmncksteppar"),
			PQfnumber(res, "optsrefsfmncksteppar")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refFmncMTooltype = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srefsFmncKToolchar.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->defSrefsFmncKSteppar.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->optSrefsFmncKSteppar.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncRMToolMTooltype::loadRst(
			PGresult* res
			, const bool append
			, ListFmncRMToolMTooltype& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncRMToolMTooltype* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "reffmncmtooltype"),
			PQfnumber(res, "srefsfmncktoolchar"),
			PQfnumber(res, "defsrefsfmncksteppar"),
			PQfnumber(res, "optsrefsfmncksteppar")
		};

		while (numread < numrow) {
			rec = new FmncRMToolMTooltype();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refFmncMTooltype = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srefsFmncKToolchar.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->defSrefsFmncKSteppar.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->optSrefsFmncKSteppar.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncRMToolMTooltype::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncRMToolMTooltype** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMToolMTooltype / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncRMToolMTooltype::loadRecBySQL(
			const string& sqlstr
			, FmncRMToolMTooltype** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncRMToolMTooltype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncRMToolMTooltype& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncRMToolMTooltype::insertRec(
			FmncRMToolMTooltype* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _refFmncMTooltype = htonl64(rec->refFmncMTooltype);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_refFmncMTooltype,
		rec->srefsFmncKToolchar.c_str(),
		rec->defSrefsFmncKSteppar.c_str(),
		rec->optSrefsFmncKSteppar.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncRMToolMTooltype_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMToolMTooltype_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncRMToolMTooltype::insertRst(
			ListFmncRMToolMTooltype& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncRMToolMTooltype::updateRec(
			FmncRMToolMTooltype* rec
		) {
	PGresult* res;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _refFmncMTooltype = htonl64(rec->refFmncMTooltype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_refFmncMTooltype,
		rec->srefsFmncKToolchar.c_str(),
		rec->defSrefsFmncKSteppar.c_str(),
		rec->optSrefsFmncKSteppar.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncRMToolMTooltype_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMToolMTooltype_updateRec)\n");

	PQclear(res);
};

void PgTblFmncRMToolMTooltype::updateRst(
			ListFmncRMToolMTooltype& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncRMToolMTooltype::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncRMToolMTooltype_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncRMToolMTooltype_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncRMToolMTooltype::loadRecByRef(
			ubigint ref
			, FmncRMToolMTooltype** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncRMToolMTooltype_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncRMToolMTooltype::loadRefsByTol(
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

	return loadRefsByStmt("TblFmncRMToolMTooltype_loadRefsByTol", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

