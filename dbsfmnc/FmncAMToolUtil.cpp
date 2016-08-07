/**
  * \file FmncAMToolUtil.cpp
  * database access for table TblFmncAMToolUtil (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMToolUtil.h"

/******************************************************************************
 class FmncAMToolUtil
 ******************************************************************************/

FmncAMToolUtil::FmncAMToolUtil(
			const ubigint ref
			, const ubigint refFmncMTool
			, const ubigint x1RefFmncMFabproject
			, const ubigint x2RefFmncMFabuser
			, const uint startd
			, const uint startt
			, const uint stopt
			, const double Unitprice
			, const string Comment
		) {

	this->ref = ref;
	this->refFmncMTool = refFmncMTool;
	this->x1RefFmncMFabproject = x1RefFmncMFabproject;
	this->x2RefFmncMFabuser = x2RefFmncMFabuser;
	this->startd = startd;
	this->startt = startt;
	this->stopt = stopt;
	this->Unitprice = Unitprice;
	this->Comment = Comment;
};

bool FmncAMToolUtil::operator==(
			const FmncAMToolUtil& comp
		) {
	return false;
};

bool FmncAMToolUtil::operator!=(
			const FmncAMToolUtil& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMToolUtil
 ******************************************************************************/

ListFmncAMToolUtil::ListFmncAMToolUtil() {
};

ListFmncAMToolUtil::ListFmncAMToolUtil(
			const ListFmncAMToolUtil& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMToolUtil(*(src.nodes[i]));
};

ListFmncAMToolUtil::~ListFmncAMToolUtil() {
	clear();
};

void ListFmncAMToolUtil::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMToolUtil::size() const {
	return(nodes.size());
};

void ListFmncAMToolUtil::append(
			FmncAMToolUtil* rec
		) {
	nodes.push_back(rec);
};

FmncAMToolUtil* ListFmncAMToolUtil::operator[](
			const uint ix
		) {
	FmncAMToolUtil* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMToolUtil& ListFmncAMToolUtil::operator=(
			const ListFmncAMToolUtil& src
		) {
	FmncAMToolUtil* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMToolUtil(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMToolUtil::operator==(
			const ListFmncAMToolUtil& comp
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

bool ListFmncAMToolUtil::operator!=(
			const ListFmncAMToolUtil& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMToolUtil
 ******************************************************************************/

TblFmncAMToolUtil::TblFmncAMToolUtil() {
};

TblFmncAMToolUtil::~TblFmncAMToolUtil() {
};

bool TblFmncAMToolUtil::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolUtil** rec
		) {
	return false;
};

ubigint TblFmncAMToolUtil::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolUtil& rst
		) {
	return 0;
};

void TblFmncAMToolUtil::insertRec(
			FmncAMToolUtil* rec
		) {
};

ubigint TblFmncAMToolUtil::insertNewRec(
			FmncAMToolUtil** rec
			, const ubigint refFmncMTool
			, const ubigint x1RefFmncMFabproject
			, const ubigint x2RefFmncMFabuser
			, const uint startd
			, const uint startt
			, const uint stopt
			, const double Unitprice
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAMToolUtil* _rec = NULL;

	_rec = new FmncAMToolUtil(0, refFmncMTool, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMToolUtil::appendNewRecToRst(
			ListFmncAMToolUtil& rst
			, FmncAMToolUtil** rec
			, const ubigint refFmncMTool
			, const ubigint x1RefFmncMFabproject
			, const ubigint x2RefFmncMFabuser
			, const uint startd
			, const uint startt
			, const uint stopt
			, const double Unitprice
			, const string Comment
		) {
	ubigint retval = 0;
	FmncAMToolUtil* _rec = NULL;

	retval = insertNewRec(&_rec, refFmncMTool, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMToolUtil::insertRst(
			ListFmncAMToolUtil& rst
			, bool transact
		) {
};

void TblFmncAMToolUtil::updateRec(
			FmncAMToolUtil* rec
		) {
};

void TblFmncAMToolUtil::updateRst(
			ListFmncAMToolUtil& rst
			, bool transact
		) {
};

void TblFmncAMToolUtil::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMToolUtil::loadRecByRef(
			ubigint ref
			, FmncAMToolUtil** rec
		) {
	return false;
};

ubigint TblFmncAMToolUtil::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMToolUtil& rst
		) {
	ubigint numload = 0;
	FmncAMToolUtil* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMToolUtil
 ******************************************************************************/

MyTblFmncAMToolUtil::MyTblFmncAMToolUtil() : TblFmncAMToolUtil(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMToolUtil::~MyTblFmncAMToolUtil() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMToolUtil::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMToolUtil (refFmncMTool, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMToolUtil SET refFmncMTool = ?, x1RefFmncMFabproject = ?, x2RefFmncMFabuser = ?, startd = ?, startt = ?, stopt = ?, Unitprice = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMToolUtil WHERE ref = ?", false);
};

bool MyTblFmncAMToolUtil::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolUtil** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMToolUtil* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMToolUtil / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMToolUtil();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refFmncMTool = atoll((char*) dbrow[1]); else _rec->refFmncMTool = 0;
		if (dbrow[2]) _rec->x1RefFmncMFabproject = atoll((char*) dbrow[2]); else _rec->x1RefFmncMFabproject = 0;
		if (dbrow[3]) _rec->x2RefFmncMFabuser = atoll((char*) dbrow[3]); else _rec->x2RefFmncMFabuser = 0;
		if (dbrow[4]) _rec->startd = atol((char*) dbrow[4]); else _rec->startd = 0;
		if (dbrow[5]) _rec->startt = atol((char*) dbrow[5]); else _rec->startt = 0;
		if (dbrow[6]) _rec->stopt = atol((char*) dbrow[6]); else _rec->stopt = 0;
		if (dbrow[7]) _rec->Unitprice = atof((char*) dbrow[7]); else _rec->Unitprice = 0.0;
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMToolUtil::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolUtil& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMToolUtil* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMToolUtil / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMToolUtil();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refFmncMTool = atoll((char*) dbrow[1]); else rec->refFmncMTool = 0;
			if (dbrow[2]) rec->x1RefFmncMFabproject = atoll((char*) dbrow[2]); else rec->x1RefFmncMFabproject = 0;
			if (dbrow[3]) rec->x2RefFmncMFabuser = atoll((char*) dbrow[3]); else rec->x2RefFmncMFabuser = 0;
			if (dbrow[4]) rec->startd = atol((char*) dbrow[4]); else rec->startd = 0;
			if (dbrow[5]) rec->startt = atol((char*) dbrow[5]); else rec->startt = 0;
			if (dbrow[6]) rec->stopt = atol((char*) dbrow[6]); else rec->stopt = 0;
			if (dbrow[7]) rec->Unitprice = atof((char*) dbrow[7]); else rec->Unitprice = 0.0;
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMToolUtil::insertRec(
			FmncAMToolUtil* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefFmncMFabproject,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefFmncMFabuser,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->startd,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->startt,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->stopt,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->Unitprice,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolUtil / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolUtil / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMToolUtil::insertRst(
			ListFmncAMToolUtil& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMToolUtil::updateRec(
			FmncAMToolUtil* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refFmncMTool,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefFmncMFabproject,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->x2RefFmncMFabuser,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->startd,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->startt,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->stopt,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->Unitprice,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolUtil / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolUtil / stmtUpdateRec)\n");
};

void MyTblFmncAMToolUtil::updateRst(
			ListFmncAMToolUtil& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMToolUtil::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMToolUtil / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMToolUtil / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMToolUtil::loadRecByRef(
			ubigint ref
			, FmncAMToolUtil** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMToolUtil WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMToolUtil
 ******************************************************************************/

PgTblFmncAMToolUtil::PgTblFmncAMToolUtil() : TblFmncAMToolUtil(), PgTable() {
};

PgTblFmncAMToolUtil::~PgTblFmncAMToolUtil() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMToolUtil::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMToolUtil_insertRec", "INSERT INTO TblFmncAMToolUtil (refFmncMTool, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMToolUtil_updateRec", "UPDATE TblFmncAMToolUtil SET refFmncMTool = $1, x1RefFmncMFabproject = $2, x2RefFmncMFabuser = $3, startd = $4, startt = $5, stopt = $6, Unitprice = $7, Comment = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMToolUtil_removeRecByRef", "DELETE FROM TblFmncAMToolUtil WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMToolUtil_loadRecByRef", "SELECT ref, refFmncMTool, x1RefFmncMFabproject, x2RefFmncMFabuser, startd, startt, stopt, Unitprice, Comment FROM TblFmncAMToolUtil WHERE ref = $1", 1, NULL);
};

bool PgTblFmncAMToolUtil::loadRec(
			PGresult* res
			, FmncAMToolUtil** rec
		) {
	char* ptr;

	FmncAMToolUtil* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMToolUtil();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1reffmncmfabproject"),
			PQfnumber(res, "x2reffmncmfabuser"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt"),
			PQfnumber(res, "stopt"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefFmncMFabproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2RefFmncMFabuser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->startt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->stopt = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Unitprice = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMToolUtil::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMToolUtil& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMToolUtil* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "reffmncmtool"),
			PQfnumber(res, "x1reffmncmfabproject"),
			PQfnumber(res, "x2reffmncmfabuser"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt"),
			PQfnumber(res, "stopt"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncAMToolUtil();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefFmncMFabproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2RefFmncMFabuser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->startt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->stopt = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Unitprice = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMToolUtil::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMToolUtil** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolUtil / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMToolUtil::loadRecBySQL(
			const string& sqlstr
			, FmncAMToolUtil** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMToolUtil::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMToolUtil& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMToolUtil::insertRec(
			FmncAMToolUtil* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _x1RefFmncMFabproject = htonl64(rec->x1RefFmncMFabproject);
	ubigint _x2RefFmncMFabuser = htonl64(rec->x2RefFmncMFabuser);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	uint _stopt = htonl(rec->stopt);
	string _Unitprice = to_string(rec->Unitprice);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1RefFmncMFabproject,
		(char*) &_x2RefFmncMFabuser,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_stopt,
		_Unitprice.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMToolUtil_insertRec", 8, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolUtil_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMToolUtil::insertRst(
			ListFmncAMToolUtil& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMToolUtil::updateRec(
			FmncAMToolUtil* rec
		) {
	PGresult* res;

	ubigint _refFmncMTool = htonl64(rec->refFmncMTool);
	ubigint _x1RefFmncMFabproject = htonl64(rec->x1RefFmncMFabproject);
	ubigint _x2RefFmncMFabuser = htonl64(rec->x2RefFmncMFabuser);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	uint _stopt = htonl(rec->stopt);
	string _Unitprice = to_string(rec->Unitprice);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refFmncMTool,
		(char*) &_x1RefFmncMFabproject,
		(char*) &_x2RefFmncMFabuser,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_stopt,
		_Unitprice.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMToolUtil_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolUtil_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMToolUtil::updateRst(
			ListFmncAMToolUtil& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMToolUtil::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMToolUtil_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMToolUtil_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMToolUtil::loadRecByRef(
			ubigint ref
			, FmncAMToolUtil** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMToolUtil_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

