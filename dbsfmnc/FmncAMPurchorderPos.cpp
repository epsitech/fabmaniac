/**
  * \file FmncAMPurchorderPos.cpp
  * database access for table TblFmncAMPurchorderPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMPurchorderPos.h"

/******************************************************************************
 class FmncAMPurchorderPos
 ******************************************************************************/

FmncAMPurchorderPos::FmncAMPurchorderPos(
			const ubigint ref
			, const ubigint pcoRefFmncMPurchorder
			, const uint pcoNum
			, const double Quantity
			, const string Itemno
			, const ubigint refFmncMArticle
			, const double Unitprice
			, const double Price
		) {

	this->ref = ref;
	this->pcoRefFmncMPurchorder = pcoRefFmncMPurchorder;
	this->pcoNum = pcoNum;
	this->Quantity = Quantity;
	this->Itemno = Itemno;
	this->refFmncMArticle = refFmncMArticle;
	this->Unitprice = Unitprice;
	this->Price = Price;
};

bool FmncAMPurchorderPos::operator==(
			const FmncAMPurchorderPos& comp
		) {
	return false;
};

bool FmncAMPurchorderPos::operator!=(
			const FmncAMPurchorderPos& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMPurchorderPos
 ******************************************************************************/

ListFmncAMPurchorderPos::ListFmncAMPurchorderPos() {
};

ListFmncAMPurchorderPos::ListFmncAMPurchorderPos(
			const ListFmncAMPurchorderPos& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMPurchorderPos(*(src.nodes[i]));
};

ListFmncAMPurchorderPos::~ListFmncAMPurchorderPos() {
	clear();
};

void ListFmncAMPurchorderPos::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMPurchorderPos::size() const {
	return(nodes.size());
};

void ListFmncAMPurchorderPos::append(
			FmncAMPurchorderPos* rec
		) {
	nodes.push_back(rec);
};

FmncAMPurchorderPos* ListFmncAMPurchorderPos::operator[](
			const uint ix
		) {
	FmncAMPurchorderPos* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMPurchorderPos& ListFmncAMPurchorderPos::operator=(
			const ListFmncAMPurchorderPos& src
		) {
	FmncAMPurchorderPos* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMPurchorderPos(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMPurchorderPos::operator==(
			const ListFmncAMPurchorderPos& comp
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

bool ListFmncAMPurchorderPos::operator!=(
			const ListFmncAMPurchorderPos& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMPurchorderPos
 ******************************************************************************/

TblFmncAMPurchorderPos::TblFmncAMPurchorderPos() {
};

TblFmncAMPurchorderPos::~TblFmncAMPurchorderPos() {
};

bool TblFmncAMPurchorderPos::loadRecBySQL(
			const string& sqlstr
			, FmncAMPurchorderPos** rec
		) {
	return false;
};

ubigint TblFmncAMPurchorderPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMPurchorderPos& rst
		) {
	return 0;
};

void TblFmncAMPurchorderPos::insertRec(
			FmncAMPurchorderPos* rec
		) {
};

ubigint TblFmncAMPurchorderPos::insertNewRec(
			FmncAMPurchorderPos** rec
			, const ubigint pcoRefFmncMPurchorder
			, const uint pcoNum
			, const double Quantity
			, const string Itemno
			, const ubigint refFmncMArticle
			, const double Unitprice
			, const double Price
		) {
	ubigint retval = 0;
	FmncAMPurchorderPos* _rec = NULL;

	_rec = new FmncAMPurchorderPos(0, pcoRefFmncMPurchorder, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMPurchorderPos::appendNewRecToRst(
			ListFmncAMPurchorderPos& rst
			, FmncAMPurchorderPos** rec
			, const ubigint pcoRefFmncMPurchorder
			, const uint pcoNum
			, const double Quantity
			, const string Itemno
			, const ubigint refFmncMArticle
			, const double Unitprice
			, const double Price
		) {
	ubigint retval = 0;
	FmncAMPurchorderPos* _rec = NULL;

	retval = insertNewRec(&_rec, pcoRefFmncMPurchorder, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMPurchorderPos::insertRst(
			ListFmncAMPurchorderPos& rst
			, bool transact
		) {
};

void TblFmncAMPurchorderPos::updateRec(
			FmncAMPurchorderPos* rec
		) {
};

void TblFmncAMPurchorderPos::updateRst(
			ListFmncAMPurchorderPos& rst
			, bool transact
		) {
};

void TblFmncAMPurchorderPos::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMPurchorderPos::loadRecByRef(
			ubigint ref
			, FmncAMPurchorderPos** rec
		) {
	return false;
};

ubigint TblFmncAMPurchorderPos::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMPurchorderPos& rst
		) {
	ubigint numload = 0;
	FmncAMPurchorderPos* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMPurchorderPos
 ******************************************************************************/

MyTblFmncAMPurchorderPos::MyTblFmncAMPurchorderPos() : TblFmncAMPurchorderPos(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMPurchorderPos::~MyTblFmncAMPurchorderPos() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMPurchorderPos::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMPurchorderPos (pcoRefFmncMPurchorder, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMPurchorderPos SET pcoRefFmncMPurchorder = ?, pcoNum = ?, Quantity = ?, Itemno = ?, refFmncMArticle = ?, Unitprice = ?, Price = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMPurchorderPos WHERE ref = ?", false);
};

bool MyTblFmncAMPurchorderPos::loadRecBySQL(
			const string& sqlstr
			, FmncAMPurchorderPos** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMPurchorderPos* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMPurchorderPos / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMPurchorderPos();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->pcoRefFmncMPurchorder = atoll((char*) dbrow[1]); else _rec->pcoRefFmncMPurchorder = 0;
		if (dbrow[2]) _rec->pcoNum = atol((char*) dbrow[2]); else _rec->pcoNum = 0;
		if (dbrow[3]) _rec->Quantity = atof((char*) dbrow[3]); else _rec->Quantity = 0.0;
		if (dbrow[4]) _rec->Itemno.assign(dbrow[4], dblengths[4]); else _rec->Itemno = "";
		if (dbrow[5]) _rec->refFmncMArticle = atoll((char*) dbrow[5]); else _rec->refFmncMArticle = 0;
		if (dbrow[6]) _rec->Unitprice = atof((char*) dbrow[6]); else _rec->Unitprice = 0.0;
		if (dbrow[7]) _rec->Price = atof((char*) dbrow[7]); else _rec->Price = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMPurchorderPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMPurchorderPos& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMPurchorderPos* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMPurchorderPos / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMPurchorderPos();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->pcoRefFmncMPurchorder = atoll((char*) dbrow[1]); else rec->pcoRefFmncMPurchorder = 0;
			if (dbrow[2]) rec->pcoNum = atol((char*) dbrow[2]); else rec->pcoNum = 0;
			if (dbrow[3]) rec->Quantity = atof((char*) dbrow[3]); else rec->Quantity = 0.0;
			if (dbrow[4]) rec->Itemno.assign(dbrow[4], dblengths[4]); else rec->Itemno = "";
			if (dbrow[5]) rec->refFmncMArticle = atoll((char*) dbrow[5]); else rec->refFmncMArticle = 0;
			if (dbrow[6]) rec->Unitprice = atof((char*) dbrow[6]); else rec->Unitprice = 0.0;
			if (dbrow[7]) rec->Price = atof((char*) dbrow[7]); else rec->Price = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMPurchorderPos::insertRec(
			FmncAMPurchorderPos* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->Itemno.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->pcoRefFmncMPurchorder,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->pcoNum,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->Quantity,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Itemno.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refFmncMArticle,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->Unitprice,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->Price,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMPurchorderPos / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMPurchorderPos / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMPurchorderPos::insertRst(
			ListFmncAMPurchorderPos& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMPurchorderPos::updateRec(
			FmncAMPurchorderPos* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->Itemno.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->pcoRefFmncMPurchorder,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->pcoNum,&(l[1]),&(n[1]),&(e[1])), 
		bindDouble(&rec->Quantity,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Itemno.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refFmncMArticle,&(l[4]),&(n[4]),&(e[4])), 
		bindDouble(&rec->Unitprice,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->Price,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMPurchorderPos / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMPurchorderPos / stmtUpdateRec)\n");
};

void MyTblFmncAMPurchorderPos::updateRst(
			ListFmncAMPurchorderPos& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMPurchorderPos::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMPurchorderPos / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMPurchorderPos / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMPurchorderPos::loadRecByRef(
			ubigint ref
			, FmncAMPurchorderPos** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMPurchorderPos WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMPurchorderPos
 ******************************************************************************/

PgTblFmncAMPurchorderPos::PgTblFmncAMPurchorderPos() : TblFmncAMPurchorderPos(), PgTable() {
};

PgTblFmncAMPurchorderPos::~PgTblFmncAMPurchorderPos() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMPurchorderPos::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMPurchorderPos_insertRec", "INSERT INTO TblFmncAMPurchorderPos (pcoRefFmncMPurchorder, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMPurchorderPos_updateRec", "UPDATE TblFmncAMPurchorderPos SET pcoRefFmncMPurchorder = $1, pcoNum = $2, Quantity = $3, Itemno = $4, refFmncMArticle = $5, Unitprice = $6, Price = $7 WHERE ref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMPurchorderPos_removeRecByRef", "DELETE FROM TblFmncAMPurchorderPos WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMPurchorderPos_loadRecByRef", "SELECT ref, pcoRefFmncMPurchorder, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price FROM TblFmncAMPurchorderPos WHERE ref = $1", 1, NULL);
};

bool PgTblFmncAMPurchorderPos::loadRec(
			PGresult* res
			, FmncAMPurchorderPos** rec
		) {
	char* ptr;

	FmncAMPurchorderPos* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMPurchorderPos();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "pcoreffmncmpurchorder"),
			PQfnumber(res, "pconum"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "itemno"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "price")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->pcoRefFmncMPurchorder = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->pcoNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Quantity = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Itemno.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refFmncMArticle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Unitprice = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Price = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMPurchorderPos::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMPurchorderPos& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMPurchorderPos* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "pcoreffmncmpurchorder"),
			PQfnumber(res, "pconum"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "itemno"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "price")
		};

		while (numread < numrow) {
			rec = new FmncAMPurchorderPos();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->pcoRefFmncMPurchorder = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->pcoNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Quantity = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Itemno.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refFmncMArticle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Unitprice = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Price = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMPurchorderPos::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMPurchorderPos** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMPurchorderPos / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMPurchorderPos::loadRecBySQL(
			const string& sqlstr
			, FmncAMPurchorderPos** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMPurchorderPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMPurchorderPos& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMPurchorderPos::insertRec(
			FmncAMPurchorderPos* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _pcoRefFmncMPurchorder = htonl64(rec->pcoRefFmncMPurchorder);
	uint _pcoNum = htonl(rec->pcoNum);
	string _Quantity = to_string(rec->Quantity);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	string _Unitprice = to_string(rec->Unitprice);
	string _Price = to_string(rec->Price);

	const char* vals[] = {
		(char*) &_pcoRefFmncMPurchorder,
		(char*) &_pcoNum,
		_Quantity.c_str(),
		rec->Itemno.c_str(),
		(char*) &_refFmncMArticle,
		_Unitprice.c_str(),
		_Price.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMPurchorderPos_insertRec", 7, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMPurchorderPos_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMPurchorderPos::insertRst(
			ListFmncAMPurchorderPos& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMPurchorderPos::updateRec(
			FmncAMPurchorderPos* rec
		) {
	PGresult* res;

	ubigint _pcoRefFmncMPurchorder = htonl64(rec->pcoRefFmncMPurchorder);
	uint _pcoNum = htonl(rec->pcoNum);
	string _Quantity = to_string(rec->Quantity);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	string _Unitprice = to_string(rec->Unitprice);
	string _Price = to_string(rec->Price);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_pcoRefFmncMPurchorder,
		(char*) &_pcoNum,
		_Quantity.c_str(),
		rec->Itemno.c_str(),
		(char*) &_refFmncMArticle,
		_Unitprice.c_str(),
		_Price.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMPurchorderPos_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMPurchorderPos_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMPurchorderPos::updateRst(
			ListFmncAMPurchorderPos& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMPurchorderPos::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMPurchorderPos_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMPurchorderPos_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMPurchorderPos::loadRecByRef(
			ubigint ref
			, FmncAMPurchorderPos** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMPurchorderPos_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

