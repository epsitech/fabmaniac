/**
  * \file FmncAVValuelistVal.cpp
  * database access for table TblFmncAVValuelistVal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAVValuelistVal.h"

/******************************************************************************
 class FmncAVValuelistVal
 ******************************************************************************/

FmncAVValuelistVal::FmncAVValuelistVal(
			const ubigint ref
			, const uint vlsIxFmncVValuelist
			, const uint vlsNum
			, const uint x1IxFmncVLocale
			, const string Val
		) {

	this->ref = ref;
	this->vlsIxFmncVValuelist = vlsIxFmncVValuelist;
	this->vlsNum = vlsNum;
	this->x1IxFmncVLocale = x1IxFmncVLocale;
	this->Val = Val;
};

bool FmncAVValuelistVal::operator==(
			const FmncAVValuelistVal& comp
		) {
	return false;
};

bool FmncAVValuelistVal::operator!=(
			const FmncAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAVValuelistVal
 ******************************************************************************/

ListFmncAVValuelistVal::ListFmncAVValuelistVal() {
};

ListFmncAVValuelistVal::ListFmncAVValuelistVal(
			const ListFmncAVValuelistVal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAVValuelistVal(*(src.nodes[i]));
};

ListFmncAVValuelistVal::~ListFmncAVValuelistVal() {
	clear();
};

void ListFmncAVValuelistVal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAVValuelistVal::size() const {
	return(nodes.size());
};

void ListFmncAVValuelistVal::append(
			FmncAVValuelistVal* rec
		) {
	nodes.push_back(rec);
};

FmncAVValuelistVal* ListFmncAVValuelistVal::operator[](
			const uint ix
		) {
	FmncAVValuelistVal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAVValuelistVal& ListFmncAVValuelistVal::operator=(
			const ListFmncAVValuelistVal& src
		) {
	FmncAVValuelistVal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAVValuelistVal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAVValuelistVal::operator==(
			const ListFmncAVValuelistVal& comp
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

bool ListFmncAVValuelistVal::operator!=(
			const ListFmncAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAVValuelistVal
 ******************************************************************************/

TblFmncAVValuelistVal::TblFmncAVValuelistVal() {
};

TblFmncAVValuelistVal::~TblFmncAVValuelistVal() {
};

bool TblFmncAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, FmncAVValuelistVal** rec
		) {
	return false;
};

ubigint TblFmncAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	return 0;
};

void TblFmncAVValuelistVal::insertRec(
			FmncAVValuelistVal* rec
		) {
};

ubigint TblFmncAVValuelistVal::insertNewRec(
			FmncAVValuelistVal** rec
			, const uint vlsIxFmncVValuelist
			, const uint vlsNum
			, const uint x1IxFmncVLocale
			, const string Val
		) {
	ubigint retval = 0;
	FmncAVValuelistVal* _rec = NULL;

	_rec = new FmncAVValuelistVal(0, vlsIxFmncVValuelist, vlsNum, x1IxFmncVLocale, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAVValuelistVal::appendNewRecToRst(
			ListFmncAVValuelistVal& rst
			, FmncAVValuelistVal** rec
			, const uint vlsIxFmncVValuelist
			, const uint vlsNum
			, const uint x1IxFmncVLocale
			, const string Val
		) {
	ubigint retval = 0;
	FmncAVValuelistVal* _rec = NULL;

	retval = insertNewRec(&_rec, vlsIxFmncVValuelist, vlsNum, x1IxFmncVLocale, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAVValuelistVal::insertRst(
			ListFmncAVValuelistVal& rst
			, bool transact
		) {
};

void TblFmncAVValuelistVal::updateRec(
			FmncAVValuelistVal* rec
		) {
};

void TblFmncAVValuelistVal::updateRst(
			ListFmncAVValuelistVal& rst
			, bool transact
		) {
};

void TblFmncAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAVValuelistVal::loadRecByRef(
			ubigint ref
			, FmncAVValuelistVal** rec
		) {
	return false;
};

ubigint TblFmncAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxFmncVValuelist
			, uint x1IxFmncVLocale
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblFmncAVValuelistVal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	ubigint numload = 0;
	FmncAVValuelistVal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAVValuelistVal
 ******************************************************************************/

MyTblFmncAVValuelistVal::MyTblFmncAVValuelistVal() : TblFmncAVValuelistVal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAVValuelistVal::~MyTblFmncAVValuelistVal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAVValuelistVal (vlsIxFmncVValuelist, vlsNum, x1IxFmncVLocale, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAVValuelistVal SET vlsIxFmncVValuelist = ?, vlsNum = ?, x1IxFmncVLocale = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAVValuelistVal WHERE ref = ?", false);
};

bool MyTblFmncAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, FmncAVValuelistVal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAVValuelistVal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAVValuelistVal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAVValuelistVal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->vlsIxFmncVValuelist = atol((char*) dbrow[1]); else _rec->vlsIxFmncVValuelist = 0;
		if (dbrow[2]) _rec->vlsNum = atol((char*) dbrow[2]); else _rec->vlsNum = 0;
		if (dbrow[3]) _rec->x1IxFmncVLocale = atol((char*) dbrow[3]); else _rec->x1IxFmncVLocale = 0;
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAVValuelistVal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAVValuelistVal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAVValuelistVal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->vlsIxFmncVValuelist = atol((char*) dbrow[1]); else rec->vlsIxFmncVValuelist = 0;
			if (dbrow[2]) rec->vlsNum = atol((char*) dbrow[2]); else rec->vlsNum = 0;
			if (dbrow[3]) rec->x1IxFmncVLocale = atol((char*) dbrow[3]); else rec->x1IxFmncVLocale = 0;
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAVValuelistVal::insertRec(
			FmncAVValuelistVal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxFmncVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxFmncVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVValuelistVal / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVValuelistVal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAVValuelistVal::insertRst(
			ListFmncAVValuelistVal& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAVValuelistVal::updateRec(
			FmncAVValuelistVal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxFmncVValuelist,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x1IxFmncVLocale,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVValuelistVal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVValuelistVal / stmtUpdateRec)\n");
};

void MyTblFmncAVValuelistVal::updateRst(
			ListFmncAVValuelistVal& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVValuelistVal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVValuelistVal / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAVValuelistVal::loadRecByRef(
			ubigint ref
			, FmncAVValuelistVal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAVValuelistVal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblFmncAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxFmncVValuelist
			, uint x1IxFmncVLocale
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	return loadRstBySQL("SELECT ref, vlsIxFmncVValuelist, vlsNum, x1IxFmncVLocale, Val FROM TblFmncAVValuelistVal WHERE vlsIxFmncVValuelist = " + to_string(vlsIxFmncVValuelist) + " AND x1IxFmncVLocale = " + to_string(x1IxFmncVLocale) + " ORDER BY vlsNum ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAVValuelistVal
 ******************************************************************************/

PgTblFmncAVValuelistVal::PgTblFmncAVValuelistVal() : TblFmncAVValuelistVal(), PgTable() {
};

PgTblFmncAVValuelistVal::~PgTblFmncAVValuelistVal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAVValuelistVal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAVValuelistVal_insertRec", "INSERT INTO TblFmncAVValuelistVal (vlsIxFmncVValuelist, vlsNum, x1IxFmncVLocale, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVValuelistVal_updateRec", "UPDATE TblFmncAVValuelistVal SET vlsIxFmncVValuelist = $1, vlsNum = $2, x1IxFmncVLocale = $3, Val = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVValuelistVal_removeRecByRef", "DELETE FROM TblFmncAVValuelistVal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAVValuelistVal_loadRecByRef", "SELECT ref, vlsIxFmncVValuelist, vlsNum, x1IxFmncVLocale, Val FROM TblFmncAVValuelistVal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAVValuelistVal_loadRstByVlsLcl", "SELECT ref, vlsIxFmncVValuelist, vlsNum, x1IxFmncVLocale, Val FROM TblFmncAVValuelistVal WHERE vlsIxFmncVValuelist = $1 AND x1IxFmncVLocale = $2 ORDER BY vlsNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAVValuelistVal::loadRec(
			PGresult* res
			, FmncAVValuelistVal** rec
		) {
	char* ptr;

	FmncAVValuelistVal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAVValuelistVal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixfmncvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixfmncvlocale"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->vlsIxFmncVValuelist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->vlsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxFmncVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAVValuelistVal::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAVValuelistVal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixfmncvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixfmncvlocale"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new FmncAVValuelistVal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->vlsIxFmncVValuelist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->vlsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxFmncVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAVValuelistVal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVValuelistVal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblFmncAVValuelistVal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVValuelistVal / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblFmncAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, FmncAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAVValuelistVal::insertRec(
			FmncAVValuelistVal* rec
		) {
	PGresult* res;
	char* ptr;

	uint _vlsIxFmncVValuelist = htonl(rec->vlsIxFmncVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxFmncVLocale = htonl(rec->x1IxFmncVLocale);

	const char* vals[] = {
		(char*) &_vlsIxFmncVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxFmncVLocale,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncAVValuelistVal_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVValuelistVal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAVValuelistVal::insertRst(
			ListFmncAVValuelistVal& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAVValuelistVal::updateRec(
			FmncAVValuelistVal* rec
		) {
	PGresult* res;

	uint _vlsIxFmncVValuelist = htonl(rec->vlsIxFmncVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxFmncVLocale = htonl(rec->x1IxFmncVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_vlsIxFmncVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxFmncVLocale,
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAVValuelistVal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVValuelistVal_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAVValuelistVal::updateRst(
			ListFmncAVValuelistVal& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAVValuelistVal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAVValuelistVal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVValuelistVal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAVValuelistVal::loadRecByRef(
			ubigint ref
			, FmncAVValuelistVal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAVValuelistVal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblFmncAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxFmncVValuelist
			, uint x1IxFmncVLocale
			, const bool append
			, ListFmncAVValuelistVal& rst
		) {
	uint _vlsIxFmncVValuelist = htonl(vlsIxFmncVValuelist);
	uint _x1IxFmncVLocale = htonl(x1IxFmncVLocale);

	const char* vals[] = {
		(char*) &_vlsIxFmncVValuelist,
		(char*) &_x1IxFmncVLocale
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblFmncAVValuelistVal_loadRstByVlsLcl", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

