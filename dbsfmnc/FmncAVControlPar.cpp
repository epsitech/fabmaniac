/**
  * \file FmncAVControlPar.cpp
  * database access for table TblFmncAVControlPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAVControlPar.h"

/******************************************************************************
 class FmncAVControlPar
 ******************************************************************************/

FmncAVControlPar::FmncAVControlPar(
			const ubigint ref
			, const uint ixFmncVControl
			, const ubigint x1RefFmncMUser
			, const uint x2IxFmncVLocale
			, const string Par
			, const string Val
		) {

	this->ref = ref;
	this->ixFmncVControl = ixFmncVControl;
	this->x1RefFmncMUser = x1RefFmncMUser;
	this->x2IxFmncVLocale = x2IxFmncVLocale;
	this->Par = Par;
	this->Val = Val;
};

bool FmncAVControlPar::operator==(
			const FmncAVControlPar& comp
		) {
	return false;
};

bool FmncAVControlPar::operator!=(
			const FmncAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAVControlPar
 ******************************************************************************/

ListFmncAVControlPar::ListFmncAVControlPar() {
};

ListFmncAVControlPar::ListFmncAVControlPar(
			const ListFmncAVControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAVControlPar(*(src.nodes[i]));
};

ListFmncAVControlPar::~ListFmncAVControlPar() {
	clear();
};

void ListFmncAVControlPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAVControlPar::size() const {
	return(nodes.size());
};

void ListFmncAVControlPar::append(
			FmncAVControlPar* rec
		) {
	nodes.push_back(rec);
};

FmncAVControlPar* ListFmncAVControlPar::operator[](
			const uint ix
		) {
	FmncAVControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAVControlPar& ListFmncAVControlPar::operator=(
			const ListFmncAVControlPar& src
		) {
	FmncAVControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAVControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAVControlPar::operator==(
			const ListFmncAVControlPar& comp
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

bool ListFmncAVControlPar::operator!=(
			const ListFmncAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAVControlPar
 ******************************************************************************/

TblFmncAVControlPar::TblFmncAVControlPar() {
};

TblFmncAVControlPar::~TblFmncAVControlPar() {
};

bool TblFmncAVControlPar::loadRecBySQL(
			const string& sqlstr
			, FmncAVControlPar** rec
		) {
	return false;
};

ubigint TblFmncAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVControlPar& rst
		) {
	return 0;
};

void TblFmncAVControlPar::insertRec(
			FmncAVControlPar* rec
		) {
};

ubigint TblFmncAVControlPar::insertNewRec(
			FmncAVControlPar** rec
			, const uint ixFmncVControl
			, const ubigint x1RefFmncMUser
			, const uint x2IxFmncVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	FmncAVControlPar* _rec = NULL;

	_rec = new FmncAVControlPar(0, ixFmncVControl, x1RefFmncMUser, x2IxFmncVLocale, Par, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAVControlPar::appendNewRecToRst(
			ListFmncAVControlPar& rst
			, FmncAVControlPar** rec
			, const uint ixFmncVControl
			, const ubigint x1RefFmncMUser
			, const uint x2IxFmncVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	FmncAVControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, ixFmncVControl, x1RefFmncMUser, x2IxFmncVLocale, Par, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAVControlPar::insertRst(
			ListFmncAVControlPar& rst
			, bool transact
		) {
};

void TblFmncAVControlPar::updateRec(
			FmncAVControlPar* rec
		) {
};

void TblFmncAVControlPar::updateRst(
			ListFmncAVControlPar& rst
			, bool transact
		) {
};

void TblFmncAVControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAVControlPar::loadRecByRef(
			ubigint ref
			, FmncAVControlPar** rec
		) {
	return false;
};

bool TblFmncAVControlPar::loadRefByCtlUsrPar(
			uint ixFmncVControl
			, ubigint x1RefFmncMUser
			, string Par
			, ubigint& ref
		) {
	return false;
};

bool TblFmncAVControlPar::loadValByCtlUsrPar(
			uint ixFmncVControl
			, ubigint x1RefFmncMUser
			, string Par
			, string& val
		) {
	return false;
};

ubigint TblFmncAVControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAVControlPar& rst
		) {
	ubigint numload = 0;
	FmncAVControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAVControlPar
 ******************************************************************************/

MyTblFmncAVControlPar::MyTblFmncAVControlPar() : TblFmncAVControlPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAVControlPar::~MyTblFmncAVControlPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAVControlPar (ixFmncVControl, x1RefFmncMUser, x2IxFmncVLocale, Par, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAVControlPar SET ixFmncVControl = ?, x1RefFmncMUser = ?, x2IxFmncVLocale = ?, Par = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAVControlPar WHERE ref = ?", false);
};

bool MyTblFmncAVControlPar::loadRecBySQL(
			const string& sqlstr
			, FmncAVControlPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAVControlPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAVControlPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAVControlPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixFmncVControl = atol((char*) dbrow[1]); else _rec->ixFmncVControl = 0;
		if (dbrow[2]) _rec->x1RefFmncMUser = atoll((char*) dbrow[2]); else _rec->x1RefFmncMUser = 0;
		if (dbrow[3]) _rec->x2IxFmncVLocale = atol((char*) dbrow[3]); else _rec->x2IxFmncVLocale = 0;
		if (dbrow[4]) _rec->Par.assign(dbrow[4], dblengths[4]); else _rec->Par = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVControlPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAVControlPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAVControlPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAVControlPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixFmncVControl = atol((char*) dbrow[1]); else rec->ixFmncVControl = 0;
			if (dbrow[2]) rec->x1RefFmncMUser = atoll((char*) dbrow[2]); else rec->x1RefFmncMUser = 0;
			if (dbrow[3]) rec->x2IxFmncVLocale = atol((char*) dbrow[3]); else rec->x2IxFmncVLocale = 0;
			if (dbrow[4]) rec->Par.assign(dbrow[4], dblengths[4]); else rec->Par = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAVControlPar::insertRec(
			FmncAVControlPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixFmncVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefFmncMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxFmncVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVControlPar / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVControlPar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAVControlPar::insertRst(
			ListFmncAVControlPar& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAVControlPar::updateRec(
			FmncAVControlPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixFmncVControl,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefFmncMUser,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x2IxFmncVLocale,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVControlPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVControlPar / stmtUpdateRec)\n");
};

void MyTblFmncAVControlPar::updateRst(
			ListFmncAVControlPar& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAVControlPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAVControlPar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAVControlPar / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAVControlPar::loadRecByRef(
			ubigint ref
			, FmncAVControlPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAVControlPar WHERE ref = " + to_string(ref), rec);
};

bool MyTblFmncAVControlPar::loadRefByCtlUsrPar(
			uint ixFmncVControl
			, ubigint x1RefFmncMUser
			, string Par
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblFmncAVControlPar WHERE ixFmncVControl = " + to_string(ixFmncVControl) + " AND x1RefFmncMUser = " + to_string(x1RefFmncMUser) + " AND Par = '" + Par + "'", ref);
};

bool MyTblFmncAVControlPar::loadValByCtlUsrPar(
			uint ixFmncVControl
			, ubigint x1RefFmncMUser
			, string Par
			, string& val
		) {
	return loadStringBySQL("SELECT Val FROM TblFmncAVControlPar WHERE ixFmncVControl = " + to_string(ixFmncVControl) + " AND x1RefFmncMUser = " + to_string(x1RefFmncMUser) + " AND Par = '" + Par + "'", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAVControlPar
 ******************************************************************************/

PgTblFmncAVControlPar::PgTblFmncAVControlPar() : TblFmncAVControlPar(), PgTable() {
};

PgTblFmncAVControlPar::~PgTblFmncAVControlPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAVControlPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAVControlPar_insertRec", "INSERT INTO TblFmncAVControlPar (ixFmncVControl, x1RefFmncMUser, x2IxFmncVLocale, Par, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVControlPar_updateRec", "UPDATE TblFmncAVControlPar SET ixFmncVControl = $1, x1RefFmncMUser = $2, x2IxFmncVLocale = $3, Par = $4, Val = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVControlPar_removeRecByRef", "DELETE FROM TblFmncAVControlPar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAVControlPar_loadRecByRef", "SELECT ref, ixFmncVControl, x1RefFmncMUser, x2IxFmncVLocale, Par, Val FROM TblFmncAVControlPar WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblFmncAVControlPar_loadRefByCtlUsrPar", "SELECT ref FROM TblFmncAVControlPar WHERE ixFmncVControl = $1 AND x1RefFmncMUser = $2 AND Par = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAVControlPar_loadValByCtlUsrPar", "SELECT Val FROM TblFmncAVControlPar WHERE ixFmncVControl = $1 AND x1RefFmncMUser = $2 AND Par = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncAVControlPar::loadRec(
			PGresult* res
			, FmncAVControlPar** rec
		) {
	char* ptr;

	FmncAVControlPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAVControlPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixfmncvcontrol"),
			PQfnumber(res, "x1reffmncmuser"),
			PQfnumber(res, "x2ixfmncvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixFmncVControl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefFmncMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2IxFmncVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Par.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAVControlPar::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAVControlPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAVControlPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixfmncvcontrol"),
			PQfnumber(res, "x1reffmncmuser"),
			PQfnumber(res, "x2ixfmncvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new FmncAVControlPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixFmncVControl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefFmncMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2IxFmncVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Par.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAVControlPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAVControlPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVControlPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAVControlPar::loadRecBySQL(
			const string& sqlstr
			, FmncAVControlPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAVControlPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAVControlPar::insertRec(
			FmncAVControlPar* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixFmncVControl = htonl(rec->ixFmncVControl);
	ubigint _x1RefFmncMUser = htonl64(rec->x1RefFmncMUser);
	uint _x2IxFmncVLocale = htonl(rec->x2IxFmncVLocale);

	const char* vals[] = {
		(char*) &_ixFmncVControl,
		(char*) &_x1RefFmncMUser,
		(char*) &_x2IxFmncVLocale,
		rec->Par.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAVControlPar_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVControlPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAVControlPar::insertRst(
			ListFmncAVControlPar& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAVControlPar::updateRec(
			FmncAVControlPar* rec
		) {
	PGresult* res;

	uint _ixFmncVControl = htonl(rec->ixFmncVControl);
	ubigint _x1RefFmncMUser = htonl64(rec->x1RefFmncMUser);
	uint _x2IxFmncVLocale = htonl(rec->x2IxFmncVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixFmncVControl,
		(char*) &_x1RefFmncMUser,
		(char*) &_x2IxFmncVLocale,
		rec->Par.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAVControlPar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVControlPar_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAVControlPar::updateRst(
			ListFmncAVControlPar& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAVControlPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAVControlPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAVControlPar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAVControlPar::loadRecByRef(
			ubigint ref
			, FmncAVControlPar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAVControlPar_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblFmncAVControlPar::loadRefByCtlUsrPar(
			uint ixFmncVControl
			, ubigint x1RefFmncMUser
			, string Par
			, ubigint& ref
		) {
	uint _ixFmncVControl = htonl(ixFmncVControl);
	ubigint _x1RefFmncMUser = htonl64(x1RefFmncMUser);

	const char* vals[] = {
		(char*) &_ixFmncVControl,
		(char*) &_x1RefFmncMUser,
		Par.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadUbigintByStmt("TblFmncAVControlPar_loadRefByCtlUsrPar", 3, vals, l, f, ref);
};

bool PgTblFmncAVControlPar::loadValByCtlUsrPar(
			uint ixFmncVControl
			, ubigint x1RefFmncMUser
			, string Par
			, string& val
		) {
	uint _ixFmncVControl = htonl(ixFmncVControl);
	ubigint _x1RefFmncMUser = htonl64(x1RefFmncMUser);

	const char* vals[] = {
		(char*) &_ixFmncVControl,
		(char*) &_x1RefFmncMUser,
		Par.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadStringByStmt("TblFmncAVControlPar_loadValByCtlUsrPar", 3, vals, l, f, val);
};

// IP pgTbl --- END

