/**
  * \file FmncMStockitem.cpp
  * database access for table TblFmncMStockitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncMStockitem.h"

/******************************************************************************
 class FmncMStockitem
 ******************************************************************************/

FmncMStockitem::FmncMStockitem(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
			, const ubigint refFmncMArticle
			, const ubigint refJQuantity
			, const string Quantity
			, const string osrefFmncKStocklcn
			, const uint Expdate
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refFmncMOrg = refFmncMOrg;
	this->refFmncMArticle = refFmncMArticle;
	this->refJQuantity = refJQuantity;
	this->Quantity = Quantity;
	this->osrefFmncKStocklcn = osrefFmncKStocklcn;
	this->Expdate = Expdate;
	this->Comment = Comment;
};

bool FmncMStockitem::operator==(
			const FmncMStockitem& comp
		) {
	return false;
};

bool FmncMStockitem::operator!=(
			const FmncMStockitem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncMStockitem
 ******************************************************************************/

ListFmncMStockitem::ListFmncMStockitem() {
};

ListFmncMStockitem::ListFmncMStockitem(
			const ListFmncMStockitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncMStockitem(*(src.nodes[i]));
};

ListFmncMStockitem::~ListFmncMStockitem() {
	clear();
};

void ListFmncMStockitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncMStockitem::size() const {
	return(nodes.size());
};

void ListFmncMStockitem::append(
			FmncMStockitem* rec
		) {
	nodes.push_back(rec);
};

FmncMStockitem* ListFmncMStockitem::operator[](
			const uint ix
		) {
	FmncMStockitem* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncMStockitem& ListFmncMStockitem::operator=(
			const ListFmncMStockitem& src
		) {
	FmncMStockitem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncMStockitem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncMStockitem::operator==(
			const ListFmncMStockitem& comp
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

bool ListFmncMStockitem::operator!=(
			const ListFmncMStockitem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncMStockitem
 ******************************************************************************/

TblFmncMStockitem::TblFmncMStockitem() {
};

TblFmncMStockitem::~TblFmncMStockitem() {
};

bool TblFmncMStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncMStockitem** rec
		) {
	return false;
};

ubigint TblFmncMStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMStockitem& rst
		) {
	return 0;
};

void TblFmncMStockitem::insertRec(
			FmncMStockitem* rec
		) {
};

ubigint TblFmncMStockitem::insertNewRec(
			FmncMStockitem** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
			, const ubigint refFmncMArticle
			, const ubigint refJQuantity
			, const string Quantity
			, const string osrefFmncKStocklcn
			, const uint Expdate
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMStockitem* _rec = NULL;

	_rec = new FmncMStockitem(0, grp, own, refFmncMOrg, refFmncMArticle, refJQuantity, Quantity, osrefFmncKStocklcn, Expdate, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncMStockitem::appendNewRecToRst(
			ListFmncMStockitem& rst
			, FmncMStockitem** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refFmncMOrg
			, const ubigint refFmncMArticle
			, const ubigint refJQuantity
			, const string Quantity
			, const string osrefFmncKStocklcn
			, const uint Expdate
			, const string Comment
		) {
	ubigint retval = 0;
	FmncMStockitem* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refFmncMOrg, refFmncMArticle, refJQuantity, Quantity, osrefFmncKStocklcn, Expdate, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncMStockitem::insertRst(
			ListFmncMStockitem& rst
			, bool transact
		) {
};

void TblFmncMStockitem::updateRec(
			FmncMStockitem* rec
		) {
};

void TblFmncMStockitem::updateRst(
			ListFmncMStockitem& rst
			, bool transact
		) {
};

void TblFmncMStockitem::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncMStockitem::loadRecByRef(
			ubigint ref
			, FmncMStockitem** rec
		) {
	return false;
};

ubigint TblFmncMStockitem::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncMStockitem& rst
		) {
	ubigint numload = 0;
	FmncMStockitem* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncMStockitem
 ******************************************************************************/

MyTblFmncMStockitem::MyTblFmncMStockitem() : TblFmncMStockitem(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncMStockitem::~MyTblFmncMStockitem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncMStockitem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncMStockitem (grp, own, refFmncMOrg, refFmncMArticle, refJQuantity, Quantity, osrefFmncKStocklcn, Expdate, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncMStockitem SET grp = ?, own = ?, refFmncMOrg = ?, refFmncMArticle = ?, refJQuantity = ?, Quantity = ?, osrefFmncKStocklcn = ?, Expdate = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncMStockitem WHERE ref = ?", false);
};

bool MyTblFmncMStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncMStockitem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncMStockitem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMStockitem / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncMStockitem();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refFmncMOrg = atoll((char*) dbrow[3]); else _rec->refFmncMOrg = 0;
		if (dbrow[4]) _rec->refFmncMArticle = atoll((char*) dbrow[4]); else _rec->refFmncMArticle = 0;
		if (dbrow[5]) _rec->refJQuantity = atoll((char*) dbrow[5]); else _rec->refJQuantity = 0;
		if (dbrow[6]) _rec->Quantity.assign(dbrow[6], dblengths[6]); else _rec->Quantity = "";
		if (dbrow[7]) _rec->osrefFmncKStocklcn.assign(dbrow[7], dblengths[7]); else _rec->osrefFmncKStocklcn = "";
		if (dbrow[8]) _rec->Expdate = atol((char*) dbrow[8]); else _rec->Expdate = 0;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncMStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMStockitem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncMStockitem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncMStockitem / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncMStockitem();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refFmncMOrg = atoll((char*) dbrow[3]); else rec->refFmncMOrg = 0;
			if (dbrow[4]) rec->refFmncMArticle = atoll((char*) dbrow[4]); else rec->refFmncMArticle = 0;
			if (dbrow[5]) rec->refJQuantity = atoll((char*) dbrow[5]); else rec->refJQuantity = 0;
			if (dbrow[6]) rec->Quantity.assign(dbrow[6], dblengths[6]); else rec->Quantity = "";
			if (dbrow[7]) rec->osrefFmncKStocklcn.assign(dbrow[7], dblengths[7]); else rec->osrefFmncKStocklcn = "";
			if (dbrow[8]) rec->Expdate = atol((char*) dbrow[8]); else rec->Expdate = 0;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncMStockitem::insertRec(
			FmncMStockitem* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->Quantity.length();
	l[6] = rec->osrefFmncKStocklcn.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refFmncMOrg,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refFmncMArticle,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refJQuantity,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Quantity.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->osrefFmncKStocklcn.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->Expdate,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMStockitem / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMStockitem / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncMStockitem::insertRst(
			ListFmncMStockitem& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncMStockitem::updateRec(
			FmncMStockitem* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->Quantity.length();
	l[6] = rec->osrefFmncKStocklcn.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refFmncMOrg,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refFmncMArticle,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refJQuantity,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Quantity.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->osrefFmncKStocklcn.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->Expdate,&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMStockitem / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMStockitem / stmtUpdateRec)\n");
};

void MyTblFmncMStockitem::updateRst(
			ListFmncMStockitem& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncMStockitem::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncMStockitem / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncMStockitem / stmtRemoveRecByRef)\n");
};

bool MyTblFmncMStockitem::loadRecByRef(
			ubigint ref
			, FmncMStockitem** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncMStockitem WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncMStockitem
 ******************************************************************************/

PgTblFmncMStockitem::PgTblFmncMStockitem() : TblFmncMStockitem(), PgTable() {
};

PgTblFmncMStockitem::~PgTblFmncMStockitem() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncMStockitem::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncMStockitem_insertRec", "INSERT INTO TblFmncMStockitem (grp, own, refFmncMOrg, refFmncMArticle, refJQuantity, Quantity, osrefFmncKStocklcn, Expdate, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMStockitem_updateRec", "UPDATE TblFmncMStockitem SET grp = $1, own = $2, refFmncMOrg = $3, refFmncMArticle = $4, refJQuantity = $5, Quantity = $6, osrefFmncKStocklcn = $7, Expdate = $8, Comment = $9 WHERE ref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncMStockitem_removeRecByRef", "DELETE FROM TblFmncMStockitem WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncMStockitem_loadRecByRef", "SELECT ref, grp, own, refFmncMOrg, refFmncMArticle, refJQuantity, Quantity, osrefFmncKStocklcn, Expdate, Comment FROM TblFmncMStockitem WHERE ref = $1", 1, NULL);
};

bool PgTblFmncMStockitem::loadRec(
			PGresult* res
			, FmncMStockitem** rec
		) {
	char* ptr;

	FmncMStockitem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncMStockitem();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "refjquantity"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "osreffmnckstocklcn"),
			PQfnumber(res, "expdate"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refFmncMOrg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refFmncMArticle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refJQuantity = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Quantity.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->osrefFmncKStocklcn.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Expdate = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncMStockitem::loadRst(
			PGresult* res
			, const bool append
			, ListFmncMStockitem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncMStockitem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "reffmncmorg"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "refjquantity"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "osreffmnckstocklcn"),
			PQfnumber(res, "expdate"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new FmncMStockitem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refFmncMOrg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refFmncMArticle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refJQuantity = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Quantity.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->osrefFmncKStocklcn.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Expdate = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncMStockitem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncMStockitem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMStockitem / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncMStockitem::loadRecBySQL(
			const string& sqlstr
			, FmncMStockitem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncMStockitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncMStockitem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncMStockitem::insertRec(
			FmncMStockitem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	ubigint _refJQuantity = htonl64(rec->refJQuantity);
	uint _Expdate = htonl(rec->Expdate);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMArticle,
		(char*) &_refJQuantity,
		rec->Quantity.c_str(),
		rec->osrefFmncKStocklcn.c_str(),
		(char*) &_Expdate,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblFmncMStockitem_insertRec", 9, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMStockitem_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncMStockitem::insertRst(
			ListFmncMStockitem& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncMStockitem::updateRec(
			FmncMStockitem* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refFmncMOrg = htonl64(rec->refFmncMOrg);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	ubigint _refJQuantity = htonl64(rec->refJQuantity);
	uint _Expdate = htonl(rec->Expdate);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refFmncMOrg,
		(char*) &_refFmncMArticle,
		(char*) &_refJQuantity,
		rec->Quantity.c_str(),
		rec->osrefFmncKStocklcn.c_str(),
		(char*) &_Expdate,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncMStockitem_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMStockitem_updateRec)\n");

	PQclear(res);
};

void PgTblFmncMStockitem::updateRst(
			ListFmncMStockitem& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncMStockitem::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncMStockitem_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncMStockitem_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncMStockitem::loadRecByRef(
			ubigint ref
			, FmncMStockitem** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncMStockitem_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

