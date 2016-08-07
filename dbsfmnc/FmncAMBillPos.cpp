/**
  * \file FmncAMBillPos.cpp
  * database access for table TblFmncAMBillPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncAMBillPos.h"

/******************************************************************************
 class FmncAMBillPos
 ******************************************************************************/

FmncAMBillPos::FmncAMBillPos(
			const ubigint ref
			, const ubigint bilRefFmncMBill
			, const uint bilNum
			, const ubigint x1RefFmncMFabuser
			, const ubigint x2RefFmncMTool
			, const double Quantity
			, const string Article
			, const double Unitprice
			, const double Price
		) {

	this->ref = ref;
	this->bilRefFmncMBill = bilRefFmncMBill;
	this->bilNum = bilNum;
	this->x1RefFmncMFabuser = x1RefFmncMFabuser;
	this->x2RefFmncMTool = x2RefFmncMTool;
	this->Quantity = Quantity;
	this->Article = Article;
	this->Unitprice = Unitprice;
	this->Price = Price;
};

bool FmncAMBillPos::operator==(
			const FmncAMBillPos& comp
		) {
	return false;
};

bool FmncAMBillPos::operator!=(
			const FmncAMBillPos& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListFmncAMBillPos
 ******************************************************************************/

ListFmncAMBillPos::ListFmncAMBillPos() {
};

ListFmncAMBillPos::ListFmncAMBillPos(
			const ListFmncAMBillPos& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncAMBillPos(*(src.nodes[i]));
};

ListFmncAMBillPos::~ListFmncAMBillPos() {
	clear();
};

void ListFmncAMBillPos::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncAMBillPos::size() const {
	return(nodes.size());
};

void ListFmncAMBillPos::append(
			FmncAMBillPos* rec
		) {
	nodes.push_back(rec);
};

FmncAMBillPos* ListFmncAMBillPos::operator[](
			const uint ix
		) {
	FmncAMBillPos* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListFmncAMBillPos& ListFmncAMBillPos::operator=(
			const ListFmncAMBillPos& src
		) {
	FmncAMBillPos* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncAMBillPos(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListFmncAMBillPos::operator==(
			const ListFmncAMBillPos& comp
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

bool ListFmncAMBillPos::operator!=(
			const ListFmncAMBillPos& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblFmncAMBillPos
 ******************************************************************************/

TblFmncAMBillPos::TblFmncAMBillPos() {
};

TblFmncAMBillPos::~TblFmncAMBillPos() {
};

bool TblFmncAMBillPos::loadRecBySQL(
			const string& sqlstr
			, FmncAMBillPos** rec
		) {
	return false;
};

ubigint TblFmncAMBillPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMBillPos& rst
		) {
	return 0;
};

void TblFmncAMBillPos::insertRec(
			FmncAMBillPos* rec
		) {
};

ubigint TblFmncAMBillPos::insertNewRec(
			FmncAMBillPos** rec
			, const ubigint bilRefFmncMBill
			, const uint bilNum
			, const ubigint x1RefFmncMFabuser
			, const ubigint x2RefFmncMTool
			, const double Quantity
			, const string Article
			, const double Unitprice
			, const double Price
		) {
	ubigint retval = 0;
	FmncAMBillPos* _rec = NULL;

	_rec = new FmncAMBillPos(0, bilRefFmncMBill, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncAMBillPos::appendNewRecToRst(
			ListFmncAMBillPos& rst
			, FmncAMBillPos** rec
			, const ubigint bilRefFmncMBill
			, const uint bilNum
			, const ubigint x1RefFmncMFabuser
			, const ubigint x2RefFmncMTool
			, const double Quantity
			, const string Article
			, const double Unitprice
			, const double Price
		) {
	ubigint retval = 0;
	FmncAMBillPos* _rec = NULL;

	retval = insertNewRec(&_rec, bilRefFmncMBill, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncAMBillPos::insertRst(
			ListFmncAMBillPos& rst
			, bool transact
		) {
};

void TblFmncAMBillPos::updateRec(
			FmncAMBillPos* rec
		) {
};

void TblFmncAMBillPos::updateRst(
			ListFmncAMBillPos& rst
			, bool transact
		) {
};

void TblFmncAMBillPos::removeRecByRef(
			ubigint ref
		) {
};

bool TblFmncAMBillPos::loadRecByRef(
			ubigint ref
			, FmncAMBillPos** rec
		) {
	return false;
};

ubigint TblFmncAMBillPos::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListFmncAMBillPos& rst
		) {
	ubigint numload = 0;
	FmncAMBillPos* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncAMBillPos
 ******************************************************************************/

MyTblFmncAMBillPos::MyTblFmncAMBillPos() : TblFmncAMBillPos(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblFmncAMBillPos::~MyTblFmncAMBillPos() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblFmncAMBillPos::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncAMBillPos (bilRefFmncMBill, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncAMBillPos SET bilRefFmncMBill = ?, bilNum = ?, x1RefFmncMFabuser = ?, x2RefFmncMTool = ?, Quantity = ?, Article = ?, Unitprice = ?, Price = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblFmncAMBillPos WHERE ref = ?", false);
};

bool MyTblFmncAMBillPos::loadRecBySQL(
			const string& sqlstr
			, FmncAMBillPos** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncAMBillPos* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMBillPos / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncAMBillPos();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->bilRefFmncMBill = atoll((char*) dbrow[1]); else _rec->bilRefFmncMBill = 0;
		if (dbrow[2]) _rec->bilNum = atol((char*) dbrow[2]); else _rec->bilNum = 0;
		if (dbrow[3]) _rec->x1RefFmncMFabuser = atoll((char*) dbrow[3]); else _rec->x1RefFmncMFabuser = 0;
		if (dbrow[4]) _rec->x2RefFmncMTool = atoll((char*) dbrow[4]); else _rec->x2RefFmncMTool = 0;
		if (dbrow[5]) _rec->Quantity = atof((char*) dbrow[5]); else _rec->Quantity = 0.0;
		if (dbrow[6]) _rec->Article.assign(dbrow[6], dblengths[6]); else _rec->Article = "";
		if (dbrow[7]) _rec->Unitprice = atof((char*) dbrow[7]); else _rec->Unitprice = 0.0;
		if (dbrow[8]) _rec->Price = atof((char*) dbrow[8]); else _rec->Price = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncAMBillPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMBillPos& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncAMBillPos* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncAMBillPos / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncAMBillPos();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->bilRefFmncMBill = atoll((char*) dbrow[1]); else rec->bilRefFmncMBill = 0;
			if (dbrow[2]) rec->bilNum = atol((char*) dbrow[2]); else rec->bilNum = 0;
			if (dbrow[3]) rec->x1RefFmncMFabuser = atoll((char*) dbrow[3]); else rec->x1RefFmncMFabuser = 0;
			if (dbrow[4]) rec->x2RefFmncMTool = atoll((char*) dbrow[4]); else rec->x2RefFmncMTool = 0;
			if (dbrow[5]) rec->Quantity = atof((char*) dbrow[5]); else rec->Quantity = 0.0;
			if (dbrow[6]) rec->Article.assign(dbrow[6], dblengths[6]); else rec->Article = "";
			if (dbrow[7]) rec->Unitprice = atof((char*) dbrow[7]); else rec->Unitprice = 0.0;
			if (dbrow[8]) rec->Price = atof((char*) dbrow[8]); else rec->Price = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncAMBillPos::insertRec(
			FmncAMBillPos* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[5] = rec->Article.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->bilRefFmncMBill,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->bilNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x1RefFmncMFabuser,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x2RefFmncMTool,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->Quantity,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Article.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->Unitprice,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->Price,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMBillPos / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMBillPos / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblFmncAMBillPos::insertRst(
			ListFmncAMBillPos& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblFmncAMBillPos::updateRec(
			FmncAMBillPos* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->Article.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->bilRefFmncMBill,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->bilNum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->x1RefFmncMFabuser,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x2RefFmncMTool,&(l[3]),&(n[3]),&(e[3])), 
		bindDouble(&rec->Quantity,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Article.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->Unitprice,&(l[6]),&(n[6]),&(e[6])), 
		bindDouble(&rec->Price,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMBillPos / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMBillPos / stmtUpdateRec)\n");
};

void MyTblFmncAMBillPos::updateRst(
			ListFmncAMBillPos& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblFmncAMBillPos::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncAMBillPos / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncAMBillPos / stmtRemoveRecByRef)\n");
};

bool MyTblFmncAMBillPos::loadRecByRef(
			ubigint ref
			, FmncAMBillPos** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncAMBillPos WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncAMBillPos
 ******************************************************************************/

PgTblFmncAMBillPos::PgTblFmncAMBillPos() : TblFmncAMBillPos(), PgTable() {
};

PgTblFmncAMBillPos::~PgTblFmncAMBillPos() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblFmncAMBillPos::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncAMBillPos_insertRec", "INSERT INTO TblFmncAMBillPos (bilRefFmncMBill, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMBillPos_updateRec", "UPDATE TblFmncAMBillPos SET bilRefFmncMBill = $1, bilNum = $2, x1RefFmncMFabuser = $3, x2RefFmncMTool = $4, Quantity = $5, Article = $6, Unitprice = $7, Price = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncAMBillPos_removeRecByRef", "DELETE FROM TblFmncAMBillPos WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncAMBillPos_loadRecByRef", "SELECT ref, bilRefFmncMBill, bilNum, x1RefFmncMFabuser, x2RefFmncMTool, Quantity, Article, Unitprice, Price FROM TblFmncAMBillPos WHERE ref = $1", 1, NULL);
};

bool PgTblFmncAMBillPos::loadRec(
			PGresult* res
			, FmncAMBillPos** rec
		) {
	char* ptr;

	FmncAMBillPos* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncAMBillPos();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "bilreffmncmbill"),
			PQfnumber(res, "bilnum"),
			PQfnumber(res, "x1reffmncmfabuser"),
			PQfnumber(res, "x2reffmncmtool"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "article"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "price")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->bilRefFmncMBill = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->bilNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1RefFmncMFabuser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2RefFmncMTool = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Quantity = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Article.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Unitprice = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Price = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncAMBillPos::loadRst(
			PGresult* res
			, const bool append
			, ListFmncAMBillPos& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncAMBillPos* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "bilreffmncmbill"),
			PQfnumber(res, "bilnum"),
			PQfnumber(res, "x1reffmncmfabuser"),
			PQfnumber(res, "x2reffmncmtool"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "article"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "price")
		};

		while (numread < numrow) {
			rec = new FmncAMBillPos();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->bilRefFmncMBill = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->bilNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1RefFmncMFabuser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2RefFmncMTool = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Quantity = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Article.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Unitprice = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Price = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncAMBillPos::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncAMBillPos** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMBillPos / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblFmncAMBillPos::loadRecBySQL(
			const string& sqlstr
			, FmncAMBillPos** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncAMBillPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncAMBillPos& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncAMBillPos::insertRec(
			FmncAMBillPos* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _bilRefFmncMBill = htonl64(rec->bilRefFmncMBill);
	uint _bilNum = htonl(rec->bilNum);
	ubigint _x1RefFmncMFabuser = htonl64(rec->x1RefFmncMFabuser);
	ubigint _x2RefFmncMTool = htonl64(rec->x2RefFmncMTool);
	string _Quantity = to_string(rec->Quantity);
	string _Unitprice = to_string(rec->Unitprice);
	string _Price = to_string(rec->Price);

	const char* vals[] = {
		(char*) &_bilRefFmncMBill,
		(char*) &_bilNum,
		(char*) &_x1RefFmncMFabuser,
		(char*) &_x2RefFmncMTool,
		_Quantity.c_str(),
		rec->Article.c_str(),
		_Unitprice.c_str(),
		_Price.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncAMBillPos_insertRec", 8, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMBillPos_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblFmncAMBillPos::insertRst(
			ListFmncAMBillPos& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblFmncAMBillPos::updateRec(
			FmncAMBillPos* rec
		) {
	PGresult* res;

	ubigint _bilRefFmncMBill = htonl64(rec->bilRefFmncMBill);
	uint _bilNum = htonl(rec->bilNum);
	ubigint _x1RefFmncMFabuser = htonl64(rec->x1RefFmncMFabuser);
	ubigint _x2RefFmncMTool = htonl64(rec->x2RefFmncMTool);
	string _Quantity = to_string(rec->Quantity);
	string _Unitprice = to_string(rec->Unitprice);
	string _Price = to_string(rec->Price);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_bilRefFmncMBill,
		(char*) &_bilNum,
		(char*) &_x1RefFmncMFabuser,
		(char*) &_x2RefFmncMTool,
		_Quantity.c_str(),
		rec->Article.c_str(),
		_Unitprice.c_str(),
		_Price.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncAMBillPos_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMBillPos_updateRec)\n");

	PQclear(res);
};

void PgTblFmncAMBillPos::updateRst(
			ListFmncAMBillPos& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblFmncAMBillPos::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblFmncAMBillPos_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncAMBillPos_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblFmncAMBillPos::loadRecByRef(
			ubigint ref
			, FmncAMBillPos** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncAMBillPos_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

