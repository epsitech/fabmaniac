/**
  * \file FmncQPcoAPos.cpp
  * Dbs and XML wrapper for table TblFmncQPcoAPos (implementation)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#include "FmncQPcoAPos.h"

/******************************************************************************
 class FmncQPcoAPos
 ******************************************************************************/

FmncQPcoAPos::FmncQPcoAPos(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint pcoNum
			, const double Quantity
			, const string Itemno
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const double Unitprice
			, const double Price
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->pcoNum = pcoNum;
	this->Quantity = Quantity;
	this->Itemno = Itemno;
	this->refFmncMArticle = refFmncMArticle;
	this->stubRefFmncMArticle = stubRefFmncMArticle;
	this->Unitprice = Unitprice;
	this->Price = Price;
};

void FmncQPcoAPos::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "FmncQPcoAPos";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeDouble(wr, "qty", Quantity);
		writeString(wr, "itn", Itemno);
		writeString(wr, "art", stubRefFmncMArticle);
		writeDouble(wr, "upr", Unitprice);
		writeDouble(wr, "prc", Price);
	} else {
		writeDouble(wr, "Quantity", Quantity);
		writeString(wr, "Itemno", Itemno);
		writeString(wr, "stubRefFmncMArticle", stubRefFmncMArticle);
		writeDouble(wr, "Unitprice", Unitprice);
		writeDouble(wr, "Price", Price);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListFmncQPcoAPos
 ******************************************************************************/

ListFmncQPcoAPos::ListFmncQPcoAPos() {
};

ListFmncQPcoAPos::ListFmncQPcoAPos(
			const ListFmncQPcoAPos& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new FmncQPcoAPos(*(src.nodes[i]));
};

ListFmncQPcoAPos::~ListFmncQPcoAPos() {
	clear();
};

void ListFmncQPcoAPos::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListFmncQPcoAPos::size() const {
	return(nodes.size());
};

void ListFmncQPcoAPos::append(
			FmncQPcoAPos* rec
		) {
	nodes.push_back(rec);
};

ListFmncQPcoAPos& ListFmncQPcoAPos::operator=(
			const ListFmncQPcoAPos& src
		) {
	FmncQPcoAPos* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new FmncQPcoAPos(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListFmncQPcoAPos::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListFmncQPcoAPos";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblFmncQPcoAPos
 ******************************************************************************/

TblFmncQPcoAPos::TblFmncQPcoAPos() {
};

TblFmncQPcoAPos::~TblFmncQPcoAPos() {
};

bool TblFmncQPcoAPos::loadRecBySQL(
			const string& sqlstr
			, FmncQPcoAPos** rec
		) {
	return false;
};

ubigint TblFmncQPcoAPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPcoAPos& rst
		) {
	return 0;
};

void TblFmncQPcoAPos::insertRec(
			FmncQPcoAPos* rec
		) {
};

ubigint TblFmncQPcoAPos::insertNewRec(
			FmncQPcoAPos** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint pcoNum
			, const double Quantity
			, const string Itemno
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const double Unitprice
			, const double Price
		) {
	ubigint retval = 0;
	FmncQPcoAPos* _rec = NULL;

	_rec = new FmncQPcoAPos(0, jref, jnum, ref, pcoNum, Quantity, Itemno, refFmncMArticle, stubRefFmncMArticle, Unitprice, Price);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblFmncQPcoAPos::appendNewRecToRst(
			ListFmncQPcoAPos& rst
			, FmncQPcoAPos** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint pcoNum
			, const double Quantity
			, const string Itemno
			, const ubigint refFmncMArticle
			, const string stubRefFmncMArticle
			, const double Unitprice
			, const double Price
		) {
	ubigint retval = 0;
	FmncQPcoAPos* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, pcoNum, Quantity, Itemno, refFmncMArticle, stubRefFmncMArticle, Unitprice, Price);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblFmncQPcoAPos::insertRst(
			ListFmncQPcoAPos& rst
		) {
};

void TblFmncQPcoAPos::updateRec(
			FmncQPcoAPos* rec
		) {
};

void TblFmncQPcoAPos::updateRst(
			ListFmncQPcoAPos& rst
		) {
};

void TblFmncQPcoAPos::removeRecByQref(
			ubigint qref
		) {
};

void TblFmncQPcoAPos::removeRstByJref(
			ubigint jref
		) {
};

bool TblFmncQPcoAPos::loadRecByQref(
			ubigint qref
			, FmncQPcoAPos** rec
		) {
	return false;
};

ubigint TblFmncQPcoAPos::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPcoAPos& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblFmncQPcoAPos
 ******************************************************************************/

MyTblFmncQPcoAPos::MyTblFmncQPcoAPos() : TblFmncQPcoAPos(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblFmncQPcoAPos::~MyTblFmncQPcoAPos() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblFmncQPcoAPos::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblFmncQPcoAPos (jref, jnum, ref, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblFmncQPcoAPos SET jref = ?, jnum = ?, ref = ?, pcoNum = ?, Quantity = ?, Itemno = ?, refFmncMArticle = ?, Unitprice = ?, Price = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblFmncQPcoAPos WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblFmncQPcoAPos WHERE jref = ?", false);
};

bool MyTblFmncQPcoAPos::loadRecBySQL(
			const string& sqlstr
			, FmncQPcoAPos** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	FmncQPcoAPos* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPcoAPos / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new FmncQPcoAPos();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->pcoNum = atol((char*) dbrow[4]); else _rec->pcoNum = 0;
		if (dbrow[5]) _rec->Quantity = atof((char*) dbrow[5]); else _rec->Quantity = 0.0;
		if (dbrow[6]) _rec->Itemno.assign(dbrow[6], dblengths[6]); else _rec->Itemno = "";
		if (dbrow[7]) _rec->refFmncMArticle = atoll((char*) dbrow[7]); else _rec->refFmncMArticle = 0;
		if (dbrow[8]) _rec->Unitprice = atof((char*) dbrow[8]); else _rec->Unitprice = 0.0;
		if (dbrow[9]) _rec->Price = atof((char*) dbrow[9]); else _rec->Price = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblFmncQPcoAPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPcoAPos& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	FmncQPcoAPos* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblFmncQPcoAPos / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new FmncQPcoAPos();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->pcoNum = atol((char*) dbrow[4]); else rec->pcoNum = 0;
			if (dbrow[5]) rec->Quantity = atof((char*) dbrow[5]); else rec->Quantity = 0.0;
			if (dbrow[6]) rec->Itemno.assign(dbrow[6], dblengths[6]); else rec->Itemno = "";
			if (dbrow[7]) rec->refFmncMArticle = atoll((char*) dbrow[7]); else rec->refFmncMArticle = 0;
			if (dbrow[8]) rec->Unitprice = atof((char*) dbrow[8]); else rec->Unitprice = 0.0;
			if (dbrow[9]) rec->Price = atof((char*) dbrow[9]); else rec->Price = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblFmncQPcoAPos::insertRec(
			FmncQPcoAPos* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->Itemno.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->pcoNum,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->Quantity,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Itemno.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refFmncMArticle,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->Unitprice,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->Price,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPcoAPos / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPcoAPos / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblFmncQPcoAPos::insertRst(
			ListFmncQPcoAPos& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblFmncQPcoAPos::updateRec(
			FmncQPcoAPos* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->Itemno.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->pcoNum,&(l[3]),&(n[3]),&(e[3])), 
		bindDouble(&rec->Quantity,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Itemno.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refFmncMArticle,&(l[6]),&(n[6]),&(e[6])), 
		bindDouble(&rec->Unitprice,&(l[7]),&(n[7]),&(e[7])), 
		bindDouble(&rec->Price,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPcoAPos / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPcoAPos / stmtUpdateRec)\n");
};

void MyTblFmncQPcoAPos::updateRst(
			ListFmncQPcoAPos& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblFmncQPcoAPos::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPcoAPos / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPcoAPos / stmtRemoveRecByQref)\n");
};

void MyTblFmncQPcoAPos::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblFmncQPcoAPos / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblFmncQPcoAPos / stmtRemoveRstByJref)\n");
};

bool MyTblFmncQPcoAPos::loadRecByQref(
			ubigint qref
			, FmncQPcoAPos** rec
		) {
	return loadRecBySQL("SELECT * FROM TblFmncQPcoAPos WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblFmncQPcoAPos::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPcoAPos& rst
		) {
	return loadRstBySQL("SELECT * FROM TblFmncQPcoAPos WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblFmncQPcoAPos
 ******************************************************************************/

PgTblFmncQPcoAPos::PgTblFmncQPcoAPos() : TblFmncQPcoAPos(), PgTable() {
};

PgTblFmncQPcoAPos::~PgTblFmncQPcoAPos() {
};

void PgTblFmncQPcoAPos::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblFmncQPcoAPos_insertRec", "INSERT INTO TblFmncQPcoAPos (jref, jnum, ref, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPcoAPos_updateRec", "UPDATE TblFmncQPcoAPos SET jref = $1, jnum = $2, ref = $3, pcoNum = $4, Quantity = $5, Itemno = $6, refFmncMArticle = $7, Unitprice = $8, Price = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPcoAPos_removeRecByQref", "DELETE FROM TblFmncQPcoAPos WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPcoAPos_removeRstByJref", "DELETE FROM TblFmncQPcoAPos WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblFmncQPcoAPos_loadRecByQref", "SELECT qref, jref, jnum, ref, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price FROM TblFmncQPcoAPos WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblFmncQPcoAPos_loadRstByJref", "SELECT qref, jref, jnum, ref, pcoNum, Quantity, Itemno, refFmncMArticle, Unitprice, Price FROM TblFmncQPcoAPos WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblFmncQPcoAPos::loadRec(
			PGresult* res
			, FmncQPcoAPos** rec
		) {
	char* ptr;

	FmncQPcoAPos* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new FmncQPcoAPos();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "pconum"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "itemno"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "price")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->pcoNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Quantity = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Itemno.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refFmncMArticle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Unitprice = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Price = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblFmncQPcoAPos::loadRst(
			PGresult* res
			, const bool append
			, ListFmncQPcoAPos& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	FmncQPcoAPos* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "pconum"),
			PQfnumber(res, "quantity"),
			PQfnumber(res, "itemno"),
			PQfnumber(res, "reffmncmarticle"),
			PQfnumber(res, "unitprice"),
			PQfnumber(res, "price")
		};

		while (numread < numrow) {
			rec = new FmncQPcoAPos();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->pcoNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Quantity = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Itemno.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refFmncMArticle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Unitprice = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Price = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblFmncQPcoAPos::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, FmncQPcoAPos** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoAPos / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPcoAPos::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListFmncQPcoAPos& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoAPos / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblFmncQPcoAPos::loadRecBySQL(
			const string& sqlstr
			, FmncQPcoAPos** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblFmncQPcoAPos::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListFmncQPcoAPos& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblFmncQPcoAPos::insertRec(
			FmncQPcoAPos* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _pcoNum = htonl(rec->pcoNum);
	string _Quantity = to_string(rec->Quantity);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	string _Unitprice = to_string(rec->Unitprice);
	string _Price = to_string(rec->Price);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
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
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblFmncQPcoAPos_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoAPos_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblFmncQPcoAPos::insertRst(
			ListFmncQPcoAPos& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblFmncQPcoAPos::updateRec(
			FmncQPcoAPos* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _pcoNum = htonl(rec->pcoNum);
	string _Quantity = to_string(rec->Quantity);
	ubigint _refFmncMArticle = htonl64(rec->refFmncMArticle);
	string _Unitprice = to_string(rec->Unitprice);
	string _Price = to_string(rec->Price);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_pcoNum,
		_Quantity.c_str(),
		rec->Itemno.c_str(),
		(char*) &_refFmncMArticle,
		_Unitprice.c_str(),
		_Price.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblFmncQPcoAPos_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoAPos_updateRec)\n");

	PQclear(res);
};

void PgTblFmncQPcoAPos::updateRst(
			ListFmncQPcoAPos& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblFmncQPcoAPos::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblFmncQPcoAPos_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoAPos_removeRecByQref)\n");

	PQclear(res);
};

void PgTblFmncQPcoAPos::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblFmncQPcoAPos_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblFmncQPcoAPos_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblFmncQPcoAPos::loadRecByQref(
			ubigint qref
			, FmncQPcoAPos** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblFmncQPcoAPos_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblFmncQPcoAPos::loadRstByJref(
			ubigint jref
			, const bool append
			, ListFmncQPcoAPos& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblFmncQPcoAPos_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

